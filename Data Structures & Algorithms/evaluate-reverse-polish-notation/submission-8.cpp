#include<bits/stdc++.h>
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        //std::vector<char> oprll = {'+','*','-','/'};
        std::stack<long> st;
        for(auto& ch : tokens)
        {
            if(ch != "+" and ch != "-" and ch != "/" and ch != "*"){
                st.push(stol(ch));
            }
            else{
                //if(st.empty()) return -1;
                long el1 = st.top();
                st.pop();
                //if(st.empty()) return -1;
                long el2 = st.top();
                st.pop();
                if(ch == "+") { st.push(el1 + el2); }
                else if(ch == "-") { st.push(el2 - el1); }
                else if(ch == "/") { st.push(el2 / el1); }
                else {
                    st.push(el1 * el2);
                }
            }
        }
        return (int)st.top();
    }
};


/*
    Input: tokens = ["1","2","+","3","*","4","-"]

    1 2 +

    3 3 *

    9 4 -

    5

    Explanation: ((1 + 2) * 3) - 4 = 5
*/