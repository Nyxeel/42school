# ✅ Libft Edge Case Checklist (Verified for 42 / libc Compatibility)

This checklist is optimized for **VSCode usage**, with real edge cases verified against `libc` and expected 42 behavior. NULL-related tests are only included where behavior is defined or useful for debugging.

---

## `ft_atoi`
- [ ] Empty string
- [ ] Only whitespaces
- [ ] Valid number with leading/trailing spaces
- [ ] Positive number with `+`
- [ ] Negative number with `-`
- [ ] Multiple signs (`--42`, `+-42`) → should return 0
- [ ] Alphanumeric mix (`42abc`) → should stop at non-digit
- [ ] Only letters → should return 0
- [ ] `INT_MAX` and `INT_MIN`
- [ ] Overflow strings → returns undefined (but should not crash)

---

## `ft_bzero`
- [ ] Zero length
- [ ] Normal memory block
- [ ] Overwrite non-zero memory

---

## `ft_calloc`
- [ ] `count = 0`, `size > 0`
- [ ] `count > 0`, `size = 0`
- [ ] `count * size` causes overflow → return NULL
- [ ] Returned memory is zeroed

---

## `ft_isalnum`
- [ ] Digits: `'0'`–`'9'`
- [ ] Letters: `'a'`–`'z'`, `'A'`–`'Z'`
- [ ] Special characters → should return 0
- [ ] Control characters → should return 0

---

## `ft_isalpha`
- [ ] Upper and lower case letters
- [ ] Digits → should return 0
- [ ] Special characters → should return 0

---

## `ft_isascii`
- [ ] Values 0–127
- [ ] Values > 127
- [ ] Negative values

---

## `ft_isdigit`
- [ ] `'0'`–`'9'`
- [ ] Characters before/after digit range (e.g. `'/'`, `':'`)

---

## `ft_isprint`
- [ ] Printable ASCII (32–126)
- [ ] Non-printables (0–31, 127)

---

## `ft_itoa`
- [ ] 0
- [ ] Positive numbers
- [ ] Negative numbers
- [ ] `INT_MIN`, `INT_MAX`

---

## `ft_memchr`
- [ ] Character found at beginning
- [ ] In the middle
- [ ] At the end
- [ ] Not found
- [ ] Length = 0

---

## `ft_memcmp`
- [ ] Buffers equal
- [ ] First byte different
- [ ] Last byte different
- [ ] Length = 0

---

## `ft_memcpy`
- [ ] Normal copy
- [ ] `n = 0`
- [ ] `dst == src`
- [ ] Overlapping → undefined behavior (test separately)

---

## `ft_memmove`
- [ ] Non-overlapping copy
- [ ] `dst < src` (forward overlap)
- [ ] `dst > src` (backward overlap)
- [ ] `dst == src`

---

## `ft_memset`
- [ ] Zero length
- [ ] Set to 0
- [ ] Set to 255

---

## `ft_putchar_fd`
- [ ] Printable ASCII
- [ ] Non-printable ASCII
- [ ] `fd = 1`, `fd = 2`

---

## `ft_putendl_fd`
- [ ] Normal string
- [ ] Empty string
- [ ] Ends with newline

---

## `ft_putnbr_fd`
- [ ] Positive and negative numbers
- [ ] Zero
- [ ] `INT_MAX`, `INT_MIN`

---

## `ft_putstr_fd`
- [ ] Normal string
- [ ] Empty string

---

## `ft_split`
- [ ] String with multiple delimiters in a row
- [ ] String with no delimiters
- [ ] String with delimiters at start and end
- [ ] Only delimiters → empty result
- [ ] Empty input string

---

## `ft_strchr`
- [ ] Character present (start, middle, end)
- [ ] Character not found
- [ ] `c = '\0'`

---

## `ft_strdup`
- [ ] Empty string
- [ ] Normal string
- [ ] Very long string

---

## `ft_striteri`
- [ ] Empty string
- [ ] Confirm correct index behavior

---

## `ft_strjoin`
- [ ] Both strings non-empty
- [ ] One string empty
- [ ] Both strings empty

---

## `ft_strlcat`
- [ ] `dstsize = 0`
- [ ] `dstsize < strlen(dst)`
- [ ] Enough space for full concat

---

## `ft_strlcpy`
- [ ] `dstsize = 0`
- [ ] `dstsize < strlen(src)`
- [ ] `dstsize > strlen(src)`

---

## `ft_strlen`
- [ ] Empty string
- [ ] Normal string
- [ ] Very long string

---

## `ft_strmapi`
- [ ] Empty string
- [ ] Function uses index properly

---

## `ft_strncmp`
- [ ] Equal strings
- [ ] Difference at start
- [ ] Difference at end
- [ ] `n = 0`
- [ ] `n > string length`

---

## `ft_strnstr`
- [ ] Empty needle
- [ ] Needle not in haystack
- [ ] Needle at start/middle/end
- [ ] `len = 0`

---

## `ft_strrchr`
- [ ] Character found multiple times
- [ ] `c = '\0'`
- [ ] Character not present

---

## `ft_strtrim`
- [ ] String with leading/trailing trim chars
- [ ] Trim set empty
- [ ] String only contains trim chars
- [ ] No trim chars present

---

## `ft_substr`
- [ ] `start > strlen(s)` → return empty string
- [ ] `len = 0`
- [ ] `len > strlen(s)`

---

## `ft_tolower` / `ft_toupper`
- [ ] All letters
- [ ] Digits and symbols → unchanged
- [ ] Negative values → unchanged (test optional)

---

✅ Use this file to build tests or a `libft_tester`. All cases verified to be necessary and sufficient for edge coverage.

