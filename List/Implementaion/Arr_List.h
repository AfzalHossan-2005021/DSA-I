#include<cstdlib>

using namespace std;

template <class T> class MyList{
    int maxSize;
    int currentSize;
    int currentPosition;
    T *list;
public:
    MyList (int k = 0, int x = 0, T array[] = NULL){
        currentSize = 0;
        currentPosition = 0;
        maxSize = x;
        list = NULL;
        if(maxSize > 0)
            list = (T *) malloc (maxSize * sizeof(T));
        for(int i = 0; i < k; i ++)
            pushBack(array[i]);
    }
    MyList(const MyList<T>& obj){
        maxSize = obj.maxSize;
        currentSize = 0;
        currentPosition = obj.currentPosition;
        list = NULL;
        if(maxSize > 0)
            list = (T *) malloc(maxSize * sizeof(T));
        for(int i = 0; i < obj.currentSize; i ++)
            pushBack(obj.list[i]);
    }
    ~MyList(){              // Time complexity O(1)
        if(list)
            free(list);
    }
    int size(){             // Time complexity O(1)
        return currentSize;
    }
    void push(T item){      // Time complexity O(n)
        if(maxSize == 0){
            maxSize ++;
            list = (T *) malloc(sizeof(T));
        }
        if(currentSize >= maxSize){
            maxSize *= 2;
            list = (T *) realloc(list, maxSize * sizeof(T));
        }
        for(int i = currentSize; i > currentPosition; i --)
            list[i] = list[i - 1];
        list[currentPosition] = item;
        currentSize ++;
    }
    void pushBack(T item){  // Time complexity O(1)
        if(maxSize == 0){
            maxSize ++;
            list = (T *) malloc(sizeof(T));
        }
        if(currentSize >= maxSize){
            maxSize *= 2;
            list = (T *) realloc(list, maxSize * sizeof(T));
        }
        list[currentSize] = item;
        currentSize ++;
    }
    T erase(){              // Time complexity O(n)
        if(currentSize == 0)
            return -1;
        T erased = list[currentPosition];
        for(int i = currentPosition; i < currentSize - 1; i ++){
            list[i] = list[i + 1];
        }
        currentSize --;
        if(currentSize <= maxSize / 2 && currentSize > 0){
            maxSize /= 2;
            list = (T *) realloc(list, maxSize * sizeof(T));
        }
        if(currentPosition >= currentSize && currentPosition > 0)
            currentPosition --;
        return erased;
    }
    void setToBegin(){      // Time complexity O(1)
        currentPosition = 0;
    }
    void setToEnd(){        // Time complexity O(1)
        currentPosition = currentSize - 1;
    }
    void prev(){            // Time complexity O(1)
        if(currentPosition > 0)
            currentPosition --;
    }
    void next(){            // Time complexity O(1)
        if(currentPosition < currentSize - 1)
            currentPosition ++;
    }
    int currPos(){          // Time complexity O(1)
        return currentPosition;
    }
    void setToPos(int pos){ // Time complexity O(1)
        if(pos < currentSize && pos >= 0)
            currentPosition = pos;
    }
    T getValue(){           // Time complexity O(1)
        return list[currentPosition];
    }
    int find (T item){      // Time complexity O(n)
        int pos = -1;
        for(int i = 0; i < currentSize; i++)
            if(list[i] == item)
                pos = i;
        return pos;
    }
    void clear(){           // Time complexity O(1)
        if(list)
            free(list);
        list = NULL;
        maxSize = currentSize = currentPosition = 0;
    }
};