#include<stdio.h>
#include<stdlib.h>
#include<time.h>
/*排列*/
void sort(int * data,int * record,int len) {
    int i,j,tmp,tmpr;
    for (i = 1;i < len;i++) {
        tmp = data[i]; // tmp 是要insert的元素的值
        tmpr = record[i];//第幾個player也要一起排
        j = i - 1; // j是要比較的元素
        while (j >= 0 && data[j] < tmp) {
            data[j+1] = data[j];
            record[j+1] = record[j];
            j = j - 1;
        }
        data[j+1] = tmp;
        record[j+1] = tmpr;
    }
}
int main(){
    int i,j,c1,c2,tmp;
    int rank = 1;
    int record[4];
    int card[52];//設定一副牌
    char color[] = {'S','H','D','C'};//花色
    char number[] = {'A','2','3','4','5','6','7','8','9','T','J','Q','K'};//號碼
    int player[4];
    /*洗牌*/
    for(i=0;i<52;i++){
        card[i]=i;
    }
    srand(time(NULL));
    for(i=0;i<1000;i++){
        c1 = rand()%52;
        c2 = rand()%52;
        tmp = card[c1];
        card[c1] = card[c2];
        card[c2] = tmp;
    }
    /*發牌*/
    for(i=0;i<4;i++){//初始化,一開始各player手上牌的總和為零
        player[i] = 0;
        record[i] = i+1;
    }
    for(j=0;j<2;j++){//算總和
        for(i=0;i<4;i++){
            player[i] = player[i]+(card[i+(j*(j+3))]%13+1);
        }
    }
    for(i=0;i<4;i++){//印出結果
        printf("player %d\n",i+1);//player從一開始
        printf("sum is %d ",player[i]);
        for(j=0;j<2;j++){
            //    花色為點數/13, 點數為取13餘數(1~12)+1
            printf("%c%c ",color[card[i+(j*(j+3))] / 13],number[card[i+(j*(j+3))] % 13]);
        }
        printf("\n");
    }
    printf("\n");
    sort(player,record,4);
    for(i=0;i<4;i++){//印出結果
        if(player[i]<22){
            printf("player %d ",record[i]);
            if(i==4){//第四個後面沒人所以不用比直接印
                printf("rank %d\n",rank);
            }else if(player[i]>player[i+1]){//判斷名次，相同分數則同名
                printf("rank %d\n",rank);
                rank++;
            }else{
                printf("rank %d\n",rank);
            }
        }
    }
    for(i=0;i<4;i++){//輸家最後印
        if(player[i]>22){
            printf("player %d ",record[i]);
            printf(" loser\n");
        }
    }
}