#include <sstream>
#include <vector>
#include <string>

using namespace std;

class ParserText
{
public:
	ParserText();
	~ParserText();
	// ��������� �������� ��������� �� �������� ������
	float getValue(string text);

protected:	
	// ��������� �������� �� �������
	float getValueToLexem(string text);
};