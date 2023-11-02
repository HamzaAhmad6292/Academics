#include<iostream>
#include<string>
using namespace std;


class Decoder
{
private:
	string message;
public:
	Decoder(string);
	virtual void Decode();
	string getmessage();
};
class SuperDecoder : public Decoder
{
	string message;

public:
	SuperDecoder(string);
	void Decode();
};
class PremiumDecoder : public Decoder
{
	string message;
public:
	PremiumDecoder(string);
	void Decode();
};






Decoder::Decoder(string s)
{
	message = s;
}


void Decoder::Decode()
{
	len = message.length();
	for (int i = 0; i < len; i++)
	{
		for (int j = 5; j > 0; j--)
		{
			if (message[i] > 'Y' && message[i] < 'Z')
			{
				message[i] = 'A';
			}

			else if (message[i] > 'y')
			{
				message[i] = 'a';
			}
			else if (message[i] == ' ') {
				message[i] = message[i];
			}

			else
			{
				message[i]--;
			}
		}
	}
}
string Decoder::getmessage()
{
	return message;
}



SuperDecoder::SuperDecoder(string s = {}) :Decoder(s)
{
	s = getmessage();
	message = s;

}


void SuperDecoder::Decode()
{
	int l = message.length();

	for (int i = 0; i < l; i++)
	{
		if (((message[i] >= 70) && (message[i] <= 85)) || ((message[i] >= 102) && (message[i] <= 117)))
		{
			message[i] = message[i] - 5;
		}
		else if (message[i] == 'a')
		{
			message[i] = 'v';
		}
		else if (message[i] == 'b')
		{
			message[i] = 'w';
		}
		else if (message[i] == 'c')
		{
			message[i] = 'x';
		}
		else if (message[i] == 'd')
		{
			message[i] = 'y';
		}
		else if (message[i] == 'e')
		{
			message[i] = 'z';
		}


		else if (message[i] == 'A')
		{
			message[i] = 'V';
		}
		else if (message[i] == 'B')
		{
			message[i] = 'W';
		}
		else if (message[i] == 'C')
		{
			message[i] = 'X';
		}
		else if (message[i] == 'D')
		{
			message[i] = 'Y';
		}
		else if (message[i] == 'E')
		{
			message[i] = 'Z';
		}
	}




	cout << "The Decrypted Message is:" << message << endl;

cout << "The Number of Characters in String are :" << l << endl;

int nonv = 0;
int v = 0;

for (int i = 0; i < l; ++i)
{
	if (message[i] == 'a' || message[i] == 'e' || message[i] == 'i' ||
		message[i] == 'o' || message[i] == 'u' || message[i] == 'A' ||
		message[i] == 'E' || message[i] == 'I' || message[i] == 'O' ||
		message[i] == 'U')
	{
		++v;
	}
	else if ((message[i] >= 'a' && message[i] <= 'z') || (message[i] >= 'A' && message[i] <= 'Z'))
	{
		++nonv;
	}

	else
	{
		++nonv;
	}
}
cout << "The number of vowels are:" << v << endl;
cout << "The number of non-vowels are:" << nonv << endl;
}

PremiumDecoder::PremiumDecoder(string s = {}) :Decoder(s)
{
	s = getmessage();
	message = s;
}
void PremiumDecoder::Decode()
{
	int count = message.length();
	for (int i = 0; i < count; i++)
	{
		if (((message[i] >= 70) && (message[i] <= 85)) || ((message[i] >= 102) && (message[i] <= 117))) 
		{
			message[i] = message[i] - 5;
		}
		else if (message[i] == 'a')
		{
			message[i] = 'v';
		}
		else if (message[i] == 'b')
		{
			message[i] = 'w';
		}
		else if (message[i] == 'c')
		{
			message[i] = 'x';
		}
		else if (message[i] == 'd')
		{
			message[i] = 'y';
		}
		else if (message[i] == 'e')
		{
			message[i] = 'z';
		}


		else if (message[i] == 'A')
		{
			message[i] = 'V';
		}
		else if (message[i] == 'B')
		{
			message[i] = 'W';
		}
		else if (message[i] == 'C')
		{
			message[i] = 'X';
		}
		else if (message[i] == 'D')
		{
			message[i] = 'Y';
		}
		else if (message[i] == 'E')
		{
			message[i] = 'Z';
		}
	}
	int l = message.length();
	cout << "The Decrypted Message is :" << message << endl;


	cout << "The Number of Characters in String are :" << l << endl;

	int nonv = 0;
	int v = 0;

	for (int i = 0; i < l; i++)
	{
		if ((message[i] == 97) || (message[i] == 101) || (message[i] == 105) || (message[i] == 111) || (message[i] == 117))
		{
			v = v + 1;
		}
		else
			nonv = nonv + 1;
	}

	cout << "The number of vowels are:" << v << endl;
	cout << "The number of non-vowels are:" << nonv << endl;

	l = message.length();
	cout << "Reversed message:";
	for (int i = l; i >= 0; --i)
	{

		cout << message[i];
	}
	cout << endl;
}




void OperateDecoder(Decoder& object)
{
	object.Decode();

}



int main()
{

	cout << "Enter Message to be Decrypted:";
	string s;
	getline(cin, s);
	cout << "Which Decoder you want to run:" << endl;
	cout << "Press 1 for Decoder\n";
	cout << "Press 2 for Super Decoder\n";
	cout << "Press 3 for Premium Decoder\n";
	cout << "\n";



	int i;
	cin >> i;
	cout << "\n";
	Decoder obj(s);
	SuperDecoder obj1(s);
	PremiumDecoder obj2(s);



	if (i == 1)
	{

		OperateDecoder(obj);
	}
	else if (i == 2)
	{
		OperateDecoder(obj1);

	}
	else if (i == 3)
	{
		OperateDecoder(obj2);
	}





	system("pause");
	return 0;

}