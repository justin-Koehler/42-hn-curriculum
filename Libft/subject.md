# Libft: Core Function Reference


## Part 1 — Character Classification & Conversion

### ft_isalpha
* **What:** Checks if a character is a letter.
* **How:** Verifies if the ASCII value sits between 'A'-'Z' or 'a'-'z'.

### ft_isdigit
* **What:** Checks if a character is a number.
* **How:** Verifies if the ASCII value sits between '0' and '9'.

### ft_isalnum
* **What:** Checks if a character is alphanumeric.
* **How:** Combines checks to see if the character passes either `ft_isalpha` or `ft_isdigit`.

### ft_isascii
* **What:** Checks if a character fits into the standard ASCII table.
* **How:** Verifies if the numeric value sits strictly between 0 and 127.

### ft_isprint
* **What:** Checks if a character is visible on screen.
* **How:** Verifies if the ASCII value sits between space (32) and tilde (126).

### ft_toupper
* **What:** Converts a lowercase letter to uppercase.
* **How:** Subtracts 32 from the ASCII value if it sits between 'a' and 'z'.

### ft_tolower
* **What:** Converts an uppercase letter to lowercase.
* **How:** Adds 32 to the ASCII value if it sits between 'A' and 'Z'.

---

## Part 1 — Core Memory Operations

### ft_strlen
* **What:** Measures the exact length of a string.
* **How:** Loops through memory character by character until it hits the null-terminator (`\0`).

### ft_memset
* **What:** Fills a block of memory with a single uniform byte.
* **How:** Casts the destination to an `unsigned char *` and overwrites it byte by byte.

### ft_bzero
* **What:** Erases a block of memory by setting it to zero.
* **How:** Writes binary zeros (`\0`) into the target memory block for a specified length.

### ft_memcpy
* **What:** Copies a block of memory from one location to another.
* **How:** Transfers raw bytes directly from a read-only source pointer to a destination pointer.

### ft_memmove
* **What:** Copies a block of memory safely, even if source and destination overlap.
* **How:** Compares pointer addresses to choose whether to copy forward or backward to prevent data overwrite.

### ft_memchr
* **What:** Searches for a specific byte inside a generic block of memory.
* **How:** Scans raw memory up to a limited size and returns a pointer to the first match.

### ft_memcmp
* **What:** Compares two memory blocks byte for byte to find deviations.
* **How:** Subtracts bytes of block B from block A sequentially until a difference is found or the limit is hit.

---

## Part 1 — Advanced String Routing

### ft_strlcpy
* **What:** Copies a string into a buffer with absolute size protection.
* **How:** Copies characters up to size-1 and forcefully appends a secure `\0` at the end.

### ft_strlcat
* **What:** Appends a source string safely onto the end of an existing string.
* **How:** Finds the end of the destination, copies the source up to the size limit, and adds a `\0`.

### ft_strchr
* **What:** Searches for the first occurrence of a character in a string from left to right.
* **How:** Traverses the string from the beginning and returns a pointer to the first matching byte.

### ft_strrchr
* **What:** Searches for the last occurrence of a character in a string by scanning backward.
* **How:** Measures the full string first, then sweeps from right to left to locate the final match.

### ft_strncmp
* **What:** Compares two strings up to a specific character count.
* **How:** Checks characters sequentially and returns the ASCII difference at the first mismatch or limit.

### ft_strnstr
* **What:** Hunts for a small substring hidden inside a larger string.
* **How:** Scans the text within a limited horizon, looking for an exact structural match of the needle.

### ft_atoi
* **What:** Converts a static text string into a mathematical integer value.
* **How:** Skips initial spaces, records a positive or negative sign, and calculates the cumulative number.

---

## Part 1 — Dynamic Allocations

### ft_calloc
* **What:** Reserves a clean, zeroed-out block of memory on the heap.
* **How:** Multiplies elements by size, requests memory via `malloc`, and pipes zeros into every byte.

### ft_strdup
* **What:** Creates an identical, dynamically allocated clone of a string.
* **How:** Measures the source string length, allocates a new home via `malloc`, and copies the text inside.

---

## Part 2 — Advanced Transformations

### ft_substr
* **What:** Extracts a precise piece out of a larger string.
* **How:** Allocates memory and copies characters starting from a specified index up to a given length limit.

### ft_strjoin
* **What:** Fuses two separate strings into a brand new standalone text layout.
* **How:** Calculates both lengths combined, allocates space, copies the prefix, and appends the suffix.

### ft_strtrim
* **What:** Strips specified unwanted characters from the extreme front and back edges of a string.
* **How:** Locates the first and last valid characters not in the trim set, then clones that clean core.

### ft_split
* **What:** Cuts a string into an organized array of separate words using a delimiter character.
* **How:** Counts the words, allocates an array of pointers, and extracts each substring independently.

### ft_itoa
* **What:** Converts a raw mathematical integer back into displayable text digits.
* **How:** Determines the digit count, allocates space, and extracts numbers modulo-style from right to left.

### ft_strmapi
* **What:** Applies a custom function to every character of a string to create a modified clone.
* **How:** Allocates space and fills it by passing each character and its index into the mapping function.

### ft_striteri
* **What:** Modifies the characters of an existing string in place using a custom function.
* **How:** Loops through the original string, passing the index and the character address (`char *`) directly.

---

## Part 2 — File Descriptor Outputs

### ft_putchar_fd
* **What:** Writes a single character to a specified destination channel.
* **How:** Executes the low-level `write` system call using the provided File Descriptor (`fd`).

### ft_putstr_fd
* **What:** Streams an entire text string to a specified destination channel.
* **How:** Measures the string length and pushes the full block out via a single `write` system call.

### ft_putendl_fd
* **What:** Writes a text string to a channel and automatically adds a clean newline at the end.
* **How:** Outputs the string using `write`, followed immediately by a separate newline (`\n`) write sequence.

### ft_putnbr_fd
* **What:** Translates raw integer values into text symbols and prints them to a channel.
* **How:** Breaks down numbers recursively, manages negative signs, and prints each isolated digit as a symbol.

---

## Part 3 — Linked List Mechanics (Bonus)

### ft_lstnew
* **What:** Builds a single, isolated node container for a linked list system.
* **How:** Allocates memory for a `t_list` struct, populates `content`, and sets the `next` pointer to `NULL`.

### ft_lstadd_front
* **What:** Attaches a new node onto the absolute beginning of a linked list.
* **How:** Links the new node’s `next` pointer to the current head, then updates the head to the new node.

### ft_lstsize
* **What:** Counts the total number of nodes currently inside a linked list.
* **How:** Moves down the chain from node to node via the `next` pointers, incrementing a counter.

### ft_lstlast
* **What:** Locates and references the absolute final node in a linked list chain.
* **How:** Follows the `next` tracking line until it identifies the station pointing to `NULL`.

### ft_lstadd_back
* **What:** Attaches a new node onto the absolute end of a linked list.
* **How:** Finds the current last node using traversal mechanics and connects its `next` pointer to the new node.

### ft_lstdelone
* **What:** Eradicates a single node's payload and container without altering the rest of the list.
* **How:** Cleans the payload via a custom `del` function, then frees the node's structural memory shell.

### ft_lstclear
* **What:** Wipes out a designated node and every single successor node after it.
* **How:** Cascades down the line, using temporary pointers to safely clear contents and free shells sequentially.

### ft_lstiter
* **What:** Loops through a list and applies a custom function to every node's payload.
* **How:** Starts at the head and sequentially triggers your function on each node's `content` data field.

### ft_lstmap
* **What:** Processes an entire list to generate a brand new, evolved copy of it.
* **How:** Iterates through nodes, transforms payloads into new node spaces, and safely handles allocation errors.
