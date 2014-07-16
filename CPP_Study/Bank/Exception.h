#pragma once

#include<iostream>

#include<fstream>
#include<string>

#include<stdlib.h>

using namespace std;

class Exception
{
public:
	Exception();
	Exception(string str);

	virtual void ShowException();

protected:
	string ExpType;

};

class FileException:public Exception
{
public:
	FileException();
	FileException(string str);
};

class OpenFileException:public FileException
{
public:
	OpenFileException();
	OpenFileException(string str);
};

class CloseFileException:public FileException
{
public:
	CloseFileException();
	CloseFileException(string str);
};


class NoFoundException:public Exception
{
public:
	NoFoundException();
	NoFoundException(string str);

};