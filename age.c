#include <stdio.h>

#define LINT

int getNum()
{
   static int i;
   printf("Enter an integer: ");
   scanf("%d", &i);
   return i;
}

int main(int argc, char *argv[])
{
   int age = getNum();
   printf("You entered %d\n", age);

   return 0;
}
