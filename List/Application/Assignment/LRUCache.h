// #include "LL_List.h"
#include "Arr_List.h"

template <class T1, class T2> class LRUCache{
    int maxSize;
    int currentSize;
    MyList <T1>* keyList;
    MyList <T2>* valueList;
public:
    LRUCache(int capacity){
        maxSize = capacity;
        currentSize = 0;
        // keyList = new MyList<T1>();
        // valueList = new MyList<T2>();
        keyList = new MyList<T1>(currentSize, maxSize);
        valueList = new MyList<T2>(currentSize, maxSize);
    }
    T2 get(T1 key){
        int pos = keyList->find(key);
        if(pos == -1){
            return pos;
        }
        keyList->setToPos(pos);
        keyList->erase();
        keyList->pushBack(key);
        valueList->setToPos(pos);
        T2 value = valueList->erase();
        valueList->pushBack(value);
        return value;
    }
    void put(T1 key, T2 value){
        int pos = keyList->find(key);
        if(pos == -1){
            if(currentSize < maxSize){
                currentSize ++;
            }
            else{
                keyList->setToBegin();
                keyList->erase();
                valueList->setToBegin();
                valueList->erase();
            }
        }
        else{
            keyList->setToPos(pos);
            keyList->erase();
            valueList->setToPos(pos);
            valueList->erase();
        }
        keyList->pushBack(key);
        valueList->pushBack(value);
    }
};