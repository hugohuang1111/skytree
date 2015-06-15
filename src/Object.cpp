
#include "Object.hpp"
#include "UUID.hpp"

ST_NS_B

Object::Object(): id(0) {
    id = UUID::create();
}

Object::~Object() {
    id = 0;
}

ST_NS_E
