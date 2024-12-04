#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=10,M=65,mod=(1e9+7);
#define Fast ios_base::sync_with_stdio;cin.tie(0);cout.tie(0);
#define all(x) x.begin(),x.end()
// for separate chaning
 int division_method(int key) {
        return key % N;
}
 int multiplication_method(int key){
     double a=0.618033;
    double t=((a*key*1.0)-int(a*key));
     return int(t*N);
 }
 int Mid_Square_Method(int key){
       string temp=to_string((key*key));
       string nb=to_string(N);
       int ans=nb.size()-1;
       int l=0,r=temp.size()-1;
     while (r-l-1>=ans+1){
         r--;
         l++;
     }
     int ans2= stoi(temp.substr(l,r-1));
     return ans2%N;
 }
 int folding_method(int key){
     string nkey=to_string(key),n=to_string(N);
     int cnt=n.size()-1,sum=0;
     for (int i = 0; i <nkey.size() ; i+=cnt) {
         string temp=nkey.substr(i,cnt);
         sum+= stoi(temp);
     }
     return sum%N;
 }
 int hash2(int key){
     return 7-(key%7);
 }
class hasht {
private:
    struct node {
        int item;
        node *next;
        node(int data) : item(data), next(nullptr) {}
    };
    node *arr[N]{nullptr};
public:
    void insert(int data) {
        int index = division_method(data);
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
 class openAdress_hash{
     pair<int,pair<bool,bool>>arr[N];
 public:  openAdress_hash(){
         for (int i = 0; i <N ; ++i) {
             arr[i].second.first=arr[i].second.second= false;
         }
     }
     void insert(int data){
         int inx= division_method(data),cnt=0;
         while (arr[inx].second.first){
             cnt++;
             inx= division_method(data+cnt);
         }
         arr[inx].first=data;
         arr[inx].second.first= true;
         arr[inx].second.second= false;
     }
     void remove(int data) {
         int inx = division_method(data), cnt = 0;
         while ((arr[inx].second.second || arr[inx].second.first)&&arr[inx].first!=data) {
             cnt++;
             inx = division_method(data + cnt);
         }
         if (arr[inx].first == data) {
             arr[inx].first = 0;
             arr[inx].second.first = false;
             arr[inx].second.second = true;
         }
     }
     void search(int data){
         int inx = division_method(data), cnt = 0;
         while ((arr[inx].second.second || arr[inx].second.first)&&arr[inx].first!=data) {
             cnt++;
             inx = division_method(data + cnt);
         }
         if (arr[inx].first == data) {
            cout<<"Found in index:"<<inx<<"\n";
         }
         else
             cout<<"Not Found\n";
     }
     void print(){
         for (auto & i : arr) {
             if (i.second.first)
                 cout<<i.first<<"\n";
             else
                 cout<<"Empty\n";
         }
     }
 };
 class double_hash{
     pair<int,pair<bool,bool>>arr[N];
 public:
     double_hash(){
         for (auto & i : arr) {
             i.second.first=i.second.second= false;
         }
     }
     void insert(int data){
         int cnt=0;
         int inx = (division_method(data)+(cnt* hash2(data)))%N;
         while ((arr[inx].second.second || arr[inx].second.first)&&arr[inx].first!=data) {
             cnt++;
             inx = (division_method(data)+(cnt* hash2(data)))%N;
         }
         arr[inx].first=data;
         arr[inx].second.first= true;
         arr[inx].second.second= false;
     }
     void remove(int data) {
         int cnt=0;
         int inx = (division_method(data)+(cnt* hash2(data)))%N;
         while ((arr[inx].second.second || arr[inx].second.first)&&arr[inx].first!=data) {
             cnt++;
             inx = (division_method(data)+(cnt* hash2(data)))%N;
         }
         if (arr[inx].first == data) {
             arr[inx].first = 0;
             arr[inx].second.first = false;
             arr[inx].second.second = true;
         }
     }
     void search(int data){
         int cnt=0;
         int inx = (division_method(data)+(cnt* hash2(data)))%N;
         while ((arr[inx].second.second || arr[inx].second.first)&&arr[inx].first!=data) {
             cnt++;
             inx = (division_method(data)+(cnt* hash2(data)))%N;
         }
         if (arr[inx].first == data) {
             cout<<"Found in index:"<<inx<<"\n";
         }
         else
             cout<<"Not Found\n";
     }
     void print(){
         for (auto & i : arr) {
             if (i.second.first)
                 cout<<i.first<<"\n";
             else
                 cout<<"Empty\n";
         }
     }
 };
int main() {
    Fast
 openAdress_hash h;
    h.insert(7);h.insert(36);h.insert(18);h.insert(62);
    h.print();
    cout<<"--------------------------------------------\n";
    h.search(1);
    h.remove(18);
    h.print();
    h.search(18);
    cout<<"--------------------------------------------\n";
    h.insert(18);
    h.print();

    return 0;
}
