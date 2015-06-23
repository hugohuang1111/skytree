
#ifndef __SKYTREE_APPLICATION_WIN32_H__
#define __SKYTREE_APPLICATION_WIN32_H__

#include <windows.h>
#include "../../Application.hpp"

ST_NS_B

class ApplicationWin : public Application {
public:
	virtual ~ApplicationWin();

	static Application* getInstance();

	virtual int run();
	virtual Lang getCurrentLanguage();
	virtual Platform getTargetPlatform();
	virtual void setAnimationInterval(double interval);

protected:
	ApplicationWin();

private:
    LARGE_INTEGER   _animationInterval;
};

ST_NS_E

#endif

