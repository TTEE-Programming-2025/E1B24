#include <stdio.h>
#include <stdlib.h>
#include <conio.h>  // �� getch() �Ȱ���
#define PASSWORD 2025

//��� 
void showMenu() {
    printf("--------------------------\n");
    printf("| a. �e�X�����T����       |\n");
    printf("| b. ��ܭ��k��           |\n");
    printf("| c. ����                 |\n");
    printf("--------------------------\n");
    printf("�п�� a, b, �� c: ");
}

//�����T���� 
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
            getch();  // ���ݨϥΪ̫����N��
            system("cls");
            break;
        } else {
            printf("��J���~! �Э��s��J (a~n)\n");
        }
    } while (1);
}
int main() {
    int inputPassword;
    int attempt = 0;

    system("cls");  // �M���ù��A���b�@�I

    // ����w��e��
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

    // ���\�n�J����ܥD���
    system("cls");
    showMenu();

    return 0;
}
