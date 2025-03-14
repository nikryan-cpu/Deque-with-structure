# My Realisation of Deque (Double Ended Queue) on a Dynamic Array in C++

Modern C++ implementation of a double-ended queue with iterator support and efficient memory management.

## Features

- � **Circular Buffer Architecture**: Optimized memory usage with automatic resizing
- 🔄 **STL-style Iterators**: Full forward iteration support (`begin()`, `end()`)
- 🛡 **Exception Safety**: Strong exception guarantee for all operations
- 🚀 **Modern C++ Features**:
  - Move semantics support
  - RAII resource management
  - Const-correct API
- 📦 **Modular Design**:
  - Separate classes for Deque and Iterator
  - Clean interface separation
- ✅ **Comprehensive Functionality**:
  - `push_front()/push_back()`
  - `pop_front()/pop_back()`
  - Random access (`at()`, operator[])
  - Size management and capacity control

## API Documentation
### Deque Class

push_front(const Student&): Insert at front

push_back(const Student&): Insert at end

pop_front(): Remove front element

pop_back(): Remove last element

Accessors
front()/back(): Reference to first/last element

at(int index): Bounds-checked access

operator[]: Direct element access

Capacity
size(): Number of elements

empty(): Check if empty

clear(): Remove all elements

Iterators
begin(): Iterator to first element

end(): Iterator to post-last element

### Iterator Class

Full forward iteration support (++, --, +=, -=)

Element access (operator*)

Comparison operators (==, !=)

## Performance

|Operation             |	Complexity    |
|----------------------|-------------   |
|Insert/Delete at ends |	O(1) amortized|
|Random Access	       |  O(1)          |
|Iteration	           |  O(n)          |
|Memory Usage	         |  25-75% load factor (auto-managed)|

## Installation

1. Clone the repository:
```bash
git clone https://github.com/yourusername/cpp-deque.git
```
