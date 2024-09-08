#include <stdio.h>
#include <stdlib.h>

// Function to calculate Fibonacci using recursion
int fibonacci_recursive(int n)
{
   if (n == 1)
      return 0; // fib(1) = 0
   if (n == 2)
      return 1; // fib(2) = 1
   return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

// Function to calculate Fibonacci using iteration
int fibonacci_iterative(int n)
{
   if (n == 1)
      return 0; // fib(1) = 0
   if (n == 2)
      return 1; // fib(2) = 1
   int a = 0, b = 1, c;
   for (int i = 3; i <= n; i++) // Start from 3 since fib(1) and fib(2) are known
   {
      c = a + b;
      a = b;
      b = c;
   }
   return b;
}

int main(int argc, char *argv[])
{
   if (argc != 4)
   {
      printf("Usage: %s <integer> <r|i> <filename>\n", argv[0]);
      return 1;
   }

   // First argument: an integer
   int first_arg = atoi(argv[1]);

   // Open the file and read the integer from it
   FILE *file = fopen(argv[3], "r");
   if (file == NULL)
   {
      printf("Error opening file %s\n", argv[3]);
      return 1;
   }
   int file_number;
   fscanf(file, "%d", &file_number);
   fclose(file);

   // Sum the two numbers
   int N = first_arg + file_number;

   // Compute the Nth Fibonacci number based on the second argument (r or i)
   int result;
   if (argv[2][0] == 'r')
   {
      result = fibonacci_recursive(N);
   }
   else if (argv[2][0] == 'i')
   {
      result = fibonacci_iterative(N);
   }
   else
   {
      printf("Invalid option %s. Use 'r' for recursive or 'i' for iterative.\n", argv[2]);
      return 1;
   }

   // Output the result
   printf("%d\n", result);
   return 0;
}