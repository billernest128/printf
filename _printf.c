#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);
    int printed_chars = 0;

    while (*format) {
        if (*format != '%') {
            putchar(*format);
            printed_chars++;
        } else {
            format++;
            if (*format == '\0') {
                break; // Incomplete format string, terminate loop
            } else if (*format == 'c') {
                // Print a character
                int c = va_arg(args, int);
                putchar(c);
                printed_chars++;
            } else if (*format == 's') {
                // Print a string
                char *str = va_arg(args, char *);
                if (str == NULL) {
                    str = "(null)";
                }
                while (*str) {
                    putchar(*str);
                    str++;
                    printed_chars++;
                }
            } else if (*format == '%') {
                // Print a literal '%'
                putchar('%');
                printed_chars++;
            } else if (*format == 'd' || *format == 'i') {
                // Print an integer
                int num = va_arg(args, int);
                printed_chars += printf("%d", num);
            }
        }
        format++;
    }

    va_end(args);
    return printed_chars;
}

int main() {
    int num_chars = _printf("Hello, %c world! This is a %s example.%% Integer: %d\n", 'C', "printf", 42);
    printf("Number of characters printed: %d\n", num_chars);
    return 0;
}

