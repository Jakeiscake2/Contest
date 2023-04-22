#include<iostream>
#include<map>
#include<vector>
using namespace std;

int favTeam=0,gamesPlayed=0;

char checker(int s1,int s2){
    if(s1>s2){
        return 'W';
    }
    else if(s1<s2){
        return 'L';
    }
    return 'T';
}

int checkPoints(map<pair<int,int>,char>m){
    vector<int> v(5,0);
    for(pair<pair<int,int>,char> p:m){
        if(p.second=='W'){
            v[p.first.first] += 3;
        }
        else if(p.second=='L'){
            v[p.first.second] += 3;
        }
        else if(p.second=='T'){
            v[p.first.second] += 1;
            v[p.first.first] += 1;
        }
    }
    for(int i = 1;i<v.size();i++){
        if(v[favTeam]<=v[i]&&favTeam!=i){
            return 0;
        }
    }
    return 1;
}

int gameCheck(map<pair<int,int>,char>m,int gamesToPlay){
    if(gamesToPlay==0){
        return checkPoints(m);
    }
    for(pair<pair<int,int>,char> p:m){
        if(p.second=='U'){
            int output = 0;
            m[p.first] = 'W';
            output += gameCheck(m,gamesToPlay-1);

            m[p.first] = 'L';
            output += gameCheck(m,gamesToPlay-1);

            m[p.first] = 'T';
            output += gameCheck(m,gamesToPlay-1);
            return output;
        }
    }
    return 123433;
}

int main(){


    
    cin>>favTeam>>gamesPlayed;
    map<pair<int,int>,char> m;

    for(int i = 1;i<=3;i++){
        for(int j = i+1;j<=4;j++){
            m[{i,j}] = 'U';
        }
    }
    for(int i = 0;i<gamesPlayed;i++){
        int t1,t2,s1,s2;
        cin>>t1>>t2>>s1>>s2;
        m[{t1,t2}] = checker(s1,s2);
    }
    cout<<gameCheck(m,6-gamesPlayed);
}
/*
1 2
1 3
1 4
2 3
2 4
3 4
*/
/*
3
3
1 3 7 5
3 4 0 8
2 4 2 2*/