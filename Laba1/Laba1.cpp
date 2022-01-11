#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <ctime>
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
	for (int i = 0; i < n.length() - 1; i = i + 4)
	{
		if (n[i] == '0' && n[i + 1] == '0' && n[i + 2] == '0' && n[i + 3] == '0')
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
string TENINDIT(int a)
{
	string z;
	while (a >= 2)
	{
		z.insert(0, to_string(a % 2));
		a = a / 2;
	}
	z.insert(0, "1");
	return z;
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
	else if (n1.length() - 1 < n2.length() - 1)
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
	int borrow = 0, temp = 0;
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
		temp = n1[i] - n2[i] - borrow;
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
		string n = "-1";
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
		}
		while (c[0] == '0' && c.length() > 1)
		{
			c.erase(0, 1);
		}
		a = LongMul(a, a);
		while (a[0] == '0' && a.length() > 1)
		{
			a.erase(0, 1);
		}
	}
	return c;
}
string LongDiv(string a, string b)
{
	while (a[0] == '0' && a.length() > 1)
	{
		a.erase(0, 1);
	}
	while (b[0] == '0' && b.length() > 1)
	{
		b.erase(0, 1);
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
	if (q == "0000")
	{
		cout << "Can`t div this numbers..." << endl;
		return q;
	}
	else
	{
		return q;
	}
}
string LongMod(string a, string b)
{
	while (a[0] == '0' && a.length() > 1)
	{
		a.erase(0, 1);
	}
	while (b[0] == '0' && b.length() > 1)
	{
		b.erase(0, 1);
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
	if (q == "0000")
	{
		cout << "Can`t div this numbers..." << endl;
		return r;
	}
	else
	{
		return r;
	}
}
string GCD(string a, string b)
{
	string d = "1";
	string two = "10";
	string a1;
	while (a[0] == '0' && a.length() > 1)
	{
		a.erase(0, 1);
	}
	while (b[0] == '0' && b.length() > 1)
	{
		b.erase(0, 1);
	}
	while (a[a.length() - 1] == '0' && b[b.length() - 1] == '0')
	{
		a = LongDiv(a, two);
		b = LongDiv(b, two);
		d = LongMul(d, two);
	}
	while (a[a.length() - 1] == '0')
	{
		a = LongDiv(a, two);
	}
	while (b != "0")
	{
		while (b[b.length() - 1] == '0')
		{
			b = LongDiv(b, two);
		}
		int cmp = LongCmp(a, b);
		if (cmp >= 0)
		{
			a1 = b;
			b = LongSub(a, b);
			a = a1;
		}
		else
		{
			b = LongSub(b, a);
		}
		while (b[0] == '0' && b.length() > 1)
		{
			b.erase(0, 1);
		}
	}
	d = LongMul(a, d);
	return d;
}
string GCK(string a, string b, string i)
{
	string d = LongMul(a, b);
	while (i[0] == '0' && i.length() > 1)
	{
		i.erase(0, 1);
	}
	if (i == "1")
	{
		return d;
	}
	else
	{
		while (d[0] == '0' && d.length() > 1)
		{
			d.erase(0, 1);
		}
		d = LongDiv(d, i);
		return d;
	}
}

string KLD(string a, int l)
{
	if (a.length() < l) l = a.length();
	a.resize(a.length() - l);
	return a;
}
string Barret(string x, string n, string y)
{
	int k = n.length();
	string q = KLD(x, k - 1);
	q = LongMul(y, q);
	q = KLD(q, k + 1);
	q = LongMul(q, n);
	string r = LongSub(x, q);
	while (LongCmp(r, n) == 1)
	{
		r = LongSub(r, n);
	}

	while (r[0] == '0' && r.length() > 1)
	{
		r.erase(0, 1);
	}
	if (LongCmp(r, n) == 0)
	{
		r = "0";
	}
	return r;
}
string BarretLongPower(string a, string b, string n)
{
	string c = "1";
	string y = LongShiftDigitsToHigh("1", 2 * n.length());
	y = LongDiv(y, n);
	while (y[0] == '0' && y.length() > 1)
	{
		y.erase(0, 1);
	}
	reverse(b.begin(), b.end());
	for (int i = 0; i < b.length(); i++)
	{
		cout << i << endl;
		if (b[i] == '1')
		{
			c = Barret(LongMul(c, a), n, y);
		}
		a = Barret(LongMul(a, a), n, y);
	}
	return c;
}
void FSTEST()
{
	string a, b, c;
	getline(cin, a);
	getline(cin, b);
	getline(cin, c);
	a = HEXINBIT(a);
	b = HEXINBIT(b);
	c = HEXINBIT(c);
	string abc = LongMul(LongAdd(a, b), c);
	abc = BININHEX(abc);
	cout << "(a+b)c = " << abc << endl;
	string cab = LongMul(c, LongAdd(a, b));
	cab = BININHEX(cab);
	cout << "c(a+b) = " << cab << endl;
	string cacb = LongAdd(LongMul(a, c), LongMul(b, c));
	cacb = BININHEX(cacb);
	cout << "ca+cb = " << cab << endl;
	string n = "C8";
	string na = a;
	n = HEXINBIT(n);
	for (int i = 0; i < 199; i++)
	{
		na = LongAdd(na, a);
	}
	na = BININHEX(na);
	cout << "a+a+a+a+... = " << na << endl;
	string an = LongMul(n, a);
	an = BININHEX(an);
	cout << "na = " << an << endl;

}
void FSTEST2()
{
	string a, b, c, mod;
	getline(cin, a);
	getline(cin, b);
	getline(cin, c);
	getline(cin, mod);
	a = HEXINBIT(a);
	b = HEXINBIT(b);
	c = HEXINBIT(c);
	mod = HEXINBIT(mod);
	string one = "1";
	one = LongShiftDigitsToHigh(one, 2 * mod.length());
	string y = LongDiv(one, mod);
	string abc = LongMul(LongAdd(a, b), c);
	abc = Barret(abc, mod, y);
	abc = BININHEX(abc);
	cout << "(a+b)c mod n = " << abc << endl;
	string cab = LongMul(c, LongAdd(a, b));
	cab = Barret(cab, mod, y);
	cab = BININHEX(cab);
	cout << "c(a+b) mod n = " << cab << endl;
	string cacb = LongAdd(LongMul(a, c), LongMul(b, c));
	cacb = Barret(cacb, mod, y);
	cacb = BININHEX(cacb);
	cout << "ca+cb modn = " << cab << endl;
	string n = "C8";
	string na = a;
	n = HEXINBIT(n);
	for (int i = 0; i < 199; i++)
	{
		na = LongAdd(na, a);
	}
	na = Barret(na, mod, y);
	na = BININHEX(na);
	cout << "a+a+a+a+... mod n = " << na << endl;
	string an = LongMul(n, a);
	an = Barret(an, mod, y);
	an = BININHEX(an);
	cout << "ma modn = " << an << endl;

}
string Evklid(string a, string b)
{
	string r1 = a;
	string r2 = b;
	while (r1[0] == '0' && r1.length() > 1)
	{
		r1.erase(0, 1);
	}
	while (r2[0] == '0' && r2.length() > 1)
	{
		r2.erase(0, 1);
	}
	while (r2 != "0")
	{
		r1 = LongMod(r1, r2);
		if (r1 == "0")
		{
			r1 = r2;
			break;
		}
		r2 = LongMod(r2, r1);
		while (r1[0] == '0' && r1.length() > 1)
		{
			r1.erase(0, 1);
		}
		while (r2[0] == '0' && r2.length() > 1)
		{
			r2.erase(0, 1);
		}
	}
	return r1;
}

int main()
{
	string number1, number2, number3;
	getline(cin, number1);
	getline(cin, number2);
	string num1 = HEXINBIT(number1);
	string num2 = HEXINBIT(number2);
	cout << num1 << endl;
	cout << num2 << endl;
	unsigned int start_timepl1 = clock();
	string c = BININHEX(LongAdd(num1, num2));
	unsigned int end_timepl1 = clock();
	cout << "A+B = " << c << endl;
	unsigned int search_timepl1 = end_timepl1 - start_timepl1;
	cout << endl << "Time + " << search_timepl1 << endl;
	unsigned int start_timeot1 = clock();
	string d = LongSub(num1, num2);
	unsigned int end_timeot1 = clock();
	if (d == "-1")
	{
		cout << "attention, you subtract less from more. Please change the order of the numbers" << endl;
	}
	else
	{
		cout << "A-B = " << BININHEX(d) << endl;
		unsigned int search_timeot1 = end_timeot1 - start_timeot1;
		cout << endl << "Time - " << search_timeot1 << endl;
	}
	unsigned int start_timem1 = clock();
	string e = LongMul(num1, num2);
	unsigned int end_timem1 = clock();
	unsigned int search_timem1 = end_timem1 - start_timem1;
	cout << "E = A*B = " << BININHEX(e) << endl;
	cout << endl << "Time * " << search_timem1 << endl;
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
	unsigned int start_timed1 = clock();
	string f = LongDiv(e, num2);
	unsigned int end_timed1 = clock();
	cout << "(A*B) / B = " << endl;
	unsigned int search_timed1 = end_timed1 - start_timed1;
	cout << BININHEX(f) << endl;
	cout << endl << "Time / " << search_timed1 << endl;
	unsigned int start_times1 = clock();
	string g = LongPower(num1, num2);
	unsigned int end_times1 = clock();
	unsigned int search_times1 = end_times1 - start_times1;
	cout << "A ^ B = " << endl;
	cout << BININHEX(g) << endl;
	cout << endl << "Time ^ " << search_times1 << endl;
	string h = LongMod(e, num2);
	cout << "A Mod B = " << endl << BININHEX(h) << endl;
	unsigned int start_time = clock();
	string evklid = Evklid(num1, num2);
	unsigned int end_time = clock();
	unsigned int search_time = end_time - start_time;
	cout << "GCDEVKLID(A, B) = " << endl << BININHEX(evklid) << endl << "Time: " << search_time << endl;
	string evkl = GCK(num1, num2, evklid);
	end_time = clock();
	search_time = end_time - start_time;
	cout << "GCKEvklid(A, B) = " << endl << BININHEX(evkl) << endl << "Time: " << search_time << endl;
	start_time = clock();
	string i = GCD(num1, num2);
	end_time = clock();
	search_time = end_time - start_time;
	cout << "GCD(A, B) = " << endl << BININHEX(i) << endl << "Time: " << search_time << endl;
	string l = GCK(num1, num2, i);
	end_time = clock();
	search_time = end_time - start_time;
	cout << "GCK(A, B) = " << endl << BININHEX(l) << endl << "Time: " << search_time << endl;
	getline(cin, number3);
	string num3 = HEXINBIT(number3);
	cout << num3 << endl;
	string one = "1";
	one = LongShiftDigitsToHigh(one, 2 * num3.length());
	string y = LongDiv(one, num3);
	cout << "Modular operation :" << endl;
	unsigned int start_timep = clock();
	string o1 = Barret(LongAdd(num1, num2), num3, y);
	unsigned int end_timep = clock();
	unsigned int search_timep = end_timep - start_timep;
	cout << "A+B mod n = " << BININHEX(o1) << endl;
	cout << endl << "Time + " << search_timep << endl;
	unsigned int start_timeot = clock();
	string o2 = Barret(LongSub(num1, num2), num3, y);
	unsigned int end_timeot = clock();
	unsigned int search_timeot = end_timeot - start_timeot;
	cout << "A-B mod n = " << BININHEX(o2) << endl;
	cout << endl << "Time - " << search_timeot << endl;
	unsigned int start_timem = clock();
	string o3 = Barret(LongMul(num1, num2), num3, y);
	unsigned int end_timem = clock();
	unsigned int search_timem = end_timem - start_timem;
	cout << "A*B mod n = " << BININHEX(o3) << endl;
	cout << endl << "Time * " << search_timem << endl;
	unsigned int start_timekv = clock();
	string o5 = Barret(LongMul(num1, num1), num3, y);
	unsigned int end_timekv = clock();
	unsigned int search_timekv = end_timekv - start_timekv;
	cout << "A*A mod n = " << BININHEX(o5) << endl;
	cout << endl << "Time kvadrat " << search_timekv << endl;
	unsigned int start_timest = clock();
	string o4 = BarretLongPower(num1, num2, num3);
	unsigned int end_timest = clock();
	unsigned int search_timest = end_timest - start_timest;
	cout << "A^B mod n = " << BININHEX(o4) << endl;
	cout << endl << "Time step " << search_timest << endl;
	cout << "It`s a test 1:" << endl;
	FSTEST();
	cout << "It`s a test 2:" << endl;
	FSTEST2();
	return 0;
}