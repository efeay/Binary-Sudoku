#include <stdio.h>
#include <stdlib.h>
#include <time.h>
char tahta[9][9];
void message(){
    char randomLetter;
    int randomNumber;
    srand(time(NULL));
    randomLetter = 'A' + (rand() % 10);
    randomNumber = (rand() % 9) + 1;
    printf("Enter Column and Row values in order, for example '%c %d'.\nType "
           "'0 0' to end the game.\n\n",randomLetter,randomNumber);
    printf("New Piece:\n");
}
void finishthecode(int satir, int sutun) {
    if (satir == 0 && sutun == 25) {
        printf("You have successfully exited.\n");
        exit(0);
    }
}
int kontrol(char sutunchar) {
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
    printf("%d\n--------\n", deger);
    if (scanf(" %c %d", &sutunchar, &satir) != 2) {
    printf("Invalid input.\nPlease enter both column and row in the format 'letter number'.\n");
        while(getchar() != '\n');
        continue;
    }
    sutun = kontrol(sutunchar);
    finishthecode(satir, sutun);
    if (satir < 1 || satir > 9 || sutun < 1 || sutun >= 9) {
      printf("Invalid coordinate.\n");
      continue;
    }
    if (tahta[satir - 1][sutun - 1] != '*') {
      printf("These coordinates are occupied, select another coordinate.\n");
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
    printf("%d %d\n--------\n", deger1, deger2);
    if (scanf(" %c %d", &sutunchar, &satir) != 2) {
    printf("Invalid input.\nPlease enter both column and row in the format 'letter number'.\n");
        while(getchar() != '\n');
        continue;
    }
    sutun = kontrol(sutunchar);
    finishthecode(satir, sutun);
    if (satir < 1 || satir > 9 || sutun < 1 || sutun >= 9) {
      printf("Invalid coordinate.\n");
      continue;
    }
    if (tahta[satir - 1][sutun - 1] != '*' || tahta[satir - 1][sutun] != '*') {
      printf("These coordinates are occupied, select another coordinate.\n");
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
    printf("%d\n%d\n--------\n", deger1, deger2);
    if (scanf(" %c %d", &sutunchar, &satir) != 2) {
    printf("Invalid input.\nPlease enter both column and row in the format 'letter number'.\n");
        while(getchar() != '\n');
        continue;
    }
    sutun = kontrol(sutunchar);
    finishthecode(satir, sutun);
    if (satir < 1 || satir >= 9 || sutun < 1 || sutun > 9) {
      printf("Invalid coordinate.\n");
      continue;
    }
    if (tahta[satir - 1][sutun - 1] != '*' || tahta[satir][sutun - 1] != '*') {
      printf("These coordinates are occupied, select another coordinate.\n");
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
    printf("%d\n%d\n%d\n--------\n", deger1, deger2, deger3);
    if (scanf(" %c %d", &sutunchar, &satir) != 2) {
    printf("Invalid input.\nPlease enter both column and row in the format 'letter number'.\n");
        while(getchar() != '\n');
        continue;
    }
    sutun = kontrol(sutunchar);
    finishthecode(satir, sutun);
    if (satir < 1 || satir >= 8 || sutun < 1 || sutun > 9) {
      printf("Invalid coordinate.\n");
      continue;
    }

    if (tahta[satir - 1][sutun - 1] != '*' || tahta[satir][sutun - 1] != '*' ||
        tahta[satir + 1][sutun - 1] != '*') {
      printf("These coordinates are occupied, select another coordinate.\n");
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
    printf("%d %d %d\n--------\n", deger1, deger2, deger3);
    if (scanf(" %c %d", &sutunchar, &satir) != 2) {
    printf("Invalid input.\nPlease enter both column and row in the format 'letter number'.\n");
        while(getchar() != '\n');
        continue;
    }
    sutun = kontrol(sutunchar);
    finishthecode(satir, sutun);
    if (satir < 1 || satir > 9 || sutun < 1 || sutun >= 8) {
      printf("Invalid coordinate.\n");
      continue;
    }
    if (tahta[satir - 1][sutun - 1] != '*' || tahta[satir - 1][sutun] != '*' ||
        tahta[satir - 1][sutun + 1] != '*') {
      printf("These coordinates are occupied, select another coordinate.\n");
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
      printf("%d %d \n%d\n--------\n", deger1, deger2, deger3);
      if (scanf(" %c %d", &sutunchar, &satir) != 2) {
         printf("Invalid input.\nPlease enter both column and row in the format 'letter number'.\n");
        while(getchar() != '\n');
        continue;
      }
      sutun = kontrol(sutunchar);
      finishthecode(satir, sutun);
      if (satir < 1 || satir > 8 || sutun < 1 || sutun >= 9) {
        printf("Invalid coordinate.\n");
        continue;
      }
      if (tahta[satir - 1][sutun - 1] != '*' ||
          tahta[satir - 1][sutun] != '*' || tahta[satir][sutun - 1] != '*') {
        printf("These coordinates are occupied, select another coordinate.\n");
        continue;
      }
      tahta[satir - 1][sutun - 1] = deger1 + '0';
      tahta[satir - 1][sutun] = deger2 + '0';
      tahta[satir][sutun - 1] = deger3 + '0';
    } else if (varyant == 1) {
      message();
      printf("%d %d\n  %d\n--------\n", deger1, deger2, deger3);
      if (scanf(" %c %d", &sutunchar, &satir) != 2) {
        printf("Invalid input.\nPlease enter both column and row in the format 'letter number'.\n");
        while(getchar() != '\n');
        continue;
      }
      sutun = kontrol(sutunchar);
      finishthecode(satir, sutun);
      if (satir < 1 || satir > 8 || sutun < 1 || sutun > 8) {
        printf("Invalid coordinate.\n");
        continue;
      }
      if (tahta[satir - 1][sutun - 1] != '*' ||
          tahta[satir - 1][sutun] != '*' || tahta[satir][sutun] != '*') {
        printf("These coordinates are occupied, select another coordinate.\n");
        continue;
      }
      tahta[satir - 1][sutun - 1] = deger1 + '0';
      tahta[satir - 1][sutun] = deger2 + '0';
      tahta[satir][sutun] = deger3 + '0';
    } else if (varyant == 2) {
      message();
      printf("%d\n%d %d\n--------\n", deger1, deger2, deger3);
      if (scanf(" %c %d", &sutunchar, &satir) != 2) {
    printf("Invalid input.\nPlease enter both column and row in the format 'letter number'.\n");
        while(getchar() != '\n');
        continue;
      }
      sutun = kontrol(sutunchar);
      finishthecode(satir, sutun);
      if (satir < 1 || satir >= 9 || sutun < 1 || sutun > 8) {
        printf("Invalid coordinate.\n");
        continue;
      }
      if (tahta[satir - 1][sutun - 1] != '*' ||
          tahta[satir][sutun - 1] != '*' || tahta[satir][sutun] != '*') {
        printf("These coordinates are occupied, select another coordinate.\n");
        continue;
      }
      tahta[satir - 1][sutun - 1] = deger1 + '0';
      tahta[satir][sutun - 1] = deger2 + '0';
      tahta[satir][sutun] = deger3 + '0';
    } else if (varyant == 3) {
      message();
      printf("  %d\n%d %d\n--------\n", deger3, deger1, deger2);
      if (scanf(" %c %d", &sutunchar, &satir) != 2) {
         printf("Invalid input.\nPlease enter both column and row in the format 'letter number'.\n");
        while(getchar() != '\n');
        continue;
      }
      sutun = kontrol(sutunchar);
      finishthecode(satir, sutun);
      if (satir < 3 || satir > 9 || sutun < 1 || sutun > 8) {
        printf("Invalid coordinate.\n");
        continue;
      }
      if (tahta[satir - 1][sutun - 1] != '*' ||
          tahta[satir - 1][sutun] != '*' || tahta[satir - 2][sutun] != '*') {
        printf("These coordinates are occupied, select another coordinate.\n");
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
    printf("%d %d\n%d %d\n--------\n", deger1, deger2, deger3, deger4);
    if (scanf(" %c %d", &sutunchar, &satir) != 2) {
        printf("Invalid input.\nPlease enter both column and row in the format 'letter number'.\n");
        while(getchar() != '\n');
        continue;
    }
    sutun = kontrol(sutunchar);
    finishthecode(satir, sutun);
    if (satir < 1 || satir >= 9 || sutun < 1 || sutun >= 9) {
      printf("Invalid coordinate.\n");
      continue;
    }
    if (tahta[satir - 1][sutun - 1] != '*' || tahta[satir][sutun - 1] != '*' ||
        tahta[satir - 1][sutun] != '*' || tahta[satir][sutun] != '*') {
      printf("These coordinates are occupied, select another coordinate.\n");
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
  int varyasyon = rand() % 74;
  if (varyasyon < 2) {
    birsimge();
  } else if (varyasyon < 6) {
    ikisimgeyatay();
  } else if (varyasyon < 10) {
    ikisimgedikey();
  } else if (varyasyon < 18) {
    ucsimgeyatay();
  } else if (varyasyon < 26) {
    ucsimgedikey();
  } else if (varyasyon < 58) {
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
  int piece = 0;
  while (1) {
    printf("                  A B C   D E F   G H J\n");
    printf("                +-------+-------+-------+   Number of Placed Pieces = %d\n",piece);
    for (i = 0; i < 9; i++) {
      printf("              %d |", i + 1);
      for (j = 0; j < 9; j++) {
        printf(" %c", tahta[i][j]);
        if ((j + 1) % 3 == 0 && j != 8) {
          printf(" |");
        }
      }
      printf(" | \n");
      if ((i + 1) % 3 == 0 && i != 8) {
        printf("                +-------+-------+-------+\n"); 
      }
    }
    printf("                +-------+-------+-------+\n");
    piece = piece + 1;
    varyasyonsec();
  }
}
