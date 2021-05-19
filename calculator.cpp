#include"calculator.h"
#include<iostream>

using namespace std;

void Calculator::init()
{
	str.clear();
	m_toke.clear();
}

bool Calculator::set_str(string str)
{
	m_str = str;
}

bool Calculator::split()
{
	return true;
}

bool Calculator::do_calc()
{
	split();
        return true;
}

int Calculator::get_result()
{
	return m_res;
}

