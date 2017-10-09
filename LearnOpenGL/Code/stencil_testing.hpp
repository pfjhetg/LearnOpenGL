//
//  stencil_testing.hpp
//  LearnOpenGL
//
//  Created by pfjhetg on 2017/10/9.
//  Copyright © 2017年 pfjhetg. All rights reserved.
//

#ifndef stencil_testing_hpp
#define stencil_testing_hpp

#include "base.hpp"
#include "model.h"

class stencil_testing: public base {
public:
    Shader *shader;
    Shader *shaderSingleColor;
    Model *ourModel;
    unsigned int diffuseMap;
    unsigned int specularMap;
    unsigned int cubeVAO, cubeVBO, planeVAO, planeVBO;
    unsigned int cubeTexture, floorTexture;
    stencil_testing(GLFWwindow *window);
    void loadShader();
    void renderLoop();
    void deallocate();
};

#endif /* stencil_testing_hpp */
