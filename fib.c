#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_N 100 // Maximum number of Fibonacci terms for memoization

// Memoization arrays for both recursive and iterative versions
unsigned long long int memo_r[MAX_N]; // For recursive
unsigned long long int memo_i[MAX_N]; // For iterative

// Recursive Fibonacci function (without memoization)
unsigned long long int fib_wrapper_recursive(int n)
{
   if (n == 1)
      return 0; // Special case: F(1) = 0
   if (n == 2)
      return 1; // Special case: F(2) = 1
   return fib_wrapper_recursive(n - 1) + fib_wrapper_recursive(n - 2);
}

// Iterative Fibonacci function (without memoization)
unsigned long long int fib_wrapper_iterative(int n)
{
   if (n == 1)
      return 0; // Special case: F(1) = 0
   if (n == 2)
      return 1; // Special case: F(2) = 1

   unsigned long long int a = 0, b = 1, temp;
   for (int i = 3; i <= n; i++)
   {
      temp = a + b;
      a = b;
      b = temp;
   }
   return b;
}

// Recursive Fibonacci function with memoization
unsigned long long int fib_r(int n)
{
   // Base cases
   if (n == 1)
      return 0;
   if (n == 2)
      return 1;

   // Check if the result is already memoized
   if (memo_r[n] != -1)
      return memo_r[n];

   // Calculate and memoize the result
   memo_r[n] = fib_r(n - 1) + fib_r(n - 2);
   return memo_r[n];
}

// Iterative Fibonacci function with memoization
unsigned long long int fib_i(int n)
{
   // Check if result is already memoized
   if (memo_i[n] != -1)
      return memo_i[n];

   // Otherwise, calculate and memoize the result
   memo_i[n] = fib_wrapper_iterative(n);
   return memo_i[n];
}

int main(int argc, char *argv[])
{
   if (argc != 4)
   {
      printf("Usage: %s <integer> <r|i> <filename>\n", argv[0]);
      return 1;
   }

   // Initialize memoization arrays with -1 (indicating uncalculated results)
   for (int i = 0; i < MAX_N; i++)
   {
      memo_r[i] = -1;
      memo_i[i] = -1;
   }

   int input_num = atoi(argv[1]);
   char method = argv[2][0];
   char *filename = argv[3];

   // Open the file and read the integer
   FILE *file = fopen(filename, "r");
   if (file == NULL)
   {
      printf("Error: Could not open file %s\n", filename);
      return 1;
   }

   int file_num;
   fscanf(file, "%d", &file_num);
   fclose(file);

   int N = input_num + file_num;

   unsigned long long int result;
   clock_t start_time, end_time;
   double time_taken;

   // Start the timer
   start_time = clock();

   if (method == 'i')
   {
      result = fib_i(N); // Call the memoized iterative version
   }
   else if (method == 'r')
   {
      result = fib_r(N); // Call the memoized recursive version
   }
   else
   {
      printf("Invalid method. Use 'r' for recursive or 'i' for iterative.\n");
      return 1;
   }

   // End the timer
   end_time = clock();
   time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

   // Output the Fibonacci number and the time taken
   printf("%llu\n", result);

   return 0;
}