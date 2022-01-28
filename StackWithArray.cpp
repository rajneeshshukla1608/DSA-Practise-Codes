#include<bits/stdc++.h>
using namespace std;

class Stack{
    int *arr;
    int max_size;
    int top;

public:
    Stack(int size = 10){
        arr = new int(size);
        max_size = size;
        top = -1;
    }
    
    int empty(){
        return top == -1;
    }

    bool full(){
        return (top + 1) == max_size;
    }

    void push(int data){
        if(full()){
            cout<<"Overflow"<<endl;
            return;
        } else {
            top++;
            arr[top] = data;
        }
    }

    void pop(){
        if(empty()){
            cout<<"underflow"<<endl;
            return;
        } else {
            top--;
        }
    }

    int get_top(){
        if(empty()){
            cout<<"Stack overflow"<<endl;
            return -1;

        } else {
            return arr[top];
        }
    }

    int size(){
        return top+1;
    }

    int maxSize(){
        return max_size;
    }

    void print(){
        cout<<endl;
        for(int i = 0; i < max_size; i++){
            cout<<arr[i]<<" ";
        }
    }
};

int main(){
    Stack st = Stack(5);
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.pop();
    st.print();
    st.maxSize();
    st.get_top();
    return 0;
}