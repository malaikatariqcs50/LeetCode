//Last Solved on: 25 Nov, 2026, Wednesday
//Last Solved in: 1 hour

class Solution {
    vector<int> parent;
    vector<int> rank;
private:
    int find(int node){
        if(parent[node] != node){
            parent[node] = find(parent[node]);
        }

        return parent[node];
    }

    bool unite(int u, int v){
        int pu = find(u);
        int pv = find(v);

        if(pu == pv)
            return false;
        
        if(rank[pu] < rank[pv]){
            swap(pu, pv);
        }

        parent[pv] = pu;

        if(rank[pu] == rank[pv])
            rank[pu]++;
        
        return true;
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n-1) return false;
        parent.resize(n);
        rank.assign(n, 0);

        iota(parent.begin(), parent.end(), 0);

        for(auto& e : edges){
            if(!(unite(e[0], e[1]))){
                return false;
            }
        }
        return true;
    }
};
