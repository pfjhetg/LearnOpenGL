//
//  lighting_maps_specular.hpp
//  LearnOpenGL
//
//  Created by pfjhetg on 2017/9/25.
//  Copyright © 2017年 pfjhetg. All rights reserved.
//

#ifndef lighting_maps_specular_hpp
#define lighting_maps_specular_hpp
#include "base.hpp"

class lighting_maps_specular: public base {
public:
    Shader *lightingShader;
    Shader *lampShader;
    unsigned int diffuseMap;
    unsigned int specularMap;
    unsigned int cubeVAO, lightVAO;
    lighting_maps_specular(GLFWwindow *window);
    void loadShader();
    void renderLoop();
    void deallocate();
};

#endif /* lighting_maps_specular_hpp */
