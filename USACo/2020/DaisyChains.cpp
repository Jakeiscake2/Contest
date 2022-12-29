#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n=0;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int output=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int sum=0;
            for(int k=i;k<=j;k++){
                sum+=v[k];
            }
            int count=j-i+1;
            for(int k=i;k<=j;k++){
                if(v[k]*count==sum){
                    output++;
                    break;
                }
            }
        }
    }
    cout<<output;
}
