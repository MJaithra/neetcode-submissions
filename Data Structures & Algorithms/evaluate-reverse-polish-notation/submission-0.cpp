class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        int res;
        for(int i=0; i<tokens.size(); i++)
        {
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*"|| tokens[i] == "/")
            {
                int b = stoi(st.top()); st.pop();
                int a = stoi(st.top()); st.pop();

                if(tokens[i] == "+") st.push(to_string(a+b));
                else if(tokens[i] == "-") st.push(to_string(a-b));
                else if(tokens[i] == "*") st.push(to_string(a*b));
                else if(tokens[i] == "/") st.push(to_string(a/b));
            }
            else
            {
                st.push(tokens[i]);
            }
        }

        return stoi(st.top());
    }
};
