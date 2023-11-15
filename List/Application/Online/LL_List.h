using namespace std;

template <class T> class Node{
public:
    T value;
    Node *next;
    Node *Prev;
    Node(T data, Node* PrevData, Node* nextData){
        value = data;
        next = nextData;
        Prev = PrevData;
    }
    Node(Node* prevData =NULL, Node* nextData =NULL) {
        Prev = prevData;
        next = nextData;
    }
};

template <class T> class MyList{
    Node<T>* head;
    Node<T>* tail;
    Node<T>* current;
    int currentSize;
    int currentPosition;
public:
    MyList(int size = 0, T array[] = NULL){        //Time Complexity = O(n)
        currentSize = size;
        currentPosition = 0;
        // currentPosition = 2;
        head = current = new Node<T>;
        tail = new Node<T>;
        head->next = tail;
        tail->Prev = head;
        if(size > 0){
            for(int i = 0; i < size; i++){
                tail->Prev = tail->Prev->next = new Node<T>(array[i], tail->Prev, tail);
            }
        }
    }
    MyList(const MyList<T>& obj){        //Time Complexity = O(n)
        currentSize = obj.currentSize;
        currentPosition = obj.currentPosition;
        head = new Node<T>;
        tail = new Node<T>;
        current = new Node<T>;
        head->next = tail;
        tail->Prev = head;
        Node<T>* temp = obj.head->next;
        for(int i = 0; i < currentSize; i ++){
            if(i == currentPosition){
                current = temp;
            }
            tail->Prev = tail->Prev->next = new Node<T>(temp->value, tail->Prev, tail);
            temp = temp->next;
        }
    }
    ~MyList(){        //Time Complexity = O(n)
        while (head != NULL){
            current = head;
            head = head->next;
            delete current;
        }
    }
    int size(){        //Time Complexity = O(1)
        return currentSize;
    }
    void push(T item){        //Time Complexity = O(1)
        bool alreadyIn = false;
        Node<T>* temp = head;
        for(int i = 0; i < currentSize; i++){
            if(temp->next->value == item)
                alreadyIn = true;
        }
        if(!alreadyIn){
            current->next = current->next->Prev = new Node<T>(item, current, current->next);
            currentSize ++;
        }
        
    }
    void pushBack(T item){        //Time Complexity = O(1)
        bool alreadyIn = false;
        Node<T>* temp = head;
        for(int i = 0; i < currentSize; i++){
            if(temp->next->value == item)
                alreadyIn = true;
        }
        if(!alreadyIn){
            tail->Prev = tail->Prev->next = new Node<T>(item, tail->Prev, tail);
            currentSize ++;
        }
    }
    T erase(){        //Time Complexity = O(1)
        if(head->next == tail){
            return -1;
        }
        T data = current->next->value;
        Node<T>* toBeDeleted = current->next;
        current->next->next->Prev = current;
        current->next = current->next->next;
        delete toBeDeleted;
        currentSize --;
        if(current->next == tail && currentSize > 0){
            current = current->Prev;
        }
        if(currentPosition >= currentSize){
            currentPosition --;
        }
        return data;
    }
    void setToBegin(){        //Time Complexity = O(1)
        current = head;
        currentPosition = 0;
    }
    void setToEnd(){        //Time Complexity = O(1)
        current = tail->Prev->Prev;
        currentPosition = currentSize - 1;
    }
    void prev(){        //Time Complexity = O(1)
        if(current != head){
            current = current->Prev;
            currentPosition --;
        }
    }
    void next(){        //Time Complexity = O(1)
        if(current->next->next != tail && current->next != tail){
            current = current->next;
            currentPosition ++;
        }
    }
    int currPos(){        //Time Complexity = O(1)
        return currentPosition;
    }
    void setToPos(int pos){        //Time Complexity = O(n)
        if(pos < currentSize && pos >= 0){
            if(pos > currentPosition){
                for(int i = currentPosition; i < pos; i++){
                    current = current->next;
                }
            }
            else if(pos < currentPosition){
                for(int i = currentPosition; i > pos; i--){
                    current = current->Prev;
                }
            }
            currentPosition = pos;
        }
    }
    T getValue(){        //Time Complexity = O(1)
        return current->next->value;
    }
    int find(T item){        //Time Complexity = O(n)
        Node<T>* temp = head->next;
        for(int pos = 0; pos < currentSize; pos++){
            if(temp->value == item){
                return pos;
            }
            temp = temp->next;
        }
        return -1;
    }
    void clear(){        //Time Complexity = O(n)
        while (head->next != tail){
            current = head;
            head = head->next;
            delete current;
        }
        current =  head;
        currentSize = currentPosition = 0;
    }
    T kThLargest(int k){
        T arr[currentSize];
        Node<T>* temp = head->next;
        for(int i = 0; i < currentSize; i++){
            arr[i] = temp->value;
            temp = temp->next;
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