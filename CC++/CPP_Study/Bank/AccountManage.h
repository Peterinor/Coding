//#pragma once
#ifndef _ACCOUNTMANAGE_H_
#define _ACCOUNTMANAGE_H_

#include"Account.h"

#include<fstream>
#include<vector>

using namespace std;

typedef vector <Account>	AccountList;

class AccountManage
{
public:
	AccountManage(void);
	~AccountManage(void);

public:
	//�½��˻���Ҫ��ӵ��˻��ɹ���Ա���������Ϣ����
	bool NewAccount();
	//�½��˻���Ҫ��ӵ��˻��ɲ�������
	bool NewAccount(Account &accountToAdd);

	//ɾ���˻���Ҫɾ�����û��ɹ���Ա���벢��Account SearchAccount()��������
	bool DeleteAccount();
	//ɾ���˻���Ҫɾ�����˻��ɲ���accountToDelet����
	bool DeleteAccount(long accountID);

	//�����˻���Ҫ�������˻��ɹ���Ա���룬�����������Ľ������m_ResultAccount������
	Account *SearchAccount();
	//�����˻���Ҫ�������˻��ɲ���accountToGet�����������������Ľ������m_ResultAccount������
	Account *SearchAccount(long accountID);
	/*��������������������Ȼ���ܸ��ݷ��ؽ�����ж��Ƿ���ȷ�����õ��ˣ����ǿ���ͨ�����m_ResultAccount
	��m_IDNumber�����Ի����Ҫ��Ϣ����ΪĬ��Ϊ0�����ǽ������ı�һ�¼��ɵõ����õĽ����������ָ��*/

	//��ʾ���е��˻���Ϣ
	void ShowAllAccount();
	//��ȡ�˻�����Ŀ
	int GetSizeOfAccountList();

	//��ȡ�˻��б�����
	AccountList &GetAccountList();

	/*��ĳһ���˻����в�������ʾ�û������˺ţ�Ȼ����ң���ϸ������
	����,���������define.h�еĶ���,�����ɹ�����true*/
	bool OperateAnAccount(/*int operation*/);
	/*��ĳ�˻�account����operation���������,�����ɹ�����true*/
	bool OperateAnAccount(int operation ,Account &account );


	/**************************�ļ�����******************************/
	//���˻��ļ�����
	bool OpenAccountFile(fstream &file,const char *accountFileName,int mode);

	//�ر��˻��ļ�����
	bool CloseAccountFile(fstream &file);

	//�����˻��б���
	void ReadAccoutList(fstream &file);

	//д���˻��б���
	void PutAccountList(fstream &file);

	//
	
	
private:
	AccountList	 m_AccountList;			//�˻��б�
	Account		 m_ResultAccount;		//�������

	AccountList::iterator m_AccountListIterator;		//�˻��б������	


};

#endif
