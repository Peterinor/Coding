#include"Exception.h"

Exception::Exception():ExpType(""){}
Exception::Exception(string str):ExpType(str){}

void Exception::ShowException()
{
	if(ExpType.size()==0) cout<<"unknown expect!";
	else cout<<this->ExpType<<endl;
}


FileException::FileException():Exception("File operation error!"){}
FileException::FileException(string str):Exception(str){}

OpenFileException::OpenFileException():FileException("File open error!"){}
OpenFileException::OpenFileException(string str):FileException(str){}

CloseFileException::CloseFileException():FileException("File isn't open yet!Open it first please!"){}
CloseFileException::CloseFileException(string str):FileException(str){}

NoFoundException::NoFoundException():Exception("No Matched Item Found!Check you Input !"){}
NoFoundException::NoFoundException(string str):Exception(str){}