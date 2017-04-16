# ft_printf
This is my own printf (language C), my first big language C project.

### Function prototype
```
int   ft_printf(const char *format, ...);
```

### Examples
```
ft_printf("%d\n", 42);
>> 42
```
```
ft_printf("%#10.*X\n", 25, 42);
>> 0X000000000000000000000002A
```
```
ft_printf("%010b\n", 42);
>> 0000101010
```

## Details
- Width managed
- Precision managed
- Wildcard managed

### Syntax
```
%[flags][width][.precision][length]type
```

### Conversions
| Character | Description |
|:-------------:|:-------------|
| dDi | int as a signed decimal number |
| c | Character |
| C | Unicode character |
| s | Null-terminated string |
| S | Unicode string |
| oO | Unsigned int in octal |
| uU | Print decimal unsigned int |
| xX | Unsigned int as a hexadecimal number. x uses lower-case letters and X uses upper-case |
| p | Pointer to void |
| bB | Long long int as a binary number. b uses lower-case letters and B uses upper-case|
| % | Print percentage |
| k | Print a date in any ordinary ISO format |

### Flags field
| Flag | Description |
|:-------------:|:-------------|
| #      | For o, x, X types, the text 0, 0x, 0X, respectively, is prepended to non-zero numbers |
| 0      | When the 'width' option is specified, prepends zeros for numeric types      |
| - | Left-align the output of this placeholder      |
| + | Prepends a plus for positive signed-numeric types. positive = +, negative = -.      |
| space | Prepends a space for positive signed-numeric types. positive =  , negative = -. This flag is ignored if the + flag exists.      |
### Length field
| Character | Description |
|:-------------:|:-------------|
| hh      | For integer types, causes printf to expect an int-sized integer argument which was promoted from a char  |
| h      | For integer types, causes printf to expect an int-sized integer argument which was promoted from a short      |
| l | For integer types, causes printf to expect a long-sized integer argument      |
| ll | For integer types, causes printf to expect a long-sized integer argument      |
| j | For integer types, causes printf to expect a intmax_t-sized integer argument      |
| z | For integer types, causes printf to expect a size_t-sized integer argument      |
