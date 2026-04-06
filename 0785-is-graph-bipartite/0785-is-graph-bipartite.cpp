#include <bits/stdc++.h>
class Solution {
public:
    bool rec(vector<vector<int>>& graph,int n,unordered_map<int,int>& mp,int node){
        queue<pair<int,int>> q;
        // cout<<"node: "<<node<<" colour: 0"<<"\n";
        q.push({node,0});
        while(!q.empty()){
            int ele = q.front().first;
            int col = q.front().second;
            q.pop();
            for(auto a: graph[ele]){
                if(mp.count(a)){
                    if(mp[a] == col) return false;
                }else{
                    mp[a] = (col^1);
                    q.push({a,mp[a]});
                }
            }
        }
        return true;
    }

    bool rec2(vector<vector<int>>& graph,int n,unordered_map<int,int>& mp,int node,int col){
        for(auto a: graph[node]){
            if(mp.count(a)){
                if(mp[a] == col) return false;
            }else{
                mp[a] = (col^1);
                if(!rec2(graph,n,mp,a,mp[a])) return false;
            }
        }
        return true;
    }


    bool isBipartite(vector<vector<int>>& graph) {
        unordered_map<int,int> mp;
        int n = graph.size();
        for(int i=0;i<n;i++){
            if(!mp.count(i)){
                mp[i] = 0;
                if(!rec2(graph,n,mp,i,0)) return false;
            }
        }
        return true;
    }
};