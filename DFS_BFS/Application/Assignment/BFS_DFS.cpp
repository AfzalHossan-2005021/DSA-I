#include<bits/stdc++.h>
#include"LL_List.h"
#include"LL_Stack.h"
#include"LL_Queue.h"

using namespace std;

template<class T>
class Vertex{
    public:
    T data;
    int color = 0;
    int distance = 0;
    int predecessor = -1;
    int d_time = 0;
    int e_time = 0;
};

template<class T>
class Graph{
    public:
    int vertex_count;
    vector<Vertex<T> > vertex_list;
    vector<vector<int> > adj_list;
    Graph(int vertex_count){
        this->vertex_count = vertex_count;
        vertex_list.resize(vertex_count);
        adj_list.resize(vertex_count);
    }
};

void BFS_helper(Graph<int> &graph, int source, vector<vector<int> > &tree){
    graph.vertex_list[source].color = 1;
    Queue<int> queue;
    queue.enqueue(source);
    while(queue.length() > 0){
        int vertex = queue.dequeue();
        for(int link : graph.adj_list[vertex]){
            if(graph.vertex_list[link].color == 0){
                tree[vertex].push_back(link);
                graph.vertex_list[link].color = 1;
                graph.vertex_list[link].distance = graph.vertex_list[vertex].distance + 1;
                graph.vertex_list[link].predecessor = vertex;
                queue.enqueue(link);
            }
        }
        graph.vertex_list[vertex].color = 2;
    }
}


void BFS(Graph<int> graph, int source){
    vector<vector<int> > tree(graph.vertex_count);
    BFS_helper(graph, source, tree);
    cout << "BFS tree" << endl;
    for(int i = 0; i < tree.size(); i++){
        if(tree[i].size() > 0){
            cout << i << " -> ";
            for(int j = 0; j < tree[i].size(); j++){
                cout << tree[i][j];
                if(j != tree[i].size() - 1)
                    cout << ", ";
            }
            cout << endl;
        }
    }
}

void DFS_helper(Graph<int> &graph, int source, vector<vector<int> > &tree, int &time){
    time++;
    graph.vertex_list[source].d_time = time;
    graph.vertex_list[source].color = 1;
    for(int link : graph.adj_list[source]){
        if(graph.vertex_list[link].color == 0){
            tree[source].push_back(link);
            graph.vertex_list[link].predecessor = source;
            DFS_helper(graph, link, tree, time);
        }
    }
    time++;
    graph.vertex_list[source].e_time = time;
    graph.vertex_list[source].color = 2;
}

void DFS(Graph<int> graph, int source){
    int time = 0;
    vector<vector<int> > tree(graph.vertex_count);
    DFS_helper(graph, source, tree, time);
    cout << endl << "DFS tree" << endl;
    for(int i = 0; i < tree.size(); i++){
        if(tree[i].size() > 0){
            cout << i << " -> ";
            for(int j = 0; j < tree[i].size(); j++){
                cout << tree[i][j];
                if(j != tree[i].size() - 1)
                    cout << ", ";
            }
            cout << endl;
        }
    }
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int vertex_count, edge_count, source;
    cin >> vertex_count >> edge_count;
    Graph<int> graph(vertex_count);
    for(int i = 0; i < vertex_count; i++){
        graph.vertex_list[i].data = i;
    }
    for(int i = 0; i < edge_count; i++){
        int origin, end;
        cin >> origin >> end;
        graph.adj_list[origin].push_back(end);
    }
    cin >> source;
    BFS(graph, source);
    DFS(graph, source);
    return 0;
}
