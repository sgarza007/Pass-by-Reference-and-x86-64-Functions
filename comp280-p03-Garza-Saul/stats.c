/*
 * Program Name: Stats.c
 * Author: Saul Garza
 * Email: sgarza@sandiego.edu
 *
 * Description: Take in a file
 * with numbers and calculate 
 * various stats like mean and
 * mode.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "readfile.h"

/* TODO: Add other function prototypes here */
double *getValues(int *size, int *capacity, char *filename);
double mean(double a[], int size);
double median(double a[], int size);
double stdv(double a[], double mean, int size);

int main(int argc, char *argv[]) {
	if(argc != 2) {
		printf ("usage: ./stats filename\n");
		exit(1);
	}
	int size = 0, capacity = 0;
	double mn = 0.0, mdn = 0.0, std = 0.0;
	double *a = getValues(&size, &capacity, argv[1]);//calls getValues and stores values in a
	printf("Stats:\n-----------\n");//display results
	mn = mean(a, size);
	mdn = median(a, size);
	std = stdv(a, mn, size);
	printf("num values: %d\n",size);
	printf("Mean: %f\nMedian: %f\nStd Dev: %f\n", mn, mdn, std);
	printf("\nUnused slots: %d\n", capacity - size);
	free(a);
	return 0;
}

/*
 * getValues reads and sorts data from file
 * takes in pointers to useful stats
 * returns pointer to array 
 */
double *getValues(int *size, int *capacity, char *filename) {
	int i = 0, j = 0, ret = 0, count = 0, storage = 0;
	ret = openFile(filename);
	if(ret == -1){ 
		printf("Error reading file: %s\n", filename);
		exit(1);
	}
	double value = 0.0;
	storage = 20;
	double *a = calloc(20, sizeof(double));//allocate memory for 20
	while (ret != -1) {
		if(i < storage){//read values in as long as its readable and enough storage
			ret = readDouble(&value);
			if(ret == -1) { break; }
			a[i] = value;
			i++;
			count++;
		}
		else{//if need more space, store values in a temp with double the size, free a and set a to values already inside
			storage *= 2;
			double *temp = calloc(storage, sizeof(double));
			for(i = 0; i < count; i++){
				temp[i] = a[i];
			}
			free(a);
			a = temp;
		}
	}
	closeFile();
	*size = count;
	*capacity = storage;
	for (i = 0; i < count - 1; i++){//swap values to make median easier to calculate
		for (j = i + 1; j < count; j++){
			 if (a[i] > a[j]){
				 double temp = a[i];
				 a[i] = a[j];
				 a[j] = temp;
			 }
		 }
	}
	return a;
}

/*
 * Calculates mean
 * takes in array and size
 * returns mean
 */
double mean(double a[], int size){
	int i = 0;
	double mean = 0.0, sum = 0.0;
	for(i = 0; i < size; i++){
		sum += a[i];
	}
	mean = sum/size;
	return mean;
}

/*
 * Calculates standard deviation
 * Takes in array, mean and size
 * returns stdv
 */
double stdv(double a[], double mean, int size){//need mean, sum of (i - mean)^2, all over size-1
	int i = 0;
	double s = 0.0, sum = 0.0;
	for(i = 0; i < size; i++){
		sum += pow((a[i] - mean),2);
	}
	sum /= size-1;
	s = sqrt(sum);
	return s;
}
/*
 * Calculates median
 * Takes in array and size
 * Returns median
 */
double median(double a[], int size){
	double median = 0.0;
	int half = size/2;
	median = a[half];
	return median;
}
