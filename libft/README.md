*This project was created as part of the curriculum of 42 by abarrio.*

# Libft - My First C Library

---

## 📋 Table of Contents

- [Description](#description)
- [Instructions](#instructions)
- [Library Functions](#library-functions)
- [Technical Decisions](#technical-decisions)
- [Resources](#resources)
- [Testing](#testing)
- [Author](#author)

---

## 📖 Description

**Libft** is the first project in the 42 curriculum and serves as a foundational C library. The goal is to recreate a collection of standard C library functions, along with additional utility functions that will be reused throughout the entire 42 cursus.

### Project Objectives

- **Understand** how standard C library functions work internally by implementing them from scratch
- **Master** fundamental C programming concepts including memory management, pointers, and data structures
- **Build** a personal library that will serve as a toolkit for future 42 projects
- **Learn** proper code organization, compilation processes, and the creation of static libraries

### What is Libft?

Libft is a static library (`libft.a`) containing 43 functions divided into three categories:

1. **Part 1 (23 functions)**: Reimplementations of standard C library functions (libc)
2. **Part 2 (11 functions)**: Additional utility functions not present in the standard library
3. **Bonus (9 functions)**: Linked list manipulation functions

This library becomes a crucial foundation for subsequent 42 projects where external libraries are often restricted.

---

## 🛠️ Instructions

### Prerequisites

- GCC or Clang compiler
- Make utility
- A Unix-like operating system (Linux, macOS, or WSL on Windows)

### Compilation

The project includes a comprehensive Makefile with the following rules:

#### Basic Compilation

```bash
# Compile the mandatory part (creates libft.a)
make

# or explicitly
make all
```

#### Compile with Bonus

```bash
# Compile including bonus functions
make bonus
```

#### Clean Object Files

```bash
# Remove .o object files
make clean
```

#### Full Clean

```bash
# Remove .o files and libft.a
make fclean
```

#### Recompile

```bash
# Remove everything and recompile
make re
```

### Using the Library

Once compiled, you can use the library in your own C programs:

```c
// your_program.c
#include "libft.h"

int main(void)
{
    char *str = ft_strdup("Hello, Libft!");
    ft_putendl_fd(str, 1);
    free(str);
    return (0);
}
```

Compile your program with the library:

```bash
gcc your_program.c -L. -lft -o your_program
./your_program
```

Or directly:

```bash
gcc your_program.c libft.a -o your_program
./your_program
```

### Compilation Flags

All source files are compiled with the following flags as required by 42:

- `-Wall`: Enable all warnings
- `-Wextra`: Enable extra warnings
- `-Werror`: Treat warnings as errors

This ensures code quality and adherence to best practices.

---

## 📚 Library Functions

### Part 1: Libc Functions (23 functions)

These functions replicate the behavior of standard C library functions.

#### Character Classification

| Function | Description | Return Value |
|----------|-------------|--------------|
| `ft_isalpha` | Check if character is alphabetic | 1 if true, 0 otherwise |
| `ft_isdigit` | Check if character is a digit | 1 if true, 0 otherwise |
| `ft_isalnum` | Check if character is alphanumeric | 1 if true, 0 otherwise |
| `ft_isascii` | Check if character is ASCII (0-127) | 1 if true, 0 otherwise |
| `ft_isprint` | Check if character is printable | 1 if true, 0 otherwise |

#### String Manipulation

| Function | Description |
|----------|-------------|
| `ft_strlen` | Calculate string length |
| `ft_strlcpy` | Size-bounded string copy |
| `ft_strlcat` | Size-bounded string concatenation |
| `ft_strchr` | Locate first occurrence of character |
| `ft_strrchr` | Locate last occurrence of character |
| `ft_strncmp` | Compare strings up to n bytes |
| `ft_strnstr` | Locate substring in string |
| `ft_strdup` | Duplicate string (with malloc) |

#### Memory Manipulation

| Function | Description |
|----------|-------------|
| `ft_memset` | Fill memory with constant byte |
| `ft_bzero` | Zero a byte string |
| `ft_memcpy` | Copy memory area |
| `ft_memmove` | Copy memory area (handles overlap) |
| `ft_memchr` | Locate byte in memory |
| `ft_memcmp` | Compare memory areas |

#### Character Conversion

| Function | Description |
|----------|-------------|
| `ft_toupper` | Convert character to uppercase |
| `ft_tolower` | Convert character to lowercase |
| `ft_atoi` | Convert string to integer |

#### Memory Allocation

| Function | Description |
|----------|-------------|
| `ft_calloc` | Allocate and zero memory |

### Part 2: Additional Functions (11 functions)

Custom utility functions for common string and I/O operations.

#### String Creation & Manipulation

| Function | Description | Allocates Memory |
|----------|-------------|------------------|
| `ft_substr` | Extract substring from string | Yes (malloc) |
| `ft_strjoin` | Concatenate two strings | Yes (malloc) |
| `ft_strtrim` | Trim characters from start and end | Yes (malloc) |
| `ft_split` | Split string by delimiter into array | Yes (malloc) |
| `ft_itoa` | Convert integer to string | Yes (malloc) |

#### Function Application

| Function | Description |
|----------|-------------|
| `ft_strmapi` | Apply function to each character (creates new string) |
| `ft_striteri` | Apply function to each character (modifies in place) |

#### File Descriptor Output

| Function | Description |
|----------|-------------|
| `ft_putchar_fd` | Write character to file descriptor |
| `ft_putstr_fd` | Write string to file descriptor |
| `ft_putendl_fd` | Write string + newline to file descriptor |
| `ft_putnbr_fd` | Write integer to file descriptor |

### Bonus: Linked List Functions (9 functions)

Functions to manipulate singly linked lists using the `t_list` structure.

#### Structure Definition

```c
typedef struct s_list
{
    void          *content;
    struct s_list *next;
}   t_list;
```

#### List Functions

| Function | Description |
|----------|-------------|
| `ft_lstnew` | Create new list node |
| `ft_lstadd_front` | Add node at beginning of list |
| `ft_lstadd_back` | Add node at end of list |
| `ft_lstsize` | Count list nodes |
| `ft_lstlast` | Get last node of list |
| `ft_lstdelone` | Delete single node |
| `ft_lstclear` | Delete all nodes in list |
| `ft_lstiter` | Apply function to each node's content |
| `ft_lstmap` | Apply function and create new list |

---

## 🔧 Technical Decisions

### Design Choices

#### 1. **Memory Safety**

All functions that allocate memory perform null checks and return NULL on allocation failure. This prevents undefined behavior and makes error handling predictable.

```c
char *result = malloc(size);
if (!result)
    return (NULL);
```

#### 2. **Norminette Compliance**

The entire project strictly adheres to the 42 Norminette coding standard:
- Maximum 25 lines per function
- Maximum 80 characters per line
- Maximum 5 functions per file
- Specific naming conventions and formatting rules

#### 3. **Static Helper Functions**

Complex functions use static helper functions to maintain modularity while keeping helpers private to their file:

```c
static int helper_function(int n)
{
    // Helper logic
}
```

#### 4. **Edge Case Handling**

All functions handle edge cases properly:
- NULL pointers (when appropriate)
- Empty strings
- Zero sizes
- Boundary values (INT_MIN, INT_MAX)

#### 5. **No Global Variables**

Following the subject requirements, no global variables are used. All state is passed through function parameters or stored in allocated memory.

### Implementation Highlights

#### `ft_split` - Most Complex Function

The `ft_split` function is arguably the most challenging, requiring:
1. Dynamic memory allocation for the array of strings
2. Counting substrings separated by delimiter
3. Allocating each substring individually
4. Proper cleanup on allocation failure

Strategy used: Two-pass approach (count then allocate) with careful memory management.

#### `ft_memmove` - Overlap Handling

Unlike `ft_memcpy`, `ft_memmove` handles overlapping memory regions by detecting the overlap direction and copying accordingly:

```c
if (dest < src)
    copy_forward();
else
    copy_backward();
```

#### `ft_lstmap` - Complex List Operation

Creates a new list by applying a function to each node, with proper error handling to delete the new list if any allocation fails.

---

## 📚 Resources

### Official Documentation

- [C Library Documentation](https://en.cppreference.com/w/c) - Comprehensive C standard library reference
- [Man Pages](https://linux.die.net/man/) - Unix/Linux manual pages for all libc functions
- [42 Docs](https://harm-smits.github.io/42docs/) - Community-maintained 42 documentation

### Learning Resources

#### Understanding C Fundamentals
- [Beej's Guide to C Programming](https://beej.us/guide/bgc/) - Excellent beginner-friendly C guide
- [CS50](https://cs50.harvard.edu/x/) - Harvard's introduction to computer science
- [The C Programming Language](https://en.wikipedia.org/wiki/The_C_Programming_Language) (K&R) - The definitive C book

#### Memory Management
- [Understanding Memory](https://www.youtube.com/watch?v=F0Ri2TpRBBg) - Video tutorial on memory layout
- [Valgrind Documentation](https://valgrind.org/docs/manual/quick-start.html) - Memory leak detection
- [GDB Tutorial](https://www.gdbtutorial.com/) - Debugging with GDB

#### Linked Lists
- [Linked List Basics](https://www.learn-c.org/en/Linked_lists) - Interactive tutorial
- [Visualgo](https://visualgo.net/en/list) - Visual representation of linked lists

### Testing Tools

- [libft-unit-test](https://github.com/alelievr/libft-unit-test) - Comprehensive test suite
- [libftTester](https://github.com/Tripouille/libftTester) - Popular 42 student tester
- [francinette](https://github.com/xicodomingues/francinette) - Automated testing framework
- [war-machine](https://github.com/0x050f/libft-war-machine) - Classic libft tester

### AI Usage Disclosure

This project was completed primarily through:

1. **Manual research and implementation** - Reading documentation, understanding algorithms, and writing code
2. **Peer learning** - Discussions with other 42 students about approaches and edge cases
3. **AI assistance for**:
   - **Documentation generation** - Structuring this README and code comments
   - **Research guidance** - Finding relevant resources and documentation
   - **Code review** - Identifying potential edge cases and suggesting improvements
   - **NOT for direct code generation** - All function logic was implemented through understanding and manual coding

The learning process focused on truly understanding each function's behavior rather than copying implementations, ensuring deep comprehension that will benefit future projects.

### Style and Standards

- [42 Norminette](https://github.com/42School/norminette) - Official 42 coding standard
- [GNU Coding Standards](https://www.gnu.org/prep/standards/) - Industry coding practices

---

## 🧪 Testing

### Manual Testing

Each function includes test cases covering:
- Normal operations
- Edge cases (NULL, empty strings, boundary values)
- Memory leak verification

Example test file:

```c
#include "libft.h"
#include <stdio.h>

int main(void)
{
    // Test ft_strlen
    printf("ft_strlen(\"Hello\"): %zu\n", ft_strlen("Hello"));
    
    // Test ft_strdup
    char *dup = ft_strdup("Test");
    printf("ft_strdup: %s\n", dup);
    free(dup);
    
    return (0);
}
```

### Automated Testing

Run external testers for comprehensive validation:

```bash
# Clone and run a tester
git clone https://github.com/Tripouille/libftTester
cd libftTester
./grademe.sh
```

### Memory Leak Detection

Use Valgrind to ensure no memory leaks:

```bash
valgrind --leak-check=full --show-leak-kinds=all ./your_test
```

Expected output:
```
All heap blocks were freed -- no leaks are possible
```

### Norm Checking

Verify code complies with 42 standards:

```bash
norminette *.c *.h
```

Should return:
```
All files passed norminette check
```

---

## 📄 License

This project is part of the 42 School curriculum. It follows the school's open-source policy where students can share their work for educational purposes.

---

## 🎯 Project Status

- ✅ All mandatory functions implemented
- ✅ All bonus functions implemented
- ✅ Passes norminette
- ✅ No memory leaks
- ✅ Comprehensive documentation
- ✅ Tested with multiple test suites

## 🙏 Acknowledgments

- **42 School** for the comprehensive curriculum
- **42 Community** for peer support and knowledge sharing
- **Open-source contributors** who created testing tools
- **Fellow students** for valuable discussions and insights

---

**Note**: This README provides a complete overview of the project. For specific function implementations and detailed code explanations, refer to the source files and inline comments.
