#include<iostream>
#include<string>
using namespace std;

bool isArthmetic(int hour,int min){
    if(min<=9){
        return false;
    }
    string s = to_string(hour)+to_string(min);
    int diff = s[0]-s[1];
    for(int i = 1;i<s.size()-1;i++){
        if(s[i]-s[i+1]!=diff){
            return false;
        }
    }
    return true;
}

int main(){
    int timePassed;
    cin>>timePassed;
    int hour = 12,min = 0,output = 0;
    output += 31*(timePassed/720);
    timePassed %= 720;
    for(int i = 0;i<timePassed;i++){
        min++;
        if(min>=60){
            min = 0;
            hour++;
            if(hour>12){
                hour = 1;
            }
        }
        if(isArthmetic(hour,min)){
            output++;
        }
    }
    cout<<output;
}