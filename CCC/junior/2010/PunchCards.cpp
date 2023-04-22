#include<iostream>
using namespace std;
int main(){
    int A = 0, B = 0;
    int inputed = 8;
    while(inputed!=7){
        cin>>inputed;
        if(inputed==1){
            char c;
            cin>>c;
            if(c=='A'){
                cin>>A;
            }
            else{
                cin>>B;
            }
        }
        else if(inputed==2){
            char c;
            cin>>c;
            if(c=='A'){
                cout<<A<<endl;
            }
            else{
                cout<<B<<endl;
            }
        }
        else if(inputed==3){
            char x,y;
            cin>>x>>y;
            int n=B;
            if(y=='A'){
                n = A;
            }
            if(x=='A'){
                A += n;
            }
            else{
                B += n;
            }

        }
        else if(inputed==4){
            char x,y;
            cin>>x>>y;
            int n=B;
            if(y=='A'){
                n = A;
            }
            if(x=='A'){
                A *= n;
            }
            else{
                B *= n;
            }

        }
        else if(inputed==5){
            char x,y;
            cin>>x>>y;
            int n=B;
            if(y=='A'){
                n = A;
            }
            if(x=='A'){
                A -= n;
            }
            else{
                B -= n;
            }

        }
        else if(inputed==6){
            char x,y;
            cin>>x>>y;
            int n=B;
            if(y=='A'){
                n = A;
            }
            if(x=='A'){
                A /= n;
            }
            else{
                B /= n;
            }

        }
    }
}

/*
1 A 3
1 B 4
2 B
4
2 A
3
3 A B
2 A
7
5 A A
2 A
0
2 B
4
7
*/