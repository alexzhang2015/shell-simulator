#include"numguess.h"

numguess::numguess()
{
c=NULL;
p=NULL;
num=4;
times=0;
}
numguess::~numguess()
{
delete [] c;
delete [] p;
}
void numguess::play()
{
	int i;
	int j=0;
	while(1)
	{
		i=gamechoose();
		j++;
		if(i==1)
			break;
		if(j>=5)
			break;
	}

}
int numguess::gamechoose()
{
	cout<<"*********GAME *********"<<endl;
	cout<<"0 to exit from the game"<<endl;
	cout<<"1 to play the game "<<endl;
	cout<<"2 to set the game mode"<<endl;
	int i=10;
//	int j=0;
	cin>>i;
	switch(i)
	{
	case 0:
		cout<<"exit"<<endl;
		return 1;
	case 1:
		gameinit();
		gamerun();
		return 1;
	case 2:
		gameset();
//		gameinit();
		return 0;
	default:
		cout<<"wrong input enter again"<<endl;
		return 0;
	}

}
void numguess::gameset()
{
cout<<"*****************SET MENU***********************"<<endl;
cout<<"we have easy nomal and hard mode for you to play"<<endl;
cout<<"1 for easy mode"<<endl;
cout<<"2 for normal mode"<<endl;
cout<<"3 for hard mode"<<endl;
/*c=NULL;
num=4;
time=0;*/
int i=10;
cin>>i;
cin.clear();
while(getchar()!='\n');
//cin.ignore();
switch(i)
{
case 1:
	num=3;
	break;
case 2:
	num=4;
	break;
case 3:
	num=5;
	break;
default:
	cout<<"wrong input set game fail"<<endl;
	break;
}
}
void numguess::gameinit()
{
//	int num=3;
c=new char [num];
p=new char [num];
int i=0;
	srand(time(NULL));
for(i=0;i<num;i++)
{
	p[i]='0';
	int j;

	j=rand()%16;
	if(0<=j&&j<=9)
		c[i]=j+48;
	else if(10<=j&&j<=15)
		c[i]=j+55;
	else 
	{
		cout<<"error "<<endl;
		exit(0);
	}
}
/*
for(i=0;i<num;i++)
{
c[i]=i+49;
}
*/
}
void numguess::gamerun()
{
	cout<<"now we are going to play the game"<<endl;

//	cout<<"enter # to stop play and see the answer"<<endl;
	while(1)
	{
		int i=0,j=0;
		i=gameinput();
		if(i==1)
			break;
		j=gamejudge();
		if(j==1)
			break;
		if(times>=num*3)
		{
			cout<<"too many times "<<endl;
			break;
		}
	}
	
}
int numguess::gameinput()
{
	cout<<"guess a number between 0..0("<<num<<"times) and f..f("<<num<<"times)"<<endl;
	cout<<"or enter # to stop play and see the answer enter * to auto run the game "<<endl;
	int i;
	for(i=0;i<num;i++)
	{
		cin>>p[i];
		if(p[0]=='#')
		{
			cout<<"the answer is"<<endl;
			for(int j=0;j<num;j++)
			cout<<c[j]<<" ";
			cout<<endl;
			cin.clear();
			while(getchar()!='\n');

			return 1;
		}
		
		if (p[0]=='*')
		{
			autogame();
			cin.clear();
			while(getchar()!='\n');

			return 1;
		}
		if(!(((48<=p[i])&&(p[i]<=57))||((p[i]<=70)&&(p[i]>=65))))
			cout<<"wrong input"<<endl;
//		cin>>p[i];
	}
	
	times++;
//	cin.ignore(100,'\n');
	cin.clear();
	while(getchar()!='\n');

	return 0;	
}
int numguess::gamejudge()
{
	int m=0,k=0;
	for(int i=0;i<num;i++)
	{
		for(int j=0;j<num;j++)
		{
			if(p[i]==c[j])
			{
				k++;
				break;
			}
		}
		if(c[i]==p[i])
			m++;
	}

	if(m==num)
	{
		cout<<"congratulations to you "<<endl;
		cout<<"you have won the game"<<endl;
		return 1;
	}
	cout<<"you have got "<<m<<"A"<<k<<"B"<<endl;
	return 0;
}
void numguess::autogame()
{
	cout<<"It is not completed yet"<<endl;
}