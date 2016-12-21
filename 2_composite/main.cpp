#include<iostream>
#include"composite.h"
using namespace std;

int main(char* argc, int argv)
{
	//һ��Ŀ¼
	cout << "1.���Ŀ¼root,��������Ŀ¼foo,bar,���ļ�rootfile1.  �밴���������.\n" << endl;
	getchar();
	Directory root("root");
	Directory foo("foo");
	Directory bar("bar");
	root.add(&foo);
	root.add(&bar);
	root.add(new File("rootfile1", 2730));
	cout << "===================================================" << endl;
	getchar();

	//����Ŀ¼
	cout << "\n2.��Ŀ¼foo,bar ����ļ�.   �밴���������.\n" << endl;
	getchar();
	File f1("foofile1", 1000);
	File f2("foofile2", 2000);
	File b1("barfile1", 1500);
	foo.add(&f1);
	foo.add(&f2);
	bar.add(&b1);
	cout << "===================================================" << endl;
	getchar();

	//��һ��ɨ��
	cout << "\n3.չʾrootĿ¼�µ��ļ��ṹ.   �밴���������.\n" << endl;
	getchar();
	root.printList1();
	cout << "===================================================" << endl;
	getchar();

	//��ȡ���׽ڵ�
	cout << "\n4.չʾ���еĽڵ�ĸ��ڵ�.   �밴���������.\n" << endl;
	getchar();
	root.getParent();
	foo.getParent();
	bar.getParent();
	f1.getParent();
	f2.getParent();
	b1.getParent();
	cout << "===================================================" << endl;
	getchar();

	//ɾ���ļ�f2
	cout << "\n5.ɾ��foo�µ��ļ�f2,����ʾfoo���ļ��ṹ. �밴���������.\n" << endl;
	getchar();
	f2.remove();
	foo.printList1();
	cout << "\n\n===================================================" << endl;
	getchar();

	//ɾ��Ŀ¼bar
	cout << "\n6.ɾ��root����Ŀ¼bar,�ٴ���ʾ�µ�rootĿ¼���ļ��ṹ.  �밴���������.\n" << endl;
	getchar();
	bar.remove();
	root.printList1();


	getchar();
	return 0;
}