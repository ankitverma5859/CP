// Link: https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1#

class Solution{
public:
    bool is_safe_color(int node, bool graph[101][101], int colors[], int m, int n, int col_num){
        for(int i=0; i<n; i++){
            if(i != node and graph[i][node] == 1 and colors[i] == col_num)
                return false;
        }
        return true;
    }

    bool solve(int node, bool graph[101][101], int colors[], int m, int n){
        if(node == n) return true;
        
        for(int i=1; i<=m; i++){
            if(is_safe_color(node, graph, colors, m, n, i)){
                colors[node] = i;
                if(solve(node+1, graph, colors, m, n) == true) return true;
                colors[node] = 0;
            }
        }
        return false;
    }

    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int m, int n) {
        int colors[n] = {0};
        if(solve(0, graph, colors, m, n)) return true;
        return false;
    }
};
