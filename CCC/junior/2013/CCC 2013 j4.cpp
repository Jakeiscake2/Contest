#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int time,n;
    cin>>time>>n;
    vector<int> v(n);
    for(int i = 0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    int counter = 0;
    for(int i : v){
        if(i>time){
            break;
        }
        time -= i;
        counter++;
    }
    cout<<counter;
}