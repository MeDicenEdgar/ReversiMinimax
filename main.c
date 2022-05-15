#include <stdio.h>
#include "stdbool.h"
#include "raylib.h"
#include "functions.h"
int main() {
    int board[10][10]={//This is the board
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
    const int screenHeight = 700;//We define the constants used for reylib
    InitWindow(screenWidth, screenHeight, "Reversi Game");
    SetTargetFPS(5);
    printBoard(board);
    int turn = 1;
    int state = 1;
    int end = 0;
    while(!WindowShouldClose()) {

        if(turn == 1 && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){//If it's players turn and the mouse is pressed
            turn = mouseValidation(board, GetMouseX(), GetMouseY(), screenHeight, screenWidth);//Validates a player input
        }
        else if(turn==2){//If it's AI's turn
            turn = mainGame(board, 2, 0, 0);//calls the game directly
        } else{
            if(hasGameEnded(board, 1, 0)==3){
                turn = 3;//Stops the loop. there is no condition for a turn = 3
                end = endgame(board, checkWinner(board), screenWidth, screenHeight);
            }
            else if(hasGameEnded(board, 1, 0)==2){
                turn = changeTurn(turn);
            }
        }
        BeginDrawing();//Raylib
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
//Credits to https://github.com/MeDicenEdgar



