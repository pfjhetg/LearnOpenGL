//
//  advanced_glsl_ubo.cpp
//  LearnOpenGL
//
//  Created by pfjhetg on 2017/10/13.
//  Copyright © 2017年 pfjhetg. All rights reserved.
//

#include "advanced_glsl_ubo.hpp"

advanced_glsl_ubo::advanced_glsl_ubo(GLFWwindow *window) {
    this->window = window;
    this->camera = new Camera(glm::vec3(0.5f, 0.5f, 7.0f));
    
    glEnable(GL_DEPTH_TEST);
}

void advanced_glsl_ubo::loadShader() {
    this->shaderRed = new Shader("/Users/pfjhetg/Desktop/LearnOpenGL/LearnOpenGL/Shaders/8.advanced_glsl.vert", "/Users/pfjhetg/Desktop/LearnOpenGL/LearnOpenGL/Shaders/8.red.frag");
    this->shaderGreen = new Shader("/Users/pfjhetg/Desktop/LearnOpenGL/LearnOpenGL/Shaders/8.advanced_glsl.vert", "/Users/pfjhetg/Desktop/LearnOpenGL/LearnOpenGL/Shaders/8.green.frag");
    this->shaderBlue = new Shader("/Users/pfjhetg/Desktop/LearnOpenGL/LearnOpenGL/Shaders/8.advanced_glsl.vert", "/Users/pfjhetg/Desktop/LearnOpenGL/LearnOpenGL/Shaders/8.blue.frag");
    this->shaderYellow = new Shader("/Users/pfjhetg/Desktop/LearnOpenGL/LearnOpenGL/Shaders/8.advanced_glsl.vert", "/Users/pfjhetg/Desktop/LearnOpenGL/LearnOpenGL/Shaders/8.yellow.frag");
    
    float cubeVertices[] = {
        // positions
        -0.5f, -0.5f, -0.5f,
        0.5f, -0.5f, -0.5f,
        0.5f,  0.5f, -0.5f,
        0.5f,  0.5f, -0.5f,
        -0.5f,  0.5f, -0.5f,
        -0.5f, -0.5f, -0.5f,
        
        -0.5f, -0.5f,  0.5f,
        0.5f, -0.5f,  0.5f,
        0.5f,  0.5f,  0.5f,
        0.5f,  0.5f,  0.5f,
        -0.5f,  0.5f,  0.5f,
        -0.5f, -0.5f,  0.5f,
        
        -0.5f,  0.5f,  0.5f,
        -0.5f,  0.5f, -0.5f,
        -0.5f, -0.5f, -0.5f,
        -0.5f, -0.5f, -0.5f,
        -0.5f, -0.5f,  0.5f,
        -0.5f,  0.5f,  0.5f,
        
        0.5f,  0.5f,  0.5f,
        0.5f,  0.5f, -0.5f,
        0.5f, -0.5f, -0.5f,
        0.5f, -0.5f, -0.5f,
        0.5f, -0.5f,  0.5f,
        0.5f,  0.5f,  0.5f,
        
        -0.5f, -0.5f, -0.5f,
        0.5f, -0.5f, -0.5f,
        0.5f, -0.5f,  0.5f,
        0.5f, -0.5f,  0.5f,
        -0.5f, -0.5f,  0.5f,
        -0.5f, -0.5f, -0.5f,
        
        -0.5f,  0.5f, -0.5f,
        0.5f,  0.5f, -0.5f,
        0.5f,  0.5f,  0.5f,
        0.5f,  0.5f,  0.5f,
        -0.5f,  0.5f,  0.5f,
        -0.5f,  0.5f, -0.5f,
    };
    
    glGenVertexArrays(1, &cubeVAO);
    glGenBuffers(1, &cubeVBO);
    glBindVertexArray(cubeVAO);
    glBindBuffer(GL_ARRAY_BUFFER, cubeVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(cubeVertices), &cubeVertices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    
    // configure a uniform buffer object
    // ---------------------------------
    // first. We get the relevant block indices
    // glGetUniformBlockIndex方法是用来获取相关色器中已定义Uniform块的位置值索引(Uniform块索引)
    unsigned int uniformBlockIndexRed = glGetUniformBlockIndex(shaderRed->ID, "Matrices");
    unsigned int uniformBlockIndexGreen = glGetUniformBlockIndex(shaderGreen->ID, "Matrices");
    unsigned int uniformBlockIndexBlue = glGetUniformBlockIndex(shaderBlue->ID, "Matrices");
    unsigned int uniformBlockIndexYellow = glGetUniformBlockIndex(shaderYellow->ID, "Matrices");
    
    // then we link each shader's uniform block to this uniform binding point
    // glUniformBlockBinding函数，它的第一个参数是一个程序对象，第二个是一个Uniform块索引,第三个是链接到的绑定点
    glUniformBlockBinding(shaderRed->ID, uniformBlockIndexRed, 0);
    glUniformBlockBinding(shaderGreen->ID, uniformBlockIndexGreen, 0);
    glUniformBlockBinding(shaderBlue->ID, uniformBlockIndexBlue, 0);
    glUniformBlockBinding(shaderYellow->ID, uniformBlockIndexYellow, 0);
    
    // Now actually create the buffer
    glGenBuffers(1, &uboMatrices);
    glBindBuffer(GL_UNIFORM_BUFFER, uboMatrices);
    glBufferData(GL_UNIFORM_BUFFER, 2 * sizeof(glm::mat4), NULL, GL_STATIC_DRAW);
    glBindBuffer(GL_UNIFORM_BUFFER, 0);
    // define the range of the buffer that links to a uniform binding point
    glBindBufferRange(GL_UNIFORM_BUFFER, 0, uboMatrices, 0, 2 * sizeof(glm::mat4));
    
    // store the projection matrix (we only do this once now) (note: we're not using zoom anymore by changing the FoV)
    glm::mat4 projection = glm::perspective(45.0f, (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
    glBindBuffer(GL_UNIFORM_BUFFER, uboMatrices);
    glBufferSubData(GL_UNIFORM_BUFFER, 0, sizeof(glm::mat4), glm::value_ptr(projection));
    glBindBuffer(GL_UNIFORM_BUFFER, 0);

}

void advanced_glsl_ubo::renderLoop() {
    // ------
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // set the view and projection matrix in the uniform block - we only have to do this once per loop iteration.
    glm::mat4 view = camera->GetViewMatrix();
    glBindBuffer(GL_UNIFORM_BUFFER, uboMatrices);
    glBufferSubData(GL_UNIFORM_BUFFER, sizeof(glm::mat4), sizeof(glm::mat4), glm::value_ptr(view));
    glBindBuffer(GL_UNIFORM_BUFFER, 0);

    // draw 4 cubes
    // RED
    glBindVertexArray(cubeVAO);
    shaderRed->use();
    glm::mat4 model;
    model = glm::translate(model, glm::vec3(-0.75f, 0.75f, 0.0f)); // move top-left
    shaderRed->setMat4("model", model);
    glDrawArrays(GL_TRIANGLES, 0, 36);
    // GREEN
    shaderGreen->use();
    model = glm::mat4();
    model = glm::translate(model, glm::vec3(0.75f, 0.75f, 0.0f)); // move top-right
    shaderGreen->setMat4("model", model);
    glDrawArrays(GL_TRIANGLES, 0, 36);
    // YELLOW
    shaderYellow->use();
    model = glm::mat4();
    model = glm::translate(model, glm::vec3(-0.75f, -0.75f, 0.0f)); // move bottom-left
    shaderYellow->setMat4("model", model);
    glDrawArrays(GL_TRIANGLES, 0, 36);
    // BLUE
    shaderBlue->use();
    model = glm::mat4();
    model = glm::translate(model, glm::vec3(0.75f, -0.75f, 0.0f)); // move bottom-right
    shaderBlue->setMat4("model", model);
    glDrawArrays(GL_TRIANGLES, 0, 36);
    
    // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
    // -------------------------------------------------------------------------------
    glfwSwapBuffers(this->window);
    glfwPollEvents();
}

void advanced_glsl_ubo::deallocate() {
    glDeleteVertexArrays(1, &cubeVAO);
    glDeleteBuffers(1, &cubeVBO);
}
