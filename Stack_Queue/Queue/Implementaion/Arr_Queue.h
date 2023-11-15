#include <stdlib.h>
#include<fstream>

using namespace std;

template <class T>
class Queue{
    int capacity;
    int currentSize;
    int front;
    int rear;
    T *dataList;

    void freeList(){
        if(dataList != NULL)
            delete[] dataList;
    }
    void createNewList(int size){
        T *tempList = new T[size + 1];
        int iter = front + 1;
        for(int i = 1; i <= currentSize; i++){
            tempList[i] = dataList[iter % (capacity + 1)];
            iter ++;
        }
        dataList = tempList;
        front = 0;
        rear = currentSize + 1;
        capacity = size;
    }
public:
    Queue(int maxSize = 0, int size = 0, T arr[] = NULL){
        capacity = maxSize;
        currentSize = 0;
        front = 0;
        rear = 1;
        dataList = NULL;
        if(capacity > 0){
            dataList = new T[capacity + 1];
            for(int i = 0; i < size; i++)
                enqueue(arr[i]);
        }
    }
    Queue(const Queue<T> &obj){
        capacity = obj.capacity;
        currentSize = 0;
        front = 0;
        rear = 1;
        dataList = NULL;
        if(capacity > 0){
            dataList = new T[capacity + 1];
            for(int i = 0; i < obj.currentSize; i++)
                enqueue(obj.dataList[i]);
        }
    }
    ~Queue(){
        freeList();
    }
    void clear(){
        freeList();
        currentSize = capacity =0;
        front = 0;
        rear = 1;
    }
    void enqueue(T item){
        if(capacity == 0){
            createNewList(1);
        }
        else if(currentSize >= capacity){
            createNewList(capacity * 2);
        }
        dataList[rear % (capacity + 1)] = item;
        currentSize ++;
        rear = (rear + 1) % (capacity + 1);
    }
    T dequeue(){
        if(currentSize > 0){
            T data = dataList[front + 1];
            front = (front + 1) % (capacity + 1);
            currentSize --;
            // if(currentSize <= capacity/2){
            //     createNewList(capacity/2);
            // }
            return data;
        }
    }
    int length(){
        return currentSize;
    }
    T frontValue(){
        if(currentSize > 0)
            if(front == capacity)
                return dataList[0];
            return dataList[front + 1];
    }
    T rearValue(){
        if(currentSize > 0)
            if(rear == 0)
                return dataList[capacity];
            return dataList[rear - 1];
    }
    T leaveQueue(){
        if(currentSize > 0){
            T data;
            if(rear == 0){
                data = dataList[capacity];
                rear = capacity;
            }
            else{
                rear --;
                data = dataList[rear];
            }
            currentSize --;
            if(currentSize <= capacity / 2){
                createNewList(capacity / 2);
            }
            return data;
        }
    }
    void reverseQueue(){
        int trueRear = rear;
        int tempRear = rear-1;
        for(int i = 0; i < currentSize; i ++){
            T tempData = dequeue();
            dataList[tempRear] =  tempData;
            tempRear = rear -1;
        }
        rear = trueRear;
    }
    void print(ofstream &outputFile){
        int iter = front + 1;
        // for(int i = 0; i < currentSize; i++){
        //     cout << iter % (capacity + 1) << " ";
        //     iter ++;
        // }
        // cout << endl;
        // iter = front + 1;
        outputFile << "< ";
        if(currentSize > 0)
            outputFile << "| ";
        for(int i = 0; i < currentSize; i++){
            outputFile << dataList[iter % (capacity + 1)] << " ";
            iter ++;
        }
        outputFile << ">" << endl;
    }
};