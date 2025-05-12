#include <stdio.h>
#include <stdlib.h>

#define PASSWORD 2025
#include <time.h>

#define SIZE 9
#include <string.h>
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
//電腦自動安排座位，並讓使用者確認
void clearSuggestions() {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (seats[i][j] == 2)
                seats[i][j] = 0;
}

int isAvailable(int r, int c) {
    return r >= 0 && r < SIZE && c >= 0 && c < SIZE && seats[r][c] == 0;
}

void suggestSeats(int count) {
    clearSuggestions();
    int found = 0;

    if (count <= 3) {
        for (int i = 0; i < SIZE && !found; i++) {
            for (int j = 0; j <= SIZE - count; j++) {
                int ok = 1;
                for (int k = 0; k < count; k++)
                    if (!isAvailable(i, j + k)) ok = 0;

                if (ok) {
                    for (int k = 0; k < count; k++)
                        seats[i][j + k] = 2;
                    found = 1;
                    break;
                }
            }
        }
    } else if (count == 4) {
        for (int i = 0; i < SIZE && !found; i++) {
            for (int j = 0; j <= SIZE - 4; j++) {
                if (isAvailable(i, j) && isAvailable(i, j + 1) &&
                    isAvailable(i, j + 2) && isAvailable(i, j + 3)) {
                    for (int k = 0; k < 4; k++)
                        seats[i][j + k] = 2;
                    found = 1;
                    break;
                }
            }
        }

        if (!found) {
            for (int i = 0; i < SIZE - 1 && !found; i++) {
                for (int j = 0; j < SIZE - 1; j++) {
                    if (isAvailable(i, j) && isAvailable(i, j + 1) &&
                        isAvailable(i + 1, j) && isAvailable(i + 1, j + 1)) {
                        seats[i][j] = seats[i][j + 1] = 2;
                        seats[i + 1][j] = seats[i + 1][j + 1] = 2;
                        found = 1;
                        break;
                    }
                }
            }
        }
    }

    showSeats();
    printf("Are you satisfied with these seats? (y/n): ");
    char ans;
    scanf(" %c", &ans);
    if (ans == 'y' || ans == 'Y') {
        for (int i = 0; i < SIZE; i++)
            for (int j = 0; j < SIZE; j++)
                if (seats[i][j] == 2)
                    seats[i][j] = 1;
    }
}
//使用者自行輸入座位
void chooseSeatsManually() {
    int n, r, c;
    char input[10];

    clearSuggestions();
    printf("How many seats do you want to choose (1~4)? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        while (1) {
            printf("Enter seat (e.g., 3-5): ");
            scanf("%s", input);
            if (sscanf(input, "%d-%d", &r, &c) != 2 || r < 1 || r > 9 || c < 1 || c > 9) {
                printf("Invalid format!\n");
                continue;
            }
            r--; c--;
            if (seats[r][c] != 0) {
                printf("Seat already taken!\n");
                continue;
            }
            seats[r][c] = 2;
            break;
        }
    }

    showSeats();
    printf("Press any key to confirm your selection...\n");
    getchar(); getchar(); // 模擬 getch() 效果
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (seats[i][j] == 2)
                seats[i][j] = 1;
}

