#include<iostream>
#include<vector>
#include<map>
#include<stack>
using namespace std;



int movingCoins(vector<stack<int>> v,map<vector<stack<int>>,bool> m,int steps){
    if(m[v]){
        return 0;
    }
    m[v] = true;
    steps++;
    for(int i = 0;i<v.size();i++){
        if(v[i].size()==0){
            continue;
        }
        if(i+1<v.size()){
            
        }
        if(v[i+1].size()==0||v[i].top()<v[i+1].top()){
            v[i+1].push(v[i].top());
            if(v[i].size()==1){
                v[i].top() = 0;
            }
            else{
                v[i].pop();
            }
        }
    }
}


int main(){
    int n = 1;
    while(n!=0){
        cin>>n;
        vector<stack<int>> v(n);
        map<vector<stack<int>>,bool> m;
        for(int i = 0;i<n;i++){
            int add;
            cin>>add;
            v[i].push(add);
        }
        int moves_needed = movingCoins(v,m,0);
        if(moves_needed==0){
            cout<<"IMPOSSIBLE\n";
        }
        else{
            cout<<moves_needed<<endl;
        }
    }
}