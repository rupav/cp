#include<stdio.h>
#include "somefile.h";

extern int var;
void main(){
    var = 10;
    printf("var is %d", var);
    getchar();
}
