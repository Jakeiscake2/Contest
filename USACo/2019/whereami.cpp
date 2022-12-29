#include <iostream>
#include <vector>
#include <set>
#include <climits>
using namespace std;

int main(){

    freopen("whereami.in","r",stdin);
    freopen("whereami.out","w",stdout);
    int n = 0;
    cin>>n;
    string s = "";
    cin>>s;
    for(int k = 1;k<s.size();k++){
        set<string>se;
        bool repeat = false;
        for(int j = 0;j<s.size()-k+1;j++){
            string add = s.substr(j,k);
            if(se.find(add)!=se.end()){
                repeat = true;
                break;
            }
            se.insert(add);
        }
        if(!repeat){
            cout<<k;
            return 0;
        }
    }
    cout<<n;
}