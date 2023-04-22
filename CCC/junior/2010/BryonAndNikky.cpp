#include<iostream>
using namespace std;
int main(){
    int a,b,c,d,s;
    cin>>c>>d>>a>>b>>s;
    int BryonTotal=0,BryonSteps=0,NikkyTotal=0,NikkySteps=0;

    while(true){
        if(BryonTotal+a>=s){
            BryonSteps += s-BryonTotal;
            break;
        }
        BryonSteps += a;
        BryonTotal += a;
        if(BryonTotal+b>=s){
            BryonSteps -= s-BryonTotal;
            break;
        }
        BryonSteps -= b;
        BryonTotal += b;
    }

    while(true){
        if(NikkyTotal+c>=s){
            NikkySteps += s-NikkyTotal;
            break;
        }
        NikkySteps += c;
        NikkyTotal += c;
        if(NikkyTotal+d>=s){
            NikkySteps -= s-NikkyTotal;
            break;
        }
        NikkySteps -= d;
        NikkyTotal += d;
    }

    if(BryonSteps>NikkySteps){
        cout<<"Byron";
    }
    else if(NikkySteps>BryonSteps){
        cout<<"Nikky";
    }
    else{
        cout<<"Tied";
    }
    //cout<<endl<<NikkySteps<<" "<<BryonSteps;
    return 0;
}