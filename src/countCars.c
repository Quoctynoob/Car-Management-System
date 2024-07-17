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

int countCars (a3Car * headLL) {
    //declaring variables
    int carNumber = 0;

    //if empty, then we return 0 cars
    if (headLL == NULL) {
        return 0;
    }
    else {
        //loop until reaches the end of the linked list
        while (headLL != NULL) {
            //add 1 to each time we past by a node
            carNumber++;
            //then move to the next node
            headLL = headLL->nextCar;
        }
    }
    //return the total of the node inside linked list
    return carNumber;
}