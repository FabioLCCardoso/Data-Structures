
//structure for a node

typedef struct node{
 int val;
 struct node *next;
} node;
// structure for the stack

typedef struct {
     node *head;
} MyStack ;


MyStack* myStackCreate() {
    //allocate memorie for the stack
     MyStack* obj =  malloc(sizeof(MyStack ));
    
    //check if memory allocation failed
    if(obj == NULL) {
        return NULL;
    }
    //start the stack as empty
  obj->head = NULL;
    
    return obj;

}

void myStackPush(MyStack* obj, int x) {
    //allocate memory for a new node
     node* newnode = malloc(sizeof(node )); 

     //check if memory allocation failed
     if(newnode == NULL){
        return;
     }
     //set the value of the new node
     newnode->val = x; 
     //point the new node to the current head of the stack
     newnode->next = obj->head; 
     //update the stack's head to the new node 
     obj ->head = newnode;
     
}

int myStackPop(MyStack* obj) {
    //check if the stack is empty
    if (obj -> head == NULL ){
        printf("this stack doesn't exist " );
        exit(EXIT_FAILURE);
    }
    //get the top node's value 
    int y = obj -> head ->val;
    //save the current top node 
    node *temp = obj->head;
    // move the head pointer to the next node
    obj->head = obj->head->next;
    //free memory of popped node
    free(temp);
    //return popped value
    return y; 
}

int myStackTop(MyStack* obj) {
    //check if the stack is empty
    if(obj->head == NULL){
        return 0;
    }
    //get the value of the top node
    int z = obj->head->val ;
    //return the value of the top node
    return z;
}

bool myStackEmpty(MyStack* obj) {
    //checks if the stack is empty 
    if(obj->head == NULL){
        return true;
    }
    else return false;
}

void myStackFree(MyStack* obj) {
    //loop through the nodes of the stack
    node *current = obj->head;
    while(current != NULL){
        //save the next node
        node*next = current->next;
        //free the memory of current node
        free(current);
        //move to the next node
        current=next;

    }
    //free the stack's memory
    free(obj);
}


/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/