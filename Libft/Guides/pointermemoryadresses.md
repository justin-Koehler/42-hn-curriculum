# Guide: Pointers & Memory Addresses

To write low-level code in C, you must understand how computer memory is organized. This guide explains what a memory address is, how pointers store them, and how to navigate through memory using pointer arithmetic.

---

## 1. What is a Memory Address?

Your computer's RAM is a massive grid of storage slots. Every single byte in memory has a unique number assigned to it. This number is its **Memory Address**, usually written in hexadecimal format (e.g., `0x7ffee3b4a2bc`).

When you create a normal variable, the operating system assigns it a free slot in RAM:

```c
void	ft_address_example(void)
{
	int	number;

	number = 42;
}
```
*Behind the scenes:* The compiler chooses a memory address (e.g., `0x001`) and stores the value `42` inside that slot.

---

## 2. Pointers: Storing the Address

A pointer is a variable that does not hold data values like integers or characters. Instead, it holds a **Memory Address**.

### Core Operators
*   `&` (Address-of): Retrieves the hexadecimal address where a variable lives.
*   `*` (Dereference): Goes to the address stored inside the pointer to read or modify the value at that location.

### Norminette-Compliant Example
```c
void	ft_pointer_example(void)
{
	int	number;
	int	*ptr;

	number = 42;
	ptr = &number;
	*ptr = 21;
}
```
*   `ptr = &number;` means: Take the address of `number` (e.g., `0x001`) and store it inside `ptr`.
*   `*ptr = 21;` means: Go to the address stored in `ptr` (`0x001`) and change the value there to `21`. Now, `number` is automatically `21`.

---

## 3. Pointer Arithmetic (Navigating Memory)

You can add or subtract integers from pointers to move them through memory blocks (like arrays). However, pointer arithmetic is unique because **adding 1 moves the pointer by the size of its data type**, not by 1 byte.

*   If you add `1` to an `int *`, it moves forward by **4 bytes** (size of an integer).
*   If you add `1` to a `char *`, it moves forward by **1 byte** (size of a character).

### Norminette-Compliant Array Traversal
This example shows how to move through an integer array using pointer arithmetic.

```c
void	ft_print_array(int *array, int size)
{
	int	i;
	int	*current;

	i = 0;
	current = array;
	while (i < size)
	{
		ft_putnbr_fd(*current, 1);
		current++;
		i++;
	}
}
```
*Note: `current++` automatically adds exactly 4 bytes to the address because `current` is defined as an `int *`.*

---

## 4. The Relationship Between Arrays and Pointers

In C, the name of an array is actually a pointer to its very first element.

```c
void	ft_array_identity(void)
{
	int	array[5];
	int	*ptr1;
	int	*ptr2;

	ptr1 = array;
	ptr2 = &array[0];
}
```
*Result:* Both `ptr1` and `ptr2` hold the exact same memory address. Writing `array[3]` is just a cleaner way of writing `*(array + 3)`.

---

## 5. Critical Safeguards for 42 Projects

1.  **Dangling Addresses**: Never return the address of a local variable from a function. Local variables are destroyed when the function exits, leaving your pointer pointing to an unsafe, empty address.
2.  **Out-of-Bounds Arithmetic**: Always ensure your pointer arithmetic never moves past the allocated size of your array or memory buffer. Reading outside your assigned addresses causes **Segmentation Faults** or security leaks.
