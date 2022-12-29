#include <iostream>
#include <vector>
#include <map>
using namespace std;

int findBiggest(vector<pair<int,int>>& trees,int startRow,int startCol,int endRow,int endCol){

    for(pair<int,int>p:trees){
        int r = p.first;
        int c = p.second;
        if(r>=startRow&&r<=endRow&&c>=startCol&&c<=endCol){
            int top = findBiggest(trees,startRow,startCol,r-1,endCol);
            int bot = findBiggest(trees,r+1,startCol,endRow,endCol);
            int rig = findBiggest(trees,startRow,c+1,endRow,endCol);
            int lft = findBiggest(trees,startRow,startCol,endRow,c-1);
            return max(max(top,bot),max(rig,lft));
        }
    }
    return min(endRow-startRow+1,endCol-startCol+1);
}

int main(){
    int n;
    cin>>n;
    int t;
    cin>>t;
    vector<pair<int,int>> trees(t);
    for(int i = 0;i<t;i++){
        cin>>trees[i].first>>trees[i].second;
    }
    cout<<findBiggest(trees,1,1,n,n);

    /*
    int left=c-1,right=n-left-1,up=r-1,down=n-up-1;
    int col=max(left,right),row=max(up,down);
    int biggest=max(col,row);
    cout<<biggest;

    */
}