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
    this->shader = new Shader("/Users/pfjhetg/Desktop/LearnOpenGL/LearnOpenGL/Shaders/3.3.shader.vert", "/Users/pfjhetg/Desktop/LearnOpenGL/LearnOpenGL/Shaders/3.3.shader.frag");
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
    glDeleteBuffers(1, &EBO);
}
