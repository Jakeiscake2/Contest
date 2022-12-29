#include <iostream>
#include <vector>
using namespace std;
bool iscrossing(pair<int,int>& p1,pair<int,int>& p2){
    if(p1.first<p2.first){
        if(p1.second<p2.first){
            return false;
        }
        else if(p2.second<p1.second){
            return false;
        }
    }
    else if(p2.first<p1.first){
        if(p2.second<p1.first){
            return false;
        }
        else if(p1.second<p2.second){
            return false;
        }
    }
    return true;
}
int main(){
   // freopen("circlecross.in","r",stdin);
   // freopen("circlecross.out","w",stdout);
    string s = "";
    cin>>s;
    vector<pair<int,int>>p(26,{-1,-1});
    for(int i = 0; i<s.size(); i++){
        int num = s[i]-'A';
        if(p[num].first!=-1){
            p[num].second = i;
        }
        else{
            p[num].first = i;
        }
    }
    int output = 0;
    for(int i = 0; i<26; i++){
        for(int j = i+1; j<26; j++){
            if(iscrossing(p[i],p[j])){
                output++;
            }
        }
    }
    cout<<output;
}