#include<iostream>
#include<cstring>
using namespace std;
void Get_Next(char pattern[], int next[]);
int Kmp_Search(string text, string pattern);
int BF(string s, string t);
int main()
{
	int n;
	string string1 = "dasdasdac";
	string string2 = "asdac";
	n = Kmp_Search(string1, string2);


	if (n != -1)
		std::cout << n;
	else
		std::cout << "no";

	n = BF(string1, string2);
	cout << endl << n;



}

void Get_Next(string pattern, int next[])            //KMP算法的移位前的前缀表
{
	int j = 0;
	int k = -1;
	next[0] = -1;
	while (j < (int)pattern.length())
	{
		if (k == -1 || pattern[j] == pattern[k])
		{
			k++;
			j++;
			next[j] = k;
		}
		else
			k = next[k];
	}
}

int Kmp_Search(string text, string pattern)                //kmp搜索
{
	int i = 0, j = 0;
	int n;
	n = pattern.length();
	int next[50];
	Get_Next(pattern, next);
	while (i < (int)text.length() && j < (int)pattern.length())
	{
		if (j == -1 || text[i] == pattern[j])
		{
			j++;
			i++;
		}
		else
			j = next[j];
	}
	if (j == pattern.length())
		return i - pattern.length() + 1;
	else
		return -1;
}

int BF(string s, string t)
{
	int i = 0;
	int j = 0;
	while (i < s.length() && j < t.length())
	{
		if (s[i] == t[j])
		{
			i++;
			j++;

		}
		else
		{
			i = i - j + 1;
			j = 0;
		}
	}

	if (j == t.length())
		return i - j + 1;
	else
		return -1;
}