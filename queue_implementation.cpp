#include<bits/stdc++.h>
using namespace std;
int Max=10;
class Queue{
    public:
        int*arr;
        int front;
        int back;
        Queue(void){
            arr=new int[Max];
            front=-1;
            back=-1;
        }
        bool isempty(void){
            if(front==-1&&back==-1) return true;
            else return false;
        }
        bool isfull(void){
            if(back+1==Max) return true;
            else return false;
        }
        void enqueue(int data){
            if(isfull()) cout<<"Queue is full\n";
            else if(isempty()){
                front=0;
                back=0;
                arr[back]=data;
            }else{
                back++;
                arr[back]=data;
            }
        }
        void dequeue(void){
            if(isempty()){
                cout<<"Queue is empty\n";
                return;
            }else if(front==back){
                front=back=-1;
            }
            else{
                front++;
            }
        }
        int peek(void){
            return arr[back];
        }
};
int main(){
    Queue q;
    q.enqueue(10);
    cout<<q.peek()<<endl;
    q.enqueue(100);
    cout<<q.peek()<<endl;
    q.enqueue(1000);
    cout<<q.peek()<<endl;
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    return 0;
}