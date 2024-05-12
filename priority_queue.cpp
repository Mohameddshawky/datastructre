#include <bits/stdc++.h>
#include <stdexcept>
using namespace std;
#define ll long long
const int N=1e5+2,M=65,mod=1073741824;
#define Fast ios_base::sync_with_stdio;cin.tie(0);cout.tie(0);

template<class t>
class Priority_queue{
    vector<t>v;// 0 based index
    int heap_size;
    int parent(int inx){
        return (inx-1)/2;
    }
    int left_child(int inx){
        return (inx*2)+1;
    }
    int right_child(int inx){
        return (inx*2)+2;
    }
    void rearrange(int inx){
        while (inx!=0 &&v[inx]>v[parent(inx)]){
            swap(v[inx],v[parent(inx)]);
            inx= parent(inx);
        }
    }
    void heapify(int i){
        int l= left_child(i);
        int r= right_child(i);
        int max=i;
        if (l < heap_size && v[l] > v[max])
            max = l;
        if (r < heap_size && v[r] > v[max])
            max = r;
        if (max != i) {
            swap(v[i], v[max]);
            heapify(max);
        }
    }
public:
    Priority_queue():heap_size(0){
    }
    void push(int value){
        v.push_back(value);
        heap_size++;
        int inx=heap_size-1;//bec i deal with zero based
        rearrange(inx);
    }
    int size() const{
        return heap_size;
    }
    t top(){
        return v[0];
    }
    bool Empty() const{
        return v.empty();
    }
    t pop(){
        if (heap_size==0){
            throw out_of_range("Priority_queue is empty");
        }
        else if (heap_size==1){
            t val=v.back();
            v.pop_back();
            heap_size--;
            return val;
        }
        t val=v.front();
        v[0]=v.back();
        v.pop_back();heap_size--;
        heapify(0);
        return val;
    }
};
int main() {
    Fast
    Priority_queue<int> m;
m.push(3);
    m.push(8);m.push(2);m.push(6);
    while (!m.Empty()){
       cout<<m.top()<<"\n";
       m.pop();
    }
    Priority_queue<char>p;
    p.push('d');
    p.push('z');
    p.push('a');
    while (!p.Empty()){
        cout<<p.top()<<"\n";
        p.pop();
    }
    return 0;
}
