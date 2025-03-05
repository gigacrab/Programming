#include <stdio.h>
#include <math.h>

int main(){
    printf("Enter your number: ");
    int n = 0;
    scanf("%d", &n);
    int q = n;
    int r = 0;
    int* out;
    int temp = n;
    int multi = 0;
    while(temp > 0){
        temp = (int)(temp/2);
        multi++;
    }
    out = calloc(multi, 4);
    int i = 0;
    do{
        r = q%2;
        out[i] = r;
        q = (int)(q/2);
        i += 1;
    }while(q != 0);
    for(int a = multi; a > 0; a--){
        printf("%d", out[a-1]);
    }
    free(out);
    return 0;
}