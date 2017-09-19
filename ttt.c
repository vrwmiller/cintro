
#include <stdio.h>

/* #define'ing DEBUG causes additional output useful for debugging */
#undef DEBUG

int board[3][3] = {
   { 1,1,1 },
   { 1,1,1 },
   { 1,1,1 }
};
int o, x;

/*
 * Functions
 */
int take_turn()
{
   return 0;
}

int eval_turn()
{
   return 0;
}

int draw_board()
{
   printf("Drawing board...\n");
   
   return 0;
}

/*
 * Main
 */
int main(int argc, char *argv[])
{

   /* Some pre-processor code for very basic lint */
   #ifdef DEBUG

   static int i;
   printf( "argc: %d\n", argc );
   for( i=0; i<argc; i++ )
      printf( "argv[%d]: %s\n", i, argv[i] );

   #endif

   printf("Welcome to Tic-Tac-Toe!\n");
   draw_board(board);
   printf("The board is clear, X goes first!\n\n");

   return 0;
}
