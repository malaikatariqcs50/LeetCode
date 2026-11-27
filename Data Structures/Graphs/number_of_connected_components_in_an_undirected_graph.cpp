//Last Solved on: 27 Nov, 2026, Friday
//Last Solved in: 30 minutes

class Solution {
    vector<int> parent,rank;
private:
    int find(int x){
        if(parent[x] != x){
            parent[x] = find(parent[x]);
        }

        return parent[x];
    }

    int unite(int u, int v){
        int pu = find(u);
        int pv = find(v);

        if(pu == pv)
            return 0;
        
        if(rank[pu] < rank[pv]){
            swap(pu, pv);
        }

        parent[pv] = pu;

        if(rank[pu] == rank[pv])
            rank[pu]++;
        
        return 1;
    }

public:
    int countComponents(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank.assign(n,0);

        iota(parent.begin(), parent.end(), 0);

        int count = n;
        for(auto& e : edges){
            count -= unite(e[0], e[1]);
        }
        
        return count;
    }
};

