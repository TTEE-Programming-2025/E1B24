#include <stdio.h>
#include <stdlib.h>
#include <conio.h>  // 用 getch() 暫停用
#define PASSWORD 2025

//選單 
void showMenu() {
    printf("--------------------------\n");
    printf("| a. 畫出直角三角形       |\n");
    printf("| b. 顯示乘法表           |\n");
    printf("| c. 結束                 |\n");
    printf("--------------------------\n");
    printf("請選擇 a, b, 或 c: ");
}

//直角三角形 
void drawTriangle() {
    char ch;
    system("cls");

    do {
        printf("請輸入一個字母 (a~n): ");
        scanf(" %c", &ch);

        if (ch >= 'a' && ch <= 'n') {
            int height = ch - 'a' + 1;
            for (int i = 1; i <= height; i++) {
                for (int j = 1; j <= i; j++) {
                    printf("%c ", ch);
                }
                printf("\n");
            }
            printf("按任意鍵返回主選單...");
            getch();  // 等待使用者按任意鍵
            system("cls");
            break;
        } else {
            printf("輸入錯誤! 請重新輸入 (a~n)\n");
        }
    } while (1);
}
int main() {
    int inputPassword;
    int attempt = 0;

    system("cls");  // 清除螢幕，乾淨一點

    // 顯示歡迎畫面
    printf("****************************************\n");
    printf("*           Welcome to My App          *\n");
    printf("*           預設密碼: %d               *\n", PASSWORD);
    printf("****************************************\n");

    // 密碼驗證
    while (attempt < 3) {
        printf("請輸入4位數密碼: ");
        scanf("%d", &inputPassword);

        if (inputPassword == PASSWORD) {
            printf("密碼正確！\n");
            break;
        } else {
            printf("密碼錯誤！\n");
            attempt++;
        }
    }

    if (attempt == 3) {
        printf("錯誤超過三次，系統鎖定！\n");
        return 0;
    }

    // 成功登入後顯示主選單
    system("cls");
    showMenu();

    return 0;
}
