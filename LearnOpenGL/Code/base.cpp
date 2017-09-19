//
//  base.cpp
//  LearnOpenGL
//
//  Created by pfjhetg on 2017/9/19.
//  Copyright © 2017年 pfjhetg. All rights reserved.
//

#include "base.hpp"

base::base() {
    
}

base::base(GLFWwindow *window) {
    this->window = window;
}

void base::loadShader() {
    // build and compile our shader program, 绝对路径
    // ------------------------------------
//    Shader ourShader("/Users/pfjhetg/Desktop/LearnOpenGL/LearnOpenGL/Shaders/3.3.shader.vert", "/Users/pfjhetg/Desktop/LearnOpenGL/LearnOpenGL/Shaders/3.3.shader.frag");
    this->shader = new Shader("/Users/pfjhetg/Desktop/LearnOpenGL/LearnOpenGL/Shaders/3.3.shader.vert", "/Users/pfjhetg/Desktop/LearnOpenGL/LearnOpenGL/Shaders/3.3.shader.frag");
    
    // set up vertex data (and buffer(s)) and configure vertex attributes
    // ------------------------------------------------------------------
    float vertices[] = {
        // positions         // colors
        0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,  // bottom right
        -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,  // bottom left
        0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f   // top
    };
    
    
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(VAO);
    
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    
    // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
    // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
    // glBindVertexArray(0);
}

void base::renderLoop() {
    // render the triangle
    this->shader->use();
    // 当我们打算绘制一个物体的时候，我们要在绘制物体前简单地把VAO绑定到希望使用的设定上
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    
    // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
    // -------------------------------------------------------------------------------
    glfwSwapBuffers(this->window);
    glfwPollEvents();
}

void base::deallocate() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}
