//
//  advanced_glsl_ubo.hpp
//  LearnOpenGL
//
//  Created by pfjhetg on 2017/10/13.
//  Copyright © 2017年 pfjhetg. All rights reserved.
//

#ifndef advanced_glsl_ubo_hpp
#define advanced_glsl_ubo_hpp

#include "base.hpp"

class advanced_glsl_ubo: public base {
public:
    Shader *shaderRed;
    Shader *shaderGreen;
    Shader *shaderBlue;
    Shader *shaderYellow;
    unsigned int uboMatrices;
    unsigned int cubeVAO, cubeVBO;
    advanced_glsl_ubo(GLFWwindow *window);
    void loadShader();
    void renderLoop();
    void deallocate();
    
};

#endif /* advanced_glsl_ubo_hpp */
