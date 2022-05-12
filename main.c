#include <stdio.h>
#include "stdbool.h"
#include "raylib.h"
#include "functions.h"
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
    const int screenWidth = 700;
    const int screenHeight = 700;
    InitWindow(screenWidth, screenHeight, "Reversi Game");
    SetTargetFPS(5);
    printBoard(board);
    int turn = 1;
    int state = 1;
    int end = 0;
    while(!WindowShouldClose()) {

        if(turn == 1 && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            turn = mouseValidation(board, GetMouseX(), GetMouseY(), screenHeight, screenWidth);
        }
        else if(turn==2){
            turn = mainGame(board, 2, 0, 0);
        } else{
            if(hasGameEnded(board, 1, 0)==3){
                turn = 3;
                end = endgame(board, checkWinner(board), screenWidth, screenHeight);
            }
            else if(hasGameEnded(board, 1, 0)==2){
                turn = changeTurn(turn);
            }
        }
        BeginDrawing();
        ClearBackground(BLACK);
        drawBoard(screenWidth, screenHeight);
        currentTurn(turn, screenHeight, screenWidth);

        drawPieces(board, screenWidth, screenHeight);
        displayNumberOfPieces(board, screenWidth, screenHeight);

        if(turn==1){
            drawAvailableMoves(board, screenWidth, screenHeight);
        }else if(turn == 3)
        {
            DrawEndgame(end, screenWidth, screenHeight);
        }
        EndDrawing();
    }
    CloseWindow();
    return 0;
}




