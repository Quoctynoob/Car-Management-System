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

int lookForCarId (struct car * headLL, int key) {
    //declaring variable
    int carNumber = 1;
    //transverse through the linked list
    while(headLL != NULL) {
        //when the requested carId matches with carId we have in linked list
        if(key == headLL->carId) {
            //return the position
            return carNumber;
        }
        //if not add 1 and move to the next node
        carNumber++;
        headLL = headLL->nextCar;
    }

    //when found nothing return -1
    return -1;
}