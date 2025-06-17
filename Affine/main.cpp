#include <iostream>
#include <string>
using namespace std;

string encrypt (string s, int a, int b)
{
    string kq="";
    for(int i=0;i<s.length();i++)
        if(s[i]!=' ')
            kq += char((a * (int(s[i])-'A') + b)%26 + 'A');
        else
            kq += s[i];
    return kq;
}

string decode (string s, int a, int b)
{
    string kq="";
    int a_1  = 0;
    int flag =0;

    //tim nghich dao cua a --> a_1
    for(int i =0;i<26; i++)
    {
        flag = (a*i)%26;
        if(flag ==1)
            a_1 = i;
    }


    for(int i=0; i<s.length();i++)
        if(s[i]!=' ')
            kq += char((a_1 * (s[i] - 'A' - b + 26)) % 26 + 'A');

        else
            kq+= s[i];
    return kq;
}

int main()
{
    string s;

    cout<<"Nhap chuoi muon ma hoa:"<<endl;
    getline(cin,s);

    int a,b;
    cout<<"Nhap cap khoa k(a,b):"<<endl;
    cout<<"a=";
    cin>>a;


    cout<<"b=";
    cin>>b;

    string e = encrypt(s,a,b);
    cout<<"Chuoi ma hoa la:"<< e<<endl;

    string d = decode(e,a,b);
    cout<<"Chuoi giai ma la:"<<d<<endl;


}
