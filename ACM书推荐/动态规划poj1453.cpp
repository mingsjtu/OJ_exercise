//http://poj.org/problem?id=1453
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
using namespace std;
string cur;
char cur_n[10005];
map<char, int> m1;
char newindex[27];

int main()
{

    int i, j, k;
    for (char ia = 'A'; ia <='Z'; ia++)
        m1[ia] = int(ia-'A');

    for (i = 0; i < 26; i++)
    {
        newindex[i] = char('A' + i);
    }
    while (getline(cin, cur))
    {
        int len = cur.length();
        int tmp;
        if (cur.find("ENCRYPT") == 0)
        {
            for (i = 7; i < len; i++)
            {
                //cout << cur_n[1] << endl;
                if (cur[i] >= 'A'&&cur[i] <= 'Z')
                {

                    if (cur[i - 1] >= 'A'&&cur[i - 1] <= 'Z' || cur[i - 1] >= 'a'&&cur[i - 1] <= 'z')
                    {
                        if (cur[i - 1] >= 'a'&&cur[i - 1] <= 'z')
                            cur[i - 1] = cur[i - 1] - 'a' + 'A';
                        tmp = m1[cur[i]] - m1[cur[i - 1]];
                        cur_n[i - 7] = newindex[(tmp+26)%26];
                    }
                    else
                    {
                        tmp = m1[cur[i]] - m1['A'];
                        //cur_n[i - 7] = '#';
                        //cout << "at" << i << endl;
                        cur_n[i - 7] = newindex[(tmp + 26) % 26];
                        //cout << "at" << i <<"is"<< cur_n[i - 7] << endl;
                    }
                }
                else
                {
                    if (cur[i] >= 'a'&&cur[i] <= 'z')
                    {
                        if (cur[i - 1] >= 'A'&&cur[i - 1] <= 'Z' || cur[i - 1] >= 'a'&&cur[i - 1] <= 'z')
                        {
                            if (cur[i - 1] >= 'a'&&cur[i - 1] <= 'z')
                                cur[i - 1] = char(cur[i - 1] - 'a' + 'A');
                            tmp = m1[char(cur[i] - 'a' + 'A')] - m1[cur[i - 1]];
                            cur_n[i - 7] = char(newindex[(tmp + 26) % 26] - 'A' + 'a');
                        }
                        else
                        {
                            tmp = m1[char(cur[i] - 'a' + 'A')] - m1['A'];
                            cur_n[i - 7] = char(newindex[(tmp + 26) % 26] - 'A' + 'a');
                        }
                    }

                    else
                        cur_n[i - 7] = cur[i];
                }
            }
            cur_n[len - 7] = '\0';
            cout <<"RESULT: "<< cur_n << endl;
            continue;
        }

        if (cur.find("DECRYPT") == 0)
        {
            int tmp;
            for (i = 7; i < len; i++)
            {
                if (cur[i] >= 'A'&&cur[i] <= 'Z')
                {
                    if (cur_n[i - 8] >= 'A'&&cur_n[i - 8] <= 'Z' || cur_n[i - 8] >= 'a'&&cur_n[i - 8] <= 'z')
                    {
                        if (cur_n[i - 8] >= 'a'&&cur_n[i - 8] <= 'z')
                            tmp = m1[cur_n[i - 8]-'a'+'A'];
                        else
                            tmp = m1[cur_n[i - 8]];
                        cur_n[i - 7] = newindex[(tmp +m1[cur[i]]) % 26];
                    }
                    else
                        cur_n[i - 7] = newindex[(m1[cur[i]] + m1['A']) % 26];
                }
                else
                {
                    if (cur[i] >= 'a'&&cur[i] <= 'z')
                    {
                        if (cur_n[i - 8] >= 'A'&&cur_n[i - 8] <= 'Z' || cur_n[i - 8] >= 'a'&&cur_n[i - 8] <= 'z')
                        {
                            if (cur_n[i - 8] >= 'a'&&cur_n[i - 8] <= 'z')
                                tmp = m1[cur_n[i - 8] - 'a' + 'A'];
                            else
                                tmp = m1[cur_n[i - 8]];
                            cur_n[i - 7] = newindex[(tmp + m1[char(cur[i]-'a'+'A')]) % 26]-'A'+'a';
                        }
                        else
                            cur_n[i - 7] = newindex[(m1[char(cur[i]-'a'+'A')] + m1['A']) % 26] - 'A' + 'a';
                    }
                    else
                        cur_n[i - 7] = cur[i];
                }
            }
            cur_n[len - 7] = '\0';
            cout <<"RESULT: "<< cur_n << endl;
            continue;
        }

        if (cur.find("CIPHER") == 0)
        {
            bool flag[26];
            bool error = false;
            memset(flag, false, sizeof(flag));
            int index = 0;
            char new1[27];
            for (i = 6; i < cur.length(); i++)
            {
                if (cur[i] >= 'a'&&cur[i] <= 'z' || cur[i] >= 'A'&&cur[i] <= 'Z')
                {
                    new1[index] = cur[i] <= 'Z' ? cur[i] : char(cur[i] - 'a' + 'A');
                    //cout << cur[i]<<index << endl;
                    if (flag[new1[index]-'A'] == false)
                        flag[new1[index] - 'A'] = true;
                    else
                    {
                        error = true;
                        break;
                    }
                    index++;
                }
            }
            new1[index] = '\0';
            //cout << error << index << endl;
            if (error || index != 26)
            {
                for (char ia = 'A'; ia <='Z'; ia++)
                    m1[ia] = int(ia-'A');

                for (i = 0; i < 26; i++)
                {
                    newindex[i] = char('A' + i);
                }
                cout << "Bad cipher.  Using default." << endl;
            }
            else
            {
                printf("Good cipher.  Using %s.\n", new1);
                for (i = 0; i < 26; i++)
                {
                    m1[new1[i]] = i;
                    newindex[i]=new1[i];
                }
            }
            continue;
        }
        cout<<"Command not understood.\n";
    }
}
