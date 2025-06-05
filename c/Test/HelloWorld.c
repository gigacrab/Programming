#include <stdio.h>

/*char* func(int x){
    static char hello[100] = "Help!";
    return hello;
}

int sum (int *x, int *y){
    int z = *x + *y;
    *x = *x + 1;
    return z;
}*/

int main(){

    int arr[] = {1, 2, 3, 4, 5, 6};


    /*int n1 = 0;
    int n2 = 0;
    printf("Enter first number: ");
    scanf("%d", &n1);
    printf("Enter second number: ");
    scanf("%d", &n2);
    printf("The sum of the both numbers is %d", sum(&n1, &n2));
    printf(" %d", n1);*/

    /*char input[100];
    printf("Enter your name: ");
    scanf("%s", input);
    printf("Hi! %s", input);*/

    /*FILE *f;
    char fileName[] = "a.txt";
    char str[100] = "Hello World";
    int number = 9;

    printf("%s", str);
    printf("Your string is %s", func(1));*/

    //writing to file
    /*if((f=fopen(fileName, "w")) != NULL){
        printf("Enter name: ");
        scanf("%s", &name);
        fprintf(f, "%s", &name);
    }*/

    //reading file
    /*if((f=fopen(fileName, "r")) != NULL) {
        while(fscanf(f, "%s", s) != EOF){
            printf("%s\n", s);
        }
    }*/

    return 0; 
}