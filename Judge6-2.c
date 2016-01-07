#include<stdio.h>
#include<stdlib.h>
#include<time.h>
/*�ƦC*/
void sort(int * data,int * record,int len) {
    int i,j,tmp,tmpr;
    for (i = 1;i < len;i++) {
        tmp = data[i]; // tmp �O�ninsert����������
        tmpr = record[i];//�ĴX��player�]�n�@�_��
        j = i - 1; // j�O�n���������
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
    int card[52];//�]�w�@�ƵP
    char color[] = {'S','H','D','C'};//���
    char number[] = {'A','2','3','4','5','6','7','8','9','T','J','Q','K'};//���X
    int player[4];
    /*�~�P*/
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
    /*�o�P*/
    for(i=0;i<4;i++){//��l��,�@�}�l�Uplayer��W�P���`�M���s
        player[i] = 0;
        record[i] = i+1;
    }
    for(j=0;j<2;j++){//���`�M
        for(i=0;i<4;i++){
            player[i] = player[i]+(card[i+(j*(j+3))]%13+1);
        }
    }
    for(i=0;i<4;i++){//�L�X���G
        printf("player %d\n",i+1);//player�q�@�}�l
        printf("sum is %d ",player[i]);
        for(j=0;j<2;j++){
            //    ��⬰�I��/13, �I�Ƭ���13�l��(1~12)+1
            printf("%c%c ",color[card[i+(j*(j+3))] / 13],number[card[i+(j*(j+3))] % 13]);
        }
        printf("\n");
    }
    printf("\n");
    sort(player,record,4);
    for(i=0;i<4;i++){//�L�X���G
        if(player[i]<22){
            printf("player %d ",record[i]);
            if(i==4){//�ĥ|�ӫ᭱�S�H�ҥH���Τ񪽱��L
                printf("rank %d\n",rank);
            }else if(player[i]>player[i+1]){//�P�_�W���A�ۦP���ƫh�P�W
                printf("rank %d\n",rank);
                rank++;
            }else{
                printf("rank %d\n",rank);
            }
        }
    }
    for(i=0;i<4;i++){//��a�̫�L
        if(player[i]>22){
            printf("player %d ",record[i]);
            printf(" loser\n");
        }
    }
}