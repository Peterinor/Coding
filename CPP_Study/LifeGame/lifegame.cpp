/*
 * File		:lifegame.cpp
 * Author	:tangyu
 * Date		:2011-05-22 22:31:27 
 * Version	:0.1
 * LastMod	:2011-05-24 22:31:29 
 */

#include"lifegame.h"

#include<iostream>
#include<cstdlib>
using std::cout;
using std::cin;
using std::endl;

LifeGame::LifeGame(void ):land(10){}
LifeGame::LifeGame(int landsize,string landdata):land(landsize,landdata){}
LifeGame::LifeGame(int landsize,unit_type *landdata):land(landsize,landdata){}

void 	LifeGame::Init()
{
	//��ʼ��game����
	
#if String_Verify
	this->record.clear();
#else
	this->recordHash.clear();
#endif
	this->landSize=0;	
	/*
	this->land;
	
	this->currentState;
	*/
}

void 	LifeGame::Plant()
{
	cout<<"Select the Plant Mode !Auto or Mannual"<<endl;
	cout<<"Auto(Y)  Mannual(N)"<<endl;
	char ch='\0';	
	cin>>ch;
	/*
	if(ch=='Y' || ch=='y')
	{
		this->AutoPlant(); 
		return ;
	}*/
	if(ch=='N' || ch=='n')
	{
		this->MannualPlant();
		return ;
	}
	else
	{
		this->AutoPlant();
		return;
	}

}

void 	LifeGame::AutoPlant()
{
	cout<<"Input the Size of the land"<<endl;
	//cout<<"���������صĴ�С��"<<endl;
	cin>>this->landSize;
	//cout<<this->landSize;
	
	string landdata(this->landSize*this->landSize,'0');
	//cout<<landdata<<endl;	
	/**		����		**/
	srand(time(NULL));
	int seedNum=rand()%(this->landSize*this->landSize);
	//cout<<seedNum<<endl;
	for(int i=0;i<seedNum;  )
	{
		int x=rand()%this->landSize;
		int y=rand()%this->landSize;
		
		if(landdata[x*this->landSize+y]=='1')
			continue;
		else
		{
			landdata[x*this->landSize+y]='1';
			i++;
		}
	}
	land.SetLand(this->landSize,landdata);
}

void 	LifeGame::MannualPlant()
{
	cout<<"Input the Size of the land"<<endl;
	//cout<<"���������صĴ�С��"<<endl;
	cin>>this->landSize;
	
	string landdata(this->landSize*this->landSize,'0');
	
	/**		����		**/	
	int seedNum;
	cout<<"Input the Number Of Seeds:"<<endl;
	cin>>seedNum;
	cout<<"Input the Positions Of the Seeds,Should be between 0 and "<<this->landSize-1<<" :"<<endl;
	for(int i=0;i<seedNum;  )
	{
		int x,y;
		cout<<"Input the Position Of the Seeds:"<<i<<endl;
		cin>>x;
		cin>>y;
		if(x<0 || x>this->landSize-1 || y<0 || y>this->landSize-1)
			continue;
		if(landdata[x*this->landSize+y]=='1')
			continue;
		else
		{
			landdata[x*this->landSize+y]='1';
			i++;
		}
	}
	//cout<<landdata<<endl;
	land.SetLand(this->landSize,landdata);
}

int 	LifeGame::CurrentState()
{
#if String_Verify
	return this->CurrentState_Str();
#else
	return this->CurrentState_Hash();
#endif
}


#if !String_Verify	
int 	LifeGame::CurrentState_Hash()
{
	//TODO:��ȡ��ǰ��״̬
	Hash_Type cur_state=this->HashLand(this->land.ReportLandState());
	//�ж�����״̬
	string dead(this->landSize*this->landSize,'0');
	if(cur_state==this->HashLand(dead)) 
		return LifeGame::CURRENT_DEAD;
	if(this->recordHash.size())
	{
		//�жϾ�ֹ״̬
		if(cur_state==this->recordHash[this->recordHash.size()-1])
			return LifeGame::CURRENT_STILL;
		//�ж�ѭ��״̬
		if(this->recordHash.size()>2)
		{
			StateRecHash::iterator findit = find(this->recordHash.begin(),this->recordHash.end(),cur_state);
			if(findit!=this->recordHash.end())
			{
				return LifeGame::CURRENT_LOOP;
			}
			/*TODO:
			in some circumstainces 
			return LifeGame::CURRENT_SLIDE;
			*/
		}
    }
}
#else
int 	LifeGame::CurrentState_Str()
{
	//TODO:��ȡ��ǰ��״̬
	string cur_state=this->land.ReportLandState();
	//�ж�����״̬
	string dead(this->landSize*this->landSize,'0');
	if(cur_state==dead) 
		return LifeGame::CURRENT_DEAD;
	if(this->record.size())
	{
		//�жϾ�ֹ״̬
		if(cur_state==this->record[this->record.size()-1])
			return LifeGame::CURRENT_STILL;
		//�ж�ѭ��״̬
		if(this->record.size()>2)
		{
			StateRec::iterator findit = find(this->record.begin(),this->record.end(),cur_state);
			if(findit!=this->record.end())
			{
				return LifeGame::CURRENT_LOOP;
			}
			/*TODO:
			in some circumstainces 
			return LifeGame::CURRENT_SLIDE;
			*/
		}
    }
    return LifeGame::CURRENT_UNKNOWING;
}
#endif

void 	LifeGame::Play()
{	
	int playAgain=1;
	while(playAgain)
	{
		this->Init();
		this->GameBegin();
		this->Plant();	
		int willgo=1;
		while(willgo)
		{
			//cout<<this->land.ReportLandState()<<endl;
			this->land.PrintLand();		
			//���״̬
			cout<<"Current State!-->";
			switch(this->CurrentState())
			{
			case LifeGame::CURRENT_DEAD:
				cout<<"Dead!"<<endl;
				break;
			case LifeGame::CURRENT_STILL:
				cout<<"Still"<<endl;
				break;
			case LifeGame::CURRENT_LOOP:
				cout<<"Loop"<<endl;
				break;
			case LifeGame::CURRENT_SLIDE:
				cout<<"Move Loop"<<endl;
				break;
			case LifeGame::CURRENT_UNKNOWING:
			default:
				//Do nothing!
				cout<<"Unknowing State!"<<endl;
				//1==1;			
			}
			//����ǰ״̬��hash����������������У��,����������һ��
#if !String_Verify
			this->recordHash.push_back(this->HashLand(this->land.NextGeneration()));
#else
			this->record.push_back(this->land.NextGeneration());
#endif		
			cout<<"continue Generate?! 1/0 "<<endl;
			cin>>willgo;
		}
		cout<<"Play game Again (1) Or Exit (0) "<<endl;
		cin>>playAgain;
	}
	this->GameOver();
}


#if !String_Verify
//TODO:���Hash������������ȷ����������벻ͬ�����ͬ���������Ҫ�Ľ�
Hash_Type 	LifeGame::HashLand(string landstr)
{

	if(landstr=="")
		return 0;	
	long hash;
	int len=landstr.length();
	for(int i=0;i<len;i++)
	{
		hash=(hash<<4)+landstr[i];		
	}
	return hash;	/**/
}

#endif

//****************************��Ϸ��logo*******************************
//��Ϸ��ʼ˵������Ϸͷ��
void LifeGame::GameBegin()
{
	system("clear"); //����

	cout<<"******************************\\/\\/TCL Group\\/\\/**********************************"<<endl
		<<"*****************************lifeGame by TCL Group *******************************"<<endl<<endl;
	
	cout<<"********************************** waiting ************************************\n"<<endl;
	cout<<"+++++++++++++++++++++++++++++++ Game begining +++++++++++++++++++++++++++++++++\n"<<endl;
	cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n"<<endl;
	cout<<"*******************************************************************************\n"<<endl;
	
}


//��Ϸ����˵������Ϸβ��	
void LifeGame::GameOver()
{

	cout<<"++++++++++++++++++++++++++++++++++  OH NO  ++++++++++++++++++++++++++++++++++++\n"<<endl;		
	cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n"<<endl;
	cout<<"*******************************************************************************\n"<<endl;
	cout<<"******************************** Game over ************************************\n"<<endl;

}







