//
//  model_loading.cpp
//  LearnOpenGL
//
//  Created by pfjhetg on 2017/9/29.
//  Copyright © 2017年 pfjhetg. All rights reserved.
//

#include "model_loading.hpp"

model_loading::model_loading(GLFWwindow *window) {
    this->window = window;
}

void model_loading::loadShader() {
    this->shader = new Shader("/Users/pfjhetg/Desktop/LearnOpenGL/LearnOpenGL/Shaders/model_loading.vert", "/Users/pfjhetg/Desktop/LearnOpenGL/LearnOpenGL/Shaders/model_loading.frag");
     this->ourModel = new Model("/Users/pfjhetg/Desktop/LearnOpenGL/LearnOpenGL/Sources/nanosuit/nanosuit.obj");
}

void model_loading::renderLoop() {
    // ------
    // 设置清空屏幕所用的颜色
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    // 清空颜色缓冲
    // 清空颜色缓冲
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    // render the triangle
    this->shader->use();
    
    
    // 用自己选择, 替换原有代码
    // <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< HEAD
    // 这是新代码
    glm::mat4 model;
    glm::mat4 view;
    glm::mat4 projection;
    model = glm::rotate(model, (float)glfwGetTime() * 30, glm::vec3(0.0f, 1.0f, 0.0f));
    model = glm::scale(model, glm::vec3(0.6f));
    view  = glm::translate(view, glm::vec3(0.0f, -5.0f, - 750.0f));
    projection = glm::perspective(glm::radians(45.0f), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 1000.0f);
    // retrieve the matrix uniform locations
    unsigned int modelLoc = glGetUniformLocation(this->shader->ID, "model");
    unsigned int viewLoc  = glGetUniformLocation(this->shader->ID, "view");
    // pass them to the shaders (3 different ways)
    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, &view[0][0]);
    // note: currently we set the projection matrix each frame, but since the projection matrix rarely changes it's often best practice to set it outside the main loop only once.
    this->shader->setMat4("projection", projection);
    // ================================
    // 这部分是教程原有的代码
//    glm::mat4 projection = glm::perspective(glm::radians(this->camera->Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
//    glm::mat4 view = this->camera->GetViewMatrix();
//    this->shader->setMat4("projection", projection);
//    this->shader->setMat4("view", view);
    // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

    this->ourModel->Draw(*this->shader);
    // 当我们打算绘制一个物体的时候，我们要在绘制物体前简单地把VAO绑定到希望使用的设定上
    // 这一步是通过VAO间接绑定之前定义的顶点属性配置，和VBO的顶点数据
    glBindVertexArray(VAO);
    // 绘制
    glDrawArrays(GL_TRIANGLES, 0, 3);
    
    // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
    // -------------------------------------------------------------------------------
    glfwSwapBuffers(this->window);
    glfwPollEvents();
}

void model_loading::deallocate() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
}
