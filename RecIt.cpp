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
	double prod=1;int c=(b>0)?b:-b;
	for(int i=1;i<=c;i++)
	{
		if(b>0)
			prod*=a;
		else
			prod/=a;
	}
	return prod;
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
	int prod=1;
	while(num>=1)
		prod*=num--;
	return prod;
}
void fibitr(int num)
{
	if(num<0)
		throw 3;
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
	cout<<"\n1. Fibonacci Series\n2. x^y\n3. Factorial\n4. GCD\n";
	cin>>n;
	if(n==2)
	cout<<"\nUse recurion if you want to enter negative exponent\n";
	cout<<"\n1. Recursion \n2. Itreation\n";
	cin>>r;
	try
	{
	if(n==1)
	{
		int num;
		cout<<"Enter the number of terms\n";
		cin>>num;
		if(r==1)
		{
			for(int c=0;c<num;c++)
			{
				cout<<"\n"<<fibrec(c);
			}
		}
		else
		fibitr(num);
	}
	else if(n==2)
	{
		float base;int exp;
		cout<<"\nEnter base\n";
		cin>>base;
		if(r==1)
		{
			cout<<"\nEnter exponent\n";
			cin>>exp;
			cout<<"\n"<<xyrec(base,exp);
		}
		else
		{
			cout<<"\nEnter exponent\n";
			cin>>exp;
			cout<<"\n"<<xyitr(base,exp);
		}
	}
	if(n==3)
	{
		int num;
		cout<<"\nEnter a positive number to find its factorial\n";cin>>num;
		if(r==1)
		{
			cout<<"\nFactorial = "<<factrec(num);
		}
		else
			cout<<"\nFactorial = "<<factitr(num);
	}
	if(n==4)
	{
		int num1,num2;
		cout<<"\nEnter two numbers\n";
		cin>>num1>>num2;
		if(r==1)
			cout<<"\nGCD is "<<gcdrec(num1,num2);
		else
			cout<<"\nGCD is "<<gcditr(num1,num2);
	}
	}
	catch(int i)
	{
		cout<<"\nInvalid for negative numbers\n";
	}
	return 0;
}