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
    mineNum = const_cast<int&>(side);

    board[side][side];

 }

char** initBoard( int side, char** board, char fill_char2 ){

    for(int r = 0; r < side; r++) {
             for(int c = 0; c < side; c++) {
                  board[r][c] = '0';
             }
        }
    return board;
}

//Displays the full board to the user
char** displayBoard( int side, char** board, char Player, int& playerCurrLocRow, int& playerCurrLocCol){
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
                  if (board[r][c] == Player){
                      playerCurrLocRow = r;
                      playerCurrLocCol = c;
                  }
             }
             if (r == 0){
                 cout<<endl;
             }
             cout<<endl;
        }
 return board;
}
//Displays the board with limited game objects
char** hiddenDisplayBoard( int side, char** board, char Player, int& playerCurrLocRow, int& playerCurrLocCol, char fill_char2){
    int fillNumCol = 0;
    int fillNumRow = 1;
    for(int r = 0; r < side; r++) {
             for(int c  = 0; c < side; c++) {
                 if (board[r][c] == Player){
                     cout<<board[r][c]<<"  ";
                 }
                 else if (c == 0){
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
                  cout<<fill_char2<<"  ";
                 }
                  if (board[r][c] == Player){
                      playerCurrLocRow = r;
                      playerCurrLocCol = c;
                  }
             }
             if (r == 0){
                 cout<<endl;
             }
             cout<<endl;
        }
 return board;
}


//Generates random locations for the game objects
char** charLocGen(int side, char** board, int mineNum, char Player){


    int i = 0;
    int j = 0;


    i = rand() % 12 + 1;
    j = rand() % 12 + 1;

    int mx, my;

    /*switch (diff){
        case 1:
            mineNum = 10;
            break;
        case 2:
            mineNum = 40;
            break;

        case 3:
            mineNum = 99;
            break;
        default:
            mineNum = 10;
            break;

    }*/
    for (int t = 0; t <= mineNum; ++t){
        int tempX;
        int tempY;
        do {
            int itr = 0;

            if (itr > 0){
                int tempX = mx;
                int tempY = my;
            }
            mx = rand()%(side - 2) + 2;
            my = rand()%(side - 2) + 2;
            board[mx][my] = '*';
            for (int x = (mx - 1); x <= (mx + 1); ++x) {
                for (int y = (my - 1); y <= (my + 1) ;++y) {
                    if (/*(x != mx && y != my) */board[x][y] != '*'){
                    if (board[x][y] >= '0' && board[x][y] <= '9'){
                        board[x][y] += 1;
                        }
                    }
                }
            }
        }while((mx==i) && (my==j) && (mx == tempX) && (mx = tempY));
    }


    //board[i][j] = Player;
    //Player = board[i][j];
    return board;
}

//User interface to navigate around the given space
char** PlayerControls(char** board, char movement, char Player, char fill_char2, int& playerCurrLocRow, int& playerCurrLocCol){
        char temp;
        switch (movement){



        case 'a':
            temp = board[playerCurrLocRow][playerCurrLocCol-1];
            board[playerCurrLocRow][playerCurrLocCol] = fill_char2;
            playerCurrLocCol -= 1;
            board[playerCurrLocRow][playerCurrLocCol] = Player;

            break;
        case 'd':
            temp = board[playerCurrLocRow][playerCurrLocCol+1];
            board[playerCurrLocRow][playerCurrLocCol] = fill_char2;
            playerCurrLocCol += 1;
            board[playerCurrLocRow][playerCurrLocCol] = Player;

            break;
        case 'w':
            temp = board[playerCurrLocRow-1][playerCurrLocCol];
            board[playerCurrLocRow][playerCurrLocCol]= fill_char2;
            playerCurrLocRow -= 1;
            board[playerCurrLocRow][playerCurrLocCol] = Player;

            break;
        case 's':
            temp = board[playerCurrLocRow+1][playerCurrLocCol];
            board[playerCurrLocRow][playerCurrLocCol] = fill_char2;
            playerCurrLocRow += 1;
            board[playerCurrLocRow][playerCurrLocCol] = Player;

            break;
        default:
            cout<<"Use w,a,s,d to move around."<<endl<<"'q' to quit";
            break;

    }
    cout<<endl<<endl;
    return board;
}



//The main pipeline for the flow of game
char theGame(){
    int playerCurrLocRow;
    int playerCurrLocCol;
    int diff;
    int side = 0;
    int mineNum = 0;
    chooseDiff(side, mineNum);
    diff = mineNum;
    char Player = '_';
    vector<int>Props(2);
    char** board = new char*[side];
    for (int var = 0; var < side; ++var) {
        board[var] = new char [side];
    }
    char fill_char2 = 'X';




    char movement = 'v'; //FIXME initialization
    while ((movement != 'q')){

           initBoard(side, board, fill_char2);


           charLocGen(side, board, mineNum, Player);
           displayBoard(side, board, Player, playerCurrLocRow, playerCurrLocCol);
           cout<<endl<<endl;
           hiddenDisplayBoard(side, board, Player, playerCurrLocRow, playerCurrLocCol, fill_char2);

           cout<<endl<<"Use w,a,s,d to move around."<<endl<<"'q' to quit"<<endl;

           while (movement != 'q'){
            movement = _getch();

            //cin>>movement;
            PlayerControls(board, movement, Player, fill_char2, playerCurrLocRow, playerCurrLocCol);
            system("CLS");
            displayBoard(side, board, Player, playerCurrLocRow, playerCurrLocCol);
            cout<<endl<<"w, a, s, d to move around and q to quit"<<endl;
            hiddenDisplayBoard(side, board, Player, playerCurrLocRow, playerCurrLocCol, fill_char2);
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
