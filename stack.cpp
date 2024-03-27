#include <bits/stdc++.h>
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
        //we must write this first bec it would be allocated on the stack and would be destroyed when the function or block goes out of scope. Using new, the node is allocated on the heap, and it remains in existence until explicitly deallocated using delete or until the program ends.
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
            cout << "Stack is empty\n";
        } else {
            node *temp = top;
            top = top->nextptr;
            temp = temp->nextptr = nullptr;
            delete temp; //to delete or free memory to avoid memory leak
            siz--;
        }
    }

    t Top() const {
        return top->val;
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
    st.push(3);
    st.push(5);
    cout << st.Top() << "\n";
    cout << st.size() << "\n";
    st.push(11);
    st.print();
    st.clear();
    cout << st.size() << "\n";
    cout<<(st.isEmpty()?"YES\n":"NO\n");
   Stack<string>ss;
    ss.push("mo");
    ss.push("shawky");
    ss.push("suiiiii");
    cout << ss.Top() << "\n";
    cout << ss.size() << "\n";
    ss.print();
    return 0;
}
