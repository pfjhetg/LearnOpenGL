//
//  textures.hpp
//  LearnOpenGL
//
//  Created by pfjhetg on 2017/9/19.
//  Copyright © 2017年 pfjhetg. All rights reserved.
//

#ifndef textures_hpp
#define textures_hpp

#include "base.hpp"

class textures: public base {
public:
    textures();
    textures(GLFWwindow *window);
    virtual void loadShader();
    virtual void renderLoop();
    virtual void deallocate();
};

#endif /* textures_hpp */
