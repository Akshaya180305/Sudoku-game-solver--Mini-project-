#include <stdio.h>

int arr[9][9];

// Function to print Sudoku in the original format
void pSudoku() {
    printf("+-------+-------+-------+\n");
    for (int i = 0; i < 9; i++) {
        printf("| ");
        for (int j = 0; j < 9; j++) {
            printf("%d ", arr[i][j]);
            if ((j + 1) % 3 == 0)
                printf("| ");
        }
        printf("\n");
        if ((i + 1) % 3 == 0)
            printf("+-------+-------+-------+\n");
    }
}

// Check if placing num at arr[row][col] is allowed
int check(int row, int col, int num) {
    for (int x = 0; x < 9; x++) {
        if (arr[row][x] == num) return 0;
        if (arr[x][col] == num) return 0;
    }
    int iRow = row - (row % 3);
    int iCol = col - (col % 3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (arr[iRow + i][iCol + j] == num)
                return 0;
        }
    }
    return 1;
}



// Sudoku solving using backtracking
int solve() {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (arr[row][col] == 0) {
                for (int num = 1; num <= 9; num++) {
                    if (check(row, col, num)) {
                        arr[row][col] = num;
                        if (solve())
                            return 1;
                        arr[row][col] = 0; // undo
                    }
                }
                return 0; // no valid number found
            }
        }
    }
    return 1; // solved
}

int main() {
    while (1) {
    	char input[10];
        
        printf("\nWant to solve a Sudoku? (y/n): ");
        if (scanf("%s", &input) != 1) {
            printf("Invalid input. Please enter 'y' or 'n'.\n");
            while (getchar() != '\n');  // Clear input buffer
            continue;
        }
        char in=input[0];
        if (in == 'n' || in == 'N') {
            return 0;
        }
        if(in=='y' || in=='Y'){
		
        printf("Enter the Sudoku (0-9 only, 0 for empty cells). Provide all 81 numbers:\n");
        
        int validInput = 1;
        for (int i = 0; i < 9 && validInput; i++) {
            for (int j = 0; j < 9 && validInput; j++) {
                int num;
                if (scanf("%d", &num) != 1) {
                    printf("Invalid input. Please enter numbers only.\n");
                    validInput = 0;
                } else if (num < 0 || num > 9) {
                    printf("Invalid number. Enter 0-9 only.\n");
                    validInput = 0;
                } else {
                    arr[i][j] = num;
                }
            }
        }
        
        if (!validInput) {
            while (getchar() != '\n');  // Clear remaining input
            continue;  // Restart loop
        }
        
        
        
        printf("\nInput Sudoku:\n");
        pSudoku();
        
        if (solve()) {
            printf("\nSolved Sudoku:\n");
            pSudoku();
        } else {
            printf("\nNo solution exists.\n");
        }}else {
        	printf("\n Invalid input! Enter only y or n\n");
		    continue;
		}
    }
    return 0;
}
