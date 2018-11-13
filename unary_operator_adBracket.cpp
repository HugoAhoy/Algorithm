//In the expression with unary operator
//If we add the brackets to make the
//the unary operator '-'&'+' become
//the form of (0- )&(0+ ). Then, we
//simplify the expression to the usual
//expression without unary operator
#include"iostream"
#include"string"
using namespace std;

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

int main(){
	string a;
    while(true) {
        cin >> a;
        cout << addBracket(a) << endl;
    }
    return 0;
}