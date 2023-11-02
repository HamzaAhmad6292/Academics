#include<iostream>
#include<string>
using namespace std;


class Decoder
{
private:
	string message;
public:
	Decoder(string);
	Decoder();
	void Decode();
};
class SuperDecoder : public Decoder
{
	string m;

public:
	SuperDecoder(string);
	void Decode();
};
class PremiumDecoder : public Decoder
{
	string m1;
public:
	PremiumDecoder(string);
	void Decode();
};






Decoder::Decoder(string s)
{
	message = s;
}
Decoder::Decoder()
{

}

void Decoder::Decode()
{
	int count = message.length();

	for (int i = 0; i < count; i++)
	{
		if (((message[i] >= 65) && (message[i] <= 85)) || ((message[i] >= 97) && (message[i] <= 117)))
		{
			message[i] = message[i] + 5;
		}
		else if (message[i] == 122)
		{
			message[i] = 'e';
		}
		else if (message[i] == 121)
		{
			message[i] = 'd';
		}
		else if (message[i] == 120)
		{
			message[i] = 'c';
		}
		else if (message[i] == 119)
		{
			message[i] = 'b';
		}
		else if (message[i] == 118)
		{
			message[i] = 'a';
		}


		else if (message[i] == 90)
		{
			message[i] = 'E';
		}
		else if (message[i] == 89)
		{
			message[i] = 'D';
		}
		else if (message[i] == 88)
		{
			message[i] = 'C';
		}
		else if (message[i] == 87)
		{
			message[i] = 'B';
		}
		else if (message[i] == 86)
		{
			message[i] = 'A';
		}
	}
	cout << "Decrypted Message:" << message << endl;

}



SuperDecoder::SuperDecoder(string s) :Decoder(s)
{
	m = s;

}
void SuperDecoder::Decode()
{
	Decoder obj(m);
	Decode();

	int l = m.length();

	cout << "The Number of Characters in String are :" << l << endl;

	int nonv = 0;
	int v = 0;

	for (int i = 0; i < l; i++)
	{
		if ((m[i] == 97) || (m[i] == 101) || (m[i] == 105) || (m[i] == 111) || (m[i] == 117))
		{
			v = v + 1;
		}
		else
			nonv = nonv + 1;
	}

	cout << "The number of vowels are:" << v << endl;
	cout << "The number of non-vowels are:" << nonv << endl;
}

PremiumDecoder::PremiumDecoder(string s) :Decoder(s)
{
	m1 = s;
}
void PremiumDecoder::Decode()
{
	SuperDecoder obj(m1);
	obj.Decode();
	int l = m1.length();
	cout << "Reversed message:";
	for (int i = l; i >= 0; --i)
	{

		cout << m1[i];
	}
	cout << endl;
}



void OperateDecoder( Decoder& object)
{
	cout << "Enter Message to be Decrypted:";
	string s;
	cin >> s;
	cout << "Which Decoder you want to run:" << endl;
	cout << "Press 1 for Decoder\n";
	cout << "Press 2 for Super Decoder\n";
	cout << "Press 3 for Premium Decoder\n";
	cout << "\n";



	int i;
	cin >> i;
	cout << "\n";




	if (i == 1)
	{
		Decoder* temp = new Decoder(s);
		temp->Decode();
	}
	else if (i == 2)
	{
		Decoder* temp = new SuperDecoder(s);
		temp->Decode();

	}
	else if (i == 3)
	{
		Decoder* temp = new PremiumDecoder(s);
		temp->Decode();
	}

}

int main()
{
	Decoder obj;
	OperateDecoder(obj);



	system("pause");
	return 0;

}