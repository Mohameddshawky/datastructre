#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=7,M=65,mod=(1e9+7);
#define Fast ios_base::sync_with_stdio;cin.tie(0);cout.tie(0);
#define all(x) x.begin(),x.end()
// for separate chaning
class hasht {
private:
    struct node {
        int item;
        node *next;

        node(int data) : item(data), next(nullptr) {}
    };

    node *arr[N]{nullptr};

    int calc_inx(int key) {
        return key % N;
    }

public:
    void insert(int data) {
        int index = calc_inx(data);
        node *newn = new node(data), *temp = arr[index];
        if (arr[index] == nullptr)
            arr[index] = newn;
        else {
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newn;
        }
    }

    void print() {
        int i = 0;
        for (auto temp: arr) {
            cout << i++ << ": ";
            if (temp == nullptr) {
                cout << '\n';
            } else {
                while (temp != nullptr) {
                    cout << temp->item << " ";
                    temp = temp->next;
                }
                cout << "\n";
            }

        }
    }
       
    ~hasht() {
        for (auto current : arr) {
            while (current != nullptr) {
                node* next = current->next;
                delete current;
                current = next;
            }
        }
    }
};
int main() {
    Fast
hasht t;
    t.insert(15);
    t.insert(8);
    t.insert(11);    t.insert(27);
    t.print();

    return 0;
}
