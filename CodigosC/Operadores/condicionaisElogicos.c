#include <stdio.h>
int main(){
    int a=10, b=3;

    if(a > b){
        printf("A é maior que B\n");
    }

    if(a<b){
        printf("A é menor que B\n");
    }

    if(a<=b){
        printf("A é menor ou igual a B\n");
    }

    if(a>=b){
        printf("A é maior ou igual a B\n");
    }

    if(a==b){
        printf("A é igual a B\n");
    }

    if(a!=b){
        printf("A é diferente de B\n");
    }

    //não, e, ou logico
    if(a>b && a<b){
        printf("A é maior que B e menor que B\n");
    }

    if(a>b || a<b){
        printf("A é maior que B ou menor que B\n");
    }


}