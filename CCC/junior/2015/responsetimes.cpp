#include<iostream>
#include<map>
#include<vector>
using namespace std;
int main(){
    map<int,int> friendSent;
    map<int,int> friendSum;
    map<int,int> friendReplied;
    int n;
    cin>>n;
    int timer = 0;
    for(int i = 0;i<n;i++){
        char c;
        int x;
        cin>>c>>x;
        if(c=='R'){
            friendSent[x] = timer;
            friendReplied[x] -= 1;
            if(!(friendSum[x]>=0)){
                friendSum[x] = 0;
            }
        }
        else if(c=='S'){
            friendSum[x] += (timer-friendSent[x]);
            friendReplied[x] += 1;
        }
        if(c=='W'){
            timer += x;
            timer--;
        }
        else{
            timer++;
        }
    }
    cout<<endl;
    for(pair<int,int> p:friendSum){
        if(friendReplied[p.first]<0){
            cout<<p.first<<" -1"<<endl;

        }
        else{
            cout<<p.first<<" "<<p.second<<endl;
        }
    }
}

/*12 13
23 8
34 2
45 -1*/