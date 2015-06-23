
#ifndef __SKYTREE_TEMP_H_
#define __SKYTREE_TEMP_H_

#include "../../Macro.h"
#include "../../GLView.hpp"

ST_NS_B

class GLViewWin : public GLView {
public:
	GLViewWin();
	~GLViewWin();

    virtual void end() override;
    virtual bool isOpenGLReady() override;
    virtual bool windowShouldClose() override;
};

ST_NS_E
#endif
