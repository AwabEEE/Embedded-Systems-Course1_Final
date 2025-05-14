#include "memory.h"
#include "data.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void test_data1() {
  int32_t value = 1234;
  uint8_t base = 16;
  uint8_t buffer[20];
  int32_t length;

  printf("Running test_data1...\n");

  length = my_itoa(value, buffer, base);
  int32_t result = my_atoi(buffer, length, base);

  if(result == value)
    printf("test_data1 PASSED\n");
  else
    printf("test_data1 FAILED: result = %d, expected = %d\n", result, value);
}

void test_data2() {
  int32_t value = -12345;
  uint8_t base = 10;
  uint8_t buffer[20];
  int32_t length;

  printf("Running test_data2...\n");

  length = my_itoa(value, buffer, base);
  int32_t result = my_atoi(buffer, length, base);

  if(result == value)
    printf("test_data2 PASSED\n");
  else
    printf("test_data2 FAILED: result = %d, expected = %d\n", result, value);
}

void test_memmove1() {
  uint8_t buffer[20];
  for(int i = 0; i < 20; i++) buffer[i] = i;

  printf("Running test_memmove1...\n");

  my_memmove(buffer, buffer + 4, 12);

  for(int i = 0; i < 12; i++) {
    if(buffer[i] != i + 4) {
      printf("test_memmove1 FAILED\n");
      return;
    }
  }

  printf("test_memmove1 PASSED\n");
}

void test_memmove2() {
  uint8_t buffer[20];
  for(int i = 0; i < 20; i++) buffer[i] = i;

  printf("Running test_memmove2...\n");

  my_memmove(buffer + 4, buffer, 12);

  for(int i = 4; i < 16; i++) {
    if(buffer[i] != i - 4) {
      printf("test_memmove2 FAILED\n");
      return;
    }
  }

  printf("test_memmove2 PASSED\n");
}

void test_memmove3() {
  uint8_t src[20], dst[20];
  for(int i = 0; i < 20; i++) src[i] = i;

  printf("Running test_memmove3...\n");

  my_memmove(dst, src, 20);

  for(int i = 0; i < 20; i++) {
    if(dst[i] != i) {
      printf("test_memmove3 FAILED\n");
      return;
    }
  }

  printf("test_memmove3 PASSED\n");
}

void test_memcopy() {
  uint8_t src[20], dst[20];
  for(int i = 0; i < 20; i++) src[i] = i;

  printf("Running test_memcopy...\n");

  my_memcopy(dst, src, 20);

  for(int i = 0; i < 20; i++) {
    if(dst[i] != i) {
      printf("test_memcopy FAILED\n");
      return;
    }
  }

  printf("test_memcopy PASSED\n");
}

void test_memset() {
  uint8_t buffer[20];

  printf("Running test_memset...\n");

  my_memset(buffer, 0xAA, 20);

  for(int i = 0; i < 20; i++) {
    if(buffer[i] != 0xAA) {
      printf("test_memset FAILED at index %d\n", i);
      return;
    }
  }

  printf("test_memset PASSED\n");
}

void course1() {
  printf("Running course1 tests...\n");
  test_data1();
  test_data2();
  test_memmove1();
  test_memmove2();
  test_memmove3();
  test_memcopy();
  test_memset();
  printf("All course1 tests executed.\n");
}
