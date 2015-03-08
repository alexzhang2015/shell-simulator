#include"playgame.h"
int playgame::chogame()
{
	switch (n)
	{
	case 0:
		cout<<"you have choosed to eixt"<<endl;
		return 0;
	case 1:
//		numguess ng;
//		ng.play();
		use();
		return 1;

	default:
		cout<<"you have made a wrong choice"<<endl;
		return 1;

	}
}
void playgame::use()
{
//numguess ng;
ng.play();
}
void playgame::getgameinfor()
{
cout<<"please enter the number "<<endl;
cin>>n;


cin.clear();
//while(getchar()!='\n');
//cin.ignore();
cin.sync();
}
void playgame::askgame()
{
	cout<<"*************************MAIN MENU ************************"<<endl;
	cout<<"we have several games which game do you want to play"<<endl;
	cout<<"0 exit"<<endl;
	cout<<"1 number guessing game "<<endl;
//	cout<<"2 we solve the number guessing for you "<<endl;
//	cout<<"2 exit "<<endl;
}
void playgame::play()
{
	int i=0;
	int j=0;
	while(1)
	{
		askgame();
		getgameinfor();
		i=chogame();
		j++;
		if(j>6)
			break;
		if(i==0)
			break;
	}
}
playgame::playgame()
{
	n=10;
}
playgame::~playgame()
{

}
