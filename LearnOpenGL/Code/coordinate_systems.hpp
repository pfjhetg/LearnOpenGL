//
//  coordinate_systems.hpp
//  LearnOpenGL
//
//  Created by pfjhetg on 2017/9/20.
//  Copyright © 2017年 pfjhetg. All rights reserved.
//

#ifndef coordinate_systems_hpp
#define coordinate_systems_hpp

#include "base.hpp"

class coordinate_systems: public base {
public:
    coordinate_systems();
    coordinate_systems(GLFWwindow *window);
    void loadShader();
    void renderLoop();
};


#endif /* coordinate_systems_hpp */
