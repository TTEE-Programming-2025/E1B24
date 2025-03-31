#include <stdio.h>
#include <stdlib.h>

// 清除輸入緩衝區
void clearInputBuffer() {
    while (getchar() != '\n');
}

int main() {
    char name[] = "林順杰";  
    char id[] = "E1B24"; 
    int passw;
    char inputChar;

    
    //1 個人標題
    printf("hihihihihihihhihihihihihihihihihihihihihihihi\n");
    printf("hi                                          hi\n");
    printf("hi                                          hi\n");
    printf("hi            歡迎來到林順杰的作業          hi\n");
    printf("hi                                          hi\n");
    printf("hi                                          hi\n");
    printf("hihihihihihihiiiihihihihihihihihihihihihihihi\n");
    printf("\n");
    printf("  name : %s\n", name);
    printf("  id : %s\n", id);
    printf("\n");
    printf("welcome to my c world\n");
    printf("這是一個對C語言做的一個練習\n");
    printf("根據下列步驟開始吧!!!!!!!!\n");
    printf("---------------------------------------------\n");
    printf("\n");
    printf("步驟:\n");
    printf("1. 請輸入四位密碼以繼續下一步!\n");
    printf("2. 輸入一字元並查看種類.\n");
    printf("3. 按下任何按鍵以繼續...\n");
    printf("\n");
    printf("---------------------------------------------\n");

   
    
    system("pause");  
    system("cls");   


   //2 要求使用者輸入 4 個數字的密碼
    while (1) {
        printf("輸入四位密碼: ");
        scanf("%d", &passw);
        clearInputBuffer(); //清除輸入緩衝區 

        if (passw == 2024) {
            printf("密碼正確!\n");
            break;
        } else {
            printf("密碼錯誤,請重新輸入\n");
        }
    }

    system("pause");
    system("cls");//清除螢幕 

    //3
    while (1) {
        printf("----------------------------------\n");
        printf("  'A' ~ 'Z' : Uppercase\n");
        printf("  'a' ~ 'z' : Lowercase\n");
        printf("  '0' ~ '9' : Digit\n");
        printf("  Otherwise : Your name\n");
        printf("----------------------------------\n");
        printf("輸入字元: ");

        scanf(" %c", &inputChar);
        clearInputBuffer();  // 清除輸入緩衝區

    // 4
        if (inputChar >= 'A' && inputChar <= 'Z') {
            printf("Uppercase\n");//若輸入的字元是A到Z之間則輸出uppercase 
        } else if (inputChar >= 'a' && inputChar <= 'z') {
            printf("Lowercase\n");//若輸入的字元是a到z之間則輸出lowercase 
        } else if (inputChar >= '0' && inputChar <= '9') {
            printf("Digit\n");//若輸入的字元是0到9的數字則輸出digit
        } else {
            printf("name: %s\n", name);
            printf("id: %s\n",id);
        break;
        }

        printf("按下任何鍵以繼續...");
        system("pause");
        system("cls");
    }

    return 0;
}
//這次是第一次用C語言去做一個有連貫性的程式，每一個之間的連接經由while來做接點，而在寫這個作業之前，設定git與github的環境設定就耗費了不少時間甚至最後還麻煩了助教幫忙。
//在開始寫之後問題就在要怎麼樣去呈現出連貫性，這個時候思考是要用要用while還是if來寫，最後選擇while，雖然不能確定自己寫的是最簡單最乾淨的。
//但是至少我在寫的過程中從以前上課的資料去尋找能根據題意所要的東西，在最後也有做出來題目要求的結果，那麼我就算是對這一個部份又有更多一些的認識。 
