#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

#define BUFFER_SIZE 100
#define HELP "-h"
#define DELIMS ",./<>?`~!@#$%^&*()_-+=:;\"\'\\| []{}"

typedef struct LLNode {
    char *word;
    struct LLNode *next;
} LLNode;

typedef struct BST {
    char *word;
    int no;
    int nc;
    struct BST *left;
    struct BST *right;
    struct LLNode *next;
} BST;

void find(LLNode **, BST **, char *);
void insert(BST **, char *);
void add(LLNode **, BST **, char *);
BST * search(BST **, char *);

/*Pre: Takes a string, and takes it from specific point to end.
 *Post: Returns the substring
 */

char * substring(const char *str, size_t begin, size_t len) {
    if (!str || !strlen(str) || strlen(str) < begin || strlen(str) < begin + len) {
        return 0;
    }

    return strndup(str + begin, len);
}

/*Pre: Takes a string, finds first letter for use in substring and insert
 *Post: Returns the index of the first letter
 */

int find_letter(const char *str) {
    int i;
    for (i = 0; i < strlen(str); i++) {
        if (!isdigit(str[i])) {
            return i;
        }
    }

    return -1;
}

/*Pre: Takes a BST and word
 *Post: Puts word in BST, makes root if null
 */

void insert(BST **root, char *data) {
    BST *node = (BST *) malloc(sizeof(struct BST));
    LLNode *next = (LLNode *) malloc(sizeof(LLNode));
    if (!(*root)) {
        node->word = (char *) malloc(sizeof(char));
        strcpy(node->word, data);
        node->no = 1;
        node->nc = 1;
        node->left = NULL;
        node->right = NULL;
        node->next = NULL;
        *root = node;
    } else {
        int comp = strcmp((*root)->word, data);
        int casecomp = strcasecmp((*root)->word, data);

        if (casecomp < 0) {
            insert(&((*root)->right), data);
        } else if (casecomp > 0) {
            insert(&((*root)->left), data);
        } else {
            (*root)->no++;

            if (comp) {
                (*root)->nc++;
            }

            next = NULL;
            (*root)->next = next;
            find(&(*root)->next, root, data);
        }
    }
}

/*Pre: Finds the data in the linked list from the BST with the given data
 *Post: sends to add if not found, else exits the function
 */

void find(LLNode **node, BST **change, char *data) {
    LLNode *temp = *node;
    while (temp) {
        if (!strcmp((*node)->word, data)) {
            (*change)->nc++;
            return;
        } else {
            temp = temp->next;
        }
    }

    add(&temp, change, data);
}

/*Pre: takes a new empty linked list, adds to the BST with the data
 *Post: none, just adds.
 */

void add(LLNode **new, BST **add, char *data) {
    if (!(*new)) {
        *new = (LLNode *) malloc(sizeof(LLNode));
        (*new)->word = (char *) malloc(sizeof(char));
        (*new)->next = NULL;
    }

    strcpy((*new)->word, data);
}


/*Pre: Displays help
 *Post: None
 */

void help() {
    printf("%s", "You have accessed the help menu\n");
    printf("%s", "This menu will be discussing the following: \n");
    printf("%s", "\t1. How to use the program\n\t2. How the program works\n");
    printf("%s", "\t3. Credits\n");
    printf("%s", "\t\t1. How to Use\n");
    printf("%s", "This program is designed to count words in your very own input.txt. You enter the file name, and the program is designed to count the words that are both case sensitive and case insensitive (or total).\n\n");
    printf("%s", "\t\t2. How it Works\n");
    printf("%s", "This program works by using C's built in stdlib.h and stdio.h and strng.h (standard library and standard input/out and string functions) to:\n A. Read in the file and text from your keyboard.\n B. Compare each word in the txt file to all of the others.\n\n");
    printf("%s", "This program uses a Binary Search Tree, in addition to a Linked List. Each node represents one version of a word, and inside each node of the linked list is every other version that appears in the txt file. We use a BST and a Linked List due to speed and it is easy to understand.\n\n");
    printf("%s", "\t\t3. Credits\n");
    printf("%s", "This program was written by Matt Klein of Rutgers University for CS211\n");
    
}


/*Pre: Takes a BST and displays it
 *Post: None
 *
 */

void print(BST *node) {
    if (!node) {
        return;
    }

    print(node->left);
    printf("%-20s%10d%20d\n", node->word, node->no, node->nc);
    print(node->right);
}

/*Pre: Takes a tree to free
 *Post: Free memory!
 */
void clear(BST *node) {
    struct LLNode *temp = node->next;

    if (!node) {
        return;
    }

    clear(node->left);
    clear(node->right);

    free(node->word);
    free(node->left);
    free(node->right);
    
    for (; temp != NULL; temp = node->next) {
        free(temp->word);
        free(temp);
    }
}


int main(int argc, char *argv[]) {
    FILE *fp;

    char buffer[BUFFER_SIZE];    char *token;

    /*printf("Enter a file name (-h for help) : ");
    scanf("%s", input);*/


    BST *root = (BST *) malloc(BUFFER_SIZE + (sizeof(BST)) + 1);

    fp = fopen(argv[1], "r");
    
    if (argc < 2) {
        fprintf(stderr, "No arguments passed.\n");
        exit(EXIT_FAILURE);
    }

    if (strcmp(argv[1], HELP) == 0) {
        help();
        exit(EXIT_FAILURE);
    }

    if (!fp) {
        fprintf(stderr, "Could not open input file.\n");
        exit(EXIT_FAILURE);
    }

    root = NULL;

    while (fgets(buffer, sizeof(buffer) / sizeof(char), fp)) {
        int len = strlen(buffer);
        if (buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        }

        token = strtok(buffer, DELIMS);
        while (token) {
            if (isdigit(token[0])) {
                int first_letter = find_letter(token);
                char *new_token = (char *) malloc(strlen(token) - first_letter);
                strcpy(new_token, substring(token, first_letter, strlen(token) - first_letter));
                
                insert(&root, new_token);
            } else {
                insert(&root, token);
            }

            token = strtok(NULL, DELIMS);
        }
    }

    if (root) {
        printf("%-20s%10s%20s\n", "Word", "Occurrences", "Case Occ.");
        printf("%-20s%10s%20s\n", "----", "-----------", "---------");
        print(root);
    }

    fclose(fp);
    clear(root);

    return 0;
}

