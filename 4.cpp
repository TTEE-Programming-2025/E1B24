#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <stdbool.h>

#define MAX_STUDENTS 10

// �ǥ�
typedef struct {
    char name[50];
    int id;
    int math;
    int physics;
    int english;
    float average;
} Student;

Student students[MAX_STUDENTS];
int studentCount = 0;

// �禡�ŧi
void displayWelcomeScreen();
bool checkPassword();
void clearScreen();
void displayMainMenu();
void enterGrades();
void displayAllGrades();
void searchStudent();
void displayRanking();
void exitSystem();

int main() {
    // �Ĥ@�B�G�K�X����
    if (!checkPassword()) {
        return 0;
    }
    
    // �D���`��
    while (1) {
        displayMainMenu();
    }
    
    return 0;
}
// ����w��e��
void displayWelcomeScreen() {
    clearScreen();
    printf("\n\n");
    printf("    ***************************************\n");
    printf("    *                                     *\n");
    printf("    *      �w��ϥξǥͦ��Z�޲z�t��      *\n");
    printf("    *                                     *\n");
    printf("    *                                     *\n");
    printf("    *  �]�p��:  E1B24                *\n");
    printf("    *  ����: 1.0                        *\n");
    printf("    *  ���: 2025                       *\n");
    printf("    *                                     *\n");
    printf("    ***************************************\n");
    printf("\n\n");
}
// �ˬd�K�X
bool checkPassword() {
    int attempts = 0;
    int password;
    const int correctPassword = 2025;
    
    displayWelcomeScreen();
    
    while (attempts < 3) {
        printf("�п�J4��ƱK�X: ");
        if (scanf("%d", &password) != 1) {
            printf("��J���~�A�п�J�Ʀr�I\n");
            while (getchar() != '\n'); // �M����J�w�İ�
            attempts++;
            continue;
        }
        
        if (password == correctPassword) {
            printf("\n�K�X���T�A�w��ϥΥ��t�ΡI\n");
            printf("���U���N���~��...");
            getch();
            return true;
        } else {
            attempts++;
            printf("�K�X���~�A�ٳ� %d �����վ��|\n", 3 - attempts);
        }
    }
    
    printf("\nĵ�i�I�z�w�s��T����J���~�K�X�A�t�αN�����I\n");
    return false;
}

// �M���ù�
void clearScreen() {
    system("cls || clear");
}
