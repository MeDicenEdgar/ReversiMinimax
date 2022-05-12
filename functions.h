typedef struct struct_Move{//This struct represents moves
    int x;
    int y;
    int value;
}Move;
typedef struct struct_stats{//This struct represents the current stats
    int bPieces;
    int wPieces;
    char Winner[7];
}Stats;
typedef struct struct_available{//This is a validation struct for possible moves in the board
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

int changeTurn(int turn){//Simple function that changes the turn
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
    if(board[xpos][ypos]!=0){
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
            isIt.possible=true;//Returns the direction in which is possible
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
    if((board[xpos+i][ypos]!=player)&&(board[xpos+i][ypos]!=0)&&(board[xpos+i][ypos]!=-1)){//Checa las posiciones de abajo
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
    if((board[xpos-i][ypos]!=player)&&(board[xpos-i][ypos]!=0)&&(board[xpos-i][ypos]!=-1)) {//Checa las posiciones de arriba
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
    if((board[xpos-i][ypos-i]!=player)&&(board[xpos-i][ypos-i]!=0)&&(board[xpos-i][ypos-i]!=-1)) {//Checa las posiciones de arrba a las izquierda
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
    if((board[xpos+i][ypos+i]!=player)&&(board[xpos+i][ypos+i]!=0)&&(board[xpos+i][ypos+i]!=-1)) {//Checa las de abajo a la derecha
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
    if((board[xpos-i][ypos+i]!=player)&&(board[xpos-i][ypos+i]!=0)&&(board[xpos-i][ypos+i]!=-1)) {//Checa las de arriba a la derecha
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
    if((board[xpos+i][ypos-i]!=player)&&(board[xpos+i][ypos-i]!=0)&&(board[xpos+i][ypos-i]!=-1)) {//Checa las de abajo a la izquierda
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

bool isPossibleMove(int board[10][10], int xpos, int ypos, int player){
    if(board[xpos][ypos]!=0){
        return false;
    }
    int i = 1;
    bool possible=false;
    if((board[xpos][ypos-i]!=player)&&(board[xpos][ypos-i]!=0)&&(board[xpos][ypos-i]!=-1)){//Checa las posiciones de la izquierda
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
    if((board[xpos][ypos+i]!=player)&&(board[xpos][ypos+i]!=0)&&(board[xpos][ypos+i]!=-1)){//Checa las posiciones de la derecha
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
    if((board[xpos+i][ypos]!=player)&&(board[xpos+i][ypos]!=0)&&(board[xpos+i][ypos]!=-1)){//Checa las posiciones de abajo
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
    if((board[xpos-i][ypos]!=player)&&(board[xpos-i][ypos]!=0)&&(board[xpos-i][ypos]!=-1)) {//Checa las posiciones de arriba
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
    if((board[xpos-i][ypos-i]!=player)&&(board[xpos-i][ypos-i]!=0)&&(board[xpos-i][ypos-i]!=-1)) {//Checa las posiciones de arrba a las izquierda
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
    if((board[xpos+i][ypos+i]!=player)&&(board[xpos+i][ypos+i]!=0)&&(board[xpos+i][ypos+i]!=-1)) {//Checa las de abajo a la derecha
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
    if((board[xpos-i][ypos+i]!=player)&&(board[xpos-i][ypos+i]!=0)&&(board[xpos-i][ypos+i]!=-1)) {//Checa las de arriba a la derecha
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
    if((board[xpos+i][ypos-i]!=player)&&(board[xpos+i][ypos-i]!=0)&&(board[xpos+i][ypos-i]!=-1)) {//Checa las de abajo a la izquierda
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

int hasGameEnded(int board[10][10], int player, int check){
    for(int i = 1; i<9;i++){
        for(int n = 1; n<9;n++){
            if(isPossibleMove(board, i, n, player)==true){
                return 0;
            }
        }
    }
    if(check == 0){
        if(hasGameEnded(board, changeTurn(player), 1)==0){
            return 2;
        }
    }
    return 3;
}

void makeMove(int board[10][10], int xpos, int ypos, int player, Available available){
    board[xpos][ypos]=player;
    int i = 1;
    if(available.left==true){
        while(board[xpos][ypos-i]!= player){
            board[xpos][ypos-i]=player;
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

Stats checkWinner(int board[10][10]){
    Stats winner={0, 0, };
    for(int i = 1; i <9; i++){
        for(int n = 1; n<9; n++){
            if(board[i][n]==1){
                winner.bPieces++;
            }
            else if(board[i][n]==2){
                winner.wPieces++;
            }
        }
    }
    if(winner.bPieces>winner.wPieces){
        winner.Winner[0] = 'B';
        winner.Winner[1] = 'l';
        winner.Winner[2] = 'a';
        winner.Winner[3] = 'c';
        winner.Winner[4] = 'k';
        winner.Winner[5] = '\0';
    }else if(winner.wPieces>winner.bPieces){
        winner.Winner[0] = 'W';
        winner.Winner[1] = 'h';
        winner.Winner[2] = 'i';
        winner.Winner[3] = 't';
        winner.Winner[4] = 'e';
        winner.Winner[5] = '\0';
    } else{
        winner.Winner[0] = 'D';
        winner.Winner[1] = 'r';
        winner.Winner[2] = 'a';
        winner.Winner[3] = 'w';
        winner.Winner[4] = '\0';
    }
    return winner;
}

void copyBoard(int board[10][10], int tempBoard[10][10]){
    for (int i = 1; i < 9; i++) {
        for (int n = 1; n < 9; n++) {
            tempBoard[i][n]=board[i][n];
        }
    }
}

int getValue(int board[10][10], Move move) {
    int tempBoard[10][10];
    copyBoard(board, tempBoard);
    makeMove(tempBoard, move.x, move.y, 2, possibleMoves(tempBoard, move.x, move.y, 2));
    Stats current = checkWinner(tempBoard);
    Move moves[64];
    int count = 0;
    for (int i = 1; i < 9; i++) {
        for (int n = 1; n < 9; n++) {
            if (isPossibleMove(tempBoard, i, n, 1) == true) {
                Move moov = {i, n};
                moves[count] = moov;
                count++;
            }
        }
    }
    int value = 0;
    int tempBoard2[10][10];
    for (int i = 0; i < count; i++) {
        copyBoard(tempBoard, tempBoard2);
        makeMove(tempBoard2, moves[i].x, moves[i].y, 1, possibleMoves(tempBoard2, move.x, move.y, 2));
        Stats tempStats = checkWinner(tempBoard2);
        int tempvalue = tempStats.wPieces - current.wPieces;
        if (tempvalue < value) {
            value = tempvalue;
        }
    }
    return value;
}

Move getBestMove(int board[10][10], Move moves[64], int count){
    int currentValue;
    Move bestMove={.x=-1, .y=-1, .value=-100};
    int i = 0;
    Move moov;
    while(i<count){
        moov = moves[i];
        currentValue = getValue(board, moov);
        if(currentValue>bestMove.value){
            bestMove.x = moves[i].x;
            bestMove.y = moves[i].y;
            bestMove.value = currentValue;
        }
        i++;
    }
    return bestMove;
}

Move minimaxMove(int board[10][10]){
    Move moves[64];
    Move bestMove;
    int count = 0;
    for(int i = 1; i<9; i++){
        for(int n = 1; n<9; n++){
            if(isPossibleMove(board, i, n, 2)==true){
                Move moov = {i, n};
                moves[count] = moov;
                count++;
            }
        }
    }
    bestMove = getBestMove(board, moves, count);
    return bestMove;
}

int mainGame(int board[10][10], int turn, int xpos, int ypos){
    int state = hasGameEnded(board, turn, 0);
    printf("State: %i\n", state);
    if(state==2){
        return changeTurn(turn);
    }
    if(state!=3) {
        if (turn == 2) {
            Move move = minimaxMove(board);
            makeMove(board, move.x, move.y, 2, possibleMoves(board, move.x, move.y, 2));
            printBoard(board);
            turn = changeTurn(turn);
        }else {
            makeMove(board, xpos, ypos, turn, possibleMoves(board, xpos, ypos, turn));
            printBoard(board);
            turn = changeTurn(turn);
        }
    }
    if(state==3){
        Stats stats = checkWinner(board);
        printBoard(board);
        printf("The game has ended \nWhite has %i pieces\nBlack has %i pieces\nThe winner is %s", stats.wPieces,
               stats.bPieces, stats.Winner);
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

int mouseValidation(int board[10][10],int y, int x, int height, int width){
    int hgap = (height-200)/8;
    int wgap = (width-200)/8;
    if((x>100 && x<height-100)&&(y>100 && y<width-100)){
        x = ((x-100)/wgap)+1;
        y = ((y-100)/hgap)+1;
        printf("%d %d\n", x, y);
        if(isPossibleMove(board, x, y, 1)){
            return mainGame(board, 1, x, y);
        } else{
            return 1;
        }

    } else{
        return 1;
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
