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

void noMoreCars (a3Car ** headLL) {
    //declaring variables 
    char input;
    a3Car *removeCar = *headLL;
    a3Car *temp;

    for(;;) {
        //ask for user input to enter y or n
        printf("Are you sure you want to remove all car data (enter y for yes, n for no): ");
        scanf(" %c", &input);
        //break when the user enter exactly y or n
        if (input == 'y' || input == 'n') {
            break;
        }
    }

    //if yes we will free all the linked list
    if (input == 'y') {
        //transverse through linked list and free every node
        while(removeCar != NULL) {
            temp = removeCar;
            removeCar = removeCar->nextCar;
            free(temp);
        }
        //making head empty and print the message
        *headLL = NULL;
        printf("All removed. Linked list is now empty.\n");
    }
    else {
        //if "n" then return back
        return;
    }
}