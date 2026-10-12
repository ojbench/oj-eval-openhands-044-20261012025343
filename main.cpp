#include <string>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

class mystring
{
private:
    char *ch = nullptr;
    int len = 0;

public:

    mystring()
    {
        ch = nullptr;
        len = 0;
    }
    
    mystring(int _len, int c)
    {
        len = _len;
        ch = new char[len];
        for (int i = 0; i < len; i++) {
            ch[i] = (char)c;
        }
    }
    
    mystring(string &c)
    {
        len = c.length();
        ch = new char[len];
        for (int i = 0; i < len; i++) {
            ch[i] = c[i];
        }
    }
    
    ~mystring()
    {
        delete[] ch;
    }
    
    char operator[](int x) const
    {
        if (x < 0 || x >= len) {
            return '\0';
        }
        return ch[x];
    }
    
    bool operator<(const mystring &other) const
    {
        int min_len = (len < other.len) ? len : other.len;
        for (int i = 0; i < min_len; i++) {
            if (ch[i] < other.ch[i]) return true;
            if (ch[i] > other.ch[i]) return false;
        }
        return len < other.len;
    }
    
    bool operator==(const mystring &other) const
    {
        if (len != other.len) return false;
        for (int i = 0; i < len; i++) {
            if (ch[i] != other.ch[i]) return false;
        }
        return true;
    }
    
    mystring& operator+=(const mystring &other)
    {
        char *new_ch = new char[len + other.len];
        for (int i = 0; i < len; i++) {
            new_ch[i] = ch[i];
        }
        for (int i = 0; i < other.len; i++) {
            new_ch[len + i] = other.ch[i];
        }
        delete[] ch;
        ch = new_ch;
        len += other.len;
        return *this;
    }
    
    mystring operator+(const mystring &other) const
    {
        mystring result = *this;
        result += other;
        return result;
    }
    
    void ADD(const mystring &other)
    {
        *this += other;
    }
    
    void out() const
    {
        for (int i = 0; i < len; i++) {
            cout << ch[i];
        }
    }
    
    int get_len() const
    {
        return len;
    }
};

string str_in1, str_in2;
int n, id;
int main()
{
    cin >> id;
    if (id == 1)
    {
        mystring str1(100,'a');
        str1.out(); puts("");
        // cout << str1 << endl;
    }
    else if (id == 2)
    {
        cin >> str_in1;
        mystring str2 = str_in1;
        cin >> n;
        for (int i = 0, x; i < n; ++ i)
        {
            cin >> x;
            cout << str2[x] << endl;
        }
    }
    else if (id == 3)
    {
        cin >> str_in1 >> str_in2;
        mystring str2 = str_in1;
        mystring str3 = str_in2;
        cout << (int)(str2 < str3) << endl;
    }
    else if (id == 4)
    {
        cin >> str_in1 >> str_in2;
        mystring str2 = str_in1;
        mystring str3 = str_in2;
        str2.ADD(str3);
        str2.out(); puts("");
        // cout << str2 << endl;
    }
    else
    {
        cin >> str_in1 >> str_in2;
        mystring str2 = str_in1;
        mystring str3 = str_in2;
        cin >> n;
        for (int i = 0, x; i < n; ++ i)
        {
            cin >> x;
            cout << str3[x] << endl;
        }
        cout << str2.get_len() << " " << str3.get_len() << endl;
        cout << (int)(str2 < str3) << endl;
        str2.ADD(str3);
        str2.out(); puts("");
        // cout << str2 << endl;
        cout << str2.get_len() << endl;
    }
    return 0;
}