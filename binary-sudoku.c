#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char tahta[9][9];

void birsimge() {
    int deger = rand() % 2;
    int satir;
    int sutun;

    while (1) {
        printf("Enter Row and Column numbers in order, for example '1 5'.\nType '25 25' to end the game.\n");
        printf("%d",deger);
        scanf("%d %d", &satir, &sutun);

        if (satir == 25 && sutun == 25) {
            printf("You have succesfully exited.\n");
            exit(0);
        }

        if (satir < 1 || satir > 9 || sutun < 1 || sutun > 9) {
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

    while (1) {
        printf("Enter Row and Column numbers in order, for example '1 5'.\nType '25 25' to end the game.\n");
        printf("%d %d\n",deger1,deger2);
        scanf("%d %d", &satir, &sutun);

        if (satir == 25 && sutun == 25) {
            printf("You have succesfully exited.\n");
            exit(0);
        }

        if (satir < 1 || satir > 9 || sutun < 1 || sutun >= 9) {
            printf("Invalid coordinate.\n");
            continue;
        }

        if (tahta[satir - 1][sutun - 1] != '' || tahta[satir - 1][sutun] != '') {
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

    while (1) {
        printf("Enter Row and Column numbers in order, for example '1 5'.\nType '25 25' to end the game.\n");
        printf("%d\n%d\n",deger1,deger2);
        scanf("%d %d", &satir, &sutun);

        if (satir == 25 && sutun == 25) {
            printf("You have succesfully exited.\n");
            exit(0);
        }

        if (satir < 1 || satir >= 9 || sutun < 1 || sutun > 9) {
            printf("Invalid coordinate.\n");
            continue;
        }

        if (tahta[satir - 1][sutun - 1] != '' || tahta[satir][sutun - 1] != '') {
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

    while (1) {
        printf("Enter Row and Column numbers in order, for example '1 5'.\nType '25 25' to end the game.\n");
        printf("%d\n%d\n%d\n",deger1,deger2,deger3);
        scanf("%d %d", &satir, &sutun);

        if (satir == 25 && sutun == 25) {
            printf("You have succesfully exited.\n");
            exit(0);
        }

        if (satir < 1 || satir >= 8 || sutun < 1 || sutun > 9) {
            printf("Invalid coordinate.\n");
            continue;
        }

        if (tahta[satir - 1][sutun - 1] != '' || tahta[satir][sutun - 1] != '' || tahta[satir + 1][sutun - 1] != '*') {
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

    while (1) {
        printf("Enter Row and Column numbers in order, for example '1 5'.\nType '25 25' to end the game.\n");
        printf("%d %d %d\n",deger1,deger2,deger3);
        scanf("%d %d", &satir, &sutun);

        if (satir == 25 && sutun == 25) {
            printf("You have succesfully exited.\n");
            exit(0);
        }

        if (satir < 1 || satir > 9 || sutun < 1 || sutun >= 8) {
            printf("Invalid coordinate.\n");
            continue;
        }

        if (tahta[satir - 1][sutun - 1] != '' || tahta[satir - 1][sutun] != '' || tahta[satir - 1][sutun + 1] != '*') {
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

    while (1) {

        if (varyant == 0) {
            printf("Enter Row and Column numbers in order, for example '1 5'.\nType '25 25' to end the game.\n");
            printf("%d %d \n%d\n",deger1,deger2,deger3);
            scanf("%d %d", &satir, &sutun);
            if (satir < 1 || satir > 8 || sutun < 1 || sutun >= 9) {
                printf("Invalid coordinate.\n");
                continue;
            }
            if (tahta[satir - 1][sutun - 1] != '' || tahta[satir - 1][sutun] != '' || tahta[satir][sutun - 1] != '*') {
                printf("These coordinates are occupied, select another coordinate.\n");
                continue;
            }
            tahta[satir - 1][sutun - 1] = deger1 + '0';
            tahta[satir - 1][sutun] = deger2 + '0';
            tahta[satir][sutun - 1] = deger3 + '0';
        } else if (varyant == 1) {
            printf("Enter Row and Column numbers in order, for example '1 5'.\nType '25 25' to end the game.\n");
            printf("%d %d\n  %d\n",deger1,deger2,deger3);
            scanf("%d %d", &satir, &sutun);
            if (satir < 1 || satir > 8 || sutun < 1 || sutun > 8) {
                printf("Invalid coordinate.\n");
                continue;
            }
            if (tahta[satir - 1][sutun - 1] != '' || tahta[satir - 1][sutun] != '' || tahta[satir][sutun] != '*') {
                printf("These coordinates are occupied, select another coordinate.\n");
                continue;
            }
            tahta[satir - 1][sutun - 1] = deger1 + '0';
            tahta[satir - 1][sutun] = deger2 + '0';
            tahta[satir][sutun] = deger3 + '0';
        } else if (varyant == 2) {
            printf("Enter Row and Column numbers in order, for example '1 5'.\nType '25 25' to end the game.\n");
            printf("%d\n%d %d\n",deger1,deger2,deger3);
            scanf("%d %d", &satir, &sutun);
            if (satir < 1 || satir >= 9 || sutun < 1 || sutun > 8) {
                printf("Invalid coordinate.\n");
                continue;
            }
            if (tahta[satir - 1][sutun - 1] != '' || tahta[satir][sutun - 1] != '' || tahta[satir][sutun] != '*') {
                printf("These coordinates are occupied, select another coordinate.\n");
                continue;
            }
            tahta[satir - 1][sutun - 1] = deger1 + '0';
            tahta[satir][sutun - 1] = deger2 + '0';
            tahta[satir][sutun] = deger3 + '0';
        } else if (varyant == 3){
            printf("Enter Row and Column numbers in order, for example '1 5'.\nType '25 25' to end the game.\n");
            printf("  %d\n%d %d\n",deger3,deger1,deger2);
            scanf("%d %d", &satir, &sutun);
            if (satir < 3 || satir > 9 || sutun < 1 || sutun > 8) {
                printf("Invalid coordinate.\n");
                continue;
            }
            if (tahta[satir - 1][sutun - 1] != '' || tahta[satir - 1][sutun] != '' || tahta[satir - 2][sutun] != '*') {
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

    while (1) {
        printf("Enter Row and Column numbers in order, for example '1 5'.\nType '25 25' to end the game.\n");
        printf("%d %d\n%d %d\n",deger1,deger2,deger3,deger4);
        scanf("%d %d", &satir, &sutun);

        if (satir == 25 && sutun == 25) {
            printf("You have succesfully exited.\n");
            exit(0);
        }

        if (satir < 1 || satir >= 9 || sutun < 1 || sutun >= 9) {
            printf("Invalid coordinate.\n");
            continue;
        }

        if (tahta[satir - 1][sutun - 1] != '' || tahta[satir][sutun - 1] != '' ||
            tahta[satir - 1][sutun] != '' || tahta[satir][sutun] != '') {
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

    while (1) {
        printf("    1 2 3   4 5 6   7 8 9\n");
        printf("  +-------+-------+-------+\n");
        for (i = 0; i < 9; i++) {
            printf("%d |", i + 1);
            for (j = 0; j < 9; j++) {
                printf(" %c", tahta[i][j]);
                if ((j + 1) % 3 == 0 && j != 8) {
                    printf(" |");
                }
            }
            printf(" |\n");
            if ((i + 1) % 3 == 0 && i != 8) {
                printf("  +-------+-------+-------+\n");
            }
        }
        printf("  +-------+-------+-------+\n");
        varyasyonsec();
   }
}
