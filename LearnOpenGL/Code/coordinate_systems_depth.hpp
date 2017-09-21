//
//  coordinate_systems_depth.hpp
//  LearnOpenGL
//
//  Created by pfjhetg on 2017/9/20.
//  Copyright © 2017年 pfjhetg. All rights reserved.
//

#ifndef coordinate_systems_depth_hpp
#define coordinate_systems_depth_hpp

#include "base.hpp"

class coordinate_systems_depth: public base {
public:
    coordinate_systems_depth(GLFWwindow *window);
    void loadShader();
    void renderLoop();
};
#endif /* coordinate_systems_depth_hpp */
