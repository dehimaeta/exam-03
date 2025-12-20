#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int is_valid(int *board, int row, int col)
{
    int i = 0;
    while (i < row)
    {
        if (col == board[i] || (board[i] - col == i - row) || (board[i] - col == row - i))
            return 0;
        i++;
    }
    return 1;
}

void solve_nqueens(int size, int *board, int row)
{
    int i;
    int col = 0;
    
    if (row == size)
    {
        i = 0;
        while (i < size)
        {
            fprintf(stdout, "%d", board[i]);
            if (i < size - 1)
                fprintf(stdout, " ");
            i++;
        }
        fprintf(stdout, "\n");
        return ;
    }
    while (col < size)
    {
        if (is_valid(board, row, col))
        {
            board[row] = col;
            solve_nqueens(size, board, row + 1);
        }
        col++;
    }
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return 1;
    int size;
    size = atoi(argv[1]);
    if (size <= 0)
        return 1;
    int *board;
    board = calloc(size, sizeof(int));
    if (!board)
        return 1;
    solve_nqueens(size, board, 0);
    free(board);
}