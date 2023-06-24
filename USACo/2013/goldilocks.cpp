#include<iostream>
#include<vector>   
#include<map>
using namespace std;
int main(){
    //freopen("milktemp.in", "r", stdin);
    //freopen("milktemp.out", "w", stdout);
    int n,cold,good,hott;
    cin>>n>>cold>>good>>hott;
    map<int,int> m;
    int goodvcold=good-cold;
    int hottvgood=hott-good;
    int n1,n2;
    for(int i=0;i<n;i++){
        cin>>n1>>n2;
        m[1]+=cold;
        m[n1]+=goodvcold;
        m[n2+1]+=hottvgood;
    }
    int start=0,most=0;
    for(pair<int,int> p:m){
        start+=p.second;
        most=max(most,start);
    
    }
    cout<<most;





}