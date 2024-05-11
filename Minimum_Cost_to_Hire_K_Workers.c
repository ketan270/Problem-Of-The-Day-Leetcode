////////////////// Max heap implementation /////////////
struct maxheap {
	int *harr; 	int capacity; 	int size;
};
typedef struct maxheap MaxHeap;

int top(MaxHeap *heap)  {  return heap->harr[0]; } 
int parent(int i ) {      return (i-1)/2;  } 
int left(int i) {      return (2*i + 1);  } 
int right(int i) {     return (2*i + 2);  } 
int size(MaxHeap *heap) {     return heap->size; } 
void swap(int *a, int *b) {		    if (a != b) {  int temp = *a;  *a = *b;  *b = temp; }   }

void maxHeapify(MaxHeap *heap, int i) { 
    int l = left(i);    int r = right(i);    int largest = i; 
    if (l < heap->size && heap->harr[l] > heap->harr[i]) 
        largest = l; 
    if (r < heap->size && heap->harr[r] > heap->harr[largest]) 
        largest = r; 
    if (largest != i) { 
        swap(&heap->harr[i], &heap->harr[largest]); 
        maxHeapify(heap, largest);
    } 
} 

MaxHeap *createMaxHeap(int n) {
	MaxHeap *heap = malloc(sizeof(MaxHeap));
	heap->harr = malloc(sizeof(int) * n); 
    heap->size = 0;  heap->capacity = n; 
    return heap;
}

void push(MaxHeap *heap, int k) { 
    heap->size++; 
    int i = heap->size - 1; 
    heap->harr[i] = k; 
  
    while (i != 0 && heap->harr[parent(i)] < heap->harr[i]) { 
        swap(&heap->harr[i], &heap->harr[parent(i)]); 
        i = parent(i); 
    } 
} 
  
int pop(MaxHeap *heap) { 
    if (heap->size <= 0)    return INT_MAX; 
    if (heap->size == 1) {  heap->size--;   return heap->harr[0]; } 
  
    int max = heap->harr[0];      heap->harr[0] = heap->harr[heap->size-1]; 
    heap->size--;     maxHeapify(heap, 0); 
    return max; 
} 
///////////////// End max heap ///////////////////

#include<float.h>       // DBL_MAX

typedef struct {
    double wByQ;
    int qual;
} wqPair;

int cmp(const void *pa, const void *pb) {
    wqPair *a = (wqPair *)pa;
    wqPair *b = (wqPair *)pb;
    return a->wByQ < b->wByQ ? -1 : 1;
}

double mincostToHireWorkers(int* quality, int qualitySize, int* wage, int wageSize, int k){
    double totalCost = DBL_MAX, curTotal = 0;
    wqPair *ratio = calloc(sizeof(wqPair), qualitySize);
    
    for(int i = 0; i < qualitySize; i++) {
        ratio[i].wByQ = ((double)wage[i]) / quality[i];
        ratio[i].qual = quality[i];
    }
    
    // sort accorting to ratio (wage/quality of worker)
    qsort(ratio, qualitySize, sizeof(ratio[0]), cmp);
    
    MaxHeap *heap = createMaxHeap(k + 1);
    // printf("created minhepa of k\n");
    for(int i = 0; i < qualitySize; i++) {
        push(heap, ratio[i].qual);
        curTotal += ratio[i].qual;
        
        // Not more than k workers are considered
        if(size(heap) > k) {
            curTotal -= pop(heap);
        }
        
        if(size(heap) == k) {
            totalCost = fmin(totalCost, curTotal * ratio[i].wByQ);            
        }
    }
    return totalCost;
}
