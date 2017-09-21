
#include <stdio.h>
#include <stdbool.h>

#define DEBUG

char board[3][3] = {
   { '-','-','-' },
   { '-','-','-' },
   { '-','-','-' },
};
char player = 'X';

/*
 * Functions
 */
int take_turn(void)
{
   int position, x, y;

   printf( "\nNext Turn!\n%c, select a position [0-8]: ", player );
   scanf( "%d", &position ); /* I really don't like character strings */

   if( position == 0 ) {
      x = 0;
      y = 0;
   }
   else if( position == 1 ) {
      x = 0;
      y = 1;
   }
   else if( position == 2 ) {
      x = 0;
      y = 2;
   }
   else if( position == 3 ) {
      x = 1;
      y = 0;
   }
   else if( position == 4 ) {
      x = 1;
      y = 1;
   }
   else if( position == 5 ) {
      x = 1;
      y = 2;
   }
   else if( position == 6 ) {
      x = 2;
      y = 0;
   }
   else if( position == 7 ) {
      x = 2;
      y = 1;
   }
   else if( position == 8 ) {
      x = 2;
      y = 2;
   }
   else {
      return 1;
   }

   #ifdef DEBUG
   printf( "Position: %d\n", position );
   printf( "Position state: %c\n", board[x][y] );
   printf( "x: %d\ny: %d\n", x, y );
   #endif

   if( board[x][y] == '-' ) { /* Position open */
      board[x][y] = player;
   }
   else { /* Position invalid */

   }

   if( player == 'X' ) {
      player = 'O';
   }
   else if( player == 'O' ) {
      player = 'X';
   }

   #ifdef DEBUG
   printf("Next player = %c\n", player);
   #endif

   return 0;
}

int is_winning_turn(void)
{
   /* Code goes here to evaluate players turn.  If player made
    * a winning move, we must return 1 to exit the game. */
   return 1;
}

void draw_board()
{
   int x = 0;
   int y = 0;

   printf("\nDrawing board...\n\n");

   while( x < 3 ) {
      while( y < 3 ) {
         printf("%c\t", board[x][y]);
         y++;
      }
      x++;
      y = 0;
      printf("\n");
   }
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

   printf("Welcome to Tic-Tac-Toe!\n\n");
   printf("\tPositions on the board are 0 - 8 starting at top left\n");
   printf("\tand ending bottom right. X goes first.\n");
   draw_board(board);
   printf("\nThe board is clear...\n");


   while( true )
   {
      take_turn();
      draw_board();
      if( is_winning_turn()) {
         printf( "\nVictory!\nPlayer %c made the winning move!\n", player );
         break;
      }
   }

   return 0;
}
