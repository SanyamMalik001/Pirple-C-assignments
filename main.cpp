#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void showBoard(char arr[][3]){
    cout<<"\t"<<arr[0][0]<<"|"<<arr[0][1]<<"|"<<arr[0][2]<<"|"<<endl;
    cout<<"\t"<<"-+-+-"<<endl;
    cout<<"\t"<<arr[1][0]<<"|"<<arr[1][1]<<"|"<<arr[1][2]<<"|"<<endl;
    cout<<"\t"<<"-+-+-"<<endl;
    cout<<"\t"<<arr[2][0]<<"|"<<arr[2][1]<<"|"<<arr[2][2]<<"|\n"<<endl;
}
int winnercheck(char arr[][3])
{
             if (arr[0][0]== arr[0][1] && arr[0][1]==arr[0][2]){
                return (1);}
             else if (arr[1][0]== arr[1][1] && arr[1][1]==arr[1][2]){
                return (2);}
             else if(arr[2][0]== arr[2][1] && arr[2][1]==arr[2][2]){
                return (3);}
             else if(arr[0][0]==arr[1][0] && arr[1][0]==arr[2][0]){
                return (4);}
             else if (arr[0][1]==arr[1][1] && arr[2][1]==arr[2][1]){
                return (5);}
             else if(arr[0][2]==arr[1][2] && arr[2][2]==arr[2][2]){
                return (6);}
             else if(arr[0][0]==arr[1][1] && arr[1][1]==arr[2][2]){
                return (7);
             }
             else if (arr[0][2]==arr[1][1] && arr[1][1]==arr[2][0]){
                return (7);
             }
             else{
                return 0;
             }}
void declarewinner(void *ending ,int ch, char arr[][3]){
            if( ch==1&&arr[0][0]== 'X' ){
                cout<<"Player X wins the top row. " <<endl;
                goto *ending;}
                else if ( ch==2&&arr[1][0]== 'X' ){
                cout<<"Player X wins the middle row. " <<endl;
                goto *ending;}
                else if (ch==3&&arr[2][0]== 'X'){
                cout<<"Player X wins the bottom row. " <<endl;
                goto *ending;}
                else if ( ch==4&&arr[0][1]== 'X' ){
                cout<<"Player X wins the left column. " <<endl;
                goto *ending;}
                else if ( ch==5&&arr[0][2]== 'X' ){
                cout<<"Player X wins the middle column. " <<endl;
                goto *ending;}
                else if ( ch==6&&arr[0][3]== 'X' ){
                cout<<"Player X wins the right column. " <<endl;
                goto *ending;}
                else if(ch==7&&((arr[0][0]== 'X' && arr[2][2]=='X')||(arr[2][0]=='X'&&arr[0][2]=='X'))){
                cout<<"Player X wins the diagonal. " <<endl;
                goto *ending;}
                else if( ch==1&&arr[0][0]== 'O' ){
                cout<<"Player Y wins the top row. " <<endl;
                goto *ending;}
                else if ( ch==2&&arr[1][0]== 'O' ){
                cout<<"Player Y wins the middle row. " <<endl;
                goto *ending;}
                else if (ch==3&&arr[2][0]== 'O'){
                cout<<"Player Y wins the bottom row. " <<endl;
                goto *ending;}
                else if ( ch==4&&arr[0][1]== 'O' ){
                cout<<"Player Y wins the left column. " <<endl;
                goto *ending;}
                else if ( ch==5&&arr[0][2]== 'O' ){
                cout<<"Player Y wins the middle column. " <<endl;
                goto *ending;}
                else if ( ch==6&&arr[0][3]== 'O') {
                cout<<"Player Y wins the right column. " <<endl;
                goto *ending;}
                else if(ch==7&&((arr[0][0]== 'O' && arr[2][2]=='O')||(arr[2][0]=='O'&&arr[0][2]=='O'))){
                cout<<"Player Y wins the diagonal. " <<endl;
                goto *ending;}}
int main()
{
    void *ending;
    char PLAYER_X = 'X', PLAYER_O = 'O';
    char lastPlayer = PLAYER_O, currentPlayer = PLAYER_X;
     char Arrchar[3][3] = {{'1','2','3'},
                    {'4','5','6'},
                    {'7','8','9'}};
        for (int x =1;x<10;x++){
    cout<< "\n Current board state \n"<<endl;
            showBoard(Arrchar);
            declarewinner(ending,winnercheck(Arrchar), Arrchar);
       choose: if(x%2==1)
         cout<<"Player X, enter a number between 1 and 9:"<<endl;
         else
        cout<<"Player Y, enter a number between 1 and 9:"<<endl;
         int chosenSquare;
         cin>> chosenSquare;
         if (chosenSquare==1 && Arrchar[0][0]== '1')
            Arrchar[0][0]= currentPlayer;
            else if (chosenSquare==2 && Arrchar[0][1]== '2')
            Arrchar[0][1]= currentPlayer;
            else if (chosenSquare==3 && Arrchar[0][2]== '3')
            Arrchar[0][2]= currentPlayer;
            else if (chosenSquare==4 && Arrchar[1][0]== '4')
            Arrchar[1][0]= currentPlayer;
            else if (chosenSquare==5 && Arrchar[1][1]== '5')
            Arrchar[1][1]= currentPlayer;
            else if (chosenSquare==6 && Arrchar[1][2]== '6')
            Arrchar[1][2]= currentPlayer;
            else if (chosenSquare==7 && Arrchar[2][0]== '7')
            Arrchar[2][0]= currentPlayer;
            else if (chosenSquare==8 && Arrchar[2][1]== '8')
            Arrchar[2][1]= currentPlayer;
            else if (chosenSquare==9 && Arrchar[2][2]== '9')
            Arrchar[2][2]= currentPlayer;
            else if (chosenSquare>9||chosenSquare<1){
            cout<<"Not a valid choice. Try again."<<endl;
            goto choose; }
            else{
            cout<<"That square is not available. Try again."<<endl;
            goto choose;  }
            if (x==9) { showBoard(Arrchar);}
            swap(lastPlayer, currentPlayer);}
            cout<<"Draw. Nobody Wins."<<endl;
    ending: return 0;}
