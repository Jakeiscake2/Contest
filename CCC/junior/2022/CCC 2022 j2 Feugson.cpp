#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(){
    int n=0;
    cin>>n;
    int better=0;
    for(int i=0;i<n;i++){
        int score,foul;
        cin>>score>>foul;
        if((score*5)-(3*foul)>40){
            better++;
        }
    }
    cout<<better;
    if(better==n){
        cout<<'+';
    }

}