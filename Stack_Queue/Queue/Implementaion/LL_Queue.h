#include<iostream>

using namespace std;

template <class T> class Node{
public:
    T value;
    Node *next;
    Node *Prev;
    Node(T data = -1, Node* PrevData = NULL, Node* nextData = NULL){
        value = data;
        next = nextData;
        Prev = PrevData;
    }
};

template <class T> class Queue{
    Node<T>* front;
    Node<T>* rear;
    int size;
    
public:
    Queue(int initialSize = 0, T array[] = NULL){        //Time Complexity = O(n)
        size = 0;
        front = new Node<T>;
        rear = new Node<T>;
        front->next = rear;
        rear->Prev = front;
        for(int i = 0; i < initialSize; i++){
            enqueue(array[i]);
        }
    }
    Queue(const Queue &obj){
        size = 0;
        front = new Node<T>;
        rear = new Node<T>;
        front->next = rear;
        rear->Prev = front;
        Node <int> *temp = front->next;
        for(int i = 0; i < obj.size; i++){
            enqueue(temp->value);
            temp = temp->next;
        }
    }
    ~Queue(){        //Time Complexity = O(n)
        clear();
        delete front;
        delete rear;
    }
    void clear(){
        Node <T> *temp;
        while(front->next != rear){
            temp = front->next;
            front->next = front->next->next;
            front->next->Prev = front;
            delete temp;
        }
        size = 0;
    }
    void enqueue(T item){
        rear->Prev->next = new Node<T>(item, rear->Prev, rear);
        rear->Prev = rear->Prev->next;
        size ++;
    }
    T dequeue(){
        if(size > 0){
            Node <T> *temp = front->next;
            T data = temp->value;
            front->next = front->next->next;
            front->next->Prev = front;
            delete temp;
            size --;
            return data;
        }
    }
    int length(){
        return size;
    }
    T frontValue(){
        if(size > 0){
            return front->next->value;
        }
    }
    T rearValue(){
        if(size > 0){
            return rear->Prev->value;
        }
    }
    T leaveQueue(){
        if(size > 0){
            Node <T> *temp = rear->Prev;
            T data = temp->value;
            rear->Prev = rear->Prev->Prev;
            rear->Prev->next = rear;
            delete temp;
            size --;
            return data;
        }
    }
    void print(ofstream &outputFile){
        Node <T> *temp = front->next;
        outputFile << "< ";
        if(size > 0)
            outputFile << "| ";
        for(int i = 0; i < size; i++){
            outputFile << temp->value << " ";
            temp = temp->next;
        }
        outputFile << ">" << endl;
    }
};