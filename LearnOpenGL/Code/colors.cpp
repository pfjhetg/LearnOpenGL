//
//  colors.cpp
//  LearnOpenGL
//
//  Created by pfjhetg on 2017/9/21.
//  Copyright © 2017年 pfjhetg. All rights reserved.
//

#include "colors.hpp"

colors::colors(GLFWwindow *window) {
    this->lightingShader = new Shader("/Users/pfjhetg/Desktop/LearnOpenGL/LearnOpenGL/Shaders/1.colors.vert", "/Users/pfjhetg/Desktop/LearnOpenGL/LearnOpenGL/Shaders/1.colors.frag");
    this->lampShader = new Shader("/Users/pfjhetg/Desktop/LearnOpenGL/LearnOpenGL/Shaders/1.lamp.vert", "/Users/pfjhetg/Desktop/LearnOpenGL/LearnOpenGL/Shaders/1.lamp.frag");
    this->window = window;
}

void colors::loadShader() {
    
    float vertices[] = {
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
    glGenBuffers(1, &VBO);
    
    glBindBuffer(GL_ARRAY_BUFFER , VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
    glBindVertexArray(cubeVAO);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);
    
    glGenVertexArrays(1, &lightVAO);
    glBindVertexArray(lightVAO);
    
    // 使用glVertexAttribPointer之前需要绑定一次VBO,由于前面已经填充了数据,这里就不需要再glBufferData了
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);
    
}

void colors::renderLoop() {
    // 键盘事件
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        this->camera->ProcessKeyboard(FORWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        this->camera->ProcessKeyboard(BACKWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        this->camera->ProcessKeyboard(LEFT, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        this->camera->ProcessKeyboard(RIGHT, deltaTime);
    // per-frame time logic
    float currentFrame = glfwGetTime();
    deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;
    // 设置清空屏幕所用的颜色
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    // 清空颜色缓冲,使用Zbuffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    this->lightingShader->use();
    this->lightingShader->setVec3("objectColor", 1.0f, 0.5f, 0.31f);
    this->lightingShader->setVec3("lightColor", 1.0f, 1.0f, 1.0f);
    
    // 用自己选择, 替换原有代码
    // <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< HEAD
    // 这是新代码
    glm::mat4 model;
    glm::mat4 view;
    glm::mat4 projection;
    model = glm::rotate(model, (float)glfwGetTime() * 50, glm::vec3(0.5f, 1.0f, 0.0f));
    view  = glm::translate(view, glm::vec3(0.0f, 0.0f, -200.0f));
    projection = glm::perspective(glm::radians(45.0f), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 1000.0f);
    // retrieve the matrix uniform locations
    unsigned int modelLoc = glGetUniformLocation(this->lightingShader->ID, "model");
    unsigned int viewLoc  = glGetUniformLocation(this->lightingShader->ID, "view");
    // pass them to the shaders (3 different ways)
    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, &view[0][0]);
    // note: currently we set the projection matrix each frame, but since the projection matrix rarely changes it's often best practice to set it outside the main loop only once.
    this->lightingShader->setMat4("projection", projection);
    // ================================
    // 这部分是教程原有的代码
//    glm::mat4 projection = glm::perspective(glm::radians(this->camera->Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
//    glm::mat4 view = this->camera->GetViewMatrix();
//    this->lightingShader->setMat4("projection", projection);
//    this->lightingShader->setMat4("view", view);
//    
//    glm::mat4 model;
//    this->lightingShader->setMat4("model", model);
    // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
   
    // 当我们打算绘制一个物体的时候，我们要在绘制物体前简单地把VAO绑定到希望使用的设定上
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 36);
    
    this->lampShader->use();
    this->lampShader->setMat4("projection", projection);
    this->lampShader->setMat4("view", view);
    model = glm::mat4();
    model = glm::translate(model, lightPos);
    // 缩小的cube
    model = glm::scale(model, glm::vec3(0.2f));
    this->lampShader->setMat4("model", model);
    
    glBindVertexArray(lightVAO);
    glDrawArrays(GL_TRIANGLES, 0, 36);
    
    // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
    // -------------------------------------------------------------------------------
    glfwSwapBuffers(this->window);
    glfwPollEvents();
}

void colors::deallocate() {
    glDeleteVertexArrays(1, &cubeVAO);
    glDeleteVertexArrays(1, &lightVAO);
    glDeleteBuffers(1, &VBO);
}


