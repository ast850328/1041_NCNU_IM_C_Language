#include<stdio.h>
int f(int x) {
    int i, a, b, c;
    if (x == 1) {
        return 1;
    } else if (x == 2) {
        return 1;
    } else {
        a = 1, b = 1, c;
    }

    for (i = 3; i <= x; i++) {
        c = a + b; 
        a = b;
        b = c;
    }
    return c; 
}

int main() {
    int num;
    scanf("%d", &num);
    printf("%d\n", f(num));
}
