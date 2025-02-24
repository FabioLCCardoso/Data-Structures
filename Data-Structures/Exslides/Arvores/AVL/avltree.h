
typedef struct Node *AVLtree;

int insert_AVL(AVLtree *root, int val);

int remove_AVL(AVLtree *root, int val);

struct Node *searchmin(struct Node* curr);