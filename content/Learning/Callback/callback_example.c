#include <stdlib.h>
#include <stdio.h>

void executer(int input, int (*func_ptr)(int)){
    (*func_ptr)(input);
}
int add_one(int input){
    printf("%d\n", input + 1);
}
int add_two(int input){
    printf("%d\n", input + 2);
}
int main(){
    executer(2, add_one);
    executer(2, add_two);
    return 0;
}