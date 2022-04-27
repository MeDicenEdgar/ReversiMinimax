typedef struct struct_Move{
    int x;
    int y;
    int value;
}Move;
typedef struct struct_stats{
    int bPieces;
    int wPieces;
    char Winner[7];
}Stats;


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
        i = 1;
        if(possible==true){
            return true;
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
    if((board[xpos][ypos-i]!=player)&&(board[xpos][ypos-i]!=0)&&(board[xpos][ypos-i]!=-1)){//Checa las posiciones de la izquierda
        possible=true;
        while (board[xpos][ypos-i]!=player){
            if(board[xpos][ypos-i]==-1 || board[xpos][ypos-i]==0){
                possible=false;
                break;
            }
            i++;
        }
        if(possible==true){
            for(int n = 1; n<i; n++){
                board[xpos][ypos-n]=player;
            }
        }
        i = 1;
        possible=false;
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
        if(possible==true){
            for(int n = 1; n<i; n++){
                board[xpos][ypos+n]=player;
            }
        }
        i = 1;
        possible=false;
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
        if(possible==true){
            for(int n = 1; n<i; n++){
                board[xpos+n][ypos]=player;
            }
        }
        i = 1;
        possible=false;
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
        if(possible==true){
            for(int n = 1; n<i; n++){
                board[xpos-n][ypos]=player;
            }
        }
        i = 1;
        possible=false;
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
        if(possible==true){
            for(int n = 1; n<i; n++){
                board[xpos-n][ypos-n]=player;
            }
        }
        i = 1;
        possible=false;
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
        if(possible==true){
            for(int n = 1; n<i; n++){
                board[xpos+n][ypos+n]=player;
            }
        }
        i = 1;
        possible=false;
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
        if(possible==true){
            for(int n = 1; n<i; n++){
                board[xpos-n][ypos+n]=player;
            }
        }
        i = 1;
        possible=false;
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
            for(int n = 1; n<i; n++){
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
    makeMove(tempBoard, move.x, move.y, 2);
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
        makeMove(tempBoard2, moves[i].x, moves[i].y, 1);
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

