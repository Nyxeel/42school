#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define SIZE 6

int count_visible(int *arr) {
    int max_height = 0, count = 0, i = 0;
    while (i < SIZE) {
        if (arr[i] > max_height) {
            count++;
            max_height = arr[i];
        }
        i++;
    }
    return count;
}

bool is_valid_latin_square(int grid[SIZE][SIZE]) {
    int i = 0;
    while (i < SIZE) {
        bool row_check[SIZE + 1] = {false};
        bool col_check[SIZE + 1] = {false};
        int j = 0;
        while (j < SIZE) {
            if (row_check[grid[i][j]] || col_check[grid[j][i]]) return false;
            row_check[grid[i][j]] = true;
            col_check[grid[j][i]] = true;
            j++;
        }
        i++;
    }
    return true;
}

void generate_latin_squares(int squares[576][SIZE][SIZE]) {
    int count = 0;
    int perm[SIZE] = {1, 2, 3, 4, 5, 6};
    while (count < 576) {
        int grid[SIZE][SIZE];
        int i = 0;
        while (i < SIZE) {
            int j = 0;
            while (j < SIZE) {
                grid[i][j] = perm[(i + j) % SIZE];
                j++;
            }
            i++;
        }
        if (is_valid_latin_square(grid)) {
            i = 0;
            while (i < SIZE) {
                int j = 0;
                while (j < SIZE) {
                    squares[count][i][j] = grid[i][j];
                    j++;
                }
                i++;
            }
            count++;
        }
    }
}

void generate_clues(int grid[SIZE][SIZE], int top[SIZE], int bottom[SIZE], int left[SIZE], int right[SIZE]) {
    int i = 0;
    while (i < SIZE) {
        top[i] = count_visible(grid[i]);
        bottom[i] = count_visible(grid[SIZE - 1 - i]);
        int col[SIZE], rev_col[SIZE];
        int j = 0;
        while (j < SIZE) {
            col[j] = grid[j][i];
            rev_col[j] = grid[SIZE - 1 - j][i];
            j++;
        }
        left[i] = count_visible(col);
        right[i] = count_visible(rev_col);
        i++;
    }
}

int main() {
    srand(time(NULL));
    int (*squares)[SIZE][SIZE] = malloc(576 * SIZE * SIZE * sizeof(int));
    generate_latin_squares(squares);
    
    int index = rand() % 576;
    int *top = malloc(SIZE * sizeof(int));
    int *bottom = malloc(SIZE * sizeof(int));
    int *left = malloc(SIZE * sizeof(int));
    int *right = malloc(SIZE * sizeof(int));
    
    generate_clues(squares[index], top, bottom, left, right);
    
    write(1, "Generated 6x6 Latin Square:\n", 27);
    int i = 0;
    while (i < SIZE) {
        int j = 0;
        while (j < SIZE) {
            char buffer[2];
            buffer[0] = '0' + squares[index][i][j];
            buffer[1] = ' ';
            write(1, buffer, 2);
            j++;
        }
        write(1, "\n", 1);
        i++;
    }
    
    write(1, "\nTop Clues:    ", 15);
    i = 0;
    while (i < SIZE) {
        char buffer[2];
        buffer[0] = '0' + top[i];
        buffer[1] = ' ';
        write(1, buffer, 2);
        i++;
    }
    write(1, "\nBottom Clues: ", 16);
    i = 0;
    while (i < SIZE) {
        char buffer[2];
        buffer[0] = '0' + bottom[i];
        buffer[1] = ' ';
        write(1, buffer, 2);
        i++;
    }
    write(1, "\nLeft Clues:   ", 15);
    i = 0;
    while (i < SIZE) {
        char buffer[2];
        buffer[0] = '0' + left[i];
        buffer[1] = ' ';
        write(1, buffer, 2);
        i++;
    }
    write(1, "\nRight Clues:  ", 15);
    i = 0;
    while (i < SIZE) {
        char buffer[2];
        buffer[0] = '0' + right[i];
        buffer[1] = ' ';
        write(1, buffer, 2);
        i++;
    }
    write(1, "\n", 1);
    
    free(squares);
    free(top);
    free(bottom);
    free(left);
    free(right);
    
    return 0;
}

