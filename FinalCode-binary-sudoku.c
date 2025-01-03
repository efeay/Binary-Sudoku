#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <math.h>
#include <stdbool.h>
char tahta[9][9];
int puan = 0;
void kontrolSatir(char tahta[9][9], int *puan) {
    for (int i = 0; i < 9; i++) {
        bool dolumu = true;
        int binaryValue = 0;
        for (int j = 0; j < 9; j++) {
            if (tahta[i][j] == '*') {
                dolumu = false;
                break;
            }
            binaryValue = binaryValue * 2 + (tahta[i][j] - '0');
        }
        if (dolumu) {
            *puan += binaryValue;
            for (int j = 0; j < 9; j++) {
                tahta[i][j] = '*';
            }
        }
    }
}
void kontrolBlok(char tahta[9][9], int *puan) {
    for (int i = 0; i < 9; i += 3) {
        for (int j = 0; j < 9; j += 3) { 
            bool dolumu = true;
            int binaryValue = 0;
            for (int k = 0; k < 3; k++) {
                for (int l = 0; l < 3; l++) {
                    if (tahta[i + k][j + l] == '*') {
                        dolumu = false;
                        break;
                    }
                    binaryValue = binaryValue * 2 + (tahta[i + k][j + l] - '0');
                }
                if (!dolumu) {
                    break;
                }
            }
            if (dolumu) {
                *puan += binaryValue;
                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 3; l++) {
                        tahta[i + k][j + l] = '*';
                    }
                }
            }
        }
    }
}

void kontrolSutun(char tahta[9][9], int *puan) {
    for (int j = 0; j < 9; j++) {
        bool dolumu = true;
        int binaryValue = 0;
        for (int i = 0; i < 9; i++) {
            if (tahta[i][j] == '*') {
                dolumu = false;
                break;
            }
            binaryValue = binaryValue * 2 + (tahta[i][j] - '0');
        }
        if (dolumu) {
            *puan += binaryValue;
            for (int i = 0; i < 9; i++) {
                tahta[i][j] = '*';
            }
        }
    }
}
void message() {
    char randomLetter;
    int randomNumber;
    srand(time(NULL));
    randomLetter = 'A' + (rand() % 10);
    randomNumber = (rand() % 9) + 1;
    const char *message1 = "\n\n\033[0mEnter Column and Row values in order, for example '";
    const char *message2 = "'.\nType '0 0' to end the game.\n\n\033[31mNew Piece:\n\033[34m";
    for (const char *ptr = message1; *ptr != '\0'; ptr++) {
        putchar(*ptr);
        fflush(stdout);
        usleep(1000);
    }
    printf("%c %d", randomLetter, randomNumber);
    fflush(stdout);
    for (const char *ptr = message2; *ptr != '\0'; ptr++) {
        putchar(*ptr);
        fflush(stdout);
        usleep(1000);
    }
}

void finishthecode(int satir, int sutun) {
    if (satir == 0 && sutun == 25) {
        printf("You have successfully exited.\n");
        exit(0);
    }
}
int donustur(char sutunchar) {
    switch (sutunchar) {
    case 'A': return 1;
    case 'B': return 2;
    case 'C': return 3;
    case 'D': return 4;
    case 'E': return 5;
    case 'F': return 6;
    case 'G': return 7;
    case 'H': return 8;
    case 'J': return 9;
    case '0':return 25;
    default: return -1;
    }
}
void birsimge() {
  int deger = rand() % 2;
  int satir;
  int sutun;
  char sutunchar;
  while (1) {
    message();
    printf("%d\n\033[37m========                                                             *\033[93mThe center piece is always the top-leftmost point,\n                                                                      with the leftmost position taking priority in case                                                                                                          of ambiguity.\n\033[32m", deger);
    if (scanf(" %c %d", &sutunchar, &satir) != 2) {
    printf("\n\033[41m\033[37mInvalid coordinate.\nPlease enter both column and row in the format 'letter number'.\033[40m\n\n");
        while(getchar() != '\n');
        continue;
    }
    sutun = donustur(sutunchar);
    finishthecode(satir, sutun);
    if (satir < 1 || satir > 9 || sutun < 1 || sutun > 9) {
      printf("\033[41m\033[37mInvalid coordinate.\033[40m\n");
      continue;
    }
    if (tahta[satir - 1][sutun - 1] != '*') {
      printf("\033[41m\033[37mThese coordinates are occupied, select another coordinate.\033[40m\n\n");
      continue;
    }
    tahta[satir - 1][sutun - 1] = deger + '0';
    break;
  }
}
void ikisimgeyatay() {
  int deger1 = rand() % 2;
  int deger2 = rand() % 2;
  int satir, sutun;
  char sutunchar;
  while (1) {
    message();
    printf("%d %d\n\033[37m========                                                             *\033[93mThe center piece is always the top-leftmost point,\n                                                                      with the leftmost position taking priority in case                                                                                                          of ambiguity.\n\033[32m", deger1, deger2);
    if (scanf(" %c %d", &sutunchar, &satir) != 2) {
    printf("%d\n\033[41m\033[37mInvalid coordinate.\nPlease enter both column and row in the format 'letter number'.\033[40m\n\n");
        while(getchar() != '\n');
        continue;
    }
    sutun = donustur(sutunchar);
    finishthecode(satir, sutun);
    if (satir < 1 || satir > 9 || sutun < 1 || sutun >= 9) {
      printf("\033[41m\033[37mInvalid coordinate.\033[40m\n");
      continue;
    }
    if (tahta[satir - 1][sutun - 1] != '*' || tahta[satir - 1][sutun] != '*') {
      printf("\033[41m\033[37mThese coordinates are occupied, select another coordinate.\033[40m\n\n");
      continue;
    }
    tahta[satir - 1][sutun - 1] = deger1 + '0';
    tahta[satir - 1][sutun] = deger2 + '0';
    break;
  }
}
void ikisimgedikey() {
  int deger1 = rand() % 2;
  int deger2 = rand() % 2;
  int satir, sutun;
  char sutunchar;
  while (1) {
    message();
    printf("%d\n%d\n\033[37m========                                                             *\033[93mThe center piece is always the top-leftmost point,\n                                                                      with the leftmost position taking priority in case                                                                                                          of ambiguity.\n\033[32m", deger1, deger2);
    if (scanf(" %c %d", &sutunchar, &satir) != 2) {
    printf("\n\033[41m\033[37mInvalid coordinate.\nPlease enter both column and row in the format 'letter number'.\033[40m\n\n");
        while(getchar() != '\n');
        continue;
    }
    sutun = donustur(sutunchar);
    finishthecode(satir, sutun);
    if (satir < 1 || satir >= 9 || sutun < 1 || sutun > 9) {
      printf("\033[41m\033[37mInvalid coordinate.\033[40m\n");
      continue;
    }
    if (tahta[satir - 1][sutun - 1] != '*' || tahta[satir][sutun - 1] != '*') {
      printf("\033[41m\033[37mThese coordinates are occupied, select another coordinate.\033[40m\n\n");
      continue;
    }
    tahta[satir - 1][sutun - 1] = deger1 + '0';
    tahta[satir][sutun - 1] = deger2 + '0';
    break;
  }
}
void ucsimgedikey() {
  int deger1 = rand() % 2;
  int deger2 = rand() % 2;
  int deger3 = rand() % 2;
  int satir, sutun;
  char sutunchar;
  while (1) {
    message();
    printf("%d\n%d\n%d\n\033[37m========                                                             *\033[93mThe center piece is always the top-leftmost point,\n                                                                      with the leftmost position taking priority in case                                                                                                          of ambiguity.\n\033[32m", deger1, deger2, deger3);
    if (scanf(" %c %d", &sutunchar, &satir) != 2) {
    printf("\n\033[41m\033[37mInvalid coordinate.\nPlease enter both column and row in the format 'letter number'.\033[40m\n\n");
        while(getchar() != '\n');
        continue;
    }
    sutun = donustur(sutunchar);
    finishthecode(satir, sutun);
    if (satir < 1 || satir >= 8 || sutun < 1 || sutun > 9) {
      printf("\033[41m\033[37mInvalid coordinate.\033[40m\n");
      continue;
    }

    if (tahta[satir - 1][sutun - 1] != '*' || tahta[satir][sutun - 1] != '*' ||
        tahta[satir + 1][sutun - 1] != '*') {
      printf("\033[41m\033[37mThese coordinates are occupied, select another coordinate.\033[40m\n\n");
      continue;
    }
    tahta[satir - 1][sutun - 1] = deger1 + '0';
    tahta[satir][sutun - 1] = deger2 + '0';
    tahta[satir + 1][sutun - 1] = deger3 + '0';
    break;
  }
}
void ucsimgeyatay() {
  int deger1 = rand() % 2;
  int deger2 = rand() % 2;
  int deger3 = rand() % 2;
  int satir, sutun;
  char sutunchar;
  while (1) {
    message();
    printf("%d %d %d\n\033[37m========                                                             *\033[93mThe center piece is always the top-leftmost point,\n                                                                      with the leftmost position taking priority in case                                                                                                          of ambiguity.\n\033[32m", deger1, deger2, deger3);
    if (scanf(" %c %d", &sutunchar, &satir) != 2) {
    printf("\n\033[41m\033[37mInvalid coordinate.\nPlease enter both column and row in the format 'letter number'.\033[40m\n\n");
        while(getchar() != '\n');
        continue;
    }
    sutun = donustur(sutunchar);
    finishthecode(satir, sutun);
    if (satir < 1 || satir > 9 || sutun < 1 || sutun >= 8) {
      printf("\033[41m\033[37mInvalid coordinate.\033[40m\n");
      continue;
    }
    if (tahta[satir - 1][sutun - 1] != '*' || tahta[satir - 1][sutun] != '*' ||
        tahta[satir - 1][sutun + 1] != '*') {
      printf("\033[41m\033[37mThese coordinates are occupied, select another coordinate.\033[40m\n\n");
      continue;
    }
    tahta[satir - 1][sutun - 1] = deger1 + '0';
    tahta[satir - 1][sutun] = deger2 + '0';
    tahta[satir - 1][sutun + 1] = deger3 + '0';
    break;
  }
}
void ucsimgeL() {
  int deger1 = rand() % 2;
  int deger2 = rand() % 2;
  int deger3 = rand() % 2;
  int satir, sutun;
  int varyant = rand() % 4;
  char sutunchar;
  while (1) {
    if (varyant == 0) {
      message();
      printf("%d %d \n%d\n\033[37m========                                                             *\033[93mThe center piece is always the top-leftmost point,\n                                                                      with the leftmost position taking priority in case                                                                                                          of ambiguity.\n\033[32m", deger1, deger2, deger3);
      if (scanf(" %c %d", &sutunchar, &satir) != 2) {
         printf("\n\033[41m\033[37mInvalid coordinate.\nPlease enter both column and row in the format 'letter number'.\033[40m\n\n");
        while(getchar() != '\n');
        continue;
      }
      sutun = donustur(sutunchar);
      finishthecode(satir, sutun);
      if (satir < 1 || satir > 8 || sutun < 1 || sutun >= 9) {
        printf("\033[41m\033[37mInvalid coordinate.\033[40m\n");
        continue;
      }
      if (tahta[satir - 1][sutun - 1] != '*' ||
          tahta[satir - 1][sutun] != '*' || tahta[satir][sutun - 1] != '*') {
        printf("\033[41m\033[37mThese coordinates are occupied, select another coordinate.\033[40m\n\n");
        continue;
      }
      tahta[satir - 1][sutun - 1] = deger1 + '0';
      tahta[satir - 1][sutun] = deger2 + '0';
      tahta[satir][sutun - 1] = deger3 + '0';
    } else if (varyant == 1) {
      message();
      printf("%d %d\n  %d\n\033[37m========                                                             *\033[93mThe center piece is always the top-leftmost point,\n                                                                      with the leftmost position taking priority in case                                                                                                          of ambiguity.\n\033[32m", deger1, deger2, deger3);
      if (scanf(" %c %d", &sutunchar, &satir) != 2) {
        printf("\n\033[41m\033[37mInvalid coordinate.\nPlease enter both column and row in the format 'letter number'.\033[40m\n\n");
        while(getchar() != '\n');
        continue;
      }
      sutun = donustur(sutunchar);
      finishthecode(satir, sutun);
      if (satir < 1 || satir > 8 || sutun < 1 || sutun > 8) {
        printf("\033[41m\033[37mInvalid coordinate.\033[40m\n");
        continue;
      }
      if (tahta[satir - 1][sutun - 1] != '*' ||
          tahta[satir - 1][sutun] != '*' || tahta[satir][sutun] != '*') {
        printf("\033[41m\033[37mThese coordinates are occupied, select another coordinate.\033[40m\n\n");
        continue;
      }
      tahta[satir - 1][sutun - 1] = deger1 + '0';
      tahta[satir - 1][sutun] = deger2 + '0';
      tahta[satir][sutun] = deger3 + '0';
    } else if (varyant == 2) {
      message();
      printf("%d\n%d %d\n\033[37m========                                                             *\033[93mThe center piece is always the top-leftmost point,\n                                                                      with the leftmost position taking priority in case                                                                                                          of ambiguity.\n\033[32m", deger1, deger2, deger3);
      if (scanf(" %c %d", &sutunchar, &satir) != 2) {
    printf("\n\033[41m\033[37mInvalid coordinate.\nPlease enter both column and row in the format 'letter number'.\033[40m\n\n");
        while(getchar() != '\n');
        continue;
      }
      sutun = donustur(sutunchar);
      finishthecode(satir, sutun);
      if (satir < 1 || satir >= 9 || sutun < 1 || sutun > 8) {
        printf("\033[41m\033[37mInvalid coordinate.\033[40m\n");
        continue;
      }
      if (tahta[satir - 1][sutun - 1] != '*' ||
          tahta[satir][sutun - 1] != '*' || tahta[satir][sutun] != '*') {
        printf("\033[41m\033[37mThese coordinates are occupied, select another coordinate.\033[40m\n\n");
        continue;
      }
      tahta[satir - 1][sutun - 1] = deger1 + '0';
      tahta[satir][sutun - 1] = deger2 + '0';
      tahta[satir][sutun] = deger3 + '0';
    } else if (varyant == 3) {
      message();
      printf("  %d\n%d %d\n\033[37m========                                                             *\033[93mThe center piece is always the top-leftmost point,\n                                                                      with the leftmost position taking priority in case                                                                                                          of ambiguity.\n\033[32m", deger3, deger1, deger2);
      if (scanf(" %c %d", &sutunchar, &satir) != 2) {
         printf("\n\033[41m\033[37mInvalid coordinate.\nPlease enter both column and row in the format 'letter number'.\033[40m\n\n");
        while(getchar() != '\n');
        continue;
      }
      sutun = donustur(sutunchar);
      finishthecode(satir, sutun);
      if (satir < 2 || satir > 9 || sutun < 1 || sutun > 8) {
        printf("\033[41m\033[37mInvalid coordinate.\033[40m\n");
        continue;
      }
      if (tahta[satir - 1][sutun - 1] != '*' ||
          tahta[satir - 1][sutun] != '*' || tahta[satir - 2][sutun] != '*') {
        printf("\033[41m\033[37mThese coordinates are occupied, select another coordinate.\033[40m\n\n");
        continue;
      }
      tahta[satir - 1][sutun - 1] = deger1 + '0';
      tahta[satir - 1][sutun] = deger2 + '0';
      tahta[satir - 2][sutun] = deger3 + '0';
    }
    break;
  }
}
void dortsimge() {
  int deger1 = rand() % 2;
  int deger2 = rand() % 2;
  int deger3 = rand() % 2;
  int deger4 = rand() % 2;
  int satir, sutun;
  char sutunchar;
  while (1) {
    message();
    printf("%d %d\n%d %d\n\033[37m========                                                             *\033[93mThe center piece is always the top-leftmost point,\n                                                                      with the leftmost position taking priority in case                                                                                                          of ambiguity.\n\033[32m", deger1, deger2, deger3, deger4);
    if (scanf(" %c %d", &sutunchar, &satir) != 2) {
        printf("\n\033[41m\033[37mInvalid coordinate.\nPlease enter both column and row in the format 'letter number'.\033[40m\n\n");
        while(getchar() != '\n');
        continue;
    }
    sutun = donustur(sutunchar);
    finishthecode(satir, sutun);
    if (satir < 1 || satir >= 9 || sutun < 1 || sutun >= 9) {
      printf("\033[41m\033[37mInvalid coordinate.\033[40m\n");
      continue;
    }
    if (tahta[satir - 1][sutun - 1] != '*' || tahta[satir][sutun - 1] != '*' ||
        tahta[satir - 1][sutun] != '*' || tahta[satir][sutun] != '*') {
      printf("\033[41m\033[37mThese coordinates are occupied, select another coordinate.\033[40m\n\n");
      continue;
    }
    tahta[satir - 1][sutun - 1] = deger1 + '0';
    tahta[satir][sutun - 1] = deger2 + '0';
    tahta[satir - 1][sutun] = deger3 + '0';
    tahta[satir][sutun] = deger4 + '0';
    break;
  }
}
void varyasyonsec() {
  int varyasyon = rand() % 19;
  if (varyasyon < 1) {
    birsimge();
  } else if (varyasyon < 3) {
    ikisimgeyatay();
  } else if (varyasyon < 5) {
    ikisimgedikey();
  } else if (varyasyon < 7) {
    ucsimgeyatay();
  } else if (varyasyon < 9) {
    ucsimgedikey();
  } else if (varyasyon < 17) {
    ucsimgeL();
  } else {
    dortsimge();
  }
}
int main() {
  srand(time(NULL));
  int i, j;
  for (i = 0; i < 9; i++) {
    for (j = 0; j < 9; j++) {
      tahta[i][j] = '*';
    }
  }

  int piece = 50;
  printf("\n");
  printf("\033[0;34m");
  printf("                                                    ************************************\n");
  printf("******************************************************    Welcome to Binary Sudoku    ******************************************************\n");
  printf("I                                                   ************************************                                                   I\n");
  printf("I                                                                                                                                          I\n");
  printf("I     Our game has very simple rules.                                                                                                      I\n");
  printf("I                                                                                                                                          I\n");
  printf("I                                                                                                                                          I\n");
  printf("I     1- You get points by filling rows, columns or 3x3 blocks with 50 random pieces generated for you and then these areas are emptied.   I\n");
  printf("I                                                                                                                                          I\n");
  printf("I     2- Depending on the difficulty type you choose,if you reach the minimum score when your number of moves is over, you win.            I\n");
  printf("I                                                                                                                                          I\n");
  printf("I     3- But when there is more than one explosion at the same time, the priority is always in the Row,                                    I\n");
  printf("I        then in the Column, then in the 3x3 block.                                                                                        I\n");
  printf("I                                                                                                                                          I\n");
  printf("I                                                                                                                                          I\n");
  printf("********************************************************************************************************************************************\n\n\n");
  printf("\033[0m");
  printf("       *If you see that there is no space left for your piece on the table, do not be upset, but you have lost.\n");
  printf("        Please end the game by entering '0, 0' and try again from the beginning.\n\n\n");
  printf("\033[1;31m");
  printf("        Please choose the difficulty level:\n\n\n");
  printf("\033[0m");
  printf("        1 - Easy (You have to reach at least 3000 Points)\n\n");
  printf("        2 - Medium (You have to reach at least 4000 Points)\n\n");
  printf("        3 - Hard (You have to reach at least 5000 Points)\n\n\n");
  printf("\033[1;31m");
  printf("        Please enter the number of the difficulty level you want and start to the game: ");
  printf("\033[0m");
  int level;
  int limit;
  while (1) {
      if (scanf("%d", &level) != 1) {
      printf("\n\033[41m\033[37m        Invalid difficulty level! Please enter a number:\033[40m");
          while(getchar() != '\n');
          continue;
      }
        
      if (level == 1) {
          limit = 3000;
          break;
      } else if (level == 2) {
          limit = 4000;
          break;
      } else if (level == 3) {
          limit = 5000;
          break;
      } else {
          printf("\n\033[41m\033[37m        Invalid difficulty level! Please enter a valid difficulty level (1, 2, or 3):\033[40m");
      }
  }
  while (0 < piece) {
    kontrolSatir(tahta,&puan);
    kontrolSutun(tahta,&puan);
    kontrolBlok(tahta,&puan);
    system("cls");
    printf("                    \033[0m========================\n");
    printf("                    ||                    ||\n");
    printf("                    ||    \033[31m\033[3mBINARY SUDOKU\033[0m   ||\n");
    printf("                    ||                    ||\n");
    printf("                    ========================\n\n");
    printf("\033[31m");
    printf("                      \033[33mA B C   D E F   G H J\n");
    printf("                    \033[31mp-------o-------o-------q     \033[0mNumber of Remaining Pieces = \033[36m%d \n\033[0m", piece);
    for (i = 0; i < 9; i++) {
      printf("                  \033[34m%d\033[31m |", i + 1);
      for (j = 0; j < 9; j++) {
        printf(" %c", tahta[i][j]);
        if ((j + 1) % 3 == 0 && j != 8) {
          printf(" |");
        }
      }
      printf(" | \n");
      if ((i + 1) % 3 == 0 && i != 8) {
        printf("                    o-------o-------o-------o\n");
      }
  }
    printf("                    b-------o-------o-------d     \033[0mScore = \033[36m%d\033[0m          \033[0mYou have to reach at least \033[36m%d\033[0m points\n", puan, limit);
    printf("\033[0m");
    piece = piece - 1;
    varyasyonsec();
   }
    kontrolSatir(tahta,&puan);
    kontrolSutun(tahta,&puan);
    kontrolBlok(tahta,&puan);
    system("cls");
    printf("                    \033[0m========================\n");
    printf("                    ||                    ||\n");
    printf("                    ||    \033[31m\033[3mBINARY SUDOKU\033[0m   ||\n");
    printf("                    ||                    ||\n");
    printf("                    ========================\n\n");
    printf("\033[31m");
    printf("                      \033[33mA B C   D E F   G H J\n");
    printf("                    \033[31mp-------o-------o-------q     \033[0mNumber of Remaining Pieces = \033[36m%d \n\033[0m", piece);
    for (i = 0; i < 9; i++) {
      printf("                  \033[34m%d\033[31m |", i + 1);
      for (j = 0; j < 9; j++) {
        printf(" %c", tahta[i][j]);
        if ((j + 1) % 3 == 0 && j != 8) {
          printf(" |");
        }
      }
      printf(" | \n");
      if ((i + 1) % 3 == 0 && i != 8) {
        printf("                    o-------o-------o-------o\n");
      }
  }
    printf("                    b-------o-------o-------d     \033[0mScore = \033[36m%d\033[0m          \033[0mYou have to reach at least \033[36m%d\033[0m points\n", puan, limit);
   printf("\033[0m");
   if (limit <= puan){
   printf("\n\nCONGRATULATIONS!!! The minimum score you had to reach in the game was %d and you reached it, you played very well.\n",limit);
   printf("Now you can try our other difficulty levels if you want, see you again\n\n\n");
   } else {
   printf("\n\nUnfortunately, you couldn't reach the minimum score of %d, but don't worry, you played very well.\n",limit);
   printf("If you want, you can lower the difficulty level or practice more at this difficulty level. See you again!!!\n\n\n");
   }
   system("pause");
}
