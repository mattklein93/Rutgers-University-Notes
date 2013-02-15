


enum stoplight {red, yellow, green};
-----------------
enum stoplight x;
int y;
x = red;
y = green;
x = (enum stoplight)37;			//Cast a generic number into an enum
					//Red = 1, Yellow = 2, Green = 3
------------------
enum stoplight {red = 5, yellow, green};	//Now red is 5, yellow is 6, green is 7

-------------------
typedef int size;
size x,y;	//Now variables of type size, equivalent to a type.
-------------------
typedef struct pt {
	int x,y;
} point

point left.top, right.top;
--------------
sizeof uniaryexpression			//Gives size bytes
sizeof (type-name)			//Gives size bytes
&					//Uniary Prefix ampersand gives address of whatever is after it (variable, type, etc)
*					//Uniary prefix, means dereference a pointer
,					//Seperating multiple expressions - The value of the comma seperated expression is the right most expression
->					//Dash and greater than, get members of structs from pointers


EX:			//Left		Right, the &x is not for the value but for the address
while(printf("enter an integer>>"), scanf("%d", &x) > 0) {
	printf("%d\n",x);
}

------------Pointers
int *p; 	//p is a pointer to an integer
int x;		//x is just an integer

p = &x;		//Points to the address of an integer
*p = 3;		//*p dereferences and changes what the pointer points to, which changes what x is
p = 0;		//null pointer, 0 is null in c


void swap (int *p1, int *p2) {		
	int temp;
	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

int x,y;
x = 3;
y = 5;
swap(&x, &y);


void faultyswap (int a, int b) {	//This swaps the copies, does not change the original values
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void faultyswap (int *a, int *b) {	//This swaps the copies, does not change the original values
	int *temp;
	temp = a;
	a = b;
	b = temp;
}
-------------Arrays

int *p, a[10],x;
p = &a[0];	//Takes an address of an array into an int
p = a;		//Refers to the pointer of the array and puts it in the array. Allows you to assign an array to ints.
x = *p;		//Grab pointer and put it in an integer

p[1] = 5; *(p+1)=5;	//Changes value in the array. Subscripts with pointers
++p;			//
p++;			//

		//Back to typedef
typedef int *ptrint;
ptrint p,q,r;		//This is the equivalent to the line below. Gives error message, try it.
int *p,*q,*r;

int a[10];				//size of an array over size of elemnts gives number of elements
myfcn(a, sizeof(a)/sizeof(int))

void myfcn(int *ptr, int noe) {...}

void *p;	//Universal pointer. Can assign anything to this
int *pi;
float *pf;

p = pi;
p = pf;
pf = (float*)p;
pi = (int*)p;


int main() {			//Eventually this program will misbehave as the top pointer will be the same as the one in the loop
	int a[10],i;
	printf("Addr of i is %#x\n", &i);
	for (i = 0; i <= 10; i++) {
		printf("Addr of a[%d] is %#x\n",i,&a[i]);
		a[i] = 0;
	}
}


----------String
		//Number of bytes is 6, not 5.
char *p3 = "hello";
char array[]= "hello";	//Defined by number of bytes. The 
char a2[10] = "hello";	//Bytes is 6, the rest are some garbage data.

char *list[8];		//List and argv are the same

int main(argc, char **argv)
