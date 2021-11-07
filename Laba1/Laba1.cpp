#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;
string HEXINBIT(string a)
{
	string c;
	char* n1 = new char[a.length() + 1];
	a.copy(n1, a.length() + 1);
	for (int i = 0; i < a.length() + 1; i++)
	{
		switch (n1[i])
		{
		case '0': c += "0000";
			break;
		case '1': c += "0001";
			break;
		case '2': c += "0010";
			break;
		case '3': c += "0011";
			break;
		case '4': c += "0100";
			break;
		case '5': c += "0101";
			break;
		case '6': c += "0110";
			break;
		case '7': c += "0111";
			break;
		case '8': c += "1000";
			break;
		case '9': c += "1001";
			break;
		case 'A': c += "1010";
			break;
		case 'B': c += "1011";
			break;
		case 'C': c += "1100";
			break;
		case 'D': c += "1101";
			break;
		case 'E': c += "1110";
			break;
		case 'F': c += "1111";
		}
	}
	return c;
}
string BININHEX(string n)
{
	while (n.length() % 4 != 0)
	{
		n.insert(0, "0");
	}
	string c;
	for (int i = 0; i < n.length()-1; i=i+4)
	{
		if (n[i] == '0' && n[i + 1] == '0' && n[i+2] == '0' && n[i+3]== '0')
		{
			c += "0";
		}
		if (n[i] == '0' && n[i + 1] == '0' && n[i + 2] == '0' && n[i + 3] == '1')
		{
			c += "1";
		}
		if (n[i] == '0' && n[i + 1] == '0' && n[i + 2] == '1' && n[i + 3] == '0')
		{
			c += "2";
		}
		if (n[i] == '0' && n[i + 1] == '0' && n[i + 2] == '1' && n[i + 3] == '1')
		{
			c += "3";
		}
		if (n[i] == '0' && n[i + 1] == '1' && n[i + 2] == '0' && n[i + 3] == '0')
		{
			c += "4";
		}
		if (n[i] == '0' && n[i + 1] == '1' && n[i + 2] == '0' && n[i + 3] == '1')
		{
			c += "5";
		}
		if (n[i] == '0' && n[i + 1] == '1' && n[i + 2] == '1' && n[i + 3] == '0')
		{
			c += "6";
		}
		if (n[i] == '0' && n[i + 1] == '1' && n[i + 2] == '1' && n[i + 3] == '1')
		{
			c += "7";
		}
		if (n[i] == '1' && n[i + 1] == '0' && n[i + 2] == '0' && n[i + 3] == '0')
		{
			c += "8";
		}
		if (n[i] == '1' && n[i + 1] == '0' && n[i + 2] == '0' && n[i + 3] == '1')
		{
			c += "9";
		}
		if (n[i] == '1' && n[i + 1] == '0' && n[i + 2] == '1' && n[i + 3] == '0')
		{
			c += "A";
		}
		if (n[i] == '1' && n[i + 1] == '0' && n[i + 2] == '1' && n[i + 3] == '1')
		{
			c += "B";
		}
		if (n[i] == '1' && n[i + 1] == '1' && n[i + 2] == '0' && n[i + 3] == '0')
		{
			c += "C";
		}
		if (n[i] == '1' && n[i + 1] == '1' && n[i + 2] == '0' && n[i + 3] == '1')
		{
			c += "D";
		}
		if (n[i] == '1' && n[i + 1] == '1' && n[i + 2] == '1' && n[i + 3] == '0')
		{
			c += "E";
		}
		if (n[i] == '1' && n[i + 1] == '1' && n[i + 2] == '1' && n[i + 3] == '1')
		{
			c += "F";
		}
	}
	return c;
}
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
	string c;
	if (n1.length() - 1 > n2.length() - 1)
	{
		n2 = OneLong(n2, n1);
	}
	else if(n1.length() - 1 < n2.length() - 1)
	{
		n1 = OneLong(n1, n2);
	}
	int temp = 0, carry = 0;
	reverse(n1.begin(), n1.end());
	reverse(n2.begin(), n2.end());
	for (int i = 0; i < n1.length(); i++)
	{
		temp = n1[i] - '0' + n2[i] - '0' + carry;
		c.insert(0, to_string(temp % 2));
		carry = temp / 2;
	}
	if (carry != 0)
	{
		c.insert(0, to_string(carry));
	}
	return c;
}
string LongSub(string n1, string n2)
{
	string c;
	int borrow = 0, temp =0;
	if (n1.length() - 1 > n2.length() - 1)
	{
		n2 = OneLong(n2, n1);
	}
	else if (n1.length() - 1 < n2.length() - 1)
	{
		n1 = OneLong(n1, n2);
	}
	reverse(n1.begin(), n1.end());
	reverse(n2.begin(), n2.end());
	for (int i = 0; i < n1.length(); i++)
	{
		temp = n1[i]  - n2[i] - borrow;
		if (temp >= 0)
		{
			c.insert(0, to_string(temp));
			borrow = 0;
		}
		else
		{
			c.insert(0, to_string(temp + 2));
			borrow = 1;
		}
	}
	if (borrow == 0)
	{
		return c;
	}
	else
	{
		string n =  "-1";
		return n;
	}
}
string LongMulOneDigit(string num1, int b)
{
	string c;
	int carry = 0, temp = 0;
	for (int i = 0; i < num1.length(); i++)
	{
		temp = (num1[i] - '0') * b + carry;
		c.insert(0,to_string(temp & 1));
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
string LongPower(string a, string b)
{
	string c = "0001";
	if (a.length() - 1 > b.length() - 1)
	{
		b = OneLong(b, a);
	}
	else if (a.length() - 1 < b.length() - 1)
	{
		a = OneLong(a, b);
	}
	for (int i = b.length() - 1; i >= 0; i--)
	{
		if (b[i] == '1')
		{
			c = LongMul(c, a);
		}
		a = LongMul(a, a);
	}
	return c;
}
string LongDivMod(string a, string b)
{
	int k = b.length();
	string r = a;
	string q = "0";
	string c;
	int cmp = LongCmp(r, b);
	string step = "1";
	while ( cmp >= 0)
	{
		int t = r.length();
		c = LongShiftDigitsToHigh(b, t - k);
		cmp = LongCmp(r, c);
		if (cmp < 0)
		{
			t = t - 1;
			c = LongShiftDigitsToHigh(b, t - k);
		}
		r = LongSub(r, c);
		step = "1";
		step = LongShiftDigitsToHigh(step, t - k);
		q = LongAdd(q, step);
		while (r[0] == '0' && r.length() > 1)
		{
			r.erase(0, 1);
		}
		cmp = LongCmp(r, b);
	}
	if ( q == "0000")
	{
		cout << "Can`t div this numbers..." << endl;
		return q;
	}
	else
	{
		return q;
	}
}


int main()
{
	string number1, number2;
	getline(cin, number1);
	getline(cin, number2);
	string num1 = HEXINBIT(number1);
	cout << num1 << endl;
	string num2 = HEXINBIT(number2);
	cout << num2 << endl;
	string c = BININHEX(LongAdd(num1, num2));
	cout << "A+B = " << c << endl;
	string d = LongSub(num1, num2);
	if (d == "-1")
	{
		cout << "attention, you subtract less from more. Please change the order of the numbers" << endl;
	}
	else
	{
		cout << "A-B = " << BININHEX(d) << endl;
	}
	string e = LongMul(num1, num2);
	cout << "E = A*B = " << BININHEX(e) << endl;
	int cmp = LongCmp(num1, num2);
	if (cmp == 0)
	{
		cout << "A = B" << endl;
	}
	else if (cmp == 1)
	{
		cout << "A > B" << endl;
	}
	else
	{
		cout << " A < B" << endl;
	}
	string f = LongDivMod(e, num2);
	cout << "E / B = " << endl;
	cout << BININHEX(f) << endl;
	string g = LongPower(num1, num2);
	cout << "A ^ B = " << endl;
	cout << BININHEX(g) << endl;
	return 0;
}