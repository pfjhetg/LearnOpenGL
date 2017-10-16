//
//  geometry_shader_houses.cpp
//  LearnOpenGL
//
//  Created by pfjhetg on 2017/10/16.
//  Copyright © 2017年 pfjhetg. All rights reserved.
//

#include "geometry_shader_houses.hpp"


geometry_shader_houses::geometry_shader_houses(GLFWwindow *window) {
    this->window = window;
    
    glEnable(GL_DEPTH_TEST);
}

void geometry_shader_houses::loadShader() {
    this->shader = new Shader("/Users/pfjhetg/Desktop/LearnOpenGL/LearnOpenGL/Shaders/9.1.geometry_shader.vert", "/Users/pfjhetg/Desktop/LearnOpenGL/LearnOpenGL/Shaders/9.1.geometry_shader.frag",  "/Users/pfjhetg/Desktop/LearnOpenGL/LearnOpenGL/Shaders/9.1.geometry_shader.gs");
    
    float points[] = {
        -0.5f,  0.5f, 1.0f, 0.0f, 0.0f, // top-left
        0.5f,  0.5f, 0.0f, 1.0f, 0.0f, // top-right
        0.5f, -0.5f, 0.0f, 0.0f, 1.0f, // bottom-right
        -0.5f, -0.5f, 1.0f, 1.0f, 0.0f  // bottom-left
    };
    
    glGenBuffers(1, &VBO);
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(points), points, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), 0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *)(2 * sizeof(float)));
    glBindVertexArray(0);
}

void geometry_shader_houses::renderLoop() {
    // ------
    // 设置清空屏幕所用的颜色
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    // 清空颜色缓冲
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // render the triangle
    // 要想绘制我们想要的物体，OpenGL给我们提供了glDrawArrays函数，它使用当前激活的着色器，之前定义的顶点属性配置，和VBO的顶点数据（通过VAO间接绑定）来绘制图元。
    // 这一步是激活着色器
    this->shader->use();
    // 当我们打算绘制一个物体的时候，我们要在绘制物体前简单地把VAO绑定到希望使用的设定上
    // 这一步是通过VAO间接绑定之前定义的顶点属性配置，和VBO的顶点数据
    glBindVertexArray(VAO);
    glDrawArrays(GL_POINTS, 0, 4);
    // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
    // -------------------------------------------------------------------------------
    glfwSwapBuffers(this->window);
    glfwPollEvents();
}

void geometry_shader_houses::deallocate() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}
