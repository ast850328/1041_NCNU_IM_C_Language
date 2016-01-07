#include <stdio.h>

int decode(int key, int encode_num) {
    int decode_num = 0, tmp1 = -1, tmp2 = -1; 
    while ( encode_num != 0 ){
        if(tmp1 == -1){
            tmp1 = encode_num % 10; 
            encode_num = encode_num / 10; 
        }else{
            tmp2 = encode_num % 10; 
            encode_num = encode_num / 10; 
            decode_num = decode_num * 10 + (tmp1 + 10 - tmp2) % 10; 
            tmp1 = tmp2;
        }
    }   
    decode_num = decode_num * 10 + (tmp1 + 10 - key) % 10; 
    return decode_num;
}

int main()
{
    int encode_num, key;
    scanf("%d %d", &encode_num, &key);
    int decode_num = decode(key, encode_num);
    printf("%d\n", decode_num);
    return 0;
}
