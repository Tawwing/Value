#pragma once
#include <cstdint>

namespace Val {
    enum class OpCode : uint8_t {
        // Constants
        CONSTANT,      
        
        // Literals
        TRUE,
        FALSE,
        NIL,
        
        // Arithmetic
        ADD,
        SUB,
        MUL,
        DIV,
        NEGATE,
        
        // Comparison
        EQUAL,
        NOT_EQUAL,
        LESS,
        LESS_EQUAL,
        GREATER,
        GREATER_EQUAL,
        
        // Logic
        NOT,
        
        // Stack ops
        POP,
        
        // I/O 
        PRINT,
        
        // Control
        RETURN,
    };
}