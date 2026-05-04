#include <vector>
#include <cstdint>
#include <iostream>
#include <iomanip>
#include "Core/Value.hpp"
#include "Core/OpCode.hpp"
#include "Core/Chunk.hpp"

namespace Val {
    void Chunk::Write(uint8_t Code, int Line) {
        Codes.push_back(Code);
        if (Lines.empty()) {
            Lines.push_back(LineInfo({Line, 1}));
            return;
        } else {
            LineInfo &LastLine = Lines.back();
            if (LastLine.Line == Line) { LastLine.Count += 1; }
            else { Lines.push_back(LineInfo({Line, 1})); }
        }
    }
    void Chunk::Write(OpCode Code, int Line) {
        Codes.push_back((uint8_t)Code);
        if (Lines.empty()) {
            Lines.push_back(LineInfo({Line, 1}));
            return;
        } else {
            LineInfo &LastLine = Lines.back();
            if (LastLine.Line == Line) { LastLine.Count += 1; }
            else { Lines.push_back(LineInfo({Line, 1})); }
        }

    } 
    int Chunk::AddConstant(Value value) {
        Constants.push_back(value);
        return Constants.size() - 1;
    }
    void Chunk::Disassemble(const char *name) const {
        std::cout << "== " << name << " ==\n";
        int Offset = 0;
        while (Offset < Codes.size()) {
            Offset = DisassembleInstruction(Offset);
        }
    }
    int Chunk::DisassembleInstruction(int Offset) const {
        std::cout << std::setw(4) << Offset << " | " << std::setw(4) << GetLine(Offset) << " ";
        OpCode instruction = static_cast<OpCode>(Codes[Offset]);
        switch (instruction) {
            case OpCode::ADD:           std::cout << "ADD";           break;
            case OpCode::DIV:           std::cout << "DIV";           break;
            case OpCode::EQUAL:         std::cout << "EQUAL";         break;
            case OpCode::TRUE:          std::cout << "TRUE";          break;
            case OpCode::FALSE:         std::cout << "FALSE";         break;
            case OpCode::GREATER:       std::cout << "GREATER";       break;
            case OpCode::GREATER_EQUAL: std::cout << "GREATER_EQUAL"; break;
            case OpCode::LESS:          std::cout << "LESS";          break;
            case OpCode::LESS_EQUAL:    std::cout << "LESS_EQUAL";    break;
            case OpCode::MUL:           std::cout << "MUL";           break;
            case OpCode::NEGATE:        std::cout << "NEGATE";        break;
            case OpCode::NIL:           std::cout << "NIL";           break;
            case OpCode::NOT:           std::cout << "NOT";           break;
            case OpCode::NOT_EQUAL:     std::cout << "NOT_EQUAL";     break;
            case OpCode::POP:           std::cout << "POP";           break;
            case OpCode::PRINT:         std::cout << "PRINT";         break;
            case OpCode::SUB:           std::cout << "SUB";           break;
            case OpCode::RETURN:        std::cout << "RETURN";        break;
            case OpCode::CONSTANT: {
                std::cout << "CONSTANT " << static_cast<int>(Codes[Offset + 1]) << " ";
                Constants[Codes[Offset + 1]].Print(); std::cout << "\n";
                return Offset + 2;
            } 
            default:                    std::cout << "UNKNOWN";       return Offset + 1; 
        }
        std::cout << '\n';
        return Offset + 1;
    }
    int Chunk::GetLine(int Offset) const {
        for (const LineInfo &Line : Lines) {
            Offset -= Line.Count;
            if (Offset < 0) { return Line.Line; }
        }
        return -1;
    }
}