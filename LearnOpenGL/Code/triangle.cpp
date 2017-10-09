//
//  triangle.cpp
//  LearnOpenGL
//
//  Created by pfjhetg on 2017/9/19.
//  Copyright © 2017年 pfjhetg. All rights reserved.
//

#include "triangle.hpp"

triangle::triangle(GLFWwindow *window) {
    this->window = window;
}

void triangle::loadShader() {
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
    
    // VAO 记录的是
    // 1.vertex attribute 的格式，由 glVertexAttribPointer 设置.
    // 2.vertex attribute 对应的 VBO 的名字, 由一对 glBindBuffer 和  glVertexAttribPointer 设置
    // 3.#当前#绑定的 GL_ELEMENT_ARRAY_BUFFER/GL_ARRAY_BUFFER 的名字，由 glBindBuffer 设置。
    
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    // 绑定顶点数组对象
    glBindVertexArray(VAO);
    
    
    // 绑定顶点缓冲对象
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    // 缓冲数据:把定点数据复制到缓冲的内存中
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
    // position attribute
    // glVertexAttribPointer函数告诉OpenGL该如何解析顶点数据（应用到逐个顶点属性上）
    // 第一个参数指定我们要配置的顶点属性,我们在顶点着色器中使用layout(location = 0)定义了position顶点属性的位置值(Location),它可以把顶点属性的位置值设置为0。因为我们希望把数据传递到这一个顶点属性中，所以这里我们传入0。
    // 第二个参数指定顶点属性的大小。顶点属性是一个vec3，它由3个值组成，所以大小是3.
    // 第三个参数指定数据的类型，这里是GL_FLOAT(GLSL中vec*都是由浮点数值组成的)
    // 第四个参数定义我们是否希望数据被标准化(Normalize)。如果我们设置为GL_TRUE，所有数据都会被映射到0（对于有符号型signed数据是-1）到1之间。我们把它设置为GL_FALSE
    // 第五个参数叫做步长(Stride)，它告诉我们在连续的顶点属性组之间的间隔
    // 最后一个参数的类型是void*，所以需要我们进行这个奇怪的强制类型转换。它表示位置数据在缓冲中起始位置的偏移量(Offset)。由于位置数据在数组的开头，所以这里是0。我们会在后面详细解释这个参数
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    // 定义了OpenGL该如何解释顶点数据，我们现在应该使用glEnableVertexAttribArray，以顶点属性位置值作为参数，启用顶点属性
    glEnableVertexAttribArray(0);
    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    
    // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
    // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
    // glBindVertexArray(0);
}
