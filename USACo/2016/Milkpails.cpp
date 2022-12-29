#include<iostream>
#include<vector>
using namespace std;
int main(){
    
    //freopen("pails.in","r",stdin);
    //freopen("pails.out","w",stdout);
     
    int x,y,m;
    cin>>x>>y>>m;
    int t=m;
    int minimum=100117 ;
    for(int i=0;i<=m/x;i++){
        t-=i*x;
        t=t%y;
        minimum=min(minimum,t);
        t=m;
    }
    cout<< m-minimum;
}

