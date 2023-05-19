#include <bits/stdc++.h>
using namespace std;
string xor1(string a, string b)
{
    string result = "";
    int n = b.length();
    for (int i = 1; i < n; i++)
    {
        if (a[i] == b[i])
            result += "0";
        else
            result += "1";
    }
    return result;
}
string mod2div(string dividend, string divisor)
{
    int pick = divisor.length();
    string tmp = dividend.substr(0, pick);
    int n = dividend.length();
    while (pick < n)
    {
        if (tmp[0] == '1')
            tmp = xor1(divisor, tmp) + dividend[pick];
        else
            tmp = xor1(string(pick, '0'), tmp) + dividend[pick];
        pick += 1;
    }
    if (tmp[0] == '1')
        tmp = xor1(divisor, tmp);
    else
        tmp = xor1(std::string(pick, '0'), tmp);

    return tmp;
}

string encodeData(string data, string key)
{
    int keyLength = key.length();
    string appended_data = (data + string(keyLength - 1, '0'));
    string remainder = mod2div(appended_data, key);
    string codeword = data + remainder;
    return remainder;
}

void receiver(string data, string key)
{
    string remainder = mod2div(data, key);
    string tempStr = "";
    if (remainder == string(key.length() - 1, '0'))
    {
        cout << "No error is detected :)";
    }
    else
    {
        cout << "Error is detected in the data !!! " << endl;
    }
}

int main()
{
    cout << "Name: Alapati Hemalatha" << endl
         << "Reg.No: 21BPS1384" << endl;
    cout << endl;
    string data;
    int Dlen = data.size();
    cout << "Enter the data: ";
    cin >> data;
    cout << "Enter the highest power of polynomial: ";
    int n;
    cin >> n;
    vector<int> arr;
    while (n >= 0)
    {
        int temp;
        cout << "Enter the coefficient of x power " << n << ":";
        cin >> temp;
        arr.push_back(temp);
        n--;
    }
    string key = "";
    for (auto i : arr)
    {
        key += to_string(i);
    }
    int Klen = key.size();
    cout << "\nSender Side: " << endl;
    string remainder = encodeData(data, key);
    string transmittedData = data + remainder;
    cout << "Remainder is: " << remainder << endl;
    cout << "Data to transmit: " << transmittedData;
    cout << endl
         << endl;
    cout << "Receiver side: " << endl;
    cout << "Do you want to flip the bit? [Y/N]: ";
    char err;
    cin >> err;
    string receivedData;
    if (err == 'Y')
    {
        cout << "Enter the bit you want to flip: ";
        int flipBit;
        cin >> flipBit;
        string receivedData = transmittedData;
        if (receivedData[flipBit + 1] = '0')
        {
            receivedData[flipBit] = '1';
        }
        else
        {
            receivedData[flipBit] = '0';
        }
    }
    else
    {
        receivedData = transmittedData;
    }
    receiver(receivedData, key);
    return 0;
}
