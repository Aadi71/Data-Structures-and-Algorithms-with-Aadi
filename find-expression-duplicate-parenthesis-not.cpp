// https://www.geeksforgeeks.org/find-expression-duplicate-parenthesis-not/

bool duplicateParenthesis(string s){
    stack<char> st;
    
    for(char ch : s){
        if(ch == ')') {
            char top = st.top();
            st.pop();

            int elems = 0;
            while(top != '('){
                elems ++;
                top = st.top();
                st.pop();
            }
            if(elems <= 1) return 1;
        }
        else st.push(ch);
    }
    return false;
}

int main(){
    string s = "((a+(b))+(c+d))";
    if(duplicateParenthesis(s)) cout<<"Duplicate Found";
    else cout<<"Duplicate not found";
}
