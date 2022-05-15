typedef struct struct_Move{//This struct represents moves
    int x;
    int y;
    int value;
}Move;
typedef struct struct_stats{//This struct represents the current stats
    int bPieces;
    int wPieces;
}Stats;
typedef struct struct_available{//This is a validation struct for possible moves in the board, used to make the moves
    bool up;
    bool down;
    bool left;
    bool right;
    bool upLeft;
    bool upRight;
    bool downLeft;
    bool downRight;
    bool possible;
}Available;

int changeTurn(int turn);
Available possibleMoves(int board[10][10], int xpos, int ypos, int player);
bool isPossibleMove(int board[10][10], int xpos, int ypos, int player);
int hasGameEnded(int board[10][10], int player, int check);
void makeMove(int board[10][10], int xpos, int ypos, int player, Available available);
void printBoard(int board[10][10]);
Stats checkWinner(int board[10][10]);
void copyBoard(int board[10][10], int tempBoard[10][10]);
int getValue(int board[10][10], Move move);
Move getBestMove(int board[10][10], Move moves[64], int count);
Move minimaxMove(int board[10][10]);
int mainGame(int board[10][10], int turn, int xpos, int ypos);
void drawBoard(int width, int height);
int mouseValidation(int board[10][10],int y, int x, int height, int width);
void currentTurn(int turn, int height, int width);
void drawPieces(int board[10][10], int width, int height);
int endgame(int board[10][10], Stats stats, int width, int height);
void drawAvailableMoves(int board[10][10], int width, int height);
void displayNumberOfPieces(int board[10][10], int screenWidth, int screenHeight);
void DrawEndgame(int winner, int width, int height);

int changeTurn(int turn){//Simple function that changes the turn, makes my life easier
    if(turn==1){
        return 2;
    }
    if(turn==2){
        return 1;
    }
    return 1;
}

Available possibleMoves(int board[10][10], int xpos, int ypos, int player){         //Unlike the one that only gets if the move is possible
    Available isIt={false, false, false, false, false, false, false, false, false}; //returns the directions in which is possible
    if(board[xpos][ypos]!=0){//If the space is not available, instantly returns the false
        return isIt;
    }
    int i = 1;
    bool possible=false;
    if((board[xpos][ypos-i]!=player)&&(board[xpos][ypos-i]!=0)&&(board[xpos][ypos-i]!=-1)){//Checks left for a enemy piece
        possible=true;
        while (board[xpos][ypos-i]!=player){//if true, checks for a piece that closes the play
            if(board[xpos][ypos-i]==-1 || board[xpos][ypos-i]==0){
                possible=false;//If there is no such piece, is false
                break;
            }
            i++;
        }
        i = 1;
        if(possible==true){
            isIt.possible=true;//Returns the direction in which is possible, and mark the move as possible
            isIt.left=true;
        }
    }
    if((board[xpos][ypos+i]!=player)&&(board[xpos][ypos+i]!=0)&&(board[xpos][ypos+i]!=-1)){//Checks right
        possible = true;
        while (board[xpos][ypos + i] != player) {
            if (board[xpos][ypos + i] == -1 || board[xpos][ypos + i] == 0) {
                possible = false;
                break;
            }
            i++;
        }
        i = 1;
        if(possible==true){
            isIt.possible=true;
            isIt.right=true;
        }
    }
    if((board[xpos+i][ypos]!=player)&&(board[xpos+i][ypos]!=0)&&(board[xpos+i][ypos]!=-1)){//Checks down
        possible = true;
        while (board[xpos+i][ypos] != player) {
            if (board[xpos+i][ypos] == -1 || board[xpos+i][ypos] == 0) {
                possible = false;
                break;
            }
            i++;
        }
        i = 1;
        if(possible==true){
            isIt.possible=true;
            isIt.down=true;
        }
    }
    if((board[xpos-i][ypos]!=player)&&(board[xpos-i][ypos]!=0)&&(board[xpos-i][ypos]!=-1)) {//Checks up
        possible = true;
        while (board[xpos-i][ypos] != player) {
            if (board[xpos-i][ypos] == -1 || board[xpos-i][ypos] == 0) {
                possible = false;
                break;
            }
            i++;
        }
        i = 1;
        if(possible==true){
            isIt.possible=true;
            isIt.up=true;
        }
    }
    if((board[xpos-i][ypos-i]!=player)&&(board[xpos-i][ypos-i]!=0)&&(board[xpos-i][ypos-i]!=-1)) {//Checks up left
        possible = true;
        while (board[xpos-i][ypos-i] != player) {
            if (board[xpos-i][ypos-i] == -1 || board[xpos-i][ypos-i] == 0) {
                possible = false;
                break;
            }
            i++;
        }
        i = 1;
        if(possible==true){
            isIt.possible=true;
            isIt.upLeft=true;
        }
    }
    if((board[xpos+i][ypos+i]!=player)&&(board[xpos+i][ypos+i]!=0)&&(board[xpos+i][ypos+i]!=-1)) {//Checks down  right
        possible = true;
        while (board[xpos+i][ypos + i] != player) {
            if (board[xpos+i][ypos + i] == -1 || board[xpos+i][ypos + i] == 0) {
                possible = false;
                break;
            }
            i++;
        }
        i = 1;
        if(possible==true){
            isIt.possible=true;
            isIt.downRight=true;
        }
    }
    if((board[xpos-i][ypos+i]!=player)&&(board[xpos-i][ypos+i]!=0)&&(board[xpos-i][ypos+i]!=-1)) {//Checks up right
        possible = true;
        while (board[xpos-i][ypos + i] != player) {
            if (board[xpos-i][ypos + i] == -1 || board[xpos-i][ypos + i] == 0) {
                possible = false;
                break;
            }
            i++;
        }
        i = 1;
        if(possible==true){
            isIt.possible=true;
            isIt.upRight=true;
        }
    }
    if((board[xpos+i][ypos-i]!=player)&&(board[xpos+i][ypos-i]!=0)&&(board[xpos+i][ypos-i]!=-1)) {//Checks down left
        possible = true;
        while (board[xpos+i][ypos - i] != player) {
            if (board[xpos+i][ypos - i] == -1 || board[xpos+i][ypos - i] == 0) {
                possible = false;
                break;
            }
            i++;
        }
        if(possible==true){
            isIt.possible=true;
            isIt.downLeft=true;
        }
    }
    return isIt;
}

bool isPossibleMove(int board[10][10], int xpos, int ypos, int player){//A function just like the one above
    if(board[xpos][ypos]!=0){                                          //This one doesn't return the direction
        return false;
    }
    int i = 1;
    bool possible=false;
    if((board[xpos][ypos-i]!=player)&&(board[xpos][ypos-i]!=0)&&(board[xpos][ypos-i]!=-1)){//Checks left for an enemy piece
        possible=true;
        while (board[xpos][ypos-i]!=player){
            if(board[xpos][ypos-i]==-1 || board[xpos][ypos-i]==0){
                possible=false;
                break;
            }
            i++;
        }
        i = 1;
        if(possible==true){
            return true;
        }
    }
    if((board[xpos][ypos+i]!=player)&&(board[xpos][ypos+i]!=0)&&(board[xpos][ypos+i]!=-1)){//Checks right
        possible = true;
        while (board[xpos][ypos + i] != player) {
            if (board[xpos][ypos + i] == -1 || board[xpos][ypos + i] == 0) {
                possible = false;
                break;
            }
            i++;
        }
        i = 1;
        if(possible==true){
            return true;
        }
    }
    if((board[xpos+i][ypos]!=player)&&(board[xpos+i][ypos]!=0)&&(board[xpos+i][ypos]!=-1)){//Checks down
        possible = true;
        while (board[xpos+i][ypos] != player) {
            if (board[xpos+i][ypos] == -1 || board[xpos+i][ypos] == 0) {
                possible = false;
                break;
            }
            i++;
        }
        i = 1;
        if(possible==true){
            return true;
        }
    }
    if((board[xpos-i][ypos]!=player)&&(board[xpos-i][ypos]!=0)&&(board[xpos-i][ypos]!=-1)) {//Checks Up
        possible = true;
        while (board[xpos-i][ypos] != player) {
            if (board[xpos-i][ypos] == -1 || board[xpos-i][ypos] == 0) {
                possible = false;
                break;
            }
            i++;
        }
        i = 1;
        if(possible==true){
            return true;
        }
    }
    if((board[xpos-i][ypos-i]!=player)&&(board[xpos-i][ypos-i]!=0)&&(board[xpos-i][ypos-i]!=-1)) {//Checks up left
        possible = true;
        while (board[xpos-i][ypos-i] != player) {
            if (board[xpos-i][ypos-i] == -1 || board[xpos-i][ypos-i] == 0) {
                possible = false;
                break;
            }
            i++;
        }
        i = 1;
        if(possible==true){
            return true;
        }
    }
    if((board[xpos+i][ypos+i]!=player)&&(board[xpos+i][ypos+i]!=0)&&(board[xpos+i][ypos+i]!=-1)) {//Checks down right
        possible = true;
        while (board[xpos+i][ypos + i] != player) {
            if (board[xpos+i][ypos + i] == -1 || board[xpos+i][ypos + i] == 0) {
                possible = false;
                break;
            }
            i++;
        }
        i = 1;
        if(possible==true){
            return true;
        }
    }
    if((board[xpos-i][ypos+i]!=player)&&(board[xpos-i][ypos+i]!=0)&&(board[xpos-i][ypos+i]!=-1)) {//Checks up right
        possible = true;
        while (board[xpos-i][ypos + i] != player) {
            if (board[xpos-i][ypos + i] == -1 || board[xpos-i][ypos + i] == 0) {
                possible = false;
                break;
            }
            i++;
        }
        i = 1;
        if(possible==true){
            return true;
        }
    }
    if((board[xpos+i][ypos-i]!=player)&&(board[xpos+i][ypos-i]!=0)&&(board[xpos+i][ypos-i]!=-1)) {//Checks down left
        possible = true;
        while (board[xpos+i][ypos - i] != player) {
            if (board[xpos+i][ypos - i] == -1 || board[xpos+i][ypos - i] == 0) {
                possible = false;
                break;
            }
            i++;
        }
        if(possible==true){
            return true;
        }
    }
    return possible;
}

int hasGameEnded(int board[10][10], int player, int check){//Recursive function that determines the state of the game
    for(int i = 1; i<9;i++){
        for(int n = 1; n<9;n++){
            if(isPossibleMove(board, i, n, player)==true){
                return 0;//If al least one move in the board is legal, returns 0, which is normal state
            }
        }
    }
    if(check == 0){//If this is the first call of the function and there isn't a possible move
        if(hasGameEnded(board, changeTurn(player), 1)==0){//Calls the function again
            return 2;                                                      //But with the turn swapped and no check
        }                                                                  //If there's a possible move, returns state 2
    }
    return 3;//If there is no move possible with the turns swapped, it means that the game has ended, returns 3
}

void makeMove(int board[10][10], int xpos, int ypos, int player, Available available){//Makes a move receiving the validation struct made in possible moves
    board[xpos][ypos]=player;
    int i = 1;
    if(available.left==true){//Checks if the struct received declares left as possible
        while(board[xpos][ypos-i]!= player){
            board[xpos][ypos-i]=player;//Make every space from the initial position until it encounters another player piece, a player piece
            i++;
        }
        i = 1;
    }
    if(available.right==true){
        while(board[xpos][ypos+i]!= player){
            board[xpos][ypos+i]=player;
            i++;
        }
        i = 1;
    }
    if(available.down==true){
        while(board[xpos+i][ypos]!= player) {
            board[xpos + i][ypos] = player;
            i++;
        }
        i = 1;
    }
    if(available.up==true){
        while(board[xpos-i][ypos]!= player){
            board[xpos-i][ypos]=player;
            i++;
        }
        i = 1;
    }
    if(available.upLeft==true){
        while(board[xpos-i][ypos-i]!= player){
            board[xpos-i][ypos-i]=player;
            i++;
        }
        i = 1;
    }
    if(available.downRight==true){
        while(board[xpos+i][ypos+i]!= player){
            board[xpos+i][ypos+i]=player;
            i++;
        }
        i = 1;
    }
    if(available.upRight==true){
        while(board[xpos-i][ypos+i]!= player){
            board[xpos-i][ypos+i]=player;
            i++;
        }
        i = 1;
    }
    if(available.downLeft==true){
        while(board[xpos+i][ypos-i]!= player){
            board[xpos+i][ypos-i]=player;
            i++;
        }
    }
}

void printBoard(int board[10][10]){//Function used for debuging that prints the board in console
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

Stats checkWinner(int board[10][10]){//Generates a struct that consists of the current stats of the game
    Stats winner={0, 0, };
    for(int i = 1; i <9; i++){
        for(int n = 1; n<9; n++){//Checks all the board
            if(board[i][n]==1){
                winner.bPieces++;//counts the pieces
            }
            else if(board[i][n]==2){
                winner.wPieces++;
            }
        }
    }
    return winner;
}

void copyBoard(int board[10][10], int tempBoard[10][10]){//Simple function that copies board 1 into board 2
    for (int i = 1; i < 9; i++) {
        for (int n = 1; n < 9; n++) {
            tempBoard[i][n]=board[i][n];
        }
    }
}

int getValue(int board[10][10], Move move) {//Part of the minimax algorithm, gets the value of a certain possible move
    int tempBoard[10][10];//Generates a copy of the original board
    copyBoard(board, tempBoard);
    makeMove(tempBoard, move.x, move.y, 2, possibleMoves(tempBoard, move.x, move.y, 2));
    Stats current = checkWinner(tempBoard);//Makes a hypothetical move on the temp board and generates the stats
    Move moves[64];
    int count = 0;
    for (int i = 1; i < 9; i++) {
        for (int n = 1; n < 9; n++) {
            if (isPossibleMove(tempBoard, i, n, 1) == true) {
                Move moov = {i, n};
                moves[count] = moov;//Registers all the possible move of the hypothetical outcome of that move
                count++;
            }
        }
    }
    int value = 0;//Generates a value for the move
    int tempBoard2[10][10];
    for (int i = 0; i < count; i++) {//For every hypothetical move in our scenario
        copyBoard(tempBoard, tempBoard2);//Generates another hypothetical move
        makeMove(tempBoard2, moves[i].x, moves[i].y, 1, possibleMoves(tempBoard2, move.x, move.y, 2));
        Stats tempStats = checkWinner(tempBoard2);//gets the stats of the hypothetical of our hypothetical
        int tempvalue = tempStats.wPieces - current.wPieces;//Generates a simple value
        if (tempvalue < value) {//If the value of the move is better than the current
            value = tempvalue;//Replaces the value, this value represents what's the best possible move that the rival can make
        }
    }
    return value;//Returns the numerical value
}

Move getBestMove(int board[10][10], Move moves[64], int count){//Defines the best possible move of an array of moves
    int currentValue;
    Move bestMove={.x=-1, .y=-1, .value=-100};//Generates the struct to return
    int i = 0;
    Move moov;
    while(i<count){//For every move in the array
        moov = moves[i];
        currentValue = getValue(board, moov);//Gets the numerical value of the move, this value is the value of the worst scenario if we make that move
        if(currentValue>bestMove.value){//If the value is better than our current best move
            bestMove.x = moves[i].x;
            bestMove.y = moves[i].y;
            bestMove.value = currentValue;//Replaces it
        }
        i++;
    }
    return bestMove;//Returns the best move
}

Move minimaxMove(int board[10][10]){//The main part of our minimax, is the one to call
    Move moves[64];
    Move bestMove;
    int count = 0;
    for(int i = 1; i<9; i++){
        for(int n = 1; n<9; n++){
            if(isPossibleMove(board, i, n, 2)==true){//Gets all the possible moves
                Move moov = {i, n};
                moves[count] = moov;
                count++;
            }
        }
    }
    bestMove = getBestMove(board, moves, count);//Calls the get best move, given the array that we made
    return bestMove;//Returns the move to make
}

int mainGame(int board[10][10], int turn, int xpos, int ypos){//The main loop of the game
    int state = hasGameEnded(board, turn, 0);//Gets the game state
    if(state==2){
        return changeTurn(turn);
    }
    if(state!=3) {//If the game has not ended
        if (turn == 2) {//if it is the AI's turn
            Move move = minimaxMove(board);
            makeMove(board, move.x, move.y, 2, possibleMoves(board, move.x, move.y, 2));//Makes the move given the minimax move
            printBoard(board);
            turn = changeTurn(turn);
        }else {
            makeMove(board, xpos, ypos, turn, possibleMoves(board, xpos, ypos, turn));//If is the player's turn
            printBoard(board);
            turn = changeTurn(turn);
        }
    }
    if(state==3){
        return 3;
    }
    return turn;
}

void drawBoard(int width, int height){
    Color color = WHITE;
    width-=200;
    height-=200;
    int hGap = height/8;
    int wGap = width/8;
    DrawRectangle(100, 100, width-4, height-4, DARKGREEN);
    for(int i = 0; i<=8; i++){
        int wPos = (wGap*i)+100;
        int hPos = (hGap*i)+100;
        DrawLine(wPos, 100, wPos, height+96, color);
        DrawLine(100, hPos, width+96, hPos, color);
    }

}

int mouseValidation(int board[10][10],int y, int x, int height, int width){//Turns a mouse input into coordinates in the board
    int hgap = (height-200)/8;
    int wgap = (width-200)/8;
    if((x>100 && x<height-100)&&(y>100 && y<width-100)){//If the mouse is in a legal position
        x = ((x-100)/wgap)+1;
        y = ((y-100)/hgap)+1;//gets the coordinates
        printf("%d %d\n", x, y);
        if(isPossibleMove(board, x, y, 1)){//If the move is possible
            return mainGame(board, 1, x, y);//Calls the main game with the coordinates the player wants to use
        } else{
            return 1;//If it is not possible, returns the players turn, the loop continues until the player enters a valid input
        }

    } else{
        return 1;
    }
}

//All the functions from now on, are raylib functions

void currentTurn(int turn, int height, int width){
    DrawRectangle(width-185, height-63, 185, 75, GRAY);
    DrawLine(width-185, height-63, width-185, height, WHITE);
    DrawLine(width-185, height-63, width, height-63, WHITE);
    DrawText("TURN:", width-174, height-49, 38, WHITE);
    if(turn==1){
        DrawCircle(width-30, height-33, 23, BLACK);
    } else if(turn == 2){
        DrawCircle(width-30, height-33, 23, WHITE);
    }else{
        DrawCircle(width-30, height-33, 23, LIME);
    }
}

void drawPieces(int board[10][10], int width, int height){
    int hgap = (height-200)/8;
    int wgap = (width-200)/8;
    int xpos;
    int ypos;
    for(int i = 1; i<9; i++){
        for(int n = 1; n<9; n++){
            if(board[i][n]==1){
                xpos = ((wgap*(n-1))+wgap/2)+100;
                ypos = ((hgap*(i-1))+hgap/2)+100;
                DrawCircle(xpos, ypos, (hgap/2)-7, BLACK);
            }
            if(board[i][n]==2){
                xpos = ((wgap*(n-1))+wgap/2)+100;
                ypos = ((hgap*(i-1))+hgap/2)+100;
                DrawCircle(xpos, ypos, (hgap/2)-7, WHITE);
            }
        }
    }
}

int endgame(int board[10][10], Stats stats, int width, int height){
    if(stats.bPieces>stats.wPieces){
        for(int i = 1; i<9; i++){
            for(int n = 1; n<9; n++){
                board[i][n]=1;
            }

        }
        return 1;
    }else if(stats.bPieces<stats.wPieces){
        for(int i = 1; i<9; i++){
            for(int n = 1; n<9; n++){
                board[i][n]=2;
            }
        }
        return 2;

    } else{
        for(int i = 1; i<9; i++){
            for(int n = 1; n<9; n++){
                board[i][n]=0;
            }
        }
    }
    return 3;
}

void drawAvailableMoves(int board[10][10], int width, int height){
    int wGap = (width-200)/8;
    int hGap = (height-200)/8;
    int xpos;
    int ypos;
    for(int i = 1; i<9; i++){
        for(int n = 1; n<9; n++){
            if(isPossibleMove(board, i, n, 1)==true){
                xpos = (wGap*(n-1))+100;
                ypos = (hGap*(i-1))+100;
                DrawRectangle(xpos, ypos, wGap-2, hGap-2, GREEN);
            }
        }
    }
}

void displayNumberOfPieces(int board[10][10], int screenWidth, int screenHeight){
    Stats stats = checkWinner(board);
    int radius = (screenWidth-500)/8+7;
    int pos = radius+10;
    char current[5];
    DrawRectangle(0, 0, screenWidth-350, radius*2+20, GRAY);
    DrawCircle(pos, pos, radius, WHITE);
    DrawCircle(pos*5, pos, radius, BLACK);
    sprintf(current, "x %d", stats.wPieces);
    DrawText(current, pos+radius+10, pos, 30, WHITE);
    sprintf(current, "x %d", stats.bPieces);
    DrawText(current, pos*5+radius+10, pos, 30, BLACK);
}

void DrawEndgame(int winner, int width, int height){
    if (winner ==1){
        DrawRectangle(width/2-85, height/2-50, 170, 100, BLACK);
        DrawText("Black Wins!", width/2 -70, height/2 -15, 27, WHITE);
    }else if(winner == 2){
        DrawRectangle(width/2-85, height/2-50, 170, 100, WHITE);
        DrawText("White Wins!", width/2 -70, height/2 -15, 27, BLACK);
    }else if (winner == 3){
        DrawRectangle(width/2-85, height/2-50, 170, 100, GRAY);
        DrawText("No One Wins!", width/2 -70, height/2 -15, 24, WHITE);
    }

}
//Credits to https://github.com/MeDicenEdgar