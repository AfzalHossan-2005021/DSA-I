#include<cstdlib>
#include<cmath>

using namespace std;

template<class T>
class MinHeap{
    int root = 0;
    int tail = 0;
    int capacity = 0;
    T *tree;

    inline int get_parent(int child){
        return (child - 1) / 2;
    }
    inline int get_first_child(int parent){
        return 2 * parent + 1;
    }
    inline int get_second_child(int parent){
        return 2 * parent + 2;
    }
    int get_index(T element){
        for(int i = 0; i < tail; i++){
            if(tree[i] == element)
                return i;
        }
        return -1;
    }
    int get_height(int root){
        if(root >= tail)
            return 0;
        return 1 + get_height(2 * root + 1);
    }
    void swap(int index_1, int index_2){
        tree[index_1] = tree[index_1] ^ tree[index_2];
        tree[index_2] = tree[index_1] ^ tree[index_2];
        tree[index_1] = tree[index_1] ^ tree[index_2];
    }
    void post_insertion_modification(int insertion_index){
        int child = insertion_index;
        int parent = get_parent(child);
        while(tree[child] < tree[parent] && parent >= 0){
            swap(child, parent);
            child = parent;
            parent = get_parent(child);
        }
    }
    // void post_insertion_modification(int insertion_index){
    //     int child = insertion_index;
    //     int parent = get_parent(child);
    //     if(parent >= 0){
    //         if(tree[parent] > tree[child]){
    //             swap(parent, child);
    //             post_insertion_modification(parent);
    //         }
    //     }
    // }
    void Delete(T item){
        int index = get_index(item);
        if(index >= 0){
            tree[index] = tree[--tail];
            post_deletion_modification(index);
            // if(tail < capacity / 2){
            //     capacity = capacity / 2;
            //     tree = (T *) realloc(tree, (capacity * sizeof(T)));
            // }
        }
    }
    void post_deletion_modification(int deletion_index){
        int parent = deletion_index;
        int child_1 = get_first_child(parent);
        int child_2 = get_second_child(parent);
        while(true){
            if(child_1 < tail && child_2 >= tail && tree[parent] > tree[child_1]){
                swap(parent, child_1);
                parent = child_1;
            }
            else if(child_1 < tail &&  child_2 < tail){
                if(tree[parent] > tree[child_1] && tree[parent] > tree[child_2]){
                    if(tree[child_1] < tree[child_2]){
                        swap(parent, child_1);
                        parent = child_1;
                    }
                    else if(tree[child_2] < tree[child_1]){
                        swap(parent, child_2);
                        parent = child_2;
                    }
                }
                else if(tree[parent] > tree[child_1] && tree[parent] < tree[child_2]){
                    swap(parent, child_1);
                    parent = child_1;
                }
                else if(tree[parent] < tree[child_1] && tree[parent] > tree[child_2]){
                    swap(parent, child_2);
                    parent = child_2;
                }
                else
                    break;;
            }
            else
                break;
            child_1 = get_first_child(parent);
            child_2 = get_second_child(parent);
        }
    }
    // void post_deletion_modification(int deletion_index){
    //     int parent = deletion_index;
    //     int child_1 = get_first_child(parent);
    //     int child_2 = get_second_child(parent);
    //     int min = parent;
    //     if(child_1 < tail && child_2 >= tail){
    //         min = (tree[parent] < tree[child_1]) ? parent : child_1;
    //     }
    //     else if(child_1 < tail && child_2 < tail){
    //         min = tree[parent] < tree[child_1] ? parent : child_1;
    //         min = tree[min] < tree[child_2] ? min : child_2;
    //     }
    //     if(min != parent){
    //         swap(parent, min);
    //         post_deletion_modification(min);
    //     }
    // }
    int level(int index){
        cout << "index: " << index << endl;
        if(index == root) return 0;
        return 1 + level(get_parent(index));
    }

public:
    MinHeap(int size = 0, T array[] = NULL){
        for (int i = 0; i < size; i++)
            Insert(array[i]);
    }
    MinHeap(const MinHeap &obj){
        for (int i = 0; i < obj.tail; i++)
            Insert(obj.tree[i]);
    }
    ~MinHeap(){
        free(tree);
    }
    T FindMin(){
        if(tail == 0){
            cout << "Operation Failed: ";
            return -1;
        }
        else
            return tree[root];
    }
    T ExtractMin(){
        if(tail == 0){
            cout << "Operation Failed: ";
            return -1;
        }
        else{
            T min = tree[root];
            Delete(min);
            return min;
        }
    }
    void Insert(T item){
        if (capacity == 0){
            capacity = 1;
            tree = (T *) malloc(capacity * sizeof(T));
        }
        else if(tail >= capacity){
            capacity *= 2;
            tree = (T *) realloc(tree, (capacity  * sizeof(T)));
        }
        tree[tail] = item;
        post_insertion_modification(tail++);
    }
    void DecreaseKey(T prevKey, T newKey){
        int index = get_index(prevKey);
        if(index >= 0){
            tree[index] = newKey;
            post_insertion_modification(index);
            cout << prevKey << " decreased to " << newKey << endl;
        }
        else
            cout << "Operation Failed: to decrease " << prevKey << " to " << newKey << endl;
    }
    int Level(T element){
        int index = get_index(element);
        cout << "index: " << index << endl;
        if(index != -1){
            return level(index);
        }
        else return index;
    }
    void Sort(){
        int true_tail = tail;
        for(int i = 0;  i < true_tail; i ++){
            T temp = ExtractMin();
            tree[tail] = temp;
        }
        tail = true_tail;
    }
    void Print(){
        cout << "Printing the binary heap ..." << endl;
        cout << "- - - - - - - - - - - - - - - - - - - -" << endl;
        int height = get_height(root);
        int level_start = 0, level_end = 0;
        for(int i = 0; i < height; i++){
            cout << "Level " << i << ":";
            for(int j = level_start; j <= level_end; j++){
                cout << " " << tree[j];
            }
            cout << endl;
            level_start += pow(2, i);
            level_end += pow(2, (i + 1));
            if(level_end >= tail)
                level_end = tail - 1;
        }
        cout << "- - - - - - - - - - - - - - - - - - - -" << endl;
    }
};