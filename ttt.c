
#include <stdio.h>

/* #define'ing DEBUG causes additional output useful for debugging */
#undef DEBUG

char board[3][3] = {
   { '-','-','-' },
   { '-','-','-' },
   { '-','-','-' },
};
char player = 'X';

/*
 * Functions
 */
int take_position()
{
/* 0 = board[0][0]
 * 1 = board[0][1]
 * 2 = board[0][2]
 * 3 = board[1][0]
 * 4 = board[1][1]
 * 5 = board[1][2]
 * 6 = board[2][0]
 * 7 = board[2][1]
 * 8 = board[2][2]
 */

   return 0;
}

int take_turn()
{
   int position;

   printf("X, select a position [0-8]: ");
   scanf("%d", &position); /* I really don't like character strings */

   if( player == 'X' ) {
      player = 'O';
   }
   else if( player == 'O' ) {
      player = 'X';
   }

   #ifdef DEBUG
   printf("Player = %c\n", player);
   #endif

   return 0;
}

int eval_turn()
{
   return 0;
}

int draw_board()
{
   int x = 0;
   int y = 0;

   printf("Drawing board...\n\n");

   while( x < 3 ) {
      while( y < 3 ) {
         printf("%c\t", board[x][y]);
         y++;
      }
      x++;
      y = 0;
      printf("\n");
   }
   
   return 0;
}

/*
 * Main
 */
int main(int argc, char *argv[])
{

   #ifdef DEBUG
   static int i;
   printf( "argc: %d\n", argc );
   for( i=0; i<argc; i++ )
      printf( "argv[%d]: %s\n", i, argv[i] );
   #endif

   printf("Welcome to Tic-Tac-Toe!\n");
   printf("Positions on the board are 0 - 8 starting at top left, ending\n");
   printf("bottom right.\n");
   draw_board(board);
   printf("\nThe board is clear, X goes first!\n");


   while(1)
   {
      take_turn(player);
   }

   return 0;
}
