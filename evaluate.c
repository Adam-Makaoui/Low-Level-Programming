#include <stdio.h>
#include <stdlib.h>\#include <stdbool.h>

//variables
int looper = 1;
char play_again = '\0';

char get_op(){
    char character = '\0';
    scanf(" %c", &character);
    return character; }

float get_num(){
    float number=0;
    scanf(" %f", &number);
    return number; }

float m_exp(float sub_exp, char op) {
    if(op=='+' || op=='-' || op=='\n') {
        ungetc(op,stdin); //push back on stack
        return sub_exp;
    }
    else {
        float f1 = get_num();
        char op1 = get_op();
        if (op1=='*'){
            f1=sub_exp*f1;
        }
        else if (op1=='/'){
            f1 = sub_exp*f1;
        }
        return m_exp(f1,op1);
    }

}

float s_exp(float sub_exp, char op) {
    if(op=='+' || op=='-' || op=='\n') {
        ungetc(op,stdin); //push back on stack
        return sub_exp;
    }
    else {
        float f1 = m_exp(sub_exp,op);
        char op1 = get_op();
        if (op1=='*'){
            f1=sub_exp*f1;
        }
        else if (op1=='/'){
            f1 = sub_exp*f1;
        }
        return s_exp(f1,op1);
    }

}

int main() {

// 2-ask user to cont or not, opt to use "do-while"

do {// 1- ask user for input (arthmetic expression)
    printf("Play again? (Y or N)\n");
    scanf( "%c", &play_again);
    if(play_again=='N' || play_again=='n'){
        looper = 0; //no more loops
    }
} while(looper==1);

    return 0;
}