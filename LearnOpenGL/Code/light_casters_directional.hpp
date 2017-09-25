//
//  light_casters_directional.hpp
//  LearnOpenGL
//
//  Created by pfjhetg on 2017/9/25.
//  Copyright © 2017年 pfjhetg. All rights reserved.
//

#ifndef light_casters_directional_hpp
#define light_casters_directional_hpp

#include "base.hpp"

class light_casters_directional: public base {
public:
    Shader *lightingShader;
    Shader *lampShader;
    unsigned int diffuseMap;
    unsigned int specularMap;
    unsigned int cubeVAO, lightVAO;
    light_casters_directional(GLFWwindow *window);
    void loadShader();
    void renderLoop();
    void deallocate();
};

#endif /* light_casters_directional_hpp */
