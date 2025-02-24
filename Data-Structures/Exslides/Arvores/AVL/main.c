#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "avltree.h" //include the prototype

struct Node{
    int info;
    int height; // subtree's height
    struct Node *left;
    struct Node *right;
};

AVLtree *root; //pointer to pointer


int main(void){
    
//int x = insert_AVL(root, val);
srand(time(0));

for( int i = 0; i<10; i++) {
    int temp = rand() %100;
    insert_AVL(root, temp);
}
//int x = remove_AVL(root, val);

}

int nodeHeight(struct Node* node){
    if (node == NULL){
        return -1;
    }
    else 
    return node->height;

}

int balanceFactor(struct Node* node){
    return labs( nodeHeight ( node->left ) - nodeHeight ( node->right ));
    
}

int Greater( int x, int y){
    if (x > y)
    return x;
    else return y;

}

void LLrotate(AVLtree *root) {
    struct Node *node;

    node = (*root)->left;
    (*root)->left = node->right;
    node->right = *root;
    (*root)->height = Greater(nodeHeight((*root)->left), (*root)->height) + 1;

    *root = node;

}

void RRrotate(AVLtree *root){
    struct Node *node;
    node = (*root)->right;
    (*root)->right = node->left;
    node->left = (*root);
    (*root)->height = Greater(nodeHeight(node->right), (*root)->height) + 1;
    
    (*root) = node;

}

void LRrotate(AVLtree *root){
    RRrotate(&(*root)->left);

    LLrotate(root);

}

void RLrotate(AVLtree *root){
    LLrotate(&(*root)->right);
    
    RRrotate(root);
}

int insert_AVL(AVLtree *root, int val ){
    int answer;

    if(*root == NULL){
        struct Node * new;
        new = (struct Node*)malloc(sizeof(struct Node));
        if( new == NULL) return 0;

        new ->info = val;
        new ->height = 0;
        new ->left = NULL;
        new ->right = NULL;
        *root = new;
        return 1;
    }
    struct Node *curr = *root;
    if(val < curr->info){
        if((answer = insert_AVL(& (curr->left), val))==1){
            if(balanceFactor(curr) >= 2){
                if (val < (*root)->left->info){
                    LLrotate(root);
                }else LRrotate(root);
            }
        }
    }
    else { if( val > curr->info){
        if((answer = insert_AVL(&(curr->right), val))==1){
            if(balanceFactor(curr) >=2){
                if((*root)->right->info < val){
                    RRrotate(root);
                } else{
                    RLrotate(root);
                }
            }
        }
    } else{
        printf("Duplicated val !! \n");
        return 0;
    }
}
    curr->height = Greater(nodeHeight (curr->left), nodeHeight(curr->right)) + 1;
    return answer;
}

int remove_AVL(AVLtree *root, int val){

    if(*root == NULL){
        printf("valor does not exist \n");
        return 0;
    }

    int answer;
    if(val < (*root)->info){
        if((answer = remove_AVL(&(*root)->left, val))==1){
            if(balanceFactor(*root) >= 2){
                if(nodeHeight((*root)->right->left) <=  nodeHeight((*root)->right->right))
                RRrotate(root);
            }
            else RLrotate(root);
        }
    }
    if((*root)->info < val){
        if((answer=remove_AVL(&(*root)->right, val))==1){
            if(balanceFactor(*root) >=2){
                if(nodeHeight((*root)->left->right) <= nodeHeight((*root)->left->left))
                LLrotate(root);
                else LRrotate(root);
            }
        }
    }

    if((*root)->info == val){
        if(((*root)->left == NULL || (*root)->right == NULL)){
            struct Node * oldNode = (*root);
            if((*root) ->left != NULL){
                *root = (*root)->left;
            }else *root = (*root)->right;
            free(oldNode);
        } else{
            struct Node * temp = searchmin((*root)->right);
            (*root) -> info = temp -> info;
            remove_AVL(&(*root)->right, (*root)->info);
            if(balanceFactor(*root) >= 2){
                if(nodeHeight((*root)->left->right) <= nodeHeight((*root)->left->left)){
                    LLrotate(root);
                }else LRrotate(root);
            }
        }
        return 1;
    }
    return answer;
}

struct Node *searchmin(struct Node* curr){
    struct Node *node1 = curr;
    struct Node *node2 = curr->left;

    while(node2 != NULL){
        node1 = node2;
        node2 = node2->left;
    }
    return node1;
}