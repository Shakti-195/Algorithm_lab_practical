// practical 8
// implement 8 queens problem (backtracking)
#include <stdio.h>

#define MAX 20

int board[MAX], count = 0;
int col[MAX], diag1[2*MAX], diag2[2*MAX];

void print(int n) {
    printf("\nSolution %d:\n", ++count);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(board[i] == j)
                printf(" Q ");
            else
                printf(" - ");
        }
        printf("\n");
    }
}

void queen(int row, int n) {
    for(int c = 0; c < n; c++) {
        if(!col[c] && !diag1[row - c + n] && !diag2[row + c]) {
            
            // place queen
            board[row] = c;
            col[c] = diag1[row - c + n] = diag2[row + c] = 1;

            if(row == n - 1)
                print(n);
            else
                queen(row + 1, n);

            // backtrack
            col[c] = diag1[row - c + n] = diag2[row + c] = 0;
        }
    }
}

int main() {
    int n;
    printf("- N Queens Problem (Optimized) -\n");
    printf("Enter number of queens: ");
    scanf("%d", &n);

    queen(0, n);

    printf("\nTotal solutions: %d\n", count);
    return 0;
}