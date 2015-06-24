
#ifndef __SKYTREE_TEMP_H_
#define __SKYTREE_TEMP_H_

#include "../../Macro.h"
#include "../../GLView.hpp"
#include "glfw3.h"



ST_NS_B

class GLViewWin : public GLView {
public:
	GLViewWin();
	~GLViewWin();

    virtual void init(const std::string title, Vec2 size) override;
    virtual void end() override;
    virtual bool isOpenGLReady() override;
    virtual bool windowShouldClose() override;

    // GLFW callbacks
    void onGLFWError(int errorID, const char* errorDesc);
    void onGLFWMouseCallBack(GLFWwindow* window, int button, int action, int modify);
    void onGLFWMouseMoveCallBack(GLFWwindow* window, double x, double y);
    void onGLFWMouseScrollCallback(GLFWwindow* window, double x, double y);
    void onGLFWKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
    void onGLFWCharCallback(GLFWwindow* window, unsigned int character);
    void onGLFWWindowPosCallback(GLFWwindow* windows, int x, int y);
    void onGLFWframebuffersize(GLFWwindow* window, int w, int h);
    void onGLFWWindowSizeFunCallback(GLFWwindow *window, int width, int height);
    void onGLFWWindowIconifyCallback(GLFWwindow* window, int iconified);

private:
    GLFWwindow*     _glfwWindow;
};

ST_NS_E
#endif
