#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    freopen("haybales.in", "r", stdin);
    freopen("haybales.out", "w", stdout);
    int n,q;
    cin>>n>>q;
    vector<int> v(n+1);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    vector<int> ans(q);
    int last=v[v.size()-1];
    for(int i=0;i<q;i++){
        int start,end;
        cin>>start>>end;
        ans[i]=upper_bound(v.begin(),v.end(),end)-lower_bound(v.begin(),v.end(),start);
    }
    for(int i:ans){
        cout<<i<<endl;
    }
}