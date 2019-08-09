/* ԭ������

20. Valid Parentheses
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.

Note that an empty string is also considered valid.

Example 1:

Input: "()"
Output: true

Example 2:

Input: "()[]{}"
Output: true

Example 3:

Input: "(]"
Output: false

Example 4:

Input: "([)]"
Output: false

Example 5:

Input: "{[]}"
Output: true
*/

// ��һ��ⷨ����
//ʱ�临�Ӷ�O(n) 4ms beats 100%
bool isValid(string s) {

    if (s == "")
        return true;
    stack<char>s1, s2;

    for (auto c : s)
        s1.push(c);

    while (!s1.empty()){
        if (!s2.empty()){
            char ch = s2.top();
            if (ch == '(' || ch == '{' || ch == '[')
                return false;
            else if (ch == ')'){
                if (s1.top() == '('){
                s2.pop();
                }
                else{
                s2.push(s1.top());
                }
            }
            else if (ch == '}'){
                if (s1.top() == '{'){
                s2.pop();
                }
                else{
                s2.push(s1.top());
                }
            }
            else if (ch == ']'){
                if (s1.top() == '['){
                s2.pop();
                }
                else{
                s2.push(s1.top());
                }
            }
        }
        else
            s2.push(s1.top());
        s1.pop();
    }
    if (s2.empty())
        return true;

    return false;
}

// ���ϺõĽⷨ
//ʱ�临�Ӷ�O(n) 4ms beats 100%
        bool isValid(string s) {
            map<char, char> parenth_dict;
            parenth_dict['('] = ')';
            parenth_dict['{'] = '}';
            parenth_dict['['] = ']';
            
            stack<char> aux;
            for (int i = 0; i < s.size(); i++) {
                if (s[i] == '(' || s[i] == '{' || s[i] == '[') 
                    aux.push(s[i]);
                else if (aux.empty() || parenth_dict[aux.top()] != s[i])
                    return false;
                else
                    aux.pop();
            }
            
            return aux.empty();
            
        }
//ʱ�临�Ӷ�O(n) 4ms beats 100%
    bool isValid(string s) {
        stack<char> st;
        for(auto c : s){
            if(c == '(' || c == '{' || c == '[') st.push(c);
            else if(st.size() > 0){
                if(c == ')' && st.top() == '(') st.pop();
                else if (c == '}' && st.top() == '{') st.pop();
                else if (c == ']' && st.top() == '[') st.pop();
                else return false;
            } else return false;
        }
        return st.size() == 0;
    }

// �����Ż�
//ʱ�临�Ӷ�O(n) 4ms beats 100%
bool isValid(string s){
    stack<char> s1;

    if (s.empty())
        return true;
    else if (s.length() % 2 != 0)
        return false;

    for (auto it : s){
        if (it == '(' || it == '{' || it == '[')
            s1.push(it);
        else if (it == ')' && !s1.empty() && s1.top() == '(')
            s1.pop();
        else if (it == ']' && !s1.empty() && s1.top() == '[')
            s1.pop();
        else if (it == '}' && !s1.empty() && s1.top() == '{')
            s1.pop();
        else
            return false;
    }

    return s1.empty();
}

/* ˼��
1. �ⷨ˼·���棺

��һ��������������stackģ������ƥ��Ĺ��̡�

������Ч���ű���ʽ��һ����Ȥ�������ǣ���Ч����ʽ���ӱ���ʽҲӦ������Ч����ʽ��
ץס������ԣ����Ǳ����ֻ����һ��stack���ɽ������ŵ�ƥ�䡣�ڱ���s�Ĺ����У�
�������������ջ��s1�У�������������ţ���ֻ��Ҫ�ж�s1.top()�Ƿ�����Ӧ����
���ż��ɡ�


2. ���������棺

�ж�һ�������Ƿ���������ʱ����x % 2 != 0����Ҫ��x % 2 == 1����Ϊx�����Ǹ�����

���ж�����������a��b�Ƿ����ʱ����Ҫ�� a == b��Ӧ���ж�����֮��ľ���ֵfabs(a-b)�Ƿ�С��ĳ����ֵ������ 1e-9

����Ҫʹ��s1.top()֮ǰ��һ��Ҫ���ж���s1�Ƿ�Ϊ�գ�����������Ҫʹ��������Ԫ�ص�ʱ��һ����˼���¸��������ڵ�״̬�Ƿ�Ϊ�ա�
*/
