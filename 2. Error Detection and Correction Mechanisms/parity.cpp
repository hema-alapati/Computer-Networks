#include <iostream>
using namespace std;
#include <cstring>
int main()
{
    int count = 0;
    cout<<"Enter 8 bit data\n";
    string data;
    cin>>data;
    for (int i = 0; i < 8; i++)
    {
        if (data[i] == '1')
        {
            count++;
        }
    }
    string parity;
    cout<<"Enter the parity: \n";
    cin >> parity;
    if (parity == "even")
    {
        if (count % 2 == 0)
        {
            data = data + "0";
        }
        else
        {
            data = data + "1";
        }
    }
    else
    {
        if (count % 2 == 0)
        {
            data = data + "1";
        }
        else
        {
            data = data + "0";
        }
    }
    cout <<"The final data is: "<< data<<endl;
    string data1;
    cout<<"Enter the 9 bit data to check the error\n";
    cin >> data1;
    count = 0;
    for (int i = 0; i < data1.length(); i++)
    {
        if (data1[i] == '1')
        {
            count++;
        }
    }
    string parity1;
    cout<<"Enter the parity you want to check\n";
    cin >> parity1;
    if (parity == "even")
    {
        if (count % 2 == 0)
        {
            cout << "no error";
        }
        else
        {
            cout << "error";
        }
    }
    else
    {
        if (count % 2 == 0)
        {
            cout << "error";
        }
        else
        {
            cout << "no error";
        }
    }
    return 0;
}
