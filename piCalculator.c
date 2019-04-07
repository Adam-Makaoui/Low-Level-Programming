/**
 * This class calculates pi given a certain precision, the smaller epsilon is, the more accurate the value of pi
 *
 * @author Ahmed Attar, 250726961
 * @date 15th/Nov/2018
 */

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

float sum, currentVal, output, result;
float sign; // flag for sign change.
bool looper; //used to loop the code
char exiter;

/**
 *This method calculates the value which we need to stop the series at.
 * it will be a very small number.
 *
 * @param n - the number of series
 * @return a float that repr depth ("smallness" in with the provided n.
 */
float testCase (int n) {
    float temp =0.00;
    temp = 4.0/(2*n+1);
    return temp;
}
/**
 *This method computes and returns the value of pi
 *
 * @param epsilon - the max range
 * @return - sum of the series which is "pi"
 */
float piCalc (double epsilon) {
    sum = 0.0;
    sign = 1.0;
    int i;

    for(i = 1; testCase(i)>epsilon; i++ ){
        //printf("loop number %d\n", i);
        currentVal = 1.0/(2.0*i-1.0);
        currentVal*=sign; //multiple to change sings
        sign = (sign==1.0 ? -1.0 : 1.0); //Switch sign of flag "sign"
        sum +=currentVal; }

        return sum*4; // last part of the formula

}

int main (void) {
    looper = true;

    while(true) {
        printf("Started, Enter a value for epsilon or q to exit : ");
        scanf(" %c", &exiter);
        if (exiter=='q') {
            exit(0);
        }
        scanf(" %f", &output);
        result = piCalc(output);
        printf("The Value pi is : %.15lf \n\n", result);
    }


    //float test = testCase(4);
    //printf("%f\n",test);

    return 0;
}