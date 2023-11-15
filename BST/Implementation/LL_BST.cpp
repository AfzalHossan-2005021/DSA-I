using namespace std;

template <class T>
class Node
{
public:
    T element;
    Node<T> *l_sub;
    Node<T> *r_sub;
    Node(T data = -1, Node<T> *left = NULL, Node<T> *right = NULL)
    {
        element = data;
        l_sub = left;
        r_sub = right;
    }
};

template <class T>
class BST
{
    Node<T> *root;

    void insert_data(T data, Node<T> *&assume_root)
    {
        if (assume_root == NULL)
            assume_root = new Node<T>(data);
        else // if(assume_root != NULL)
        {
            if (data < (assume_root->element))
                insert_data(data, assume_root->l_sub);
            else // if(data >= assume_root->element)
                insert_data(data, assume_root->r_sub);
        }
    }

    string find_data(T data, Node<T> *assume_root)
    {
        if (assume_root == NULL)
            return "False\n";
        else
        {
            if (data == assume_root->element)
                return "True\n";
            else if (data < assume_root->element)
                return find_data(data, assume_root->l_sub);
            else // if (data > assume_root->element)
                return find_data(data, assume_root->r_sub);
        }
    }

    string delete_data(T data, Node<T> *&assume_root)
    {
        if (data == assume_root->element)
        {
            if (assume_root->l_sub == NULL && assume_root->r_sub == NULL)
            {
                Node<T> *temp = assume_root;
                assume_root = NULL;
                delete temp;
                return "Succeed";
            }
            else
                return "Failed";
            // else if (assume_root->l_sub == NULL && assume_root->r_sub != NULL){
            //     Node<T>* remove = assume_root;
            //     assume_root = assume_root->r_sub;
            //     delete remove;
            // }
            // else if (assume_root->r_sub == NULL && assume_root->l_sub != NULL){
            //     Node<T>* remove = assume_root;
            //     assume_root = assume_root->l_sub;
            //     delete remove;
            // }
            // else if (assume_root->l_sub != NULL && assume_root->r_sub != NULL)
            // {
            //     Node<T> *iter = assume_root;
            //     iter = iter->r_sub;
            //     while (iter->l_sub != NULL)
            //         iter = iter->l_sub;
            //     T temp = iter->element;
            //     delete_data(temp, root);
            //     assume_root->element = temp;
            // }
            // return "Succeed";
        }
        else if(data != assume_root->element && assume_root->l_sub == NULL && assume_root->r_sub == NULL)
            return "Failed";
        else if (data < assume_root->element)
            return delete_data(data, assume_root->l_sub);
        else //if (data > assume_root->element)
            return delete_data(data, assume_root->r_sub);
        // else
        //     return "Failed";
    }
    void traverse(Node<T> *assume_root, string order, string &output)
    {
        if (assume_root)
        {
            if (assume_root->l_sub == NULL && assume_root->r_sub == NULL)
            {
                output = output + to_string(assume_root->element);
                output.push_back(' ');
            }
            else
            {
                if (order.compare("In") == 0)
                {
                    if (assume_root->l_sub)
                        traverse(assume_root->l_sub, order, output);
                    output = output + to_string(assume_root->element);
                    output.push_back(' ');
                    if (assume_root->r_sub)
                        traverse(assume_root->r_sub, order, output);
                }
                else if (order.compare("Pre") == 0)
                {
                    output = output + to_string(assume_root->element);
                    output.push_back(' ');
                    if (assume_root->l_sub)
                        traverse(assume_root->l_sub, order, output);
                    if (assume_root->r_sub)
                        traverse(assume_root->r_sub, order, output);
                }
                else if (order.compare("Post") == 0)
                {
                    if (assume_root->l_sub)
                        traverse(assume_root->l_sub, order, output);
                    if (assume_root->r_sub)
                        traverse(assume_root->r_sub, order, output);
                    output = output + to_string(assume_root->element);
                    output.push_back(' ');
                }
            }
        }
    }
    void print_tree(Node<T> *assume_root, string &output)
    {
        if (assume_root)
        {
            output = output + to_string(assume_root->element);
            if (assume_root->l_sub != NULL || assume_root->r_sub != NULL)
            {
                output.push_back('(');
                print_tree(assume_root->l_sub, output);
                output.push_back(')');
                output.push_back('(');
                print_tree(assume_root->r_sub, output);
                output.push_back(')');
            }
        }
    }
    void clear(Node<T> *&assume_root)
    {
        if (assume_root->l_sub == NULL && assume_root->r_sub == NULL)
        {
            Node<T> *temp;
            temp = assume_root;
            assume_root = NULL;
            delete temp;
        }
        else
        {
            if (assume_root->l_sub)
                clear(assume_root->l_sub);
            if (assume_root->r_sub)
                clear(assume_root->r_sub);
            Node<T> *temp;
            temp = assume_root;
            assume_root = NULL;
            delete temp;
        }
    }
    void copy_tree(Node<T> *&assume_root, Node<T> *old_root)
    {
        assume_root = old_root;
        if (old_root->l_sub != NULL)
            copy_tree(assume_root->l_sub, old_root->l_sub);
        if (old_root->r_sub != NULL)
            copy_tree(assume_root->r_sub, old_root->r_sub);
    }
    int Depth(Node<T> * assume_root, T element){
        if(element == assume_root->element)
            return 0;
        else if(element > assume_root->element)
            return 1 + Depth(assume_root->r_sub, element);
        else
            return 1 + Depth(assume_root->l_sub, element);
    }
    int Height(Node<T> *assume_root){
        if(assume_root->r_sub == NULL && assume_root->l_sub == NULL)
            return 1;
        else if(assume_root->r_sub != NULL && assume_root->l_sub == NULL)
            return 1 + Height(assume_root->r_sub);
        else if(assume_root->r_sub == NULL && assume_root->l_sub != NULL)
            return 1 + Height(assume_root->l_sub);
        else{
            int x = Height(assume_root->r_sub);
            int y = Height(assume_root->l_sub);
            if(x > y) return 1 + x;
            return 1 + y;
        }
    }

public:
    BST(int size = 0, T array[] = NULL)
    {
        root = NULL;
        if (size != 0)
        {
            for (int i = 0; i < size; i++)
                Insert(array[i]);
        }
    }
    BST(const BST<T> &obj)
    {
        root = NULL;
        if (obj.root != NULL)
            copy_tree(this->root, obj.root);
    }
    ~BST()
    {
        if (root != NULL)
            clear(root);
    }
    string Insert(T data)
    {
        string output = "";
        insert_data(data, this->root);
        print_tree(this->root, output);
        output.append("\n");
        return output;
    }
    string Delete(T data)
    {
        string output = "";
        string flag = "Failed";
        if (root != NULL)
            flag = delete_data(data, root);
        if (flag.compare("Failed") == 0)
            return "Invalid Operatioon\n";
        else
            print_tree(root, output);
        output.append("\n");
        return output;
    }
    string Find(T data)
    {
        return find_data(data, root);
    }
    string Traversal(string order)
    {
        string output = "";
        traverse(root, order, output);
        output.append("\n");
        return output;
    }
    int Depth(T element){
        int depth;
        if(Find(element).compare("True\n") == 0)
            depth = Depth(root, element);
        else
            return -1;
        return depth;
    }
    int Height(T element){
        int height;
        height = Height(root);
        return height;
    }
};