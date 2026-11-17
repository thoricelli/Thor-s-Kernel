#pragma once

#include <stddef.h>

#ifdef __cplusplus
extern "C"
{
#endif

    /**
     * Marks this space as available.
     */
    void free(void *ptr);
    /**
     * Allocates `size` bytes onto the heap.
     */
    void *malloc(size_t size);
    /**
     * Reallocates `ptr`
     */
    void *realloc(void *ptr, size_t size);

#ifdef __cplusplus
}
#endif