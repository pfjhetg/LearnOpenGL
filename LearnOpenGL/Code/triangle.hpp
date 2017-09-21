//
//  triangle.hpp
//  LearnOpenGL
//
//  Created by pfjhetg on 2017/9/19.
//  Copyright © 2017年 pfjhetg. All rights reserved.
//

#ifndef triangle_hpp
#define triangle_hpp

#include "base.hpp"

class triangle: public base {
public:
    triangle(GLFWwindow *window);
    void loadShader();
};

#endif /* triangle_hpp */
