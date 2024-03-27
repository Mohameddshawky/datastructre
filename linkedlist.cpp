#include <bits/stdc++.h>
using namespace std;
template<class t>
class linkedlist{
    struct node {
        node *next{};
        t item{};
    };
    node*head,*tail;
    int siz;
public:
    linkedlist(){
        siz=0;
        head=tail= nullptr;
    }
    void insertAtHead(t elem){
        node*newn=new node;
        newn->item=elem;
        if (siz==0){
            head=tail=newn;
        }
        else{
            newn->next=head;
            head=newn;
        }
        siz++;
    }
    void insertAtTail(t elem){
        node*newn=new node;
        newn->item=elem;
        if (siz==0){
            head=tail=newn;
        }
        else{
            tail->next=newn;
            newn->next= nullptr;
            tail=newn;
        }
        siz++;
    }
    void insertAt(t elem,int pos){
        if (pos==0)
            insertAtHead(elem);
        else if (pos==siz)
            insertAtTail(elem);
        else{
            node*newn=new node;
            newn->item=elem;
            node*curr=head;
            for (int i = 0; i <pos-1 ; ++i) {
                curr=curr->next;
            }
            newn->next=curr->next;
            curr->next=newn;
            siz++;
        }
    }
    void removeAtHead(){
        if (siz==0)
            return;
        if (siz==1){
            delete head;
            head=tail= nullptr;
            siz--;
        }
        else {
            node *temp = head;
            head = head->next;
            delete temp;
            siz--;
        }
    }
    void removeAtTail(){
        if (siz==0)
            return;
        if (siz==1){
            delete tail;
            head=tail= nullptr;
            siz--;
        }
        else {
            node *temp = head;
            for (int i = 0; i <siz-2 ; ++i) {
                temp=temp->next;
            }
            delete tail;
            tail=temp;
            temp->next= nullptr;
            siz--;
        }
    }
    void removeAt(int inx){
        if (siz==0||inx>siz)
            return;
        else if (inx==0)
            removeAtHead();
        else if (inx==siz-1)
            removeAtTail();
        else{
            node*cur=head->next,*prev=head;
            for (int i = 0; i <inx-1 ; ++i) {
                cur=cur->next;
                prev=prev->next;
            }
            prev->next=cur->next;
            delete cur;
            siz--;
        }
    }
    bool isItemAtEqual (t element, int index)const{
        if (index>siz)return false;
        node*temp=head;
        for (int i = 0; i <index ; ++i) {
            temp=temp->next;
        }
        return (temp->item==element);
    }
    void replaceAt (t newElement, int index){
        if (index>siz)return;
        node*temp=head;
        for (int i = 0; i <index ; ++i) {
            temp=temp->next;
        }
        temp->item=newElement;
    }
    bool isEmpty()const{
        return (siz==0);
    }
    int listsize()const{
        return siz;
    }
    void clear(){
        node*temp=head,*temp2=head->next;
        while (temp2!=tail){
            delete temp;
            temp=temp2;
            temp2=temp2->next;
        }
        delete temp2;
        siz=0;
    }
    void print()const{
        node*curr=head;
        for (int i = 0; i < siz; ++i) {
            cout<<curr->item<<" ";
            curr=curr->next;
        } cout<<"\n";
    }
    void destroy(){
        node*temp=head;
        while (head!= nullptr){
            temp=head;
            head=head->next;
            delete temp;
        }
        tail= nullptr;
        siz=0;
    }
    ~linkedlist(){
        destroy();
    }
};
int main() {
    linkedlist<int>l;
    l.insertAtTail(1);
    l.insertAtTail(3);
    l.insertAtHead(0);
    l.removeAtTail();
    l.print();
l.destroy();
l.print();
    return 0;
}
