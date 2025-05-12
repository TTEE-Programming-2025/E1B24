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

