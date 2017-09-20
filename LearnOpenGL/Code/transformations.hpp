//
//  transformations.hpp
//  LearnOpenGL
//
//  Created by pfjhetg on 2017/9/20.
//  Copyright © 2017年 pfjhetg. All rights reserved.
//

#ifndef transformations_hpp
#define transformations_hpp

#include "base.hpp"

class transformations: public base {
public:
    transformations();
    transformations(GLFWwindow *window);
    virtual void loadShader();
    virtual void renderLoop();
    virtual void deallocate();
};

#endif /* transformations_hpp */
