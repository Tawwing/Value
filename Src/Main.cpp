#include <iostream>
#include "Core/Chunk.hpp"
#include "Core/Value.hpp"
#include "Core/OpCode.hpp"

int main() {
    Val::Chunk chunk;

    // 1. Add constants 1 and 2 to the constant pool
    // (Adjust constructor if your Value class uses a different signature)
    chunk.AddConstant(Val::Value(1.0));
    chunk.AddConstant(Val::Value(2.0));

    // 2. Write bytecode for: print(1 + 2)
    chunk.Write(Val::OpCode::CONSTANT, 1);
    chunk.Write(static_cast<uint8_t>(0), 1); // Operand: constant index 0 (value 1)

    chunk.Write(Val::OpCode::CONSTANT, 2);
    chunk.Write(static_cast<uint8_t>(1), 2); // Operand: constant index 1 (value 2)

    chunk.Write(Val::OpCode::ADD, 3);
    chunk.Write(Val::OpCode::PRINT, 4);
    chunk.Write(Val::OpCode::RETURN, 5);

    // 3. Disassemble the chunk
    chunk.Disassemble("test");

    return 0;
}