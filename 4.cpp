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
