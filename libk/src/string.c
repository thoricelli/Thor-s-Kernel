#include <stdint.h>

#include "string.h"

void *memcpy(void *dest, const void *src, size_t count)
{
    for (size_t i = 0; i < count; i++)
    {
        ((char *)dest)[i] = ((char *)src)[i];
    }
    return dest;
}

#define NUMBER_BASE 10

int32_t atoi(const char *str)
{
    int32_t result = 0;
    char *current = str;

    // TODO: Empty spaces

    do
    {
        result += ((*str) - '0') * (NUMBER_BASE * (str - current));
        current++;
    } while (*current != 0);

    return result;
}

size_t strlen(const char *str)
{
    // TODO: Read this per DWORD instead of per byte.
    // CPU likes that better :)

    char *reader = str;

    do
    {
        reader++;
    } while (*reader);

    return (size_t)(reader - str);
}

char *reverse(const char *str)
{
    /**
     * Classic reverse algorithm:
     * Two pointers, each assigns to each other.
     */

    char *left = str;
    char *right = str + strlen(str) - 1;

    while (left < right)
    {
        char left_value = *left;

        *left = *right;
        *right = left_value;

        left++;
        right--;
    }

    return str;
}

char *itoa(int32_t value, const char *str, int32_t base)
{
    char *result = str;

    if (base < 2 || base > 36)
        return NULL;

    char is_negative = value < 0;

    if (is_negative)
    {
        *result = '-';
        *result++;

        // Flip to positive so we don't have to handle this later.
        value = -value;
    }

    int32_t value_no_base;

    do
    {
        value_no_base = value;
        value /= base;

        // Example: 123456789 - 123456780 = 9
        // This gives us an indexer into the table.
        *result = "0123456789abcdef"[value_no_base - (value * base)];
        *result++;
    } while (value);

    // Do not reverse the sign if it exists.
    reverse(str + is_negative);

    return str;
}