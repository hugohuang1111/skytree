
#include "UUID.hpp"

ST_NS_B

static int counter = 0;

UUID::UUID() {
}

UUID::~UUID() {
}

int UUID::create() {
    //TODO thread safe?
    return ++counter;
}

ST_NS_E
