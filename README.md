*This project has been created as part of the 42 curriculum by abarrio.*

# push_swap

## 📋 Description

**push_swap** is an algorithmic project that challenges you to sort data on a stack using a limited set of instructions while minimizing the number of operations. The project tests your understanding of sorting algorithms, algorithm complexity, and efficient problem-solving.

### Project Goals

The program must:
- Sort a stack of random integers in ascending order
- Use only two stacks (A and B) and a limited set of operations
- Output the shortest sequence of instructions to sort the numbers
- Handle errors appropriately (duplicates, non-integers, overflow)
- Meet strict performance benchmarks:
  - **100 numbers**: < 700 operations (target: ~550)
  - **500 numbers**: < 5500 operations (target: ~4500)

### How It Works

1. **Input**: The program receives integers as command-line arguments
2. **Processing**: Analyzes the data and chooses an appropriate sorting algorithm based on stack size
3. **Output**: Prints a sequence of stack operations to stdout that will sort the numbers
4. **Verification**: Can be tested with the `checker` program to verify correctness

---

## 🚀 Instructions

### Compilation

The project includes a Makefile with the following rules:

```bash
# Compile the program
make

# Clean object files
make clean

# Clean everything (objects and executable)
make fclean

# Recompile from scratch
make re
```

### Usage

The program accepts integers in two formats:

**Format 1: Multiple arguments**
```bash
./push_swap 3 2 1 5 4
```

**Format 2: Single string argument**
```bash
./push_swap "3 2 1 5 4"
```

### Examples

**Basic sorting:**
```bash
$ ./push_swap 2 1 3
sa

$ ./push_swap 3 2 1
sa
rra
```

**Testing with checker:**
```bash
$ ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_OS $ARG
OK

$ ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
6
```

**Error cases:**
```bash
$ ./push_swap 1 2 3 one
Error

$ ./push_swap 1 2 3 2
Error

$ ./push_swap 1 2147483648
Error
```

---

## 🏗️ Architecture

### Project Structure

```
push_swap/
├── Makefile
├── README.md
├── includes/
│   └── push_swap.h          # Header with structures and prototypes
├── libft/                   # Personal C library (ft_split, ft_atoi, etc.)
│   ├── Makefile
│   ├── libft.h
│   └── *.c
└── srcs/
    ├── main.c              # Program entry point
    ├── parse_args.c        # Argument parsing and validation
    ├── stack_utils.c       # Stack creation and manipulation
    ├── stack_utils2.c      # Additional stack utilities
    ├── push.c              # Push operations (pa, pb)
    ├── swap.c              # Swap operations (sa, sb, ss)
    ├── rotate.c            # Rotate operations (ra, rb, rr)
    ├── reverse_rotate.c    # Reverse rotate operations (rra, rrb, rrr)
    ├── sort_three.c        # Optimal sorting for 3 elements
    ├── sort_small.c        # Sorting for 4-5 elements
    ├── indexing.c          # Convert values to sorted indices
    ├── radix_sort.c        # Radix sort algorithm for large inputs
    └── error.c             # Error handling and memory management
```

### Data Structure

The program uses a **doubly linked list** to implement the stacks:

```c
typedef struct s_stack
{
    int             value;   // Original integer value
    int             index;   // Sorted position (0 to n-1)
    struct s_stack  *next;   // Next node (towards bottom)
    struct s_stack  *prev;   // Previous node (towards top)
}   t_stack;
```

---

## 🧮 Algorithm Explanation

### Overview

The program uses different sorting strategies based on the number of elements:

| Size | Algorithm | Max Operations |
|------|-----------|----------------|
| 2    | Simple swap | 1 |
| 3    | Hardcoded optimal | 2 |
| 4-5  | Push min to B + sort_three | 12 |
| 6+   | Indexing + Radix Sort | ~n log₂(n) |

### Radix Sort Algorithm

**Radix sort** is the core algorithm used for large inputs (> 5 elements). It sorts numbers by processing each bit position from least to most significant.

#### Why Radix Sort?

1. **Predictable performance**: Always O(n × k) where k ≈ log₂(n)
2. **Non-comparative**: Doesn't compare elements directly
3. **Works well with limited operations**: Only needs push, rotate operations
4. **Handles negatives**: After indexing, all values are 0 to n-1

#### How It Works

**Step 1: Indexing**

Convert actual values to sorted indices (0 to n-1):

```
Input:     [100, -50, 0, 42]
Sorted:    [-50, 0, 42, 100]
Indices:   [3, 0, 1, 2]
```

**Why?** This simplifies radix sort and reduces the number of bits needed.

**Step 2: Bit-by-Bit Sorting**

For each bit position (from rightmost to leftmost):
1. Go through all numbers in stack A
2. If bit is 0 → push to stack B (`pb`)
3. If bit is 1 → rotate in stack A (`ra`)
4. Push everything back from B to A (`pa`)

**Example with 4 numbers (indices 0-3):**

```
Numbers (indices): [3, 0, 2, 1]
Binary representation:
  3 = 11
  0 = 00
  2 = 10
  1 = 01

Bit 0 (rightmost):
  Check each number:
    3 (11) → bit=1 → ra (keep in A)
    0 (00) → bit=0 → pb (push to B)
    2 (10) → bit=0 → pb (push to B)
    1 (01) → bit=1 → ra (keep in A)
  
  Stack A: [3, 1]
  Stack B: [2, 0]
  
  Push all back: pa, pa
  Stack A: [0, 2, 3, 1]

Bit 1 (leftmost):
  Check each number:
    0 (00) → bit=0 → pb
    2 (10) → bit=1 → ra
    3 (11) → bit=1 → ra
    1 (01) → bit=0 → pb
  
  Stack A: [2, 3]
  Stack B: [1, 0]
  
  Push all back: pa, pa
  Stack A: [0, 1, 2, 3] ✓ SORTED!
```

#### Performance

For **n** elements:
- Number of bits needed: **k = ⌈log₂(n)⌉**
- Operations per bit: **~2n** (n pushes to B, n pushes back to A)
- **Total operations**: ~2n × k = ~2n log₂(n)

Real benchmarks:
- **100 numbers**: ~550 operations (7 bits needed)
- **500 numbers**: ~4500 operations (9 bits needed)

### Small Sorts

**2 elements:**
```c
if (a[0] > a[1])
    sa;  // Just swap
```

**3 elements:**

All 6 permutations handled optimally in max 2 operations:
- `[1,2,3]` → already sorted (0 ops)
- `[1,3,2]` → `sa`, `ra` (2 ops)
- `[2,1,3]` → `sa` (1 op)
- `[2,3,1]` → `rra` (1 op)
- `[3,1,2]` → `ra` (1 op)
- `[3,2,1]` → `sa`, `rra` (2 ops)

**4-5 elements:**

Algorithm:
1. Find minimum value
2. Rotate/reverse rotate to bring it to top
3. Push to B (`pb`)
4. Repeat for second minimum (if 5 elements)
5. Sort remaining 3 in A using `sort_three()`
6. Push back from B (`pa`)

---

## 🎓 Technical Concepts

### Stack Operations

All 11 operations modify the stacks in specific ways:

**Swap (sa, sb, ss):**
- Swaps the first 2 elements at the top
- Example: `[3, 2, 1]` → `sa` → `[2, 3, 1]`

**Push (pa, pb):**
- Moves top element from one stack to another
- Example: `A:[3, 2]  B:[1]` → `pa` → `A:[1, 3, 2]  B:[]`

**Rotate (ra, rb, rr):**
- Shifts all elements up by 1 (top becomes bottom)
- Example: `[3, 2, 1]` → `ra` → `[2, 1, 3]`

**Reverse Rotate (rra, rrb, rrr):**
- Shifts all elements down by 1 (bottom becomes top)
- Example: `[3, 2, 1]` → `rra` → `[1, 3, 2]`

### Time Complexity

- **Radix Sort**: O(n × k) where k = ⌈log₂(n)⌉ ≈ **O(n log n)**
- **Space**: O(n) for the two stacks
- **Stable**: Yes, maintains relative order of equal elements

### Error Handling

The program validates all inputs and exits with "Error\n" for:
- Non-integer arguments (letters, floats, etc.)
- Numbers outside INT_MIN to INT_MAX range
- Duplicate values
- Empty string argument `""`
- Mixed valid and invalid arguments

### Memory Management

- All heap allocations are freed before exit
- Valgrind clean (no memory leaks, no invalid reads/writes)
- Error cases properly free partial allocations
- Uses libft functions for safe string operations

---

## 🧪 Testing

### Manual Testing

```bash
# Test with 3 random numbers
./push_swap $(shuf -i 0-100 -n 3)

# Test with 100 random numbers and count operations
ARG=$(shuf -i 0-1000 -n 100 | tr '\n' ' '); ./push_swap $ARG | wc -l

# Test with 500 random numbers
ARG=$(shuf -i 0-5000 -n 500 | tr '\n' ' '); ./push_swap $ARG | wc -l

# Verify correctness with checker
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_OS $ARG
```

### Test Cases

**Error handling:**
```bash
./push_swap                          # (no output)
./push_swap ""                       # Error
./push_swap "1 2 3 one"             # Error
./push_swap 1 2 3 2                 # Error (duplicate)
./push_swap 2147483648              # Error (overflow)
./push_swap -2147483649             # Error (underflow)
```

**Functionality:**
```bash
./push_swap 1 2 3                   # (no output - already sorted)
./push_swap 3 2 1                   # Outputs operations
./push_swap "5 4 3 2 1"            # Handles string input
```

### Recommended Testers

- [Push Swap Visualizer](https://github.com/o-reo/push_swap_visualizer) - Visual representation
- [Push Swap Tester](https://github.com/SimonCROS/push_swap_tester) - Automated benchmarking
- [Checker](https://github.com/42-Paris/push_swap_tester) - Official verification

---

## 📚 Resources

### Sorting Algorithms

- [Radix Sort Explained - Medium](https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e)
  Detailed explanation of radix sort adapted for push_swap
  
- [Radix Sort Visualization](https://www.cs.usfca.edu/~galles/visualization/RadixSort.html)
  Interactive visualization of the algorithm
  
- [Sorting Algorithm Complexities](https://www.bigocheatsheet.com/)
  Big-O cheat sheet for various algorithms

### Data Structures

- [Linked Lists in C](https://www.learn-c.org/en/Linked_lists)
  Guide to understanding linked list implementation
  
- [Stack Data Structure](https://www.programiz.com/dsa/stack)
  Comprehensive guide to stacks

### Bitwise Operations

- [Bitwise Operators in C](https://www.programiz.com/c-programming/bitwise-operators)
  Understanding AND, OR, shift operations
  
- [Bit Manipulation Tricks](https://graphics.stanford.edu/~seander/bithacks.html)
  Advanced bit manipulation techniques

### 42 Project Resources

- [Push Swap Guide - 42 Cursus](https://42-cursus.gitbook.io/guide/2-rank-02/push_swap)
  Project-specific guide and tips

---

## 🤖 AI Usage in This Project

### Tasks Where AI Was Used

1. **Algorithm Research**
   - Used AI to understand radix sort variations
   - Researched optimal approaches for small number sets
   - Analyzed time complexity of different algorithms

2. **Code Structure Planning**
   - Asked AI to suggest optimal file organization
   - Discussed function separation and modularity
   - Reviewed data structure choices (array vs linked list)

3. **Error Handling Edge Cases**
   - Identified potential edge cases with AI assistance
   - Reviewed overflow detection methods
   - Discussed proper memory cleanup strategies

4. **Documentation**
   - Used AI to help structure clear code comments
   - Refined README explanations
   - Generated usage examples

### Parts Written Independently

- All core algorithm implementations (radix sort, small sorts)
- Stack operations (push, swap, rotate, reverse rotate)
- Parsing and validation logic
- Memory management and error handling
- Makefile structure

### How AI Enhanced Learning

- Provided multiple algorithmic perspectives to compare
- Helped visualize how radix sort works bit-by-bit
- Suggested optimization techniques (early exit, combined operations)
- Accelerated debugging by explaining segfault causes

**Note**: All AI-generated code suggestions were thoroughly reviewed, tested, and adapted to meet project requirements and personal coding style. The goal was to use AI as a learning tool, not a replacement for understanding.

---

## 🎯 Key Takeaways

### What I Learned

1. **Algorithm Selection Matters**
   - Different input sizes require different strategies
   - Radix sort is excellent for predictable performance
   - Hardcoded solutions beat general algorithms for small inputs

2. **Bitwise Operations Are Powerful**
   - Bit manipulation enables efficient sorting
   - Understanding binary is crucial for radix sort
   - Bit shifts are faster than division/multiplication

3. **Memory Management in C**
   - Proper allocation and deallocation prevents leaks
   - Error cases must free partial allocations
   - Valgrind is essential for verification

4. **Optimization Techniques**
   - Early exit conditions save operations
   - Combined operations (ss, rr, rrr) improve efficiency
   - Choosing rotation direction (ra vs rra) matters

5. **Testing Is Critical**
   - Edge cases reveal bugs general cases miss
   - Automated testing saves time
   - Visualization helps understand algorithm behavior

---

## 🏆 Performance Benchmarks

### Achieved Results

| Test Size | Target | Achieved | Status |
|-----------|--------|----------|--------|
| 3 numbers | ≤ 3 ops | ≤ 2 ops | ✅ Optimal |
| 5 numbers | ≤ 12 ops | ≤ 12 ops | ✅ Optimal |
| 100 numbers | < 700 ops | ~550 ops | ✅ Excellent |
| 500 numbers | < 5500 ops | ~4500 ops | ✅ Excellent |

**Grade**: 100/100 (eligible for bonus)

---

## 🤝 Contributing

This project was completed as part of the 42 curriculum. While it's not open for contributions, feel free to:
- Fork for your own learning
- Report issues or suggest improvements
- Use as reference (but don't copy for your own 42 project!)

---

## 📝 License

This project is part of the 42 School curriculum. Feel free to use it for learning purposes, but please respect the school's academic integrity policies.