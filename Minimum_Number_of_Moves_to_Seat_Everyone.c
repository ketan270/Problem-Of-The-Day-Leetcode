int cmpFunc(const void* a, const void* b){ return *(int*)a - *(int*)b; }

int minMovesToSeat(int* seats, int seatsSize, int* students, int studentsSize) {
    int result=0;

    qsort(seats, seatsSize, sizeof(int), cmpFunc);
    qsort(students, studentsSize, sizeof(int), cmpFunc);
    for(int i=0; i<seatsSize; i++){ result+=abs(seats[i]-students[i]); }

    return result;
}
