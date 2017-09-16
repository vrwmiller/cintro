#include <stdio.h>

#undef LINT

int getNum()
{
   static int i;
   printf("Enter an integer: ");
   scanf("%d", &i);
   return i;
}

int main(int argc, char *argv[])
{

   #ifdef LINT
   static int i;
   printf("argc: %d\n", argc);
   for(i=0; i<argc; i++)
      printf("argv[%d]: %s\n", i, argv[i]);
   #endif

   int age = getNum();
   printf("You entered %d\n", age);

   return 0;
}
