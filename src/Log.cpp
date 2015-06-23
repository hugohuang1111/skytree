
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <io.h>

#include <windows.h>

#include "Log.hpp"

#define MAX_BUF_LENG 512

ST_NS_B

Log::Log() {
}

Log::~Log() {
}

void Log::log(const char *format, ...) {
    va_list args;
    va_start(args, format);

    char buf[MAX_BUF_LENG];

    vsnprintf_s(buf, MAX_BUF_LENG - 3, format, args);
    strcat_s(buf, "\n");

#if ST_TARGET_PLATFORM == ST_PLATFORM_WIN32
    WCHAR wszBuf[MAX_BUF_LENG] = { 0 };
    MultiByteToWideChar(CP_UTF8, 0, buf, -1, wszBuf, sizeof(wszBuf));
    OutputDebugStringW(wszBuf);
    WideCharToMultiByte(CP_ACP, 0, wszBuf, -1, buf, sizeof(buf), nullptr, FALSE);
    printf("%s", buf);
    fflush(stdout);
#elif ST_TARGET_PLATFORM ==  ST_PLATFORM_ANDROID
    __android_log_print(ANDROID_LOG_DEBUG, "cocos2d-x debug info", "%s", buf);
#else
    // Linux, Mac, iOS, etc
    fprintf(stdout, "%s", buf);
    fflush(stdout);
#endif

    va_end(args);

    print(buf);
}

void Log::print(const char* log) {
    printf(log);
}

ST_NS_E
