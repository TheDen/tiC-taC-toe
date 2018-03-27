#include <stdio.h>
//#include <stdlib.h>                                               // library included for qsort, RAND_MAX, rand, srand
//#include <math.h>                                                 // include the C numerics library for mathematical functions
//#include <time.h>                                                 // include C time library for using time() function as seed

#define squares 9

char print_board(char, int);
int print_score(int, int);

int
main(int argc, char **argv) {
  int i;
  int score_cross = 0;
  int score_naught = 0;
  int end = 0;
  int square_num;
  int player_turn = 0;
  int answer_confirm;
  char board[squares];
  char cross = 'X';
  char naught = 'O';
  char answer[100];

  printf("\nTic Tac Toe -- Two Players\n");

  // print board
  for (i=0; i<squares; i++) {
    board[i] = (char)(((int)'1')+i);
  }

  for (i=0; i<squares; i++) {
    print_board(board[i], i);
  }


  while (end==0) {

    if (player_turn==0) {
      printf("Player 1 (cross), choose your square[1-9]: ");
      scanf("%d", &square_num);
      if (board[square_num-1]==cross || board[square_num-1]==naught) {
        printf("Square already chosen\n");
        player_turn = 0;
      }
      else if (square_num > 9 || square_num <1) {
        printf("Invalid_input, ty again\n");
        player_turn = 0;
      }
      else {
        board[square_num-1] = cross;
        for (i=0; i<squares; i++) {
          print_board(board[i], i);
        }
        player_turn = 1;
      }
    }
    else if (player_turn==1) {
      printf("Player 2 (na1ught), choose your square[1-9]: ");
      scanf("%d", &square_num);
      if (board[square_num-1]==cross || board[square_num-1]==naught) {
        printf("Square already chosen\n");
        player_turn = 1;
      }
      else if (square_num > 9 || square_num < 1) {
        printf("Invalid_input, ty again\n");
        player_turn = 1;
      }
      else {
        board[square_num-1] = naught;
        for (i=0; i<squares; i++) {
          print_board(board[i], i);
        }
        player_turn = 0;
      }
    }

    for (i=0; i<5; i+= 3) {
      if (board[i] == cross && board[i+1] == cross && board[i+2]== cross) {
        printf("Player 1 wins round!\n" );
        score_cross += 1;
        print_score(score_cross, score_naught);
        end = 1;
      }
      if (board[i] == naught && board[i+1] == naught && board[i+2]== naught) {
        printf("Player 2 wins round!\n" );
        score_naught += 1;
        print_score(score_cross, score_naught);
        end = 1;
      }

    }
    for (i=0; i<3; i++) {
      if (board[i] == cross && board[i+3] == cross && board[i+6]==cross) {
        printf("Player 1 wins round!\n" );
        score_cross += 1;
        print_score(score_cross, score_naught);
        end = 1;
      }
      if (board[i] == naught && board[i+3] == naught && board[i+6]==naught) {
        printf("Player 2 wins round!\n" );
        score_naught += 1;
        print_score(score_cross, score_naught);
        end = 1;
      }
    }
    if ((board[0]==cross && board[4]==cross && board[8]==cross) || (board[2]==cross && board[4]==cross && board[6]==cross)) {
      printf("Player 1 wins round!\n" );
      score_cross += 1;
      print_score(score_cross, score_naught);
      end = 1;
    }
    if ((board[0]==naught && board[4]==naught && board[8]==naught) || (board[2]==naught && board[4]==naught && board[6]==naught)) {
      printf("Player 2 wins round!\n" );
      score_naught += 1;
      print_score(score_cross, score_naught);
      end = 1;
    }

    if (end==1) {
      answer_confirm = 0;
      printf("\nWould you like to play another round? ");

      scanf("%s", answer);
      while(answer_confirm==0) {
        if (*answer == 'Y' || *answer == 'y') {
          answer_confirm = 1;
          for (i=0; i<squares; i++) {
            board[i] = (char)(((int)'1')+i);
          }
          for (i=0; i<squares; i++) {
            print_board(board[i], i);
          }
          printf("\n");
          end = 0;
        }
        else if (*answer == 'N' || *answer == 'n') {
          answer_confirm = 1;
          end = 1;
        }
        else {
          printf("\nERROR: INVALID INPUT. Please try answering again: " );
          scanf("%s", answer);
        }
      }
    }
  }
  printf("\nFinal ");
  print_score(score_cross, score_naught);
  if (score_cross>score_naught) {
    printf("Player 1 wins match!\n");
  }
  if (score_cross<score_naught) {
    printf("Player 2 wins match!\n");
  }
  if (score_cross==score_naught) {
    printf("A tie!\n");
  }
  return 0;
}

int print_score(score_cross, score_naught) {
  printf("Score: P1 = %d | P2 = %d\n", score_cross, score_naught);
  return 0;
}

char print_board(char board_aux, int count) {
  int i = count;
  char board[squares];
  board[count] = board_aux;

  if (i==squares-1) {
    printf("----------\n");
    for (i=0; i<squares; i++) {
      printf("|%c",board[i]);
      if (i==2 || i==5 || i== 8) {
        printf("|\n");
      }
    }
    printf("----------\n");
  }
  return 0;
}
