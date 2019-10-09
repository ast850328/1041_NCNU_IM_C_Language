#include<stdio.h>
// 費氏數列
int f(int x) {
    int i, a, b, c;
    if (x == 1 || x == 2) {
        return 1;
    } else {
        a = 1, b = 1, c;
    }
    // 每次皆為前兩項之和
    for (i = 3; i <= x; i++) {
        c = a + b; 
        a = b;
        b = c;
    }
    return c; 
}

int main() {
    int num;
    scanf("%d", &num);
    printf("%d\n", f(num));
}
