#include<bits/stdc++.h>

using namespace std;

template<class T>
class Vertex{
    public:
    T data;
    int color = 0;
    int predecessor = -1;
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

void cycle_detector(Graph<int> &graph, int source, bool &contain_cycle, int cycle_start){
    if(!contain_cycle){
        for(int link : graph.adj_list[source]){
            // cout << "source: " << source << " link: " << link << endl;
            if(link == cycle_start){
                contain_cycle = true;
                break;
            }
            else{
                cycle_detector(graph, link, contain_cycle, cycle_start);
            }
        }
    }
}

void Print_Graph(Graph<int> &graph){
    for(int i = 0; i < graph.adj_list.size(); i++){
        cout << "source: " << i << " -> " ;
        for(int j = 0; j < graph.adj_list[i].size(); j++){
            cout << graph.adj_list[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int vertex_count, edge_count, source = 0;
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
    // Print_Graph(graph);
    bool contain_cycle = false;
    for(int i = 0; i < vertex_count; i++)
        cycle_detector(graph, i, contain_cycle, i);    
    if(contain_cycle)
        cout << "Yes" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
