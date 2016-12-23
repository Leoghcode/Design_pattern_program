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

	cout << "1.展示用户A,B,C,D的friend" << endl;
	A.printFriendsList();
	B.printFriendsList();
	C.printFriendsList();
	D.printFriendsList();

	cout << "==============================================" << endl;
	string a = "#";
	string b = "#";
	while (1)
	{
		cout << "\n2.修改某人在线状态：如 A on或A off （退出：exit a）" << endl;
		cin >> a;
		cin >> b;
		if(a!="exit")
			cout << endl << "某些用户收到提醒：" << endl;

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

		cout << "\n==============================================" << endl;
		cout << "订阅者的自身属性（在线好友数量）发生相应改变" << endl;
		A.printOLFriendNum();
		B.printOLFriendNum();
		C.printOLFriendNum();
		D.printOLFriendNum();

	}

	cout << "\n3.显示用户的粉丝（订阅者列表）" << endl;
	A.printFollowedUser();
	B.printFollowedUser(); 
	C.printFollowedUser();
	D.printFollowedUser();
	//A.online();
	getchar();
	getchar();
	cout << "\n4.取消D对A的订阅" << endl;
	D.deleteObservable(&A);
	A.printFollowedUser();
	D.printFriendsList();
	getchar();
	return 0;
}
