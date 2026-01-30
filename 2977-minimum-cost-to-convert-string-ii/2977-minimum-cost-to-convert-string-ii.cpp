#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sLen;
    int n;
    unordered_map<string, int> getIdx;
    set<int> validLength;
    vector<vector<int>> dist;
    int INF = 1e8;
    int graphSize;
    vector<long long> dp;

    // Floyd–Warshall to compute all-pairs minimum cost
    void fillFloydWarshall(vector<vector<int>> &dist) {
        for (int via = 0; via < graphSize; via++) {
            for (int i = 0; i < graphSize; i++) {
                for (int j = 0; j < graphSize; j++) {
                    if (dist[i][via] == INF || dist[via][j] == INF) continue;
                    dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
                }
            }
        }
    }

    long long solve(int idx, string &source, string &target) {
        if (idx == sLen) return 0;
        if (dp[idx] != -1) return dp[idx];

        long long ans = 1e10;

        // If characters already match
        if (source[idx] == target[idx])
            ans = solve(idx + 1, source, target);

        // Try all valid substring lengths
        for (int len : validLength) {
            if (idx + len > sLen) break;

            string srcSub = source.substr(idx, len);
            string trgSub = target.substr(idx, len);

            if (!getIdx.count(srcSub) || !getIdx.count(trgSub)) continue;

            int u = getIdx[srcSub];
            int v = getIdx[trgSub];

            if (dist[u][v] == INF) continue;

            ans = min(ans, dist[u][v] + solve(idx + len, source, target));
        }

        return dp[idx] = ans;
    }

    long long minimumCost(string source, string target,
                          vector<string> &original,
                          vector<string> &changed,
                          vector<int> &cost) {
        sLen = source.length();
        dp.assign(sLen, -1);
        n = original.size();

        int id = 0;

        // Assign IDs to strings (nodes)
        for (int i = 0; i < n; i++) {
            if (!getIdx.count(original[i])) getIdx[original[i]] = id++;
            if (!getIdx.count(changed[i])) getIdx[changed[i]] = id++;
            validLength.insert(original[i].length());
        }

        graphSize = id;
        dist.assign(graphSize, vector<int>(graphSize, INF));

        for (int i = 0; i < graphSize; i++)
            dist[i][i] = 0;

        // Direct edges
        for (int i = 0; i < n; i++) {
            int u = getIdx[original[i]];
            int v = getIdx[changed[i]];
            dist[u][v] = min(dist[u][v], cost[i]);
        }

        // Floyd–Warshall
        fillFloydWarshall(dist);

        long long res = solve(0, source, target);
        return (res >= 1e10) ? -1 : res;
    }
};