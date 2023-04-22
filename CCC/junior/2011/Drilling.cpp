#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main(){
    map<pair<int,int>,bool> visted;
    vector<pair<char,int>>encoded = {{'d',2},{'r',3},{'d',2},{'r',2},{'u',2},{'r',2},{'d',4},{'l',8},{'u',2}};
    pair<int,int> cords = {0,-1};
    char c;
    int i;
    bool danger = false;
    for(int j = 0;j<encoded.size();j++){
        c = encoded[j].first;
        i = encoded[j].second;
        int x_change = 0,y_change = 0;
        if(c=='u'){
            y_change = i;
        }
        else if(c=='d'){
            y_change = (-1*i);
        }
        else if(c=='l'){
            x_change = (-1*i);
        }
        else if(c=='r'){
            x_change = i;
        }
        else{
            return 0;
        }
        for(int j = 0;j<=i;j++){
            cords.first += x_change;
            cords.second += y_change;
            visted[cords] = true;
        }
    }
    while(true){
        cin>>c>>i;
        int x_change=0,y_change=0;
        if(c=='u'){
            y_change = i;
        }
        else if(c=='d'){
            y_change = (-1*i);
        }
        else if(c=='l'){
            x_change = (-1*i);
        }
        else if(c=='r'){
            x_change = i;
        }
        else{
            return 0;
        }
        for(int j = 0;j<i;j++){
            cords.first += x_change;
            cords.second += y_change;
            if(visted[cords]){
                danger = true;
            }
            visted[cords] = true;
        }
        cout<<cords.first<<" "<<cords.second;
            if(danger){
                cout<<" DANGER";
                return 0;
            }
            else{
                cout<<" safe";
            }
    }
}
/*
l 2
d 2
r 1
q 0


*/