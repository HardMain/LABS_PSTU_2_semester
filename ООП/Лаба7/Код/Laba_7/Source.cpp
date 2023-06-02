#include "List.h"
#include "Pair.h"

int main()
{
	system("chcp 1251 >> null");

// -----------------------------------------------------------------

	List<int> a, a2;

	a.push_back(10);
	a.push_back(15);
	cout << "List<int>(a): "; a.show_list();
	cout << "a[0]: " << a[0] << endl; 
	cout << "size a(): " << a() << endl << endl;

	a2.push_back(10);
	a2.push_back(15);
	a2.push_back(20);
	cout << "List<int>(a2): "; a2.show_list();
	cout << "a2[0]: " << a2[0] << endl;
	cout << "size a2(): " << a2() << endl << endl;
	
	a = a * a2;
	cout << "(a = a * a2) == "; a.show_list(); 
	cout << "_____________________________________________________\n\n";

// -----------------------------------------------------------------

	List<float> b, b2;

	b.push_back(10.5);
	b.push_back(15.5);
	cout << "List<float>(b): "; b.show_list();
	cout << "b[0]: " << b[0] << endl;
	cout << "size b(): " << b() << endl << endl;

	b2.push_back(10.5);
	b2.push_back(15.5);
	b2.push_back(20.5);
	cout << "List<float>(b2): "; b2.show_list();
	cout << "b2[0]: " << b2[0] << endl;
	cout << "size b2(): " << b2() << endl << endl;

	b = b * b2;
	cout << "(b = b * b2) == "; b.show_list();
	cout << "_____________________________________________________\n\n";

// -----------------------------------------------------------------

	List<double> c, c2;

	c.push_back(10.111);
	c.push_back(15.555);
	cout << "List<double>(c): "; c.show_list();
	cout << "c[0]: " << c[0] << endl;
	cout << "size c(): " << c() << endl << endl;

	c2.push_back(10.111);
	c2.push_back(15.555);
	c2.push_back(20.555);
	cout << "List<double>(c2): "; c2.show_list();
	cout << "c2[0]: " << c2[0] << endl;
	cout << "size c2(): " << c2() << endl << endl;

	c = c * c2;
	cout << "(c = c * c2) == "; c.show_list();
	cout << "_____________________________________________________\n\n";

// -----------------------------------------------------------------

	List<Pair> d, d2;
	Pair dp(11,17.2), dp2(16,7.7);

	d.push_back(dp);
	dp = dp + 5; dp = dp + 5.0;
	d.push_back(dp);
	cout << "List<Pair>(d): "; d.show_list();
	cout << "d[0]: " << d[0] << endl;
	cout << "size d(): " << d() << endl << endl;

	d2.push_back(dp2);
	dp2 = dp2 + 5; dp2 = dp2 + 5.0;
	d2.push_back(dp2);
	d2.push_back(dp2);
	cout << "List<Pair>(d2): "; d2.show_list();
	cout << "d2[0]: " << d2[0] << endl;
	cout << "size d2(): " << d2() << endl << endl;

	d = d * d2;
	cout << "(d = d * d2) == "; d.show_list();
	cout << "_____________________________________________________\n\n";

// -----------------------------------------------------------------

	return 0;
}
