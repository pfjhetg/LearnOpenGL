//
//  asteroids.hpp
//  LearnOpenGL
//
//  Created by pfjhetg on 2017/10/17.
//  Copyright © 2017年 pfjhetg. All rights reserved.
//

#ifndef asteroids_hpp
#define asteroids_hpp

#include "base.hpp"

class asteroids: public base {
public:
    unsigned int instanceVBO, quadVAO, quadVBO;
    unsigned int amount = 1000;
    glm::mat4* modelMatrices;
    asteroids(GLFWwindow *window);
    Model *rock;
    Model *planet;
    void loadShader();
    void renderLoop();
    void deallocate();
    
};

#endif /* asteroids_hpp */
