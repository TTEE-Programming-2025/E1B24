#include <stdio.h>
#include <stdlib.h>

#define PASSWORD 2025

int main() {
    int inputPassword;
    int attempt = 0;

    system("cls");  // �M���ù�

    printf("****************************************\n");
    printf("*           Welcome to My App          *\n");
    printf("*           �w�]�K�X: %d               *\n", PASSWORD);
    printf("****************************************\n");

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

    return 0;
}
