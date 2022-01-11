#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <ctime>
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
string TENINDIT(int a)
{
	string z;
	if (a == 0)
	{
		return "0";
	}
	while (a >= 2)
	{
		z.insert(0, to_string(a % 2));
		a = a / 2;
	}
	z.insert(0, "1");
	return z;
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
		while (r.length() < 281)
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
	while (tr[0] == '0' && tr.length() > 1)
	{
		tr.erase(0, 1);
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
	/*while (c.size() < 281)
	{
		c.insert(0, "0");
	}*/
	return c;
}
void FTEST(string a, string b, string c, string mod)
{
	string ab = LongAdd(a, b);
	ab = LongMul(ab, c);
	ab = Mod(ab, mod);
	cout << "(a + b)*c = " << endl << ab << endl;
	string ac = LongMul(a, c);
	ac = Mod(ac, mod);
	string bc = LongMul(b, c);
	bc = Mod(bc, mod);
	ab = LongAdd(ac, bc);
	cout << "a*c + c*b = " << endl << ab << endl;
	string m = "11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111";
	string d = LongPower(a, m, mod);
	d = LongAdd(d, mod);
	cout << "D^2^m-1 = " << d << endl;
}
string Zdvig(string a)
{
	string z;
	reverse(a.begin(), a.end());
	z = a[a.length() - 1];
	a.insert(0, z);
	a.erase(a.length()-1, 1);
	reverse(a.begin(), a.end());
	return a;
}
string MulKvar(string a)
{
	string z;
	z = a[a.length() - 1];
	a.insert(0, z);
	a.erase(a.length() - 1, 1);
	return a;
}
string MulMatr(string a, string m[])
{
	
	string c;
	for (int i = 0; i < 281; i++)
	{
		int step = 0;
		for (int j = 0; j < 281; j++)
		{
			step = step + (a[j] - '0') * (m[i][j] - '0');
			step = step % 2;
		}
		c.insert(0, to_string(step));
	}
	reverse(c.begin(), c.end());
	return c;
}
int Mulvect(string c, string b)
{
	int step = 0;
	for (int i = 0; i < 281; i++)
	{
		step = step + (c[i] - '0') * (b[i] - '0');
		step = step % 2;
	}
	return step;
}
string LongMulONB(string a, string b, string m[])
{
	int step = 0;
	string c;
	string e;
	for (int k = 0; k < 281; k++)
	{
		c = MulMatr(a, m);
		step = Mulvect(c, b);
		e.insert(0, to_string(step));
		a = Zdvig(a);
		b = Zdvig(b);
	}
	reverse(e.begin(), e.end());
	return e;
}
int POWmod(int a, int k)
{
	int temp = 1;
	if (k == 0)
	{
		return 1;
	}
	for (int i = 0; i < k; i++)
	{
		temp = (temp * a) % 563;
	}
	return temp;
}
string ItoTsiRevers(string a, string m[])
{
	string betta = a;
	int k = 1;
	string ma = "100011001";
	string bettakvar;
	for (int i = ma.length() - 1; i > -1; i--)
	{
		for (int j = 0; j < k; j++)
		{
			bettakvar = MulKvar(betta);
		}
		betta = LongMulONB(bettakvar, betta, m);
		k = 2 * k;
		if (ma[i] == 1)
		{
			bettakvar = MulKvar(betta);
			betta = LongMulONB(bettakvar, a, m);
			k++;
		}
	}
	betta = MulKvar(betta);
	a = betta;
	return a;
}
string ONBPower(string a, string n, string m[])
{
	string c = "11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111";
	for (int i = n.length() - 1; i >= 0; i--)
	{
		if (n[i] == '1')
		{
			c = LongMulONB(c, a, m);
		}
		a = MulKvar(a);
	}
	return c;
}
int ONBtrace(string a)
{
	int temp = 0;
	for (int i = 0; i < a.length() - 1; i++)
	{
		temp = temp + a[i] - '0';
	}
	temp = temp % 2;
	return temp;
}
void FTEST2(string m[])
{
	string a = "01110110000001000011000101111010100110111101100011110000010110111100101101111001111110111110011010110000101001110110100011100001000111001011001110010001000110010000001111001100011100011110010000111010110100011111101010100011011111001110000001111000010100111111010110100111110011010";
	string b = "01010010011011100101011010001001110011010101011100010110000011111010101100111101000010011110011000110100001001111101001100011111100110111101001011001010001010011001110100111111110011111110000110011111010110001000111110110101010000101001000111111111111000001001110010111010010010100";
	string c = "01000010100111000011111001110111100110011111001110100101111000100101000001110011010111010111101000100101011111111110011010111011001100001111111010111100010011010110001100110111101100100100100000001110001000001100001000001101101111101111111010001000111101000000000011100001110111000";
	string ab = LongAdd(a, b);
	ab = LongMulONB(ab, c, m);
	cout << "(a + b)*c = " << endl << ab << endl;
	string ac = LongMulONB(a, c, m);
	string bc = LongMulONB(b, c, m);
	ab = LongAdd(ac, bc);
	cout << "a*c + c*b = " << endl << ab << endl;
	string am = ONBPower(a, "11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111", m);
	cout << "(A ^ 2 ^ m - 1 = )" << am << endl;
}


int main()
{
	string number1, number2, number3;
	getline(cin, number1);
	getline(cin, number2);
	unsigned int start_timepl1 = clock();
	number3 = LongAdd(number1, number2);
	unsigned int end_timepl1 = clock();
	cout << "A+B = " << endl << number3 << endl;
	unsigned int search_timepl1 = end_timepl1 - start_timepl1;
	cout << endl << "Time + " << search_timepl1 << endl;
	unsigned int start_timem1 = clock();
	string number4 = LongMul(number1, number2);
	unsigned int end_timem1 = clock();
	string nummod = "100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001000010011";
	cout << "A*B = " << endl << Mod(number4, nummod)  << endl;
	unsigned int search_timem1 = end_timem1 - start_timem1;
	cout << endl << "Time * " << search_timem1 << endl;
	unsigned int start_timeot1 = clock();
	string kvadr = LongMul(number1, number1);
	unsigned int end_timeot1 = clock();
	cout << "A^2 = " << endl << Mod(kvadr, nummod) << endl;
	unsigned int search_timeot1 = end_timeot1 - start_timeot1;
	cout << endl << "Time - " << search_timeot1 << endl;
	unsigned int start_timetr1 = clock();
	string trace = Trace(number1, nummod);
	unsigned int end_timetr1 = clock();
	cout << "Trace = " << endl << trace << endl;
	unsigned int search_timetr1 = end_timetr1 - start_timetr1;
	cout << endl << "Time Trace " << search_timetr1 << endl;
	string n;
	cout << "Please write your N" << endl;
	getline(cin, n);
	unsigned int start_times1 = clock();
	string power = LongPower(number1, n, nummod);
	unsigned int end_times1 = clock();
	unsigned int search_times1 = end_times1 - start_times1;
	cout << "A^N = " << endl << power << endl;
	cout << endl << "Time ^ " << search_times1 << endl;
	string m2 = "11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111110";
	unsigned int start_timed1 = clock();
	string revers = LongPower(number1, m2, nummod);
	unsigned int end_timed1 = clock();
	unsigned int search_timed1 = end_timed1 - start_timed1;
	cout << "A^-1 = " << endl << revers << endl;
	cout << endl << "Time -1 = " << search_timed1 << endl;
	FTEST(number1, number2, n, nummod);  //end of 3 lab
	cout << "Operation in ONB" << endl << " A+B = " << number3 << endl;
	string matrix[281];
	int step, step1;
	string z;
	int a;
	int odin = 0;
	for (int i = 0; i < 281; i++)
	{
		z = "";
		for (int j = 0; j < 281; j++)
		{
			
			if (((POWmod(2,i) + POWmod(2, j)) % 563 == 1) || ((-POWmod(2, i) + POWmod(2, j)) % 563 == 1) || ((POWmod(2, i) - POWmod(2, j)) % 563 == 1) || ((-POWmod(2, i) - POWmod(2, i)) % 563 == 1) || ((-POWmod(2, i) + POWmod(2, j)) % 563 == -1) || ((POWmod(2, i) + POWmod(2, j)) % 563 == -1) || ((POWmod(2, i) - POWmod(2, j)) % 563 == -1) || ((-POWmod(2, i) - POWmod(2, j)) % 563 == -1) || ((POWmod(2, i) + POWmod(2, j)) % 563 == 562) || ((-POWmod(2, i) + POWmod(2, j)) % 563 == 562) || ((POWmod(2, i) - POWmod(2, j)) % 563 == 562) || ((-POWmod(2, i) - POWmod(2, i)) % 563 == 562))
			{
				z.insert(0, "1");
				odin++;
			}
			else
			{
				z.insert(0, "0");
			}
		}
		reverse(z.begin(), z.end());
		matrix[i] = z;
		cout << matrix[i] << endl;
		cout << "///////" << endl;
	}
	cout << "Kolichestvo 1 " << odin << endl;
	FTEST2(matrix);
	unsigned int start_timem = clock();
	string n2 = LongMulONB(number1, number2, matrix);
	unsigned int end_timem = clock();
	cout << "A*B = " << endl << n2 << endl;
	unsigned int search_timem = end_timem - start_timem;
	cout << endl << "Time * " << search_timem << endl;
	unsigned int start_timetr = clock();
	int t = ONBtrace(number1);
	unsigned int end_timetr = clock();
	unsigned int search_timetr = end_timetr - start_timetr;
	cout << endl << "Time Trace " << search_timetr << endl;
	cout << "Trace = " << endl << t << endl;
	unsigned int start_timekv = clock();
	string ONBkvad = MulKvar(number1);
	unsigned int end_timekv = clock();
	unsigned int search_timekv = end_timekv - start_timekv;
	cout << "A^2 = " << endl << ONBkvad << endl;
	cout << endl << "Time kvadrat " << search_timekv << endl;
	string N;
	cout << "Please write your N" << endl;
	getline(cin, N);
	unsigned int start_timest = clock();
	string powerONB = ONBPower(number1, N, matrix);
	unsigned int end_timest = clock();
	unsigned int search_timest = end_timest - start_timest;
	cout << "A^N = " << endl << powerONB << endl;
	cout << endl << "Time step " << search_timest << endl;
	string min = "11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111110";
	unsigned int start_timeot = clock();
	string powerMONB = ONBPower(number1, min, matrix);
	unsigned int end_timeot = clock();
	unsigned int search_timeot = end_timeot - start_timeot;
	cout << "A^-1 = " << endl << powerMONB << endl;
	cout << endl << "Time -1 " << search_timeot << endl;
	return 0;
}