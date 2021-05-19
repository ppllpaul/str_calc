#include<string>
#include<vector>
 
using namespace std;

enum TOKEN_TYPE
{
	NUM = 0, //number
	OP  = 1, //calc op
};

struct token
{
	int type;
	int value;
}

class Calculator
{
public:
	void init();
	bool set_str(string str);
	int  get_result();
	bool do_calc();
private:
	bool split();
	string m_str;
	vector<token> m_toke;
	int m_res;
};
