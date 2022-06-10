
#include <stdio.h>
#include <math.h>

#define NBITS 8
#define MAX pow(2,NBITS)

void setZero(int arr[], int n);
void addOct(int result[], int binary1[], int binary2[]);
void subOct(int result[], int binary1[], int binary2[], int n);
void multiOct(int arr1[], int num2, int result[]);
void divOct(int arr1[], int arr2[], int result[]);
void decimal2oct(int bin[], int dec, int n);
int oct2dec(int oct[]);
void createOctArray(int arr[]);
void displayOct(int[]);

void main(){
    int num1,num2;
    int arr1[NBITS], arr2[NBITS], result[NBITS];
    createOctArray(arr1);
    createOctArray(arr2);
    createOctArray(result);

    do{
    
    printf("\nEnter the first decimal integer: ");
    scanf("%d", &num1);
    } while (!(num1 >0 && num1 <= MAX));

    do{
    printf("Enter the second decimal integer: ");
    scanf("%d", &num2);
    } while (!(num2 >0 && num2 <= MAX));

    decimal2oct(arr1, num1, NBITS);
    decimal2oct(arr2, num2, NBITS);

    printf("\nOctect number of decimal %d is : ", num1);
    displayOct(arr1);
    printf("\nAnd again decimal number is : %d", oct2dec(arr1));

    printf("\nOctect number of decimal %d is : ", num2);
    displayOct(arr2);
    printf("\nAnd again decimal number is : %d", oct2dec(arr2));


    printf("\n\nThis program can perform the following operations on binary numbers:\n1. ADDITION\n2. SUBTRACTION\n3. MULTIPLICATION\n4. DIVISION\n");

    int select;
    printf("Enter operation number that you want to do:  ");
    scanf("%d", &select);

    switch(select){
        case 1:
        addOct(result, arr1, arr2);
        printf("\nIf the operation is 1, the addition of the two numbers is: \n");
        break;

        case 2:
        if(num1 >= num2){
            subOct(result, arr1, arr2, NBITS);
            printf("\nIf the operation is 2, the subtraction of %d from %d  is: \n", num2,num1);
            }
        else if(num2 > num1){
        subOct(result, arr2, arr1, NBITS);
        printf("\nIf the operation is 2, the subtraction of %d from %d  is: \n", num1,num2);}
        break;

        case 3:
        multiOct(arr1, num2, result);
        printf("\nIf the operation is 3, the multiplication of the two numbers is: \n");
        break;

        case 4:
        divOct(arr1, arr2, result);
        printf("\nIf the operation is 4, the division of the two numbers is: \n");
        break;

        default:
        printf("\nError \n");
        break;
    }

    displayOct(result);
    printf("\nThe decimal result is : %d \n", oct2dec(result));
    printf("\n*********************\n\n");

}


void createOctArray(int arr[]){
    for(int i = 0; i < NBITS; i++){
        arr[i] = 0;
    }
}

void decimal2oct(int bin[], int dec, int num){
    int i = NBITS - 1;
    int rem;

    while (dec != 0)
    {
        rem = dec % 8;
        bin[i] = rem;
        dec = dec / 8;
        i--;
    }
    
}

void displayOct(int bin[]){
    for ( int j = 0; j < NBITS; j++){

        printf("%d", bin[j]);
        if (j<NBITS-1){ printf(" , ");}
    }
}

void addOct(int result[], int binary1[], int binary2[]){
    int check;
    int carry = 0;

    for(int i= NBITS-1; i >= 0; i--){

        check = binary1[i] + binary2[i] + carry;

        if(check <= 7){
            result[i] = check;
            carry = 0;
        }
        else if(check > 7){
            result[i] = check % 8;
            carry = check / 8;
        }
        else(printf("Error in Calculation"));
    }
}

void subOct(int result[], int binary1[], int binary2[], int n){
    int check;
    int carry = 0;

    for(int i= NBITS-1; i >= 0; i--){

        if( binary1[i] < binary2[i] ){

            binary1[i-1]--;
            binary1[i] = binary1[i] + 8;

            result[i] = binary1[i] - binary2[i];
        }
        else if ( binary1[i] >= binary2[i]) {
            result[i] = binary1[i] - binary2[i];
        }
        else(printf("Calculation Error"));
    }
}

void multiOct(int arr1[], int num2, int result[]){
    setZero(result, NBITS);
    for(int i=1 ; i <= num2; i++){
        addOct(result, arr1, result);
    }
}

int oct2dec(int oct[]){
    int lastDigit;
    int number = 0;
    int j = 0;

    for (int i = NBITS-1 ; i >= 0 ; i--){
        lastDigit = oct[i] * pow(8,j);
        number = number + lastDigit;
        j++;
    }
    return number;
}

void divOct(int arr1[], int arr2[], int result[]){
    setZero(result, NBITS);
    int times = 0;

    while(!(arr1[NBITS-1] <= 0 && arr1[NBITS-2] == 0)){
        subOct(arr1, arr1, arr2, NBITS);
        times++;
    }
    decimal2oct(result, times, NBITS);
}

void setZero(int arr[], int n){
    n = NBITS;
    for (int i =0; i < n; i++){
        arr[i] = 0;
    }

}