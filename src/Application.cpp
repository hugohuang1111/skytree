
#include "Application.hpp"

ST_NS_B

Application::Application() : _startupScript("") {
}

Application::~Application() {
}

void Application::setStartupScript(const std::string& startupScriptFile) {
	_startupScript = startupScriptFile;
}

ST_NS_E


