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

    // void printMap(){
    //     for(auto it : mp)
    //     {
    //         cout<<it.first<<" "<<it.second<<endl;
    //     }
    // }
    
    bool remove(int val) {
    // check if value exists
    if (mp.find(val) == mp.end())
        return false;

    int ind = mp[val];              // index of val
    int lastVal = arr.back();       // last element

    // move last element to the removed position
    arr[ind] = lastVal;
    mp[lastVal] = ind;

    // remove last element
    arr.pop_back();
    mp.erase(val);

    return true;
}

    
    int getRandom() {
        return arr[rand()%arr.size()];
     }
};

int main() {
    RandomizedSet* obj = new RandomizedSet();
    int x;
    for(int i=0 ; i<4 ; i++)
    {
        cin>>x;
        obj->insert(x);
    }
    //obj->printMap();
    obj->remove(4);
    cout<<"after"<<endl;
    //obj->printMap();
    return 0;
}