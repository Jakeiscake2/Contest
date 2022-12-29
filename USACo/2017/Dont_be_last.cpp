#include <iostream>
#include <vector>
#include <map>
#include <climits>
using namespace std;

int main(){

    freopen("notlast.in","r",stdin);
    freopen("notlast.out","w",stdout);
    map<string,int>m = {{"Bessie",0},{"Elsie",0},{"Daisy",0},{"Gertie",0},{"Annabelle",0},{"Maggie",0},{"Henrietta",0}};
    int n = 0;
    cin>>n;
    for(int i = 0;i<n;i++){
        string s = "";
        int add = 0;
        cin>>s>>add;
        m[s] += add;
    }
    pair<string,int>least = {"",INT_MAX};
    for(pair<string,int>p:m){
        if(least.second>p.second){
            least = p;
        }
    }
    pair<string,int>secondleast = {"Tie",INT_MAX};
    int equaltosecond = 0;
    for(pair<string,int>p:m){
        if(p.second>least.second&&secondleast.second>p.second){
            secondleast = p;
            equaltosecond = 0;
        }
        else if(p.second==secondleast.second&&p.first!=secondleast.first){
            equaltosecond = 1;
        }
    }
    if(equaltosecond>=1){
        secondleast.first = "Tie";
    }
    cout<<secondleast.first;
}