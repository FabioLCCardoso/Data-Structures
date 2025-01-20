
typedef struct node{
 int val;
 struct node *next;
} node;

typedef struct {
     node *head;
} MyStack ;


MyStack* myStackCreate() {

     MyStack* obj =  malloc(sizeof(MyStack ));
    
    if(obj == NULL) {
        return NULL;
    }
  obj->head = NULL;

    return obj;

}

void myStackPush(MyStack* obj, int x) {
     node* newnode = malloc(sizeof(node )); 
     if(newnode == NULL){
        return;
     }
     newnode->val = x; 
     newnode->next = obj->head; 
     obj ->head = newnode;
     
}

int myStackPop(MyStack* obj) {
    if (obj -> head == NULL ){
        printf("this stack doesn't exist " );
        exit(EXIT_FAILURE);
    }
    int y = obj -> head ->val;
    node *temp = obj->head;
    obj->head = obj->head->next;
    free(temp);

    return y; 
}

int myStackTop(MyStack* obj) {
    
    if(obj->head == NULL){
        return 0;
    }
    int z = obj->head->val ;
    return z;
}

bool myStackEmpty(MyStack* obj) {
    if(obj->head == NULL){
        return true;
    }
    else return false;
}

void myStackFree(MyStack* obj) {
    node *current = obj->head;
    while(current != NULL){
        node*next = current->next;
        free(current);
        current=next;

    }
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