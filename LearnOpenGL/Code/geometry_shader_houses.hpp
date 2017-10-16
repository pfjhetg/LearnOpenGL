//
//  geometry_shader_houses.hpp
//  LearnOpenGL
//
//  Created by pfjhetg on 2017/10/16.
//  Copyright © 2017年 pfjhetg. All rights reserved.
//

#ifndef geometry_shader_houses_hpp
#define geometry_shader_houses_hpp

#include "base.hpp"

class geometry_shader_houses: public base {
public:
    unsigned int uboMatrices;
    unsigned int cubeVAO, cubeVBO;
    geometry_shader_houses(GLFWwindow *window);
    void loadShader();
    void renderLoop();
    void deallocate();
    
};

#endif /* geometry_shader_houses_hpp */
