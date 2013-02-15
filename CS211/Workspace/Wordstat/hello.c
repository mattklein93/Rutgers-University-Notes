#include <stdio.h>
struct BST{
    char* word;
    //LLNode * front;
    int numOccur;
    int numCaseOccur;
    struct BST* left;
    struct BST* right;
};

int main() {
    struct BST* name = {"", 0, 0, 0, 0};
    return 0;
}
