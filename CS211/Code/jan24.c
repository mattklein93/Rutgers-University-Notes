#include <stdio.h>						//Includes IO

int main() {							//Always the name, has nothing to do with the file
	printf("cogito ergo sum.\n");		//Standard output
	return 0;							//Return to the shell
}

-------

#include <stdio.h>

int main (int argc, char **argv) {						//argc by convention, argv is convention
														// can also take any amount of arguments
	int i;
	for (i = 0; i < argc, i++) {
		printf("arg %d is %s)n", i, argv[i]);			//Reads from commands
	}
	return 0;
}

-------
//Structure, since no classes. This is a point in a 2d space. No constructors, everything is public.
//There is no private etc.
struct point {
	int x;
	int y;
} a,b,c;	//These are struct variables already created

//Nothing is declared for us
//Declaring a struct
struct point pt = {200, 300};
struct point pt = {200}; //no need to complete. now only x is initialized.
pt.y = 300; //just sets pt's y to 300.

struct rect {
	struct point lowleft;
	struct point topright;
	int q;
}
struct rect box = {{200,300}, {0,7}, 5};

------

int a[50]
int b[7][30]
int c[] = {0,1,2,3,4,5};		//initializer
int d[][3] = {{1,2,3}.{4,5,6}}


------
//Bad
int main() {
	int array[10], i;
	for (i = 0; i <= 10; i++)
		array[i] = 0;	//After i is 10, a[0] is at the same space as i. resets i to 0 and continues forever
	return 0;
}

------

union bigword {
	long bwlong;
	char bwchar[4];
};
