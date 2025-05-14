/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file <stats.c> 
 * @brief < a simple application that performs statistical analytics on a dataset >
 *
 * <    Write a simple programming assignment that prints statistics to the command line using a variety of c-programming operators and features.>
 *
 * @author <Awab Abdallah>
 * @date <6 april 2025 >
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

    print_array(test, SIZE);

// After sorting the array
 printf("\nSorted Array (Largest to Smallest):\n");
sort_array(test, SIZE);

// Print the sorted array

	print_array(test, SIZE);

    /* Print the statistics */
    print_statistics(test, SIZE);

}

/* Add other Implementation File Code Here */
/* Find Maximum */
unsigned char find_maximum(unsigned char *array, unsigned int length) {
    unsigned char max = array[0];
    for (unsigned int i = 1; i < length; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}


unsigned char find_minimum(unsigned char *array, unsigned int length) {
    unsigned char min = array[0];
    for (unsigned int i = 1; i < length; i++) {
        if (array[i] < min) {
            min = array[i];
        }
    }
    return min;
}

unsigned char find_mean(unsigned char *array, unsigned int length) {
    unsigned int sum = 0;
    for (unsigned int i = 0; i < length; i++) {
        sum += array[i];
    }
    return sum / length;
}
unsigned char find_median(unsigned char *array, unsigned int length) {
    sort_array(array, length); // Sort array first

    if (length % 2 == 0) {
        // Even number of elements, average the two middle values
        unsigned char mid1 = array[length / 2 - 1];
        unsigned char mid2 = array[length / 2];
        return (mid1 + mid2) / 2;
    } else {
        // Odd number of elements, return the middle value
        return array[length / 2];
    }
}
void sort_array(unsigned char *array, unsigned int length) {
    for (unsigned int i = 0; i < length - 1; i++) {
        for (unsigned int j = 0; j < length - i - 1; j++) {
            if (array[j] < array[j + 1]) {
                // Swap the values if they're in the wrong order
                unsigned char temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}
void print_array(unsigned char *array, unsigned int length) {
    printf("Array values: ");
    for (unsigned int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}
void print_statistics(unsigned char *array, unsigned int length) {
    printf("Array Statistics:\n");
    printf("Maximum: %d\n", find_maximum(array, length));
    printf("Minimum: %d\n", find_minimum(array, length));
    printf("Mean: %d\n", find_mean(array, length));
    printf("Median: %d\n", find_median(array, length));
}
