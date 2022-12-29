#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<queue>
using namespace std;
struct cell{
    int x;
    int row;
    int col;
};
int main(){
    int m,n,x;
    cin>>m>>n;
    map<int,vector<pair<int,int>>> valueToCells;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cin>>x;
            valueToCells[x].push_back({i,j});
        }
    }
    //set<pair<int,int>> visted;
    vector<vector<bool>> visted(m+1,vector<bool>(n+1,false));
    queue<pair<int,int>> q;
    q.push({m,n});
    visted[m][n]=true;
    while(!q.empty()){
        int product=q.front().first*q.front().second;
        q.pop();
        for(pair<int,int> p:valueToCells[product]){
            if(p.first==1&&p.second==1){
                cout<<"yes";
                return 0;
            }
            if(!visted[p.first][p.second]){
                q.push({p.first,p.second});
                visted[p.first][p.second]=true;
            }
        }
    }
    cout<<"no";
    return 0;
}

