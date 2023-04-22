#include<vector>
#include<iostream>
#include<string>
#include<map>
using namespace std;

string endingString;
vector<string> in(3);
vector<string> out(3);
int maxSteps;
map<pair<string,int>,bool> visted;


struct Step{
    int ruleUsed;
    int positionUsed;
    string resultingString;
};


void findPath(int stepsTaken,const string& current,vector<Step>& pathToGetHere){
    if(current==endingString&&stepsTaken==maxSteps){
        for(Step s : pathToGetHere){
            cout<<s.ruleUsed+1<<" "<<s.positionUsed+1<<" "<<s.resultingString<<endl;
        }
        exit(0);
    }
    if(stepsTaken==maxSteps){
        return;
    }
    if(visted[{current,stepsTaken}]){
        return;
    }
    for(int i = 0;i<3;i++){
        int foundPos = current.find(in[i],0);
        while(foundPos!=string::npos){
            string next = current.substr(0,foundPos)+out[i]+current.substr(foundPos+in[i].size());
            pathToGetHere.push_back({i,foundPos,next});
            findPath(stepsTaken+1,next,pathToGetHere);
            visted[{current,stepsTaken}] = true;
            pathToGetHere.pop_back();
            foundPos = current.find(in[i],foundPos+1);
        }
    }
}

int main(){
    cin>>in[0];
    cin>>out[0];
    cin>>in[1];
    cin>>out[1];
    cin>>in[2];
    cin>>out[2];
    string start;
    cin>>maxSteps>>start>>endingString;
    vector<Step> output;
    findPath(0,start,output);
}

//use map<pair<string,int>>,bool> as a visted to decrease time used
