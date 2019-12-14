
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

   printf( "\n%c, select a position [0-8]: ", *player );
   scanf( "%d", &i ); /* I really don't like character strings */

   return i;
}

int take_turn(void)
{
   int position = get_position();

   #ifdef DEBUG
   printf( "Position: %d\n", position );
   printf( "Position state: %d\n", board[position] );
   #endif

   if( board[position] == 0 ) { /* Position open */
      board[position] = *player;
   }
   else { /* Position invalid */

   }

   if( *player == x ) {
      player = &o;
   }
   else if( *player == o ) {
      player = &x;
   }

   #ifdef DEBUG
   printf("Next player = %c\n", *player);
   #endif

   return 0;
}

int is_winning_turn(void)
{
   /* Evaluate play; Exit if a winning move is made */
   return 0;
}

void draw_board()
{
   int j = 1;
   printf("\nDrawing board...\n\n");

   for( int i = 0; i < MAXMOVES; i++ )
   {
      printf("%d\t", board[i]);
      if( j%3 == 0 ) {
         printf("\n");
      }
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
   printf( "argc: %d\n", argc );
   for( i=0; i<argc; i++ )
      printf( "argv[%d]: %s\n", i, argv[i] );
   #endif

   printf("Welcome to Tic-Tac-Toe!\n\n");
   printf("\tPositions on the board are 0 - 8 starting at top left\n");
   printf("\tand ending bottom right. X goes first.\n");
   draw_board();
   printf("\nThe board is clear...\n");

   int ea = 0;
   while( ea < MAXMOVES ) {
      take_turn();
      draw_board();
      if( is_winning_turn()) {
         printf( "\nVictory!\nPlayer %c made the winning move!\n", *player );
         break;
      }
      ea++;
   }

   return 0;
}
