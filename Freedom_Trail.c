#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    int min_steps;
    int pos;
} Pair;

int helper(int in_index, int pos, int positions[26][MAX_SIZE], char* key, char* ring, int memo[MAX_SIZE][MAX_SIZE]) {
    if (key[in_index] == '\0') {
        return 0;
    }
    if (memo[in_index][pos] != -1) {
        return memo[in_index][pos];
    }
    int min_steps = __INT_MAX__;
    for (int i = 0; i < MAX_SIZE; i++) {
        if (positions[key[in_index] - 'a'][i] != -1) {
            int steps;
            if (positions[key[in_index] - 'a'][i] >= pos) {
                steps = positions[key[in_index] - 'a'][i] - pos;
                steps = steps < (pos + strlen(ring) - positions[key[in_index] - 'a'][i]) ? steps : (pos + strlen(ring) - positions[key[in_index] - 'a'][i]);
            } else {
                steps = pos - positions[key[in_index] - 'a'][i];
                steps = steps < (positions[key[in_index] - 'a'][i] + strlen(ring) - pos) ? steps : (positions[key[in_index] - 'a'][i] + strlen(ring) - pos);
            }
            int next_steps = helper(in_index + 1, positions[key[in_index] - 'a'][i], positions, key, ring, memo);
            min_steps = (steps + next_steps) < min_steps ? (steps + next_steps) : min_steps;
        }
    }
    memo[in_index][pos] = min_steps + 1;
    return min_steps + 1;
}

int findRotateSteps(char* ring, char* key) {
    int positions[26][MAX_SIZE];
    memset(positions, -1, sizeof(positions));
    for (int i = 0; ring[i] != '\0'; i++) {
        positions[ring[i] - 'a'][i] = i;
    }
    int memo[MAX_SIZE][MAX_SIZE];
    memset(memo, -1, sizeof(memo));
    return helper(0, 0, positions, key, ring, memo);
}
