//
//  asteroids_instanced.hpp
//  LearnOpenGL
//
//  Created by pfjhetg on 2017/10/17.
//  Copyright © 2017年 pfjhetg. All rights reserved.
//

#ifndef asteroids_instanced_hpp
#define asteroids_instanced_hpp

#include "base.hpp"

class asteroids_instanced: public base {
public:
    unsigned int instanceVBO, quadVAO, quadVBO;
    unsigned int buffer;
    unsigned int amount = 100000;
    glm::mat4* modelMatrices;
    asteroids_instanced(GLFWwindow *window);
    Shader *asteroidShader;
    Shader *planetShader;
    Model *rock;
    Model *planet;
    void loadShader();
    void renderLoop();
    void deallocate();
};

#endif /* asteroids_instanced_hpp */
