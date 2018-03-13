#include <fstream>
using namespace std;
int main()
{
	int a, b;
	ifstream in("input.txt");
	in >> a >> b;
	in.close();
	ofstream out("output.txt");
	char c = a > b ? '>' : a == b ? '=' : '<';
	out << c;
	out.close();
	return 0;
}