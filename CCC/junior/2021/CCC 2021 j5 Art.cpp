#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(){
    int m,n,k;
    cin>>m>>n>>k;
    vector<int> rows(m,0);
    vector<int> cols(n,0);
    //starting code

    //inputed
    for(int i=0;i<k;i++){
        char c;
        cin>>c;
        int changedRowCol;
        cin>>changedRowCol;
        changedRowCol-=1;
        if(c=='R'){
            rows[changedRowCol]++;
        }
        else{
            cols[changedRowCol]++;
        }
    }

    //check the grid
    int output=0;
    for(int i:rows){
        for(int j:cols){
            if((i+j)%2==1){
                output++;
            }
        }
    }
    cout<<output;
}