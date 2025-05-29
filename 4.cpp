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
// 顯示主選單
void displayMainMenu() {
    clearScreen();
    printf("\n------------[Grade System]----------\n");
    printf("| a. Enter student grades          |\n");
    printf("| b. Display student grades        |\n");
    printf("| c. Search for student grades     |\n");
    printf("| d. Grade ranking                |\n");
    printf("| e. Exit system                   |\n");
    printf("------------------------------------\n");
    
    printf("請選擇要使用的功能 (a-e): ");
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
            printf("無效的選擇，請重新輸入！\n");
            printf("按下任意鍵繼續...");
            getch();
            break;
    }
}
// 輸入學生成績
void enterGrades() {
    clearScreen();
    printf("\n--- 輸入學生成績 ---\n");
    
    int n;
    while (1) {
        printf("請輸入學生人數 (5-10): ");
        if (scanf("%d", &n) != 1) {
            printf("輸入錯誤，請輸入數字！\n");
            while (getchar() != '\n');
            continue;
        }
        
        if (n < 5 || n > 10) {
            printf("人數必須在5到10之間！\n");
        } else {
            break;
        }
    }
    
    studentCount = n;
    
    for (int i = 0; i < n; i++) {
        printf("\n學生 #%d:\n", i + 1);
        
        // 輸入姓名
        printf("姓名: ");
        scanf("%s", students[i].name);
        
        // 輸入學號
        while (1) {
            printf("學號 (6位數字): ");
            if (scanf("%d", &students[i].id) != 1) {
                printf("輸入錯誤，請輸入數字！\n");
                while (getchar() != '\n');
                continue;
            }
            
            if (students[i].id < 100000 || students[i].id > 999999) {
                printf("學號必須是6位數字！\n");
            } else {
                break;
            }
        }
        
        // 輸入數學成績
        while (1) {
            printf("數學成績 (0-100): ");
            if (scanf("%d", &students[i].math) != 1) {
                printf("輸入錯誤，請輸入數字！\n");
                while (getchar() != '\n');
                continue;
            }
            
            if (students[i].math < 0 || students[i].math > 100) {
                printf("成績必須在0到100之間！\n");
            } else {
                break;
            }
        }
        
        // 輸入物理成績
        while (1) {
            printf("物理成績 (0-100): ");
            if (scanf("%d", &students[i].physics) != 1) {
                printf("輸入錯誤，請輸入數字！\n");
                while (getchar() != '\n');
                continue;
            }
            
            if (students[i].physics < 0 || students[i].physics > 100) {
                printf("成績必須在0到100之間！\n");
            } else {
                break;
            }
        }
        
        // 輸入英文成績
        while (1) {
            printf("英文成績 (0-100): ");
            if (scanf("%d", &students[i].english) != 1) {
                printf("輸入錯誤，請輸入數字！\n");
                while (getchar() != '\n');
                continue;
            }
            
            if (students[i].english < 0 || students[i].english > 100) {
                printf("成績必須在0到100之間！\n");
            } else {
                break;
            }
        }
        
        // 計算平均成績
        students[i].average = (students[i].math + students[i].physics + students[i].english) / 3.0f;
    }
    
    printf("\n所有學生成績輸入完成！\n");
    printf("按下任意鍵返回主選單...");
    getch();
}

// 顯示所有學生成績
void displayAllGrades() {
    clearScreen();
    printf("\n--- 所有學生成績 ---\n");
    printf("------------------------------------------------------------\n");
    printf("姓名\t\t學號\t\t數學\t物理\t英文\t平均\n");
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
    
    printf("\n按下任意鍵返回主選單...");
    getch();
}
// 搜尋學生
void searchStudent() {
    clearScreen();
    printf("\n--- 搜尋學生成績 ---\n");
    
    char searchName[50];
    printf("請輸入要搜尋的學生姓名: ");
    scanf("%s", searchName);
    
    bool found = false;
    
    for (int i = 0; i < studentCount; i++) {
        if (strcmp(students[i].name, searchName) == 0) {
            printf("\n找到學生記錄:\n");
            printf("------------------------------------------------------------\n");
            printf("姓名\t\t學號\t\t數學\t物理\t英文\t平均\n");
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
        printf("\n找不到姓名為 \"%s\" 的學生記錄。\n", searchName);
    }
    
    printf("\n按下任意鍵返回主選單...");
    getch();
}

// 顯示成績排名
void displayRanking() {
    clearScreen();
    printf("\n--- 學生成績排名 ---\n");
    
    // 建立排名陣列
    int ranking[MAX_STUDENTS];
    for (int i = 0; i < studentCount; i++) {
        ranking[i] = i;
    }
       // 使用冒泡排序按平均成績排序
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
    printf("排名\t姓名\t\t學號\t\t平均\n");
    printf("----------------------------------------\n");
    
    for (int i = 0; i < studentCount; i++) {
        printf("%d\t%-10s\t%d\t\t%.1f\n", 
               i + 1, 
               students[ranking[i]].name, 
               students[ranking[i]].id, 
               students[ranking[i]].average);
    }
    
    printf("\n按下任意鍵返回主選單...");
    getch();
}

// 退出系統
void exitSystem() {
    char confirm;
    
    while (1) {
        clearScreen();
        printf("\n確定離開？ (y/n): ");
        scanf(" %c", &confirm);
        
        if (tolower(confirm) == 'y') {
            printf("\n感謝使用學生成績管理系統，再見！\n");
            exit(0);
        } else if (tolower(confirm) == 'n') {
            return; // 返回主選單
        } else {
            printf("無效的輸入，請輸入 'y' 或 'n'。\n");
            printf("按下任意鍵繼續...");
            getch();
        }
    }
}
//這次的作業為設計成績系統，然後後段有寫到排名陣列的建立
//其中對我來說最有趣的是冒泡排序，因為之前沒有使用過
//而是在這次寫作業時，去找了要怎麼完成排名的陣列時找到的
//就想說那就試試看，發現還挺有趣的。 
