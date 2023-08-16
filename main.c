#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

char board[3][3];
const char PLAYER = 'X';
const char COMPUTER = 'O';

void resetBoard();
void printBoard();
int checkFreeSpaces();
void playerMove();
void computerMove();
char checkWinner();
void printWinner(char);

int main(void){
    char winner = ' ';
    int turn = 0;
    resetBoard();
    while(winner == ' ' && checkFreeSpaces() != 0){
        printf("\nTurn: %d\n", turn);
        turn++;
        printBoard();
        playerMove();
        winner = checkWinner();
        if(winner != ' ' || checkFreeSpaces() == 0){
            break;
        }
        computerMove();
        if(winner != ' ' || checkFreeSpaces() == 0){
            break;
        }
    }
    printBoard();
    printWinner(winner);
    return 0;
}

void resetBoard(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            board [i][j] = ' ';
        }

    }

}
void printBoard(){
    for(int i = 0; i < 3; i++){
        printf(" %c | %c | %c ", board[i][0],board[i][1],board[i][2]);
        if(i != 2){
            printf("\n---|---|---\n");
        }
    }

}
int checkFreeSpaces(){
    int freeSpaces = 9;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(board[i][j] != ' '){
                freeSpaces--;
            }

        }

    }
    return freeSpaces;

}
void playerMove(){
    int x;
    int y;
    do{
        printf("\nEnter row#(1-3): ");
        scanf(" %d", &x);
        x--;

        printf("Enter columns#(1-3): ");
        scanf(" %d", &y);
        y--;

        if(board[x][y] != ' '){
            printf("Invalid move\n");
        }
        else{
            board[x][y] = PLAYER;
            break;
        }
    }while(board[x][y] != ' ');
}
void computerMove(){
    printf("\n COMPUTER MOVE");
    srand(time(0));
    int x;
    int y;
    if (checkFreeSpaces > 0){
        do{
            x = rand() % 3;
            y = rand() % 3;
            printf("%c", board[x][y]);
        }while(board[x][y] != ' ');
        board[x][y] = COMPUTER;}
    else{
        printWinner(' ');

    }
    }




char checkWinner(){
    for(int i = 0; i < 3; i++){
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2]){
            return board[i][0];
        }
    }
    // Check Columns
    for(int i = 0; i < 3; i++){
    if(board[0][i] == board[1][i] && board[2][i] == board[0][i]){
        return board[0][i];
    }
    }
    // Check Diagonals
    if(board[0][0] == board[1][1] && board[2][2] == board[0][0]){
        return board[0][0];
    }
    if(board[2][0] == board[1][1] && board[2][0] == board[0][2]){
        return board[2][0];
    }
    return ' ';

}
void printWinner(char winner){
    if (winner == PLAYER){
        printf("\nYou win!");
    }
    else if (winner == COMPUTER){
        printf("\nYou lose!");
    }
    else{
        printf("\nIt's a tie");
    }



}
