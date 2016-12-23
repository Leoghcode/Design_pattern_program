#include"observe1.h"
#include<iostream>
#include<string>
using namespace std;
/*observable functions*/
observable::observable()
{
	//this->observerList = new vector<observer*>();
	this->stateChanged = false;
}
observer* observable::addObserver(observer* o)
{
	observerList.push_back(o);
	(o->obs).push_back(this);
	return o;
}
/*
observer* observable::removeObserver(observer* o)
{
	//observerList->erase(o);
	//o->obs->erase(this);
}
void observable::notifyAllObservers1()
{
	//notifyAllObservers();
}
*/
void observable::notifyAllObservers(hint* _h)
{
	int length = observerList.size();
	if (length != 0)
	{
		for (int i = 0; i < length; i++)
		{
			observerList.at(i)->update(this, _h);
		}
	}
	stateChanged = false;
}

bool observable::deleteObserver(observer* o) {
	for (int i = 0; i < observerList.size(); i++)
	{
		if (o == observerList.at(i))
		{
			observerList.erase(observerList.begin() + i);
			return true;
		}
	}
	return false;
}
/*observer functions*/
observer::observer()
{
	//obs = new vector<observable*>();
}
bool observer::deleteObservable(observable* o)
{
	
	for (int i = 0; i < obs.size(); i++)
	{
		if (o == obs.at(i))
		{
			obs.erase(obs.begin() + i);
			o->deleteObserver(this);
			return true;
		}
	}
	return false;
}

/*hint functions*/
hint::hint()
{
	OLStateChanged = false;
}
void hint::changedOLState()
{
	OLStateChanged = true;
}
bool hint::returnOLState()
{
	return OLStateChanged;
}


/*User functions*/
User::User(string name)
{
	isOnLine = false;
	this->name = name;
	olfriendnum = 0;
}
void User::online()
{
	if (isOnLine == false)
	{
		isOnLine = true;
		stateChanged = true;
		hint* hint1 = new hint();
		hint1->changedOLState();
		notifyAllObservers(hint1);

		User* usr = NULL;
		for (int i = 0; i < obs.size(); i++)
		{
			usr = (User *)obs.at(i);
			if (usr->isOnLine == true)
				olfriendnum++;
		}
	}
}
void User::offline()
{
	if (isOnLine == true)
	{
		isOnLine = false;
		stateChanged = true;
		hint* hint1 = new hint();
		hint1->changedOLState();
		notifyAllObservers(hint1);
	}
}
string User::returnName()
{
	return name;
}
void User::update(observable* o, hint* _h)
{
	User* usr = (User*)o;
	if (_h->returnOLState() == true&&this->isOnLine==true)
	{
		if (usr->isOnLine == true)
		{
			cout << "\n" << this->name << "\nNew Notice:  You friend " << usr->name << "  is on line." << endl;
			olfriendnum++;
			//cout << olfriendnum;
		}
		else
		{
			cout << "\n" << this->name << "\nNew Notice:  You friend " << usr->name << "  is off line." << endl;
			olfriendnum--;
		}

		cout << endl;

	}

}
void User::printFriendsList()
{
	cout << "User:" << this->name << endl;
	cout << "Friends:" << endl;
	int length = obs.size();
	if (length != 0)
	{
		User* usr = NULL;
		for (int i = 0; i < length; i++)
		{
			usr = (User*)(obs.at(i));
			cout << usr->name << "\t";
			if (usr->isOnLine == true)
				cout << "OnLine" << endl;
			else
				cout << "OffLine" << endl;
		}
	}
}
void User::printOLFriendNum()
{
	if(this->isOnLine==true)
	cout << this->name << ":" << "you have " << olfriendnum << " friends online." << endl;
}
void User::printFollowedUser() {
	User* usr = NULL;
	cout << this->name << " be followed by:";
	for (int i = 0; i < observerList.size(); i++)
	{
		usr = (User*)observerList.at(i);
		cout << usr->name << "\t";
	}
	cout << endl;
}