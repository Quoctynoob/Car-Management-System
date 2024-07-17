carBase: mainA3.o addNewCar.o printAll.o printOne.o lookForCarId.o lookForCarModelType.o sortCarId.o loadCarData.o countCars.o noMoreCars.o oneLessCar.o
	gcc mainA3.o addNewCar.o printAll.o printOne.o lookForCarId.o lookForCarModelType.o sortCarId.o loadCarData.o countCars.o noMoreCars.o oneLessCar.o -o bin/carBase
mainA3.o: src/mainA3.c include/headerA3.h
	gcc -Wall -std=c99 -c src/mainA3.c
addNewCar.o: src/addNewCar.c include/headerA3.h
	gcc -Wall -std=c99 -c src/addNewCar.c
printAll.o: src/printAll.c include/headerA3.h
	gcc -Wall -std=c99 -c src/printAll.c 
printOne.o: src/printOne.c include/headerA3.h
	gcc -Wall -std=c99 -c src/printOne.c
lookForCarId.o: src/lookForCarId.c include/headerA3.h
	gcc -Wall -std=c99 -c src/lookForCarId.c
lookForCarModelType.o: src/lookForCarModelType.c include/headerA3.h
	gcc -Wall -std=c99 -c src/lookForCarModelType.c
sortCarId.o: src/sortCarId.c include/headerA3.h
	gcc -Wall -std=c99 -c src/sortCarId.c
loadCarData.o: src/loadCarData.c include/headerA3.h
	gcc -Wall -std=c99 -c src/loadCarData.c
countCars.o: src/countCars.c include/headerA3.h
	gcc -Wall -std=c99 -c src/countCars.c
noMoreCars.o: src/noMoreCars.c include/headerA3.h
	gcc -Wall -std=c99 -c src/noMoreCars.c
oneLessCar.o: src/oneLessCar.c include/headerA3.h
	gcc -Wall -std=c99 -c src/oneLessCar.c
clean: 
	rm *.o 
