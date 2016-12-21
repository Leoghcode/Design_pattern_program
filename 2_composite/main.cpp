#include<iostream>
#include"composite.h"
using namespace std;

int main(char* argc, int argv)
{
	//一级目录
	cout << "1.添加目录root,和它的子目录foo,bar,子文件rootfile1.  请按任意键继续.\n" << endl;
	getchar();
	Directory root("root");
	Directory foo("foo");
	Directory bar("bar");
	root.add(&foo);
	root.add(&bar);
	root.add(new File("rootfile1", 2730));
	cout << "===================================================" << endl;
	getchar();

	//二级目录
	cout << "\n2.往目录foo,bar 添加文件.   请按任意键继续.\n" << endl;
	getchar();
	File f1("foofile1", 1000);
	File f2("foofile2", 2000);
	File b1("barfile1", 1500);
	foo.add(&f1);
	foo.add(&f2);
	bar.add(&b1);
	cout << "===================================================" << endl;
	getchar();

	//第一次扫描
	cout << "\n3.展示root目录下的文件结构.   请按任意键继续.\n" << endl;
	getchar();
	root.printList1();
	cout << "===================================================" << endl;
	getchar();

	//获取父亲节点
	cout << "\n4.展示所有的节点的父节点.   请按任意键继续.\n" << endl;
	getchar();
	root.getParent();
	foo.getParent();
	bar.getParent();
	f1.getParent();
	f2.getParent();
	b1.getParent();
	cout << "===================================================" << endl;
	getchar();

	//删除文件f2
	cout << "\n5.删除foo下的文件f2,并显示foo的文件结构. 请按任意键继续.\n" << endl;
	getchar();
	f2.remove();
	foo.printList1();
	cout << "\n\n===================================================" << endl;
	getchar();

	//删除目录bar
	cout << "\n6.删除root的子目录bar,再次显示新的root目录的文件结构.  请按任意键继续.\n" << endl;
	getchar();
	bar.remove();
	root.printList1();


	getchar();
	return 0;
}