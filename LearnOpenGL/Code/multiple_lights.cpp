//
//  multiple_lights.cpp
//  LearnOpenGL
//
//  Created by pfjhetg on 2017/9/25.
//  Copyright © 2017年 pfjhetg. All rights reserved.
//

#include "multiple_lights.hpp"

multiple_lights::multiple_lights(GLFWwindow *window) {
    this->window = window;
}

void multiple_lights::loadShader() {
    this->lightingShader = new Shader("/Users/pfjhetg/Desktop/LearnOpenGL/LearnOpenGL/Shaders/6.multiple_lights.vert", "/Users/pfjhetg/Desktop/LearnOpenGL/LearnOpenGL/Shaders/6.multiple_lights.frag");
    this->lampShader = new Shader("/Users/pfjhetg/Desktop/LearnOpenGL/LearnOpenGL/Shaders/6.lamp.vert", "/Users/pfjhetg/Desktop/LearnOpenGL/LearnOpenGL/Shaders/6.lamp.frag");
    
    float vertices[] = {
        // positions          // normals           // texture coords
        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  0.0f,
        0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  0.0f,
        0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  1.0f,
        0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  0.0f,
        
        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  0.0f,
        0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  0.0f,
        0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  1.0f,
        0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  0.0f,
        
        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
        -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  1.0f,
        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
        -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  0.0f,
        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
        
        0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
        0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  1.0f,
        0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
        0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
        0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  0.0f,
        0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
        
        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  1.0f,
        0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  1.0f,
        0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  0.0f,
        0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  0.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  0.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  1.0f,
        
        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  1.0f,
        0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  1.0f,
        0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  0.0f,
        0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  0.0f,
        -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  0.0f,
        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  1.0f
    };
 
    glGenVertexArrays(1, &cubeVAO);
    glGenBuffers(1, &VBO);
    
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
    glBindVertexArray(cubeVAO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);
    
    glGenVertexArrays(1, &lightVAO);
    glBindVertexArray(lightVAO);
    
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    // note that we update the lamp's position attribute's stride to reflect the updated buffer data
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    
    diffuseMap = loadTexture("/Users/pfjhetg/Desktop/LearnOpenGL/LearnOpenGL/Sources/container2.png");
    specularMap = loadTexture("/Users/pfjhetg/Desktop/LearnOpenGL/LearnOpenGL/Sources/container2_specular.png");
    
    this->lightingShader->use();
    this->lightingShader->setInt("material.diffuse", 0);
    this->lightingShader->setInt("material.specular", 1);
    
}

void multiple_lights::renderLoop() {
    // ------
    // 设置清空屏幕所用的颜色
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    // 清空颜色缓冲
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    
    // positions all containers
    glm::vec3 cubePositions[] = {
        glm::vec3( 0.0f,  0.0f,  0.0f),
        glm::vec3( 2.0f,  5.0f, -15.0f),
        glm::vec3(-1.5f, -2.2f, -2.5f),
        glm::vec3(-3.8f, -2.0f, -12.3f),
        glm::vec3( 2.4f, -0.4f, -3.5f),
        glm::vec3(-1.7f,  3.0f, -7.5f),
        glm::vec3( 1.3f, -2.0f, -2.5f),
        glm::vec3( 1.5f,  2.0f, -2.5f),
        glm::vec3( 1.5f,  0.2f, -1.5f),
        glm::vec3(-1.3f,  1.0f, -1.5f)
    };
    
    // positions of the point lights
    glm::vec3 pointLightPositions[] = {
        glm::vec3( 0.7f,  0.2f,  2.0f),
        glm::vec3( 2.3f, -3.3f, -4.0f),
        glm::vec3(-4.0f,  2.0f, -12.0f),
        glm::vec3( 0.0f,  0.0f, -3.0f)
    };
    
    
    this->lightingShader->use();
    this->lightingShader->setVec3("viewPos", this->camera->Position);
    this->lightingShader->setFloat("material.shininess", 32.0f);
    
    // directional light
    this->lightingShader->setVec3("dirLight.direction", -0.2f, -1.0f, -0.3f);
    this->lightingShader->setVec3("dirLight.ambient", 0.05f, 0.05f, 0.05f);
    this->lightingShader->setVec3("dirLight.diffuse", 0.4f, 0.4f, 0.4f);
    this->lightingShader->setVec3("dirLight.specular", 0.5f, 0.5f, 0.5f);
    // point light 1
    this->lightingShader->setVec3("pointLights[0].position", pointLightPositions[0]);
    this->lightingShader->setVec3("pointLights[0].ambient", 0.05f, 0.05f, 0.05f);
    this->lightingShader->setVec3("pointLights[0].diffuse", 0.8f, 0.8f, 0.8f);
    this->lightingShader->setVec3("pointLights[0].specular", 1.0f, 1.0f, 1.0f);
    this->lightingShader->setFloat("pointLights[0].constant", 1.0f);
    this->lightingShader->setFloat("pointLights[0].linear", 0.09);
    this->lightingShader->setFloat("pointLights[0].quadratic", 0.032);
    // point light 2
    this->lightingShader->setVec3("pointLights[1].position", pointLightPositions[1]);
    this->lightingShader->setVec3("pointLights[1].ambient", 0.05f, 0.05f, 0.05f);
    this->lightingShader->setVec3("pointLights[1].diffuse", 0.8f, 0.8f, 0.8f);
    this->lightingShader->setVec3("pointLights[1].specular", 1.0f, 1.0f, 1.0f);
    this->lightingShader->setFloat("pointLights[1].constant", 1.0f);
    this->lightingShader->setFloat("pointLights[1].linear", 0.09);
    this->lightingShader->setFloat("pointLights[1].quadratic", 0.032);
    // point light 3
    this->lightingShader->setVec3("pointLights[2].position", pointLightPositions[2]);
    this->lightingShader->setVec3("pointLights[2].ambient", 0.05f, 0.05f, 0.05f);
    this->lightingShader->setVec3("pointLights[2].diffuse", 0.8f, 0.8f, 0.8f);
    this->lightingShader->setVec3("pointLights[2].specular", 1.0f, 1.0f, 1.0f);
    this->lightingShader->setFloat("pointLights[2].constant", 1.0f);
    this->lightingShader->setFloat("pointLights[2].linear", 0.09);
    this->lightingShader->setFloat("pointLights[2].quadratic", 0.032);
    // point light 4
    this->lightingShader->setVec3("pointLights[3].position", pointLightPositions[3]);
    this->lightingShader->setVec3("pointLights[3].ambient", 0.05f, 0.05f, 0.05f);
    this->lightingShader->setVec3("pointLights[3].diffuse", 0.8f, 0.8f, 0.8f);
    this->lightingShader->setVec3("pointLights[3].specular", 1.0f, 1.0f, 1.0f);
    this->lightingShader->setFloat("pointLights[3].constant", 1.0f);
    this->lightingShader->setFloat("pointLights[3].linear", 0.09);
    this->lightingShader->setFloat("pointLights[3].quadratic", 0.032);
    // spotLight
    this->lightingShader->setVec3("spotLight.position", this->camera->Position);
    this->lightingShader->setVec3("spotLight.direction", this->camera->Front);
    this->lightingShader->setVec3("spotLight.ambient", 0.0f, 0.0f, 0.0f);
    this->lightingShader->setVec3("spotLight.diffuse", 1.0f, 1.0f, 1.0f);
    this->lightingShader->setVec3("spotLight.specular", 1.0f, 1.0f, 1.0f);
    this->lightingShader->setFloat("spotLight.constant", 1.0f);
    this->lightingShader->setFloat("spotLight.linear", 0.09);
    this->lightingShader->setFloat("spotLight.quadratic", 0.032);
    this->lightingShader->setFloat("spotLight.cutOff", glm::cos(glm::radians(12.5f)));
    this->lightingShader->setFloat("spotLight.outerCutOff", glm::cos(glm::radians(15.0f)));
    
    // 用自己选择, 替换原有代码
    // <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< HEAD
    // 这是新代码
    glm::mat4 model;
    glm::mat4 view;
    glm::mat4 projection;
    model = glm::rotate(model, 0.0f, glm::vec3(0.5f, 1.0f, 0.0f));
    view  = glm::translate(view, glm::vec3(0.0f, -1.0f, -600.0f));
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
    //    // world transformation
    //    glm::mat4 model;
    //    this->lightingShader->setMat4("model", model);
    // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, diffuseMap);
    // bind specular map
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, specularMap);

  
    glBindVertexArray(cubeVAO);
    for (unsigned int i = 0; i < 10; i++)
    {
        // calculate the model matrix for each object and pass it to shader before drawing
        glm::mat4 model;
        model = glm::translate(model, cubePositions[i]);
        model = glm::rotate(model, (float)glfwGetTime() * 30, glm::vec3(1.0f, 0.3f, 0.5f));
        float angle = 20.0f * i;
        model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
        this->lightingShader->setMat4("model", model);
        glDrawArrays(GL_TRIANGLES, 0, 36);
    }
    
    this->lampShader->use();
    this->lampShader->setMat4("projection", projection);
    this->lampShader->setMat4("view", view);
    glBindVertexArray(lightVAO);
    for (unsigned int i = 0; i < 4; i++)
    {
        model = glm::mat4();
        model = glm::translate(model, pointLightPositions[i]);
        model = glm::scale(model, glm::vec3(0.2f)); // Make it a smaller cube
         this->lampShader->setMat4("model", model);
        glDrawArrays(GL_TRIANGLES, 0, 36);
    }
    
    // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
    // -------------------------------------------------------------------------------
    glfwSwapBuffers(this->window);
    glfwPollEvents();
}

void multiple_lights::deallocate() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
}
