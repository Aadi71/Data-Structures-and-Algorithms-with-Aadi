// https://www.geeksforgeeks.org/stack-set-2-infix-to-postfix/

int prec(char c){
    if(c == '^') return 3;
    else if(c == '/' || c == '*') return 2;
    else if(c == '+' || c == '-') return 1;
    else return -1;
}

string infixToPostfix(string s){
    stack <char> st;
    string result;

    for(int i = 0; i<s.length(); i++){
        char c = s[i];

        if(c == '(') st.push('(');
        else if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) result += c;
        else if(c == ')'){
            while (st.top() != '(')
            {
                result += st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            while(!st.empty() && prec(s[i]) <=  prec(st.top())){
                if(c == '^' && st.top() == '^') break;
                else{
                    result += st.top();
                    st.pop();
                }
            }
            st.push(s[i]);
        }
    }
    while(!st.empty()){
        result += st.top();
        st.pop();
    }
    return result;
}

int main(){

    string exp = "a+b*(c^d-e)^(f+g*h)-i";
    cout<<infixToPostfix(exp);

}
