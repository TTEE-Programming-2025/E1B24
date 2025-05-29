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
// ��ܥD���
void displayMainMenu() {
    clearScreen();
    printf("\n------------[Grade System]----------\n");
    printf("| a. Enter student grades          |\n");
    printf("| b. Display student grades        |\n");
    printf("| c. Search for student grades     |\n");
    printf("| d. Grade ranking                |\n");
    printf("| e. Exit system                   |\n");
    printf("------------------------------------\n");
    
    printf("�п�ܭn�ϥΪ��\�� (a-e): ");
    char choice;
    scanf(" %c", &choice);
    
    switch (tolower(choice)) {
        case 'a':
            enterGrades();
            break;
        case 'b':
            displayAllGrades();
            break;
        case 'c':
            searchStudent();
            break;
        case 'd':
            displayRanking();
            break;
        case 'e':
            exitSystem();
            break;
        default:
            printf("�L�Ī���ܡA�Э��s��J�I\n");
            printf("���U���N���~��...");
            getch();
            break;
    }
}
// ��J�ǥͦ��Z
void enterGrades() {
    clearScreen();
    printf("\n--- ��J�ǥͦ��Z ---\n");
    
    int n;
    while (1) {
        printf("�п�J�ǥͤH�� (5-10): ");
        if (scanf("%d", &n) != 1) {
            printf("��J���~�A�п�J�Ʀr�I\n");
            while (getchar() != '\n');
            continue;
        }
        
        if (n < 5 || n > 10) {
            printf("�H�ƥ����b5��10�����I\n");
        } else {
            break;
        }
    }
    
    studentCount = n;
    
    for (int i = 0; i < n; i++) {
        printf("\n�ǥ� #%d:\n", i + 1);
        
        // ��J�m�W
        printf("�m�W: ");
        scanf("%s", students[i].name);
        
        // ��J�Ǹ�
        while (1) {
            printf("�Ǹ� (6��Ʀr): ");
            if (scanf("%d", &students[i].id) != 1) {
                printf("��J���~�A�п�J�Ʀr�I\n");
                while (getchar() != '\n');
                continue;
            }
            
            if (students[i].id < 100000 || students[i].id > 999999) {
                printf("�Ǹ������O6��Ʀr�I\n");
            } else {
                break;
            }
        }
        
        // ��J�ƾǦ��Z
        while (1) {
            printf("�ƾǦ��Z (0-100): ");
            if (scanf("%d", &students[i].math) != 1) {
                printf("��J���~�A�п�J�Ʀr�I\n");
                while (getchar() != '\n');
                continue;
            }
            
            if (students[i].math < 0 || students[i].math > 100) {
                printf("���Z�����b0��100�����I\n");
            } else {
                break;
            }
        }
        
        // ��J���z���Z
        while (1) {
            printf("���z���Z (0-100): ");
            if (scanf("%d", &students[i].physics) != 1) {
                printf("��J���~�A�п�J�Ʀr�I\n");
                while (getchar() != '\n');
                continue;
            }
            
            if (students[i].physics < 0 || students[i].physics > 100) {
                printf("���Z�����b0��100�����I\n");
            } else {
                break;
            }
        }
        
        // ��J�^�妨�Z
        while (1) {
            printf("�^�妨�Z (0-100): ");
            if (scanf("%d", &students[i].english) != 1) {
                printf("��J���~�A�п�J�Ʀr�I\n");
                while (getchar() != '\n');
                continue;
            }
            
            if (students[i].english < 0 || students[i].english > 100) {
                printf("���Z�����b0��100�����I\n");
            } else {
                break;
            }
        }
        
        // �p�⥭�����Z
        students[i].average = (students[i].math + students[i].physics + students[i].english) / 3.0f;
    }
    
    printf("\n�Ҧ��ǥͦ��Z��J�����I\n");
    printf("���U���N���^�D���...");
    getch();
}

// ��ܩҦ��ǥͦ��Z
void displayAllGrades() {
    clearScreen();
    printf("\n--- �Ҧ��ǥͦ��Z ---\n");
    printf("------------------------------------------------------------\n");
    printf("�m�W\t\t�Ǹ�\t\t�ƾ�\t���z\t�^��\t����\n");
    printf("------------------------------------------------------------\n");
    
    for (int i = 0; i < studentCount; i++) {
        printf("%-10s\t%d\t%d\t%d\t%d\t%.1f\n", 
               students[i].name, 
               students[i].id, 
               students[i].math, 
               students[i].physics, 
               students[i].english, 
               students[i].average);
    }
    
    printf("\n���U���N���^�D���...");
    getch();
}
// �j�M�ǥ�
void searchStudent() {
    clearScreen();
    printf("\n--- �j�M�ǥͦ��Z ---\n");
    
    char searchName[50];
    printf("�п�J�n�j�M���ǥͩm�W: ");
    scanf("%s", searchName);
    
    bool found = false;
    
    for (int i = 0; i < studentCount; i++) {
        if (strcmp(students[i].name, searchName) == 0) {
            printf("\n���ǥͰO��:\n");
            printf("------------------------------------------------------------\n");
            printf("�m�W\t\t�Ǹ�\t\t�ƾ�\t���z\t�^��\t����\n");
            printf("------------------------------------------------------------\n");
            printf("%-10s\t%d\t%d\t%d\t%d\t%.1f\n", 
                   students[i].name, 
                   students[i].id, 
                   students[i].math, 
                   students[i].physics, 
                   students[i].english, 
                   students[i].average);
            found = true;
            break;
        }
    }
    
    if (!found) {
        printf("\n�䤣��m�W�� \"%s\" ���ǥͰO���C\n", searchName);
    }
    
    printf("\n���U���N���^�D���...");
    getch();
}

// ��ܦ��Z�ƦW
void displayRanking() {
    clearScreen();
    printf("\n--- �ǥͦ��Z�ƦW ---\n");
    
    // �إ߱ƦW�}�C
    int ranking[MAX_STUDENTS];
    for (int i = 0; i < studentCount; i++) {
        ranking[i] = i;
    }
       // �ϥΫ_�w�Ƨǫ��������Z�Ƨ�
    for (int i = 0; i < studentCount - 1; i++) {
        for (int j = 0; j < studentCount - i - 1; j++) {
            if (students[ranking[j]].average < students[ranking[j + 1]].average) {
                int temp = ranking[j];
                ranking[j] = ranking[j + 1];
                ranking[j + 1] = temp;
            }
        }
    }
    
    printf("----------------------------------------\n");
    printf("�ƦW\t�m�W\t\t�Ǹ�\t\t����\n");
    printf("----------------------------------------\n");
    
    for (int i = 0; i < studentCount; i++) {
        printf("%d\t%-10s\t%d\t\t%.1f\n", 
               i + 1, 
               students[ranking[i]].name, 
               students[ranking[i]].id, 
               students[ranking[i]].average);
    }
    
    printf("\n���U���N���^�D���...");
    getch();
}

// �h�X�t��
void exitSystem() {
    char confirm;
    
    while (1) {
        clearScreen();
        printf("\n�T�w���}�H (y/n): ");
        scanf(" %c", &confirm);
        
        if (tolower(confirm) == 'y') {
            printf("\n�P�¨ϥξǥͦ��Z�޲z�t�ΡA�A���I\n");
            exit(0);
        } else if (tolower(confirm) == 'n') {
            return; // ��^�D���
        } else {
            printf("�L�Ī���J�A�п�J 'y' �� 'n'�C\n");
            printf("���U���N���~��...");
            getch();
        }
    }
}
//�o�����@�~���]�p���Z�t�ΡA�M���q���g��ƦW�}�C���إ�
//�䤤��ڨӻ��̦��쪺�O�_�w�ƧǡA�]�����e�S���ϥιL
//�ӬO�b�o���g�@�~�ɡA�h��F�n��򧹦��ƦW���}�C�ɧ�쪺
//�N�Q�����N�ոլݡA�o�{�ٮ����쪺�C 
