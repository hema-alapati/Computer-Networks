#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string addBinary(string A, string B)
{
	string res;
	char carry = '0';
	for (int i = A.length() - 1; i >= 0; i--) {
		if (A[i] == '1' && B[i] == '1') {
			if (carry == '1')
				res.push_back('1'), carry = '1';
			else
				res.push_back('0'), carry = '1';
		}
		else if (A[i] == '0' && B[i] == '0') {
			if (carry == '1')
				res.push_back('1'), carry = '0';
			else
				res.push_back('0'), carry = '0';
		}
		else if (A[i] != B[i]) {
			if (carry == '1')
				res.push_back('0'), carry = '1';
			else
				res.push_back('1'), carry = '0';
		}
	}
    reverse(res.begin(), res.end());
    string temp1="00000001";
	if (carry == '1')
        return addBinary(res,temp1);
	return res;
}

int main(){
    int n;
    cin>>n;
    vector<string> data;
    for(int i=0;i<n;i++){
        string temp;
        cin>>temp;
        data.push_back(temp);
    }
    string sum=data[0];
    for (int i = 1; i < n; i++) {
        sum = addBinary(sum, data[i]);
    }
    string sum1;
    sum1=sum;
    for(int i=0;i<sum.length();i++){
        if(sum[i]=='0'){
            sum[i]='1';
        }
        else{
            sum[i]='0';
        }
    }
    cout<<"check sum is: "<<sum<<endl;

    sum=addBinary(sum,sum1);
    for(int i=0;i<sum.length();i++){
        if(sum[i]=='1'){
            sum[i]='0';
        }
        else{
            sum[i]='1';
        }
    }
    for(int i=0;i<sum.length();i++){
        if(sum[i]!='0'){
            cout<<"Error"<<endl;
            break;
        }
    }
    cout<<"No error"<<endl;
    return 0;
}

