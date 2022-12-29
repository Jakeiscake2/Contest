#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){
    string t,s;
    cin>>t>>s;
    for(int i=0;i<s.size();i++){
        if(t.find(s)!=string::npos){
            cout<<"yes";
            return 0;
        }
        s+=s[0];
        s.erase(s.begin());
    }
    cout<<"no";
    return 0;
}