#include <fstream>
#include <algorithm>
using namespace std;
struct bigInt
{
	string val = "0";

	void operator + (bigInt addVal)
	{
		sum(val, addVal.val);
	}

	void operator = (string v)
	{
		val = v;
	}

	void sum(string a, string b)
	{
		if (a.length() < b.length())
		{
			string t = a;
			a = b;
			b = t;
		}
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
		int t = 0, m = 0;
		int i;
		for (i = 0; i < b.length(); i++)
		{
			t = (a[i] - '0') + (b[i] - '0') + m;
			a[i] = (t % 10) + '0';
			m = (t / 10);
		}
		if (m > 0)
		{
			do
			{
				if (i < a.length())
				{
					t = (a[i] - '0') + m;
					a[i] = (t % 10) + '0';
					m = (t / 10);
				}
				else
				{
					a += m + '0';
					m = 0;
				}
				i++;
			}
			while (m > 0);;
		}
		val = a;
		reverse(val.begin(), val.end());
		if (val[0] == '0')
		{
			val[0] = val[val.length() - 1];
			val[val.length() - 1] = '0';
		}
	}
};

string f(int val, int k, bigInt * map)
{
	if (val == 0 || val == 1) return "1";
	bigInt t;
	for (int i = 1; i <= k; i++)
	{
		if (val - i >= 0)
		{
			if (map[val - i].val == "0")
			{
				map[val - i].val = f(val - i, k, map);;
				t + map[val - i];
			}
			else
				t + map[val - i];
		}
	}
	return t.val;
}
int main()
{
	int n, k;
	ifstream in("input.txt");
	in >> k >> n;
	in.close();
	bigInt * map = new bigInt[n + 1];
	ofstream out("output.txt");
	out << f(n, k, map).c_str();
	out.close();
	delete[] map;
	return 0;
}