#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>

enum CALC_C_TYPE
{
	NUM = 0, //number
	SUM,
	SUB,
	MUL,
	DIV,
	BKL, //left brackets
	BKR,  //right brackets
	END
}

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

int main(int argc，char *argv[])
{
	int ret = 0;
	char str[101] = {0};
	int len = 0;
	struct cnode *p;
	if(argc > 2)
		printf("input error,please check your input.\n");
	else if(argc == 2) {
		return do_calc(argv[1]);
	}
	
	printf("welcome to use my calc,here is some tips\n");
	printf("1,please do not type more than 100 characters\n");
	printf("2,input number max 99999\n");
	printf("please input your calc character,end with enter:\n");
	
	while(1) {
		memset(str,0,101);
		fgets(str, 101, stdin);
		len = strlen(str);
		if(len == 101 && str[len-1] != '\n') {
			printf("input error,len more than 100,pleese re-enter\n");
			memset(str,0,101);
			continue;
		}
		if(len < 3) {
			printf("input too short,please re-enter\n");
			continue;
		}
		ret = do_calc(str);
		sleep(1);
	}
	
	return 0;
}

int do_calc(char* c_in)
{
	int i = 0; //current pos
	int pos = 0;//last pos
	char num[5] = {0}; //number char
	int count = 0; //number char count
	int type = 0;  //calc char type
	int len = strlen(c_in);
	int r_num = 0;
	int l_num = 0;
	int calc = 0;
	int res = 0;
	for(;i<len;i++) {
		type = get_char_type(c_in[i]);
		if(type < 0) {
			printf("Illegal character %c,please re-enter\n",c_in[i]);
			return -1;
		}
		else if(type == NUM) {
			num[count] = c_in[i];
			count++;
			if(count > 5) {
				printf("num too large,not support\n");
				return -1;
			}
		}
		else if(type == END) {
			if(calc == 0) {
				printf("there is calc operator,please re-enter\n");
				return -1;
			}
			if(count == 0) {
				printf("there is no right value,please re-enter\n");
				return -1;
			}
			r_num = atoi(num);
			res = get_result();
		}
		else {
			if(count == 0) {
				printf("there is no left value,please re-enter\n");
				return -1;
			}
			l_num = atoi(num);
			calc = type;
			count = 0;
		}
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
			*res = l_num \ r_num;
			break;
		default:
			printf("unkown calc op\n");
			return -1;
	}
	return 0;
	
}

