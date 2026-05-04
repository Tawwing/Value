#include <iostream>
#include "Core/Value.hpp"

int main() {
    Val::Value a((int64_t)42);
    Val::Value b(3.14);
    Val::Value c(true);
    Val::Value d(nullptr);
    Val::Value e;

    std::cout << a.Int     << "\n"; // 42
    std::cout << b.Float   << "\n"; // 3.14
    std::cout << c.Bool    << "\n"; // 1
    std::cout << d.Object  << "\n"; // 0
    std::cout << e.Type    << "\n"; // 3 (TYPE_NULL)

    return 0;
}