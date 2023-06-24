#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool checkifhaybales(vector<int>&haybales,int R,int k){
    int cowsneeded=1;
    int current=haybales[0];
        current+=2*R;
    for(int i=0;i<haybales.size();i++){
        if(current>=haybales[i]){
            continue;
        }
        else{
            cowsneeded++;
            current=haybales[i];
            current+=2*R;
        }
        if(cowsneeded>k){
            return false;
        }
    }
    return true;
}
int main()
{
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);
    int n,k;
    cin>>n>>k;
    if(n==1){
        return 1;
    }
    vector<int> haybales(n,9);
    for(int i=0;i<n;i++){
        cin>>haybales[i];
    }
    sort(haybales.begin(),haybales.end());
    int low=0;
    if(n==k){
        cout<<n;
    }
    int high=(haybales[n-1]);
    while(low<high){
        int middle=(low+high)/2;
        if(checkifhaybales(haybales,middle,k)){
            high=middle;
        }
        else{
            low=middle+1;
        }
    }
    cout<<low;
}