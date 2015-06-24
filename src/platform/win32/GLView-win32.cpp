
#include "GLView-win32.hpp"

ST_NS_B

class GLFWEventHandler {
public:
    static void onGLFWError(int errorID, const char* errorDesc) {
        if (_view)
            _view->onGLFWError(errorID, errorDesc);
    }

    static void onGLFWMouseCallBack(GLFWwindow* window, int button, int action, int modify) {
        if (_view)
            _view->onGLFWMouseCallBack(window, button, action, modify);
    }

    static void onGLFWMouseMoveCallBack(GLFWwindow* window, double x, double y) {
        if (_view)
            _view->onGLFWMouseMoveCallBack(window, x, y);
    }

    static void onGLFWMouseScrollCallback(GLFWwindow* window, double x, double y) {
        if (_view)
            _view->onGLFWMouseScrollCallback(window, x, y);
    }

    static void onGLFWKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
        if (_view)
            _view->onGLFWKeyCallback(window, key, scancode, action, mods);
    }

    static void onGLFWCharCallback(GLFWwindow* window, unsigned int character) {
        if (_view)
            _view->onGLFWCharCallback(window, character);
    }

    static void onGLFWWindowPosCallback(GLFWwindow* windows, int x, int y) {
        if (_view)
            _view->onGLFWWindowPosCallback(windows, x, y);
    }

    static void onGLFWframebuffersize(GLFWwindow* window, int w, int h) {
        if (_view)
            _view->onGLFWframebuffersize(window, w, h);
    }

    static void onGLFWWindowSizeFunCallback(GLFWwindow *window, int width, int height) {
        if (_view)
            _view->onGLFWWindowSizeFunCallback(window, width, height);
    }

    static void setGLViewImpl(GLViewWin* view) {
        _view = view;
    }

    static void onGLFWWindowIconifyCallback(GLFWwindow* window, int iconified) {
        if (_view)
        {
            _view->onGLFWWindowIconifyCallback(window, iconified);
        }
    }

private:
    static GLViewWin* _view;
};

GLViewWin::GLViewWin() {
    GLFWEventHandler::setGLViewImpl(this);
    glfwSetErrorCallback(GLFWEventHandler::onGLFWError);
    glfwInit();
}

GLViewWin::~GLViewWin() {
    GLFWEventHandler::setGLViewImpl(nullptr);
    glfwTerminate();
}

void GLViewWin::init(const std::string title, Vec2 size) {
    _glfwWindow = glfwCreateWindow(size.x, size.y, title.c_str(), nullptr, nullptr);
    glfwMakeContextCurrent(_glfwWindow);

    glfwSetMouseButtonCallback(_glfwWindow, GLFWEventHandler::onGLFWMouseCallBack);
    glfwSetCursorPosCallback(_glfwWindow, GLFWEventHandler::onGLFWMouseMoveCallBack);
    glfwSetScrollCallback(_glfwWindow, GLFWEventHandler::onGLFWMouseScrollCallback);
    glfwSetCharCallback(_glfwWindow, GLFWEventHandler::onGLFWCharCallback);
    glfwSetKeyCallback(_glfwWindow, GLFWEventHandler::onGLFWKeyCallback);
    glfwSetWindowPosCallback(_glfwWindow, GLFWEventHandler::onGLFWWindowPosCallback);
    glfwSetFramebufferSizeCallback(_glfwWindow, GLFWEventHandler::onGLFWframebuffersize);
    glfwSetWindowSizeCallback(_glfwWindow, GLFWEventHandler::onGLFWWindowSizeFunCallback);
    glfwSetWindowIconifyCallback(_glfwWindow, GLFWEventHandler::onGLFWWindowIconifyCallback);

    setFrameSize(rect.size.width, rect.size.height);

    // check OpenGL version at first
    const GLubyte* glVersion = glGetString(GL_VERSION);

    if (utils::atof((const char*)glVersion) < 1.5)
    {
        char strComplain[256] = { 0 };
        sprintf(strComplain,
            "OpenGL 1.5 or higher is required (your version is %s). Please upgrade the driver of your video card.",
            glVersion);
        MessageBox(strComplain, "OpenGL version too old");
        return false;
    }

    initGlew();

    // Enable point size by default.
    glEnable(GL_VERTEX_PROGRAM_POINT_SIZE);
}

void GLViewWin::end() {
}

bool GLViewWin::isOpenGLReady() {
    return true;
}

bool GLViewWin::windowShouldClose() {
    return false;
}


void GLViewWin::onGLFWError(int errorID, const char* errorDesc) {
}

void GLViewWin::onGLFWMouseCallBack(GLFWwindow* window, int button, int action, int modify) {
}

void GLViewWin::onGLFWMouseMoveCallBack(GLFWwindow* window, double x, double y) {
}

void GLViewWin::onGLFWMouseScrollCallback(GLFWwindow* window, double x, double y) {
}

void GLViewWin::onGLFWKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
}

void GLViewWin::onGLFWCharCallback(GLFWwindow* window, unsigned int character) {
}

void GLViewWin::onGLFWWindowPosCallback(GLFWwindow* windows, int x, int y) {
}

void GLViewWin::onGLFWframebuffersize(GLFWwindow* window, int w, int h) {
}

void GLViewWin::onGLFWWindowSizeFunCallback(GLFWwindow *window, int width, int height) {
}

void GLViewWin::onGLFWWindowIconifyCallback(GLFWwindow* window, int iconified) {
}


ST_NS_E
