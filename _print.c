#include <stdio.h>
#include <stdarg.h>
#include "main.h"

int printf_char(va_list val)
{
    char str;

    str = va_arg(val, int);
    _putchar(str);
    return (1);
}

int printf_string(va_list val)
{
    char *str;
    int i;
    int length;

    str = va_arg(val, char *);

    if (str == NULL)
    {
        str = "(null)";
        length = _strlen(str);
        for (i = 0; i < length; i++)
            _putchar(str[i]);
        return length;
    }
    else
    {
        length = _strlen(str);
        for (i = 0; i < length; i++)
            _putchar(str[i]);
        return length;
    }
}

