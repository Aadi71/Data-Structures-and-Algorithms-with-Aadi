// https://practice.geeksforgeeks.org/problems/consecutive-elements2306/1

class Solution{
    public:
    string removeConsecutiveCharacter(string S)
    {
        string f;
        char temp = S[0];
        f += temp;
        for(int i = 1; i<S.length(); i++){
            if(S[i] == temp) continue;
            else{
                f += S[i];
                temp = S[i];
            }
        }
        return f;
    }
};
