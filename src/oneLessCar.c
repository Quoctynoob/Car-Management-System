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

void oneLessCar (a3Car ** headLL, int whichOne) {
    //declaring variables
    a3Car ** removeCar = headLL;
    a3Car  * temp;
    int carNumber = 1;

    //transverse through the loop and stop when either reaches the end or reaches the requested position
    while (*removeCar != NULL && carNumber < whichOne) {
        //add one each time
        carNumber++;
        //find the node before the one we want to remove
        removeCar = &(*removeCar)->nextCar;
    }

    //once found we free the node
    temp = *removeCar;
    *removeCar = (*removeCar)->nextCar;
    free(temp);
}