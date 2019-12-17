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

/* Evaluate play; Return true if play is winner */
int is_winning_turn(void)
{

   int i = 0;
   bool win = false;

   while( win == false && i < 8 ) {

      if( *winMv[i][0] == *winMv[i][1] && *winMv[i][1] == *winMv[i][2] )
         if( *winMv[i][0] != 0 )
            win = true;
      i++;

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
   int pos;
   bool validPos = false;
   bool iswin = false;

   do {

      #ifdef DEBUG
      printf("\nDEBUG: move: %d; validPos: %d\n", move, validPos);
      #endif

      while( validPos != true ) {

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

             validPos = true;

          } else {
             printf("Invalid move, try again!\n");
          }
      }

      validPos = false;
      move++;

   } while( (move < MAXMOVES ) && ( iswin == false ) );

   if( iswin == true )
      printf( "\nVictory!\nPlayer %d made the winning move!\n", *player );
   else
      printf( "\nIt's a tie\n" );

}
