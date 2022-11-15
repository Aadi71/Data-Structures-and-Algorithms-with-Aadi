// https://leetcode.com/problems/lemonade-change/

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int, int> umap;
        for(int i = 0; i<bills.size(); i++){
            if(bills[i] == 5) umap[5]++;
            else{
                umap[bills[i]]++;
                int bal = bills[i] - 5;
                while(bal){
                    if(bal == 15){
                        if(umap[10] > 0 && umap[5] > 0){
                            umap[10]--; 
                            umap[5]--;
                            bal = 0;
                        }
                        else if(umap[5] >= 3){
                            umap[5] -= 3;
                            bal = 0;
                        }
                        else return false;
                    }
                    if(bal == 10){
                        if(umap[10] > 0){
                            umap[10]--; 
                            bal = 0;
                        }
                        else if(umap[5] >= 2){
                            umap[5] -= 2;
                            bal = 0;
                        }
                        else return false;
                    }
                    if(bal == 5){
                        if(umap[5] > 0){
                            umap[5]--;
                            bal = 0;
                        }
                        else return false;
                    }
                }
            }
        }
        return true;
    }
};
