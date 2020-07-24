typedef int itemType; 

typedef struct list {
    itemType item;
    struct list *next;
} list;

void insert_list(list **lst, itemType item);
list* create_list(itemType item);
void traverse_list2(list *lst);
void free_list(list *lst);
void traverse_list(list *lst, void (*f)(list*));
void print_item(list *lst);
void free_item(list *lst);
void inc_item(list *lst);
list *predecessor(list *lst, itemType item);
void delete_list(list **lst, itemType item);

