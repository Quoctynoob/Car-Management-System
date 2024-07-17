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

void addNewCar (struct car ** headLL) {
    //Declaring variables
    struct car *newCarId, *temp;
    char model[MAX_LENGTH], type[MAX_LENGTH];
    int randomNumber, year, lengthCar, carId;
    int sumAscii = 0;
    int uniqueId = 0;
    double price;

    //malloc for the size of struct 
    newCarId = malloc(sizeof(struct car));

    //Ask for user input and then input it into the struct
    printf("Enter the car model: ");
    scanf("%s", model);
    strcpy(newCarId->model, model);
    printf("Enter the car type: ");
    scanf("%s", type);
    strcpy(newCarId->type, type);
    printf("Enter its year of manufacture: ");
    scanf("%d", &year);
    newCarId->year = year;
    printf("Enter its price: CDN $ ");
    scanf("%lf", &price);
    newCarId->price = price;

    //this is to calculate the ASCII value of the model
    for (int i = 0; model[i] != '\0'; i++) {
        sumAscii += model[i];
    }
    lengthCar = strlen(type);

    //calculate the carId then add it into struct
    carId = sumAscii + lengthCar;
    newCarId->carId = carId;

    //checking for identical id
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
    //make this to be the last node
    newCarId->nextCar = NULL;
    //if "headLL" is null then we make it to the first node
    if (*headLL == NULL) {
        *headLL = newCarId;
    }
    else {
        //if not empty
        temp = *headLL;
        //we loop through all the node
        while (temp->nextCar != NULL) {
            temp = temp->nextCar;
        }
        //add the node at the end of linked list
        temp->nextCar = newCarId;
    }  
    //print out the carId
    printf("\nThe computer-generated carId is %d\n\n", newCarId->carId);
    
}