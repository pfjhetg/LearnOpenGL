//
//  base.hpp
//  LearnOpenGL
//
//  Created by pfjhetg on 2017/9/19.
//  Copyright © 2017年 pfjhetg. All rights reserved.
//

#ifndef base_hpp
#define base_hpp

#include "shader.h"

class base
{
private:
    GLFWwindow *window;
    Shader *shader;
    unsigned int VBO, VAO, EBO;
public:
    base();
    base(GLFWwindow *window);
    void loadShader();
    void renderLoop();
    void deallocate();
    
};

#endif /* base_hpp */
