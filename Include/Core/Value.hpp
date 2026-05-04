#pragma once 
#include <cstdint>

namespace Val {
    struct Value {
        enum ValueType : uint8_t {
            TYPE_INT, TYPE_FLOAT, TYPE_BOOL, TYPE_NULL, TYPE_OBJECT
        };
        union { 
            int64_t Int; double Float; bool Bool; void* Object; 
        }; 
        ValueType Type;
        Value() {Type = ValueType::TYPE_NULL; };
        Value(int64_t I) {Type = ValueType::TYPE_INT; Int = I; };
        Value(double F) {Type = ValueType::TYPE_FLOAT; Float = F; };
        Value(bool B) {Type = ValueType::TYPE_BOOL; Bool = B; };
        Value(void* O) {Type = ValueType::TYPE_OBJECT; Object = O; };
    };
}