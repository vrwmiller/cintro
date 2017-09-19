#include <stdio.h>

#undef DEBUG

int main(int argc, char *argv[])
{

   /* Some pre-processor code for very basic lint */
   #ifdef DEBUG

   static int i;
   printf( "argc: %d\n", argc );
   for( i=0; i<argc; i++ )
      printf( "argv[%d]: %s\n", i, argv[i] );

   #endif

   return 0;
}
