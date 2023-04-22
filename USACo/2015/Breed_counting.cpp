#include<iostream>
#include<vector>

using namespace std;
int main(){
    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);
    int n,q;
    cin>>n>>q;
    vector<int>h(n+1,0);
    vector<int>g(n+1,0);
    vector<int>j(n+1,0);
    for(int i=1;i<n+1;i++){
        h[i]=h[i-1];
        g[i]=g[i-1];
        j[i]=j[i-1];
        char c;
        cin>>c;
        if(c=='1'){
            h[i]++;
        }
        else if(c=='2'){
            g[i]++;
        }
        else{
            j[i]++;
        }
    }
    for(int i=0;i<q;i++){
        int l,r;
        cin>>l>>r;
        cout<<h[r]-h[l-1]<<" "<<g[r]-g[l-1]<<" "<<j[r]-j[l-1]<<endl;
    }
}