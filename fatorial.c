#include <stdio.h>
#include<stdlib.h>

int fatorialN(int n) {
    if(n) {
        return n * fatorialN(n - 1);
    } else {
        return 1;
    }
}

int main() {
    int num;
    scanf("%d", &num);

    printf("%d\n", fatorialN(num));

    return 0;
}
