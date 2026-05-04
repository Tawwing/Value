#include <iostream>
#include "Core/Value.hpp"

namespace Val {
    void Value::Print() const {
        switch (Type) {
            case ValueType::TYPE_INT: {
                std::cout << Int;
                break;
            }
            case ValueType::TYPE_BOOL: {
                std::cout << (Bool ? "true" : "false");
                break;
            }
            case ValueType::TYPE_NULL: {
                std::cout << "null";
                break;
            }
            case ValueType::TYPE_FLOAT: {
                printf("%.17g", Float);
                break;
            }
            case ValueType::TYPE_OBJECT: {
                std::cout << "<val_object>";
                break;
            }
        }
    }
}