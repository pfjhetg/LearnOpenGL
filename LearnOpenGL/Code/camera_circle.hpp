//
//  camera_circle.hpp
//  LearnOpenGL
//
//  Created by pfjhetg on 2017/9/21.
//  Copyright © 2017年 pfjhetg. All rights reserved.
//

#ifndef camera_circle_hpp
#define camera_circle_hpp

#include "base.hpp"

class camera_circle: public base {
public:
    camera_circle();
    camera_circle(GLFWwindow *window);
    void loadShader();
    void renderLoop();
};

#endif /* camera_circle_hpp */
