#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    //freopen("diamond.in", "r", stdin);
    //freopen("diamond.out", "w", stdout);
    int n,k;
    cin>>n>>k;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    
    int i=0,j=0;
    vector<int>sum_at_point(n);
    while(j<n){
        if(v[j]-v[i]>k){
            sum_at_point[i]=v[j-1]-v[i]-1;
            i++;
            j=i;
        }
        j++;
    }
    
    vector<int>max_left(n);
    vector<int>max_right(n);

    for(int i=0;)
    

}

// 7,3
// [1,5,5,9,10,12,14]

//k=3
//[1,1,1,1,1,2]