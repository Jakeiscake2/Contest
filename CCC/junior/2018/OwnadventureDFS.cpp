#include<iostream>
#include<vector>
#include<climits>
using namespace std;

vector<bool>pages;
int minSteps = INT_MAX;
vector<vector<int>> pageOptions;

void dfs(int pageNum,int stepsTaken){
    pages[pageNum] = true;
    if(pageOptions[pageNum].size()==0){
        minSteps = min(minSteps,stepsTaken);
        return;
    }
    for(int i : pageOptions[pageNum]){
        if(!pages[i]){
            pages[i] = true;
            dfs(i,stepsTaken+1);
        }
    }
}
int main(){
    int n;
    cin>>n;
    pages = vector<bool>(n+1,false);
    pages[0] = true;
    pageOptions = vector<vector<int>>(n+1);
    for(int i = 1;i<=n;i++){
        int options;
        cin>>options;
        for(int j = 0;j<options;j++){
            int add;
            cin>>add;
            pageOptions[i].push_back(add);
        }
    }
    dfs(1,1);
    bool allVisted = true;
    for(bool b : pages){
        if(!b){
            allVisted = false;
        }
    }
    if(allVisted){
        cout<<"Y"<<endl;
    }
    else{
        cout<<"N"<<endl;
    }
    cout<<minSteps;
}