
#include "SkyTree.h"
#include "./platform/win32/Application-win32.hpp"

US_NS_SKYTREE;

int main() {
    skytree::Application* app = skytree::ApplicationWin::getInstance();

    app->run();

    return 0;
}

