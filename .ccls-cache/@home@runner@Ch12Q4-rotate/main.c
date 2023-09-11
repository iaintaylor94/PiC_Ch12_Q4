// Program to illustrate the rotation of integers using a function to edtermine the number of bits in an int

#include <stdio.h>

// Declare Functions
int int_size (void);
unsigned int rotate (unsigned int, int);

int main(void) {

  unsigned int w1 = 0xabcdef00u, w2 = 0xffff1122u;

  printf ("  Rotate     BY     Equals\n");
  printf ("--------   ----   --------\n");
  printf ("%.6x   %.4d   %.6x\n", w1, 8, rotate (w1, 8));
  printf ("%.6x   %.4d   %.6x\n", w1, -16, rotate (w1, -16));
  printf ("%.6x   %.4d   %.6x\n", w2, 4, rotate (w2, 4));
  printf ("%.6x   %.4d   %.6x\n", w2, -2, rotate (w2, -2));
  printf ("%.6x   %.4d   %.6x\n", w1, 0, rotate (w1, 0));
  printf ("%.6x   %.4d   %.6x\n", w1, 44, rotate (w1, 44));
  
  return 0;
}

// Define Functions
int int_size (void) {
  unsigned int test = ~0; // All ones

  int i = 0;
  while (test != 0) {
    test >>= 1;
    i++;
  }

  return i;
}

unsigned int rotate (unsigned int value, int n) {
  unsigned int result, bits;

  if (n > 0)
    n %= int_size();
  else
    n = -(-n % int_size());

  if (n == 0)
    result = value;
  else if (n > 0) { // Rotate left
    bits = value >> (int_size() - n);
    result = value << n | bits;
  }
  else { // Rotate right
    n = -n;
    bits = value << (int_size() - n);
    result = value >> n | bits;
  }

  return result;
}