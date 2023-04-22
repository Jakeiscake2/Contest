#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(){

//k-(prefix[k+i]-prefix[i-1])
//sliding window
//http://www.usaco.org/index.php?page=viewproblem2&cpid=715
    //freopen("hps.in","r",stdin);
    //freopen("hps.out","w",stdout);
    int n;
    cin>>n;
    vector<int> prefix(n+1,0);
    for(int i=1;i<n+1;i++){
        char c;
        cin>>c;
        p[i]=p[i-1];
        h[i]=h[i-1];
        s[i]=s[i-1];
        if(c=='H'){
            p[i]++;
        }
        else if(c=='P'){
            s[i]++;
        }
        else{
            h[i]++;
        }
    }
    int htotal=h[h.size()-1],stotal=s[s.size()-1],ptotal=p[p.size()-1];
    int mostwins=0;
    for(int i=0;i<h.size();i++){
        int h1=h[i],h2=htotal-h1;
        int p1=p[i],p2=ptotal-p1;
        int s1=s[i],s2=stotal-s1;
        mostwins=max(mostwins,h1+p2);
        mostwins=max(mostwins,h1+s2);
        mostwins=max(mostwins,p1+h2);
        mostwins=max(mostwins,p1+s2);
        mostwins=max(mostwins,s1+h2);
        mostwins=max(mostwins,s1+p2);
    }
    cout<<mostwins;
}
/*
1 D
2 D 
3
4
5 D
6
7
8
9 D
10 D

10 6 5
2
10
1
5
9

*/