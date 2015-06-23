
#include "Director.hpp"
#include "Log.hpp"

ST_NS_B

static Director* gInstance = nullptr;

Director::Director() : _openGLView(nullptr) {
}

Director::~Director() {
}

Director* Director::getInstance(void) {
    if (nullptr == gInstance) {
        gInstance = new Director();
    }

    return gInstance;
}

void Director::setOpenGLView(GLView *openGLView) {
    _ASSERT(nullptr == _openGLView);
    _openGLView = openGLView;
}

void Director::start(void) {
}

void Director::loop(void) {
    LOG("director loop");
}

void Director::end(void) {
}

ST_NS_E
