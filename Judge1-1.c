#include <stdio.h>
//印出指定數量的某字元
void print(int n, char c){
    int i;
    for(i = 1; i <= n; i++)
        printf("%c",c);
}
int main(){
    int n, i;
    scanf("%d",&n);
    //印出上半段的圖形
    for(i = 1;i <= n; i++){
        //印出魚的身體
        print( (n-i) * 3, ' ');
        print( i * 3 + 3 * (i-1), '*');
        //印出魚的尾巴
        print( (n-i) * 3 + (n-i), ' ');
        print( i-1, '*');
        printf("\n");
    }
    //印出下半段的圖形
    for(i = n-1 ;i >= 1; i--){
        //印出魚的身體
        print( (n-i) * 3, ' ');
        print( i*3 + 3 * (i-1), '*');
        //印出魚的圖形
        print( (n-i) * 3 + (n-i), ' ');
        print( i-1, '*');
        printf("\n");
    }
}
