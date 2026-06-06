# Libft - Common Core Circle 00

A clean, minimal guide explaining the logic, purpose, and traps of the custom C library functions.

---

## 1. Character Analysis & Manipulation (`ctype.h`)

These functions check or modify single characters based on the ASCII table.

* **`ft_isalpha`**
  * **Logic**: Checks if `c` is between 'a'-'z' or 'A'-'Z'.
  * **Why**: Used for parsing text, validating commands, or checking alphabetic inputs.
  * **Traps**: Remember that `c` is passed as an `int`. Do not restrict checks outside the 0-127 ASCII range.
* **`ft_isdigit`**
  * **Logic**: Checks if `c` is between '0' and '9' (ASCII 48 to 57).
  * **Why**: Essential for numbers-only validation or before converting strings to integers (`atoi`).
  * **Traps**: It checks the character representation of the digit, not the raw integer value `0-9`.
* **`ft_isalnum`**
  * **Logic**: Combines `ft_isalpha` and `ft_isdigit`.
  * **Why**: Validates alphanumeric strings like usernames or variable identifiers.
  * **Traps**: Ensure it returns `0` for spaces, punctuation, or special characters.
* **`ft_isascii`**
  * **Logic**: Checks if `c` fits within the standard ASCII table (0 to 127).
  * **Why**: Prevents undefined behavior when handling extended characters or foreign symbols.
  * **Traps**: The condition is strictly `c >= 0 && c <= 127`. Negative values are out.
* **`ft_isprint`**
  * **Logic**: Checks if `c` is a printable character (ASCII 32 to 126).
  * **Why**: Filters out invisible control characters (like `\n`, `\t`, `\0`) before printing to the terminal.
  * **Traps**: Space (` ` / 32) is printable. Delete (`\x7f` / 127) is not.
* **`ft_toupper`**
  * **Logic**: Converts lowercase 'a'-'z' to uppercase 'A'-'Z' by subtracting 32.
  * **Why**: Normalizes text strings for case-insensitive comparisons.
  * **Traps**: If the character is already uppercase or not a letter, return it completely unchanged.
* **`ft_tolower`**
  * **Logic**: Converts uppercase 'A'-'Z' to lowercase 'a'-'z' by adding 32.
  * **Why**: Standardizes user inputs or handles lower-case filtering.
  * **Traps**: Leave non-uppercase characters completely untouched.

---

## 2. String Manipulation - Non-Allocating (`string.h`)

Basic string utilities that read, search, or modify existing memory without using `malloc`.

* **`ft_strlen`**
  * **Logic**: Counts characters one by one until it hits the null-terminator `\0`.
  * **Why**: Determines how much space a string occupies before copying or allocating memory.
  * **Traps**: Passing a `NULL` pointer will cause a segmentation fault. Protect your input if necessary.
* **`ft_strlcpy`**
  * **Logic**: Copies up to `size - 1` bytes from source to destination, always adding `\0`.
  * **Why**: Safer alternative to `strcpy`. Prevents buffer overflows by respecting destination boundaries.
  * **Traps**: Returns the *total length of the source string* it tried to copy, not what it actually copied.
* **`ft_strlcat`**
  * **Logic**: Appends source to the end of destination, ensuring total length doesn't exceed `size - 1`.
  * **Why**: Safely glues two strings together without risking out-of-bounds memory writes.
  * **Traps**: If `size` is smaller than the initial destination length, the return value calculation changes (`size + strlen(src)`).
* **`ft_strchr`**
  * **Logic**: Scans a string from left to right looking for character `c`.
  * **Why**: Locates delimiters, file extensions, or specific targets inside a text block.
  * **Traps**: If searching for `\0`, it must return a pointer to the null-terminator at the end of the string.
* **`ft_strrchr`**
  * **Logic**: Scans a string from right to left (reverse search) looking for character `c`.
  * **Why**: Finds the last occurrence, such as extracting the final file extension in a full path.
  * **Traps**: Must handle searching for `\0` properly, just like `ft_strchr`.
* **`ft_strncmp`**
  * **Logic**: Compares two strings character by character up to `n` bytes.
  * **Why**: Checks if strings match exactly, sorting alphabetical order, or verifying commands.
  * **Traps**: Comparison must use `unsigned char` pointers to avoid negative character value bugs.
* **`ft_strnstr`**
  * **Logic**: Searches for a small substring inside a big string, looking at most `len` total characters.
  * **Why**: Locates keywords within bounded network buffers or text streams safely.
  * **Traps**: If the small substring is empty (`""`), return the entire big string pointer immediately.

---

## 3. Memory Blocks (`string.h`)

Raw memory operations handling bytes (`void *`) rather than null-terminated text strings.

* **`ft_memset`**
  * **Logic**: Fills the first `len` bytes of a memory block with a specific byte value `c`.
  * **Why**: Quick initialization tool to wipe structures or zero-out arrays.
  * **Traps**: Typecast the pointer to `unsigned char *` internally to overwrite byte-by-byte.
* **`ft_bzero`**
  * **Logic**: Fills a memory area with zero bytes (`\0`) up to `n` bytes.
  * **Why**: Specifically cleans up structures or buffers before reuse. 
  * **Traps**: It is effectively a wrapper around `ft_memset(ptr, 0, n)`. Do not return a value.
* **`ft_memcpy`**
  * **Logic**: Copies `n` bytes from source straight to destination.
  * **Why**: Fast transfer of raw data packets, structs, or fixed arrays.
  * **Traps**: Does **not** handle overlapping memory blocks. If memory overlaps, data gets corrupted.
* **`ft_memmove`**
  * **Logic**: Copies `n` bytes from source to destination safely, even if memory areas overlap.
  * **Why**: Solves the overlap limitation of `memcpy` by checking pointer positions before copying.
  * **Traps**: If destination is before source, copy forward. If destination is after source, copy backward.
* **`ft_memchr`**
  * **Logic**: Searches raw memory area for byte `c` up to `n` bytes.
  * **Why**: Locates data byte markers inside binary structures where `\0` does not mean the end.
  * **Traps**: Stops precisely at `n` bytes even if the character was not found.
* **`ft_memcmp`**
  * **Logic**: Compares two memory blocks byte-by-byte up to `n` bytes.
  * **Why**: Validates if two structs, arrays, or binary images are identical.
  * **Traps**: Returns the difference between the first non-matching bytes evaluated as `unsigned char`.

---

## 4. Conversions (`stdlib.h`)

Converts data types between readable text representations and machine numbers.

* **`ft_atoi`**
  * **Logic**: Skips whitespaces, checks for a single `+` or `-` sign, and converts numeric string digits to an integer.
  * **Why**: Parses configuration files, numbers passed in arguments (`argv`), or user text inputs.
  * **Traps**: Stop parsing the moment a non-digit character is encountered. Watch out for integer overflow.
