//
//  textures.cpp
//  LearnOpenGL
//
//  Created by pfjhetg on 2017/9/19.
//  Copyright © 2017年 pfjhetg. All rights reserved.
//

#include "textures.hpp"

textures::textures() {
    
}

textures::textures(GLFWwindow *window) {
   this->window = window;
}

void textures::loadShader() {
    this->shader = new Shader("/Users/pfjhetg/Desktop/LearnOpenGL/LearnOpenGL/Shaders/4.1.texture.vert", "/Users/pfjhetg/Desktop/LearnOpenGL/LearnOpenGL/Shaders/4.1.texture.frag");
    
    float vertices[] = {
        // positions          // colors           // texture coords
        0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f, // top right
        0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f, // bottom right
        -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f, // bottom left
        -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f  // top left
    };
    
    unsigned int indices[] = {
        0, 1, 3, // first triangle
        1, 2, 3  // second triangle
    };
    
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    
    glBindVertexArray(VAO);
    
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    
    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);
    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    //texture coord attribute
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);
    
    //texture
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    
    // 纹理环绕
    // 第一个参数指定纹理目标,我们使用的2D纹理;
    // 第二个参数指定设置的选项与应用的纹理轴,我们配置的是WRAP选项,并且指定S和T轴;
    // 第三个参数需要传递一个环绕方式(Wrapping)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    
    // 纹理过滤
    // 第一个参数和上面类似
    // 第二个参数表明是放大还是缩小
    // 第三个参数是设置过滤方式,默认是GL_NEAREST,当启用多级渐远纹理时候,这里可以设置成为多级渐远提供的几个过滤方式,特别注意的是,放大是没法使用多级渐远纹理过滤的,因为多级渐远本来适用于缩小的
    glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    
    int width, height, nrChannels;
    unsigned char *data = stbi_load("/Users/pfjhetg/Desktop/LearnOpenGL/LearnOpenGL/Sources/wall.jpg", &width, &height, &nrChannels, 0);
    if (data) {
        // 当调用glTexImage2D时，当前绑定的纹理对象就会被附加上纹理图像。
        // 第一个参数指定了纹理目标(Target)。设置为GL_TEXTURE_2D意味着会生成与当前绑定的纹理对象在同一个目标上的纹理（任何绑定到GL_TEXTURE_1D和GL_TEXTURE_3D的纹理不会受到影响）。
        // 第二个参数为纹理指定多级渐远纹理的级别，如果你希望单独手动设置每个多级渐远纹理的级别的话。这里我们填0，也就是基本级别
        // 第三个参数告诉OpenGL我们希望把纹理储存为何种格式。我们的图像只有RGB值，因此我们也把纹理储存为RGB值。
        // 第六个参数应该总是被设为0（历史遗留的问题）。
        // 第七第八个参数定义了源图的格式和数据类型。我们使用RGB值加载这个图像，并把它们储存为char(byte)数组，我们将会传入对应值
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    } else {
        std::cout << "Failed to load texture" << std::endl;
    }
    // 释放图像内存
    stbi_image_free(data);

}

void textures::renderLoop() {
    // render the triangle
    this->shader->use();
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    
    // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
    // -------------------------------------------------------------------------------
    glfwSwapBuffers(this->window);
    glfwPollEvents();
}

void textures::deallocate() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
}












