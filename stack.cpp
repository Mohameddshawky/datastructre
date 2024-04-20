#include <bits/stdc++.h>
#include <stdexcept>
using namespace std;
// linked stack
template<class t>
class Stack {
private:
    struct node {
        t val{};
        node *nextptr{};
    };
    node *top;
    int siz;
public:
    Stack() {
        top = nullptr;
        siz = 0;
    }
    void push(t newval) {
        node *newitem = new node;
        newitem->nextptr = top;
        newitem->val = newval;
        top = newitem;
        siz++;
    }

    bool isEmpty() const {
        return top == nullptr;
    }

    void pop() {
        if (isEmpty()) {
            throw out_of_range("Stack is empty");
        } else {
            node *temp = top;
            top = top->nextptr;
            temp = temp->nextptr = nullptr;
            delete temp;
            siz--;
        }
    }

    t Top() const {
        return !isEmpty() ? top->data : throw out_of_range("Stack is Empty!");
    }
    int size() const {
        return siz;
    }
    void print() const {
        node *temp = top;
        while (temp != nullptr) {
            cout << temp->val << " ";
            temp = temp->nextptr;
        }
        cout << "\n";
        delete temp;
    }
    void clear(){
        node*tmp=top;
        while (top!= nullptr){
            top=top->nextptr;
            delete tmp;
            tmp=top;
        }
        siz=0;
    }
};
int main() {
    Stack<int> st;

    return 0;
}
