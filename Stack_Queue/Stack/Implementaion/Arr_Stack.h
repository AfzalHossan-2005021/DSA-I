#include <cstdlib>
#include<fstream>

using namespace std;

template <class T>
class Stack{
    int capacity;
    int top;
    T *dataList;
    void createNewList(int size){
        capacity = size;
        dataList = (T*) realloc(dataList, capacity * sizeof(T));
    }
    void FreeList(){
        if(dataList != NULL)
            free(dataList);
    }
public:
    Stack(int maxSize = 0, int size = 0, T arr[] = NULL){
        capacity = maxSize;
        top = -1;
        dataList = NULL;
        if(capacity > 0){
            dataList = (T*) malloc(capacity * sizeof(T));
            for(int i = 0; i <size; i++)
                push(arr[i]);
        }
    }
    Stack(const Stack<T> &obj){
        capacity = obj.capacity;
        top = -1;
        dataList = NULL;
        if(capacity > 0){
            dataList = (T*) malloc(capacity * sizeof(T));
            for(int i = 0; i <= obj.top; i++)
                push(obj.dataList[i]);
        }
    }
    ~Stack(){
        FreeList();
    }
    void clear(){
        FreeList();
        capacity = 0;
        top = -1;
    }
    void push(T item){
        if(capacity == 0){
            capacity = 1;
            dataList = (T*) malloc(capacity * sizeof(T));
        }
        else if(top >= capacity - 1){
            createNewList(capacity * 2);
        }
        top++;
        dataList[top] = item;
    }
    T pop(){
        if(top >= 0){
            T data = dataList[top];
            top --;
            if(top < capacity / 2){
                createNewList(capacity / 2);
            }
            return data;
        }
    }
    int length(){
        return top + 1;
    }
    T topValue(){
        if(top >= 0)
            return dataList[top];
    }
    int getCapacity(){
        return capacity;
    }
    void print(ofstream &outputFile){
        outputFile << "< ";
        for(int i = 0; i <= top; i++)
            outputFile << dataList[i] << " ";
        if(capacity > 0)
            outputFile << "| ";
        outputFile << ">" << endl;
    }
};
