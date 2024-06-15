typedef struct s_job{
    int profit;
    int capital;
}   t_job;

int heap_size;
int *heap;

#define parent(i) ((i - 1) / 2)
#define left_child(i) (i * 2 + 1)
#define right_child(i) (i * 2 + 2)

void merge(int l, int m, int r, t_job *job)
{
    int left = m - l + 1;
    int right = r - m;
    t_job L[left], R[right];
    int i, j, k;

    for (i = 0; i < left; i++)
        L[i] = job[l + i];
    for (i = 0; i < right; i++)
        R[i] = job[m + i + 1];
    i = 0, j = 0, k = l;
    while (i < left && j < right)
        if (L[i].capital < R[j].capital)
            job[k++] = L[i++];
        else
            job[k++] = R[j++];
    while (i < left)
        job[k++] = L[i++];
    while (j < right)
        job[k++] = R[j++];
}
void merge_sort(int l, int r, t_job *job)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        merge_sort(l, m, job);
        merge_sort(m + 1, r, job);
        merge(l, m, r, job);
    }
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void shift_up(int i)
{
    while (i > 0 && heap[parent(i)] < heap[i])
    {
        swap(&heap[parent(i)], &heap[i]);
        i = parent(i);
    }
}

void push_job(t_job job)
{
    heap[heap_size++] = job.profit;
    shift_up(heap_size - 1);
}

void shift_down(int i)
{
    int max = i;
    int l = left_child(i);
    int r = right_child(i);

    if (l < heap_size && heap[l] > heap[max])
        max = l;
    if (r < heap_size && heap[r] > heap[max])
        max = r;
    if (max != i)
    {
        swap(&heap[i], &heap[max]);
        shift_down(max);
    }
}

int pop_job(void)
{
    int res = heap[0];

    heap[0] = heap[--heap_size];
    shift_down(0);
    return (res);
}

int findMaximizedCapital(int k, int w, int* profits, int profitsSize, int* capital, int capitalSize) {
    int i = 0;
    int jobs_index = 0;
    int money = w;

    heap_size = 0;
    heap = malloc(sizeof(int) * profitsSize);
    t_job *job = malloc(sizeof(t_job) * profitsSize);
    while (i < profitsSize)
    {
        job[i].profit = profits[i];
        job[i].capital = capital[i];
        i++;
    }
    merge_sort(0, profitsSize - 1, job);
    while (k-- > 0)
    {
        while (jobs_index < profitsSize && job[jobs_index].capital <= money)
            push_job(job[jobs_index++]);
        if (heap_size == 0)
            break ;
        money += pop_job ();
    }
    return (money);
}
