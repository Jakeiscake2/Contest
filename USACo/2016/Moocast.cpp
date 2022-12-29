#include<iostream>
#include<vector>
using namespace std;
struct cow{
    int x=0;
    int y=0;
    long long p=0;
};
int counter=0;
long long distance(long long  x1,long long  x2,long long  y1,long long  y2){
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}
void dfs(vector<vector<int>>&adj,vector<bool>&transmited,int start){
    transmited[start]=true;
    counter++;
    for(int i:adj[start]){
        if(transmited[i]==false){
            dfs(adj,transmited,i);
        }
    }
    return;
}
int main(){
     freopen("moocast.in","r",stdin);
     freopen("moocast.out","w",stdout);
   
    int n=0;
    cin>>n;
    vector<cow> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].x;
        cin>>v[i].y;
        cin>>v[i].p;
    }
    vector<vector<int>>adj(n);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            long long d=distance(v[i].x,v[j].x,v[i].y,v[j].y);
            if(v[i].p*v[i].p>=d){
                adj[i].push_back(j);
            }
            if(v[j].p*v[j].p>=d){
                adj[j].push_back(i);
            }
        }
    }
    
    int max=0;
    for(int i=0;i<n;i++){
        vector<bool>transmitted(n,false);
        if(transmitted[i]==false){      
            counter=0;
        dfs(adj,transmitted,i);
        if(counter>max){
            max=counter;
        }
        }
    }
    cout<<max;
}