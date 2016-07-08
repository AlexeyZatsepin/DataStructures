#include <iostream>
#include "vector.h"
#include "unordered_set.h"
#include "linked_list.h"
#include "unordered_map.h"
#include "queue.h"
#include "heap.h"

using std::cout;
using std::string;
using std::endl;

void print(const unordered_set<char> &s) {
    for (auto i : s) {
        cout << i << endl;
    }
}
int main() {
    #ifdef _DEBUG
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    //_CrtSetBreakAlloc(401);
    //_CrtSetBreakAlloc(551);
    //_CrtSetBreakAlloc(701);
    /*_CrtMemState _ms;
    _CrtMemCheckpoint(&_ms);*/
    #endif
    vector<size_t> v1;
    cout << "====array=add====" << endl;
    for (size_t i = 0; i < 20; i++) {
        v1.add(i + 1);
    }
    for (size_t i = 0; i < v1.getSize(); ++i) {
        std::cout << v1.get(i) << std::endl;
    }

    std::cout << "===array=insert====" << std::endl;
    v1.insert(2, 55);
    for (size_t i = 0; i < v1.getSize(); ++i) {
        std::cout << v1.get(i) << std::endl;
    }

    cout << "===array=remove=====" << endl;
    v1.remove(4);
    for (size_t i = 0; i < v1.getSize(); ++i) {
        std::cout << v1.get(i) << std::endl;
    }

    cout << "===array=Iterator=====" << endl;
    vector<size_t> v(v1);
    for (vector<size_t>::Iterator i = v.begin(); i != v.end(); ++i) {
        cout << *i << endl;
    }
    cout << "===array=Iterator=====" << endl;
    for (auto i : v) {
        cout << i << endl;
    }


    cout << "=========SET=add=======" << endl;
    unordered_set<size_t> set;
    for (size_t k = 0; k < 20000; ++k) {
        set.add(k);
    }
    cout << "Set size: " << set.getSize() << endl;
    cout << "=======SET==Iterator======" << endl;

    for (size_t i : set) {
        cout << i << endl;
    }

    cout << "=======SET==Iterator=Char=====" << endl;
    unordered_set<char> strset;
    for (auto x = 'a'; x < 'z'; x++) {
        strset.add(x);
    }
    for (auto item : strset) {
        cout << item << endl;
    }
    cout << "------" << endl;
    print(strset);

    cout << "---------list---------"<<endl;
    linked_list<int> list;
    for (int i : set) {
        list.add(i);
    }
    cout << list.contains(200)<<endl;
    cout << list.contains(200000000)<<endl;
    list.clear();

    list.add(1);
    list.add(2);
    list.add(3);
    cout << "----------list---get-------"<<endl;
    cout<<list.get(0)<<endl;
    cout<<list.get(1)<<endl;
    cout<<list.get(2)<<endl;
    list.remove(2);
    cout << "---------list---remove-------"<<endl;
    cout<<list.get(0)<<endl;
    cout<<list.get(1)<<endl;
    //cout<<list.get(2)<<endl;
//#ifdef _DEBUG
//// _CrtDumpMemoryLeaks();
//_CrtMemDumpAllObjectsSince(&_ms);
//_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
//_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
//#endif


    cout << "---------map---------"<<endl;
    unordered_map<int, int> map;
    map.put(1,20);
    map.put(2,16);
    map.put(2,31);
    map.put(3,16);
    map.put(4,29);

    //cout << map.get(1) << map.get(2) ;
//    for(int entry:map){
//        cout << entry << endl;
//    }
    cout << "---------queue---------"<<endl;
    queue<int> q(100);
    q.push(1);
    q.push(2);
    q.push(3);
    cout << q.pop() << endl;


    cout << "---------heap---------"<<endl;
    max_heap<int> heap;
    heap.add(1);
    heap.add(10);
    heap.add(9);
    heap.add(4);
    heap.add(19);
    heap.add(2);

    cout << heap.top() << endl;
    heap.add(15);
    while(!heap.isEmpty()){
        cout << heap.top() << endl;
        heap.remove();
    }
    getchar();
    return 0;
}
