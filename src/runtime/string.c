#include <stdint.h>

#include <runtime/string.h>

void *memcpy(void *dest, const void *src, size_t count)
{
    for (size_t i = 0; i < count; i++)
    {
        ((char *)dest)[i] = ((char *)src)[i];
    }
    return dest;
}

#define NUMBER_BASE 10

/**
 * Converts the C-string `str` to a number.
 */
int32_t atoi(int8_t *str)
{
    int32_t result = 0;
    int8_t *current = str;

    // TODO: Empty spaces

    do
    {
        result += ((*str) - '0') * (NUMBER_BASE * (str - current));
        current++;
    } while (*current != 0);

    return result;
}

/**
 * TODO
 */
// int8_t *itoa(int32_t value, int8_t str, int32_t base)
//{
//     return (int8_t *)"";
// }