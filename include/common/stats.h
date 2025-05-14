/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************//**
 * @file <stats.h> 
 * @brief <the header file , function prototype >
 *
 * <The file declares the functions that will be implemented in the stats.c>
 *
 * @author <Awab Abdallh>
 * @date <6 april 2025 >
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Function Declarations and Comments */

/**
 * @brief Finds the maximum value in an array.
 *
 * This function iterates through the array and finds the largest value
 * by comparing each element. It returns the maximum value found
 * @return The maximum value in the array.
 */
unsigned char find_maximum(unsigned char *array, unsigned int length);

/**
 * @brief Finds the minimum value in an array.
 *
 * This function iterates through the array and finds the smallest value
 * by comparing each element. It returns the minimum value found.
 *
 */
unsigned char find_minimum(unsigned char *array, unsigned int length);

/**
 * @brief Calculates the mean (average) value of an array.
 * This function sums all the elements of the array and then divides by
 * the number of elements to calculate the mean
 * @param array A pointer to the unsigned char array that holds the data.
 * @param length The number of elements in the array.
 * @return The mean value of the array

*/

unsigned char find_mean(unsigned char *array, unsigned int length);

/**
 * @brief Finds the median value of an array.
 *
 * This function first sorts the array and then finds the median value.
 * If the number of elements is odd, the middle value is returned.
 * If even, the average of the two middle values is returned.
 *
 * @param array A pointer to the unsigned char array that holds the data.
@param length The number of elements in the array.
 *
 * @return The median value of the array.
 */
unsigned char find_median(unsigned char *array, unsigned int length);

/**
 * @brief Sorts an array from largest to smallest.
 *
 * This function uses a sorting algorithm to sort the elements of the array
 * in descending order.
 *
 * @param array A pointer to the unsigned char array that holds the data.
 * @param length The number of elements in the array.
 *
 * @return void This function doesn't return any value.
 */
void sort_array(unsigned char *array, unsigned int length);

/**
 * @brief Prints all elements of the array.
 *
 * This function iterates over the array and prints each element to the screen.
 *
 * @param array A pointer to the unsigned char array that holds the data.
 * @param length The number of elements in the array.
 *
 * @return void This function doesn't return any value.
 */
void print_array(unsigned char *array, unsigned int length);

/**
 * @brief Prints statistics such as maximum, minimum, mean, and median.
 *
 * This function calculates the statistics (max, min, mean, median) and 
 * prints them to the screen.
 *
 * @param array A pointer to the unsigned char array that holds the data.
 * @param length The number of elements in the array.
 *
 * @return void This function doesn't return any value.
 */
void print_statistics(unsigned char *array, unsigned int length);

#endif /* __STATS_H__ */
