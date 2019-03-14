#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cmath>

using namespace std;

const int Row = 16;
const int Col = 16;
char board[Row][Col];
char Player = '_';

int playerCurrLocRow;
int playerCurrLocCol;

char movement;
int fillNumCol = 0;
int fillNumRow = 1;
char fill_char = '=';
char fill_char2 = 'O';



//Initializes the board
void initBoard(char board[Row][Col], char fill_char ){

    for(int r = 0; r < Row; r++) {
             for(int c = 0; c < Col; c++) {
                  board[r][c] = fill_char2;
             }
        }
}


//Displays the full board to the user
void displayBoard(char board[Row][Col]){
    fillNumCol = 0;
    fillNumRow = 1;
    for(int r = 0; r < Row; r++) {
             for(int c  = 0; c < Col; c++) {
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

}
//Displays the board with limited game objects

//Generates random locations for the game objects
void charLocGen(char board[Row][Col], int diff, int rowB, int colB){

    int mineNum;
    int i = 0;
    int j = 0;


    i = rand() % 12 + 1;
    j = rand() % 12 + 1;

    int mx, my;
    switch (diff){
        case 1:
        {mineNum = 10;
            break;}
        case 2:
        {mineNum = 40;
            break;}

        case 3:
        {mineNum = 100;
            break;}
        default:
        {mineNum = 10;
            break;}

    }
    for (int t = 0; t <= mineNum; ++t){
        int tempX;
        int tempY;
        do {
            int itr = 0;

            if (itr > 0){
                int tempX = mx;
                int tempY = my;
            }
            mx = rand()%(rowB - 1) + 1;
            my = rand()%(colB - 1) + 1;
            board[mx][my] = '*';
        }while((mx==i) && (my==j) && (mx == tempX) && (mx = tempY));
    }
    board[i][j] = Player;
    //Player = board[i][j];
}

//User interface to navigate around the given space
void PlayerControls(char board[Row][Col]){

        switch (movement){

        case 'a':
            board[playerCurrLocRow][playerCurrLocCol] = fill_char2;
            playerCurrLocCol -= 1;
            board[playerCurrLocRow][playerCurrLocCol] = Player;

            break;
        case 'd':
            board[playerCurrLocRow][playerCurrLocCol] = fill_char2;
            playerCurrLocCol += 1;
            board[playerCurrLocRow][playerCurrLocCol] = Player;

            break;
        case 'w':
            board[playerCurrLocRow][playerCurrLocCol] = fill_char2;
            playerCurrLocRow -= 1;
            board[playerCurrLocRow][playerCurrLocCol] = Player;

            break;
        case 's':
            board[playerCurrLocRow][playerCurrLocCol] = fill_char2;
            playerCurrLocRow += 1;
            board[playerCurrLocRow][playerCurrLocCol] = Player;

            break;
        default:
            cout<<"Use w,a,s,d to move around."<<endl<<"'q' to quit";
            break;

    }
    cout<<endl<<endl;
}

//The main pipeline for the flow of game
void theGame(){
    int diff;
    while ((movement != 'q')){
           initBoard(board, fill_char);
        cout<<"Enter Difficulty (1, 2, 3)"<<endl;
        cin>>diff;
           charLocGen(board, diff, Row, Col);
           displayBoard(board);

           cout<<endl<<"Use w,a,s,d to move around."<<endl<<"'q' to quit"<<endl;

           while (movement != 'q'){
            cin>>movement;
            PlayerControls(board);
            system("CLS");
            displayBoard(board);

            }

        }

}


//Displays the game menu having interactable options
void gameMenu(){

    int userInput = 0;
    cout<<"1. START GAME"<<endl<<"2. INFO"<<endl<<"3. CREDITS"<<endl<<"4. Quit"<<endl<<endl;


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
            if(movement == 'q'){
                userInput = 4;
            }
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


    displayBoard(board);
    return 0;
}
