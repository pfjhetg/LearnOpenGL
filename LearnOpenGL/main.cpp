#include "triangle.hpp"
#include "textures.hpp"
#include "transformations.hpp"
#include "coordinate_systems.hpp"
#include "coordinate_systems_depth.hpp"
#include "camera_circle.hpp"
#include "colors.hpp"
#include "basic_lighting_specular.hpp"
#include "materials.hpp"
#include "lighting_maps_diffuse.hpp"
#include "lighting_maps_specular.hpp"
#include "light_casters_directional.hpp"
#include "multiple_lights.hpp"
#include "model_loading.hpp"
#include "stencil_testing.hpp"
#include "framebuffers.hpp"
#include "cubemaps_skybox.hpp"
#include "advanced_glsl_ubo.hpp"
#include "geometry_shader_houses.hpp"
#include "instancing_quads.hpp"
#include "asteroids.hpp"


void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void processInput(GLFWwindow *window);

base *base;

int main() {
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // uncomment this statement to fix compilation on OS X
#endif
    
    // glfw window creation
    // --------------------
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetCursorPosCallback(window, mouse_callback);
    
    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    
//    base = new triangle(window);//三角形
//    base = new textures(window);//纹理
//    base = new transformations(window);//变换
//    base = new coordinate_systems(window);//坐标系统
//    base = new coordinate_systems_depth(window);//坐标系统,Zbuff
//    base = new camera_circle(window);//摄像机
//    base = new colors(window);//颜色//有bug,去掉鼠标,键盘的处理,用漫游替换
//    base = new basic_lighting_specular(window);//基础光照,有bug,去掉鼠标,键盘的处理,用漫游替换
//    base = new materials(window);//基础光照,有bug,去掉鼠标,键盘的处理,用漫游替换
//    base = new lighting_maps_diffuse(window);//基础光照-漫反射,有bug,去掉鼠标,键盘的处理,用漫游替换
//    base = new lighting_maps_specular(window);//基础光照-高光反射,有bug,去掉鼠标,键盘的处理,用漫游替换
//    base = new light_casters_directional(window);//平行光,有bug,去掉鼠标,键盘的处理,用漫游替换
//    base = new multiple_lights(window);//多光源,有bug,去掉鼠标,键盘的处理,用漫游替换
//    base = new model_loading(window);//加载模型
//    base = new stencil_testing(window);//模版测试(物体轮廓)
//    base = new framebuffers(window);//帧缓冲
//    base = new cubemaps_skybox(window);//天空盒子
//    base = new advanced_glsl_ubo(window);//使用Uniform缓冲
//    base = new geometry_shader_houses(window);//几何着色器画房子
//    base = new instancing_quads(window);//实例化quad
    base = new asteroids(window);//行星带:1
    
    // build and compile our shader program
    base->loadShader();
    
    // render loop
    // -----------
    while (!glfwWindowShouldClose(window)) {
        // input
        // -----
        base->processInput(window);
        
        // render
        base->renderLoop();
    }
    
    base->deallocate();
 
    // glfw: terminate, clearing all previously allocated GLFW resources.
    //当渲染循环结束后我们需要正确释放/删除之前的分配的所有资源
    // ------------------------------------------------------------------
    glfwTerminate();
    return 0;
}


// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    // make sure the viewport matches the new window dimensions; note that width and
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}

void mouse_callback(GLFWwindow* window, double xpos, double ypos) {
    if (firstMouse) {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }
    
    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top
    
    lastX = xpos;
    lastY = ypos;
    
    base->camera->ProcessMouseMovement(xoffset, yoffset);
}
