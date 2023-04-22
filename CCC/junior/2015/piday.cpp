#include<iostream>
#include<map>
using namespace std;


map<pair<int,pair<int,int>>,int> visted;
int waysForPie(int people,int pies,int lastNumber){
    if(visted[{lastNumber,{people,pies}}]>=1){
        return visted[{lastNumber,{people,pies}}];
    }
    
    if(people==pies){
        return 1;
    }
    if(people==1){
        return 1;
    }
    int output = 0;
    for(int piesTaken = lastNumber;piesTaken<=pies/(people);piesTaken++){
        output += waysForPie(people-1,pies-piesTaken,piesTaken);
    }
    visted[{lastNumber,{people,pies}}] = output;
    return output;
}


int main(){
    int n,k;
    cin>>n>>k;
    cout<<waysForPie(k,n,1);
}

//cache the numbers
//so you dont