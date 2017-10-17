//
//  anti_aliasing_post_processing.hpp
//  LearnOpenGL
//
//  Created by pfjhetg on 2017/10/17.
//  Copyright © 2017年 pfjhetg. All rights reserved.
//

#ifndef anti_aliasing_post_processing_hpp
#define anti_aliasing_post_processing_hpp

#include "base.hpp"

class anti_aliasing_post_processing: public base {
public:
    Shader *screenShader;
    unsigned int cubeVAO, cubeVBO;
    unsigned int quadVAO, quadVBO;
    unsigned int framebuffer;
    unsigned int intermediateFBO;
    unsigned int rbo;
    unsigned int screenTexture;
    anti_aliasing_post_processing(GLFWwindow *window);
    void loadShader();
    void renderLoop();
    void deallocate();
};

#endif /* anti_aliasing_post_processing_hpp */
