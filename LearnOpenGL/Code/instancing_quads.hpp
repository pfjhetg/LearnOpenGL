//
//  instancing_quads.hpp
//  LearnOpenGL
//
//  Created by pfjhetg on 2017/10/16.
//  Copyright © 2017年 pfjhetg. All rights reserved.
//

#ifndef instancing_quads_hpp
#define instancing_quads_hpp

#include "base.hpp"

class instancing_quads: public base {
public:
    unsigned int instanceVBO, quadVAO, quadVBO;
    
    instancing_quads(GLFWwindow *window);
    void loadShader();
    void renderLoop();
    void deallocate();
    
};

#endif /* instancing_quads_hpp */
