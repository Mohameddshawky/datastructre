#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+1,m=65,mod=(1e9+7);

template<class tt>
class AVl{
    struct node{
        node*left,*right;
        tt data;
        int h;
        node(){
            left=right= nullptr;
            h=0;
        }
    };
    node* doubleWithLeftChild( node * k3 ) {
        k3->left= rotatewithrightchild(k3->left);
        k3= rotateWithLeftChild(k3);
        return k3;
    }
    node* doubleWithrightChild( node * k3 ) {
        k3->right= rotateWithLeftChild(k3->right);
        k3= rotatewithrightchild(k3);
        return k3;
    }
    node* rotateWithLeftChild(node*r) {
        node *k1 = r->left;
        r->left = k1->right;
        k1->right = r;
        r->h = max(height(r->left), height(r->right)) + 1;
        k1->h = max(height(k1->left), r->h) + 1;
        return k1;
    }
    node*rotatewithrightchild(node*r){
        node *temp=r->right;
        r->right=temp->left;
        temp->left=r;
        r->h = max(height(r->left), height(r->right)) + 1;
        temp->h = max( height( temp->right ), r->h ) + 1;
        return temp;
    }
    node* balanced(node*r){
        if (r== nullptr)
            return r;
        if( height( r->left ) - height( r->right ) > 1 ) {
            if (height(r->left->left) >= height(r->left->right))
                r=rotateWithLeftChild(r);
            else
                r= doubleWithLeftChild(r);
        }
        else{
            if( height( r->right ) - height( r->left ) > 1 ) {
                if (height(r->right->right) >= height(r->right->left))
                    r= rotatewithrightchild(r);
                else
                    r= doubleWithrightChild(r);
            }
        }
        r->h = max( height( r->left ), height( r->right ) ) + 1;
        return r;
    }
    node*root;
    int height(node*r)const{
        return r== nullptr?-1:r->h;
    }
    node* insert(tt dat,node*r){
        if (r== nullptr){
            node *newn=new node;
            newn->data=dat;
            r=newn;
        }
        else if (dat>r->data){
            r->right= insert(dat,r->right);
        }
        else{
            r->left= insert(dat,r->left);
        }
        return balanced(r);
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
    node *search(node *r, tt item) {
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
    node *Delete(node *r, tt item) {
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
        return balanced(r);
    }
public:
    AVl() {
        root = nullptr;
    }
    bool search(tt item) {
        node *fr = search(root,item );
        return !(fr == nullptr);
    }
    void insert(tt item) {
        root = insert( item,root);
    }
    tt min_element(){
        return mn(root)->data;
    }
    tt max_element(){
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
    void Delete_node(tt value){
        root=Delete(root,value);
    }
    void BFS(){
        queue<node*>q;
        q.push(root);
        while (!q.empty()){
            int sz=q.size();
            while (sz--){
                node *temp=q.front();
                q.pop();
                cout<<temp->data<<" "<<temp->h<<"//";
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
    AVl<int >t;
    t.insert(14);
    t.insert(17);
    t.insert(11);
    t.insert(7);
    t.insert(53);
    t.insert(4);
    t.insert(13);
    t.insert(12);
    t.insert(8);
     t.Delete_node(53);
    t.BFS();
    t.Delete_node(11);
    t.BFS();
    cout<<'\n';

    return 0;
}
