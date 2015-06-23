
#ifndef __SKYTREE_DIRECTOR_H_
#define __SKYTREE_DIRECTOR_H_

#include "Macro.h"
#include "Ref.hpp"
#include "GLView.hpp"

ST_NS_B

class Director : public Ref {
public:
    ~Director();
    static Director* Director::getInstance(void);

    inline GLView* getOpenGLView() { return _openGLView; }
    void setOpenGLView(GLView *openGLView);

    void start(void);
    void loop(void);
    void end(void);

private:
    Director();

    GLView *_openGLView;
};

ST_NS_E
#endif
