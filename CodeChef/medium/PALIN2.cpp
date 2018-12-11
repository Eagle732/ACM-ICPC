#include<bits/stdc++.h>
using namespace std;


void increment(string &str)
{
    // cout<<"Strinf : "<<str<<endl;
    int carry = 1,len = str.length();
    if(len % 2 == 0)
    {
        int i = (len/2)-1, j = len/2;
        while(carry && i>=0)
        {
            // cout<<"H";
            if(str[i] + carry == ':')
            {
                str[j] = str[i] = '0';
            }else
            {
                carry=0;
                str[i] = str[j] = str[i]+1;
            }
            i--;
            j++;
        }
    }else
    {
        int i=(len/2) -1,p=len/2,j=(len/2) + 1;
        if(str[p] + carry == ':')
        {
            str[p] = '0';
        }else
        {
            str[p] = str[p] + 1;
            carry=0;
        }
        while(carry && i >=0)
        {
            // cout<<"H1";
            if(str[i] + carry == ':')
            {
                // cout<<i<<j<<endl;
                str[j] ='0'; str[i] = '0';
            }else
            {
                carry=0;
                str[i] = str[j] = str[i]+1;
            }
            i--;
            j++;
        }
    }
    if(carry == 1)
    {
        // cout<<str<<":   "<<str.length()<<endl<<endl;
        str[0] = '1';
        str += "1";
    }
    // cout<<str<<endl;
}
int main()
{
    string str,str1;
    int i,j,p,T;
    cin>>T;
    cin.ignore();
    while(T--)
    {
        getline(cin,str);
        str1=str;
        int len = str.length();
        if(len%2 == 0)
        {
            i = len/2-1;
            j=i+1;
        }else
        {
            i=len/2-1;
            j=i+2;
            p=i+1;
        }
        int flag = 0;
        for(;i>=0;i--,j++)
        {
            if(str[i] < str[j] && flag == 0)
            {
                // cout<<"Heu";
                increment(str);
                str[j] = str[i];
                flag = 1;
            }else if(str[i] != str[j])
            {
                str[j] = str[i];
                flag=1;
            }
        }
        if(len == 1){
            increment(str);
            // cout<<"Heu";
        }
        if(str1 == str)
            increment(str);
        cout<<str<<endl;

        // cout<<"KK"<<endl;
        fflush(stdin);
    }







    return 0;
}
