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

int main () {
    //declaring variables
    int choice, whichOneFour, totalCars, key, carFoundFive, newCars, carFoundSix, whichOneNine;
    char stringKey[100];
    char fileName[MAX_LENGTH];
    struct car *headLL = NULL;
    struct car *temp;
    for(;;) {
        //printing out the menu
        printf("1. Add data on a new car\n2. Load data on cars from a given text file\n");
        printf("3. Print data of all cars\n4. Print data of the nth car\n");
        printf("5. Search car data based on carId\n6. Search car data based on model and type\n");
        printf("7. Count the total number of cars in the list\n8. Sort the cars in the list based on carId\n");
        printf("9. Remove data of the nth car\n10. Remove all car data\n");

        printf("11. Exit\n");
        
        printf("Choose a menu option: ");
        scanf("%d", &choice);
        
        //use switch to call each functions
        switch (choice) {
            case 1:
                //calling function
                addNewCar(&headLL);
                break;
            case 2:
                //ask for user input to enter text file name
                printf("Enter your text file: ");
                scanf("%s", fileName);
                //then call the function here
                loadCarData(&headLL, fileName);
                break;
            case 3:
                //calling function
                printAll(headLL);
                break;
            case 4:
                for(;;) {
                    totalCars = countCars(headLL);
                    if (totalCars == 0) {
                        break;
                    }
                    //ask user input for position
                    printf("Enter a position: ");
                    scanf("%d", &whichOneFour);
                    //make sure the user input must be in range from 1 to available position we have
                    if (whichOneFour > 0  && whichOneFour <= totalCars) {
                        break;
                    }
                }
                //calling the function at the end
                printOne(headLL, whichOneFour);
                break;
            case 5:
                //ask user input for car ID
                printf("\nEnter a car ID: ");
                scanf("%d", &key);
                //then call the function
                carFoundFive = lookForCarId(headLL, key);
                //print out error message when not found id
                if (carFoundFive == -1) {
                    printf("No cars found with that ID\n\n");
                }
                else {
                    //if does then call function 4 here
                    printOne(headLL, carFoundFive);
                }
                break;
            case 6:
                //ask for user input
                printf("Enter the model and type (separated by a space): ");
                //remove the previous "\n" after enter 6 then use fgets to get user input
                while(getchar() != '\n');
                fgets(stringKey, sizeof(stringKey), stdin);
                //remove newline after fgets
                stringKey[strlen(stringKey) - 1] = '\0';
                //now call function here
                carFoundSix = lookForCarModelType(headLL, stringKey);
                //print out error message when not found id
                if (carFoundSix == -1) {
                    printf("No cars found with that name\n");
                }
                else {
                    //if does then call function 4 here
                    printOne(headLL, carFoundSix);
                }
                break;
            case 7:
                //calling function
                totalCars = countCars(headLL);
                printf("\nTotal number of cars = %d\n\n", totalCars);
                break;
            case 8:
                //calling the function
                sortCarId(&headLL);
                printAll(headLL);
                break;
            case 9:
                //keep counts of the total availble cars inside linked list
                totalCars = countCars(headLL);
                //if there are none, exit this choice
                if (totalCars == 0) {
                    printf("There are no cars to remove\n");
                    break;
                }
                for(;;) {
                    //when there is 1 car I put a different way to ask
                    while (totalCars == 1) {
                        printf("Currently there is 1 car.\n");
                        printf("Do you wish to remove this car - enter 1: ");
                        scanf("%d", &whichOneNine);
                        if (whichOneNine == 1) {
                            break;
                        }
                    }
                    //break from the loop when equal 1 so don't ask the question again
                    if (totalCars == 1) {
                        break;
                    }
                    //now if it's any other number then we keep asking again and again
                    printf("Currently there are %d cars.\n", totalCars);
                    printf("Which car do you wish to remove - enter a value between 1 and %d: ", totalCars);
                    scanf("%d", &whichOneNine);
                    //when satisfied condition, break
                    if (whichOneNine > 0  && whichOneNine <= totalCars) {
                        break;
                    }
                }
                //now we run the code
                oneLessCar(&headLL, whichOneNine);
                //print out the necessary result
                printf("\nCar [Id: %d] removed.\n", headLL->carId);
                newCars = totalCars - 1;
                printf("There are now %d cars remaining.\n", newCars);
                break;
            case 10:
                //calling the function
                noMoreCars(&headLL);
                break;
            case 11:
                //free all before exit so will not have any memory leaks
                while(headLL != NULL) {
                    temp = headLL;
                    headLL = headLL->nextCar;
                    free(temp);
                }
                return 0;
            default: printf ("\nThat is an invalid choice\n\n");
                
        }
    }
    return 0;
}