# vector3

A from-scratch C++ dynamic array.

I built this to understand how `std::vector` actually works under the hood. Instead of just using it, I wanted to implement my own version from scratch. It uses manual memory management, move semantics, operator overloading, and template metaprogramming.

It's header-only. No dependencies. Just include it and go.

---

## Why I Built This

I wanted to know what happens when you call `push_back()` or `operator[]`. I wanted to understand the memory layout, the pointer arithmetic, and the move semantics that make `std::vector` fast.

So I built my own. Then I built a `vector3` on top of it — a template class that works with any type.

This is the result.

---

## Features

- Template-based — works with `int`, `double`, `std::string`, anything
- Initializer list support — `vector3<int> v = {1, 2, 3};`
- Bounds-checked access — `at()` throws `std::out_of_range`
- Operator overloading — `+`, `-`, `==`, `!=`, `[]`
- Move semantics — efficient resource transfer
- Header-only — copy and include

---

## Quick Start

```cpp
#include "vector3.hpp"
#include <iostream>

int main() {
    vector3<int> v = {1, 2, 3};
    v.push_back(4);
    v.print();  // [1, 2, 3, 4]

    std::cout << v[0] << "\n";  // 1

    return 0;
}

## Licence
MIT
