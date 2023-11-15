#include<iostream>
#include<cstdlib>
using namespace std;

template <class T>
class BST{
    int root = 1;
    int array_size;
    bool *indicator;
    T *tree;
    void createNewList(int size){
        bool *temp = new bool[size + 1];
        T *tempList = new T[size + 1];
        for(int i = 0; i < size + 1; i++){
            temp[i] = false;
            tempList[i] = -1;
        }
        if(array_size > 0){
            for(int i = 0; i <= array_size; i++){
                tempList[i] = tree[i];
                temp[i] = indicator[i];
            }
            delete[] tree;
            delete[] indicator;
        }
        tree = tempList;
        indicator = temp;
        array_size = size;
    }
    void Insert(T element, int index){
        if(array_size == 0)
            createNewList(1);
        else if(array_size < 2 * index + 1)
            createNewList(2 * array_size + 1);
        if(indicator[index] == false){
            tree[index] = element;
            indicator[index] = true;
        }
        else{
            if(element < tree[index])
                Insert(element, 2 * index);
            else if(element > tree[index])
                Insert(element, 2 * index + 1);
        }
    }
    void step_back(int index){
        if(indicator[index] == true){
            Insert(tree[index], root);
            indicator[index] = false;
            step_back(2 * index);
            step_back(2 * index + 1);
        }
    }
    string Delete(T element, int index){
        if(tree[index] == element && indicator[index] == true){
            if(indicator[2*index] == false && indicator[2*index+1] == false){
                indicator[index] = false;
                return "Succeed";
            }
            else
                return "Failed";
            // else if (indicator[2*index] == true && indicator[2*index+1] == false){
            //     indicator[index] = false;
            //     step_back(2 * index);
            // }
            // else if(indicator[2*index] == false && indicator[2*index+1] == true){
            //     indicator[index] = false;
            //     step_back(2 * index + 1);
            // }
            // else if (indicator[2*index] == true && indicator[2*index+1] == true){
            //     int iter = 2 * root + 1;
            //     while (indicator[2 * iter] == true)
            //         iter *= 2;
            //     tree[index] = tree[iter];
            //     indicator[iter] = false;
            // }
            // return "Succeed";
        }
        else if(element != tree[index] && indicator[2*index] == false && indicator[2*index+1] == false)
            return "Failed";
        else if(element < tree[index])
            return Delete(element, 2 * index);
        else
            return Delete(element, 2 * index + 1);
    }
    string Find(T element, int index){
        if(indicator[index] == false)
            return "False\n";
        else{
            if(element == tree[index])
                return "True\n";
            else if(element < tree[index])
                return Find(element, 2 * index);
            else
                return Find(element, 2 * index + 1);
        }
    }

    void Traversal(int index, string order, string &output){
        if(indicator[index] == true){
            if(indicator[2 * index] == false && indicator[2 * index + 1] == false){
                output += to_string(tree[index]);
                output.push_back(' ');
            }
            else{
                if(order.compare("In") == 0){
                    if(indicator[2 * index] == true)
                        Traversal(2 * index, order, output);
                    output += to_string(tree[index]);
                    output.push_back(' ');
                    if(indicator[2 * index + 1] == true)
                        Traversal(2 * index + 1, order, output);
                }
                else if(order.compare("Pre") == 0){
                    output += to_string(tree[index]);
                    output.push_back(' ');
                    if(indicator[2 * index] == true)
                        Traversal(2 * index, order, output);
                    if(indicator[2 * index + 1] == true)
                        Traversal(2 * index + 1, order, output);
                }
                else if(order.compare("Post") == 0){
                    if(indicator[2 * index] == true)
                        Traversal(2 * index, order, output);
                    if(indicator[2 * index + 1] == true)
                        Traversal(2 * index + 1, order, output);
                    output += to_string(tree[index]);
                    output.push_back(' ');
                }
            }
        }
    }
    void print_tree(int index, string &output){
        if(indicator[index] == true){
            output += to_string(tree[index]);
            if(indicator[2 * index] == true || indicator[2 * index + 1] == true){
                output.push_back('(');
                print_tree(2 * index, output);
                output.push_back(')');
                output.push_back('(');
                print_tree(2 * index + 1, output);
                output.push_back(')');
            }
        }
    }
    
    public:
    BST(int size = 0, T arr[] = NULL){
        array_size = 0;
        if(size > 0){
            for(int i = 0; i < size; i++)
                Insert(arr[i]);
        }
    }
    BST(const BST &obj){
        array_size = obj.array_size;
        if(array_size > 0){
            tree = new T[array_size + 1];
            indicator = new bool[array_size + 1];
            for(int i = 0; i <= array_size; i++){
                tree[i] = obj.tree[i];
                indicator[i] = obj.indicator[i];
            }
        }
    }
    ~BST(){
        delete[] tree;
        delete[] indicator;
    }
    string Insert(T element){
        string output = "";
        Insert(element, root);
        print_tree(root, output);
        output.append("\n");
        return output;
    }
    string Delete(T element){
        string output = "";
        string flag = "Failed";
        if(indicator[root] == true)
            flag = Delete(element, root);
        if(flag.compare("Failed") == 0)
            return "Invalid Operatioon\n";
        else
            print_tree(root, output);
        output.append("\n");
        return output;

    }
    string Find(T element){
        return Find(element, root);
    }
    string Traversal(string order){
        string output = "";
        Traversal(root, order, output);
        output.append("\n");
        return output;
    }
};