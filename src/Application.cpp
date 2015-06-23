
#include "Application.hpp"

ST_NS_B

Application::Application() : _startupScript("") {
}

Application::~Application() {
}

void Application::setStartupScript(const std::string& startupScriptFile) {
	_startupScript = startupScriptFile;
}

void Application::initGLContextAttrs() {
}

bool Application::launched() {
	return SUCCESS;
}

void Application::suspend() {
}

void Application::resume() {
}

ST_NS_E


