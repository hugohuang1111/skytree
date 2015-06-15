
#ifndef __SKYTREE_UUID_H_
#define __SKYTREE_UUID_H_

#include "Macro.h"

ST_NS_B

class UUID {
public:
    UUID();
    ~UUID();

    static int create();
};

ST_NS_E
#endif
