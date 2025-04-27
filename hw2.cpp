#include <stdio.h>
#include <stdlib.h>
#include <conio.h>  // 使用 getch()

#define PASSWORD 2025

void showMenu() {
    printf("--------------------------\n");
    printf("| a. 畫出直角三角形       |\n");
    printf("| b. 顯示乘法表           |\n");
    printf("| c. 結束                 |\n");
    printf("--------------------------\n");
    printf("請選擇 a, b, 或 c: ");
}

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
            getch();
            system("cls");
            break;
        } else {
            printf("輸入錯誤! 請重新輸入 (a~n)\n");
        }
    } while (1);
}

void multiplicationTable() {
    int n;
    system("cls");

    do {
        printf("請輸入一個整數(1~9): ");
        scanf("%d", &n);

        if (n >= 1 && n <= 9) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    printf("%2d x %2d = %2d  ", i, j, i * j);
                }
                printf("\n");
            }
            printf("按任意鍵返回主選單...");
            getch();
            system("cls");
            break;
        } else {
            printf("輸入錯誤! 請重新輸入 1~9 的數字。\n");
        }
    } while (1);
}

int main() {
    int inputPassword;
    int attempt = 0;
    char choice;
    char confirm;

    system("cls");

    // 登入畫面
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

    // 登入成功後進入主選單
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
                        break;  // 回主選單
                    } else if (confirm == 'n' || confirm == 'N') {
                        printf("程式結束，掰掰！\n");
                        return 0;  // 程式結束
                    } else {
                        printf("輸入錯誤，請輸入 y 或 n。\n");
                    }
                } while (1);
                break;
            default:
                printf("選項錯誤！請重新輸入。\n");
                getch(); // 按任意鍵繼續
                break;
        }
    } while (1);

    return 0;
}

