#include <iostream>
using namespace std;
template<class T>
struct Node{
public:
    Node*right;
    Node*left;
    Node*rchild;
    Node*lchild;
    bool leaf;
    T val;
    Node(){
        right= left= rchild= lchild=nullptr;
        leaf=true;
    }
    Node(T val):Node(){
        this->val=val;
    }
};
#define Node Node<T>
template<class T,int si>
class BTree{
private :
    int size;
    Node *root;
    Node*insert(Node *troot, Node* newnode){
        if(troot == nullptr || troot->leaf){
            if(troot == nullptr){
                root=newnode;
                return nullptr;
            }
            Node *temp=troot;
            while(temp->right != nullptr && temp->val < newnode->val)temp=temp->right;
            if(temp->right == nullptr && temp->val < newnode->val){
                temp->right=newnode;
                temp->right->left=temp;
            }
            else{
                if(temp->left != nullptr){
                    newnode->left=temp->left;
                    temp->left->right=newnode;
                    temp->left=newnode;
                    newnode->right=temp;
                }
                else {
                    newnode->right=temp;
                    temp->left=newnode, troot=newnode;
                }
            }
            int nkeys=1;
            temp=troot;
            while(temp->right != nullptr)nkeys++, temp=temp->right;
            if(nkeys == size)return split(troot);
            else return nullptr;
        }
        else{
            Node *temp=troot;
            while(temp->right != nullptr && temp->val < newnode->val)temp=temp->right;
            //newnode is the greatest val
            if(temp->right == nullptr and temp->val < newnode->val){
                Node*ret=insert(temp->rchild, newnode);
                if(ret== nullptr)temp->rchild=(temp->rchild->left != nullptr ? temp->rchild->left : temp->rchild);
                if(ret!=nullptr) {
                    temp->right = ret;
                    temp->rchild = ret->lchild;
                    ret->left=temp;
                    int nkeys=1;
                    temp=troot;
                    while(temp->right != nullptr)nkeys++, temp=temp->right;
                    if(nkeys == size)return split(troot);
                }
                else return nullptr;
            }
            else{
                Node*ret=insert(temp->lchild, newnode);
                if(ret==nullptr){
                    temp->lchild=(temp->lchild->left != nullptr ? temp->lchild->left : temp->lchild);
                    if(temp->left != nullptr)temp->left->rchild=temp->lchild;
                }

                if(ret!=nullptr){
                    if(temp->left != nullptr){
                        ret->left=temp->left;
                        temp->left->right=ret;
                        temp->left=ret;
                        ret->right=temp;
                        ret->left->rchild=ret->lchild;
                        temp->lchild=ret->rchild;
                    }
                    else{
                        ret->right=temp;
                        temp->left=ret;
                        temp->lchild=ret->rchild;
                        troot=(ret->left != nullptr ? ret->left : ret);
                    }
                    int numOfKeys=1;
                    temp=troot;
                    while(temp->right != nullptr)numOfKeys++, temp=temp->right;
                    if(numOfKeys==size)return split(troot);
                }
                return nullptr;
            }
            return nullptr;
        }
    }
    Node *split(Node *head){
        Node*temp=head;
        int mid=1;
        while(mid < ((size + 1) / 2)){
            mid++;
            temp=temp->right;
        }
        temp->leaf=false;
        temp->lchild=head;
        temp->rchild=temp->right;
        temp->left->right=temp->right->left=nullptr;
        temp->left=temp->right=nullptr;
        return temp;
    }
    void Print(Node *head,string s){
        if(head==nullptr)return;
        cout << s;
        Node*temp=head;
        while(temp->right!=nullptr){
            cout << temp->val << ',';
            temp=temp->right;
        }
        cout << temp->val << "\n";
        temp=head;
        Print(head->lchild, s + ' ');
        while(temp!=nullptr){
            Print(temp->rchild, s + ' ');
            temp=temp->right;
        }
    }
public :
    BTree(): root(nullptr) {
        size=si;
    }
    void Insert(T val){
        Node*temp=new Node(val);
        Node*rnode=insert(root, temp);
        if(rnode != nullptr){
            root=rnode;
        }
        while(root->left!=nullptr)root=root->left;
    }
    void Print(){
        Print(root,"");
    }
};
int main(){
    // Construct a BTree of order 3, which stores int data
    BTree<int,3> t1;
    t1.Insert(1);
    t1.Insert(5);
    t1.Insert(0);
    t1.Insert(4);
    t1.Insert(3);
    t1.Insert(2);
    t1.Print(); // Should output the following on the screen:
    /*
    1,4
      0
      2,3
      5
    */
    BTree <char,5> t;     // Construct a BTree of order 5, which stores char data, Look at the example in our lecture:
    t.Insert('G');
    t.Insert('I');
    t.Insert('B');
    t.Insert('J');
    t.Insert('C');
    t.Insert('A');
    t.Insert('K');
    t.Insert('E');
    t.Insert('D');
    t.Insert('S');
    t.Insert('T');
    t.Insert('R');
    t.Insert('L');
    t.Insert('F');
    t.Insert('H');
    t.Insert('M');
    t.Insert('N');
    t.Insert('P');
    t.Insert('Q');
    t.Print(); // Should output the following on the screen:
    /*
    K
      C,G
        A,B
        D,E,F
        H,I,J
      N,R
        L,M
        P,Q
        S,T
    */

    return 0;
}
