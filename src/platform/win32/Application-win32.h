
#ifndef __SKYTREE_APPLICATION_WIN32_H__
#define __SKYTREE_APPLICATION_WIN32_H__

#include "../../Application.hpp"

ST_NS_B

class ApplicationWin : public Application {
public:
	virtual ~ApplicationWin();

	static Application* getInstance();

	virtual int run();
	virtual Lang getCurrentLanguage();
	virtual Platform getTargetPlatform();

protected:
	ApplicationWin();
};

ST_NS_E

#endif

