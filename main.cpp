#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <time.h>
#include <cmath>
#include <fstream>

int imax;  //最大数
int numofcalculate; //算式数量
int brackets; //是否有括号
int decimal;  //是否有小数
char op[4]={'+','-','*','/'};		  //运算符
int ope;      //用户输入的运算符
int outputform;//输出形式
void  integer_Cal();//生成整数四则运算
void decimal_Cal();//生成小数四则运算
using namespace std;
ofstream outfile;//数据写入文件

int main()
{
        cout<<"---小学生四则运算练习系统---"<<endl;
	cout<<"********************** "<<endl;
	cout<<" ①:请输入算式数量: "<<endl;
	cin>>numofcalculate;
	cout<<" ②: 请输入最大数: "<<endl;
	cin>>imax;
	cout<<" ③:请输入运算符: "<<endl;
	cout<<" 1代表+ 2代表- 3代表* 4代表/ 其他代表随意:"<<endl;
	cin>>ope;
	cout<<" ④:请选择数字类型: "<<endl;
	cout<<" 1代表整数 2代表小数"<<endl;
	cin>>decimal;
	cout<<" ⑤:请选择是否需要括号 "<<endl;
	cout<<" 1代表不需要括号 2代表需要括号"<<endl;
	cin>>brackets;
	cout<<" ⑥:请选择输出形式 "<<endl;
	cout<<" 1代表输出到文件 2代表打印机或打印到屏幕"<<endl;
	cin>>outputform;
	if(outputform==1)
        {
                outfile.open("myfile.txt");//数据写入文件
        }
	if(decimal==1)
	{
		srand(time(NULL));//设置一个随机种子，每次运行都能保证随机种子不同
		for(int i=0;i<numofcalculate;i++)
		{
			integer_Cal();
		}
	}
	else
	{
		srand(time(NULL));
		for(int i=0;i<numofcalculate;i++)
		{
			decimal_Cal();
		}
	}
	outfile.close();
	cout<<"********************* "<<endl;
	cout<<"---感谢使用此系统，祝您学习进步---"<<endl;
	return 0;
}
void integer_Cal()//生成整数四则运算
{
	int a,b,c,d;
	a=(rand()%imax)+1;//得到一个1到imax的随机数a
	b=(rand()%imax)+1;//得到一个1到imax的随机数b
	c=(rand()%imax)+1;//得到一个1到imax的随机数c
	int op1,op2,op3;
	op1=rand()%4;//随机得到"+" "-" "*" "/"中的一个
	op2=rand()%4;
	if(brackets==1)//不需要括号
	{
		if(ope==1)//执行"+"运算
		{
		    //f=a+b+c;
			cout<<a<<"+"<<b<<"+"<<c<<"="<<endl;
			outfile<<a<<"+"<<b<<"+"<<c<<"="<<endl;
		}
		else if(ope==2)//执行"-"运算
		{
			cout<<a<<"-"<<b<<"-"<<c<<"="<<endl;
			outfile<<a<<"-"<<b<<"-"<<c<<"="<<endl;
		}
		else if(ope==3)//执行"*"运算
		{
			cout<<a<<"*"<<b<<"*"<<c<<"="<<endl;
			outfile<<a<<"*"<<b<<"*"<<c<<"="<<endl;
		}
		else if(ope==4)//执行"/"运算
		{
			cout<<a<<"/"<<b<<"/"<<c<<"="<<endl;
			outfile<<a<<"/"<<b<<"/"<<c<<"="<<endl;
		}
		else//执行混合运算
		{
			cout<<a<<op[op1]<<b<<op[op2]<<c<<"="<<endl;//随机生成运算符的四则运算
			outfile<<a<<op[op1]<<b<<op[op2]<<c<<"="<<endl;
		}
	}
	else
	{
		int k;
		k=rand()%2;//随机生成"0"或"1"
		if(k==0)//括号位置在前
		{
			if(ope==1)
			{
				cout<<"("<<a<<"+"<<b<<")"<<"+"<<c<<"="<<endl;
				outfile<<"("<<a<<"+"<<b<<")"<<"+"<<c<<"="<<endl;
			}
			else if(ope==2)
			{
				cout<<"("<<a<<"-"<<b<<")"<<"-"<<c<<"="<<endl;
				outfile<<"("<<a<<"-"<<b<<")"<<"-"<<c<<"="<<endl;
			}
			else if(ope==3)
			{
				cout<<"("<<a<<"*"<<b<<")"<<"*"<<c<<"="<<endl;
				outfile<<"("<<a<<"*"<<b<<")"<<"*"<<c<<"="<<endl;
			}
			else if(ope==4)
			{
				cout<<"("<<a<<"/"<<b<<")"<<"/"<<c<<"="<<endl;
				outfile<<"("<<a<<"/"<<b<<")"<<"/"<<c<<"="<<endl;
			}
			else
			{
				cout<<"("<<a<<op[op1]<<b<<")"<<op[op2]<<c<<"="<<endl;
				outfile<<"("<<a<<op[op1]<<b<<")"<<op[op2]<<c<<"="<<endl;
			}
		}
		else//括号位置在后
		{
			if(ope==1)
			{
				cout<<a<<"+"<<"("<<b<<"+"<<c<<")"<<"="<<endl;
				outfile<<a<<"+"<<"("<<b<<"+"<<c<<")"<<"="<<endl;
			}
			else if(ope==2)
			{
				cout<<a<<"-"<<"("<<b<<"-"<<c<<")"<<"="<<endl;
				outfile<<a<<"-"<<"("<<b<<"-"<<c<<")"<<"="<<endl;
			}
			else if(ope==3)
			{
				cout<<a<<"*"<<"("<<b<<"*"<<c<<")"<<"="<<endl;
				outfile<<a<<"*"<<"("<<b<<"*"<<c<<")"<<"="<<endl;
			}
			else if(ope==4)
			{
				cout<<a<<"/"<<"("<<b<<"/"<<c<<")"<<"="<<endl;
				outfile<<a<<"/"<<"("<<b<<"/"<<c<<")"<<"="<<endl;
			}
			else
			{
				cout<<a<<op[op1]<<"("<<b<<op[op2]<<c<<")"<<"="<<endl;
				outfile<<a<<op[op1]<<"("<<b<<op[op2]<<c<<")"<<"="<<endl;
			}
		}
	}
}
void decimal_Cal()//生成小数四则运算
{
	double a,b,c,d;
	a=(double)rand()/RAND_MAX*imax+1.0;
	b=(double)rand()/RAND_MAX*imax+1.0;
	c=(double)rand()/RAND_MAX*imax+1.0;
	int op1,op2;
	op1=rand()%4;
	op2=rand()%4;
	if(brackets==1)
	{
		if(ope==1)
		{
			cout<<a<<"+"<<b<<"+"<<c<<"="<<endl;
			outfile<<a<<"+"<<"("<<b<<"+"<<c<<")"<<"="<<endl;
		}
		else if(ope==2)
		{
			cout<<a<<"-"<<b<<"-"<<c<<"="<<endl;
			outfile<<a<<"-"<<"("<<b<<"-"<<c<<")"<<"="<<endl;
		}
		else if(ope==3)
		{
			cout<<a<<"*"<<b<<"*"<<c<<"="<<endl;
			outfile<<a<<"*"<<"("<<b<<"*"<<c<<")"<<"="<<endl;
		}
		else if(ope==4)
		{
			cout<<a<<"/"<<b<<"/"<<c<<"="<<endl;
			outfile<<a<<"/"<<"("<<b<<"/"<<c<<")"<<"="<<endl;
		}
		else
		{
			cout<<a<<op[op1]<<b<<op[op2]<<c<<"="<<endl;
			outfile<<a<<op[op1]<<"("<<b<<op[op2]<<c<<")"<<"="<<endl;
		}
	}
	else
	{
		int k;
		k=rand()%2;
		if(k==0)
		{
			if(ope==1)
			{
				cout<<"("<<a<<"+"<<b<<")"<<"+"<<c<<"="<<endl;
				outfile<<"("<<a<<"+"<<b<<")"<<"+"<<c<<"="<<endl;
			}
			else if(ope==2)
			{
				cout<<"("<<a<<"-"<<b<<")"<<"-"<<c<<"="<<endl;
				outfile<<"("<<a<<"-"<<b<<")"<<"-"<<c<<"="<<endl;
			}
			else if(ope==3)
			{
				cout<<"("<<a<<"*"<<b<<")"<<"*"<<c<<"="<<endl;
				outfile<<"("<<a<<"*"<<b<<")"<<"*"<<c<<"="<<endl;
			}
			else if(ope==4)
			{
				cout<<"("<<a<<"/"<<b<<")"<<"/"<<c<<"="<<endl;
				outfile<<"("<<a<<"/"<<b<<")"<<"/"<<c<<"="<<endl;
			}
			else
			{
				cout<<"("<<a<<op[op1]<<b<<")"<<op[op2]<<c<<"="<<endl;
				outfile<<"("<<a<<op[op1]<<b<<")"<<op[op2]<<c<<"="<<endl;
			}
		}
		else
		{
			if(ope==1)
			{
				cout<<a<<"+"<<"("<<b<<"+"<<c<<")"<<"="<<endl;
				outfile<<a<<"+"<<"("<<b<<"+"<<c<<")"<<"="<<endl;
			}
			else if(ope==2)
			{
				cout<<a<<"-"<<"("<<b<<"-"<<c<<")"<<"="<<endl;
				outfile<<a<<"-"<<"("<<b<<"-"<<c<<")"<<"="<<endl;
			}
			else if(ope==3)
			{
				cout<<a<<"*"<<"("<<b<<"*"<<c<<")"<<"="<<endl;
				outfile<<a<<"*"<<"("<<b<<"*"<<c<<")"<<"="<<endl;
			}
			else if(ope==4)
			{
				cout<<a<<"/"<<"("<<b<<"/"<<c<<")"<<"="<<endl;
				outfile<<a<<"/"<<"("<<b<<"/"<<c<<")"<<"="<<endl;
			}
			else
			{
				cout<<a<<op[op1]<<"("<<b<<op[op2]<<c<<")"<<"="<<endl;
				outfile<<a<<op[op1]<<"("<<b<<op[op2]<<c<<")"<<"="<<endl;
			}
		}
	}
}
