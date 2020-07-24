typedef int itemType;

typedef struct btree {
    itemType item;
    struct btree *parent;
    struct btree *left;
    struct btree *right;
} btree;

btree* create_bnode(btree* parent, itemType item);
// TODO
// void delete_btree(btree **tree, itemType item);

void insert_btree(btree **tree, btree* parent, itemType item);
void traverse_btree(btree *tree, void (*f)(btree *));
void print(btree *b);
void dble(btree *b);

// TODO:
btree *search_tree(btree *tree, itemType item);
itemType minTreeVal(btree *b);
itemType maxTreeVal(btree *b);

void copy_tree(btree *b, btree *c);
void copy_btree(btree **b, btree *c);