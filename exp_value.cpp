//using stack to calculate the
//value of arithmatic expression
#include"stack"
#include"algorithm"
#include"iostream"
#include"string"
#include"map"
#include"cmath"
using namespace std;

stack<char> ops;
stack<int> oprands;
map<char,int> prior;
inline void calculation(char op, int left , int right, stack<int> &oprand) {
    switch(op) {
        case '+':oprand.push(left + right);break;
        case '-':oprand.push(left - right);break;
        case '*':oprand.push(left * right);break;
        case '/':oprand.push(left / right);break;
        case '^':
        {
            int ans = pow(left, right);
            oprand.push(ans);break;
        }
    }
}
inline void gen_num(string &exp, int &index, int &ans);
inline bool isNum(char ch);
int exp_value(stack<char> &ops, stack<int> &oprand, map<char,int> &prior, string &exp, int strlen,int index = 0);
stirng addBracket(string exp);
void init_PriorMap(map<char,int> &temp) {
    temp.insert(make_pair('+',1));
    temp.insert(make_pair('-',1));
    temp.insert(make_pair('*',2));
    temp.insert(make_pair('/',2));
    temp.insert(make_pair('^',3));
    temp.insert(make_pair('(',0));
    return;
}

int main() {
    init_PriorMap(prior);
    while(true) {
        string exp;
        cin >> exp;
        exp_value(ops, oprands, prior, exp, exp.length());
        cout << oprands.top() << endl;
    }
    return 0;
}

//function implementaion
bool isNum(char ch) {
    return((ch >= '0')&&(ch <= '9'));
}

void gen_num(string &exp, int &index, int &ans) {
    ans = 0;
    int len = exp.length();
    for(; index < len; index++) {
        if(!isNum(exp[index])) {
            break;
        }
        ans = ans*10 + (exp[index] - '0');
    }
}

int exp_value(stack<char> &ops, stack<int> &oprand, map<char,int> &prior, string &exp, int len, int index) {
    int left, right;
    char op;
    for(; index < len; index++) {
        if(isNum(exp[index])) {
            int ans;
            gen_num(exp, index, ans);
            oprand.push(ans);
        }
        if(exp[index] == '(') {
            ops.push('(');
            index++;
            index = exp_value(ops, oprand, prior, exp, len, index);
        }
        else if(exp[index] == ')' || index == len) {
            break;
        }
        else {
            char op = exp[index];
            if(ops.empty() || prior[op] >= prior[ops.top()]) {
                ops.push(op);
            }
            else {
                int left, right;
                right = oprand.top();
                oprand.pop();
                left = oprand.top();
                oprand.pop();
                calculation(ops.top(), left, right, oprand);
                ops.pop();
                ops.push(op);
            }
        }
    }
    if(ops.empty()) {
        return index;
    }
    while((!ops.empty())&&(op = ops.top(), op != '(')) {
        ops.pop();
        right = oprand.top();
        oprand.pop();
        left = oprand.top();
        oprand.pop();
        calculation(op, left, right, oprand);                
    }
    if(op == '(') {
        ops.pop();
    }
    return index;
}

string addBracket(string exp) {
    string newstr = "";
	int len = exp.length();
    for(int i = 0; i < len; i++) {
        if(exp[i] == '-' || exp[i] == '+') {
            if(i == 0 || exp[i-1] == '('|| exp[i-1] == '*' || exp[i-1] == '/'|| exp[i-1] == '^'|| exp[i-1] == '+'|| exp[i-1] == '-') {
                newstr = newstr + "(0" + exp[i++];
                if((exp[i] == '+' || exp[i] == '-')&& i != len - 1) {
                    i--;
                    continue;
                }
                while(exp[i] <= '9' && exp[i] >='0') {
					newstr = newstr + exp[i++];
					if(i == len) {
						newstr = newstr + ')';
						break;
					}
				}
				newstr =newstr + ')';
				i--;
            }
            else {
                newstr = newstr + exp[i];
            }
        }
        else {
            newstr = newstr + exp[i];
        }
    }
	return newstr;
}