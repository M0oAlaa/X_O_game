/*******************************************************************/
/******************** Date: 23/12/2021 *****************************/
/******************** Project: X-O Game ****************************/
/******************** Author: Mohamed Alaa *************************/
/******************** Version: 1.0 *********************************/
/*******************************************************************/
#include<stdio.h>

/*Initialize some global data types*/
char arr[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};//Initialize the main array (Rows, Culomns)
char checkarr[9];
int i,j; //For loop counters

/*Declaration of some functions*/
void printNewXO(char *x_play,char *O_play);/*Function to print X&O after each play*/
char CheckTheWinner(void);/*Function to check the winner*/

void main(void)
{
	/*Iocal data types*/
	int NumOfGameTurns;
	char x_play[1],O_play[1];
	
	/*Display the game in the beginning*/
	printf("----------------------------");
	printf("\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("|   %c   ",arr[i][j]);
		}
		printf("|");
		printf("\n");
		printf("----------------------------");
		printf("\n");
	}
	
	/*the game turn 8 rounds*/
	for(NumOfGameTurns=0;NumOfGameTurns<4;NumOfGameTurns++)
	{
		char CheckWinStatus=0;
		printf("Please select the number where x Player wants to play");
		printf("Player (x):");
		scanf(" %s",&x_play);//X player play
		/*check if the player choise is available or not*/
		if(*x_play>='1' && *x_play<='9'){
			/*check if this place is taken or not*/
			for(i=0;checkarr[i]!='\0';i++)
			{
				*O_play='0';
				/*if yes*/
				if((checkarr[i]==*x_play) || (checkarr[i]==*O_play))
				{
					printf("This place is already taken.\nPlease Try agian.\n");
					printf("Player (x):");
					scanf(" %s",&x_play);
					i=-1;// to check from the beginning of the checkarr
				}
				else{}
			}
		}
		/*if player choise is not exist*/
		else{
			/*loop till make correct choise*/
			while(1)
			{
				printf("This choise is not exist.\nPlease try again\n");
				printf("Player (x):");
				scanf(" %s",&x_play);
				if(*x_play>='1'&&*x_play<='9'){break;}
				else{}
			}
		}
		printNewXO(x_play,O_play);/*print new game after x&o players play*/
		CheckWinStatus=CheckTheWinner();/*check if any of them won*/
			/*if yes stop the game*/
			if(CheckWinStatus==1)
			{
				break;
			}
			/*if no continue*/
			else{
			
			}
			
		printf("Please select the number where o Player wants to play");
		printf("Player (O):");
		scanf(" %s",&O_play);/*O player plays*/
		/*check if the player choise is available or not*/
		if(*O_play>='1' &&* O_play<='9')
		{
			/*check if this place is taken or not*/
			for(j=0;checkarr[j]!='\0';j++)
			{
				*x_play='0';
				/*if yes*/
				if((checkarr[j]==*x_play) || (checkarr[j]==*O_play))
				{
					printf("This place is already taken.\nPlease Try agian.\n");
					printf("Player (O):");
					scanf(" %s",&O_play);
					j=-1;// to check from the beginning of the checkarr
				}
			}
		}
		/*if player choise is not exist*/
		else
		{
			/*loop till make correct choise*/
			while(1)
			{
				printf("This choise is not exist.\nPlease try again\n");
				printf("Player (O):");
				scanf(" %s",&O_play);
				if(*O_play>='1'&&*O_play<='9'){break;}
				else{}
			}
		}
		printNewXO(x_play,O_play);/*print new game after x&o players play*/
		CheckWinStatus=CheckTheWinner();/*check if any of them won*/
			/*if yes stop the game*/
			if(CheckWinStatus==1)
			{
				break;
			}
			/*if no continue*/
			else{
			
			}
	}
}

void printNewXO(char *x_play,char *O_play)
{
	static char checkarrcounter=0;
	printf("----------------------------");
	printf("\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(arr[i][j]==*x_play)
			{
				checkarr[checkarrcounter]=arr[i][j];
				arr[i][j]='X';
				printf("|   X   ");
				checkarrcounter++;
			}
			else if(arr[i][j]==*O_play)
			{
				checkarr[checkarrcounter]=arr[i][j];
				arr[i][j]='O';
				printf("|   O   ");
				checkarrcounter++;
			}
			else
			{
				printf("|   %c   ",arr[i][j]);
			}
		}
		printf("|");
		printf("\n");
		printf("----------------------------");
		printf("\n");
	}
}

char CheckTheWinner(void)
{
	char ErrorCheck=0;
	if((arr[0][0]==arr[0][1]) && (arr[0][0]==arr[0][2]))
	{
		if(arr[0][0]=='X')
		{
			printf("X player is winner.\n");
			ErrorCheck=1;
		}
		else if(arr[0][0]=='O')
		{
			printf("O player is winner.\n");
			ErrorCheck=1;
		}
	}
	else if((arr[0][0]==arr[1][0]) && (arr[0][0]==arr[2][0]))
	{
		if(arr[0][0]=='X')
		{
			printf("X player is winner.\n");
			ErrorCheck=1;
		}
		else if(arr[0][0]=='O')
		{
			printf("O player is winner.\n");
			ErrorCheck=1;
		}
	}
	else if((arr[0][1]==arr[1][1]) && (arr[0][1]==arr[2][1]))
	{
		if(arr[0][1]=='X')
		{
			printf("X player is winner.\n");
			ErrorCheck=1;
		}
		else if(arr[0][1]=='O')
		{
			printf("O player is winner.\n");
			ErrorCheck=1;
		}
	}
	else if((arr[0][2]==arr[1][2]) && (arr[0][2]==arr[2][2]))
	{
		if(arr[0][2]=='X')
		{
			printf("X player is winner.\n");
			ErrorCheck=1;
		}
		else if(arr[0][2]=='O')
		{
			printf("O player is winner.\n");
			ErrorCheck=1;
		}
	}
	else if((arr[1][0]==arr[1][1]) && (arr[1][0]==arr[1][2]))
	{
		if(arr[1][0]=='X')
		{
			printf("X player is winner.\n");
			ErrorCheck=1;
		}
		else if(arr[1][0]=='O')
		{
			printf("O player is winner.\n");
			ErrorCheck=1;
		}
	}
	else if((arr[2][0]==arr[2][1]) && (arr[2][0]==arr[2][2]))
	{
		if(arr[2][0]=='X')
		{
			printf("X player is winner.\n");
			ErrorCheck=1;
		}
		else if(arr[2][0]=='O')
		{
			printf("O player is winner.\n");
			ErrorCheck=1;
		}
	}
	else if((arr[0][0]==arr[1][1]) && (arr[0][0]==arr[2][2]))
	{
		if(arr[0][0]=='X')
		{
			printf("X player is winner.\n");
			ErrorCheck=1;
		}
		else if(arr[0][0]=='O')
		{
			printf("O player is winner.\n");
			ErrorCheck=1;
		}
	}
	else if((arr[0][2]==arr[1][1]) && (arr[0][2]==arr[2][0]))
	{
		if(arr[0][2]=='X')
		{
			printf("X player is winner.\n");
			ErrorCheck=1;
		}
		else if(arr[0][2]=='O')
		{
			printf("O player is winner.\n");
			ErrorCheck=1;
		}
	}
	else
	{
		printf("Draw Game.")
		ErrorCheck=1;
	}
	return ErrorCheck;
}