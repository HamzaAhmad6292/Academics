#include<iostream>
#include<cmath>
using namespace std;
int i = 1;
int c = 1;
bool mul = false;
bool sum = false;
bool subtract = false;
bool mag = false;
bool conj = false;
class ComplexNumber
{
	int real;
	int imaginary;
public:
	ComplexNumber(int x, int y); //with default arguments.
	void Input();
	void Output();
	bool IsEqual(ComplexNumber);


	ComplexNumber Conjugate();

	ComplexNumber Add(ComplexNumber);

	ComplexNumber Subtract(ComplexNumber);

	ComplexNumber Multiplication(ComplexNumber);

	float Magnitude();
};
ComplexNumber::ComplexNumber(int x = 0, int y = 0)
{

	real = x;

	imaginary = x;
}
void ComplexNumber::Input()
{
	int n = real;
	int m = imaginary;
	cout << "Enter c" << ":" << endl;
	cout << "Enter real part:";
	cin >> real;
	cout << "Enter Imaginary part:";
	cin >> imaginary;

}
void ComplexNumber::Output()
{


	if (mul == true)
	{
		if (imaginary >= 0)
		{
			cout << "c" << i++ << "xc" << i << "=" << real << "+" << imaginary << "i" << endl << endl;
		}
		else if (imaginary < 0)
		{
			cout << "c" << i++ << "xc" << i << "=" << real << imaginary << "i" << endl << endl;
		}
	}

	else if (sum == true)
	{
		if (imaginary >= 0)
		{
			cout << "c" << i++ << "+c" << i << "=" << real << "+" << imaginary << "i" << endl << endl;
		}
		else if (imaginary < 0)
		{
			cout << "c" << i++ << "+c" << i << "=" << real << imaginary << "i" << endl << endl;
		}
	}

	else if (subtract == true)
	{
		if (imaginary >= 0)
		{
			cout << "c" << i++ << "-c" << i << "=" << real << "+" << imaginary << "i" << endl << endl;
		}
		else if (imaginary < 0)
		{
			cout << "c" << i++ << "-c" << i << "=" << real << imaginary << "i" << endl << endl;
		}
	}
	else if (mag == true)
	{
		cout << "Magnitude:" << "c" << i++ << real;
	}

	else if (conj == true)
	{
		if (imaginary >= 0)
		{
			cout << "c" << i++ << "=" << real << imaginary << "i" << endl << endl;
		}
		else if (imaginary < 0)
		{
			cout << "c" << i++ << "=" << real << "+" << imaginary << "i" << endl << endl;
		}
	}
	else {
		if (imaginary >= 0)
		{
			cout << "c" << i++ << "=" << real << "+" << imaginary << "i" << endl << endl;
		}
		else if (imaginary < 0)
		{
			cout << "c" << i++ << "=" << real << imaginary << "i" << endl << endl;
		}
	}


}
bool ComplexNumber::IsEqual(ComplexNumber obj)
{
	if ((obj.real == real) && (obj.imaginary == imaginary))
	{
		return true;
	}
	else
	{
		return false;
	}
}
ComplexNumber ComplexNumber::Conjugate()
{

	int n = imaginary * (-1);
	int m = real;
	ComplexNumber obj(m, n);
	return obj;


}

ComplexNumber ComplexNumber::Add(const ComplexNumber obj)
{
	sum = true;
	int rsum = real + obj.real;
	int isum = imaginary + obj.imaginary;
	ComplexNumber obj1(rsum, isum);
	return obj1;
}


ComplexNumber ComplexNumber::Subtract(const ComplexNumber obj)
{
	subtract = true;
	int rsum = real - obj.real;
	int isum = imaginary - obj.imaginary;
	ComplexNumber obj1(rsum, isum);
	return obj1;
}

ComplexNumber ComplexNumber::Multiplication(const ComplexNumber obj)
{

	mul = true;
	int intmul = real * obj.real;
	int intima = real * obj.imaginary;
	int imaint = imaginary * obj.real;
	int imamul = imaginary * obj.imaginary;



	int r = intmul + (-1 * imamul);
	int im = intima + imaint;



	ComplexNumber obj1(r, im);
	return obj1;

}
float ComplexNumber::Magnitude()
{
	int n = real;
	int m = imaginary;

	int sqr1 = pow(n, 2);
	int sqrt2 = pow(m, 2);

	float sum = sqr1 + sqrt2;

	float final = sqrt(sum);

	return final;
}
int main()
{
	int a = 0;
	int b = 0;
	int x = 0;
	int y = 0;
	ComplexNumber c1(a, b);
	c1.Input();
	c1.Output();
	ComplexNumber c2(x, y);
	c2.Input();
	c2.Output();

	c = 1;
	i = 1;
	cout << "Conjigate of both:" << endl;
	ComplexNumber conj1 = c1.Conjugate();
	conj1.Output();
	ComplexNumber conj2 = c2.Conjugate();
	conj2.Output();

	i = 1;
	c = 1;

	bool flag = c1.IsEqual(c2);
	if (flag == true)
	{
		cout << "The complex Number are equal" << endl;
	}
	else
	{
		cout << "The complex Number are not equal" << endl;
	}
	c = 1;
	i = 1;


	ComplexNumber obj = c1.Add(c2);
	obj.Output();
	c = 1;
	i = 1;
	sum = false;

	ComplexNumber obj1 = c1.Subtract(c2);
	obj1.Output();
	c = 1;
	i = 1;
	subtract = false;

	ComplexNumber obj2 = c1.Multiplication(c2);
	obj2.Output();
	c = 1;
	i = 1;
	mul = false;

	float mag1 = c1.Magnitude();
	float mag2 = c2.Magnitude();

	cout << "Magnitude;" << mag1 << endl;
	cout << "Magnitude:" << mag2 << endl;

	return 0;

}