#define tablesize 100003

typedef struct node {
    int value;
    int index;
    struct node* next;
} NODE;

bool exist_node(NODE** table, int num, int origin_index) {
    int table_index = num % tablesize;
    NODE* ptr = table[table_index];
    while (ptr) {
        if (ptr->value == num)
            return true;
        ptr = ptr->next;
    }
    return false;
}

int find_index(NODE** table, int num) {
    int table_index = num % tablesize;
    NODE* ptr = table[table_index];
    while (ptr) {
        if (ptr->value == num)
            return ptr->index;
    }
    return 0;
}

void create_node(NODE** table, int num, int origin_index) {
    int table_index = num % tablesize;
    NODE* newnode = (NODE*)malloc(sizeof(NODE));
    newnode->value = num;
    newnode->index = origin_index;
    newnode->next = table[table_index];
    table[table_index] = newnode;
}

bool checkSubarraySum(int* nums, int numsSize, int k) {
    NODE** table = (NODE**)calloc(tablesize, sizeof(NODE*));
    create_node(table, 0, -1);
    int sum = 0;
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
        int mod = sum % k;
        if (exist_node(table, mod, i)) {
            int pre_index = find_index(table, mod);
            if (i - pre_index > 1)
                return true;
        } else {
            create_node(table, mod, i);
        }
    }
    return false;
}
