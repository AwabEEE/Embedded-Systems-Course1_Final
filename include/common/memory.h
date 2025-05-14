#ifndef __MEMORY_H__
#define __MEMORY_H__

#include <stdint.h>
#include <stddef.h>

uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length);
uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length);
uint8_t * my_memset(uint8_t * src, uint8_t value, size_t length);
uint8_t * my_memzero(uint8_t * src, size_t length);
int32_t  my_reverse(uint8_t * src, size_t length);

#endif /* __MEMORY_H__ */
