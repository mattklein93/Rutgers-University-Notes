

#include <stdio.h>
//#include "hash.h"
#define BUFFER_SIZE 1000
#include <string.h>
#define WORD_LEN  100
#include <ctype.h>

typedef struct Node{
	int occ; //total occurances 
	int cso; 
	char * word;
	struct Node  * left; 
	struct Node * right; 
};

struct Node*  insert (char *, struct Node *); 


/*void insert (char * a , struct Node ** root) // throw in a new char array and the address of the root of the tree
{
		struct Node** node = root;
		
    	while (*node != NULL) {
			 if (stricmp(a, *node->word) < 0) // a is smaller than the node
				{
					if(*node->left == NULL) {
						struct Node * temp = (struct Node *) malloc(sizeof(struct Node) + 1); 
						temp->word = a; 
						*node->left = temp; 
					}
					else 
						*node = &(*node)->left;
				
				}
			else if (stricmp(a, *node->word) > 0) // a is bigger than the node
				{
					if(*node->right == null) {
						struct Node * temp = (struct Node *) malloc(sizeof(struct Node) + 1); 
						temp->word = a; 
						*node->right = temp; 
					}
					else 
						*node = *node->right;
				
				}
			else 
				{
					*node->occ++;
					if (strcmp(a, *node->word) == 0)
						*node->cso++; 
				}
		
		}

}
*/
void print(struct Node * root){
	print(root->left);
	printf("%s %d %d", root->word, root->occ, root->cso);
	print(root->right);

}
struct Node* insert(char * a , struct Node * root)
{
	char *lol = (char*) malloc(sizeof(&a)); 
	strcpy(lol, a);
	printf ("%s", lol); 
    if( root == 0 )
    {
        root = (struct Node*) malloc(sizeof(struct Node));
        root->word = lol; 
        //initialize the children to null 
        root->left = 0;    
        root->right = 0;   
    }
	else {
		char * f = root->word;
		if (strcasecmp(a,f) == 0) //if they are equal 
    	{
        	root->occ++;
			if (strcmp(a,f) == 0)
				root->cso++; 
			return root; 
    	}
    	else if(strcasecmp(a,f)  < 0) // a is less than b 
    	{
        	insert(a, root->right);
    	}
		else // a is more than f 
		{
			insert(a, root->left);
		}
	}
	return root; 
}
int main()
{ 
	
	struct Node * tree = ( struct Node *) malloc(sizeof( struct Node)); //initialize a memory block FOR THE FIRST NODE 
    FILE *input;        //File pointer
	char buffer [BUFFER_SIZE];
    input = fopen("faiq.txt", "r");    //Open file, second parameter is mode
	int flag = 0; //flag for root node 
    if (input != NULL) {
    	while (fgets(buffer, sizeof(buffer)/sizeof(char), input)){
  			int startword = 0; 
			int i = 0;
			int k = 0; 
			while (i < strlen(buffer)) // loop through line 
			{
				char * ptr; 
				char temp[WORD_LEN];
				//printf("%d", i);
				if  (isalpha(buffer[i]) != 0 && startword == 0) // i found a letter 
				{
					startword = 1;  
					temp[k] = buffer[i]; 
					k++; 
					i++;
						
				}
				else if (startword == 1)
				{
					while(1) {
						/*if (isdigit(buffer[i]) != 0)
						{
							temp[k] = buffer[i];
							i++;
							k++;
						} //end if */
						if (isalpha(buffer[i]) != 0) //we found a letter, append that to the word 
						{
							temp[k] = buffer[i]; 
							startword = 0;  
							i++; 
							k++;
						} //end else 
						else{
							if(isdigit(buffer[i]) != 0){
								temp[k] = buffer[i]; 
								k++;
							}// end if  
							temp[k] = '\0 ';
							k = 0;
							startword = 0;
							ptr = temp;  
							printf("%s \n" , temp);
				
							if(flag == 0){
								struct Node start = {0,0,ptr};
								tree = &start; //equivalent to *tree = start?; 
								flag = 1;
							}	
							else{
								tree = insert(ptr, tree);
							} 

							break; 
						}
					}	//end while 
				}//end else if 
				else 
					i++; 
    		}//end while to go through the lines word by word 
	}// end while to get the lines 
	printf("%s", "word______________number of total occ_number of casesensitive occ");
	print(tree);
	}//IF END 

	else 
		printf("%s", "put in a proper file numbskull");
		

	
}
