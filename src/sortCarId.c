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

void sortCarId (struct car ** headLL) {
    //Declaring variables
    a3Car ** current;
    a3Car * temp;
    a3Car * last = NULL;
    int swap;

    //if empty return
    if (*headLL == NULL) {
        return;
    }

    //loop through to bubble swap
    for(;;) {
        current = headLL;
        swap = 0;
        //transverse through all nodes until the last one
        while ((*current)->nextCar != last) {
            temp = *current;
            //when carId's is bigger than the other one then we sort it
            if (temp->carId > temp->nextCar->carId) {
                swap = 1;
                *current = temp->nextCar;
                temp->nextCar = temp->nextCar->nextCar;
                (*current)->nextCar = temp;
            }
            current = &(*current)->nextCar;
        }
        //then we adjust last to the last sorted node
        last = temp;

        //when everything done swapping , then break
        if (!swap) {
            break;
        }
    }

}