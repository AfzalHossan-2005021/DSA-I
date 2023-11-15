#include<cstdlib>

using namespace std;

template <class T> class MyList{
    int maxSize;
    int currentSize;
    int initialCapacity;
    int currentPosition;
    T *list;
public:
    MyList (int k = 0, int x = 0, T array[] = NULL){
        currentSize = k;
        currentPosition = 0;
        // currentPosition = 2;
        maxSize = initialCapacity = x;
        if(maxSize){
            list = (T *) malloc (maxSize * sizeof(T));
        }
        if(!list){
            exit(1);
        }
        if(array){
            for(int i = 0; i < currentSize; i ++){
                list[i] = array[i];
            }
        }
    }
    MyList(const MyList<T>& obj){
        maxSize = obj.maxSize;
        currentSize = obj.currentSize;
        currentPosition = obj.currentPosition;
        initialCapacity = obj.initialCapacity;
        if(maxSize){
            list = (T *) malloc(maxSize * sizeof(T));
        }
        if(currentSize){
            for(int i = 0; i < currentSize; i ++){
                list[i] = obj.list[i];
            }
        }
    }
    ~MyList(){      // Time complexity O(1)
        free(list);
    }
    int size(){      // Time complexity O(1)
        return currentSize;
    }
    void push(T item){      // Time complexity O(n)
        if(maxSize == 0){
            maxSize = 1;
            list = (T *) malloc(maxSize * sizeof(T));
        }
        bool alredyIn = false;
        for(int i = 0; i < currentSize; i ++){
            if(list[i] == item){
                alredyIn = true;
            }
        }
        if(!alredyIn){
            if(currentSize >= maxSize){
                maxSize = 2 * maxSize;
                list = (T *) realloc(list, maxSize * sizeof(T));
                if(list == NULL){
                    exit(1);
                }
            }
            for(int i = currentSize; i > currentPosition; i --){
                list[i] = list[i - 1];
            }
            list[currentPosition] = item;
            currentSize ++;
        }
    }
    void pushBack(T item){      // Time complexity O(1)
        if(maxSize == 0){
            maxSize = 1;
            list = (T *) malloc(maxSize * sizeof(T));
        }
        bool alredyIn = false;
        for(int i = 0; i < currentSize; i ++){
            if(list[i] == item){
                alredyIn = true;
            }
        }
        if(!alredyIn){
            if(currentSize >= maxSize){
                maxSize = 2 * maxSize;
                list = (T *) realloc(list, maxSize * sizeof(T));
                if(list == NULL){
                    exit(1);
                }
            }
            list[currentSize] = item;
            currentSize ++;
        }
    }
    T erase(){      // Time complexity O(n)
        if(currentSize == 0){
            return -1;
        }
        T erased = list[currentPosition];
        for(int i = currentPosition; i < currentSize - 1; i ++){
            list[i] = list[i + 1];
        }
        currentSize --;
        if(currentSize <= maxSize / 2){
            maxSize = maxSize / 2;
            list = (T *) realloc(list, maxSize * sizeof(T));
        }
        if(currentPosition >= currentSize && currentSize > 0){
            currentPosition = currentSize - 1;
        }
        return erased;
    }
    void setToBegin(){      // Time complexity O(1)
        currentPosition = 0;
    }
    void setToEnd(){        // Time complexity O(1)
        currentPosition = currentSize - 1;
    }
    void prev(){        // Time complexity O(1)
        if(currentPosition > 0){
            currentPosition --;
        }
    }
    void next(){        // Time complexity O(1)
        if(currentPosition < currentSize - 1){
            currentPosition ++;
        }
    }
    int currPos(){      // Time complexity O(1)
        return currentPosition;
    }
    void setToPos(int pos){     // Time complexity O(1)
        if(pos < currentSize && pos >= 0){
            currentPosition = pos;
        }
    }
    T getValue(){       // Time complexity O(1)
        return list[currentPosition];
    }
    int find (T item){      // Time complexity O(n)
        int pos = -1;
        for(int i = 0; i < currentSize; i++){
            if(list[i] == item)
                pos = i;
        }
        return pos;
    }
    void clear(){       // Time complexity O(1)
        free(list);
        if(initialCapacity){
            list = (T *) malloc(initialCapacity * sizeof(T));
        }
        maxSize = initialCapacity;
        currentSize = currentPosition = 0;
    }
    T kThLargest(int k){
        T arr[currentSize];
        for (int i = 0; i < currentSize; i++)
        {
            arr[i] = list[i];
        }
        
        for(int i = 0; i < currentSize; i++){
            for(int j = i; j < currentSize; j++){
                if(arr[j] > arr[i]){
                    T temp = arr[j];
                    arr[j] = arr[i];
                    arr[i] = temp;
                }
            }
        }
        return arr[k-1];
    }
};