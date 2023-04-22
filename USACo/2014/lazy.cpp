#include<iostream>
#include<vector>   
#include<algorithm>
using namespace std;
int main(){
    freopen("lazy.in", "r", stdin);
    freopen("lazy.out", "w", stdout);
 int n,k;
 cin>>n>>k;
 vector<pair<int,int>> v(n);
 for(int i=0;i<n;i++){
    int grass,pos;
    cin>>grass>>pos;
    v[i]={pos,grass};
 }
 sort(v.begin(),v.end());
int left=0,right=0;
int grassamount=0;
int maxgrass=grassamount;
int bestpos=-1;
while(right<v.size()){
    while(v[right].first-v[left].first>k*2){
        grassamount-=v[left].second;
        left++;
    }
    while(v[right].first-v[left].first<=k*2){
        grassamount+=v[right].second;
        right++;
        maxgrass=max(maxgrass,grassamount);
    }
}
cout<<maxgrass;
}