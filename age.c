#include <stdio.h>

/*
 * #define'ing DEBUG below generates additional output useful for debugging
 */
#undef DEBUG
#define YOUNG 40
#define OLD 70
#define QUIT 200

int getNum()
{

   static int i;
   printf( "Enter an integer: " );
   scanf( "%d", &i );

   return i;
}

int main(int argc, char *argv[])
{

   /* Some pre-processor code for very basic lint */
   #ifdef DEBUG

   static int i;
   printf( "argc: %d\n", argc );
   for( i=0; i<argc; i++ )
      printf( "argv[%d]: %s\n", i, argv[i] );

   #endif

   int age;
   do {
      age = getNum();
      if ( age < YOUNG ) {
         printf( "%d is less than %d\n", age, YOUNG );
      }
      else if ( age > OLD ) {
         printf( "%d is more than %d\n", age, OLD );
      }
      else {
         printf( "%d is middle-aged\n", age );
      }
   } while( age != QUIT );

   return 0;
}
