#include <bits/stdc++.h>
using namespace std;
template<class t>
class Queue{
struct node{
    node*next{};
    t value{};
};
int siz;
node*first,*last;
public:
    Queue(){
        first=last= nullptr;
        siz=0;
    }
    bool isEmpty()const{
        return siz==0;
    }
    int size()const{
        return siz;
    }
    void enqueue(t element){
        node*newn=new node;
        newn->value=element;
        if (siz==0){
            first=last=newn;
        }
        else{
            last->next=newn;
            last=newn;
        }
        siz++;
    }
    void dequeue(){
        if (!isEmpty()){
            cout<<first->value<<"\n";
            node*temp=first;
            first=first->next;
            delete temp;
            siz--;
        }
        else{
            cout<<"Queue is Empty\n";
        }
    }
    void First()const{
        if (!isEmpty()){
            cout<<first->value<<"\n";
        }
        else{
            cout<<"Queue is Empty\n";
        }
    }
    void print()const{
        node*temp=first;
        while (temp!= nullptr){
            cout<<temp->value<<" ";
            temp=temp->next;
        }
        cout<<'\n';
    }
    void clear(){
        node*temp=first;
        siz=0;
        while (first!= nullptr){
            first=first->next;
            delete temp;
            temp=first;
        }
        delete first;
    }
};
int main() {
    Queue<string> q;
    q.enqueue("mo");
    q.enqueue("suii");
    q.enqueue("shawky");
    q.print();
    q.clear();
    q.enqueue("ahmed");
    q.print();
    cout << q.size();
    return 0;
}
