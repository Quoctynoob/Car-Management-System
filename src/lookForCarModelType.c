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

int lookForCarModelType (struct car * headLL, char key [100]) {
    //declaring variables
    int carNumber = 1;
    char *model, *type;

    //use strtok to separate using the space
    model = strtok(key, " ");
    type = strtok(NULL, " ");

    //transverse through the linked list
    while (headLL != NULL) {
        //compare the requested string with the one in linked list
        if (strcmp(headLL->model, model) == 0 && strcmp(headLL->type, type) == 0) {
            return carNumber;
        }
        //add one each time
        carNumber++;
        //move to the next node
        headLL = headLL->nextCar; 
    }
    //return -1 if nothing is found
    return -1;
}