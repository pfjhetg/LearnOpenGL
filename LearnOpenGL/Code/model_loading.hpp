//
//  model_loading.hpp
//  LearnOpenGL
//
//  Created by pfjhetg on 2017/9/29.
//  Copyright © 2017年 pfjhetg. All rights reserved.
//

#ifndef model_loading_hpp
#define model_loading_hpp

#include "base.hpp"

class model_loading: public base {
public:
    Shader *lightingShader;
    Shader *lampShader;
    Model *ourModel;
    unsigned int diffuseMap;
    unsigned int specularMap;
    unsigned int cubeVAO, lightVAO;
    model_loading(GLFWwindow *window);
    void loadShader();
    void renderLoop();
    void deallocate();
};

#endif /* model_loading_hpp */
