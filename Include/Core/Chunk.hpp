#pragma once
#include <vector>
#include <cstdint>
#include "Core/Value.hpp"
#include "Core/OpCode.hpp"

namespace Val {
    struct LineInfo {
        int Line;
        int Count;
    };
    struct Chunk {
        std::vector<uint8_t> Codes;
        std::vector<Value> Constants;
        std::vector<LineInfo> Lines;
        Chunk() {
            Codes.reserve(256);
            Constants.reserve(256);
        }
        void Write(uint8_t Code, int Line);
        void Write(OpCode Code, int Line);
        int AddConstant(Value value);
        void Disassemble(const char* name) const;
        int DisassembleInstruction(int offset) const;
        int GetLine(int Offset) const;
    };
}