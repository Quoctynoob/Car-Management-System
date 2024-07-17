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

void loadCarData (struct car ** headLL, char fileName [MAX_LENGTH]) {
    //Declaring variables
    a3Car * temp = *headLL;
    a3Car * newCarId;
    char *tempModel, *tempType, *tempPrice, *tempCarId, *tempYear;
    char input[100];
    int uniqueId = 0;
    int randomNumber;

    //open file in read mode
    FILE *file = fopen(fileName, "r");

    //If empty print error message and return
    if (file == NULL) {
        printf("File doesn't exist\n");
        return;
    }

    //keep reading the text file when it's not empty
    while (fgets(input, sizeof(input), file) != NULL) {

        newCarId = malloc(sizeof(a3Car)); 

        //add information in use "strtok" to separate commas
        tempCarId = strtok(input, ","); 
        newCarId->carId = atoi(tempCarId);
        tempModel = strtok(NULL, ","); 
        strcpy(newCarId->model, tempModel);
        tempType = strtok(NULL, ","); 
        strcpy(newCarId->type, tempType);
        tempYear = strtok(NULL, ","); 
        newCarId->year = atoi(tempYear);
        tempPrice = strtok(NULL, ",");
        newCarId->price = atof(tempPrice);

        //if matching names, we add random numbers
        while(uniqueId == 0) {
        //then make it to 1 to identify we change it to the new id already
            uniqueId = 1;
            temp = *headLL;
            //transverse through linked list until reaches the end
            while(temp != NULL) {
                //compare any identical id
                if(temp->carId == newCarId->carId) {
                    //if yes then change "uniqueId" back to 0 and add random generated number
                    uniqueId = 0;
                    srand(time(NULL));
                    randomNumber = rand() % 999 + 1;
                    newCarId->carId += randomNumber;
                    break;
                }
                //if no identical id, then we move to the next node
                temp = temp->nextCar;
            }
        }
        newCarId->nextCar = *headLL; 
        *headLL = newCarId;
    }
    fclose(file);
}