#include<bits/stdc++.h>
using namespace std;

class RandomizedSet {
public:
        unordered_map<int,int> mp;
        vector<int> arr;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val) != mp.end())
        return false;
        arr.push_back(val);
        mp[val]=arr.size()-1;
        return true;
    }

    void printMap(){
        for(auto it : mp)
        {
            cout<<it.first<<" "<<it.second<<endl;
        }
    }
    
    // bool remove(int val) {
    //     if(mp.find(val) != mp.end())
    //     return false;
    //     int ind = mp[val];
    //     mp[arr.size()-1]=ind;
    //     swap(arr[ind] , arr[arr.size()-1]);
        
    // }
    
    // int getRandom() {
        
    // }
};

int main() {
    RandomizedSet* obj = new RandomizedSet();
    int x;
    for(int i=0 ; i<10 ; i++)
    {
        cin>>x;
        obj->insert(x);
    }
    obj->printMap();
    return 0;
}