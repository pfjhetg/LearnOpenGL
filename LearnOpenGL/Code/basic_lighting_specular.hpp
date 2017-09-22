//
//  basic_lighting_specular.hpp
//  LearnOpenGL
//
//  Created by pfjhetg on 2017/9/22.
//  Copyright © 2017年 pfjhetg. All rights reserved.
//

#ifndef basic_lighting_specular_hpp
#define basic_lighting_specular_hpp

#include "base.hpp"

class basic_lighting_specular: public base {
public:
    Shader *lightingShader;
    Shader *lampShader;
    unsigned int cubeVAO, lightVAO;
    basic_lighting_specular(GLFWwindow *window);
    void loadShader();
    void renderLoop();
    void deallocate();
};

#endif /* basic_lighting_specular_hpp */
