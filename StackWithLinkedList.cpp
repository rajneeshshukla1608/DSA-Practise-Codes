#include<bits/stdc++.h>
using namespace std;

class Stack{

    struct Node{
        int data;
        Node *next;
        Node(int d){
            data = d;
            next = NULL;
        };
    };

    Node *head;
    int size;

public:
    Stack(){
        head = NULL;
        size = 0;
    }

    bool empty(){
        return head == NULL;
    }

    void push(int data)
    {
        Node *newHead = new Node(data);
        if (empty())
        {
            head = newHead;
        }
        else
        {
            newHead->next = head;
            head = newHead;
        }
        size += 1;
    }

    void pop()
    {
        if (empty())
        {
            cout << "Stack Underflow" << endl;
            return;
        }
        else
        {
            Node *toDelete = head;
            head = head->next;
            free(toDelete);
            size -= 1;
        }
    }

    int top()
    {
        if (empty())
        {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        else
        {
            return head->data;
        }
    }

    int getSize()
    {
        return size;
    }

    void print()
    {
        if (empty())
        {
            cout << "Stack is empty" << endl;
            return;
        }
        else
        {
            Node *current = head;
            cout << "Top to bottom: ";
            while (current != NULL)
            {
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }
    }

};

int main(){
    Stack st = Stack();
    st.push(1);
    st.push(2);
    st.push(3);
    st.print();
    st.pop();
    st.print();
    st.pop();
    st.print();
    cout<<st.top()<<endl;
    cout<<st.getSize()<<endl;

    return 0;
}