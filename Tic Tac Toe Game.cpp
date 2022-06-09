#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
int playboard();
int player();
int toss();
int show();
int play();
int check();
int posncheck(int posn);

char arr[9]={'1','2','3','4','5','6','7','8','9'};
char player1[15],player2[15],symbol;
int n,count=0;
int main()
{
   playboard();
   player();
   toss();
   for(int i=0;i<6;i++)
   {
   	system("CLS");
   	show();
   	play();
   }
   
}
int playboard()
{
	printf("\n\t\t\t\t\t\t\t\t\t\t\t ~~~~~~~ TIC TAC TOE GAME ~~~~~~~\n\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t       --::GAME STARTED::-- ");
	printf("\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t       %c    |   %c   |   %c  \n",arr[0],arr[1],arr[2]);
	printf("\t\t\t\t\t\t\t\t\t\t\t     -------|-------|--------\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t       %c    |   %c   |   %c   \n",arr[3],arr[4],arr[5]);
	printf("\t\t\t\t\t\t\t\t\t\t\t     -------|-------|--------\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t       %c    |   %c   |   %c   \n",arr[6],arr[7],arr[8]);
}
int player()
{
	printf("\n\n\t  ENTER PLAYER1 NAME : ");
	scanf("%s",&player1);
	fflush(stdin);
	printf("\t  ENTER PLAYER2 NAME : ");
	scanf("%s",&player2);
	fflush(stdin);
	printf("\t  Player 1 : %s \n\t  Player 2 : %s\n ",player1,player2);
	
}
int toss()
{
	int tn[5],i,a,b,c;
	srand(time(0));
	for(i=0;i<5;i++)
	{
		tn[i]=rand();
	}
	printf("\n\t  %s CHOOSE A NUMBER WITHIN 0 TO 5 : ",player1);
	scanf("%d",&a);
	fflush(stdin);
	while(a>5)
	{
		printf("\n\t  YOU HAVE ENTERED A INVALID NUMBER ");
		printf("\n\t  ENTER A VALID RESPONSE : ");
		scanf("%d",&c);
		fflush(stdin);
		a=c;
	}
	printf("\t  %s CHOOSE A NUMBER WITHIN 0 TO 5 : ",player2);
	scanf("%d",&b);
	fflush(stdin);
	while(b>5 || b==a)
	{
		if(b>5)
		printf("\n\t  YOU HAVE ENTERED A INVALID NUMBER ");
		else
		printf("\n\t  %s HAS ALREADY ENTERED THIS NUMBER ",player1);
		printf("\n\t  ENTER A VALID RESPONSE : ");
		scanf("%d",&c);
		fflush(stdin);
		a=c;
	}
	if(tn[a]>tn[b])
	{
		 printf("\t  %s YOU OWN THE TOSS \n",player1);
		 printf("\t  PLEASE SELECT  X or 0 : ");
		 scanf("%c",&symbol);
		 fflush(stdin);
		 symbol=toupper(symbol);
		 while(symbol!='X' && symbol!='0')
		 {
		 	printf("\t  ENTER A VALID OPTION : ");
		 	scanf("%c",&symbol);
		 	fflush(stdin);
		 	symbol=toupper(symbol);
		 }
		 n=1;
	}
	else
	{
		printf("\t  %s YOU OWN THE TOSS \n",player2);
		printf("\t  PLEASE SELECT  X or 0 : ");
		scanf("%c",&symbol);
		fflush(stdin);
		symbol=toupper(symbol);
		while(symbol!='X' && symbol!='0')
		 {
		 	printf("\t  ENTER A VALID OPTION : ");
		 	scanf("%c",&symbol);
		 	fflush(stdin);
		 	symbol=toupper(symbol);
		 }
		n=2;
	}	
}
int play()
{
	int posn1,posn2;
	if(n==1)
	{
		if(symbol=='X')
		{
			printf("\n\n\t  %s ENTER YOUR POSITION : ",player1);
			scanf("%d",&posn1);
			fflush(stdin);
			posn1=posncheck(posn1);
			arr[posn1-1]='X';
			count+=1;
		    check();
		    system("CLS");
		    show();
			printf("\t  %s ENTER YOUR POSITION : ",player2);
			scanf("%d",&posn2);	
			fflush(stdin);
			posn2=posncheck(posn2);
			arr[posn2-1]='0';
			check();
		}
		else
		{
			printf("\n\n\t  %s ENTER YOUR POSITION  : ",player1);
			scanf("%d",&posn1);
			fflush(stdin);
			posn1=posncheck(posn1);
			arr[posn1-1]='0';
			count+=1;
			check();
			system("CLS");
		    show();
			printf("\t  %s ENTER YOUR POSITION  : ",player2);
			scanf("%d",&posn2);	
			fflush(stdin);
			posn2=posncheck(posn2);
			arr[posn2-1]='X';
			check();
		}
		
	}
	else
	{
		if(symbol=='X')
		{
			printf("\n\n\t  %s ENTER YOUR POSITION  : ",player2);
			scanf("%d",&posn2);
			fflush(stdin);
			posn2=posncheck(posn2);
			arr[posn2-1]='X';
			count+=1;
		    check();
		    system("CLS");
		    show();
			printf("\t  %s ENTER YOUR POSITION  : ",player1);
			scanf("%d",&posn1);	
			fflush(stdin);
			posn1=posncheck(posn1);
			arr[posn1-1]='0';
			check();
		}
		else
		{
			printf("\n\n\t  %s ENTER YOUR POSITION  : ",player2);
			scanf("%d",&posn2);
			fflush(stdin);
			posn2=posncheck(posn2);
			arr[posn2-1]='0';
			count+=1;
			check();
			system("CLS");
		    show();
			printf("\t  %s ENTER YOUR POSITION  : ",player1);
			scanf("%d",&posn1);	
			fflush(stdin);
			posn1=posncheck(posn1);
			arr[posn1-1]='X';
			check();
		}
	}
	 
}
int show()
{
	printf("\n\t\t\t\t\t\t\t\t\t\t\t ~~~~~~~ TIC TAC TOE GAME ~~~~~~~\n\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t       --::GAME STARTED::-- ");
	printf("\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t       %c    |   %c   |   %c  \n",arr[0],arr[1],arr[2]);
	printf("\t\t\t\t\t\t\t\t\t\t\t     -------|-------|--------\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t       %c    |   %c   |   %c   \n",arr[3],arr[4],arr[5]);
	printf("\t\t\t\t\t\t\t\t\t\t\t     -------|-------|--------\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t       %c    |   %c   |   %c   \n",arr[6],arr[7],arr[8]);
}
int check()
{
	if((arr[0]=='X' && arr[1]=='X' && arr[2]=='X')||(arr[0]=='X' && arr[3]=='X' && arr[6]=='X')||(arr[6]=='X' && arr[7]=='X' && arr[8]=='X')||(arr[2]=='X' && arr[5]=='X' && arr[8]=='X')||(arr[3]=='X' && arr[4]=='X' && arr[5]=='X')||(arr[2]=='X' && arr[4]=='X' && arr[6]=='X')||(arr[0]=='X' && arr[4]=='X' && arr[8]=='X')||(arr[1]=='X' && arr[4]=='X' && arr[7]=='X')) 
	{
	
		if((n==1)&&(symbol=='X'))
		{
			system("CLS");
			show();
			printf("\n\n\t  %s You Own The Game\n",player1);
			printf("\n\n\t\t\t\t\t\t\t\t\t\t\t       --::GAME OVER::-- ");
			exit(0);
		}
		else if((n==1)&&(symbol=='0'))
		{
			system("CLS");
			show();
			printf("\n\n\t  %s You Own The Game\n",player2);
			printf("\n\n\t\t\t\t\t\t\t\t\t\t\t       --::GAME OVER::-- ");
			exit(0);
		}
		else if((n==2)&&(symbol=='X'))
		{
			system("CLS");
			show();
			printf("\n\n\t  %s You Own The Game\n",player2);
			printf("\n\n\t\t\t\t\t\t\t\t\t\t\t       --::GAME OVER::-- ");
			exit(0);
		}
		else
		{
			system("CLS");
			show();
			printf("\n\n\t  %s You Own The Game\n",player1);
			printf("\n\n\t\t\t\t\t\t\t\t\t\t\t       --::GAME OVER::-- ");
			exit(0);
		}
	}
	else if((arr[0]=='0' && arr[1]=='0' && arr[2]=='0')||(arr[0]=='0' && arr[3]=='0' && arr[6]=='0')||(arr[6]=='0' && arr[7]=='0' && arr[8]=='0')||(arr[2]=='0' && arr[5]=='0' && arr[8]=='0')||(arr[3]=='0' && arr[4]=='0' && arr[5]=='0')||(arr[2]=='0' && arr[4]=='0' && arr[6]=='0')||(arr[0]=='0' && arr[4]=='0' && arr[8]=='0')||(arr[1]=='0' && arr[4]=='0' && arr[7]=='0') )
	{
		
		if((n==1)&&(symbol=='0'))
		{
			system("CLS");
			show();
			printf("\n\n%s You Own The Game\n",player1);
			printf("\n\n\t\t\t\t\t\t\t\t\t\t\t       --::GAME OVER::-- ");
			exit(0);
		}
		else if((n==1)&&(symbol=='X'))
		{
			system("CLS");
			show();
			printf("\n\n%s You Own The Game\n",player2);
			printf("\n\n\t\t\t\t\t\t\t\t\t\t\t       --::GAME OVER::-- ");
			exit(0);
		}
		else if((n==2)&&(symbol=='0'))
		{
			system("CLS");
			show();
			printf("\n\n%s You Own The Game\n",player2);
			printf("\n\n\t\t\t\t\t\t\t\t\t\t\t       --::GAME OVER::-- ");
			exit(0);
		}
		else
		{
			system("CLS");
			show();
			printf("\n\n%s You Own The Game\n",player1);
			printf("\n\n\t\t\t\t\t\t\t\t\t\t\t       --::GAME OVER::-- ");
			exit(0);
		}
	} 
	else 
	{
	    if(count==5)
	    {
	    	system("CLS");
			show();
	    	printf("\n\n\t  Match Drawn ");
	    	printf("\n\n\t\t\t\t\t\t\t\t\t\t\t       --::GAME OVER::-- ");
			exit(0);
			
		}
	} 
}

int posncheck(int posn)
{
	int i,value,count=0;
	char p_value=posn+'0';
	for(i=0;i<9;i++)
	{
		if(arr[i]==p_value)
		count=1;
	}
	if(count==0)
	{
		printf("\t  ENTER A VALID OPTION : ");
		scanf("%d",&value);
		posncheck(value);
	}
	else
	 value=posn;
	
	return value;
}




