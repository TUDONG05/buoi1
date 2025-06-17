#include <iostream>
#include <string>

using namespace std;

string encrypt(string s, int k)
{
    k %=26;
    string result="";
    for(int i=0;i<s.length();i++)
        if(isupper(s[i]))
            result+=char((int(s[i])-65+k)%26+65 );
        else if(islower(s[i]))
            result+=char((int(s[i])-97+k)%26+97);
        else
            result+=s[i];
    return result;

}

string decrypt(string s, int k)
{
    k%=26;
    string result = "";
    for(int i=0;i<s.length();i++)
        if(isupper(s[i]))
            result += char((int(s[i])-65-k+26)%26+65);
        else if(islower(s[i]))
            result += char((int(s[i])-97-k+26)%26+97);
        else
            result +=s[i];

    return result;
}
int main()
{
    cout<<"Nhap thong diep muon ma hoa:";
    string mess ;
    getline(cin,mess);

    int k;
    cout<<"Nhap so dich vong k:";
    cin>>k;

    string en_mess = encrypt(mess,k);
    cout<<"Thong diep sau khi ma hoa la:"<<en_mess<<endl;

    string de_mess = decrypt(en_mess,k);
    cout<<"Giai ma thong diep ta thu duoc:"<<de_mess<<endl;

}
