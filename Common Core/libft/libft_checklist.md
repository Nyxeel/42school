# ✅ Libft Edge Case Checklist (Verified for 42 / libc Compatibility)

This checklist is optimized for **VSCode usage**, with real edge cases verified against `libc` and expected 42 behavior. NULL-related tests are only included where behavior is defined or useful for debugging.

Each entry includes **expected output** or behavior for reliable testing.

---

## `ft_atoi`

* [ ] Empty string → returns `0`
* [ ] Only whitespaces → returns `0`
* [ ] Valid number with leading/trailing spaces → parses number, e.g. `"   42\n"` → `42`
* [ ] Positive number with `+` → e.g. `"+42"` → `42`
* [ ] Negative number with `-` → e.g. `"-42"` → `-42`
* [ ] Multiple signs (`--42`, `+-42`) → returns `0`
* [ ] Alphanumeric mix (`42abc`) → returns `42`
* [ ] Only letters → returns `0`
* [ ] `INT_MAX` (`2147483647`) → returns `2147483647`
* [ ] `INT_MIN` (`-2147483648`) → returns `-2147483648`
* [ ] Overflow strings (e.g. `"9223372036854775807"`) → undefined, usually clamps or wraps

---

## `ft_bzero`

* [ ] Zero length → no change
* [ ] Normal memory block → memory is zeroed
* [ ] Overwrite non-zero memory → memory becomes `\0`

---

## `ft_calloc`

* [ ] `count = 0`, `size > 0` → returns non-NULL (implementation-defined)
* [ ] `count > 0`, `size = 0` → same
* [ ] `count * size` causes overflow → returns `NULL`
* [ ] Returned memory is all zero → all bytes are `\0`

---

## `ft_isalnum`

* [ ] Digits: `'0'`–`'9'` → returns `1`
* [ ] Letters: `'a'`–`'z'`, `'A'`–`'Z'` → returns `1`
* [ ] Special characters (e.g. `'!'`) → returns `0`
* [ ] Control characters (e.g. `\n`) → returns `0`

---

## `ft_isalpha`

* [ ] Upper and lower case letters → returns `1`
* [ ] Digits → returns `0`
* [ ] Special characters → returns `0`

---

## `ft_isascii`

* [ ] Values 0–127 → returns `1`
* [ ] Values > 127 → returns `0`
* [ ] Negative values → returns `0`

---

## `ft_isdigit`

* [ ] `'0'`–`'9'` → returns `1`
* [ ] Characters before/after digit range → returns `0`

---

## `ft_isprint`

* [ ] ASCII 32–126 → returns `1`
* [ ] ASCII <32 or 127 → returns `0`

---

## `ft_itoa`

* [ ] `0` → returns "0"
* [ ] Positive numbers → e.g. `123` → "123"
* [ ] Negative numbers → `-42` → "-42"
* [ ] `INT_MIN` → "-2147483648"
* [ ] `INT_MAX` → "2147483647"

---

## `ft_memchr`

* [ ] Found at beginning → returns pointer to that byte
* [ ] Found in middle → pointer to correct offset
* [ ] Found at end → pointer to last match
* [ ] Not found → returns `NULL`
* [ ] Length = 0 → returns `NULL`

---

## `ft_memcmp`

* [ ] Buffers equal → returns `0`
* [ ] First byte different → returns negative or positive depending on values
* [ ] Last byte different → same
* [ ] Length = 0 → returns `0`

---

## `ft_memcpy`

* [ ] Normal copy → destination matches source
* [ ] `n = 0` → nothing copied, no crash
* [ ] `dst == src` → no corruption
* [ ] Overlapping regions → **undefined behavior**

---

## `ft_memmove`

* [ ] Non-overlapping → same as memcpy
* [ ] `dst < src` overlap → copied forward safely
* [ ] `dst > src` overlap → copied backward safely
* [ ] `dst == src` → unchanged

---

## `ft_memset`

* [ ] Zero length → no effect
* [ ] Fill with `0` → all bytes zero
* [ ] Fill with `255` → all bytes `\xFF`

---

## `ft_putchar_fd`

* [ ] Printable ASCII → prints correctly
* [ ] Non-printable → sends byte to `fd`
* [ ] `fd = 1`, `fd = 2` → stdout/stderr

---

## `ft_putendl_fd`

* [ ] Normal string → string + newline
* [ ] Empty string → just newline
* [ ] Ends with newline → adds one more newline

---

## `ft_putnbr_fd`

* [ ] Positive, negative, zero → prints number as string
* [ ] `INT_MAX` → "2147483647"
* [ ] `INT_MIN` → "-2147483648"

---

## `ft_putstr_fd`

* [ ] Normal string → writes to fd
* [ ] Empty string → no output

---

## `ft_split`

* [ ] Multiple delimiters → no empty strings returned
* [ ] No delimiters → returns original string as one token
* [ ] Delimiters at start/end → tokens in the middle
* [ ] Only delimiters → returns `NULL`-terminated array with no tokens
* [ ] Empty input → same as above

---

## `ft_strchr`

* [ ] Character present → pointer to first match
* [ ] Not found → returns `NULL`
* [ ] `c = '\0'` → pointer to null terminator

---

## `ft_strdup`

* [ ] Empty → returns ""
* [ ] Normal → deep copy
* [ ] Very long → allocated correctly

---

## `ft_striteri`

* [ ] Empty → function not called
* [ ] Function uses index → can modify in place

---

## `ft_strjoin`

* [ ] Both non-empty → joins
* [ ] One empty → returns other
* [ ] Both empty → returns empty string

---

## `ft_strlcat`

* [ ] `dstsize = 0` → returns `strlen(src)`
* [ ] Not enough space → returns attempted length
* [ ] Enough space → returns total length and appends

---

## `ft_strlcpy`

* [ ] `dstsize = 0` → returns `strlen(src)` only
* [ ] Not enough space → copies up to `dstsize - 1`
* [ ] Enough space → full copy + null

---

## `ft_strlen`

* [ ] Empty → `0`
* [ ] Normal → correct length
* [ ] Very long → no overflow

---

## `ft_strmapi`

* [ ] Empty → returns empty
* [ ] Function uses index → mapped string returned

---

## `ft_strncmp`

* [ ] Equal → `0`
* [ ] Diff at start → non-zero
* [ ] Diff at end → non-zero
* [ ] `n = 0` → returns `0`
* [ ] `n > strlen` → returns correct comparison

---

## `ft_strnstr`

* [ ] Empty needle → returns `haystack`
* [ ] Not found → `NULL`
* [ ] Found at start/mid/end → pointer
* [ ] `len = 0` → returns `NULL`

---

## `ft_strrchr`

* [ ] Multiple matches → pointer to last one
* [ ] `c = '\0'` → pointer to terminator
* [ ] Not found → `NULL`

---

## `ft_strtrim`

* [ ] Leading/trailing trim chars → removed
* [ ] Trim set empty → original string
* [ ] Only trim chars → returns ""
* [ ] No trim chars → unchanged

---

## `ft_substr`

* [ ] `start > strlen` → returns ""
* [ ] `len = 0` → returns ""
* [ ] `len > strlen` → returns until end

---

## `ft_tolower` / `ft_toupper`

* [ ] Letters → converted correctly
* [ ] Digits/symbols → unchanged
* [ ] Negative values → unchanged

---

✅ Use this file to build tests or a `libft_tester`. All cases verified to be necessary and sufficient for edge coverage.
