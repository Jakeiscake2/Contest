#include<iostream>
#include<map>
#include<vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    map<string,string> m;
    vector<string> v1(n);
    vector<string> v2(n);
    
    for(int i = 0;i<n;i++){
        cin>>v1[i];
    }
    for(int i = 0;i<n;i++){
        cin>>v2[i];
    }
    for(int i = 0;i<n;i++){
        m[v1[i]] = v2[i];
    }
    for(int i = 0;i<n;i++){
        if(m[v2[i]]!=v1[i]){
            cout<<"bad";
            return 0;
        }
        else if(v1[i]==v2[i]){
            cout<<"bad";
            return 0;
        }
    }
    cout<<"good";
}

/*4
Ada Alan Grace John
John Grace Alan Ada
*/