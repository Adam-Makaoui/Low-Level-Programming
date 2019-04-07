#include <stdio.h>

float value;
char c1, c2;

int main(void) {



    for ( ; ;) {
        printf("Enter a value from 1-5 : ");
        scanf(" %c", &c1);

        if (c1 == '1') {
            printf("Enter a char 'K'(Km -> Mile) or 'M' (Mile ->Km) : ");
            scanf(" %c", &c2);
            if (c2 == 'K' || c2 == 'k') {
                printf("enter the value you'd like to convert to Miles : ");
                scanf(" %f", &value);
                value = value/1.609; // K->M
                printf(" the value is %f Miles\n", value);
            }
            else if (c2 == 'M' || c2 == 'm') {
                printf("enter the value you'd like to convert to Kilometres : ");
                scanf(" %f", &value);
                value = value *1.609; //M->K
                printf(" the value is %f Kilometres\n", value);
            }
            else{
                printf("ERROR, enter a correct value from 1-5\n");
            }
        }


        if (c1 == '2') {
            printf("Enter a char 'M' (Meter) or 'F' (Feet) : ");
            scanf(" %c", &c2);
            if (c2 == 'M' || c2 == 'm') {
                printf("enter the value you'd like to convert to feet");
                scanf(" %f", &value);
                value = value * 3.281; // M->F
                printf(" the value is %f feet\n", value);
            }
            else if (c2 == 'F' || c2 == 'f') {
                    printf("enter the value you'd like to convert to metres");
                    scanf(" %f", &value);
                    value = value / 3.281; //F->M
                    printf(" the value is %f metres\n", value);
            }
            else {
                printf("ERROR, enter a correct value from 1-5");
            }
        }

        if (c1 == '3') {
            printf("Enter a char 'C' (centimetre or 'I' (Inch) : ");
            scanf(" %c", &c2);
            if (c2 == 'C' || c2 == 'c') {
                printf("enter the value you'd like to convert to inches");
                scanf(" %f", &value);
                value = value /2.54; // C->I
                printf(" the value is %f inches\n", value);
            }
            else if (c2 == 'I' || c2 == 'i') {
                printf("enter the value you'd like to convert to centimetres");
                scanf(" %f", &value);
                value = value * 2.54; //I->C
                printf(" the value is %f centimetres\n", value);
            }
            else{
                printf("ERROR, enter a correct value from 1-5");
            }
        }


        if (c1 == '4') {
            printf("Enter a char 'C' (Celsius) or 'F' (Fahrenheit) : ");
            scanf(" %c", &c2);
            if (c2 == 'C' || c2 == 'c') {
                printf("enter the value you'd like to convert to Fahrenheit");
                scanf(" %f", &value);
                value = (value * 9/5) +32; // C->F
                printf(" the value is %f Fahrenheit\n", value);
            }
            else if (c2 == 'F' || c2 == 'f') {
                printf("enter the value you'd like to convert to Celsius");
                scanf(" %f", &value);
                value = (value -32)*5/9; //F->C
                printf(" the value is %f Celsius\n", value);
            }
            else{
                printf("ERROR, enter a correct value from 1-5");
            }
        }


        if (c1 == '5') {
            printf("Exiting System... ");
            return 0;
        }


        if  (c1 !='1' && c1 != '2' && c1 != '3' && c1 != '4' && c1 != '5') {
            printf("ERROR, enter a value from 1-5 ");
        }

    }

}