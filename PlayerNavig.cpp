#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cmath>
#include <conio.h>

using namespace std;


//Initializes the board
void chooseDiff(int& side, int& mineNum){
    int selection;
    char board[side][side];
    vector<int>Props(2);
    cout<<"Choose Difficulty: "<<endl<<"1. Easy"<<endl<<"2. Hard"<<endl<<"3. Nightmare"<<endl;
    cin>>selection;
    while (selection < 1 || selection > 3){
        cout<<"Please select a valid option."<<endl;
        cin>>selection;
    }

    switch (selection){
    case 1:
        side = 10;
        mineNum = 10;
        break;
    case 2:
        side = 17;
        mineNum = 40;
        break;
    case 3:
        side = 25;
        mineNum = 99;
        break;
    }

    Props.at(0) = side;
    side = const_cast<int&>(side);
    Props.at(1) = mineNum;
    mineNum = const_cast<int&>(mineNum);

    board[side][side];

 }

char** initBoard( int side, char**& board, char fill_char2 ){

    for(int r = 0; r < side; r++) {
             for(int c = 0; c < side; c++) {
                  board[r][c] = '0';
             }
        }
    return board;
}

//Displays the full board to the user
char** displayBoard( int side, char**& board, char Player, int& playerCurrLocRow, int& playerCurrLocCol){
    int fillNumCol = 0;
    int fillNumRow = 1;
    for(int r = 0; r < side; r++) {
             for(int c  = 0; c < side; c++) {
                 if (c == 0){
                    cout<<fillNumCol;
                    if (fillNumCol >= 10){
                        cout<<"   ";
                    }
                    else{
                        cout<<"    ";
                    }
                    fillNumCol += 1;
                 }
                 else if (r == 0){
                    if (fillNumRow < 9){
                     cout<<fillNumRow<<"  ";
                    }
                    else{
                     cout<<fillNumRow<<" ";
                    }
                     fillNumRow += 1;
                 }

                 else{
                  cout<<board[r][c]<<"  ";
                 }
                  /*if (board[r][c] == Player){
                      playerCurrLocRow = r;
                      playerCurrLocCol = c;
                  }*/
             }
             if (r == 0){
                 cout<<endl;
             }
             cout<<endl;
        }
 return board;
}
//Displays the board with limited game objects
char** hiddenDisplayBoard( int side, bool& flag, char**& hiddenBoard, char Player, int& hiddenPlayerCurrLocRow, int& hiddenPlayerCurrLocCol, char fill_char2){
    int fillNumCol = 0;
    int fillNumRow = 1;

    for(int r = 0; r < side; r++) {
             for(int c  = 0; c < side; c++) {

                 if (c == 0){
                    cout<<fillNumCol;
                    if (fillNumCol >= 10){
                        cout<<"   ";
                    }
                    else{
                        cout<<"    ";
                    }
                    fillNumCol += 1;
                 }
                 else if (r == 0){
                    if (fillNumRow < 9){
                     cout<<fillNumRow<<"  ";
                    }
                    else{
                     cout<<fillNumRow<<" ";
                    }
                     fillNumRow += 1;
                 }
                 else if (hiddenBoard[r][c] < '9' && hiddenBoard[r][c] >= '0'){
                     cout<<hiddenBoard[r][c]<<"  ";
                 }
                 else if (hiddenBoard[r][c] == Player){
                     cout<<hiddenBoard[r][c]<<"  ";
                 }
                 else  if(flag == 1 && hiddenBoard[r][c] == 'P'){
                     cout<<hiddenBoard[r][c]<<"  ";
                 }

                 else{
                  cout<<fill_char2<<"  ";
                 }
                  if (hiddenBoard[r][c] == Player){
                      hiddenPlayerCurrLocRow = r;
                      hiddenPlayerCurrLocCol = c;
                  }
             }
             if (r == 0){
                 cout<<endl;
             }
             cout<<endl;
        }
 return hiddenBoard;
}


//Generates random locations for the game objects
void mineGen(int side, char**& board, int mineNum){
    int mx, my;
    cout<<endl<<endl<<mineNum<<endl<<endl;
    for (int t = 0; t < mineNum; ++t){
          int tempX;
          int tempY;
        do {
            int itr = 0;

            if (itr > 0){
                int tempX = mx;
                int tempY = my;
            }
            mx = rand()%(side - 1)+ 1;
            my = rand()%(side - 1)+ 1;
            board[mx][my] = '*';
            /*if (mx > 1 && mx < side - 1 && my > 1 && my < side - 1){
            for (int k = mx - 1; k <= mx + 1; ++k) {
                for (int l = my - 1; l <= my + 1; ++l) {
                    if (board[k][l] != '*'){
                        if (k > 0 && k < side && l > 0 && l < side)
                        board[k][l] += 1;
                    }
                }
            }
            }*/

            ++itr;
        }while(/*(mx==i) && (my==j) && */board[tempX][tempY] == '*');
    }
    //return board;
}

void numGen(int side, char**& board, int& numMines){
    for (int i = 1; i < side; ++i) {
        for (int j = 1; j < side; ++j) {
            if (board[i][j] == '*'){
                numMines += 1;
                if (i - 1 >= 1){
                    if (board[i - 1][j] != '*'){
                    board[i - 1][j] += 1;
                    }
                    if ((j + 1 < side)&&(board[i - 1][j + 1] != '*')){
                    board[i - 1][j + 1] += 1;
                    }
                    if ((j - 1 >= 1)&&(board[i - 1][j - 1] != '*')){
                    board[i - 1][j - 1] += 1;
                    }
                }
                if (j - 1 >= 1){
                    if (board[i][j - 1] != '*'){
                    board[i][j - 1] += 1;
                    }
                    if ((i + 1 < side )&&(board[i + 1][j - 1] != '*')){
                    board[i + 1][j - 1] += 1;
                    }

                }
                if (i + 1 < side){
                    if (board[i + 1][j] != '*'){
                    board[i + 1][j] += 1;
                    }
                    if ((j + 1 < side)&&(board[i + 1][j + 1] != '*')){
                    board[i + 1][j + 1] += 1;
                    }
                }
                if (j + 1 < side){
                    if (board[i][j + 1] != '*'){
                    board[i][j + 1] += 1;
                    }
                }
            }
        }
    }
}
void onClick(char**& hiddenBoard, char**& board, int side, int playerCurrLocRow, int playerCurrLocCol){
    int tempRow = playerCurrLocRow;
    int tempCol = playerCurrLocCol;
    if(board[playerCurrLocRow][playerCurrLocCol] == '*'){
        cout<<endl<<"You Lose!"<<endl;
    }
    else if(board[playerCurrLocRow][playerCurrLocCol] < '9' && board[playerCurrLocRow][playerCurrLocCol] > '0'){
        hiddenBoard[playerCurrLocRow][playerCurrLocCol] = board[playerCurrLocRow][playerCurrLocCol];
    }
    else if(board[playerCurrLocRow][playerCurrLocCol] == '0'){
        hiddenBoard[playerCurrLocRow][playerCurrLocCol] = board[playerCurrLocRow][playerCurrLocCol];
        while((board[playerCurrLocRow][playerCurrLocCol] != '*')&&(playerCurrLocCol > 0)&&(playerCurrLocRow > 0)&&(playerCurrLocCol < side) && (playerCurrLocRow < side)){
            while((board[playerCurrLocRow][playerCurrLocCol] != '*')&&(playerCurrLocCol > 0)&&(playerCurrLocRow > 0)&&(playerCurrLocCol < side) && (playerCurrLocRow < side)){
                playerCurrLocRow -= 1;
                hiddenBoard[playerCurrLocRow][playerCurrLocCol] = board[playerCurrLocRow][playerCurrLocCol];
            }
            playerCurrLocRow = tempRow;
            while((board[playerCurrLocRow][playerCurrLocCol] != '*')&&(playerCurrLocCol > 0)&&(playerCurrLocRow > 0)&&(playerCurrLocCol < side) && (playerCurrLocRow < side)){
                playerCurrLocRow += 1;
                hiddenBoard[playerCurrLocRow][playerCurrLocCol] = board[playerCurrLocRow][playerCurrLocCol];
            }
            playerCurrLocRow = tempRow;
            while((board[playerCurrLocRow][playerCurrLocCol] != '*')&&(playerCurrLocCol > 0)&&(playerCurrLocRow > 0)&&(playerCurrLocCol < side) && (playerCurrLocRow < side)){
                playerCurrLocCol -= 1;
                hiddenBoard[playerCurrLocRow][playerCurrLocCol] = board[playerCurrLocRow][playerCurrLocCol];
            }
            playerCurrLocCol = tempCol;
            while((board[playerCurrLocRow][playerCurrLocCol] != '*')&&(playerCurrLocCol > 0)&&(playerCurrLocRow > 0)&&(playerCurrLocCol < side) && (playerCurrLocRow < side)){
                playerCurrLocCol += 1;
                hiddenBoard[playerCurrLocRow][playerCurrLocCol] = board[playerCurrLocRow][playerCurrLocCol];
            }
            playerCurrLocRow -= 1;
            playerCurrLocRow -= 1;
        }
        playerCurrLocRow = tempRow;
        playerCurrLocCol = tempCol;
        /*while((board[playerCurrLocRow][playerCurrLocCol] != '*')&&(playerCurrLocCol > 0)&&(playerCurrLocRow > 0)&&(playerCurrLocCol < side) && (playerCurrLocRow < side)){
            while((board[playerCurrLocRow][playerCurrLocCol] != '*')&&(playerCurrLocCol > 0)&&(playerCurrLocRow > 0)&&(playerCurrLocCol < side) && (playerCurrLocRow < side)){
                playerCurrLocRow -= 1;
                hiddenBoard[playerCurrLocRow][playerCurrLocCol] = board[playerCurrLocRow][playerCurrLocCol];
            }
            playerCurrLocRow = tempRow;
            while((board[playerCurrLocRow][playerCurrLocCol] != '*')&&(playerCurrLocCol > 0)&&(playerCurrLocRow > 0)&&(playerCurrLocCol < side) && (playerCurrLocRow < side)){
                playerCurrLocRow += 1;
                hiddenBoard[playerCurrLocRow][playerCurrLocCol] = board[playerCurrLocRow][playerCurrLocCol];
            }
            playerCurrLocRow = tempRow;
            while((board[playerCurrLocRow][playerCurrLocCol] != '*')&&(playerCurrLocCol > 0)&&(playerCurrLocRow > 0)&&(playerCurrLocCol < side) && (playerCurrLocRow < side)){
                playerCurrLocCol -= 1;
                hiddenBoard[playerCurrLocRow][playerCurrLocCol] = board[playerCurrLocRow][playerCurrLocCol];
            }
            playerCurrLocCol = tempCol;
            while((board[playerCurrLocRow][playerCurrLocCol] != '*')&&(playerCurrLocCol > 0)&&(playerCurrLocRow > 0)&&(playerCurrLocCol < side) && (playerCurrLocRow < side)){
                playerCurrLocCol += 1;
                hiddenBoard[playerCurrLocRow][playerCurrLocCol] = board[playerCurrLocRow][playerCurrLocCol];
            }
            playerCurrLocRow += 1;
            playerCurrLocRow += 1;
        }
        playerCurrLocRow = tempRow;
        playerCurrLocCol = tempCol;
        while((board[playerCurrLocRow][playerCurrLocCol] != '*')&&(playerCurrLocCol > 0)&&(playerCurrLocRow > 0)&&(playerCurrLocCol < side) && (playerCurrLocRow < side)){
            while((board[playerCurrLocRow][playerCurrLocCol] != '*')&&(playerCurrLocCol > 0)&&(playerCurrLocRow > 0)&&(playerCurrLocCol < side) && (playerCurrLocRow < side)){
                playerCurrLocRow -= 1;
                hiddenBoard[playerCurrLocRow][playerCurrLocCol] = board[playerCurrLocRow][playerCurrLocCol];
            }
            playerCurrLocRow = tempRow;
            while((board[playerCurrLocRow][playerCurrLocCol] != '*')&&(playerCurrLocCol > 0)&&(playerCurrLocRow > 0)&&(playerCurrLocCol < side) && (playerCurrLocRow < side)){
                playerCurrLocRow += 1;
                hiddenBoard[playerCurrLocRow][playerCurrLocCol] = board[playerCurrLocRow][playerCurrLocCol];
            }
            playerCurrLocRow = tempRow;
            while((board[playerCurrLocRow][playerCurrLocCol] != '*')&&(playerCurrLocCol > 0)&&(playerCurrLocRow > 0)&&(playerCurrLocCol < side) && (playerCurrLocRow < side)){
                playerCurrLocCol -= 1;
                hiddenBoard[playerCurrLocRow][playerCurrLocCol] = board[playerCurrLocRow][playerCurrLocCol];
            }
            playerCurrLocCol = tempCol;
            while((board[playerCurrLocRow][playerCurrLocCol] != '*')&&(playerCurrLocCol > 0)&&(playerCurrLocRow > 0)&&(playerCurrLocCol < side) && (playerCurrLocRow < side)){
                playerCurrLocCol += 1;
                hiddenBoard[playerCurrLocRow][playerCurrLocCol] = board[playerCurrLocRow][playerCurrLocCol];
            }
            playerCurrLocRow -= 1;
            playerCurrLocRow += 1;
        }
        playerCurrLocRow = tempRow;
        playerCurrLocCol = tempCol;
        while((board[playerCurrLocRow][playerCurrLocCol] != '*')&&(playerCurrLocCol > 0)&&(playerCurrLocRow > 0)&&(playerCurrLocCol < side) && (playerCurrLocRow < side)){
            while((board[playerCurrLocRow][playerCurrLocCol] != '*')&&(playerCurrLocCol > 0)&&(playerCurrLocRow > 0)&&(playerCurrLocCol < side) && (playerCurrLocRow < side)){
                playerCurrLocRow -= 1;
                hiddenBoard[playerCurrLocRow][playerCurrLocCol] = board[playerCurrLocRow][playerCurrLocCol];
            }
            playerCurrLocRow = tempRow;
            while((board[playerCurrLocRow][playerCurrLocCol] != '*')&&(playerCurrLocCol > 0)&&(playerCurrLocRow > 0)&&(playerCurrLocCol < side) && (playerCurrLocRow < side)){
                playerCurrLocRow += 1;
                hiddenBoard[playerCurrLocRow][playerCurrLocCol] = board[playerCurrLocRow][playerCurrLocCol];
            }
            playerCurrLocRow = tempRow;
            while((board[playerCurrLocRow][playerCurrLocCol] != '*')&&(playerCurrLocCol > 0)&&(playerCurrLocRow > 0)&&(playerCurrLocCol < side) && (playerCurrLocRow < side)){
                playerCurrLocCol -= 1;
                hiddenBoard[playerCurrLocRow][playerCurrLocCol] = board[playerCurrLocRow][playerCurrLocCol];
            }
            playerCurrLocCol = tempCol;
            while((board[playerCurrLocRow][playerCurrLocCol] != '*')&&(playerCurrLocCol > 0)&&(playerCurrLocRow > 0)&&(playerCurrLocCol < side) && (playerCurrLocRow < side)){
                playerCurrLocCol += 1;
                hiddenBoard[playerCurrLocRow][playerCurrLocCol] = board[playerCurrLocRow][playerCurrLocCol];
            }
            playerCurrLocRow += 1;
            playerCurrLocRow -= 1;
        }
        playerCurrLocRow = tempRow;
        playerCurrLocCol = tempCol;*/
    }
}


//User interface to navigate around the given space
void PlayerControls(char**& hiddenBoard, char**& board, int& minesFlag, int& numFlags, bool& flag, int side, char& movement, char Player, char fill_char2, int& playerCurrLocRow, int& playerCurrLocCol){
        //char temp;
        switch (movement){



        case 'a':
            //temp = board[playerCurrLocRow][playerCurrLocCol-1];
            if (playerCurrLocCol > 1){
                if (hiddenBoard[playerCurrLocRow][playerCurrLocCol] != 'P' && !(hiddenBoard[playerCurrLocRow][playerCurrLocCol] >= '0' && hiddenBoard[playerCurrLocRow][playerCurrLocCol] < '9')){
                hiddenBoard[playerCurrLocRow][playerCurrLocCol] = fill_char2;
                }
            playerCurrLocCol -= 1;
            if (hiddenBoard[playerCurrLocRow][playerCurrLocCol] != 'P' && !(hiddenBoard[playerCurrLocRow][playerCurrLocCol] >= '0' && hiddenBoard[playerCurrLocRow][playerCurrLocCol] < '9')){
            hiddenBoard[playerCurrLocRow][playerCurrLocCol] = Player;
            }
            }
            else{
                cout<<endl<<"You cannot select from further left"<<endl;
            }

            break;
        case 'd':
            //temp = board[playerCurrLocRow][playerCurrLocCol+1];
            if (playerCurrLocCol < side - 1){
                if (hiddenBoard[playerCurrLocRow][playerCurrLocCol] != 'P' && !(hiddenBoard[playerCurrLocRow][playerCurrLocCol] >= '0' && hiddenBoard[playerCurrLocRow][playerCurrLocCol] < '9')){
                hiddenBoard[playerCurrLocRow][playerCurrLocCol] = fill_char2;
                }
            playerCurrLocCol += 1;
            if (hiddenBoard[playerCurrLocRow][playerCurrLocCol] != 'P' && !(hiddenBoard[playerCurrLocRow][playerCurrLocCol] >= '0' && hiddenBoard[playerCurrLocRow][playerCurrLocCol] < '9')){
            hiddenBoard[playerCurrLocRow][playerCurrLocCol] = Player;
            }
            }
            else{
                cout<<endl<<"You cannot select from further right"<<endl;
            }
            break;
        case 'w':
            //temp = board[playerCurrLocRow-1][playerCurrLocCol];
            if (playerCurrLocRow > 1){
                if (hiddenBoard[playerCurrLocRow][playerCurrLocCol] != 'P' && !(hiddenBoard[playerCurrLocRow][playerCurrLocCol] >= '0' && hiddenBoard[playerCurrLocRow][playerCurrLocCol] < '9')){
                hiddenBoard[playerCurrLocRow][playerCurrLocCol]= fill_char2;
                }
            playerCurrLocRow -= 1;
            if (hiddenBoard[playerCurrLocRow][playerCurrLocCol] != 'P' && !(hiddenBoard[playerCurrLocRow][playerCurrLocCol] >= '0' && hiddenBoard[playerCurrLocRow][playerCurrLocCol] < '9')){
            hiddenBoard[playerCurrLocRow][playerCurrLocCol] = Player;
            }
            }
            else{
                cout<<endl<<"You cannot select from further upwards"<<endl;
            }

            break;
        case 's':
            //temp = board[playerCurrLocRow+1][playerCurrLocCol];
            if (playerCurrLocRow < side - 1){
                if (hiddenBoard[playerCurrLocRow][playerCurrLocCol] != 'P' && !(hiddenBoard[playerCurrLocRow][playerCurrLocCol] >= '0' && hiddenBoard[playerCurrLocRow][playerCurrLocCol] < '9')){
                hiddenBoard[playerCurrLocRow][playerCurrLocCol] = fill_char2;
                }
            playerCurrLocRow += 1;
            if (hiddenBoard[playerCurrLocRow][playerCurrLocCol] != 'P' && !(hiddenBoard[playerCurrLocRow][playerCurrLocCol] >= '0' && hiddenBoard[playerCurrLocRow][playerCurrLocCol] < '9')){
            hiddenBoard[playerCurrLocRow][playerCurrLocCol] = Player;
            }
            }
            else{
                cout<<endl<<"You cannot select from further downwards"<<endl;
            }

            break;
        case 'p':
            if (hiddenBoard[playerCurrLocRow][playerCurrLocCol] == 'P'){
                hiddenBoard[playerCurrLocRow][playerCurrLocCol] = Player;
                numFlags -= 1;
                if (board[playerCurrLocRow][playerCurrLocCol] == '*'){
                minesFlag -= 1;
                }

            }

            else if (hiddenBoard[playerCurrLocRow][playerCurrLocCol] != 'P' && !(hiddenBoard[playerCurrLocRow][playerCurrLocCol] >= '0' && hiddenBoard[playerCurrLocRow][playerCurrLocCol] < '9')){
            flag = 1;
            numFlags += 1;
            hiddenBoard[playerCurrLocRow][playerCurrLocCol] = 'P';

            if (board[playerCurrLocRow][playerCurrLocCol] == '*'){
            minesFlag += 1;
            }

            if ((playerCurrLocRow < side - 1) && hiddenBoard[playerCurrLocRow + 1][playerCurrLocCol] != 'P' && !(hiddenBoard[playerCurrLocRow][playerCurrLocCol] >= '0' && hiddenBoard[playerCurrLocRow][playerCurrLocCol] < '9')){
            playerCurrLocRow += 1;
            hiddenBoard[playerCurrLocRow][playerCurrLocCol] = Player;
            }
            else if((playerCurrLocRow > 1) && hiddenBoard[playerCurrLocRow - 1][playerCurrLocCol] != 'P' && !(hiddenBoard[playerCurrLocRow][playerCurrLocCol] >= '0' && hiddenBoard[playerCurrLocRow][playerCurrLocCol] < '9')){
            playerCurrLocRow -= 1;
            hiddenBoard[playerCurrLocRow][playerCurrLocCol] = Player;
            }
            else if((playerCurrLocCol < side - 1) && hiddenBoard[playerCurrLocRow][playerCurrLocCol + 1] != 'P' && !(hiddenBoard[playerCurrLocRow][playerCurrLocCol] >= '0' && hiddenBoard[playerCurrLocRow][playerCurrLocCol] < '9')){
            playerCurrLocCol += 1;
            hiddenBoard[playerCurrLocRow][playerCurrLocCol] = Player;
            }
            else if ((playerCurrLocCol > 1) && hiddenBoard[playerCurrLocRow][playerCurrLocCol - 1] != 'P' && !(hiddenBoard[playerCurrLocRow][playerCurrLocCol] >= '0' && hiddenBoard[playerCurrLocRow][playerCurrLocCol] < '9')){
            playerCurrLocCol -= 1;
            hiddenBoard[playerCurrLocRow][playerCurrLocCol] = Player;
            }
            }
            break;
        case 'o':
            onClick(hiddenBoard, board, side, playerCurrLocRow, playerCurrLocCol);
            if ((playerCurrLocRow < side - 1) && hiddenBoard[playerCurrLocRow + 1][playerCurrLocCol] != 'P' && !(hiddenBoard[playerCurrLocRow + 1][playerCurrLocCol] >= '0' && hiddenBoard[playerCurrLocRow + 1][playerCurrLocCol] < '9' )){
            playerCurrLocRow += 1;
            hiddenBoard[playerCurrLocRow][playerCurrLocCol] = Player;
            }
            else if((playerCurrLocRow > 1) && hiddenBoard[playerCurrLocRow - 1][playerCurrLocCol] != 'P' && !(hiddenBoard[playerCurrLocRow - 1][playerCurrLocCol] >= '0' && hiddenBoard[playerCurrLocRow - 1][playerCurrLocCol] < '9')){
            playerCurrLocRow -= 1;
            hiddenBoard[playerCurrLocRow][playerCurrLocCol] = Player;
            }
            else if((playerCurrLocCol < side - 1) && hiddenBoard[playerCurrLocRow][playerCurrLocCol + 1] != 'P' && !(hiddenBoard[playerCurrLocRow][playerCurrLocCol + 1] >= '0' && hiddenBoard[playerCurrLocRow ][playerCurrLocCol + 1] < '9')){
            playerCurrLocCol += 1;
            hiddenBoard[playerCurrLocRow][playerCurrLocCol] = Player;
            }
            else if ((playerCurrLocCol > 1) && hiddenBoard[playerCurrLocRow][playerCurrLocCol - 1] != 'P' && !(hiddenBoard[playerCurrLocRow][playerCurrLocCol - 1] >= '0' && hiddenBoard[playerCurrLocRow ][playerCurrLocCol - 1] < '9')){
            playerCurrLocCol -= 1;
            hiddenBoard[playerCurrLocRow][playerCurrLocCol] = Player;
            }
            break;
        default:
            cout<<"Use w,a,s,d to move around."<<endl<<"'q' to quit";
            break;

    }
    cout<<endl<<endl;
    //return board;
}

void Statistics(int numMines, int minesFlag, int numFlags){
    if(minesFlag == numMines && numFlags == minesFlag){
        cout<<endl<<"You have flagged all mines! You WIN!"<<endl;
    }
}


//The main pipeline for the flow of game
char theGame(){
    int playerCurrLocRow;
    int playerCurrLocCol;
    int hiddenPlayerCurrLocRow;
    int hiddenPlayerCurrLocCol;
    int numMines = 0;
    bool flag = 0;
    int minesFlag = 0;
    int numFlags = 0;
    int side = 0;
    int mineNum = 0;
    chooseDiff(side, mineNum);

    char Player = '_';
    vector<int>Props(2);
    char** board = new char*[side];
    for (int var = 0; var < side; ++var) {
        board[var] = new char [side];
    }
    char** hiddenBoard = new char*[side];
    for (int var = 0; var < side; ++var) {
        hiddenBoard[var] = new char [side];
    }
    int px = rand()%(5) + 3;
    int py = rand()%(5) + 3;
    hiddenBoard[px][py] = Player;
    hiddenPlayerCurrLocRow = px;
    hiddenPlayerCurrLocCol = py;
    char fill_char2 = 'L';




    char movement = 'v'; //FIXME initialization
    while ((movement != 'q')){

           initBoard(side, board, fill_char2);


           mineGen(side, board, mineNum);
           numGen(side, board, numMines);
           displayBoard(side, board, Player, hiddenPlayerCurrLocRow, hiddenPlayerCurrLocCol);
           cout<<endl<<endl;
           hiddenDisplayBoard(side, flag, hiddenBoard, Player, hiddenPlayerCurrLocRow, hiddenPlayerCurrLocCol, fill_char2);

           cout<<endl<<"Use w,a,s,d to move around."<<endl<<"'q' to quit"<<endl;

           while (movement != 'q'){
            movement = _getch();
            PlayerControls(hiddenBoard, board, minesFlag, numFlags, flag, side, movement, Player, fill_char2, hiddenPlayerCurrLocRow, hiddenPlayerCurrLocCol);
            system("CLS");
            displayBoard(side, board, Player, hiddenPlayerCurrLocRow, hiddenPlayerCurrLocCol);
            cout<<endl<<"w, a, s, d to move around and q to quit"<<endl;
            hiddenDisplayBoard(side, flag, hiddenBoard, Player, hiddenPlayerCurrLocRow, hiddenPlayerCurrLocCol, fill_char2);

            cout<<endl<<"Your Current Location: ("<<hiddenPlayerCurrLocRow<<", "<<hiddenPlayerCurrLocCol<<")"<<endl;
            Statistics(numMines, minesFlag, numFlags);
            }

        }
    return movement;

}



//Displays the game menu having interactable options
void gameMenu(){

    int userInput = 0;
    cout<<"1. START GAME"<<endl<<"2. INFO"<<endl<<"3. CREDITS"<<endl<<"4. Quit"<<endl<<endl;
    //char movement = theGame();

    while (userInput != 4){
        cin>>userInput;
        cout<<endl;
        if (userInput == 2){
            cout<<endl<<" "<<endl<<endl;

        }
        else if (userInput == 3){
            cout<<"CREDITS:"<<endl<<endl<<"Made by Manvith Krishna Kandukuri"<<endl
               <<"Courtesy of Department of EECS University of Cincinnati."<<endl<<endl;
        }
        else if (userInput == 1){
            theGame();
            /*if(movement == 'q'){
                userInput = 4;
            }*/
        }
    }

}

/*
void mineGen(int diff, int& mx, int& my){


}

void mineGenerator_easy() {
    int mx = rand()%10;
    int my = rand()%10;
}

void mineGenerator_medium() {
    int mx = rand()%40;
    int my = rand()%40;
}

void mineGenerator_hard() {
    int mx = rand()%99;
    int my = rand()%99;
}


void minePlacer(char board[Row][Col], int num) {
    for(int i=0;i<Row;i++) {
        for(int j=0;j<Col;j++) {
            board[i][j] = rand()%10;
        }
    }
    for(int i=0;i<Row;i++) {
        for(int j=0;j<Col;j++) {
            cout<<board[i][j];
        }
    }
}
*/
int main()
{
    srand(time(NULL));

    gameMenu();
    int diff;
    int mx;
    int my;
    char num;


    //displayBoard(board);
    return 0;
}
