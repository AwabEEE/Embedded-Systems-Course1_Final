#include "memory.h"
#include <stddef.h>

uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length) {
    if (src == NULL || dst == NULL || length == 0) return dst;

    if (src < dst && (src + length) > dst) {
        // Overlapping: copy backwards
        for (size_t i = length; i > 0; i--) {
            dst[i - 1] = src[i - 1];
        }
    } else {
        // No overlap: copy forward
        for (size_t i = 0; i < length; i++) {
            dst[i] = src[i];
        }
    }
    return dst;
}

uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length) {
    if (src == NULL || dst == NULL || length == 0) return dst;

    for (size_t i = 0; i < length; i++) {
        dst[i] = src[i];
    }
    return dst;
}

uint8_t * my_memset(uint8_t * src, uint8_t value, size_t length) {
    if (src == NULL || length == 0) return src;

    for (size_t i = 0; i < length; i++) {
        src[i] = value;
    }
    return src;
}

uint8_t * my_memzero(uint8_t * src, size_t length) {
    return my_memset(src, 0, length);
}

int32_t my_reverse(uint8_t * src, size_t length) {
    if (src == NULL || length == 0) return -1;

    size_t start = 0;
    size_t end = length - 1;

    while (start < end) {
        uint8_t temp = src[start];
        src[start] = src[end];
        src[end] = temp;
        start++;
        end--;
    }

    return 0;
}
