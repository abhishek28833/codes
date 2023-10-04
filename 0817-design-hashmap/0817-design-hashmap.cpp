#include<bits/stdc++.h>
class MyHashMap {
public:
  vector<int> arr;
  
    MyHashMap() {
        for(int i=0;i<1000002;i++) arr.push_back(-1);
    }
    
    void put(int key, int value) {
        arr[key] = value;
    }
    
    int get(int key) {
        return arr[key];
    }
    
    void remove(int key) {
        arr[key] =-1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */