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

template <class T> class MyList{
    Node<T>* head;
    Node<T>* tail;
    Node<T>* current;
    int currentSize;
    int currentPosition;
public:
    MyList(int size = 0, T array[] = NULL){     //Time Complexity = O(n)
        currentSize = 0;
        currentPosition = 0;
        head = new Node<T>;
        tail = new Node<T>;
        head->next = tail;
        tail->Prev = head;
        current = head;
        for(int i = 0; i < size; i++)
            pushBack(array[i]);
    }
    MyList(const MyList<T>& obj){//Time Complexity = O(n)
        currentSize = 0;
        currentPosition = obj.currentPosition;
        head = new Node<T>;
        tail = new Node<T>;
        head->next = tail;
        tail->Prev = head;
        current = head;
        Node<T>* temp = obj.head->next;
        for(int i = 0; i < obj.currentSize; i ++){
            pushBack(temp->value);
            temp = temp->next;
        }
        for (int i = 0; i < currentPosition; i++)
            current = current->next;
        
    }
    ~MyList(){                  //Time Complexity = O(n)
        while (head != NULL){
            current = head;
            head = head->next;
            delete current;
        }
    }
    int size(){                 //Time Complexity = O(1)
        return currentSize;
    }
    void push(T item){          //Time Complexity = O(1)
        current->next = current->next->Prev = new Node<T>(item, current, current->next);
        currentSize ++;
    }
    void pushBack(T item){      //Time Complexity = O(1)
        tail->Prev = tail->Prev->next = new Node<T>(item, tail->Prev, tail);
        currentSize ++;
    }
    T erase(){                  //Time Complexity = O(1)
        if(head->next == tail)
            return -1;
        T data = current->next->value;
        Node<T>* toBeDeleted = current->next;
        current->next->next->Prev = current;
        current->next = current->next->next;
        delete toBeDeleted;
        currentSize --;
        if(current->next == tail && currentSize > 0)
            current = current->Prev;
        if(currentPosition >= currentSize && currentPosition > 0)
            currentPosition --;
        return data;
    }
    void setToBegin(){          //Time Complexity = O(1)
        current = head;
        currentPosition = 0;
    }
    void setToEnd(){            //Time Complexity = O(1)
        current = tail->Prev->Prev;
        currentPosition = currentSize - 1;
    }
    void prev(){                //Time Complexity = O(1)
        if(current != head){
            current = current->Prev;
            currentPosition --;
        }
    }
    void next(){                //Time Complexity = O(1)
        if(current->next->next != tail && current->next != tail){
            current = current->next;
            currentPosition ++;
        }
    }
    int currPos(){              //Time Complexity = O(1)
        return currentPosition;
    }
    void setToPos(int pos){     //Time Complexity = O(n)
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
    T getValue(){               //Time Complexity = O(1)
        return current->next->value;
    }
    int find(T item){           //Time Complexity = O(n)
        Node<T>* temp = head->next;
        for(int pos = 0; pos < currentSize; pos++){
            if(temp->value == item)
                return pos;
            temp = temp->next;
        }
        return -1;
    }
    void clear(){               //Time Complexity = O(n)
        while (head->next != tail){
            current = head;
            head = head->next;
            delete current;
        }
        current =  head;
        currentSize = currentPosition = 0;
    }
    bool detectLoop(){
        if(head->next == NULL) return false;
        Node *slow = head, *fast = head->next;
        while(true){
            if(slow == fast)
                return true;
            if(fast->next == NULL) break;
            else if(fast->next->next == NULL) break;
            slow = slow->next;
            fast = fast->next->next;
        }
        return false;
    }
};