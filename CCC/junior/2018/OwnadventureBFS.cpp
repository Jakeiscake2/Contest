#include<iostream>
#include<vector>
#include<climits>
#include<queue>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<bool>pages = vector<bool>(n+1,false);
    pages[0] = true;
    pages[1] = true;
    int minSteps = INT_MAX;
    vector<vector<int>> pageOptions = vector<vector<int>>(n+1);
    
    for(int i = 1;i<=n;i++){
        int options;
        cin>>options;
        for(int j = 0;j<options;j++){
            int add;
            cin>>add;
            pageOptions[i].push_back(add);
        }
    }
    queue<pair<int,int>> q;
    q.push({1,1});
    while(!q.empty()){
        int pageNum = q.front().first;
        int stepsTaken = q.front().second;
        q.pop();
        if(pageOptions[pageNum].size()==0){
            minSteps = min(minSteps,stepsTaken);
        }
        for(int i : pageOptions[pageNum]){
            if(!pages[i]){
                pages[i] = true;
                q.push({i,stepsTaken+1});
            }
        }
        
    }

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