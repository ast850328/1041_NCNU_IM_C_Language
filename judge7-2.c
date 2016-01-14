#include <stdio.h>
//計算進位的函數
int carryCount(int a, int b){
    //tmpA, tmpB 為要做加法的兩個位置
    int tmpA, tmpB, times = 0, carry = 0;
    //中止條件為其中一方變為零
    while(a != 0 || b != 0) {
        tmpA = a % 10;
        tmpB = b % 10;
        if(tmpA + tmpB + carry >= 10) {
            carry = 1;
            times++;
        }else {
            carry = 0;
        }
        //類似reverse 的作法取下一個位置的數字
        a = a / 10;
        b = b / 10;
    }
    //若b 為零，繼續判斷a 其他位置的進位
    while (a != 0) {
        tmpA = a % 10;
        if(tmpA + carry >= 10) {
            carry = 1;
            times++;
        }else {
            carry = 0;
        }
        a = a / 10;
    }
    //反之
    while (b != 0) {
        tmpB = b % 10;
        if(tmpB + carry >= 10) {
            carry = 1;
            times++;
        }else {
            carry = 0;
        }
        b = b / 10;
    }
    return times;
}
int main() {
    int a, b, sum;
    scanf("%d %d", &a, &b);
    printf("%d %d\n", a + b, carryCount(a,b));
    return 0;
}
