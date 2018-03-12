#include <fstream>
#include <sstream>
using namespace std;
int main()
{
	string a, b, c, t1, t2;
	ifstream in("input.txt");
	in >> a >> b >> c;
	in.close();
	ofstream out("output.txt");
	if (a.length() > b.length() && a.length() > c.length())
		out << a;
	else
	{
		if (b.length() > a.length() && b.length() > c.length())
			out << b;
		else
			if (c.length() > a.length() && c.length() > b.length())
				out << c;
			else
			{
				if (a.length() == b.length() && a.length() == c.length())
				{
					for (int i = 0; i < a.length(); i++)
					{
						if (a[i] > b[i] && a[i] > c[i])
						{
							out << a;
							break;
						}
						if (b[i] > a[i] && b[i] > c[i])
						{
							out << b;
							break;
						}
						if (c[i] > a[i] && c[i] > b[i])
						{
							out << c;
							break;
						}
						if (i == a.length() - 1)
						{
							if (a == b && a == c)
								out << a;
							else
								if (a == b)
									out << a;
								else
									if (a == c)
										out << a;
									else
										if (b == c)
											out << b;
						}
					}
				}
				else
				{
					if (a.length() == b.length())
					{
						t1 = a;
						t2 = b;
					}
					if (a.length() == c.length())
					{
						t1 = a;
						t2 = c;
					}
					if (b.length() == c.length())
					{
						t1 = b;
						t2 = c;
					}
					for (int i = 0; i < t1.length(); i++)
					{
						if (t1[i] > t2[i])
						{
							out << t1;
							break;
						}
						if (t2[i] > t1[i])
						{
							out << t2;
							break;
						}
						if (i == t1.length()-1) out << t1;
					}
				}
			}
	}
	out.close();
	return 0;
}