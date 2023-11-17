#include <iostream>
#include <sstream>
// #include "LL_BST.cpp"
#include "Arr_BST.cpp"

using namespace std;

int main()
{
    BST<int> bst;

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (!feof(stdin))
    {
        string arg1, arg2, input;
        getline(cin, input);
        stringstream line(input);
        line >> arg1 >> arg2;
        if (arg1.compare("I") == 0)
            cout << bst.Insert(stoi(arg2));
        else if (arg1.compare("D") == 0)
            cout << bst.Delete(stoi(arg2));
        else if (arg1.compare("F") == 0)
            cout << bst.Find(stoi(arg2));
        else if (arg1.compare("T") == 0)
            cout << bst.Traversal(arg2);
        else if (arg1.compare("P") == 0)
            cout << bst.Depth(stoi(arg2)) << endl;
        else if (arg1.compare("H") == 0)
            cout << bst.Height(stoi(arg2)) << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}