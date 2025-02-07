/*
232
Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

Implement the MyQueue class:

    void push(int x) Pushes element x to the back of the queue.
    int pop() Removes the element from the front of the queue and returns it.
    int peek() Returns the element at the front of the queue.
    boolean empty() Returns true if the queue is empty, false otherwise.

Notes:

    You must use only standard operations of a stack, which means only push to top, peek/pop from top, size, and is empty operations are valid.
    Depending on your language, the stack may not be supported natively. You may simulate a stack using a list or deque (double-ended queue) as long as you use only a stack's standard operations.

*/





typedef struct node{
 int val;
 struct node *next;
} node;

typedef struct {
     node *head;
} Stack ;

//initialize stack 

void initStack(Stack *s) {
    s->head = NULL;
}

bool isStackEmpty(Stack *s){
    return s->head == NULL;
}

//push into the stack
void push(Stack *s, int x){
    node *newNode = (node *)malloc(sizeof(node));

    if(!newNode){
        exit(EXIT_FAILURE);
    }
    newNode->val = x;
    //link new node to the head
    newNode->next = s->head;
    //update head of the stack
    s->head = newNode;
}

//pop from stack

int pop(Stack *s){
    if(isStackEmpty(s)){
        exit(EXIT_FAILURE);
    } 

    // store reference to top node
    node *temp = s->head;
    //get node's value
    int value = temp->val;
    //move head to next node 
    s->head = temp->next;
    free(temp);
    //return popped value
    return value;
}
    //returns head value 
int peek(Stack *s){
    if (isStackEmpty(s)){
        exit(EXIT_FAILURE);
    }
    return s->head->val;
}

void freeStack(Stack *s){
    while (!isStackEmpty(s)){
        pop(s);
    }
}

    //queue using stacks
typedef struct {
    Stack s1, s2;
} MyQueue;

    //create a queue
MyQueue* myQueueCreate() {

MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));

    if (!obj){
        exit(EXIT_FAILURE);
    }

    //initialize both stacks
    initStack(&obj->s1);
    initStack(&obj->s2);
    
    return obj;

}
    //push element to the back of the queue
void myQueuePush(MyQueue* obj, int x) {
    
    //push element to s1
    push(&obj->s1, x);
}
    //pop (remove) element from the front of the queue
int myQueuePop(MyQueue* obj) {

    //if s2 is empty, move elements from s1 to s2.
    if (isStackEmpty(&obj->s2)){
        //while there's an element in s1, moves all elements from s1 to s2
        while(!isStackEmpty(&obj->s1)){
            push(&obj->s2, pop(&obj->s1));
        }
    }
    //pop the head of s2
    return pop(&obj->s2);
}

// "peeks" the front element
int myQueuePeek(MyQueue* obj) {
    //if s2 is empty, move elements from s1 to s2
    if (isStackEmpty(&obj->s2)){
        while(!isStackEmpty(&obj->s1)){
            push(&obj->s2, pop(&obj->s1));
        }
    }
    //return the top of s2 without popping it
    return peek(&obj->s2);
}

// checks if the queue is empty
bool myQueueEmpty(MyQueue* obj) {
    return isStackEmpty(&obj->s1) && isStackEmpty(&obj->s2);
}

//free the queue's memory
void myQueueFree(MyQueue* obj) {
    freeStack(&obj->s1);
    freeStack(&obj->s2);
    free(obj);

}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/