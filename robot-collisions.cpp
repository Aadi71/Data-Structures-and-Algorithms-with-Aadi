// https://leetcode.com/problems/robot-collisions/

class Solution {
public:
    void battle(stack<pair<int, pair<int, char>>> &st, int pos, pair<int, char> hd) {
        if (st.empty()) st.push({pos, {hd.first, hd.second}});
        else {
            int spos = st.top().first;
            pair<int, char> hds = st.top().second;
            if (hds.second == hd.second || hd.second == 'R') {
                st.push({pos, {hd.first, hd.second}});
            } else {
                if (hds.first == hd.first) {
                    st.pop();
                } else if (hds.first > hd.first) {
                    st.pop();
                    st.push({spos, {hds.first - 1, hds.second}});
                } else {
                    st.pop();
                    battle(st, pos, {hd.first - 1, hd.second});
                }
            }
        }
    }
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<int> ans;
        map<int, pair<int, char>> umap;
        int n = positions.size();

        for(int i = 0; i < n; i++) {
            umap[positions[i]] = {healths[i], directions[i]};
        }
        stack<pair<int, pair<int, char>>> st;
        for (auto itr: umap) {
            int pos = itr.first;
            pair<int, char> hd = itr.second;
            battle(st, pos, hd);
        }
        unordered_map<int, int> pps_umap;
        while(!st.empty()) {
            pps_umap[st.top().first] = st.top().second.first;
            st.pop();
        }
        for(auto itr: positions) {
            if (pps_umap.contains(itr)) ans.push_back(pps_umap[itr]);
        }
        return ans;
    }
};
