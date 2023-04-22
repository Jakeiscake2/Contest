#include<iostream>
#include<vector>
using namespace std;
int main(){
    string flips;
    cin>>flips;
    int hflips = 0,vflips = 0;
    for(char c : flips){
        if(c=='H'){
            hflips++;
        }
        else{
            vflips++;
        }
    }
    hflips %= 2;
    vflips %= 2;
    vector<vector<int>>board = {{1,2},{3,4}};
    if(hflips==1){
        swap(board[0],board[1]);
    }
    if(vflips==1){
        swap(board[0][0],board[0][1]);
        swap(board[1][0],board[1][1]);
    }
    cout<<board[0][0]<<" "<<board[0][1]<<endl<<board[1][0]<<" "<<board[1][1];
}