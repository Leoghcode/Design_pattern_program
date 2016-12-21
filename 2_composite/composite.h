#ifndef COMPOSITE_H
#define COMPOSITE_H	
#include<string>
#include<vector>
#include<iostream>
using namespace std;
class Entry {
public:
	Entry();
	virtual string getName()=0;
	virtual int getSize()=0;
	virtual Entry* add(Entry* entry);
	virtual void remove()=0;
	void printList1();
	string toString();
	virtual void printList(string prefix)=0;
	void setParent(Entry* parent) {
		this->parent = parent;
	}
	void getParent() {
		cout << "me:  " << this->getName() << "  parent: ";
		if(this->parent==NULL)
			cout << "/" << endl;
		else
			cout << this->parent->getName() << endl;
	}
protected:
	Entry* parent;
};

class File :public Entry {
public:
	File(string name, int size,Entry* parent=NULL);
	virtual void remove();
	virtual string getName();
	virtual int getSize();
	virtual void printList(string prefix);
private:
	string name;
	int size;
};

class Directory :public Entry {
public:
	Directory(string name, Entry* parent = NULL);
	virtual string getName();
	virtual int getSize();
	virtual Entry* add(Entry* entry);
	virtual void remove();
	virtual int getEntryId(string name);
	virtual void printList(string prefix);
	vector<Entry*>* returnDirectory() {
		return directory;
	}
private:
	string name;
	vector<Entry*>* directory;

};
#endif