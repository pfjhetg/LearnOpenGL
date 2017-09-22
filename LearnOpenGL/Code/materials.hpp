//
//  materials.hpp
//  LearnOpenGL
//
//  Created by pfjhetg on 2017/9/22.
//  Copyright © 2017年 pfjhetg. All rights reserved.
//

#ifndef materials_hpp
#define materials_hpp

#include "base.hpp"

class materials: public base {
public:
    Shader *lightingShader;
    Shader *lampShader;
    unsigned int cubeVAO, lightVAO;
    materials(GLFWwindow *window);
    void loadShader();
    void renderLoop();
    void deallocate();
};

#endif /* materials_hpp */
