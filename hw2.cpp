#include <stdio.h>
#include <stdlib.h>
#include <conio.h>  // �ϥ� getch()

#define PASSWORD 2025

void showMenu() {
    printf("--------------------------\n");
    printf("| a. �e�X�����T����       |\n");
    printf("| b. ��ܭ��k��           |\n");
    printf("| c. ����                 |\n");
    printf("--------------------------\n");
    printf("�п�� a, b, �� c: ");
}

void drawTriangle() {
    char ch;
    system("cls");

    do {
        printf("�п�J�@�Ӧr�� (a~n): ");
        scanf(" %c", &ch);

        if (ch >= 'a' && ch <= 'n') {
            int height = ch - 'a' + 1;
            for (int i = 1; i <= height; i++) {
                for (int j = 1; j <= i; j++) {
                    printf("%c ", ch);
                }
                printf("\n");
            }
            printf("�����N���^�D���...");
            getch();
            system("cls");
            break;
        } else {
            printf("��J���~! �Э��s��J (a~n)\n");
        }
    } while (1);
}

void multiplicationTable() {
    int n;
    system("cls");

    do {
        printf("�п�J�@�Ӿ��(1~9): ");
        scanf("%d", &n);

        if (n >= 1 && n <= 9) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    printf("%2d x %2d = %2d  ", i, j, i * j);
                }
                printf("\n");
            }
            printf("�����N���^�D���...");
            getch();
            system("cls");
            break;
        } else {
            printf("��J���~! �Э��s��J 1~9 ���Ʀr�C\n");
        }
    } while (1);
}

int main() {
    int inputPassword;
    int attempt = 0;
    char choice;
    char confirm;

    system("cls");

    // �n�J�e��
    printf("****************************************\n");
    printf("*           Welcome to My App          *\n");
    printf("*           �w�]�K�X: %d               *\n", PASSWORD);
    printf("****************************************\n");

    // �K�X����
    while (attempt < 3) {
        printf("�п�J4��ƱK�X: ");
        scanf("%d", &inputPassword);

        if (inputPassword == PASSWORD) {
            printf("�K�X���T�I\n");
            break;
        } else {
            printf("�K�X���~�I\n");
            attempt++;
        }
    }

    if (attempt == 3) {
        printf("���~�W�L�T���A�t����w�I\n");
        return 0;
    }

    // �n�J���\��i�J�D���
    do {
        system("cls");
        showMenu();
        scanf(" %c", &choice);

        switch (choice) {
            case 'a':
            case 'A':
                drawTriangle();
                break;
            case 'b':
            case 'B':
                multiplicationTable();
                break;
            case 'c':
            case 'C':
                do {
                    printf("Continue? (y/n): ");
                    scanf(" %c", &confirm);

                    if (confirm == 'y' || confirm == 'Y') {
                        break;  // �^�D���
                    } else if (confirm == 'n' || confirm == 'N') {
                        printf("�{�������A�T�T�I\n");
                        return 0;  // �{������
                    } else {
                        printf("��J���~�A�п�J y �� n�C\n");
                    }
                } while (1);
                break;
            default:
                printf("�ﶵ���~�I�Э��s��J�C\n");
                getch(); // �����N���~��
                break;
        }
    } while (1);

    return 0;
}

