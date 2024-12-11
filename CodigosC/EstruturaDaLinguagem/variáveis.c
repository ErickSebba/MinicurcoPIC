#include <stdio.h>
#include <stdlib.h>

int main(){
    char a = 'a';
    int b = 10;
    float c = 10.5;
    double d = 10.55901;

    signed char e = -10;
    short int f = 10;
    long int g = 10;
    long long int h = 10;
    unsigned char i = 10;

    register char k = 10;
    static int l = 10;
    const unsigned char m = 10;
    volatile int n = 10;
    //extern float o = 10.5;//error an initializer is not allowed on a local declaration of an extern variable
    
    int media; //uma variável
    int Media; //outra variável
    int mEdIa; //uma terceira variável
    int MEDIA; //uma quarta variável

    int variavel;
    int _variavel;
    int vari_avel;
    //int /variavel; //invalido

    float conversao = 10.5;
    int inteiro = (int)conversao; // inteiro = 10

}