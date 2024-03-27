#include <bits/stdc++.h>
using namespace std;
template<class t>
class double_linked_list{
    struct node{
        t value{};
        node*next{},*prev{};
    };
    node*head,*tail;
    int siz;
public:
    double_linked_list(){
        head = tail = nullptr;
        siz=0;
    }
   void insetAtHead(t element){
        node*newn=new node;
        newn->value=element;
       if (!siz){
           newn->prev=newn->next= nullptr;
          head =tail =newn;
       }
       else{
           newn->next=head;
           head->prev=newn;
           newn->prev= nullptr;
           head=newn;
       }
       siz++;
    }
    void insertAtTail(t element){
        node*newn=new node;
        newn->value=element;
        if (!siz){
            newn->prev=newn->next= nullptr;
            head =tail =newn;
        }
        else{
            newn->prev=tail;
            newn->next= nullptr;
            tail->next=newn;
            tail=newn;
        }
        siz++;
    }
    void insertAt(t element,int index){
        if (index<0||index>siz){
            return;
        }
        else if (index==0){
            insetAtHead(element);
        }
        else if (index==siz){
            insertAtTail(element);
        }
        else{
            node*newn=new node,*temp=head;
            newn->value=element;
            for (int i = 0; i <index-1 ; ++i) {
                temp=temp->next;
            }
            newn->next=temp->next;
            newn->prev=temp;
            newn->next->prev=newn;
            temp->next=newn;
            siz++;
        }
    }
    void removeAtHead(){
        if (!siz){
            return;
        }
        node*temp=head;
        head=head->next;
        delete temp;
        head->prev= nullptr;
        siz--;
    }
    void removeAtTail(){
        if (!siz){
            return;
        }
        node*temp=tail;
        tail=tail->prev;
        delete temp;
        tail->next= nullptr;
        siz--;
    }
    void removeAt(int index){
        if (index<0||index>siz){
            return;
        }
        else if (index==0){
            removeAtHead();
        }
        else if (index==siz-1){
            removeAtTail();
        }
        else{
            node*temp=head;
            for (int i = 0; i <index ; ++i) {
                temp=temp->next;

            }
            temp->next->prev=temp->prev;
            temp->prev->next=temp->next;
            delete temp;
            siz--;
        }
    }
    bool isEmpty()const{
        return siz==0;
    }
    int doubleLinkedListSize()const{
        return siz;
    }
    void forwardTraversal()const{
        node*temp=head;
        while (temp!= nullptr){
            cout<<temp->value<<" ";
            temp=temp->next;
        }
        cout<<"\n";
    }
    void backwardTraversal()const{
        node*temp=tail;
        while (temp!= nullptr){
            cout<<temp->value<<" ";
            temp=temp->prev;
        }
        cout<<"\n";
    }
};
int main() {
double_linked_list<int>d;
d.insertAtTail(1);
    d.insertAtTail(3);
    d.insertAtTail(4);
    d.insetAtHead(0);
    d.insertAt(2,2);
    d.removeAt(4);
    d.forwardTraversal();
    d.backwardTraversal();
    cout<<d.doubleLinkedListSize();
d.insertAt(4,4);
    d.forwardTraversal();
    d.backwardTraversal();
    cout<<d.doubleLinkedListSize();
    return 0;
}
