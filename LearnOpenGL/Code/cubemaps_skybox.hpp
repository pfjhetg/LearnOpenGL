//
//  cubemaps_skybox.hpp
//  LearnOpenGL
//
//  Created by pfjhetg on 2017/10/12.
//  Copyright © 2017年 pfjhetg. All rights reserved.
//

#ifndef cubemaps_skybox_hpp
#define cubemaps_skybox_hpp

#include "base.hpp"

class cubemaps_skybox: public base {
public:
    Shader *shader;
    Shader *skyboxShader;
    Model *ourModel;
    unsigned int diffuseMap;
    unsigned int specularMap;
    unsigned int framebuffer, textureColorbuffer;
    unsigned int cubeVAO, cubeVBO, skyboxVAO, skyboxVBO;
    unsigned int cubeTexture, cubemapTexture;
    cubemaps_skybox(GLFWwindow *window);
    void loadShader();
    void renderLoop();
    void deallocate();
    
};

#endif /* cubemaps_skybox_hpp */
