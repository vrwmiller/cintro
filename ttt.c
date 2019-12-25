#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define DEBUG
#define MAXMOVES 9
#define MAXINPUT 1

int x = 1;
int o = 2;
int mode = 0;
int board[MAXMOVES] = { 0,0,0,0,0,0,0,0,0 };
int *player = &x;
int *winMv[8][3] = {
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

/* How many moves are left? */
int moves(void)
{
   int i, j = 0;

   for( i = 0; i < MAXMOVES; i++ )
      if( board[i] == 0 )
         j++;

   return j;
}

/* Get position from player */
int get_position(void)
{
   int i;
   char input[MAXINPUT];
   bool lpos = false;

   while(lpos != true) {
      printf( "\n%d, select a position [0-8] or ctrl-c to exit: ", *player );
      scanf( "%s", &input[0] );

      if( isdigit(input[0]) ) {

         /* Recast char input[0] as int i */
         i = input[0] - '0';

         if( i >= 0 && i <= 8 )
            lpos = true;
      }
   }

   return i;
}

/* Evaluate play/game mode:
 * 0: game play
 * 1: game win
 * 2: tie game
 */
void is_winning_turn(int *var)
{

   int i = 0;

   while( *var == 0 && i < 8 ) {

      if( *winMv[i][0] != 0 && *winMv[i][1] != 0 && *winMv[i][2] != 0 )
         if( *winMv[i][0] == *winMv[i][1] && *winMv[i][1] == *winMv[i][2] )
            *var = 1;
      i++;

   }

}

/* Output current board */
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

   int pos;

   do {

      #ifdef DEBUG
      printf("\nDEBUG: move: %d; mode: %d\n", moves(), mode);
      #endif

      pos = get_position();

      if( board[pos] == 0 ) {

         board[pos] = *player;
         draw_board();
         is_winning_turn(&mode);
         if( mode == 0) {
            if( *player == x ) {
               player = &o;
            } else if( *player == o ) {
               player = &x;
            }
         }

      } else {
         printf("Invalid move, try again!\n");
      }

   } while( (moves() > 0 ) && ( mode == 0 ) );

   if( mode == 1 )
      printf( "\nVictory!\nPlayer %d made the winning move!\n", *player );
   else
      printf( "\nIt's a tie\n" );

}
