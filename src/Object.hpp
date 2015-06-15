
#ifndef __SKYTREE_OBJECT_H_
#define __SKYTREE_OBJECT_H_

#include "Macro.h"

ST_NS_B

class Object {
public:
    Object();
    ~Object();

    int getID() { return id; };

private:
    int id;
};

ST_NS_E
#endif
