#include <iostream>
#include "Time.h"

bool operator < (Time c1, Time c2)
{
	return c1.Sec() < c2.Sec();
}
bool operator > (Time c1, Time c2)
{
	return c1.Sec() > c2.Sec();
}

using namespace std;
int main() {
	Time a(60);
	Time b(10, 10, 10);
	Time c(a);
	cout << c.ToString() << endl;
	c = a + b;
	cout << c.ToString() << endl;
	c.decSec(600);
	cout << c.ToString() << endl;
	c.addSec(1200);
	cout << c.ToString() << endl;
	
	Time r = c - a;
	cout << r.ToString() << endl;

	Time q(1, 1, 1);
	Time w(1, 1, 0);
	if (q > w) {
		cout << "OK";
	}
}