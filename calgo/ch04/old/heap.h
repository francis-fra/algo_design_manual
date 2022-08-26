#define PQ_SIZE 10
enum heapType {min_heap = 1, max_heap = 0}; 
typedef int itemType;

typedef struct {
    enum heapType type;
    itemType buffer[PQ_SIZE-1];
    int size;
} priority_queue;

// get the array index of the parent
int pq_parent(int n); 
// get the young children index
int pq_young_child(int n); 
void pq_insert(priority_queue *q, itemType item);
void swap(itemType arr[], int a, int b);

void pq_show(priority_queue *q);

void bubble(priority_queue *q, int p, int (*f) (itemType, itemType));
void bubble_up(priority_queue *q, int p);
void bubble_down(priority_queue *q, int p);

void bubble_root(priority_queue *q, int p, int (*f) (itemType, itemType));

void pq_init(priority_queue *q, enum heapType type);
void make_heap(priority_queue *q, itemType a[], int n);

int greater_than(itemType a, itemType b);
int less_than(itemType a, itemType b);

itemType find_min(priority_queue *q);
itemType find_max(priority_queue *q);

/* itemType extract_min(priority_queue *q); */
itemType extract_root(priority_queue *q);

void heap_sort(itemType s[], int n, int direction);
