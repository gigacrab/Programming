#include <stdio.h>
#include <stdlib.h>

int convert(int** out, int* multi, int n);

int main(){
    int n = 0;
    int* out;
    int multi = 0;

    printf("Enter your number: ");
    scanf("%d", &n);
    convert(&out, &multi, n);
    printf("Binary: ");
    for(int a = multi - 1; a >= 0; a--){
        printf("%d", out[a]);
    }
    free(out);
    return 0;
}

int convert(int** out, int* multi, int n){
    int temp = n;
    while(temp > 0){
        temp = (int)(temp/2);
        *multi = *multi + 1;
    }
    *out = (int*)calloc(*multi, sizeof(int));
    for(int i = 0; i < *multi; i++){
        (*out)[i] = n%2;
        n = (int)(n/2);
    }
}