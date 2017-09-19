
#version 330 core
// 通过layout (location = 0)设定了输入变量的位置值(Location)
// GLSL中每一个attribute变量都有一个“位置”值(Location)，在ShaderProgram链接(link)前，可以Bind之，链接之后，可以Get之
// 关键字用于一个具体变量前，用于显式标明该变量的一些布局属性，这里就是显式设定了该attribute变量的位置值(location)，其作用跟ShaderProgram(着色程序)链接前调用glBindAttribLocation来设定atribute变量的位置值是等效的
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;

out vec3 ourColor;

void main()
{
    gl_Position = vec4(aPos, 1.0);
    ourColor = aColor;
}
