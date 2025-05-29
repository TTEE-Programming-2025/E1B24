#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <stdbool.h>

#define MAX_STUDENTS 10

// 學生
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

// 函式宣告
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
    // 第一步：密碼驗證
    if (!checkPassword()) {
        return 0;
    }
    
    // 主選單循環
    while (1) {
        displayMainMenu();
    }
    
    return 0;
}
