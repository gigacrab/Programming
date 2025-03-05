#include <stdio.h>
#include <stdlib.h>

int main(){
    int n = 0;
    int* out;
    int temp = 0;
    int multi = 0;

    printf("Enter your number: ");
    scanf("%d", &n);
    temp = n;
    while(temp > 0){
        temp = (int)(temp/2);
        multi++;
    }
    out = calloc(multi, sizeof(int));
    for(int i = 0; i < multi; i++){
        out[i] = n%2;
        n = (int)(n/2);
    }
    printf("Binary: ");
    for(int a = multi - 1; a >= 0; a--){
        printf("%d", out[a]);
    }
    free(out);
    return 0;
}

/*#include <stdio.h>
#include <stdlib.h>

int convert(int n, int** out) {
    int r = 0;
    int temp = n;
    int multi = 0;

    // Calculate the number of bits required to represent n
    while (temp > 0) {
        temp = temp / 2;
        multi++;
    }

    // Allocate memory for the binary representation
    *out = (int*)calloc(multi, sizeof(int));

    // Fill the array with the binary representation of n
    for (int i = 0; i < multi; i++) {
        r = n % 2;
        (*out)[i] = r;
        n = n / 2;
    }

    return multi;
}

int main() {
    printf("Enter your number: ");
    int n = 0;
    scanf("%d", &n);

    int* out = NULL;
    int multi = convert(n, &out);

    // Print the binary representation (in reverse order)
    for (int a = multi - 1; a >= 0; a--) {
        printf("%d", out[a]);
    }
    printf("\n");

    // Free the allocated memory
    free(out);

    return 0;
}*/