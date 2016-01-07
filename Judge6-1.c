#include <stdio.h>
#include <stdlib.h>
//定義 true = 1, false = 0
#define true 1
#define false 0
//判斷是否為真的身份證字號
int judgeID(char *data) {
    int i=0, tmp, sum = 0;
    while(i < 10){
        //處理第一個英文字
        if(i == 0) {
            tmp = (int)data[i] - 55;
            sum += (tmp / 10) + (tmp % 10) * (9 - i);
        }
        //處理最後一碼
        else if( i == 9){
            tmp = (int)data[i] - 48;
            sum += tmp;
        }
        //依序處理其他數字
        else {
            tmp = (int)data[i] - 48;
            sum += tmp * (9 - i);
        }
        i++;
    }
    if (sum % 10 == 0)
        return true;
    return false;
}
int main() {
    char data[10];
    scanf("%s", data);
    if(judgeID(data) == true)
        printf("real.\n");
    else
        printf("fake.\n");
    return 0;
}
