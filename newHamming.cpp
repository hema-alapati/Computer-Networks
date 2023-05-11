#include <bits/stdc++.h>
using namespace std;
bool powerOfTwo(int n)
{
    while(n%2==0) n/=2;
    if(n==1) return 1;
    return 0;
}

int main()
{
    cout << "Enter the number of data bits: ";
    int m;
    cin >> m;
    int r = 0;
    for (int i = 0; i < m; i++)
    {
        if (pow(2, i) >= (i + m + 1))
        {
            r = i;
            break;
        }
    }
    cout<<"Enter the data bits: \n";
    vector<int> data;
    for (int i = 0; i < m; i++)
    {
        int temp;
        cin >> temp;
        data.push_back(temp);
    }
    cout<<"check bits required are: "<<r<<endl;
    cout<<"Total bits to be transmitted= "<<m<<" data bits + "<<r<<" check bits ="<<m+r;
    reverse(data.begin(), data.end());
    vector<int> v;
    int k = 0;
    for (int i = 1; i <= m + r + 1; i++)
    {
        if (i == 0)
        {
            v.push_back(-1);
        }
        else if (powerOfTwo(i))
        {
            v.push_back(-1);
        }
        else
        {
            v.push_back(data[k]);
            k++;
        }
    }
    cout << endl;
    cout<<"check bits are: "<<endl;
    for (int i = 0; i < r; i++)
    {
        int xorVal = 0;
        for (int j = i + 1; j <= r + m; j++)
        {
            if ((j & (1 << i)) != 0 && v[j - 1] != -1)
            {
                xorVal ^= v[j - 1];
            }
        }
        v[(1 << i) - 1] = xorVal;
        cout <<"r"<<i+1<<" = "<< xorVal<<endl;
    }
    cout << "Hamming code = ";
    for (int i = m + r - 1; i >= 0; i--)
    {
        cout << v[i];
    }
    int errorBit=rand()%(m+r);
    cout<<"\nError bit generated is: "<<errorBit+1;
    v[errorBit]= v[errorBit] == 0 ? 1: 0;
    cout<<"\nHamming code after flipping that bit: ";
    for(auto it: v){
        cout<<it;
    }
    cout<<endl;
    int err;
    for (int i = 0; i < r; i++)
    {
        int xorVal = 0;
        for (int j = i + 1; j <= r + m; j++)
        {
            if ((j & (1 << i)) != 0 && v[j - 1] != -1)
            {
                xorVal ^= v[j - 1];
            }
        }
        v[(1 << i) - 1] = xorVal;
        err += pow(2, i)*xorVal;
        cout <<"r"<<i+1<<" = "<< xorVal<<endl;
    }
        if (err != 0) 
            cout<<"Error is detected at position: "<<err;
        else 
            cout<<"No error detected";        
    return 0;
}

//implementation for error detection
//xor the previous check bits(hamming code), with the ones found using code(calculated ones) and find the decimal equivalent of 
//that binary value to get the position of bit which has error
