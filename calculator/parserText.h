#include <sstream>
#include <vector>
#include <string>

using namespace std;

class ParserText
{
public:
	ParserText();
	~ParserText();
	// получение значения выражения из входящей строки
	float getValue(string text);

protected:	
	// получение значения из лексемы
	float getValueToLexem(string text);
};