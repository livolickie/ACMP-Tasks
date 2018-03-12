#include <fstream>
#include <sstream>
using namespace std;
int main()
{
	char a, b;
	int a1, b1;
	string str;
	ifstream in("input.txt");
	in >> str;
	in.close();
	ofstream out("output.txt");
	if (str.length() != 5)
		out << "ERROR";
	else
	{
		a = str[0];
		b = str[3];
		a1 = str[1] - '0';
		b1 = str[4] - '0';
		if (a1 > 8 || b1 > 8 || a-'0' > 24 || b-'0' > 24 || a-'0' < 17 || b-'0' < 17 || a1 <= 0 || b1 <= 0 || str[2] != '-')
			out << "ERROR";
		else
		{
			if ((abs(a1 - b1) == 1 && abs(a - b) == 2) || (abs(a1 - b1) == 2 && abs(a - b) == 1))
				out << "YES";
			else
				out << "NO";
		}
		out.close();
	}
	return 0;
}