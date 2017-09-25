//
//  multiple_lights.hpp
//  LearnOpenGL
//
//  Created by pfjhetg on 2017/9/25.
//  Copyright © 2017年 pfjhetg. All rights reserved.
//

#ifndef multiple_lights_hpp
#define multiple_lights_hpp

#include "base.hpp"

class multiple_lights: public base {
public:
    Shader *lightingShader;
    Shader *lampShader;
    unsigned int diffuseMap;
    unsigned int specularMap;
    unsigned int cubeVAO, lightVAO;
    multiple_lights(GLFWwindow *window);
    void loadShader();
    void renderLoop();
    void deallocate();
};

#endif /* multiple_lights_hpp */
