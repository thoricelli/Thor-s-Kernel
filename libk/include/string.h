#pragma once

#include <stddef.h>

#ifdef __cplusplus
extern "C"
{
#endif
    /**
     * Copies the values from `dest` into `src`, `count` amounts.
     */
    void *memcpy(void *dest, const void *src, size_t count);

    /**
     * Converts the C-string `str` to a number.
     */
    int32_t atoi(const char *str);

    /**
     * Calculates the length of a C-string.
     */
    size_t strlen(const char *str);

    /**
     * Reverses the given C-string.
     */
    char *reverse(const char *str);

    /**
     * Converts numeric value to C-string.
     */
    char *itoa(int32_t value, const char *str, int32_t base);

#ifdef __cplusplus
}
#endif