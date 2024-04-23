#include <bits/stdc++.h>
using namespace std;
#define ll long long
template<class t>
class BST {
    struct node {
        node *left, *right;
        t data;
        node() {
            data = 0;
            left = right = nullptr;
        }
    };
private:
    node *root;
    node *insert(node *pn, t n) {
        if (pn == nullptr) {
            node *newn = new node;
            newn->data = n;
            pn = newn;
        } else if (n < pn->data) {
            pn->left = insert(pn->left, n);
        } else {
            pn->right = insert(pn->right, n);
        }
        return pn;
    }
    void pre(node *te) {
        if (te == nullptr) {
            return;
        }
        cout << te->data << " ";
        pre(te->left);
        pre(te->right);
    }

    void in(node *te) {
        if (te == nullptr) {
            return;
        }
        in(te->left);
        cout << te->data << " ";
        in(te->right);
    }

    void post(node *te) {
        if (te == nullptr) {
            return;
        }
        post(te->left);
        post(te->right);
        cout << te->data << " ";
    }

    node *search(node *r, t item) {
        if (r == nullptr)
            return nullptr;
        else if (r->data == item) {
            return r;
        } else if (item < r->data) {
            return search(r->left, item);
        } else {
            return search(r->right, item);
        }
    }
    node *mn(node *r) {
        if (r == nullptr) {
            return nullptr;
        }
        if (r->left == nullptr) {
            return r;
        } else
            return mn(r->left);
    }

    node *mx(node *r) {
        if (r == nullptr) {
            return nullptr;
        }
        if (r->right == nullptr) {
            return r;
        } else
            return mx(r->right);
    }

    node *Delete(node *r, t item) {
        if (r == nullptr) {
            return nullptr;
        } else if (item < r->data) {
            r->left = Delete(r->left, item);
        } else if (item > r->data) {
            r->right = Delete(r->right, item);
        } else {
            if (r->right == nullptr && r->left == nullptr) {
                delete r;
                r = nullptr;
            } else if (r->left == nullptr) {
                node *temp = r;
                r = r->right;
                delete temp;
            } else if (r->right == nullptr) {
                node *temp = r;
                r = r->left;
                delete temp;
            } else {
                node *temp = mn(r->right);
                r->data = temp->data;
                r->right = Delete(r->right, temp->data);
            }
        }
        return r;
    }
public:
    BST() {
        root = nullptr;
    }
    bool search(t item) {
        node *fr = search(root, item);
        return !(fr == nullptr);
    }
    void insert(t item) {
        root = insert(root, item);
    }
    t min_element(){
        return mn(root)->data;
    }
    t max_element(){
        return mx(root)->data;
    }
    bool Isempty(){
        return root== nullptr;
    }
    void Pre_order(){
        pre(root);
    }
    void Post_order(){
        post(root);
    }
    void IN_order(){
        in(root);
    }
    void Delete_node(t value){
        Delete(root,value);
    }
    void BFS(){
        queue<node*>q;
        q.push(root);
        while (!q.empty()){
            int sz=q.size();
            while (sz--){
                node *temp=q.front();
                q.pop();
                cout<<temp->data<<" ";
                if (temp->left!= nullptr)
                    q.push(temp->left);
                if (temp->right!= nullptr)
                    q.push(temp->right);
            }
            cout<<"\n";
        }
    }
};
int main() {
    BST<int> tre;
    tre.insert(12);
    tre.insert(15);
    tre.insert(17);
    tre.insert(13);
    tre.insert(5);
    tre.insert(7);
    tre.insert(9);
    tre.insert(3);
    tre.insert(1);
    tre.BFS();
    cout << '\n';
    tre.Delete_node( 1);
    tre.IN_order();
    return 0;
}
