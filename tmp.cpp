#include<iostream>
#include<deque>
using  namespace std;

class bigInteger
{
private:
    deque<int> value;

public:
    bigInteger () {};
    bigInteger (int x)
    {
        while (x)
        {
            value.push_front(x % 10);
            x /= 10;
        }
    }

    void print ()
    {
        deque<int>::const_iterator iter = value.begin();
        for (; iter != value.end(); iter++)
        {
            printf("%d", *iter);
        }
        printf("\n");
    }

    bigInteger operator + (const bigInteger& B) const
    {
        bigInteger res;
        int carry = 0;
        deque<int>::const_reverse_iterator iter, iter_B;
        iter = value.rbegin();
        iter_B = B.value.rbegin();

        while (iter != value.rend() || iter_B != B.value.rend() || carry)
        {
            int v1, v2;
            v1 = v2 = 0;
            if (iter != value.rend())
            {
                v1 = *iter;
                iter++;
            }
            if (iter_B != B.value.rend())
            {
                v2 = *iter_B;
                iter_B++;
            }
            int sum = v1 + v2 + carry;
            res.value.push_front(sum % 10);
            carry = sum / 10;
        }
        return res;
    }

    friend istream& operator >> (istream& is, bigInteger& bigInt);
};

istream& operator >> (istream& is, bigInteger& bigInt)
{
    string s;
    cin >> s;
    bigInt.value.clear();
    for (int i = 0; s[i]; i++)
    {
        bigInt.value.push_back(s[i] - '0');
    }
    return is;
}

int main ()
{
    bigInteger a, b;
    while (cin >> a >> b) 
    {
        bigInteger res = a + b;
        res.print();
    }
    return 0;
}