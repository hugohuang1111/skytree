
#ifndef __SKYTREE_COMPONENT_H_
#define __SKYTREE_COMPONENT_H_

#include "Macro.h"
#include "Object.hpp"

ST_NS_B

class Component : public Object {
public:
	Component();
	~Component();

	int getID();
};

ST_NS_E
#endif
