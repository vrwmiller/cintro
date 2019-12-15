
#include <stdio.h>
#include <stdbool.h>

#define DEBUG
#define MAXMOVES 9

int x = 1;
int o = 2;
int board[MAXMOVES] = { 0,0,0,0,0,0,0,0,0 };
int *player = &x;
int *winningMv[8][3] = {
   { &board[0], &board[1], &board[2] },
   { &board[3], &board[4], &board[5] },
   { &board[6], &board[7], &board[8] },
   { &board[0], &board[3], &board[6] },
   { &board[1], &board[4], &board[7] },
   { &board[2], &board[5], &board[8] },
   { &board[0], &board[4], &board[8] },
   { &board[2], &board[4], &board[6] }
};

/*
 * Functions
 */
int get_position()
{
   int i;

   printf( "\n%d, select a position [0-8]: ", *player );
   scanf( "%d", &i ); /* I really don't like character strings */

   return i;
}

int is_winning_turn(void)
{
   /* Evaluate play; Exit if a winning move is made */
   #ifdef DEBUG
   printf("DEBUG: is_winning?\n");
   #endif
   return false;
}

void draw_board()
{
   int j = 1;
   printf("\nDrawing board...\n\n");

   for( int i = 0; i < MAXMOVES; i++ )
   {
      printf("%d\t", board[i]);
      if( j%3 == 0 )
         printf("\n");
      j++;
   }

}

/*
 * Main
 */
int main(int argc, char *argv[])
{

   #ifdef DEBUG
   static int i;
   printf( "DEBUG: argc: %d\n", argc );
   for( i=0; i<argc; i++ )
      printf( "DEBUG: argv[%d]: %s\n", i, argv[i] );
   #endif

   printf("Welcome to Tic-Tac-Toe!\n\n");
   printf("\tBoard positions are 0 - 8 starting at top left\n");
   printf("\tand ending bottom right. X goes first.\n");
   draw_board();
   printf("\nThe board is clear...\n");

   int move = 0;
   int vpos = 1;
   int pos;
   bool win = false;

   do {
      #ifdef DEBUG
      printf("\nDEBUG: move: %d; vpos: %d\n", move, vpos);
      #endif
      while( vpos != 0 ) {
          pos = get_position();
          if( board[pos] == 0 ) {
             board[pos] = *player;
             draw_board();
             if( *player == x ) {
                player = &o;
             } else if( *player == o ) {
                player = &x;
             }
             vpos = 0;
          } else {
             printf("Invalid move, try again!\n");
          }
      }

      vpos++;
      move++;
      win = is_winning_turn();

   } while( (move < MAXMOVES ) && ( win == false ) );

   printf( "\nVictory!\nPlayer %d made the winning move!\n", *player );

}
