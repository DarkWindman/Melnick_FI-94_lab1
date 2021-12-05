#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;

string OneLong(string a, string b)
{
	while (a.length() - 1 != b.length() - 1)
	{
		a.insert(0, "0");
	}
	return a;
}
string LongAdd(string n1, string n2)
{
	if (n1.length() - 1 > n2.length() - 1)
	{
		n2 = OneLong(n2, n1);
	}
	else if (n1.length() - 1 < n2.length() - 1)
	{
		n1 = OneLong(n1, n2);
	}
	string c;
	int temp = 0;
	reverse(n1.begin(), n1.end());
	reverse(n2.begin(), n2.end());
	for (int i = 0; i < n1.length(); i++)
	{
		temp = n1[i] - '0' + n2[i] - '0';
		c.insert(0, to_string(temp % 2));
	}
	return c;
}

int LongCmp(string n1, string n2)
{
	if (n1.length() - 1 > n2.length() - 1)
	{
		n2 = OneLong(n2, n1);
	}
	else if (n1.length() - 1 < n2.length() - 1)
	{
		n1 = OneLong(n1, n2);
	}
	int i = n1.length() - 1;
	reverse(n1.begin(), n1.end());
	reverse(n2.begin(), n2.end());
	while (i >= 0 && n1[i] == n2[i])
	{
		i = i - 1;
	}
	if (i == -1)
	{
		return 0;
	}
	else
	{
		if (n1[i] > n2[i])
		{
			return 1;
		}
		else
		{
			return -1;
		}
	}
}
string LongMulOneDigit(string num1, int b)
{
	string c;
	int carry = 0, temp = 0;
	for (int i = 0; i < num1.length(); i++)
	{
		temp = (num1[i] - '0') * b + carry;
		c.insert(0, to_string(temp & 1));
		carry = temp >> 1;
	}
	c.insert(0, to_string(carry));
	return c;
}
string LongShiftDigitsToHigh(string num1, int b)
{
	reverse(num1.begin(), num1.end());
	for (int i = 0; i < b; i++)
	{
		num1.insert(0, "0");
	}
	reverse(num1.begin(), num1.end());
	return num1;
}
string LongMul(string n1, string n2)
{
	string c = "0";
	string temp;
	reverse(n1.begin(), n1.end());
	reverse(n2.begin(), n2.end());
	if (n1.length() >= n2.length())
	{
		for (int i = 0; i < n2.length(); i++)
		{
			temp = LongMulOneDigit(n1, n2[i] - '0');
			temp = LongShiftDigitsToHigh(temp, i);
			c = LongAdd(temp, c);
		}
	}
	else
	{
		for (int i = 0; i < n1.length(); i++)
		{
			temp = LongMulOneDigit(n2, n1[i] - '0');
			temp = LongShiftDigitsToHigh(temp, i);
			c = LongAdd(temp, c);
		}
	}
	while (c[0] == '0' && c.length() > 1)
	{
		c.erase(0, 1);
	}
	return c;
}

string Mod(string a, string b)
{
	while (b[0] == '0' && b.length() > 1)
	{
		b.erase(0, 1);
	}
	while (a[0] == '0' && a.length() > 1)
	{
		a.erase(0, 1);
	}
	int k = b.length();
	string r = a;
	string q = "0";
	string c;
	int cmp = LongCmp(r, b);
	string step = "1";
	while (cmp >= 0)
	{
		int t = r.length();
		c = LongShiftDigitsToHigh(b, t - k);
		cmp = LongCmp(r, c);
		r = LongAdd(r, c);
		while (r[0] == '0' && r.length() > 1)
		{
			r.erase(0, 1);
		}
		cmp = LongCmp(r, b);
	}
	if (q == "0000")
	{
		cout << "Can`t div this numbers..." << endl;
		return r;
	}
	else
	{
		while (r.length() != 281)
		{
			r.insert(0, "0");
		}
		return r;
	}
}
string Trace(string a, string mod)
{
	string tr = "0";
	for (int i = 0; i < 281; i++)
	{
		a = LongMul(a, a);
		a = Mod(a, mod);
		tr = LongAdd(tr, a);
	}
	return tr;
}
string LongPower(string a, string b, string mod)
{
	string c = "1";
	while (a[0] == '0' && a.length() > 1)
	{
		a.erase(0, 1);
	}
	while (b[0] == '0' && b.length() > 1)
	{
		b.erase(0, 1);
	}
	for (int i = b.length() - 1; i >= 0; i--)
	{
		if (b[i] == '1')
		{
			c = LongMul(c, a);
			c = Mod(c, mod);
		}
		while (c[0] == '0' && c.length() > 1)
		{
			c.erase(0, 1);
		}
		a = LongMul(a, a);
		a = Mod(a, mod);
		while (a[0] == '0' && a.length() > 1)
		{
			a.erase(0, 1);
		}
	}
	return c;
}

int main()
{
	string number1, number2, number3;
	getline(cin, number1);
	getline(cin, number2);
	number3 = LongAdd(number1, number2);
	cout << "A+B = " << endl << number3 << endl;
	string number4 = LongMul(number1, number2);
	string nummod = "100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001000010011";
	cout << "A*B = " << endl << Mod(number4, nummod)  << endl;
	string kvadr = LongMul(number1, number1);
	cout << "A^2 = " << endl << Mod(kvadr, nummod) << endl;
	string trace = Trace(number1, nummod);
	cout << "Trace = " << endl << trace;
	string N;
	cout << "Please write your N" << endl;
	getline(cin, N);
	string power = LongPower(number1, N, nummod);
	cout << "A^N = " << endl << power << endl;
	string m2 = "11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111110";
	string revers = LongPower(number1, m2, nummod);
	cout << "A^-1 = " << endl << revers << endl;
	return 0;
}