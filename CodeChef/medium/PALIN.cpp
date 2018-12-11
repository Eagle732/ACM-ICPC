#include<bits/stdc++.h>
using namespace std;
int main()
{
  int T,len;
  string str,str1;

  cin>>T;
  cin.ignore();
  while(T--)
  {
    getline(cin,str);
    str1 = str;
    len = str.length();
    bool flag = 0;
    int i,j,p;
    if(len % 2 == 0)
    {
      i = (len/2)-1;
      j = i+1;
      p=0;
    }else
    {
      i = (len/2)-1;
      j = i+2;
      p=i+1;
    }
    if(len %2 == 0)
    {
        flag = 0;
        int k=i,m=j;
        // flag = 0;
        // cout<<k<<m;
        for(;k>=0;k--,m++)
            if(str[k] != '9' || str[m] != '9')
            {
                flag = 1;
                break;
            }

        if(flag == 0)
        {
            for(;i>=0;i--,j++){
                str1[i] = str1[j] = '0';
            }
            // str1[p]='0';
            str1[0] = '1';
            str1+="1";
        }else
        {
            flag = 0;
            for(;i>=0;i--,j++)
            {
                if(str[i] > str[j])
                {
                    str1[i] = str1[j] = str[i];
                    flag = 1;
                }else if(str[i]< str[j])
                {
                    if(flag == 0){
                        str1[i] = str1[j] = str[i]+1;
                        flag = 1;
                    }else
                    {
                        str1[i] = str1[j] = str[i];
                    }
                }
            }
            if(str1 == str)
            {
                str1[(len/2)-1] = str1[len/2] = str[len/2]+1;
            }
        }
    }else
    {
        int k=i,m=j;
        flag = 0;
        // cout<<k<<m;
        for(;k>=0;k--,m++)
            if(str[k] != '9' || str[m] != '9')
            {
                flag = 1;
                break;
            }
        if(len == 1 && str[0] == '9')
            flag = 0;
        else if(len == 1 && str[0] != '9')
        {
            flag = 1;
        }
        if(flag == 0)
        {
            if(str[p] != '9')
                flag = 1;
        }

        // cout<<flag << i<<j;
        if(flag == 0)
        {
            // cout<<"Hello";
            for(;i>=0;i--,j++){
                str1[i] = str1[j] = '0';
            }
            str1[p]='0';
            str1[0] = '1';
            str1+="1";
            // cout<<str1;
        }
        else
        {
            for(;i>=0;i--,j++)
            {
                if(str[i] < str[j])
                {
                    if(str[p] != '9'){
                        str1[p] = str[p]+ 1;
                        str1[j] = str1[i] = str[i];
                    }
                    else
                    {
                        str1[i] = str[i]+1;
                        str1[j] = str1[i];
                    }
                }
                else
                {
                    str1[j] = str1[i] = str[i];
                }
            }
            if(str1 == str)
            {
                if(str[p] != '9')
                {
                    str1[p]+=1;
                }else
                {
                    str1[p-1] = str1[p+1] = str[p-1]+1;
                }
            }
        }
    }
    cout<<str1<<endl;
  }

  return 0;
}
