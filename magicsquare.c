int isLoShu(int square[3][3]) {
    int i, j;
    int alreadyUsed[10] = {0}; 
    int rowSum[3] = {0};
    int columnSum[3] = {0};
    int diagonalSum[2] = {0};

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) 
        {
            int val = square[i][j];
            
            if (val < 1 || val > 9) {
                return 0; 
            }

            if (alreadyUsed[val] == 1) {
                return 0; 
            }

            alreadyUsed[val] = 1;
        }
    }

    for (i = 0; i < 3; i++) 
    {
        for (j = 0; j < 3; j++) 
        {
            rowSum[i] += square[i][j];
            columnSum[j] += square[i][j];

            if (i == j) {
                diagonalSum[0] += square[i][j];  
            }

            if (i + j == 2) {
                diagonalSum[1] += square[i][j];  
            }
        }
    }

    for (i = 0; i < 3; i++) 
    {
        if (rowSum[i] != 15 || columnSum[i] != 15) 
        {
            return 0;
        }
    }

    if (diagonalSum[0] != 15 || diagonalSum[1] != 15) 
    {
        return 0;
    }

    return 1;
}

void printSquare(int square[3][3]) {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", square[i][j]);
        }
        printf("\n");
    }
}

void fillRandomSquare(int square[3][3]) {
    int used[10] = {0}; // Track numbers 1..9
    int i, j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            int r;
            do {
                r = rand() % 9 + 1; // Random number between 1 and 9
            } while (used[r] == 1); // If already used, pick again
            used[r] = 1;
            square[i][j] = r;
        }
    }
}