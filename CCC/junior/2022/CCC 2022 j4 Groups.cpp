#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(){
    int x=0;
    cin>>x;
    string add1,add2;
    vector<pair<string,string>> together;
    for(int i=0; i<x;i++){
        cin>>add1>>add2;
        together.push_back({add1,add2});
    }
    int y=0;
    cin>>y;
    string add3,add4;
    vector<pair<string,string>> apart;
    for(int i=0; i<y;i++){
        cin>>add3>>add4;
        apart.push_back({add3,add4});
    }
    int g=0;
    cin>>g;
    map<string,int> groups;
    string s;
    for(int i=0; i<g;i++){
        for(int j=0;j<3;j++){
            cin>>s;
            groups.insert({s,i});
        }
    }
    int numOfViolation=0;
    for(pair<string,string>p:together){
        if(groups[p.first]!=groups[p.second]){
            numOfViolation++;
        }
    }
    for(pair<string,string>p:apart){
        if(groups[p.first]==groups[p.second]){
            numOfViolation++;
        }
    }
    cout<<numOfViolation;

}

/*
3
A B
G L
J K
2
D F
D G
4
A C G
B D F
E H I
J K L
A 1
B 2
C 1
D 2
E 3
F 2
G 1
H 3
I 3
J 4
K 4
L 4


*/