#include "data.h"

int32_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base) {
    int32_t i = 0;
    int32_t is_negative = 0;

    if (data == 0) {
        ptr[i++] = '0';
        ptr[i] = '\0';
        return i;
    }

    if (data < 0 && base == 10) {
        is_negative = 1;
        data = -data;
    }

    while (data != 0) {
        int32_t rem = data % base;
        ptr[i++] = (rem > 9) ? (rem - 10) + 'A' : rem + '0';
        data = data / base;
    }

    if (is_negative) {
        ptr[i++] = '-';
    }

    ptr[i] = '\0';

    // Reverse the string
    for (int32_t start = 0, end = i - 1; start < end; start++, end--) {
        uint8_t temp = ptr[start];
        ptr[start] = ptr[end];
        ptr[end] = temp;
    }

    return i;
}

int32_t my_atoi(uint8_t * ptr, uint32_t digits, uint32_t base) {
    int32_t result = 0;
    int32_t i = 0;
    int32_t is_negative = 0;

    if (ptr[0] == '-') {
        is_negative = 1;
        i++;
    }

    for (; i < digits; i++) {
        result *= base;

        if (ptr[i] >= '0' && ptr[i] <= '9') {
            result += ptr[i] - '0';
        } else if (ptr[i] >= 'A' && ptr[i] <= 'F') {
            result += ptr[i] - 'A' + 10;
        } else if (ptr[i] >= 'a' && ptr[i] <= 'f') {
            result += ptr[i] - 'a' + 10;
        }
    }

    if (is_negative) {
        result = -result;
    }

    return result;
}
