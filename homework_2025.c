#include <stdio.h>
#include <stdlib.h>

// �M����J�w�İ�
void clearInputBuffer() {
    while (getchar() != '\n');
}

int main() {
    char name[] = "�L���N";  
    char id[] = "E1B24"; 
    int passw;
    char inputChar;

    
    //1 �ӤH���D
    printf("hihihihihihihhihihihihihihihihihihihihihihihi\n");
    printf("hi                                          hi\n");
    printf("hi                                          hi\n");
    printf("hi            �w��Ө�L���N���@�~          hi\n");
    printf("hi                                          hi\n");
    printf("hi                                          hi\n");
    printf("hihihihihihihiiiihihihihihihihihihihihihihihi\n");
    printf("\n");
    printf("  name : %s\n", name);
    printf("  id : %s\n", id);
    printf("\n");
    printf("welcome to my c world\n");
    printf("�o�O�@�ӹ�C�y�������@�ӽm��\n");
    printf("�ھڤU�C�B�J�}�l�a!!!!!!!!\n");
    printf("---------------------------------------------\n");
    printf("\n");
    printf("�B�J:\n");
    printf("1. �п�J�|��K�X�H�~��U�@�B!\n");
    printf("2. ��J�@�r���ìd�ݺ���.\n");
    printf("3. ���U�������H�~��...\n");
    printf("\n");
    printf("---------------------------------------------\n");

   
    
    system("pause");  
    system("cls");   


   //2 �n�D�ϥΪ̿�J 4 �ӼƦr���K�X
    while (1) {
        printf("��J�|��K�X: ");
        scanf("%d", &passw);
        clearInputBuffer(); //�M����J�w�İ� 

        if (passw == 2024) {
            printf("�K�X���T!\n");
            break;
        } else {
            printf("�K�X���~,�Э��s��J\n");
        }
    }

    system("pause");
    system("cls");//�M���ù� 

    //3
    while (1) {
        printf("----------------------------------\n");
        printf("  'A' ~ 'Z' : Uppercase\n");
        printf("  'a' ~ 'z' : Lowercase\n");
        printf("  '0' ~ '9' : Digit\n");
        printf("  Otherwise : Your name\n");
        printf("----------------------------------\n");
        printf("��J�r��: ");

        scanf(" %c", &inputChar);
        clearInputBuffer();  // �M����J�w�İ�

    // 4
        if (inputChar >= 'A' && inputChar <= 'Z') {
            printf("Uppercase\n");//�Y��J���r���OA��Z�����h��Xuppercase 
        } else if (inputChar >= 'a' && inputChar <= 'z') {
            printf("Lowercase\n");//�Y��J���r���Oa��z�����h��Xlowercase 
        } else if (inputChar >= '0' && inputChar <= '9') {
            printf("Digit\n");//�Y��J���r���O0��9���Ʀr�h��Xdigit
        } else {
            printf("name: %s\n", name);
            printf("id: %s\n",id);
        break;
        }

        printf("���U������H�~��...");
        system("pause");
        system("cls");
    }

    return 0;
}
//�o���O�Ĥ@����C�y���h���@�Ӧ��s�e�ʪ��{���A�C�@�Ӥ������s���g��while�Ӱ����I�A�Ӧb�g�o�ӧ@�~���e�A�]�wgit�Pgithub�����ҳ]�w�N�ӶO�F���֮ɶ��Ʀ̫ܳ��ٳ·ФF�U�������C
//�b�}�l�g������D�N�b�n���˥h�e�{�X�s�e�ʡA�o�Ӯɭԫ�ҬO�n�έn��while�٬Oif�Ӽg�A�̫���while�A���M����T�w�ۤv�g���O��²��̰��b���C
//���O�ܤ֧ڦb�g���L�{���q�H�e�W�Ҫ���ƥh�M���ھ��D�N�ҭn���F��A�b�̫�]�����X���D�حn�D�����G�A����ڴN��O��o�@�ӳ����S����h�@�Ǫ��{�ѡC 
