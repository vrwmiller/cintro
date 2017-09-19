#include <stdio.h>

#undef DEBUG

struct db {
   int age;
   int id;
   float sal;
};

int main(int argc, char *argv[])
{

   /* Some pre-processor code for very basic lint */
   #ifdef DEBUG

   static int i;
   printf( "argc: %d\n", argc );
   for( i=0; i<argc; i++ )
      printf( "argv[%d]: %s\n", i, argv[i] );

   #endif

   struct db emp;
   struct db *ptr;
   emp.age = 22;
   emp.id = 1;
   emp.sal = 12000.21;

   ptr = &emp;
   printf("Emp ID: %d\n", ptr->id);

   return 0;
}
