
#ifndef __SKYTREE_REF_H_
#define __SKYTREE_REF_H_

#include <memory>
#include "Macro.h"

ST_NS_B


class Ref : public std::enable_shared_from_this<Ref>{
public:
	Ref();
	~Ref();
};

ST_NS_E
#endif
