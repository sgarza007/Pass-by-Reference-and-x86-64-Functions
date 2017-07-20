/*
 * TODO: add top-level comment
 *
 */

#include <stdio.h>
#include <stdlib.h>

// You will implement this function in swap.s
/*
 * Rotates the values pointed at by the parameters
 * @param x A pointer to an integer
 * @param y A pointer to another integer
 * @param y A pointer to yet another integer
 */
void rotate(int *x, int *y, int *z);

int main(int argc, char **argv) {
	if(argc != 4) {
		printf("usage: ./swap-test a b c\n");
		exit(1);
	}

	// Convert command line args from text to integers
	// Note: strtol returns a long, so need to cast it
	int a = (int)strtol(argv[1], NULL, 10);
	int b = (int)strtol(argv[2], NULL, 10);
	int c = (int)strtol(argv[3], NULL, 10);

	printf("Before rotate: a = %d, b = %d, c = %d \n", a, b, c);
	rotate(&a, &b, &c);
	printf("After first rotate: a = %d, b = %d, c = %d \n", a, b, c);
	rotate(&a, &b, &c);
	printf("After second rotate: a = %d, b = %d, c = %d \n", a, b, c);

	return 0;
}
