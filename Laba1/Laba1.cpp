#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class HEXCalculator
{
public: string a;
	  int* HEXINBIT(string a)
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
		  reverse(c.begin(), c.end());
		  c.resize(2048, '0');
		  char* numb1 = new char[c.length() + 1];
		  c.copy(numb1, c.length() + 1);
		  int* num1 = new int[(c.length() + 1)];
		  for (int i = 0; i < c.length(); i++)
		  {
			  num1[i] = numb1[i] - '0';
		  }
		  cout << "In bit:" << endl;
		  for (int i = 0; i < c.length(); i++)
		  {
			  cout << num1[i];
		  }
		  return num1;
	  }
	  string BININHEX(int* n)
	  {
		  string c;
		  for (int i = 0; i < 2048; i=i+4)
		  {
			  if (n[i] == 0 && n[i + 1] == 0 && n[i+2] == 0 && n[i+3]==0)
			  {
				  c += "0";
			  }
			  if (n[i] == 1 && n[i + 1] == 0 && n[i + 2] == 0 && n[i + 3] == 0)
			  {
				  c += "1";
			  }
			  if (n[i] == 0 && n[i + 1] == 1 && n[i + 2] == 0 && n[i + 3] == 0)
			  {
				  c += "2";
			  }
			  if (n[i] == 1 && n[i + 1] == 1 && n[i + 2] == 0 && n[i + 3] == 0)
			  {
				  c += "3";
			  }
			  if (n[i] == 0 && n[i + 1] == 0 && n[i + 2] == 1 && n[i + 3] == 0)
			  {
				  c += "4";
			  }
			  if (n[i] == 1 && n[i + 1] == 0 && n[i + 2] == 1 && n[i + 3] == 0)
			  {
				  c += "5";
			  }
			  if (n[i] == 0 && n[i + 1] == 1 && n[i + 2] == 1 && n[i + 3] == 0)
			  {
				  c += "6";
			  }
			  if (n[i] == 1 && n[i + 1] == 1 && n[i + 2] == 1 && n[i + 3] == 0)
			  {
				  c += "7";
			  }
			  if (n[i] == 0 && n[i + 1] == 0 && n[i + 2] == 0 && n[i + 3] == 1)
			  {
				  c += "8";
			  }
			  if (n[i] == 1 && n[i + 1] == 0 && n[i + 2] == 0 && n[i + 3] == 1)
			  {
				  c += "9";
			  }
			  if (n[i] == 0 && n[i + 1] == 1 && n[i + 2] == 0 && n[i + 3] == 1)
			  {
				  c += "A";
			  }
			  if (n[i] == 1 && n[i + 1] == 1 && n[i + 2] == 0 && n[i + 3] == 1)
			  {
				  c += "B";
			  }
			  if (n[i] == 0 && n[i + 1] == 0 && n[i + 2] == 1 && n[i + 3] == 1)
			  {
				  c += "C";
			  }
			  if (n[i] == 1 && n[i + 1] == 0 && n[i + 2] == 1 && n[i + 3] == 1)
			  {
				  c += "D";
			  }
			  if (n[i] == 0 && n[i + 1] == 1 && n[i + 2] == 1 && n[i + 3] == 1)
			  {
				  c += "E";
			  }
			  if (n[i] == 1 && n[i + 1] == 1 && n[i + 2] == 1 && n[i + 3] == 1)
			  {
				  c += "F";
			  }
		  }
		  reverse(c.begin(), c.end());
		  return c;
	  }
	  void LongAdd(string a, string b)
	  {
		  int* num1 = HEXINBIT(a);
		  int* num2 = HEXINBIT(b);
		  int * c = new int[2048];
		  int carry =0 , temp = 0;
		  for (int i = 0; i < 2048; i++)
		  {
			  temp = num1[i] + num2[i] + carry;
			  c[i] = temp % 2;
			  carry = temp / 2;
		  }
		  cout << "A+B = " << endl;
		  /*char* numb1 = new char[2048];
		  for (int i = 0; i < 2048; i++)
		  {
			  numb1[i] = c[i] + '0';
		  }
		  string s = string(numb1);
		  cout << s << endl;
		  cout << endl << "Normal form" << endl;
		  reverse(s.begin(), s.end());*/
		  string str = BININHEX(c);
		  cout << str << endl;
	  }
	  void LongSub(string a, string b)
	  {
		  int* num1 = HEXINBIT(a);
		  int* num2 = HEXINBIT(b);
		  int* c = new int[2048];
		  int borrow = 0, temp =0;
		  for (int i = 0; i < 2048; i++)
		  {
			  temp = num1[i] - num2[i] - borrow;
			  if (temp >= 0)
			  {
				  c[i] = temp;
				  borrow = 0;
			  }
			  else
			  {
				  c[i] = 2 + temp;
				  borrow = 1;
			  }
		  }
		  cout << endl << "A-B = " << endl;
		  string str = BININHEX(c);
		  cout << str << endl;
	  }
	  
 };

int main()
{
	string number1, number2;
	getline(cin, number1);
	getline(cin, number2);
	HEXCalculator A;
	/*A.LongAdd(number1, number2);*/
	A.LongSub(number1, number2);

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	/*string number1, num1bit;
	getline(cin, number1);
	char * n1 = new char[number1.length()+1];
	number1.copy(n1, number1.length()+1);
	for (int i = 0; i < number1.length() + 1; i++)
	{
		cout << n1[i] << " ";
	}
	for (int i = 0; i < number1.length() + 1; i++)
	{
		switch (n1[i])
		{
		case '0': num1bit += "0000";
			break;
		case '1': num1bit += "0001";
			break;
		case '2': num1bit += "0010";
			break;
		case '3': num1bit += "0011";
			break;
		case '4': num1bit += "0100";
			break;
		case '5': num1bit += "0101";
			break;
		case '6': num1bit += "0110";
			break;
		case '7': num1bit += "0111";
			break;
		case '8': num1bit += "1000";
			break;
		case '9': num1bit += "1001";
			break;
		case 'A': num1bit += "1010";
			break;
		case 'B': num1bit += "1011";
			break;
		case 'C': num1bit += "1100";
			break;
		case 'D': num1bit += "1101";
			break;
		case 'E': num1bit += "1111";
			break;
		}
	}

	cout << num1bit << endl;





	//ПРЕОБРАЗОВАНИЕ В МАССИВ ИНТА
	reverse(num1bit.begin(), num1bit.end());
	char * numb1 = new char[number1.length() + 1];
	num1bit.copy(numb1, num1bit.length() + 1);
	int* num1 = new int[(num1bit.length() + 1)];
	for (int i = 0; i < num1bit.length(); i++)
	{
		num1[i] = numb1[i] - '0';
	}
	cout << "Kakayato hren inta" << endl;
	for (int i = 0; i < num1bit.length(); i++)
	{
		cout << num1[i] << endl;
	

	//СЛОЖЕНИЕ
	int carry,temp = 0;
	for (int i = 0; i < num1bit.length(); i++)
	{
		temp = a[i] + b[i] + carry;
		c[i] = temp % 2;
		carry = temp / 2;
	}}*/

}

