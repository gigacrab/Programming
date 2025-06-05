#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int* item;
    int num;
}list;

int main(){
    list arr;
    arr.num = 10;
    arr.item = calloc(arr.num, sizeof(*arr.item));
    for(int i = 0; i < arr.num; i++){
        arr.item[i] = i;
    }
    for(int i = 0; i < arr.num; i++){
        printf(" %d", arr.item[i]);
    }
    return 0;
    /*list ptr;
    ptr.size = sizeof(ptr.size);
    ptr.iNum = 10;
    *ptr.item = malloc(ptr.iNum * ptr.size);
    
    int amount = 42;
    for(int* i = 0; *i < amount; *i++){
        if(ptr.iNum == amount){
            ptr.iNum += 10;
            ptr.item = realloc(ptr.item, ptr.iNum * ptr.size);
        }
        ptr.*item[*i] = *i;
    }
    printf("Pointer size is %d", ptr.iNum * ptr.size);*/
    
}