#include <stdio.h>
#include <stdlib.h>

/*FUNCTION*/
float recursiveExp(float a, int n) {

    if (a<0) {
        printf("ERROR, Enter a positive base (a)");
        exit(-1);
    }
    //base case
    if (n == 0) {
        return 1;
    }
    float temp = recursiveExp(a, n/2);

    if (n % 2 == 0) { //even
        return temp*temp;
    }
    else
    {
        if (n>0) { //odd
            return a*temp*temp;
        }
        else
            return (temp*temp)/a;
    }

}

main() {
    float a;  //base
    int n; //exponent
    float result;

    //Getting user input "&" storing it in variables
    printf("enter base (float) : ");
    scanf("%f", &a);
    printf("enter exponent (int) : ");
    scanf("%d", &n);

    //calling the rec-function and displaying output
    result = recursiveExp(a, n);
    printf("The result is :  %f \n", result);


    //system("pause");
    return 0;

}                    /*********END OF MAIN METHOD*********/