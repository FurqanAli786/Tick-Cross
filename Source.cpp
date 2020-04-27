#include<iostream>
#include<conio.h>

using namespace std;

char a[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char turn='X';
int row,column;
bool draw=false;

void board_display()
{
	system("cls");
cout<<" \n\t\t TICK CROSS GAME \n ";
cout<<" \n\t Player1 [X] \n \t Player2 [0] \n\n";
cout<<" \t\t     |     |     \n";
cout<<" \t\t  "<<a[0][0]<<"  |  "<<a[0][1]<<"  |  "<<a[0][2]<<"     \n";
cout<<" \t\t_____|_____|_____\n";
cout<<" \t\t     |     |     \n";
cout<<" \t\t  "<<a[1][0]<<"  |  "<<a[1][1]<<"  |  "<<a[1][2]<<"     \n";
cout<<" \t\t_____|_____|_____\n";
cout<<" \t\t     |     |     \n";
cout<<" \t\t  "<<a[2][0]<<"  |  "<<a[2][1]<<"  |  "<<a[2][2]<<"     \n";
cout<<" \t\t     |     |     \n";
}

void player_turn()
{
	int ch;

	if (turn=='X')
cout<<"\n\t Player1 [X] Turn::: ";

	if (turn=='0')
cout<<"\n\t Player2 [0] Turn::: ";
	
cin>>ch;
switch(ch)

	/*case 1:a[0][0]='X';break;
	case 2:a[0][1]='X';break;
	case 3:a[0][2]='X';break;
	case 4:a[1][0]='X';break;
	case 5:a[1][1]='X';break;
	case 6:a[1][2]='X';break;
	case 7:a[2][0]='X';break;
	case 8:a[2][1]='X';break;
	case 9:a[2][2]='X';break;
	default:cout<<" Invalid Choice !!! /n";break;

}*/
{
	case 1: row=0; column=0;break;
	case 2: row=0; column=1;break;
	case 3: row=0; column=2;break;
	case 4: row=1; column=0;break;
	case 5: row=1; column=1;break;
	case 6: row=1; column=2;break;
	case 7: row=2; column=0;break;
	case 8: row=2; column=1;break;
	case 9: row=2; column=2;break;
	default:cout<<" Invalid Choice...!!! \n";break;
}
if (turn=='X' &&a[row][column]!='X' &&a[row][column]!='0')
{
a[row][column]='X';
turn='0';
}
else if (turn=='0' &&a[row][column]!='X' &&a[row][column]!='0')
{
a[row][column]='0';
turn='X';
}
else 
{
		cout<<" \n Box Is Already Filled!!! \n Please Try Again... \n ";
player_turn();
}
}

bool gameover()
{
//game win
	for (int i=0;i<3;i++)
	if(a[i][0]==a[i][1] && a[i][0]==a[i][2] || a[0][i]==a[1][i] && a[0][i]==a[2][i])
		return false;

	if(a[0][0]==a[1][1] && a[0][0]==a[2][2] || a[0][2]==a[1][1] && a[0][2]==a[2][0])
		return false;

	//if any box not filled
	for (int i=0;i<3;i++)
		for (int j=0;j<3;j++)
			if(a[i][j]!='X' && a[i][j]!='0')
				return true;

	//draw
	draw=true;
	return false;
}
int main()
{
	while(gameover())
	{
	board_display();
	//player_turn();
	//gameover();
	player_turn();
	board_display();
	//board_display();
	}

	if(turn=='X' && draw== false)
		cout<<"Player 2[0] Wins "<<"\n"<<"Congratulations!!! \n";

	else if(turn=='0' && draw== false)
		cout<<"Player 1[X] Wins "<<"\n"<<"Congratulations!!! \n";
	else 
		cout<<"Game Draw \n ";
getch();
}