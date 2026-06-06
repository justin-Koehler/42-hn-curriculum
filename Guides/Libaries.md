# Libraries

A library is a digital toolbox. Instead of writing common features (like printing text, math operations, or memory handling) from scratch for every new project, you use a library that already contains these pre-written tools.

---

### The 3 Rules

1. **They prevent rewriting.** You never write the same basic utility code twice; you build it once, save it in a library, and reuse it.
2. **They keep code clean.** Instead of cluttering your main project with thousands of lines of background logic, you hide that logic inside a library.
3. **They require an interface.** To use a library, your program needs a header file (`.h`) to look up the available tools and their instructions.

---

### How to Use Them

Using a library in your project always follows a simple three-step concept:

```c
// 1. Include the header (the blueprint)
#include <stdio.h> 

int main(void)
{
    // 2. Call the tool directly in your code
    printf("It just works.\n"); 
    return (0);
}

// 3. Link it during compilation so the compiler connects the tool
// gcc main.c -lft
```

---

### Why it Matters

Without libraries, every programmer would have to reinvent the wheel—rewriting functions to talk to the screen, the keyboard, or the hard drive for every single app. Libraries let you skip the plumbing and focus entirely on building your actual product.
