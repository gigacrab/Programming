#include <stdio.h>

typedef struct{
    double x;
    double y;
}vector;

vector c = {0, 0};

void vectorAdd(vector* v1, vector* v2, vector* result){
    // can use (*v1).x as well
    result->x = v1->x + v2->x;
    result->y = v1->y + v2->y;
}

int main(){
    vector a = {1, 2};
    vector b = {2, 3};
    vectorAdd(&a, &b, &c);
    printf("The resultant vector is {%.2f, %.2f}", c.x, c.y);
}