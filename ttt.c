#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define DEBUG
#define MAXMOVES 9
#define MAXINPUT 1
#define WINMOVES 8

struct user {
   int   id;         /* Player ID */
   char  name[1];    /* Player Name */
} x, o;

struct user x = {1,'X'};
struct user o = {2,'O'};
struct user *player = &x;
int pos = -1;
int mode = 0;
int board[MAXMOVES] = { 0,0,0,0,0,0,0,0,0 };
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
void get_position(int *pos_ptr)
{
   int i = -1;
   char input[MAXINPUT];
   bool lpos = false;

   while(lpos != true) {
      printf( "\n%s, select a position [0-8] or ctrl-c to exit: ", player->name );
      scanf( "%s", &input[0] );

      /* Recast char input[0] as int i */
      if( isdigit(input[0]) )
         i = input[0] - '0';

      if( (i >= 0 && i <= WINMOVES) && board[i] == 0 ) {
         *pos_ptr = i;
         lpos = true;
      } else {
         printf("Invalid move, try again!\n");
      }
   }
}

/* Evaluate play/game mode:
 * 0: game play
 * 1: game win
 * 2: tie game
 */
void is_winning_turn(int *var)
{
   int i = 0;

   while( *var == 0 && i < WINMOVES ) {
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
      if( board[i] == 0 )
         printf("-\t");
      else if( board[i] == 1 )
         printf("X\t");
      else if( board[i] == 2 )
         printf("O\t");

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
   printf("\tand ending bottom right. %s goes first.\n", player->name);
   draw_board();
   printf("\nThe board is clear...\n");

   do {

      #ifdef DEBUG
      printf("\nDEBUG: moves remaining: %d; mode: %d\n", moves(), mode);
      #endif

      get_position(&pos);
      board[pos] = player->id;
      draw_board();
      is_winning_turn(&mode);
      if( mode == 0) {
         if( player->id == x.id ) {
            player = &o;
         } else if( player->id == o.id ) {
            player = &x;
         }
      }

   } while( (moves() > 0 ) && ( mode == 0 ) );

   if( mode == 1 ) {
      printf( "\nVictory!\nPlayer %s made the winning move!\n", player->name );
   } else {
      mode = 2;
      printf( "\nIt's a tie\n" );
   }

   #ifdef DEBUG
   printf("\nDEBUG: moves remaining: %d; mode: %d\n", moves(), mode);
   #endif
}
