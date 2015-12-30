#include<stdio.h>
#include<math.h>
//自定義star型態可放name和xy座標 
struct star{
	char name[10];
	int x;
	int y;
};
//算距離 
double distance(int x1,int y1,int x2, int y2){
	return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)); 
}
//將座標換算為陣列索引 
int number(int x,int y){
	return x+(y-1)*30;
}
int main(){
	// check為檢查值 n為幾顆星星 max為最大距離 
	int i,n,check=0,j;
	double max=0;
	printf("輸入有幾顆星星:");
	scanf("%d",&n);
	//allstar為可存放所有星星的陣列 
	struct star allstar[n];
	for(i=0; i<n; i++){
		printf("第%d顆星星的名字為:",i+1);
		scanf("%s",&allstar[i].name);
		printf("第%d顆星星的x座標為:",i+1);
		scanf("%d",&allstar[i].x);
		printf("第%d顆星星的y座標為:",i+1);
		scanf("%d",&allstar[i].y);
		printf("\n");
		//判斷是否輸入錯誤 
		if(allstar[i].x<1||allstar[i].x>30||allstar[i].y<1||allstar[i].y>30){
			printf("範圍是1~30之間 輸入有誤 請重新輸入\n\n");
			i--;
		}
	}
	//上方座標 
	for(i=0; i<30; i++)
		printf("%2d",i+1);
		printf("\n");
	//30x30大小的面板 每一個位置都偵測是否有星星在此座標上 有則將check設為1 並將星星印出 
	for(i=0; i<900; i++){
		check=0;
		for(j=0; j<n; j++){
			if(number(allstar[j].x,allstar[j].y)==i+1){
				printf(" *");
				check=1;
				break;
			}
		}
		if(check==0)
			printf(" -");
		if((i+1)%30==0){
			printf(" %d",(i+1)/30);
			printf("\n");
		}
	}
	printf("\n");
	//每一顆星星彼此的距離 
	for(i=0; i<n; i++){
		for(j=i+1; j<n; j++){
			if(distance(allstar[i].x,allstar[i].y,allstar[j].x,allstar[j].y)>max)
				max=distance(allstar[i].x,allstar[i].y,allstar[j].x,allstar[j].y);
			printf("%s 和 %s 的距離是 %f\n",allstar[i].name,allstar[j].name,distance(allstar[i].x,allstar[i].y,allstar[j].x,allstar[j].y));
		}
	}
	printf("\n最遠的兩顆星星距離是%f",max);
} 
