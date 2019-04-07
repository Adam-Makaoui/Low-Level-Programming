#include <stdio.h>

int main(void) {
    /*   ------------------------------------ CREATING ARRAY ------------------------------------    */
    const char segment[10][3][3]={ {{' ','_',' '},{'|',' ','|'},{'|','_','|'}}, //0

                                   {{' ',' ',' '},{' ',' ','|'},{' ',' ','|'}}, //1

                                   {{' ','_',' '},{' ','_','|'},{'|','_',' '}}, //2

                                   {{' ','_',' '},{' ','_','|'},{' ','_','|'}}, //3

                                   {{' ',' ',' '},{'|','_','|'},{' ',' ','|'}}, //4

                                   {{' ','_',' '},{'|','_',' '},{' ','_','|'}}, //5

                                   {{' ','_',' '},{'|','_',' '},{'|','_','|'}}, //6

                                   {{' ','_',' '},{' ',' ','|'},{' ',' ','|'}}, //7

                                   {{' ','_',' '},{'|','_','|'},{'|','_','|'}}, //8

                                   {{' ','_',' '},{'|','_','|'},{' ','_','|'}} }; //9
    /*    ------------------------------------------ DONE ARRAY ---------------------------------    */

    char playAgain; // var to hold 'Y' OR 'N'

    do { //do while loop to keep on asking to run program

        int num;
        printf("\nEnter integer : ");
        scanf(" %d", &num);
        int n=num; //making copy of user input (number)
        int numDigits=0,pos=0;
        while(num>0 || -1*num > 0){ //counting how manny digits in number
            num=num/10;
            numDigits++;
        }

        int negative = 0;
        //dealing with negative
        if (n<0) {
            negative = 1;
            n *= -1; // inverse of neg is pos
        }


        int arr[numDigits]; //array according to number of digits
        while(n>0) {
            arr[pos]=n%10; //breaking number and storing remainder in array
            n=n/10;
            pos++; }


        int j;
        for(j=0;j<3;j++) {
            if (negative==1 && j%2==1){
                printf(" - ");}
            else if (negative==1 && j%2==0) {
                printf("   ");
            }
            int i;
            for(i=numDigits-1;i>=0;i--){ //iterating arr from behind because remainder is stored in reverse order of number

                int numbers = arr[numDigits];
                int k;
                for(k=0;k<3;k++){
                    printf("%c",segment[arr[numbers]][j][k]); } //printing 3d array values
            }
            printf("\n");
        }
        printf("\n You want to continue(Y/N):");
        scanf(" %c", &playAgain);


    } while (playAgain=='Y' || playAgain=='y');

    return 0;
}