

#include <iostream>
#include <string>
using namespace std;


int sum(string num, int index, int &counter);
int stairs(int staircount);
bool s(string word,int index,bool p);
int gcd(int a, int b);
int main()
{
	string num;
	int index = 0;
	int counter = 0;
	int staircount=0;
	string word;
	bool p=false;
	int a = 0, b = 0;
	
	
	cout << "what number ";
	cin >> num;
	sum(num, index, counter);
	cout << counter<<endl;
	counter = 0;

	cout << "how many stairs ";
	cin >> staircount;
	cout<<stairs(staircount)<<endl;
	
	cout << "what word ";
	cin >> word;
	cout<<boolalpha<<s(word, index, p)<<endl;

	cout << "a? + b?";
	cin >> a >> b;
	cout << gcd(a, b);

	


}

int sum(string num, int index,int &counter )

{
	if (index == num.size())
	{
		return counter;
	}
	counter = (num[index] -48) + counter;
	
	sum(num, index+1, counter);
}
int stairs(int staircount)
{
	if (staircount < 0)
	{
		return 0;
	}
	if (staircount == 1)
	{
		return 1;
	}
	if (staircount == 0)
	{
		return 1;
	}
	return stairs(staircount - 1) + stairs(staircount - 2);
}
bool s(string word,int index,bool p)
{
	
	if(index == (word.size()/2))
	{
		return p;
	}

	if (word[index] == word[word.size() - index-1])
	{
		p = true;
	}
	if (word[index] != word[word.size() - index-1])
	{
		p = false;
	}

	return s(word, index + 1, p);
}
int gcd(int a, int b)
{
	if (b == 0)
	{
		return a;
	}
	return gcd(b, a % b);
}