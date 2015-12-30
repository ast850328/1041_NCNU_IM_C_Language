#include <stdio.h>
void weight(int *s, int n, int m, int got, int from, int treeWeight, int * result) {
    int i;
    int tmp;
    if (m == got) {
        int tmpWeight = 0;
        for (i = 0; i < got; i++)
            tmpWeight += s[i];
        if(tmpWeight == treeWeight){
            for (i = 0; i < got; i++)
                printf("%d ", s[i]);
            printf("\n");
            *result = *result + 1;
        }
        return;
    }
    for (i = from; i < n; i++) {
        tmp = s[i];
        s[i] = s[got];
        s[got] = tmp;
        weight(s, n , m, got + 1, i + 1, treeWeight, result);
        tmp = s[i];
        s[i] = s[got];
        s[got] = tmp;
    }
}
int main(){
    int n,i;
    scanf("%d",&n);
    int m[n];
    for(i = 0; i < n; i++)
        scanf("%d",&m[i]);
    int treeWeight,result = 0;
    scanf("%d", &treeWeight);
    for(i = 1; i <= n; i++)
        weight(m,n,i,0,0,treeWeight,&result);
    if (result == 0)
        printf("No answer.\n");
}
