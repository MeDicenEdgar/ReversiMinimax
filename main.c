#include <stdio.h>
#include "stdbool.h"
typedef struct struct_Move{
    int x;
    int y;
    struct struct_Move *PossibleMoves[30];
}Move;
bool isPossibleMove(int board[10][10], int xpos, int ypos, int player);
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
    scanf("%d %d", &xpos, &ypos);
    isPossibleMove(board, xpos, ypos, 1);
    return 0;
}
bool isPossibleMove(int board[10][10], int xpos, int ypos, int player){
    if(board[xpos][ypos]!=0){
        return false;
    }
    int i = 1;
    bool possible=false;
    if((board[xpos][ypos-i]!=player)&&(board[xpos][ypos-i]!=0)&&(board[xpos][ypos-i]!=-1)){//Checa las posiciones de la izquierda
        possible=true;
        while (board[xpos][ypos-i]!=player){
            if(board[xpos][ypos-i]==-1){
                possible=false;
                break;
            }
            i++;
        }
        i = 1;
    }
    if((board[xpos][ypos+i]!=player)&&(board[xpos][ypos+i]!=0)&&(board[xpos][ypos+i]!=-1)){//Checa las posiciones de la derecha
        possible = true;
        while (board[xpos][ypos + i] != player) {
            if (board[xpos][ypos + i] == -1) {
                possible = false;
                break;
            }
            i++;
        }
        i = 1;
    }
    if((board[xpos+i][ypos]!=player)&&(board[xpos+i][ypos]!=0)&&(board[xpos+i][ypos]!=-1)){//Checa las posiciones de abajo
        possible = true;
        while (board[xpos+i][ypos] != player) {
            if (board[xpos+i][ypos] == -1) {
                possible = false;
                break;
            }
            i++;
        }
        i = 1;
    }
    if((board[xpos-i][ypos]!=player)&&(board[xpos-i][ypos]!=0)&&(board[xpos-i][ypos]!=-1)) {//Checa las posiciones de arriba
        possible = true;
        while (board[xpos-i][ypos] != player) {
            if (board[xpos-i][ypos] == -1) {
                possible = false;
                break;
            }
            i++;
        }
        i = 1;
    }
    if((board[xpos-i][ypos-i]!=player)&&(board[xpos-i][ypos-i]!=0)&&(board[xpos-i][ypos-i]!=-1)) {//Checa las posiciones de arrba a las izquierda
        possible = true;
        while (board[xpos-i][ypos-i] != player) {
            if (board[xpos-i][ypos-i] == -1) {
                possible = false;
                break;
            }
            i++;
        }
        i = 1;
    }
    if((board[xpos+i][ypos+i]!=player)&&(board[xpos+i][ypos+i]!=0)&&(board[xpos+i][ypos+i]!=-1)) {//Checa las de abajo a la derecha
        possible = true;
        while (board[xpos+i][ypos + i] != player) {
            if (board[xpos+i][ypos + i] == -1) {
                possible = false;
                break;
            }
            i++;
        }
        i = 1;
    }
    if((board[xpos-i][ypos+i]!=player)&&(board[xpos-i][ypos+i]!=0)&&(board[xpos-i][ypos+i]!=-1)) {//Checa las de arriba a la derecha
        possible = true;
        while (board[xpos-i][ypos + i] != player) {
            if (board[xpos-i][ypos + i] == -1) {
                possible = false;
                break;
            }
            i++;
        }
        i = 1;
    }
    if((board[xpos+i][ypos-i]!=player)&&(board[xpos+i][ypos-i]!=0)&&(board[xpos+i][ypos-i]!=-1)) {//Checa las de abajo a la izquierda
        possible = true;
        while (board[xpos+i][ypos - i] != player) {
            if (board[xpos+i][ypos - i] == -1) {
                possible = false;
                break;
            }
            i++;
        }
        i = 1;
    }
    return possible;
}
