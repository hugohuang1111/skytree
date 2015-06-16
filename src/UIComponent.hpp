
#ifndef __SKYTREE_UICOMPONENT_H_
#define __SKYTREE_UICOMPONENT_H_

#include "Macro.h"

ST_NS_B

class UIComponent {
public:
	UIComponent();
	~UIComponent();

    virtual int draw() = 0;
};

ST_NS_E
#endif
