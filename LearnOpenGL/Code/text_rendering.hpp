//
//  text_rendering.hpp
//  LearnOpenGL
//
//  Created by pfjhetg on 2017/10/18.
//  Copyright © 2017年 pfjhetg. All rights reserved.
//

#ifndef text_rendering_hpp
#define text_rendering_hpp

#include "base.hpp"

class text_rendering: public base {
public:
    Shader *screenShader;
    text_rendering(GLFWwindow *window);
    void loadShader();
    void renderLoop();
    void deallocate();
};

#endif /* text_rendering_hpp */
