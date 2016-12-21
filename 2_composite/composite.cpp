#include"composite.h"
#include<iostream>
#include<sstream>
/*Entry function*/
Entry::Entry(){

}
Entry*  Entry::add(Entry* entry)
{
	cout << "file cannot add!" << endl;
	return NULL;
}
void Entry::printList1()
{
	string str = " ";
	printList(str);
}
string Entry::toString()
{
	string str;
	str = getName();
	str = str.append(" (");
	stringstream ss;
	ss << getSize();
	str = str.append(ss.str());
	str = str.append(")");

	return str;
}
/*end of Entry function*/


/*File functions*/
File::File(string name, int size)
{
	this->name = name;
	this->size = size;
}

string File::getName()
{
	return name;
}

int File::getSize()
{
	return size;
}
void File::printList(string prefix)
{
	cout << prefix << "/" << toString()<<endl;
}
/*end of File functions*/

/*Directory functions*/
Directory::Directory(string name)
{
	this->name = name;
	this->directory = new vector<Entry*>();
}
string Directory::getName()
{
	return name;
}
int Directory::getSize()
{
	int size = 0;
	int length = directory->size();
	if (length!=0)
	{
		for (int i = 0; i < length; i++)
		{
			size += directory->at(i)->getSize();
		}
	}
	return size;
}
Entry* Directory::add(Entry* entry)
{
	directory->push_back(entry);
	return entry;
}
void Directory::printList(string prefix)
{
	cout << prefix << "/" <<toString()<<endl;
	int length = directory->size();
	if (length != 0)
	{
		string str,str1;
		for (int i = 0; i < length; i++)
		{
			str = prefix + "/";
			str1=str.append(name);
			directory->at(i)->printList(str1);
		}
	}
}
/*end of Directory functions*/