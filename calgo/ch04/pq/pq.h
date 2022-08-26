#define MAX_PQ_SIZE 20

// min heap: ascending order
typedef struct PQ
{
    int size;
    int queue[MAX_PQ_SIZE];
} PQ;

// get the array index of the parent
int pq_parent(int n); 
// get the young children index
int pq_left_child(int n); 
int pq_right_child(int n); 

void pq_insert(PQ *q, int item);
void swap(int arr[], int a, int b);

PQ* pq_init();
void print_pq(PQ* pq);

void bubble_up(PQ *pq, int p);
int pq_extract(PQ* pq);
void bubble_down(PQ *pq, int idx);

// in place sorting
void heap_sort(int arr[], int n);
PQ* make_heap(int arr[], int size);

// improved version
PQ* fast_make_heap(int arr[], int size);
void fast_heap_sort(int arr[], int n);


void print_array(int arr[], int size);