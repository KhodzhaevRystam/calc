#include "parserText.h"
#include <math.h>
#include <float.h>; 

ParserText::ParserText()
{
}

ParserText::~ParserText()
{
}

// получение значения выражения из входящей строки
float ParserText::getValue(string text)
{
	float value = FLT_MAX;
	std::vector<string> lexems;

	string curText = text;
	// нахождение позиций скобок
	int posBegin = curText.find("(");
	int posEnd = curText.find(")");

	if (posBegin == -1 && posEnd == -1)
		return getValueToLexem(text);	
	else
	{
		string temp = "";

		while(posBegin != -1 && posEnd != -1)
		{
			int l = curText.length();
			string _text = curText.substr(posBegin+1, posEnd - (posBegin + 1));

			// определение наличия открывающихся скобок внутри полученной строки
			int posOpenBracket = _text.find("(");
			while (posOpenBracket != -1)
			{
				posBegin += posOpenBracket;
				string p = curText.substr(0, posBegin+1);
				_text = _text.substr(posOpenBracket+1, _text.length() - posOpenBracket+1);
				posOpenBracket = _text.find("(");	
				if(posOpenBracket == -1)
				{
					posBegin += 1;
				}
			}
			// полчение значения из лексемы
			float curValue = getValueToLexem(_text);
			std::stringstream ss;
			ss << curValue;

			temp = curText.substr(0, posBegin) + ss.str() + curText.substr(posEnd+1, curText.length());

			posBegin = temp.find("(");
			posEnd = temp.find(")");

			curText = temp;
		}
		value = getValueToLexem(temp);
	}	
	return value;
}

// получение значения из лексемы
float ParserText::getValueToLexem(string text)
{
	// инициализация переменной
	float value = FLT_MAX;
	std::vector<string> lexems;

	string curText = text;
	
	// разбор на элементы
	while(curText.length() != 0)
	{
		int posSpace = curText.find(" ");
		string lexem = "";
		if(posSpace != 0)
		{
			lexem = curText.substr(0, posSpace);

			// проверка на запятую
			int pos = lexem.find(".");
			// если есть именно "." а не ","
			if (pos != -1)
			{
				string temp = curText.substr(0, pos) + "," +curText.substr(pos+1,2);
				lexem = temp;
			}
			// проверка на знаки арифметического действия			
			if (lexem.length() >1)
			{
				char symbol = lexem.back();
				if ((int)symbol == 42 || (int)symbol == 43 || (int)symbol == 45 || (int)symbol == 47)
				{
					lexem = lexem.substr(0, lexem.length()-1);
					posSpace -= 1;
				}
			}
			lexems.push_back(lexem);

			if (posSpace == -1)
				break;

			curText = curText.substr(posSpace, curText.length() - posSpace);

			string temp = curText.substr(0, 1);
			if (temp == "+" || temp == "-" || temp == "/" || temp == "*")
			{
				curText = temp + " " + curText.substr(1, curText.length()); 
			}
		}
		else
		{
			curText = curText.substr(1, curText.length() - 1);

			string temp = curText.substr(0, 1);
			if (temp == "+" || temp == "/" || temp == "*")
			{
				curText = temp + " " + curText.substr(1, curText.length()); 
			}
		}		
	}

	// нахождение значения
	for (int i = 1; i < lexems.size(); i+=2)
	{
		if (i == 1)
		{
			if (lexems[i] == "+")
			{
				value = atof(lexems[i-1].c_str()) + atof(lexems[i+1].c_str());
			}
			else if (lexems[i] == "-")
			{
				value = atof(lexems[i-1].c_str()) - atof(lexems[i+1].c_str());
			}
			else if (lexems[i] == "/")
			{
				value = atof(lexems[i-1].c_str()) / atof(lexems[i+1].c_str());
			}
			else if (lexems[i] == "*")
			{
				value = atof(lexems[i-1].c_str()) * atof(lexems[i+1].c_str());
			}
		}
		else
		{
			if (lexems[i] == "+")
			{
				value += atof(lexems[i+1].c_str());
			}
			else if (lexems[i] == "-")
			{
				value -= atof(lexems[i+1].c_str());
			}
			else if (lexems[i] == "/")
			{
				value /= atof(lexems[i+1].c_str());
			}
			else if (lexems[i] == "*")
			{
				value *= atof(lexems[i+1].c_str());
			}
		}
	}
	
	return value;
}