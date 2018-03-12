#include <fstream>
#include <sstream>
using namespace std;
int main()
{
	int n,i,j;
	short l,z1,z2,z3;
	bool a;
	string str;
	ifstream in("input.txt");
	in >> n;
	ofstream out("output.txt");
	for (i = 0; i < n; i++)
	{
		in >> str;
		l = 0;
		z1 = 0;
		z2 = 0;
		z3 = 0;
		a = true;
		if (str[0] != '0') a = false;
		if (str[str.length() - 1] != '2') a = false;
		if (str[str.length() / 2] != '1') a = false;
		for (j = 0; j < str.length(); j++)
		{
			if (j > 0 && str[j] == '1' && str[j - 1] == '0')
				l++;
			if (j > 0 && str[j] == '2' && str[j - 1] == '1')
				l++;
			if (l == 0 && str[j] == '0')
			{
				z1++;
			}
			if (l == 1 && str[j] == '1')
			{
				z2++;
			}
			if (l == 2 && str[j] == '2')
			{
				z3++;
			}
		}
		if (z1 == z2 && z2 == z3 && a)
			out << "YES" << endl;
		else out << "NO" << endl;
	}
	in.close();
	out.close();
	return 0;
}