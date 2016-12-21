#include<iostream>
#include"composite.h"
using namespace std;

int main(char* argc, int argv)
{
	Directory root("root");
	Directory foo("foo");
	Directory bar("bar");
	root.add(&foo);
	root.add(&bar);
	foo.add(new File("foofile1",1000));
	foo.add(new File("foofile2", 2000));
	bar.add(new File("barfile1", 1500));

	root.add(new File("rootfile1", 2730));

	root.printList1();

	getchar();
	return 0;
}