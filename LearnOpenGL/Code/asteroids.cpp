//
//  asteroids.cpp
//  LearnOpenGL
//
//  Created by pfjhetg on 2017/10/17.
//  Copyright © 2017年 pfjhetg. All rights reserved.
//

#include "asteroids.hpp"

asteroids::asteroids(GLFWwindow *window) {
    this->window = window;
    glEnable(GL_DEPTH_TEST);
    this->camera = new Camera(glm::vec3(0, 0, 1000.0f));
}

void asteroids::loadShader() {
    this->shader = new Shader("/Users/pfjhetg/Desktop/LearnOpenGL/LearnOpenGL/Shaders/10.2.instancing.vert", "/Users/pfjhetg/Desktop/LearnOpenGL/LearnOpenGL/Shaders/10.2.instancing.frag");
    this->rock = new Model("/Users/pfjhetg/Desktop/LearnOpenGL/LearnOpenGL/Sources/rock/rock.obj");
    this->planet = new Model("/Users/pfjhetg/Desktop/LearnOpenGL/LearnOpenGL/Sources/planet/planet.obj");
    
    modelMatrices = new glm::mat4[amount];
    srand(glfwGetTime()); // initialize random seed
    float radius = 50.0;
    float offset = 2.5f;
    for (unsigned int i = 0; i < amount; i++)
    {
        glm::mat4 model;
        // 1. translation: displace along circle with 'radius' in range [-offset, offset]
        float angle = (float)i / (float)amount * 360.0f;
        float displacement = (rand() % (int)(2 * offset * 100)) / 100.0f - offset;
        float x = sin(angle) * radius + displacement;
        displacement = (rand() % (int)(2 * offset * 100)) / 100.0f - offset;
        float y = displacement * 0.4f; // keep height of asteroid field smaller compared to width of x and z
        displacement = (rand() % (int)(2 * offset * 100)) / 100.0f - offset;
        float z = cos(angle) * radius + displacement;
        model = glm::translate(model, glm::vec3(x, y, z));
        
        // 2. scale: Scale between 0.05 and 0.25f
        float scale = (rand() % 20) / 100.0f + 0.05;
        model = glm::scale(model, glm::vec3(scale));
        
        // 3. rotation: add random rotation around a (semi)randomly picked rotation axis vector
        float rotAngle = (rand() % 360);
        model = glm::rotate(model, rotAngle, glm::vec3(0.4f, 0.6f, 0.8f));
        
        // 4. now add to list of matrices
        modelMatrices[i] = model;
    }
    
}

void asteroids::renderLoop() {
    // ------
    // 设置清空屏幕所用的颜色
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    // 清空颜色缓冲
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // 这一步是激活着色器
    // configure transformation matrices
    glm::mat4 projection = glm::perspective(glm::radians(60.0f), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 1000.0f);
    glm::mat4 view = camera->GetViewMatrix();
    shader->use();
    shader->setMat4("projection", projection);
    shader->setMat4("view", view);
    
    // draw planet
    glm::mat4 model;
    model = glm::translate(model, glm::vec3(0.0f, -3.0f, 0.0f));
    model = glm::scale(model, glm::vec3(3.0f, 3.0f, 3.0f));
    shader->setMat4("model", model);
    planet->Draw(*shader);
    
    for (unsigned int i = 0; i < amount; i++)
    {
        shader->setMat4("model", modelMatrices[i]);
        rock->Draw(*shader);
    }
    
    // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
    // -------------------------------------------------------------------------------
    glfwSwapBuffers(this->window);
    glfwPollEvents();
}

void asteroids::deallocate() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
}
