
#ifndef __SKYTREE_LOG_H_
#define __SKYTREE_LOG_H_

#include "Macro.h"

ST_NS_B

class Log {
public:
    Log();
    ~Log();

    static void log(const char *format, ...);
    static void print(const char* log);

};

#define LOG(format, ...)        Log::log(format, ##__VA_ARGS__)

ST_NS_E
#endif
