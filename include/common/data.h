#ifndef __DATA_H__
#define __DATA_H__

#include <stdint.h>

int32_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);
int32_t my_atoi(uint8_t * ptr, uint32_t digits, uint32_t base);

#endif /* __DATA_H__ */
