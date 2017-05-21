#include <iostream>
#include "parserText.h"
#include <stdio.h>
#include <sstream>
 
using namespace std;

int main()
{	
	setlocale ( LC_ALL, "Russian" ); //определение русского языка
	
	
	bool endCalc = false;

	while(!endCalc)
	{
		std::string text = "";
		cout<<"Введите выражение: ";
		getline(cin, text);		
		
		const char* c = text.c_str();
		if ((int)c[0] != 45 && 48 < (int)c[0] && (int)c[0] > 57)
			cout << "Не корректно задана формула"<<endl;

		string errorText = "";
		// проверка корректности заданной строки
		for (int i = 0; i < text.length(); i++)
		{
			if ((int)c[i] != 20 && 28 < (int)c[i] && (int)c[i] > 57)
				errorText += c[i];			
		}

		if (errorText.length() != 0)
		{
			cout << "В заданной строке присутствуют недопустимые символы: " <<errorText.c_str() <<endl;

			cout<<"Ввести новое выражение? (да - yes)"<<endl;
			string cont = "";
			cin >> cont;
		
			if (cont != "yes")
			{
				endCalc = true;
			}
			cin.ignore();
			break;
		}
		
		// создание класса разбота выражения
		ParserText* parserText = new ParserText();
		// получение значения из входного текста
		float value = parserText->getValue(text);
		// удаляем из памяти объект
		delete parserText;

		if (value == FLT_MAX)
			cout<<"Не корректно введенные данные.\nНет соответствия количества открытых и закрытых скобок"<<endl;	
		else
		{
			cout.setf(ios::fixed);
			cout.precision(2);
			cout<<"Результат: " << value<<endl;
		}

		cout<<"Ввести новое выражение? (да - yes)"<<endl;
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