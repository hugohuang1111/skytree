
#ifndef __SKYTREE_GLVIEW_H_
#define __SKYTREE_GLVIEW_H_

#include "Macro.h"

ST_NS_B

class GLView {
public:
	GLView();
	virtual ~GLView();

    virtual void end() = 0;
    virtual bool isOpenGLReady() = 0;
    virtual bool windowShouldClose() = 0;
    virtual void pollEvents();
};


ST_NS_E
#endif
