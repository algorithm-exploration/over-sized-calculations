#include <string>
#include <iostream>

using namespace std;

string stringMultiply(string a, string b) {
    string c="", solution="", strCarry=""; 
    int carry=0, t=0;
    for(int i=a.size()-1; i>=0; i--) {
        for(int z=i; z<a.size()-1; z++) c+='0';
        for(int j=b.size()-1; j>=0; j--) {
            carry = ((a[i]-'0') * (b[j]-'0')) + carry; //char to int
            strCarry = to_string(carry);
            if(strCarry.size() == 2) {
                c = strCarry[1] + c;
                carry = strCarry[0]-'0'; //relies on ascii pos #48-57, -'0' = -48
                if(j==0) c = strCarry[0] + c;
            } else {
                c = strCarry + c;
                carry = 0;
            }
        }
        t = c.size() - solution.size();
        if(t < 0) {
            t = abs(t);
            while(t>0) {
                c = '0' + c; //did it work?
                t--;
            }
        } else {
            while(t>0) {
                solution = '0' + solution;
                t--;
            }
        }
        carry = 0;
        for(int m=c.size()-1; m>=0; m--) {
            carry = (int)(c[m]-'0') + (int)(solution[m]-'0') + carry;
            strCarry = to_string(carry);
            if(strCarry.size() == 2) {
                solution[m] = strCarry[1];
                carry = strCarry[0]-'0'; //relies on ascii pos #48-57, -'0' = -48
                if(m==0) solution = strCarry[0] + solution;
            } else {
                solution[m] = strCarry[0];
                carry = 0;
            }
        }
        carry = 0;
        c = "";
        strCarry = "";
        t=0;

    }
    return solution;
}

void extraLongFactorials(int n) {
    long long num = 1;
    string numString="", temp="";
    if(n>20) {
        for(int i=20; i>0; i--) {
            num*=i;
        }
        numString = to_string(num);
        for(int j=n; j>20; j--) {
            temp = to_string(j);
            numString = stringMultiply(numString, temp);
        }
        cout << numString << endl;
    } else {
        for(int i=n; i>0; i--) {
            num*=i;
        }
        cout << num << endl;
    }
}

int main()
{
    int n;
    cin >> n;

    extraLongFactorials(n);

    return 0;
}
