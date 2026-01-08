#include <iostream>
#include <string>
using namespace std;

int stk[10000];
int s_top=0;

//스택 동작 함수
void push(int a){
    stk[s_top] = a;
    s_top++;
}
int pop(){
    if(s_top == 0) return -1;
        return stk[--s_top];
}
int size(){
    return s_top;
}
int empty(){
    if(s_top == 0)
        return 1;
    else 
        return 0;
}
int top(){
    if(s_top == 0) return -1;
        return stk[s_top -1];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    //명령 수행 횟수만큼 반복
    for(int i=0; i<n; i++){
        string command;
        cin >> command;

        if(command == "push"){
            int num;
            cin >>num;
            push(num);
        }else if(command == "pop"){
            cout << pop() << "\n";
        }else if(command == "size"){
            cout << size() << "\n";
        }else if(command == "empty"){
            cout << empty() << "\n";
        }else if(command == "top"){
            cout << top() << "\n";
        }
    }
    
    return 0;
}