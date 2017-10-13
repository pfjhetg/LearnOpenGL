//
//  base.hpp
//  LearnOpenGL
//
//  Created by pfjhetg on 2017/9/19.
//  Copyright © 2017年 pfjhetg. All rights reserved.
//

#ifndef base_hpp
#define base_hpp

#include "learnopengl.h"
#include "shader.h"
#include "model.h"

class base {
public:
    GLFWwindow *window;
    Shader *shader;
    Camera *camera;
    unsigned int VBO, VAO, EBO;
    unsigned int texture1, texture2;
    
    base();
    base(GLFWwindow *window);
    virtual void processInput(GLFWwindow *window);
    virtual void loadShader();
    virtual void renderLoop();
    virtual void deallocate();
    virtual unsigned int loadTexture(char *path);
    virtual unsigned int loadCubemap(vector<std::string> faces);

    
};

#endif /* base_hpp */
