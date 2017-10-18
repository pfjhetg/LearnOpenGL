//
//  base.hpp
//  LearnOpenGL
//
//  Created by pfjhetg on 2017/9/19.
//  Copyright © 2017年 pfjhetg. All rights reserved.
//

#ifndef base_hpp
#define base_hpp

#include "learnopengl.h"
#include "shader.h"
#include "model.h"

// Holds all state information relevant to a character as loaded using FreeType
struct Character {
    GLuint TextureID;   // ID handle of the glyph texture
    glm::ivec2 Size;    // Size of glyph
    glm::ivec2 Bearing;  // Offset from baseline to left/top of glyph
    GLuint Advance;    // Horizontal offset to advance to next glyph
};

class base {
public:
    GLFWwindow *window;
    Shader *shader;
    Camera *camera;
    unsigned int VBO, VAO, EBO;
    unsigned int texture1, texture2;
    std::map<GLchar, Character> Characters;
    
    base();
    base(GLFWwindow *window);
    virtual void processInput(GLFWwindow *window);
    virtual void loadShader();
    virtual void renderLoop();
    virtual void deallocate();
    virtual unsigned int loadTexture(char *path);
    virtual unsigned int loadCubemap(vector<std::string> faces);
    virtual void RenderText(Shader &shader, std::string text, GLfloat x, GLfloat y, GLfloat scale, glm::vec3 color);

    
};

#endif /* base_hpp */
