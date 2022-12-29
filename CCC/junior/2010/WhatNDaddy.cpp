#include<iostream>
using namespace std;
int main(){
    int n;
        cin>>n;
        int ways = 0;
        for(int i = 0;i<=n/2;i++){
            if(i>5||n-i>5){
                continue;
            }
            ways++;
        }
        cout<<ways;
    }