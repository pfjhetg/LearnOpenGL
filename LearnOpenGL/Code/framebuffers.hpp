//
//  framebuffers.hpp
//  LearnOpenGL
//
//  Created by pfjhetg on 2017/10/10.
//  Copyright © 2017年 pfjhetg. All rights reserved.
//

#ifndef framebuffers_hpp
#define framebuffers_hpp

#include "base.hpp"

class framebuffers: public base {
public:
    Shader *shader;
    Shader *screenShader;
    Model *ourModel;
    unsigned int diffuseMap;
    unsigned int specularMap;
    unsigned int framebuffer, textureColorbuffer;
    unsigned int cubeVAO, cubeVBO, planeVAO, planeVBO, quadVAO, quadVBO, RBO;
    unsigned int cubeTexture, floorTexture;
    framebuffers(GLFWwindow *window);
    void loadShader();
    void renderLoop();
    void deallocate();
    
};

#endif /* framebuffers_hpp */
