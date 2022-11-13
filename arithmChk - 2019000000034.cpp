#include<iostream>
#include<stack>
#include<string.h>


using namespace std;
int top = -1;
bool isempty()
{
  if(top==-1)
  return true;
  else
  return false;
}

void push(int count, char st[], char value)
{
  if(top==count-1)
  {    cout<<"Stack is full!\n";
  }
   else
  {
    top++;
    //cout<<"value "<<value<<endl;
    st[top]=value;
    //cout<<"st top "<<st[top]<<endl;
    //cout<<"top "<<top<<endl;
  }
}

void pop()
{
 if(isempty()){
  cout<<"Stack is empty!\n";
 }

 else
  top--;
}

char st_top(char st[])
{
 if(isempty())
  cout<<"Stack is empty!\n";
 else return st[top];

}




int main(){

    char exprsn[100];
    int exprsn_length, count = 0;

    cout<<"Enter expression : ";
    cin>>exprsn;
    exprsn_length = strlen(exprsn);

    for(int i=0;i<exprsn_length;i++){
        if(exprsn[i]=='(') count++;
        else if(exprsn[i]=='{') count++;
        else if(exprsn[i]=='[') count++;
    }

    char st[count];
    int unlockSTR=0;
//     push(count,st,'1');
//     push(count,st,'23');
//     cout<<st_top(st);

    for(int i = 0;i<exprsn_length;i++){
        if(exprsn[i] == '(') push(count,st,exprsn[i]);

        else if(exprsn[i] == '{') push(count,st,exprsn[i]);

        else if(exprsn[i] == '[') push(count,st,exprsn[i]);

        else if(exprsn[i] == ')' ||exprsn[i] == '}' ||exprsn[i] == ']'){
          if(isempty()){
            cout<<"Invalid expression!!!"<<endl;
            return 0;
          }

          else{
                //cout<<"st top ->"<<st_top(st)<<"<---->"<<"exprsn[i] ->"<<exprsn[i];
            if(st_top(st) =='(' && exprsn[i] == ')'|| st_top(st) =='{' && exprsn[i] == '}' || st_top(st) =='[' && exprsn[i] == ']'){
                pop();
                //cout<<"poping done"<<endl;
            }
            else{
                cout<<"Invalid expression!!!"<<endl;
                return 0;
            }
          }
         }
    }

    if(isempty()) cout<<"Congratulation...Expression is valid..."<<endl;
    else cout<<"Invalid expression!!!"<<endl;



return 0;
}

/// d+[(a-b)*{m/(n+p)}]
/// d+(a-b)*{m/(n+p)}]
/// d+[(a-b)*{m/(n+p)}
