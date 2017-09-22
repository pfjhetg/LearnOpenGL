//
//  lighting_maps_diffuse.hpp
//  LearnOpenGL
//
//  Created by pfjhetg on 2017/9/22.
//  Copyright © 2017年 pfjhetg. All rights reserved.
//

#ifndef lighting_maps_diffuse_hpp
#define lighting_maps_diffuse_hpp

#include "base.hpp"

class lighting_maps_diffuse: public base {
public:
    Shader *lightingShader;
    Shader *lampShader;
    unsigned int diffuseMap;
    unsigned int cubeVAO, lightVAO;
    lighting_maps_diffuse(GLFWwindow *window);
    void loadShader();
    void renderLoop();
    void deallocate();
};

#endif /* lighting_maps_diffuse_hpp */
