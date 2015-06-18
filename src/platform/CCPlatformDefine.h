
#ifndef __SKYTREE_PLATFORM_Define_H_
#define __SKYTREE_PLATFORM_Define_H_


#define ST_PLATFORM_UNKNOWN            0
#define ST_PLATFORM_WIN32              1
#define ST_PLATFORM_MAC                2


#define ST_TARGET_PLATFORM              ST_PLATFORM_UNKNOWN

// win32
#if defined(WIN32)
    #undef  ST_TARGET_PLATFORM
    #define ST_TARGET_PLATFORM          ST_PLATFORM_WIN32
#endif

// mac
#if defined(ST_TARGET_OS_MAC) || defined(__APPLE__)
    #undef  ST_TARGET_PLATFORM
    #define ST_TARGET_PLATFORM          ST_PLATFORM_MAC
#endif

// check user set platform
#if ! ST_TARGET_PLATFORM
    #error  "Cannot recognize the target platform; are you targeting an unsupported platform?"
#endif 


#endif

