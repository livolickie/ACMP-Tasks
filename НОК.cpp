#include <fstream>
using namespace std;
int NOD(int n1, int n2)
{
	int div;
	if (n1 == n2)  return n1;
	int d = n1 - n2;
	if (d < 0) {
		d = -d;  div = NOD(n1, d);
	}
	else
		div = NOD(n2, d);
	return div;
}
int NOK(int n1, int n2)
{
	return n1 * n2 / NOD(n1, n2);
}
int main()
{
	int a, b;
	ifstream in("input.txt");
	in >> a >> b;
	in.close();
	ofstream out("output.txt");
	out << NOK(a, b);
	out.close();
	return 0;
}