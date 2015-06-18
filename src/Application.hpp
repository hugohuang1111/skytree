
#ifndef __SKYTREE_APPLICATION_H_
#define __SKYTREE_APPLICATION_H_

#include <string>

#include "Common.hpp"


ST_NS_B

class Application {
public:
    virtual ~Application();

    virtual int run() = 0;
    virtual Lang getCurrentLanguage() = 0;
    virtual Platform getTargetPlatform() = 0;
	virtual void setStartupScript(const std::string& startupScriptFile);
    const std::string& getStartupScript() { return _startupScript; };

protected:
	Application();

protected:
	std::string _startupScript;
};


ST_NS_E
#endif
