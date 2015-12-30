#include<stdio.h>
//排序 
void sort(int input[],int n){
    int i,j,tmp;
    for(i=0; i<n; i++){
        tmp=input[i];
        for(j=i; j>=0; j--){
            if(input[j]>tmp){
                input[j+1]=input[j];
            }
            if(input[j]<tmp)
                break;
        }
        input[j+1]=tmp;
    }
}
int main(){
    //drink為飲料罐數，other為其他商品數量，othermoney,drinkmoney分別為其他物品總價及飲料總價，price為輸入其他物品用 
    int drink,other,i,othermoney=0,drinkmoney=0,price;
    //5捨6入暫用值 
    float tmp;
    printf("要買幾罐飲料?\n");
    scanf("%d",&drink);
    printf("其他還要買幾樣?\n");
    scanf("%d",&other);
    //因為只有飲料會有發生沒湊到兩樣優惠有差別的問題 所以飲料使用一個陣列來排序價錢 
    int drinkprice[drink];
    for(i=0; i<drink; i++){
        printf("第%d罐飲料的價錢 ",i+1);
        scanf("%d",&drinkprice[i]);
    }
    sort(drinkprice,drink);
    
    //算出其他物品的總價 
    for(i=0; i<other; i++){
        printf("第%d個東西的價錢 ",i+1);
        scanf("%d",&price);
        othermoney=othermoney+price;
    }
    tmp=othermoney*0.9;
    othermoney=(int)(tmp+0.4);
    //算飲料價錢 
    if(drink%2==0){
        for(i=0; i<drink; i++){
            drinkmoney+=drinkprice[i];
        }
        tmp=drinkmoney*0.88;
        drinkmoney=(int)(tmp+0.4);
    }else{
        for(i=0; i<drink-1; i++){
            drinkmoney+=drinkprice[i];
        }
        tmp=drinkmoney*0.88;
        drinkmoney=(int)(tmp+0.4);
        drinkmoney=drinkmoney+drinkprice[i];
    }
    printf("\n算出來總共的飲料價格為%d元\n其他價格為%d元\n總計為%d元\n",drinkmoney,othermoney,drinkmoney+othermoney);
}
