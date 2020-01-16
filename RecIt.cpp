#include <iostream>
using namespace std;
int gcdrec(int a,int b)
{
	if(a<0||b<0)
		throw 1;
	 else if(a==0)
		return b;
	return gcdrec(b%a,a); 
}
int gcditr(int a,int b)
{
	if(a<0||b<0)
		throw 1;
	int temp;
	while(b!=0)
	{
		temp=b;
		b=a%b;
		a=temp;
	}
		return a;
}
double xyrec(float a,int b)
{
	double temp;
	if(b==0)
		return 1;
	temp=xyrec(a,b/2);
	if(b%2==0)
		return temp*temp;
	else
	{
		if(b>0)
			return a*temp*temp;
		else
			return (temp*temp)/a;
	}
}
double xyitr(float a,int b)
{
	double result=1;int c=(b>0)?b:-b;
	for(int i=1;i<=c;i++)
	{
		if(b>0)
			result*=a;
		else
			result/=a;
	}
	return result;
}
int factrec(int num)
{
	if(num<0)
		throw 1;
	if(num==0)
		return 1;
	return num*factrec(num-1);
}
int factitr(int num)
{
	if(num<0)
		throw 1;
	int fact=1;
	while(num>=1)
		fact*=num--;
	return fact;
}
void fibitr(int num)
{
	if(num<0)
		throw 1;
	int a=0,b=1,c,i;
	if(num==1)
		cout<<"\n"<<a;
	for(i=2;i<=num;i++)
	{
		c=a+b;
		a=b;
		b=c;
		cout<<"\n"<<a;
	}
}
int fibrec(int num)
{
	if(num<0)
		throw 1;
	if(num==0)
		return 0;
	else if(num==1)
		return 1;
	else 
		return(fibrec(num-1)+fibrec(num-2));
}
int main()
{
	int n,r;
	char ch;
	do
	{
		cout<<"\n1. Fibonacci Series\n2. x^y\n3. Factorial\n4. GCD\n";
		cin>>n;
		cout<<"\n1. Recursive Method\n2. Itreative Method\n";
		cin>>r;
		try
		{
			if(n==1)
			{
				int num;
				cout<<"Enter the number of terms\n";
				cin>>num;
				if(num<0)
					throw 1;
				if(r==1)
					for(int c=0;c<num;c++)
						cout<<"\n"<<fibrec(c);
				else
					fibitr(num);
			}
			else if(n==2)
			{
				float base;int exp;
				cout<<"\nEnter base\n";
				cin>>base;
				cout<<"\nEnter exponent\n";
				cin>>exp;
				if(r==1)
					cout<<"\n"<<xyrec(base,exp);
				else
					cout<<"\n"<<xyitr(base,exp);
			}
			else if(n==3)
			{	
				int num;
				cout<<"\nEnter a positive number to find its factorial\n";cin>>num;
				if(r==1)
					cout<<"\nFactorial = "<<factrec(num);
				else
					cout<<"\nFactorial = "<<factitr(num);
			}
			else if(n==4)
			{	
				int num1,num2;
				cout<<"\nEnter two numbers\n";
				cin>>num1>>num2;
				if(r==1)
					cout<<"\nGCD is "<<gcdrec(num1,num2);
				else
					cout<<"\nGCD is "<<gcditr(num1,num2);
			}
			else
				cout<<"\nInvalid choice\nProgram Terminated\n";
		}
		catch(int i)
		{
			cout<<"\nNot applicable for negative numbers\n";
		}
		cout<<"\nEnter any character to continue\nEnter 0 to terminate\n";
		cin>>ch;
	}while (ch!='0');
	return 0;
}