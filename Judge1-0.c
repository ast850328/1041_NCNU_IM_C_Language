#include<stdio.h>
#include<stdlib.h>
#include <time.h>
//1為喜歡 判斷是否為喜歡哈密瓜的人 如果是就+1最後回傳 
int yes(int a[]){
    int i,sol = 0;
    for(i = 0; i < 5000; i++){
        if(a[i] == 1)
            sol++;
    }
    return sol;
}
//由第一千位路人開始計算，每一千位挑出來檢查是不是1 是1的話代表喜歡 需要送出的禮物就+1最後回傳 
int gift(int a[]){
    int i,sol = 0;
    for(i = 999; i < 5000; i += 1000){
        if(a[i] == 1)
            sol++;
    }
    return sol;
}
int main(){ 
    srand(time(NULL)); 
    //放路人結果用的陣列 
    int a[5000];
    int i;
    //隨機訪問路人的結果 
    for(i = 0; i < 5000; i++){
        a[i]=(rand() % 2) + 1;
    }
    printf("有%d個人喜歡\n", yes(a));
    //5000-喜歡的就是不喜歡的人數 
    printf("有%d個人不喜歡\n", 5000-yes(a));
    printf("送出%d份禮物", gift(a));
    return 0;
}
