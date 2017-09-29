//
//  learnopengl.h
//  LearnOpenGL
//
//  Created by pfjhetg on 2017/9/18.
//  Copyright © 2017年 pfjhetg. All rights reserved.
//

#ifndef learnopengl_h
#define learnopengl_h

#include "glad.h"
#include <GLFW/glfw3.h>

#include "stb_image.h"
#include "camera.h"


// settings
const unsigned int SCR_WIDTH = 1280;
const unsigned int SCR_HEIGHT = 960;

static float lastX = SCR_WIDTH / 2.0f;
static float lastY = SCR_HEIGHT / 2.0f;
static bool firstMouse = true;

// timing
static float deltaTime = 0.0f;
static float lastFrame = 0.0f;

// lighting
static glm::vec3 lightPos(1.2f, 1.0f, 2.0f);
#endif /* learnopengl_h */
