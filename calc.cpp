#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<iostream>
#include<calculator.h>
using namespace std;

int main(int argc,char *argv[])
{
	int ret = 0;
	string str;
	int len = 0;
	
	printf("welcome to use my calc,here is some tips\n");
	printf("1,please do not type more than 100 characters\n");
	printf("2,if the number is too long,we cannot ensure it's result\n");
	printf("please input your calc character,end with enter:\n");
	Calculator calc;
	
	while(1) {
		str.clear();
		getline(cin,str);
		len = str.size();
		if(len < 3) {
			printf("input too short,please re-enter:\n");
			continue;
		}
		calc.init();
		calc.set_str(str);
		calc.do_calc;
		res = calc.get_result();
		printf("calc result is %d",res);
		sleep(1);
	}
	
	return 0;
}

