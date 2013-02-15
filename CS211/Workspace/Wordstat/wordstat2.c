#include <stdio.h> 
#define BUFFER_SIZE 1000 
#include <string.h> 
#define WORD_LEN  100 
#include <ctype.h> 
#include <stdlib.h> 
  
  
 struct Node{ 
    int occ; 
    int cso;  
    char * word; 
    struct Node  * left;  
    struct Node * right;  
    struct ll * next; 
  
    }; 
    struct ll{ 
    char * word; 
    struct ll * next;  
    }; 
      
void print(struct Node * root){ 
    if (root == NULL) 
        return;  
    print(root->left); 
    printf("%s %d %d \n", root->word, root->occ, root->cso); 
    print(root->right); 
  
} 
  
  
void insert (struct Node** root, char * a) { 
    
    if (*root == NULL) { 
        struct Node * node = (struct Node *) malloc(sizeof(struct Node)); 
        node->word = (char*) malloc(sizeof(char)); 
        strcpy(node->word, a); 
        node->occ = 1; 
        node->cso = 1; 
        node->left = NULL;     
        node->right = NULL; 
        node->next = NULL; 
        *root = node; 
        printf("%s \n", "created first node"); 
    } 
    else { 
        printf("%s %s  \n", "we are comparing to this" , (*root)->word); 
    int casecomp = strcasecmp((*root)->word, a); 
    printf("%s", "node is not null"); 
        if(casecomp < 0) 
            insert(&(*root)->right, a); 
        if(casecomp > 0) 
            insert(&(*root)->left, a); 
        if(casecomp == 0) { 
            (*root)->occ++; /*increase occurances field now loop through the next field*/

            struct ll *next = (struct ll*)malloc(sizeof(struct ll*));
            next = NULL;
            (*root)->next = next;
            puts("need to find\n");
        } 
    } 
}

int main() 
{  
    struct Node * tree = NULL; 
    FILE *input;         
    char buffer [BUFFER_SIZE]; 
    input = fopen("faiq.txt", "r"); 
    char *token;
      
      
    if (input != NULL) { 
        while (fgets(buffer, sizeof(buffer)/sizeof(char), input)){ 
            token = strtok(buffer, ",./<>?`~!@#$%^&*()_-+=:;\"\'\\| []{}");
            while (token) {
                insert(&tree, token); 
                token = strtok(NULL, ",./<>?`~!@#$%^&*()_-+=:;\"\'\\| []{}");
            }
        }
            
    fclose(input); 
    printf("%s /n", "word___number of total occ_____number of casesensitive occ\n"); 
    print(tree); 
    }/*IF END*/ 
  
    else 
        printf("%s", "put in a proper file numbskull");  
} 
