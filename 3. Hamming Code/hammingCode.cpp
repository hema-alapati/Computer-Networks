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
    cout<<"The total number of check bits required are: "<<r<<endl;
    cout<<"Total bits transmitted= "<<m<<" data bits + "<<r<<" check bits ="<<m+r;
    cout<<"Enter the data bits: \n";
    vector<int> data;
    for (int i = 0; i < m; i++)
    {
        int temp;
        cin >> temp;
        data.push_back(temp);
    }
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
    for (int i = 0; i < r+m; i++)
    {
        cout << v[i];
    }
    cout << endl;
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
    
    return 0;
}
