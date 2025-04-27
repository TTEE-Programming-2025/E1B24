#include <stdio.h>
#include <stdlib.h>

#define PASSWORD 2025

int main() {
    int inputPassword;
    int attempt = 0;

    system("cls");  // 清除螢幕

    printf("****************************************\n");
    printf("*           Welcome to My App          *\n");
    printf("*           預設密碼: %d               *\n", PASSWORD);
    printf("****************************************\n");

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

    return 0;
}
