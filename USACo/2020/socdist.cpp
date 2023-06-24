#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool trydistance(vector<pair<int,int>>&vp,int n, int d){
    int c1=-d-1;
    int cow_eating=0;
    for(int i=0;i<vp.size();i++){
        int start=vp[i].first;
        int end=vp[i].second;
        if(c1+d>start){
            start=c1+d;
            if(start>end){
                continue;
            }
        }
        int number_o_cows=(end-start+1)/d;
        cow_eating+=number_o_cows;
        c1=start+(number_o_cows-1)*d;
        if(cow_eating>=n){
            return true;
        }
    }
    return false;
}

int main(){

    //freopen("socdist.in","r",stdin);
    //freopen("socdist.out","w",stdout);

    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> vp(m);
    for(int i=0;i<m;i++){
        cin>>vp[i].first>>vp[i].second;
    }
    int low=0,high=vp[vp.size()-1].second-vp[0].first+1;
    while(low<high){
        int middle=(low+high)/2;
        if(trydistance(vp, n, middle)){
            low=middle;
        }
        else{
            high=middle-1;
        }
    }
    cout<<high;
}