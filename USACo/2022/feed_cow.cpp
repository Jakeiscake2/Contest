#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<map>
using namespace std;


int main(){
    int T = 0;
    cin>>T;
    vector<pair<int,string>> output;
    for(int testcase = 0;testcase<T;testcase++){
        int N,K;
        cin>>N>>K;
        string line;
        cin>>line;
        int patches = 0;
        string field = "";
        for(int i = 0;i<N;i++){
            field += '.';
        }
        int lastPatchG = -K -1;
        int lastPatchH = lastPatchG;
        for(int lineNum = 0;lineNum<N;lineNum++){
            if(line[lineNum]=='G'){
                if(lineNum-lastPatchG>K){
                    //too far to reach, needs a patch
                    if(K+lineNum>=N){
                        if(field[N-1]!='.'){
                            lastPatchG = N-2;
                        }
                        else{
                            lastPatchG = N-1;
                        }
                    }
                    else{
                        if(field[K+lineNum]!='.'){
                            lastPatchG = K+lineNum-1;
                        }
                        else{
                            lastPatchG = K+lineNum;
                        }
                    }
                    field[lastPatchG] = 'G';
                    patches++;
                }
                
            }
            else if(line[lineNum]=='H'){
                if(lineNum-lastPatchH>K){
                    //too far to reach, needs a patch
                    if(K+lineNum>=N){
                        if(field[N-1]!='.'){
                            lastPatchH = N-2;
                        }
                        else{
                            lastPatchH = N-1;
                        }
                    }
                    else{
                        if(field[K+lineNum]!='.'){
                            lastPatchH = K+lineNum-1;
                        }
                        else{
                            lastPatchH = K+lineNum;
                        }
                    }
                    field[lastPatchH] = 'H';
                    patches++;
                }
            }
        }
        output.push_back({patches,field});
    }
    for(pair<int,string>p:output){
        cout<<p.first<<endl<<p.second<<endl;
    }






}

/*


22
.HG.HG..GH..HG.HG.HG..HG..HG..GH..GHHG
2
......................................HG
10
..H....HG....G....G.H....H..G.H...H
17
.HG.H..G..G..G.HG.HG..G..G..G.H..H..H.H
4
.............H...G...............GH
21
.H..GH..HG..H.G.HG..GH..GH.GH..HG.HG..HG
18
.GH..H.G.H..H..HG..H..GH..G.H.GH..GH.G
15
.GH..H..H..H..HG..G..G..G..G..G..G.H..H.
8
....H.G.......H..G......H.G........HG...
2
..........................G.......H

*/