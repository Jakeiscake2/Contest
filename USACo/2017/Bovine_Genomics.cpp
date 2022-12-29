#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(){

    freopen("cownomics.in","r",stdin);
    freopen("cownomics.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<string>spotted(n);
    vector<string>plain(n);

    for(int i = 0;i<n;i++){
        cin>>spotted[i];
    }

    for(int i = 0;i<n;i++){
        cin>>plain[i];
    }

    int output = 0;
    for(int col = 0;col<m;col++){
        set<char> s;

        for(int row = 0;row<n;row++){
            s.insert(plain[row][col]);
        }
        bool works = true;
        for(int row = 0;row<n;row++){
            if(s.find(spotted[row][col])!=s.end()){
                works = false;
                break;
            }
        }
        if(works){
            output++;
        }
    }
    cout<<output;
}
/*
5 10
GCCGC
CCCA
CCTCT
CCTTG
GCGTC

AGAAG
TAATC
TTCGA
ATTCG
AAATG

*/