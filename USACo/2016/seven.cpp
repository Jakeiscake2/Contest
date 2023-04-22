#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int main(){
    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);
    int n;
    cin>>n;
    vector<long long> v(n+1,0);
    for(int i=0;i<n;i++){
        long long l;
        cin>>l;
        v[i+1]=v[i]+l;
    }
    vector<int> smol(7,INT_MAX);
    vector<int> bigg(7,INT_MIN);
    for(int i=0;i<v.size();i++){
        int remin=v[i]%7;
        if(smol[remin]==INT_MAX){
            smol[remin]=i;
        }
        bigg[remin]=max(bigg[remin],i);
    }
    int output=INT_MIN;
    for(int i=0;i<bigg.size();i++){
        output=max(output,bigg[i]-smol[i]);
    }
    cout<<output;
}