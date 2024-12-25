# Car Management System

This project is a Car Management System in C language. The system allows users to manage a list of cars, providing functionalities to add new cars, load car data from a file, search for cars, and sort them.

## Features

- **Add New Car**: Dynamically add new car entries to the system.
- **Load Car Data**: Load car information from a specified text file.
- **Search Car**: Search for cars based on car ID or model and type.
- **Sort Cars**: Sort the list of cars based on car ID.
- **Print Car Data**: Print data of all cars or a specific car.
- **Remove Car**: Remove data of a specific car or all cars.

## Files and Structure

- `src/mainA3.c`: Main program file containing the user interface and main logic.
- `src/addNewCar.c`: Function to add new cars to the linked list.
- `src/loadCarData.c`: Function to load car data from a text file.
- `src/lookForCarId.c`: Function to search for a car by ID.
- `src/lookForCarModelType.c`: Function to search for a car by model and type.
- `src/sortCarId.c`: Function to sort cars by ID.
- `include/headerA3.h`: Header file containing function prototypes and definitions.
- `makefile`: Makefile for compiling the project.
- `inputFile.txt`: Sample input file containing car data.

## How to Run

1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/car-management-system.git
   cd car-management-system
2. Compile the project:
   ```bash
   make
3. Run the program:
   ```bash
   ./bin/carBase

