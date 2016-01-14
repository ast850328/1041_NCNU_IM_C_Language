#include<stdio.h>
//算有幾個5
int get(int input) {
    int count = 0;
    while(input != 0) {
        if(input%10 == 5)
            count++;
        input /= 10;
    }
    return count;
}
//是否含有5
int isWant(int input){
    if(get(input) > 0)
        return 1;
    else return 2;
}
int main() {
    //allcount為總共有多少5,count為有多少含5的數
    int allcount = 0, i, input, count = 0;
    scanf("%d", &input);
    for(i = 1; i <= input; i++) {
        allcount = allcount + get(i);
        //i有含5就print出來 並將count加一
        if(isWant(i) == 1) {
            printf("%d ", i);
            count++;
        }
    }
    printf("\n共有%d個數 包含%d個5", count, allcount);
}
