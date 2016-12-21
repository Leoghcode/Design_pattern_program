#ifndef OBESERVER_H
#define OBESERBER_H
#include<string>
#include<vector>
using namespace std;
class hint {
public:
	hint();
	void changedOLState();
	bool returnOLState();
private:
	bool OLStateChanged;
};
class observable;
class observer;
class observer {
public:
	observer();
	virtual void update(observable* o, hint* _h) = 0;
	vector<observable*> obs;
};
class observable {
public:
	vector<observer*> observerList;
	bool stateChanged;

	observable();
	observer* addObserver(observer* o);
	//observer* removeObserver(observer* o);
	//virtual void notifyAllObservers1();
	void notifyAllObservers(hint* _h);

};


class User :public observable, public observer {
public:
	User(string name);
	void online();
	void offline();
	void update(observable* o, hint* _h);
	string returnName();
	void printFriendsList();
private:
	bool isOnLine;
	string name;
};

#endif
