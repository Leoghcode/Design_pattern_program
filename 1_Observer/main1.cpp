#include<iostream>
#include"observe1.h"
using namespace std;

int main(int argc, char* argv[])
{
	User A("A");
	User B("B");
	User C("C");
	User D("D");
	A.addObserver(&B);
	A.addObserver(&C);
	A.addObserver(&D);
	B.addObserver(&C);
	B.addObserver(&D);
	C.addObserver(&D);

	cout << "1.չʾ�û�A,B,C,D��friend" << endl;
	A.printFriendsList();
	B.printFriendsList();
	C.printFriendsList();
	D.printFriendsList();

	cout << "==============================================" << endl;
	string a = "#";
	string b = "#";
	while (1)
	{
		cout << "\n2.�޸�ĳ������״̬���� A on��A off ���˳���exit a��" << endl;
		cin >> a;
		cin >> b;
		if(a!="exit")
			cout << endl << "ĳЩ�û��յ����ѣ�" << endl;

		if (a == "A"&&b == "on")
			A.online();
		else if (a == "A"&&b == "off")
			A.offline();
		else if (a == "B"&&b == "on")
			B.online();
		else if (a == "B"&&b == "off")
			B.offline();
		else if (a == "C"&&b == "on")
			C.online();
		else if (a == "C"&&b == "off")
			C.offline();
		else if (a == "D"&&b == "on")
			D.online();
		else if (a == "D"&&b == "off")
			D.offline();
		else if (a == "exit")
			break;
		else
			cout << "���Ϸ�������!" << endl;

		cout << "\n==============================================" << endl;
		cout << "�����ߵ��������ԣ����ߺ���������������Ӧ�ı�" << endl;
		A.printOLFriendNum();
		B.printOLFriendNum();
		C.printOLFriendNum();
		D.printOLFriendNum();

	}

	cout << "\n3.��ʾ�û��ķ�˿���������б�" << endl;
	A.printFollowedUser();
	B.printFollowedUser(); 
	C.printFollowedUser();
	D.printFollowedUser();
	//A.online();
	getchar();
	getchar();
	cout << "\n4.ȡ��D��A�Ķ���" << endl;
	D.deleteObservable(&A);
	A.printFollowedUser();
	D.printFriendsList();
	getchar();
	return 0;
}
