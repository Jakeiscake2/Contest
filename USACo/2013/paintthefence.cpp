#include<iostream>
#include<map>
#include<vector>
using namespace std;
int main(){
    //freopen("paint.in", "r", stdin);
    //freopen("paint.out", "w", stdout);
    int n,k;
    cin>>n>>k;
    int currentpos=0;
    int lowestpos=0;
    map<int,int>m;
    for(int i=0;i<n;i++){
        int steps;
        char direction;
        cin>>steps>>direction;
        int n1,n2;
        if(direction=='R'){
            n1=currentpos;
            currentpos+=steps;
            n2=currentpos;
        }
        else if(direction=='L'){
            n2=currentpos;
            currentpos-=steps;
            n1=currentpos;
        }
        m[n1]++;
        m[n2+1]--;
        lowestpos=min(lowestpos,currentpos);
    }
    int start=0;
    int lastindex=lowestpos;
    int count=0;
    for(pair<int,int> p:m){
        start+=p.second;
        if(start>=k){
            count+=p.first-lastindex-1;
            cout<<p.first<<" "<<lastindex<<endl;
        }
        lastindex=p.first;
    }
    cout<<count;
}

//[-11,-8], [-4,-3], and [0,2]