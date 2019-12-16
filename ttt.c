#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define DEBUG
#define MAXMOVES 9
#define MAXINPUT 1

int x = 1;
int o = 2;
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

/* Get position from player */
int get_position(void)
{
   int i;
   char input[MAXINPUT];
   bool vpos = false;

   while(vpos != true) {
      printf( "\n%d, select a position [0-8] or ctrl-c to exit: ", *player );
      scanf( "%s", &input[0] );

      if( isdigit(input[0]) ) {

         /* Recast char input[0] as int i */
         i = input[0] - '0';

         if( i >= 0 && i <= 8 )
            vpos = true;
      }
   }

   return i;
}

/* Evaluate play; Return true if play is winner */
int is_winning_turn(void)
{

   int i, j;
   int k = 1;
   bool win = false;

   for( i = 0; i < 8; i++ ) {

      /* Moves starting w/ 0 cannot be a winning move */
      if( *winMv[i][0] == 0 )
         continue;

      if( *winMv[i][0] == *winMv[i][1] && *winMv[i][1] == *winMv[i][2] )
            win = true;
   }

   return win;

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

   int move = 0;
   int vpos = 1;
   int pos;
   bool iswin = false;

   do {

      #ifdef DEBUG
      printf("\nDEBUG: move: %d; vpos: %d\n", move, vpos);
      #endif

      while( vpos != 0 ) {

          pos = get_position();

          if( board[pos] == 0 ) {

             board[pos] = *player;
             iswin = is_winning_turn();

             draw_board();
             if( iswin == false) {
                if( *player == x ) {
                   player = &o;
                } else if( *player == o ) {
                   player = &x;
                }
             }

             vpos = 0;

          } else {
             printf("Invalid move, try again!\n");
          }
      }

      vpos++;
      move++;

   } while( (move < MAXMOVES ) && ( iswin == false ) );

   printf( "\nVictory!\nPlayer %d made the winning move!\n", *player );

}
