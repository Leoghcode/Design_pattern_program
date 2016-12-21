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

	A.printFriendsList();
	B.printFriendsList();
	C.printFriendsList();
	D.printFriendsList();

	string a = "#";
	string b = "#";
	while (1)
	{
		cout << "\n修改某人在线状态：如 A on或A off （退出：exit a）" << endl;
		cin >> a;
		cin >> b;
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
			cout << "不合法的输入!" << endl;
	}
	
	//A.online();
	getchar();
	return 0;
}
