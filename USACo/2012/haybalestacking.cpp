#include<iostream>
#include<vector>   
#include<algorithm>
using namespace std;
int main(){
    freopen("stacking.in", "r", stdin);
    freopen("stacking.out", "w", stdout);
    int n,k;
    cin>>n>>k;
    vector<int> v(n+1,0);
    for(int i=0;i<k;i++){
        int n1,n2;
        cin>>n1>>n2;
        v[n1]++;
        if(n2!=n){
            v[n2+1]--;
        }
    }
    for(int i=1;i<n+1;i++){
        v[i]+=v[i-1];
    }
    sort(v.begin(),v.end());
    cout<< v[(n+1)/2];
    //0 1 <2> 3 
    //0 1 2 <3> 4 5
    //0 1 2 3 <4> 5 6 7




}