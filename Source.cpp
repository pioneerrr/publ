#include <iostream>
#include <fstream>
#include <string.h>
#include <cstring>
#include <fstream>
#include <math.h>
using namespace std;

int main()
{
	ifstream fin("fin1.txt", std::ios::in);
	ofstream fout("fout1.txt", std::ios::out);
	char Str1Dec[25];
	int Num1Cel=0;
	double Num1Drob= 0;
	int s1=0;
	int stepen1=0;
	int stepen3=0;
	int Str1Deci[25];
	int InvStr1Sixt[25];
	int Str1Sixt[25];
	char Str2Dec[25];
	int Num2Cel=0;
	double Num2Drob= 0;
	int s2=0;
	int stepen2=0;
	int stepen4=0;
	int Str2Deci[25];
	int InvStr2Sixt[25];
	int Str2Sixt[25];
	int j1 = 0;
	int i1 = 0;
	int i2 = 0;
	int Sum[25];
	int SumBuf = 0;
	bool flag1 = false;
	bool flag2 = false;

	int rem1;
	int rem2;
	int rem3;
	int rem4;
	int rem5;
	int rem6;
	int lishn = 0;

	for (int i = 0; i < 25; i++)
	{
		Sum[i] = 0;
	}
	for (int i = 0; i < 25; i++)
	{
		Str1Sixt[i] = 0;
	}
	for (int i = 0; i < 25; i++)
	{
		Str2Sixt[i] = 0;
	}
	for (int i = 0; i < 25; i++)
	{
		Str2Deci[i] = 0;
	}
	for (int i = 0; i < 25; i++)
	{
		Str1Deci[i] = 0;
	}


	if (!fin.is_open())
		cout << "file can't be opened\n";
	while (1)
	{
		char ch = fin.get();
		if (fin.eof())
			break;
		Str1Dec[j1] = ch;
		j1++;
		s1 = j1 ;
		if (ch == ' ')
		{
			j1 = 0;
			while (1)
			{
				
				char ch = fin.get();
				if (fin.eof())
					break;
				Str2Dec[j1] = ch;
				j1++;
				s2 = j1;
			}
		}
	}
	s1--;

    for (int i = 0; i < s1; i++)
	{
		switch(Str1Dec[i])
		{ 
			case '-': Str1Deci[i] = 11;
				flag1 = true;
				break;
			case '0': Str1Deci[i] = 0;
				break;
			case '1': Str1Deci[i] = 1;
				break;
			case '2': Str1Deci[i] = 2;
				break;
			case '3': Str1Deci[i] = 3;
				break;
			case '4': Str1Deci[i] = 4;
				break;
			case '5': Str1Deci[i] = 5;
				break;
			case '6': Str1Deci[i] = 6;
				break;
			case '7': Str1Deci[i] = 7;
				break;
			case '8': Str1Deci[i] = 8;
				break;
			case '9': Str1Deci[i] = 9;
				break;
			case '.': Str1Deci[i] = 10;
				stepen1 = i ;
				break;
		}
		stepen3 = i;
		
	}
	if (flag1 == true)
	{
		for (int i = 0; i < s1; i++)
		{
			Str1Deci[i] = Str1Deci[i + 1];
		}
	}
	stepen3 = stepen3 - stepen1;
	rem1 = stepen3;
	
	if (stepen1 == 0) stepen1 = s1;
	int buf1 = s1;
	int stepen = s1;
	if (flag1 == true) stepen1--;
	for (int i = 0; i < buf1; i++)
	{
		if (Str1Deci[i] == 10)
		{
			for (int i1 = i + 1; i1 < buf1; i1++)
			{
				Num1Drob = Num1Drob + Str1Deci[i1] * pow(10, (stepen3 - 1));
				stepen3--;
			}
			break;
		}
	
		Num1Cel = Num1Cel + Str1Deci[i] * pow(10 ,(stepen1-1));
		stepen1--;
	}


	for (int i = 0; i < s2; i++)
	{
		switch (Str2Dec[i])
		{
		case '-': Str2Deci[i] = 11;
			flag2 = true;
			break;
		case '0': Str2Deci[i] = 0;
			break;
		case '1': Str2Deci[i] = 1;
			break;
		case '2': Str2Deci[i] = 2;
			break;
		case '3': Str2Deci[i] = 3;
			break;
		case '4': Str2Deci[i] = 4;
			break;
		case '5': Str2Deci[i] = 5;
			break;
		case '6': Str2Deci[i] = 6;
			break;
		case '7': Str2Deci[i] = 7;
			break;
		case '8': Str2Deci[i] = 8;
			break;
		case '9': Str2Deci[i] = 9;
			break;
		case '.': Str2Deci[i] = 10;
			stepen2 = i;
			break;
		}
		stepen4 = i;
	}
	if (flag2 == true)
	{
		for (int i = 0; i < s2; i++)
		{
			Str2Deci[i] = Str2Deci[i + 1];
		}
	}
	stepen4 = stepen4 - stepen2;
	rem2 = stepen4;
	if (stepen2 == 0) stepen2 = s2;
	buf1 = s2;
	if (flag2 == true) stepen2--;
	for (int i = 0; i < buf1; i++)
	{
		if (Str2Deci[i] == 10)
		{
			for (int i1 = i + 1; i1 < buf1; i1++)
			{
				Num2Drob = Num2Drob + Str2Deci[i1] * pow(10, (stepen4 - 1));
				stepen4--;
			}
			break;
		}

		Num2Cel = Num2Cel + Str2Deci[i] * pow(10, (stepen2 - 1));
		stepen2--;
	}
	//ниже перевод из 10 в 16
	int j = 0;;
	while (Num1Cel >= 16)
	{
	 InvStr1Sixt[j]=Num1Cel-Num1Cel/16*16;
	 Num1Cel = Num1Cel / 16;
	 j++;
	}
	InvStr1Sixt[j] = Num1Cel;
	while (j > -1)
	{
		Str1Sixt[i1] = InvStr1Sixt[j];
		j--;
		i1++;
	}

	j = 0;;
	
	while (Num2Cel >= 16)
	{
		InvStr2Sixt[j] = Num2Cel - Num2Cel / 16 * 16;
		Num2Cel = Num2Cel / 16;
		j++;
	}
	InvStr2Sixt[j] = Num2Cel;
	while (j > -1)
	{
		Str2Sixt[i2] = InvStr2Sixt[j];
		j--;
		i2++;
	}
	//целые части чисел переведены в 16 сс
	rem5 = i1;//количество элементов до запятой в первом числе
	rem6 = i2;//количество элементов до запятой во втором числе
	double buf2=0;
	if (Num1Drob != 0)
	{
		Num1Drob = Num1Drob * pow(10, -rem1);
		while (Num1Drob != 0)
		{
			Num1Drob = modf(Num1Drob * 16,&buf2);
			Str1Sixt[i1] = buf2;
			i1++;
			if (i1 > 5) break;
		}
	}
	if (Num2Drob != 0)
	{
		Num2Drob = Num2Drob * pow(10, -rem2);
		while (Num2Drob != 0)
		{
			Num2Drob = modf(Num2Drob * 16, &buf2);
			Str2Sixt[i2] = buf2;
			i2++;
			if (i2 > 5) break;
		}
	}
	rem3 = i1;//количество элементов в первом числе
	rem4 = i2;//количество элементов во втором числе
	//числа переведены в 16 сс
	
	cout << "first number in 16 ";
	if (flag1 == true) cout << '-';
	for (int i = 0; i < i1; i++)
	{
		if ((i == rem5) && (i != 0)) {
			cout << '.';

		}
		switch (Str1Sixt[i])
		{
		case 0: cout << '0';
			fout << '0';
			break;
		case 1: cout << '1';
			fout << '1';
			break;
		case 2: cout << '2';
			fout << '2';
			break;
		case 3: cout << '3';
			fout << '3';
			break;
		case 4: cout << '4';
			fout << '4';
			break;
		case 5: cout << '5';
			fout << '5';
			break;
		case 6: cout << '6';
			fout << '6';
			break;
		case 7: cout << '7';
			fout << '7';
			break;
		case 8: cout << '8';
			fout << '8';
			break;
		case 9: cout << '9';
			fout << '9';
			break;
		case 10: cout << 'A';
			fout << 'A';
			break;
		case 11: cout << 'B';
			fout << 'B';
			break;
		case 12: cout << 'C';
			fout << 'C';
			break;
		case 13: cout << 'D';
			fout << 'D';
			break;
		case 14: cout << 'E';
			fout << 'E';

			break;
		case 15: cout << 'F';
			fout << 'F';

			break;
		}
	}
	cout << endl;
	cout << "second number 16 ";
	if (flag2 == true) cout << '-';
	for (int i = 0; i < i2; i++)
	{
		if ((i == rem6) && (i != 0)) {
			cout << '.';

		}
		switch (Str2Sixt[i])
		{
		case 0: cout << '0';
			fout << '0';
			break;
		case 1: cout << '1';
			fout << '1';
			break;
		case 2: cout << '2';
			fout << '2';
			break;
		case 3: cout << '3';
			fout << '3';
			break;
		case 4: cout << '4';
			fout << '4';
			break;
		case 5: cout << '5';
			fout << '5';
			break;
		case 6: cout << '6';
			fout << '6';
			break;
		case 7: cout << '7';
			fout << '7';
			break;
		case 8: cout << '8';
			fout << '8';
			break;
		case 9: cout << '9';
			fout << '9';
			break;
		case 10: cout << 'A';
			fout << 'A';
			break;
		case 11: cout << 'B';
			fout << 'B';
			break;
		case 12: cout << 'C';
			fout << 'C';
			break;
		case 13: cout << 'D';
			fout << 'D';
			break;
		case 14: cout << 'E';
			fout << 'E';

			break;
		case 15: cout << 'F';
			fout << 'F';

			break;
		}
	}
	cout << endl;

	//сложение двух положительных или двух отрицательных
	if (((flag1 == false) && (flag2 == false))||((flag1 == true) && (flag2 == true)))
	{
		if (rem5 > rem6)
		{
			for (int i = 0; i < rem5 - rem6; i++)
			{
				i1 = s2 + rem5 - rem6;
				while (i1 >-1)
				{
					if (i1 - 1 < 0) Str2Sixt[i1] = 0;
					else
						Str2Sixt[i1] = Str2Sixt[i1 - 1];
					i1--;
				}
			}

			for (int i = rem3; i > -1; i--)
			{
				Sum[i] = Str1Sixt[i] + Str2Sixt[i]+Sum[i];
				if (Sum[i] > 15)
				{
					
					Sum[i-1] = Sum[i-1]+1 ;
					Sum[i] = Sum[i]-16;
					if (i - 1 < 0)
					{
						lishn += 1;
						
					}
				}
			}

			if (flag1 == true) cout << '-';
			cout << lishn;
			for (int i = 0; i < rem3; i++)
			{  
				if ((i == rem3)&&(i!=0)) {
					cout << '.';
					
				}
				switch (Sum[i])
				{
				case 0: cout << '0';
					fout << '0';
					break;
				case 1: cout << '1';
					fout << '1';
					break;
				case 2: cout << '2';
					fout << '2';
					break;
				case 3: cout << '3';
					fout << '3';
					break;
				case 4: cout << '4';
					fout << '4';
					break;
				case 5: cout << '5';
					fout << '5';
					break;
				case 6: cout << '6';
					fout << '6';
					break;
				case 7: cout << '7';
					fout << '7';
					break;
				case 8: cout << '8';
					fout << '8';
					break;
				case 9: cout << '9';
					fout << '9';
					break;
				case 10: cout << 'A';
					fout << 'A';
					break;
				case 11: cout << 'B';
					fout << 'B';
					break;
				case 12: cout << 'C';
					fout << 'C';
					break;
				case 13: cout << 'D';
					fout << 'D';
					break;
				case 14: cout << 'E';
					fout << 'E';

					break;
				case 15: cout << 'F';
					fout << 'F';

					break;
				}
				//cout << Sum[i];
			}
		}

		if (rem6 > rem5)
		{
			for (int i = 0; i < rem6 - rem5; i++)
			{
				i1 = s2 + rem6 - rem5;
				while (i1 > -1)
				{
					if (i1 - 1 < 0) Str1Sixt[i1] = 0;
					else
						Str1Sixt[i1] = Str1Sixt[i1 - 1];
					i1--;
				}
			}
			for (int i = rem4; i > -1; i--)
			{
				Sum[i] = Str1Sixt[i] + Str2Sixt[i] + Sum[i];
				if (Sum[i] > 16)
				{
					Sum[i - 1] = Sum[i - 1] + 1;
					Sum[i] = Sum[i] - 16;
					if (i - 1 < 0)
					{
						lishn += 1;
						
					}
				}
			}
			if (flag1 == true) cout << '-';
			cout << lishn;
			for (int i = 0; i < rem4; i++)
			{
				if ((i == rem4 )&&(i!=0)) {
					cout << '.';

				}
				switch (Sum[i])
				{
				case 0: cout << '0';
					fout << '0';

					break;
				case 1: cout << '1';
					fout << '1';
					break;
				case 2: cout << '2';
					fout << '2';
					break;
				case 3: cout << '3';
					fout << '3';
					break;
				case 4: cout << '4';
					fout << '4';
					break;
				case 5: cout << '5';
					fout << '5';
					break;
				case 6: cout << '6';
					fout << '6';
					break;
				case 7: cout << '7';
					fout << '7';
					break;
				case 8: cout << '8';
					fout << '8';
					break;
				case 9: cout << '9';
					fout << '9';
					break;
				case 10: cout << 'A';
					fout << 'A';
					break;
				case 11: cout << 'B';
					fout << 'B';
					break;
				case 12: cout << 'C';
					fout << 'C';
					break;
				case 13: cout << 'D';
					fout << 'D';
					break;
				case 14: cout << 'E';
					fout << 'E';
					break;
				case 15: cout << 'F';
					fout << 'F';
					break;
				}
				//cout << Sum[i];
			}
		}


		int max = 0;
		if (rem3 > rem4) max = rem3;
		else max = rem4;
		if (rem6 == rem5)
		{
			for (int i = rem4; i > -1; i--)
			{
				Sum[i] = Str1Sixt[i] + Str2Sixt[i] + Sum[i];
				if (Sum[i] > 15)
				{
					Sum[i - 1] = Sum[i - 1] + 1;
					Sum[i] = Sum[i] - 16;
					if (i - 1 < 0)
					{
						lishn += 1;
						
					}
				}
			}
			if (flag1 == true) cout << '-';
			cout << lishn;
			for (int i = 0; i < max; i++)
			{
				if ((i == rem6 )&&(i!=0)) {
					cout << '.';

				}
				switch (Sum[i])
				{
				case 0: cout << '0';
					fout << '0';

					break;
				case 1: cout << '1';
					fout << '1';
					break;
				case 2: cout << '2';
					fout << '2';
					break;
				case 3: cout << '3';
					fout << '3';
					break;
				case 4: cout << '4';
					fout << '4';
					break;
				case 5: cout << '5';
					fout << '5';
					break;
				case 6: cout << '6';
					fout << '6';
					break;
				case 7: cout << '7';
					fout << '7';
					break;
				case 8: cout << '8';
					fout << '8';
					break;
				case 9: cout << '9';
					fout << '9';
					break;
				case 10: cout << 'A';
					fout << 'A';
					break;
				case 11: cout << 'B';
					fout << 'B';
					break;
				case 12: cout << 'C';
					fout << 'C';
					break;
				case 13: cout << 'D';
					fout << 'D';
					break;
				case 14: cout << 'E';
					fout << 'E';
					break;
				case 15: cout << 'F';
					fout << 'F';
					break;
				}
				//cout << Sum[i];
			}

		}


    }

	//вычитание
	bool max1=false;
	bool max2=false;

	if (((flag1 == false) && (flag2 == true)) || ((flag1 == true) && (flag2 == false)))
	{
		if (Num1Cel > Num2Cel)
		max1 = true;
		if (Num2Cel > Num1Cel)
	    max2 = true;
		if (Num2Cel == Num1Cel)
		{
			if (Num1Drob > Num2Drob)
				max1 = true;
			if (Num2Drob > Num1Drob)
				max2 = true;
		}
		if (max1 == true)
		{
			if (flag1 == true) {cout << '-';
			 fout << '-';
			}


			if (rem5 > rem6)
			{
				for (int i = 0; i < rem5 - rem6; i++)
				{
					i1 = s2 + rem5 - rem6;
					while (i1 >-1)
					{
						if (i1 - 1 < 0) Str2Sixt[i1] = 0;
						else
							Str2Sixt[i1] = Str2Sixt[i1 - 1];
						i1--;
					}
				}

				for (int i = rem3; i > -1; i--)
				{
					Sum[i] = Str1Sixt[i] - Str2Sixt[i] + Sum[i];
					if (Sum[i] <0)
					{
						Sum[i - 1] = Sum[i - 1] - 1;
						Sum[i] =  16+Sum[i];
					}
				}

				
				for (int i = 0; i < rem3; i++)
				{
					if ((i == rem3) && (i != 0)) {
						cout << '.';
						fout << '.';

					}
					switch (Sum[i])
					{
					case 0: cout << '0';
						fout << '0';

						break;
					case 1: cout << '1';
						fout << '1';
						break;
					case 2: cout << '2';
						fout << '2';
						break;
					case 3: cout << '3';
						fout << '3';
						break;
					case 4: cout << '4';
						fout << '4';
						break;
					case 5: cout << '5';
						fout << '5';
						break;
					case 6: cout << '6';
						fout << '6';
						break;
					case 7: cout << '7';
						fout << '7';
						break;
					case 8: cout << '8';
						fout << '8';
						break;
					case 9: cout << '9';
						fout << '9';
						break;
					case 10: cout << 'A';
						fout << 'A';
						break;
					case 11: cout << 'B';
						fout << 'B';
						break;
					case 12: cout << 'C';
						fout << 'C';
						break;
					case 13: cout << 'D';
						fout << 'D';
						break;
					case 14: cout << 'E';
						fout << 'E';
						break;
					case 15: cout << 'F';
						fout << 'F';
						break;
					}
					//cout << Sum[i];
				}
			}

			if (rem6 > rem5)
			{
				for (int i = 0; i < rem6 - rem5; i++)
				{
					i1 = s2 + rem6 - rem5;
					while (i1 > -1)
					{
						if (i1 - 1 < 0) Str1Sixt[i1] = 0;
						else
							Str1Sixt[i1] = Str1Sixt[i1 - 1];
						i1--;
					}
				}
				for (int i = rem4; i > -1; i--)
				{
					Sum[i] = Str1Sixt[i] - Str2Sixt[i] + Sum[i];
					if (Sum[i] <0)
					{
						Sum[i - 1] = Sum[i - 1] -1;
						Sum[i] = Sum[i] + 16;
					}
				}
				
				for (int i = 0; i < rem4; i++)
				{
					if ((i == rem4) && (i != 0)) {
						cout << '.';
						fout << '.';

					}
					switch (Sum[i])
					{
					case 0: cout << '0';
						fout << '0';

						break;
					case 1: cout << '1';
						fout << '1';
						break;
					case 2: cout << '2';
						fout << '2';
						break;
					case 3: cout << '3';
						fout << '3';
						break;
					case 4: cout << '4';
						fout << '4';
						break;
					case 5: cout << '5';
						fout << '5';
						break;
					case 6: cout << '6';
						fout << '6';
						break;
					case 7: cout << '7';
						fout << '7';
						break;
					case 8: cout << '8';
						fout << '8';
						break;
					case 9: cout << '9';
						fout << '9';
						break;
					case 10: cout << 'A';
						fout << 'A';
						break;
					case 11: cout << 'B';
						fout << 'B';
						break;
					case 12: cout << 'C';
						fout << 'C';
						break;
					case 13: cout << 'D';
						fout << 'D';
						break;
					case 14: cout << 'E';
						fout << 'E';
						break;
					case 15: cout << 'F';
						fout << 'F';
						break;
					}
					//cout << Sum[i];
				}
			}


			int max = 0;
			if (rem3 > rem4) max = rem3;
			else max = rem4;
			if (rem6 == rem5)
			{
				for (int i = rem4; i > -1; i--)
				{
					Sum[i] = Str1Sixt[i] - Str2Sixt[i] + Sum[i];
					if (Sum[i] <0)
					{
						Sum[i - 1] = Sum[i - 1] -1 ;
						Sum[i] = Sum[i] + 16;
					}
				}
				
				for (int i = 0; i < max; i++)
				{
					if ((i == rem6) && (i != 0)) {
						cout << '.';
						fout << '.';

					}
					switch (Sum[i])
					{
					case 0: cout << '0';
						fout << '0';

						break;
					case 1: cout << '1';
						fout << '1';
						break;
					case 2: cout << '2';
						fout << '2';
						break;
					case 3: cout << '3';
						fout << '3';
						break;
					case 4: cout << '4';
						fout << '4';
						break;
					case 5: cout << '5';
						fout << '5';
						break;
					case 6: cout << '6';
						fout << '6';
						break;
					case 7: cout << '7';
						fout << '7';
						break;
					case 8: cout << '8';
						fout << '8';
						break;
					case 9: cout << '9';
						fout << '9';
						break;
					case 10: cout << 'A';
						fout << 'A';
						break;
					case 11: cout << 'B';
						fout << 'B';
						break;
					case 12: cout << 'C';
						fout << 'C';
						break;
					case 13: cout << 'D';
						fout << 'D';
						break;
					case 14: cout << 'E';
						fout << 'E';
						break;
					case 15: cout << 'F';
						fout << 'F';
						break;
					}
					//cout << Sum[i];
				}

			}

            
		}
		if (max2 == true)
		{
            
			if (flag2 == true) {
				cout << '-';
				fout << '-';
			}



			if (rem5 > rem6)
			{
				for (int i = 0; i < rem5 - rem6; i++)
				{
					i1 = s2 + rem5 - rem6;
					while (i1 >-1)
					{
						if (i1 - 1 < 0) Str2Sixt[i1] = 0;
						else
							Str2Sixt[i1] = Str2Sixt[i1 - 1];
						i1--;
					}
				}

				for (int i = rem3; i > -1; i--)
				{
					Sum[i] = -Str1Sixt[i] + Str2Sixt[i] + Sum[i];
					if (Sum[i] <0)
					{
						Sum[i - 1] = Sum[i - 1] - 1;
						Sum[i] = 16 + Sum[i];
					}
				}


				for (int i = 0; i < rem3; i++)
				{
					if ((i == rem3) && (i != 0)) {
						cout << '.';
						fout << '.';
					}
					switch (Sum[i])
					{
					case 0: cout << '0';
						fout << '0';

						break;
					case 1: cout << '1';
						fout << '1';
						break;
					case 2: cout << '2';
						fout << '2';
						break;
					case 3: cout << '3';
						fout << '3';
						break;
					case 4: cout << '4';
						fout << '4';
						break;
					case 5: cout << '5';
						fout << '5';
						break;
					case 6: cout << '6';
						fout << '6';
						break;
					case 7: cout << '7';
						fout << '7';
						break;
					case 8: cout << '8';
						fout << '8';
						break;
					case 9: cout << '9';
						fout << '9';
						break;
					case 10: cout << 'A';
						fout << 'A';
						break;
					case 11: cout << 'B';
						fout << 'B';
						break;
					case 12: cout << 'C';
						fout << 'C';
						break;
					case 13: cout << 'D';
						fout << 'D';
						break;
					case 14: cout << 'E';
						fout << 'E';
						break;
					case 15: cout << 'F';
						fout << 'F';
						break;
					}
					//cout << Sum[i];
				}
			}

			if (rem6 > rem5)
			{
				for (int i = 0; i < rem6 - rem5; i++)
				{
					i1 = s2 + rem6 - rem5;
					while (i1 > -1)
					{
						if (i1 - 1 < 0) Str1Sixt[i1] = 0;
						else
							Str1Sixt[i1] = Str1Sixt[i1 - 1];
						i1--;
					}
				}
				for (int i = rem4; i > -1; i--)
				{
					Sum[i] = -Str1Sixt[i] + Str2Sixt[i] + Sum[i];
					if (Sum[i] <0)
					{
						Sum[i - 1] = Sum[i - 1] - 1;
						Sum[i] = Sum[i] + 16;
					}
				}

				for (int i = 0; i < rem4; i++)
				{
					if ((i == rem4) && (i != 0)) {
						cout << '.';
						fout << '.';
					}
					switch (Sum[i])
					{
					case 0: cout << '0';
						fout << '0';

						break;
					case 1: cout << '1';
						fout << '1';
						break;
					case 2: cout << '2';
						fout << '2';
						break;
					case 3: cout << '3';
						fout << '3';
						break;
					case 4: cout << '4';
						fout << '4';
						break;
					case 5: cout << '5';
						fout << '5';
						break;
					case 6: cout << '6';
						fout << '6';
						break;
					case 7: cout << '7';
						fout << '7';
						break;
					case 8: cout << '8';
						fout << '8';
						break;
					case 9: cout << '9';
						fout << '9';
						break;
					case 10: cout << 'A';
						fout << 'A';
						break;
					case 11: cout << 'B';
						fout << 'B';
						break;
					case 12: cout << 'C';
						fout << 'C';
						break;
					case 13: cout << 'D';
						fout << 'D';
						break;
					case 14: cout << 'E';
						fout << 'E';
						break;
					case 15: cout << 'F';
						fout << 'F';
						break;
					}
					//cout << Sum[i];
				}
			}


			int max = 0;
			if (rem3 > rem4) max = rem3;
			else max = rem4;
			if (rem6 == rem5)
			{
				for (int i = rem4; i > -1; i--)
				{
					Sum[i] = -Str1Sixt[i] + Str2Sixt[i] + Sum[i];
					if (Sum[i] <0)
					{
						Sum[i - 1] = Sum[i - 1] - 1;
						Sum[i] = Sum[i] + 16;
					}
				}

				for (int i = 0; i < max; i++)
				{
					if ((i == rem5) && (i != 0)) {
						cout << '.';
						fout << '.';

					}
					switch (Sum[i])
					{
					case 0: cout << '0';
						fout << '0';

						break;
					case 1: cout << '1';
						fout << '1';
						break;
					case 2: cout << '2';
						fout << '2';
						break;
					case 3: cout << '3';
						fout << '3';
						break;
					case 4: cout << '4';
						fout << '4';
						break;
					case 5: cout << '5';
						fout << '5';
						break;
					case 6: cout << '6';
						fout << '6';
						break;
					case 7: cout << '7';
						fout << '7';
						break;
					case 8: cout << '8';
						fout << '8';
						break;
					case 9: cout << '9';
						fout << '9';
						break;
					case 10: cout << 'A';
						fout << 'A';
						break;
					case 11: cout << 'B';
						fout << 'B';
						break;
					case 12: cout << 'C';
						fout << 'C';
						break;
					case 13: cout << 'D';
						fout << 'D';
						break;
					case 14: cout << 'E';
						fout << 'E';
						break;
					case 15: cout << 'F';
						fout << 'F';
						break;
					}
					//cout << Sum[i];
				}

			}
		}
	}
	cout << endl;
	system("pause");
}