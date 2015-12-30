#include <stdio.h>

int reverse(int key, int num) {
    int r_num = 0, cipher_num;
    while ( num != 0){
        key = ((num % 10) + key ) % 10;
        r_num =  r_num * 10 + key;
        num = num /10;
    }
    return r_num;
}

int main()
{
    int num, key;
    scanf("%d %d", &key, &num);
    printf("%d\n",reverse(key, num));
    return 0;
}
