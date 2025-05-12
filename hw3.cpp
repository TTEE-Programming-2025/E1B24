#include <stdio.h>
#include <stdlib.h>

#define PASSWORD 2025
#include <time.h>

#define SIZE 9
//個人風格畫面設計 
int checkPassword() {
    int input, tries = 0;

    printf("************************************\n");
    printf("*     Welcome to the Booking System!      *\n");
    printf("*         Designed by E1B24          *\n");
    printf("*                                    *\n");
    printf("************************************\n");

    while (tries < 3) {
        printf("Please enter 4-digit password: ");//set the password input maximum,if incorrect 3 times to exit the system.
        scanf("%d", &input);

        if (input == PASSWORD) {
            printf("Access granted! Welcome!\n");
            return 1;
        } else {
            tries++;
            printf("Incorrect! Attempts left: %d\n", 3 - tries);
        }
    }

    printf("Too many failed attempts. Exiting...\n");
    return 0;
}
//主選單 
void printMenu() {
    printf("----------[Booking System]----------\n");
    printf("| a. Available seats               |\n");
    printf("| b. Arrange for you               |\n");
    printf("| c. Choose by yourself            |\n");
    printf("| d. Exit                          |\n");
    printf("------------------------------------\n");
    printf("Choose an option: ");
}
//隨機產生 10 個已被預訂的座位，並顯示座位表
int seats[SIZE][SIZE] = {0}; // 0: free space, 1: booked(*), 2: suggestion(@)

void randomBookedSeats(int count) {
    srand(time(NULL));
    int r, c, booked = 0;

    while (booked < count) {
        r = rand() % SIZE;
        c = rand() % SIZE;
        if (seats[r][c] == 0) {
            seats[r][c] = 1;
            booked++;
        }
    }
}

void showSeats() {
    printf(" \\123456789\n");
    for (int i = SIZE - 1; i >= 0; i--) {
        printf("%d", i + 1);
        for (int j = 0; j < SIZE; j++) {
            if (seats[i][j] == 1)
                printf("*");
            else if (seats[i][j] == 2)
                printf("@");
            else
                printf("-");
        }
        printf("\n");
    }
}

