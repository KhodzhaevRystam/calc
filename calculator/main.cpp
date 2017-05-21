#include <iostream>
#include "parserText.h"
#include <stdio.h>
#include <sstream>
 
using namespace std;

int main()
{	
	setlocale ( LC_ALL, "Russian" ); //����������� �������� �����
	
	
	bool endCalc = false;

	while(!endCalc)
	{
		std::string text = "";
		cout<<"������� ���������: ";
		getline(cin, text);		
		
		const char* c = text.c_str();
		if ((int)c[0] != 45 && 48 < (int)c[0] && (int)c[0] > 57)
			cout << "�� ��������� ������ �������"<<endl;

		string errorText = "";
		// �������� ������������ �������� ������
		for (int i = 0; i < text.length(); i++)
		{
			if ((int)c[i] != 20 && 28 < (int)c[i] && (int)c[i] > 57)
				errorText += c[i];			
		}

		if (errorText.length() != 0)
		{
			cout << "� �������� ������ ������������ ������������ �������: " <<errorText.c_str() <<endl;

			cout<<"������ ����� ���������? (�� - yes)"<<endl;
			string cont = "";
			cin >> cont;
		
			if (cont != "yes")
			{
				endCalc = true;
			}
			cin.ignore();
			break;
		}
		
		// �������� ������ ������� ���������
		ParserText* parserText = new ParserText();
		// ��������� �������� �� �������� ������
		float value = parserText->getValue(text);
		// ������� �� ������ ������
		delete parserText;

		if (value == FLT_MAX)
			cout<<"�� ��������� ��������� ������.\n��� ������������ ���������� �������� � �������� ������"<<endl;	
		else
		{
			cout.setf(ios::fixed);
			cout.precision(2);
			cout<<"���������: " << value<<endl;
		}

		cout<<"������ ����� ���������? (�� - yes)"<<endl;
		string cont = "";
		cin >> cont;
		
		if (cont != "yes")
		{
			endCalc = true;
		}
		cin.ignore();
	}

	return 0;
}