# Guide: Typecasting and Pointer Conversion in C

Typecasting is the process of converting a variable from one data type to another. In the 42 curriculum—especially during `Libft`—you will constantly cast pointers to manipulate raw memory at the byte level.

---

## 1. What is Typecasting?

C is a typed language. Every variable has a specific data type (like `int`, `char`, or `double`) that tells the compiler how many bytes to read and how to interpret them. 

Typecasting forces the compiler to treat a variable of type A as if it were of type B.

### Syntax
```c
(target_type)variable;
```

---

## 2. Value Casting vs. Pointer Casting

### Value Casting (Scalar)
Converting raw numbers. For example, changing a floating-point number into an integer. The compiler chops off the decimal part.

```c
void	ft_value_cast_example(void)
{
	double	pi;
	int		rounded_pi;

	pi = 3.14159;
	rounded_pi = (int)pi;
}
```

### Pointer Casting (Crucial for 42)
Changing how the compiler reads a memory address. The address itself stays exactly the same, but the compiler changes **how many bytes** it reads or writes when you dereference (`*`) it.

*   If you dereference an `int *`, the computer reads/writes **4 bytes**.
*   If you dereference a `char *`, the computer reads/writes **1 byte**.

---

## 3. Void Pointers (`void *`) and Byte Manipulation

A `void *` is a generic pointer. It points to a memory address, but it has **no type**. Because it has no type, the computer does not know how big the data is.

*   **Rule**: You cannot dereference (`*ptr`) or do math (`ptr++`) on a `void *`.
*   **Solution**: You must cast it to a specific type first. In `Libft`, we almost always cast it to an `unsigned char *` because an `unsigned char` is exactly **1 byte** and safely represents raw memory values from `0` to `255`.

### Norminette-Compliant Example: `ft_bzero`
`ft_bzero` takes a generic `void *` pointer and fills the memory with zeroes. To move through the memory byte by byte, we cast it to an `unsigned char *`.

```c
void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n > 0)
	{
		*ptr = 0;
		ptr++;
		n--;
	}
}
```

---

## 4. Why We Cast to `(char *)` or `(unsigned char *)`

When writing functions like `ft_memcpy`, `ft_memmove`, or `ft_memcmp`, the arguments are passed as `void *` so the function can accept any data structure (strings, integer arrays, structs).

By casting them internally to `unsigned char *`, you gain absolute control:
1.  You can increment the pointer (`ptr++`) to move exactly **1 byte** forward in RAM.
2.  You can read or overwrite memory at a granular, byte-by-byte level.

---

## 5. Common Pitfalls to Avoid

1.  **Implicit Casting in Modern Norm**: In older C standards, you had to cast the return value of `malloc` (e.g., `ptr = (int *)malloc(...)`). In the modern 42 Norminette, this is no longer required because a `void *` automatically converts to any other pointer type upon assignment. Keep your mallocs clean: `ptr = malloc(sizeof(int));`.
2.  **Wrong Pointer Size Alignment**: Casting an `int *` to a `char *` is safe (you just read it slower, byte by byte). However, casting a `char *` to an `int *` and dereferencing it can cause alignment crashes or read data you didn't intend to read if the memory boundary isn't a multiple of 4 bytes.
