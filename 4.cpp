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
// 顯示歡迎畫面
void displayWelcomeScreen() {
    clearScreen();
    printf("\n\n");
    printf("    ***************************************\n");
    printf("    *                                     *\n");
    printf("    *      歡迎使用學生成績管理系統      *\n");
    printf("    *                                     *\n");
    printf("    *                                     *\n");
    printf("    *  設計者:  E1B24                *\n");
    printf("    *  版本: 1.0                        *\n");
    printf("    *  日期: 2025                       *\n");
    printf("    *                                     *\n");
    printf("    ***************************************\n");
    printf("\n\n");
}
// 檢查密碼
bool checkPassword() {
    int attempts = 0;
    int password;
    const int correctPassword = 2025;
    
    displayWelcomeScreen();
    
    while (attempts < 3) {
        printf("請輸入4位數密碼: ");
        if (scanf("%d", &password) != 1) {
            printf("輸入錯誤，請輸入數字！\n");
            while (getchar() != '\n'); // 清除輸入緩衝區
            attempts++;
            continue;
        }
        
        if (password == correctPassword) {
            printf("\n密碼正確，歡迎使用本系統！\n");
            printf("按下任意鍵繼續...");
            getch();
            return true;
        } else {
            attempts++;
            printf("密碼錯誤，還剩 %d 次嘗試機會\n", 3 - attempts);
        }
    }
    
    printf("\n警告！您已連續三次輸入錯誤密碼，系統將關閉！\n");
    return false;
}

// 清除螢幕
void clearScreen() {
    system("cls || clear");
}
