
---

## Preview (What It Looks Like)

# vector3

**A from-scratch C++ dynamic array.**

Built to understand how `std::vector` works under the hood:

- 🧠 **Manual memory management** — no STL containers used internally
- 🔄 **Move semantics** — efficient resource transfer
- ⚡ **Operator overloading** — `+`, `-`, `==`, `!=`, `[]`
- 🧩 **Template metaprogramming** — works with any type

**Header-only. No dependencies. Just include and go.**

---

## Quick Start

```cpp
#include "vector3.hpp"

int main() {
    vector3<int> v = {1, 2, 3};
    v.push_back(4);
    v.print();  // [1, 2, 3, 4]

    return 0;
}
