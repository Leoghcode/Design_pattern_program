#ifndef COMPOSITE_H
#define COMPOSITE_H	
#include<string>
#include<vector>
using namespace std;
class Entry {
public:
	Entry();
	virtual string getName()=0;
	virtual int getSize()=0;
	virtual Entry* add(Entry* entry);
	void printList1();
	string toString();
	virtual void printList(string prefix)=0;
};

class File :public Entry {
public:
	File(string name, int size);
	virtual string getName();
	virtual int getSize();
	virtual void printList(string prefix);
private:
	string name;
	int size;
};

class Directory :public Entry {
public:
	Directory(string name);
	virtual string getName();
	virtual int getSize();
	virtual Entry* add(Entry* entry);
	virtual void printList(string prefix);
private:
	string name;
	vector<Entry*>* directory;

};
#endif