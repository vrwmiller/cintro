#include <stdio.h>

#undef DEBUG /* #define'ing DEBUG for additional debugging output */

int main(int argc, char *argv[])
{

   /* Some pre-processor code for very basic lint */
   #ifdef DEBUG

   static int i;
   printf( "argc: %d\n", argc );
   for( i=0; i<argc; i++ )
      printf( "argv[%d]: %s\n", i, argv[i] );

   #endif

   int zip;
   zip = 92126;
   printf( "zip: %d\n", zip );
   return 0;
}
