//
//  colors.hpp
//  LearnOpenGL
//
//  Created by pfjhetg on 2017/9/21.
//  Copyright © 2017年 pfjhetg. All rights reserved.
//

#ifndef colors_hpp
#define colors_hpp

#include "base.hpp"

class colors: public base {
public:
    Shader *lightingShader;
    Shader *lampShader;
    unsigned int cubeVAO, lightVAO;
    colors(GLFWwindow *window);
    void loadShader();
    void renderLoop();
    void deallocate();
};

#endif /* colors_hpp */
