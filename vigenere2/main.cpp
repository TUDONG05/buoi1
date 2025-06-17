#include <iostream>

using namespace std;
string key(string str, string key) {
    int x = str.size();
    string newKey = key;

    for (int i = 0; newKey.size() < x; i++)
        newKey += key[i % key.size()];

    return newKey;
}

string encrypt(string s, string k)
{
    string result ="";
    for(int i=0;i< s.size(); i++)
        {
        char x = (s[i] + k[i] )%26 +65  ;
        result.push_back(x);
        }

    return result;

}
string decode(string s, string k)
{
    string result="";
    for(int i=0;i< s.size(); i++)
        {
        char x = (s[i] - k[i] +26 )%26;
        x+= 'A';
        result.push_back(x);
        }
    return result;
}



int main()
{
       string s;

    cout<<"Nhap chuoi muon ma hoa:"<<endl;
    getline(cin,s);

    string k;
    cout<<"Nhap chuoi khoa K:"<<endl;
    getline(cin,k);

    k=key(s,k);

    string e = encrypt(s,k);
    cout<<"Doan ma thu duoc la: "<<e<<endl;

   string d = decode(e, k);
    cout<<"Giai ma ta thu duoc:"<<d<<endl;

}
