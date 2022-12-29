#include<iostream>
#include<vector>
using namespace std;
int main(){
    freopen("planting.in","r",stdin);
     freopen("planting.out","w",stdout);
    
    int n=0;
    cin>>n;
    vector<vector<int>>v(n+1);
    for(int i=1;i<n;i++){
        int a1,a2;
        cin>> a1;
        cin>> a2;
        v[a1].push_back(a2);
        v[a2].push_back(a1);
    }
    int max=0;
    for(int i=0;i<v.size();i++){
        if(v[i].size()>max){
            max=v[i].size();
        }
    }
    cout<<max+1;
}