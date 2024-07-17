/*
Student Name: Quoc Le
Student ID: 1301583
Due Date: 04/05/2024
Course: CIS*2500
I have exclusive control over this submission via my password.
By including this header comment, I certify that:
1) I have read and understood the policy on academic integrity.
2) I have completed Moodle's module on academic integrity.
3) I have achieved at least 80% on the academic integrity quiz
I assert that this work is my own. I have appropriate acknowledged
any and all material that I have used, be it directly quoted or
paraphrased. Furthermore, I certify that this assignment was written
by me in its entirety.
*/

#include "../include/headerA3.h"

void printAll (struct car * headLL) {
    //declaring variable
    int temp;
    int carNumber = 0;
    int tempNum = 0;
    double price;

    //making condition if null then return 
    if (headLL == NULL) {
        printf("No cars found\n");
        return;
    }

    //transverse through linked list 
    while(headLL != NULL) {
        //printing all the info in each node
        carNumber++;
        printf("Car # %d:\n\t", carNumber);
        printf("Car id: %d\n\t", headLL->carId);
        printf("Model: %s\n\t", headLL->model);
        printf("Type: %s\n\t", headLL->type);
        //when price is less than 1000 then we don't need the commas
        if (headLL->price < 1000) {
            printf("Price: CDN $%.2lf\n", headLL->price);
        }
        else {
            //print the integer part after the commas(thousands) first
            temp = headLL->price / 1000;
            printf("Price: CDN $%d,", temp);

            //when hundreds are less than tens, print missing two zeros infront
            if ((int)headLL->price % 1000 < 10) {
                tempNum = 2;
            }
            //when hundreds are less than hundred, print missing one zeros infront
            else if ((int)headLL->price % 1000 < 100) {
                tempNum = 1;
            }
            else {
                //but if all digits in hundreds bigger than hundred, then no need to print any zeros
                tempNum = 0;
            }

            //this loop is used to print zeros
            for (int i = 0; i < tempNum; i++) {
                printf("0");
            }
            //and print the two zeros at the end
            price = headLL->price - (temp * 1000);
            printf("%.2lf\n\t", price);
        }
        printf("Year of Manufacture: %d\n\n", headLL->year);

        //then move to the next node
        headLL = headLL->nextCar;
    }
    //printing out the position to make it plural and singular LOL
    if (carNumber == 1) {
        printf("Currently, there is %d car.\n\n", carNumber);
    }
    else {
        printf("Currently, there are %d cars.\n\n", carNumber);
    }
    return;
}