using namespace std;

template <class T> class Node{
public:
    T value;
    Node *next;
    Node *Prev;
    Node(T data = 0, Node* PrevData = NULL, Node* nextData = NULL){
        value = data;
        next = nextData;
        Prev = PrevData;
    }
    
};

template <class T> class Stack{
    Node<T>* top;
    Node<T>* bottom;
    int size;
public:
    Stack(int initialSize = 0, T array[] = NULL){        //Time Complexity = O(n)
        size = 0;
        top = new Node<T>;
        bottom = new Node<T>;
        bottom->next = top;
        top->Prev = bottom;
        if(initialSize > 0){
            for(int i = 0; i < size; i++){
                push(array[i]);
            }
        }
    }
    ~Stack(){        //Time Complexity = O(n)
        clear();
        delete top;
        delete bottom;
    }
    void clear(){
        while(size --){
            Node <T> *temp = top->Prev;
            top->Prev = top->Prev->Prev;
            top->Prev->next = top;
            delete temp;
        }
    }
    void push(T item){
        top->Prev->next = new Node<T>(item, top->Prev, top);
        top->Prev = top->Prev->next;
        size ++;
    }
    T pop(){
        if(size > 0){
            Node <T> *temp = top->Prev;
            T data = temp->value;
            top->Prev = top->Prev->Prev;
            top->Prev->next = top;
            delete temp;
            size --;
            return data;
        }
    }
    int length(){
        return size;
    }
    T topValue(){
        if(size > 0){
            return top->Prev->value;
        }
    }
    void print(ofstream &outputFile){
        Node <T> *temp = bottom ->next;
        outputFile << "< ";
        for(int i = 0; i < size; i++){
            outputFile << temp->value << " ";
            temp = temp->next;
        }
        if(size > 0)
            outputFile << ">" << endl;
    }
};