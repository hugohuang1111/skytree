
#ifndef __SKYTREE_GLVIEW_H_
#define __SKYTREE_GLVIEW_H_

#include "Macro.h"
#include "../../math/Vec2.h"

ST_NS_B

class GLView {
public:
    GLView();
    virtual ~GLView();

    virtual void init(const std::string title, Vec2 size) = 0;
    virtual void end() = 0;
    virtual bool isOpenGLReady() = 0;
    virtual bool windowShouldClose() = 0;
    virtual void pollEvents();
};


ST_NS_E
#endif
