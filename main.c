#include <stdio.h>
#include "stdbool.h"
typedef struct struct_Move{
    int x;
    int y;
    struct struct_Move *PossibleMoves[30];
}Move;
bool isPossibleMove(int board[10][10], int xpos, int ypos, int player);
bool hasGameEnded(int board[10][10], int player);
void makeMove(int board[10][10], int xpos, int ypos, int player);
void printBoard(int board[10][10]);
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
    printBoard(board);
    printf("----------------------Black Move----------------------\n");
    bool p = true;
    while(hasGameEnded(board, turn)==false){
        scanf("%d %d", &xpos, &ypos);
        if (isPossibleMove(board, xpos, ypos, turn)==true){
            makeMove(board, xpos, ypos, turn);
            printBoard(board);
        }else{
            printf("That is not a valid movement\n");
            continue;
        }
        if(turn==1){
            turn=2;
            printf("----------------------White Move----------------------\n");
        } else{
            turn=1;
            printf("----------------------Black Move----------------------\n");
        }
    }
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
        if(possible==true){
            return possible;
        }
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
        if(possible==true){
            return possible;
        }
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
        if(possible==true){
            return possible;
        }
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
        if(possible==true){
            return possible;
        }
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
        if(possible==true){
            return possible;
        }
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
        if(possible==true){
            return possible;
        }
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
        if(possible==true){
            return possible;
        }
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
        if(possible==true){
            return possible;
        }
    }
    return possible;
}

bool hasGameEnded(int board[10][10], int player){
    for(int i = 1; i<9;i++){
        for(int n = 1; n<9;n++){
            if(isPossibleMove(board, i, n, player)==true){
                return false;
            }
        }
    }
    return true;
}

void makeMove(int board[10][10], int xpos, int ypos, int player){
    board[xpos][ypos]=player;
    int i = 1;
    bool possible=false;
    int count = 0;
    if((board[xpos][ypos-i]!=player)&&(board[xpos][ypos-i]!=0)&&(board[xpos][ypos-i]!=-1)){//Checa las posiciones de la izquierda
        possible=true;
        while (board[xpos][ypos-i]!=player){
            if(board[xpos][ypos-i]==-1){
                possible=false;
                break;
            }
            i++;
        }
        if(possible==true){
            for(int n = 1; n<=i; n++){
                board[xpos][ypos-n]=player;
            }
        }
        i = 1;
        possible=false;
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
        if(possible==true){
            for(int n = 1; n<=i; n++){
                board[xpos][ypos+n]=player;
            }
        }
        i = 1;
        possible=false;
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
        if(possible==true){
            for(int n = 1; n<=i; n++){
                board[xpos+n][ypos]=player;
            }
        }
        i = 1;
        possible=false;
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
        if(possible==true){
            for(int n = 1; n<=i; n++){
                board[xpos-n][ypos]=player;
            }
        }
        i = 1;
        possible=false;
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
        if(possible==true){
            for(int n = 1; n<=i; n++){
                board[xpos-n][ypos-n]=player;
            }
        }
        i = 1;
        possible=false;
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
        if(possible==true){
            for(int n = 1; n<=i; n++){
                board[xpos+n][ypos+n]=player;
            }
        }
        i = 1;
        possible=false;
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
        if(possible==true){
            for(int n = 1; n<=i; n++){
                board[xpos-n][ypos+n]=player;
            }
        }
        i = 1;
        possible=false;
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
        if(possible==true){
            for(int n = 1; n<=i; n++){
                board[xpos+n][ypos-n]=player;
            }
        }
        i = 1;
        possible=false;
    }
}

void printBoard(int board[10][10]){

    for(int i = 1; i<9; i++){
        printf("%d |", i);
        for(int n = 1; n<9; n++){
            if(board[i][n]==0){
                printf("   |");
            }
            else if(board[i][n]==1){
                printf(" X |");
            }
            else if(board[i][n]==2){
                printf(" O |");
            }
            else{
                printf("-1");
            }
        }
        printf("\n");
    }
    printf("    1   2   3   4   5   6   7   8  ");
    printf("\n");
}
