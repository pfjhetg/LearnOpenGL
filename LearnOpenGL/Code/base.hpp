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

class base {
public:
    GLFWwindow *window;
    Shader *shader;
    Camera *camera;
    unsigned int VBO, VAO, EBO;
    unsigned int texture1, texture2;
    
    base();
    base(GLFWwindow *window);
    virtual void loadShader();
    virtual void renderLoop();
    virtual void deallocate();
    virtual unsigned int loadTexture(char *path);
    
};

#endif /* base_hpp */
