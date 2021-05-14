#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<iostream>
#include<string>
using namespace std;

enum CALC_C_TYPE
{
	NUM = 0, //number
	SUM,
	SUB,
	MUL,
	DIV,
	BKL, //left brackets
	BKR,  //right brackets
	TAB, //blank space or tab
	END
};

/*struct cnode
{
	int num;//number or number calc result
	int calc;//calc operator
	struct cnode *sub_l;//left value for calc operator
	struct cnode *sub_r;//right value for calc operator
}*/

int do_calc(char* c_in);
int get_char_type(char c);
int calc(int op,int l_num,int r_num,int* res);

int main(int argc,char *argv[])
{
	int ret = 0;
	string str;
	int len = 0;
	/*struct cnode *p;
	if(argc > 2)
		printf("input error,please check your input.\n");
	else if(argc == 2) {
		return do_calc(argv[1]);
	}*/
	
	printf("welcome to use my calc,here is some tips\n");
	printf("1,please do not type more than 100 characters\n");
	printf("2,if the number is too long,we cannot ensure it's result\n");
	printf("please input your calc character,end with enter:\n");
	
	while(1) {
		str.clear();
		getline(cin,str);
		len = str.size();
		if(len < 3) {
			printf("input too short,please re-enter:\n");
			continue;
		}
		ret = do_calc((char*)str.c_str());
		sleep(1);
	}
	
	return 0;
}

int do_calc(char* c_in)
{
	int i = 0; //current pos
	int pos = 0;//last pos
	string num; //number char
	int type = 0;  //calc char type
	int len = strlen(c_in);
	int r_num = 0;
	int l_num = 0;
	int op = 0;
	int res = 0;
	int ret = 0;
	for(;i<len;i++) {
		type = get_char_type(c_in[i]);
		if(type < 0) {
			printf("Illegal character \"%c\",please re-enter:\n",c_in[i]);
			return -1;
		}
		else if(type == NUM) {
			//num.append(c_in[i]);
			num = num + c_in[i];
		}
		else if(type == TAB) {
			continue;
		}
		else {
			if(num.size() == 0) {
				printf("there is no left value,please re-enter:\n");
				return -1;
			}
			l_num = atoi(num.c_str());
			num.clear();
			op = type;
		}
	}
	if(op == 0) {
		printf("there is no calc operator,please re-enter:\n");
		return -1;
	}
	if(num.size() == 0) {
		printf("there is no right value,please re-enter:\n");
		return -1;
	}
	r_num = atoi(num.c_str());
	ret = calc(op,l_num,r_num,&res);
	if(ret<0)
		printf("do calc failed please check your input\n");
	else {
		printf("calc result is %d\n",res);
		printf("another input again:\n");
	}
	
	return 0;
}

int get_char_type(char c)
{
	switch(c)
	{
		case '+':
			return SUM;
		case '-':
			return SUB;
		case '*':
			return MUL;
		case '/':
			return DIV;
		case '(':
			return BKL;
		case ')':
			return BKR;
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			return NUM;
		case ' ':
		case '\t':
			return TAB;
		case '\n':
			return END;
		default:
			return -1;
	}
	return -1;
}

int calc(int op,int l_num,int r_num,int* res)
{
	if(res == NULL)
	{
		printf("error\n");
		exit(0);
	}
	switch(op)
	{
		case SUM:
			*res = l_num + r_num;
			break;
		case SUB:
			*res = l_num - r_num;
			break;
		case MUL:
			*res = l_num * r_num;
			break;
		case DIV:
			if(r_num == 0) {
				printf("r_num cannot be 0\n");
				return -1;
			}
			*res = l_num / r_num;
			break;
		default:
			printf("unkown calc op\n");
			return -1;
	}
	return 0;
	
}

