#pragma once

#include <stddef.h>

#ifdef __cplusplus
extern "C"
{
#endif
    void *memcpy(void *dest, const void *src, size_t count);

    int32_t atoi(int8_t *str);
    int8_t *itoa(int32_t value, int8_t str, int32_t base);

#ifdef __cplusplus
}
#endif