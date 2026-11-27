//Last Solved on: 27 Nov, 2026, Friday
//Last Solved in: 30 minutes

class Solution {
    vector<int> parent, rank;

private:
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }

        return parent[x];
    }

    bool unite(int u, int v) {
        int pu = find(u);
        int pv = find(v);

        if (pu == pv) {
            return false;
        }

        if (rank[pu] < rank[pv]) {
            swap(pu, pv);
        }

        parent[pv] = pu;

        if (rank[pu] == rank[pv])
            rank[pu]++;

        return true;
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n + 1);
        rank.assign(n + 1, 0);

        iota(parent.begin(), parent.end(), 0);

        for (auto& e : edges) {
            if (!unite(e[0], e[1])) {
                return {e[0], e[1]};
            }
        }
        return {};
    }
};

//If the nodes are already connected i.e if they already have the same parent, they dont need to be connected again
//The edge can be removed