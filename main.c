#include <stdio.h>
#include "stdbool.h"
#include "functions.h"



bool isPossibleMove(int board[10][10], int xpos, int ypos, int player);
bool hasGameEnded(int board[10][10], int player);
void makeMove(int board[10][10], int xpos, int ypos, int player);
void printBoard(int board[10][10]);
void copyBoard(int board[10][10], int tempBoard[10][10]);
Stats checkWinner(int board[10][10]);
Move minimaxMove(int board[10][10]);
int getValue(int board[10][10], Move move);
Move getBestMove(int board[10][10], Move moves[64], int count);

int main() {
    int board[10][10]={
            {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
            {-1,0,0,0,0,0,0,0,0,-1},
            {-1,0,0,0,0,0,0,0,0,-1},
            {-1,0,0,0,0,0,0,0,0,-1},
            {-1,0,0,0,1,2,0,0,0,-1},
            {-1,0,0,0,2,1,0,0,0,-1},
            {-1,0,0,0,0,0,0,0,0,-1},
            {-1,0,0,0,0,0,0,0,0,-1},
            {-1,0,0,0,0,0,0,0,0,-1},
            {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}
    };
    int xpos;
    int ypos;
    int turn = 1;

    while(hasGameEnded(board, turn)==false){
        if(turn==2){
            printBoard(board);
            printf("----------------------White Move----------------------\n");
            Move move = minimaxMove(board);
            makeMove(board, move.x, move.y, 2);
            turn=1;
        } else{
            printBoard(board);
            printf("----------------------Black Move----------------------\n");
            scanf("%d %d", &xpos, &ypos);
            if (isPossibleMove(board, xpos, ypos, turn)==true){
                makeMove(board, xpos, ypos, turn);
            }else{
                printf("That is not a valid movement\n");
                continue;
            }
            turn=2;
        }
    }
    Stats stats = checkWinner(board);
    printf("The game has ended\nBlack has %d pieces\nWhite has %d pieces\nThe winner is %s", stats.bPieces, stats.wPieces, stats.Winner);
    return 0;
}

