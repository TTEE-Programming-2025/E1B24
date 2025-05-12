#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define PASSWORD 2025
#define SIZE 9

int seats[SIZE][SIZE] = {0}; // 0: free space, 1: booked(*), 2: suggest(@)

// password
int checkPassword() {
    int input, tries = 0;

    printf("************************************\n");
    printf("*     Welcome to the Booking!      *\n");
    printf("*         Designed by E1B24          *\n");
    printf("*      THe  Seat System     *\n");
    printf("************************************\n");

    while (tries < 3) {
        printf("Please enter 4-digit password: ");
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

// menu
void printMenu() {
    printf("----------[Booking System]----------\n");
    printf("| a. Available seats               |\n");
    printf("| b. Arrange for you               |\n");
    printf("| c. Choose by yourself            |\n");
    printf("| d. Exit                          |\n");
    printf("------------------------------------\n");
    printf("Choose an option: ");
}

// random seat
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

// clear Suggestions seat
void clearSuggestions() {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (seats[i][j] == 2)
                seats[i][j] = 0;
}

// check the seat is avaliable or not
int isAvailable(int r, int c) {
    return r >= 0 && r < SIZE && c >= 0 && c < SIZE && seats[r][c] == 0;
}

// random to set the seat
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

// user input mainly
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
    printf("Press Enter to confirm your selection...");
    getchar(); getchar(); // wait for Enter
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (seats[i][j] == 2)
                seats[i][j] = 1;
}

// continue or not
int askContinue() {
    char ch;
    printf("Continue? (y/n): ");
    scanf(" %c", &ch);
    if (ch == 'y' || ch == 'Y')
        return 1;
    else if (ch == 'n' || ch == 'N') {
        printf("Goodbye!\n");
        return 0;
    } else {
        printf("Invalid input. Try again.\n");
        return askContinue();
    }
}

// main
int main() {
    char option;

    if (!checkPassword())
        return 0;

    randomBookedSeats(10);

    while (1) {
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
        printMenu();
        scanf(" %c", &option);
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif

        switch (option) {
            case 'a':
                showSeats();
                printf("Press Enter to go back to menu...");
                getchar(); getchar();
                break;
            case 'b': {
                int n;
                printf("How many seats (1~4)? ");
                scanf("%d", &n);
                suggestSeats(n);
                break;
            }
            case 'c':
                chooseSeatsManually();
                break;
            case 'd':
                if (!askContinue()) return 0;
                break;
            default:
                printf("Invalid option.\n");
                break;
        }
    }
    return 0;
}
//�o�����q��t�αM�����ڧ�[���x�F C �y�����򥻵��c�P�޿豱��
//�Ҧp����P�_�B�j��B�}�C���ϥΥH�Φp��]�p²�檺�ϥΪ̤���
//�z�L�@�B�@�B��@�\��]���O�K�X�n�J�B�D���B�y��Ƶ{�P��ܡ^
//�ھǷ|�F,�p���@�ӽ������\���Ѧ��h��²�檺�B�J�ӧ���
//���~�A�ڤ]�ǲߨ��H���ơB�r���B�z�P��J�ˬd
//���M�L�{�����@�ǿ��~�P�D�ԡA���z�L�����P���д��աA�ڧ�M���ۤv��y�k���x���{�סA�]���ɤF�ѨM���D����O�C
