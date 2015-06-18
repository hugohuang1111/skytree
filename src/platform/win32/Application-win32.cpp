
#include <windows.h>
#include <tchar.h>

//#include <WinNls.h>
//#include <winreg.h>
//#include <shellapi.h>
//#include <winerror.h>

#include "Application-win32.h"


ST_NS_B

static void PVRFrameEnableControlWindow(bool bEnable)
{
	HKEY hKey = 0;

	// Open PVRFrame control key, if not exist create it.
	if (ERROR_SUCCESS != RegCreateKeyExW(HKEY_CURRENT_USER,
		L"Software\\Imagination Technologies\\PVRVFRame\\STARTUP\\",
		0,
		0,
		REG_OPTION_NON_VOLATILE,
		KEY_ALL_ACCESS,
		0,
		&hKey,
		nullptr))
	{
		return;
	}

	const WCHAR* wszValue = L"hide_gui";
	const WCHAR* wszNewData = (bEnable) ? L"NO" : L"YES";
	WCHAR wszOldData[256] = { 0 };
	DWORD   dwSize = sizeof(wszOldData);
	LSTATUS status = RegQueryValueExW(hKey, wszValue, 0, nullptr, (LPBYTE)wszOldData, &dwSize);
	if (ERROR_FILE_NOT_FOUND == status              // the key not exist
		|| (ERROR_SUCCESS == status                 // or the hide_gui value is exist
		&& 0 != wcscmp(wszNewData, wszOldData)))    // but new data and old data not equal
	{
		dwSize = sizeof(WCHAR) * (wcslen(wszNewData) + 1);
		RegSetValueEx(hKey, wszValue, 0, REG_SZ, (const BYTE *)wszNewData, dwSize);
	}

	RegCloseKey(hKey);
}


static ApplicationWin* _Application = nullptr;


ApplicationWin::~ApplicationWin() {
}

Application* ApplicationWin::getInstance() {
	ApplicationWin* app = _Application;
	if (nullptr == app) {
		app = new ApplicationWin();
		_Application = app;
	}

	return app;
}

int ApplicationWin::run() {
	PVRFrameEnableControlWindow(false);

	// Main message loop:
	LARGE_INTEGER nLast;
	LARGE_INTEGER nNow;

	QueryPerformanceCounter(&nLast);

	//initGLContextAttrs();

	//// Initialize instance and cocos2d.
	//if (!applicationDidFinishLaunching())
	//{
	//	return 1;
	//}

	//auto director = Director::getInstance();
	//auto glview = director->getOpenGLView();

	//// Retain glview to avoid glview being released in the while loop
	//glview->retain();

	//while (!glview->windowShouldClose())
	//{
	//	QueryPerformanceCounter(&nNow);
	//	if (nNow.QuadPart - nLast.QuadPart > _animationInterval.QuadPart)
	//	{
	//		nLast.QuadPart = nNow.QuadPart - (nNow.QuadPart % _animationInterval.QuadPart);

	//		director->mainLoop();
	//		glview->pollEvents();
	//	}
	//	else
	//	{
	//		Sleep(1);
	//	}
	//}

	//// Director should still do a cleanup if the window was closed manually.
	//if (glview->isOpenGLReady())
	//{
	//	director->end();
	//	director->mainLoop();
	//	director = nullptr;
	//}
	//glview->release();
	return 0;
}

Lang ApplicationWin::getCurrentLanguage() {
	Lang ret = Lang::ENGLISH;

	LCID localeID = GetUserDefaultLCID();
	unsigned short primaryLanguageID = localeID & 0xFF;

	switch (primaryLanguageID) {
	default:
		ret = Lang::ENGLISH;
		break;
	}

	return ret;
}

Platform ApplicationWin::getTargetPlatform() {
	return Platform::PF_WINDOWS;
}

ST_NS_E


