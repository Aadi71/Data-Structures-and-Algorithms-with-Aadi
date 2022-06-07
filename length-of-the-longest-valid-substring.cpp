// https://www.geeksforgeeks.org/length-of-the-longest-valid-substring/

int longestValidSubstring(string s){
    stack <char> st;
    int sum = 0;
    for(int i = 0; i<s.length(); i++){
        if(s[i] == '(') st.push('(');
        else{
            if(st.empty()) continue;
            else if(st.top() == '('){
                sum += 2;
                st.pop();
            }
            else{
                continue;
            }
        }
    }
    return sum;
}

int main(){

    string s = "((((((()";
    cout<<longestValidSubstring(s);

}
