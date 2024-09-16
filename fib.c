#include <stdio.h>
#include <stdlib.h>

// Iterative Fibonacci function
unsigned long long int fibonacci_iterative(int n)
{
   if (n > 93)
   {
      printf("Overflow: The largest Fibonacci number that can be accurately represented is F(93).\n");
      exit(1); // Exit if the number exceeds the limit
   }

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

// Recursive Fibonacci function
unsigned long long int fibonacci_recursive(int n)
{
   if (n > 50)
   {
      printf("Recursive method: Taking too long for large inputs.\n");
      exit(1); // Exit if the input is too large for recursion
   }

   if (n == 1)
      return 0; // Special case: F(1) = 0
   if (n == 2)
      return 1; // Special case: F(2) = 1

   return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

int main(int argc, char *argv[])
{
   if (argc != 4)
   {
      printf("Usage: %s <integer> <r|i> <filename>\n", argv[0]);
      return 1;
   }

   int input_num = atoi(argv[1]);
   char method = argv[2][0];
   char *filename = argv[3];

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

   if (method == 'i')
   {
      result = fibonacci_iterative(N);
   }
   else if (method == 'r')
   {
      result = fibonacci_recursive(N);
   }
   else
   {
      printf("Invalid method. Use 'r' for recursive or 'i' for iterative.\n");
      return 1;
   }

   printf("%llu\n", result);

   return 0;
}
