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
File::File(string name, int size, Entry* parent)
{
	this->name = name;
	this->size = size;
	this->parent = parent;
}
void File::remove()
{
	Directory* entry = (Directory*)this->parent;
	int index = entry->getEntryId(this->getName());
	if (index >= 0)
	{
		vector<Entry*>* direc = entry->returnDirectory();
		direc->erase(direc->begin() + index);
	}
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
Directory::Directory(string name,Entry* parent)
{
	this->name = name;
	this->parent = parent;
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
	entry->setParent(this);
	cout << this->getName() << "\t adds  \t" << entry->getName() << "\t successfully!" << endl;
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
void Directory::remove() {
	for (int i = 0; i < (directory->size()); i++) {
		directory->at(i)->remove();
	}
	Directory* entry = (Directory*)this->parent;
	int index = entry->getEntryId(this->getName());
	if (index >= 0)
	{
		vector<Entry*>* direc = entry->returnDirectory();
		direc->erase(direc->begin() + index);
	}
}
int Directory::getEntryId(string name) {
	for (int i = 0; i < directory->size(); i++)
	{
		if (name == directory->at(i)->getName())
			return i;
	}
	return -1;
}
/*end of Directory functions*/