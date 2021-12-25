/*******************************************************************/
/******************** Date: 23/12/2021 *****************************/
/******************** Project: X-O Game ****************************/
/******************** Author: Mohamed Alaa *************************/
/******************** Version: 1.0 *********************************/
/*******************************************************************/
#include<stdio.h>
#include<stdint.h>

/*Initialize some global data types*/
uint8_t gu8_arr[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};//Initialize the main array (Rows, Culomns)
uint8_t gu8_checkarr[9];
uint8_t gu8_flag=0;

uint8_t gu8_i,gu8_j; //For loop counters

/*Declaration of some functions*/
uint8_t printNewXO(uint8_t *u8arr_x_play,uint8_t *u8arr_O_play);/*Function to print X&O after each play*/
uint8_t CheckTheWinner(uint8_t u8_NumOfGameTurns);/*Function to check the winner*/

void main(void)
{
	/*Iocal data types*/
	uint8_t u8_NumOfGameTurns;
	uint8_t u8_CheckWinStatus=0;
	uint8_t u8arr_x_play[1],u8arr_O_play[1];
	
	/*Display the game in the beginning*/
	printf("-------------------------");
	printf("\n");
	for(gu8_i=0;gu8_i<3;gu8_i++)//raws looping
	{
		for(gu8_j=0;gu8_j<3;gu8_j++)//culomns looping
		{
			printf("|   %c   ",gu8_arr[gu8_i][gu8_j]);
		}
		printf("|");
		printf("\n");
		printf("-------------------------");
		printf("\n");
	}
	
	/*the game turn 8 rounds*/
	for(u8_NumOfGameTurns=0;u8_NumOfGameTurns<4;u8_NumOfGameTurns++)
	{
		printf("Please select the number where x Player wants to play");
		printf("Player (x):");
		scanf(" %s",&u8arr_x_play);//X player play
		/*check if the player choise is available or not*/
		if(*u8arr_x_play>='1' && *u8arr_x_play<='9'){
			/*check if this place is taken or not*/
			for(gu8_i=0;gu8_checkarr[gu8_i]!='\0';gu8_i++)
			{
				*u8arr_O_play='0';
				/*if yes*/
				if((gu8_checkarr[gu8_i]==*u8arr_x_play) || (gu8_checkarr[gu8_i]==*u8arr_O_play))
				{
					printf("This place is already taken.\nPlease Try agian.\n");
					printf("Player (x):");
					scanf(" %s",&u8arr_x_play);
					gu8_i=-1;// to check from the beginning of the checkarr
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
				scanf(" %s",&u8arr_x_play);
				if(*u8arr_x_play>='1'&&*u8arr_x_play<='9'){break;}
				else{}
			}
		}
		printNewXO(u8arr_x_play,u8arr_O_play);/*print new game after x&o players play*/
		u8_CheckWinStatus=CheckTheWinner(u8_NumOfGameTurns);/*check if any of them won*/
			/*if yes stop the game*/
			if(u8_CheckWinStatus==1)
			{
				break;
			}
			/*if no continue*/
			else{
			
			}
			
		printf("Please select the number where o Player wants to play");
		printf("Player (O):");
		scanf(" %s",&u8arr_O_play);/*O player plays*/
		/*check if the player choise is available or not*/
		if(*u8arr_O_play>='1' &&* u8arr_O_play<='9')
		{
			/*check if this place is taken or not*/
			for(gu8_j=0;gu8_checkarr[gu8_j]!='\0';gu8_j++)
			{
				*u8arr_x_play='0';
				/*if yes*/
				if((gu8_checkarr[gu8_j]==*u8arr_x_play) || (gu8_checkarr[gu8_j]==*u8arr_O_play))
				{
					printf("This place is already taken.\nPlease Try agian.\n");
					printf("Player (O):");
					scanf(" %s",&u8arr_O_play);
					gu8_j=-1;// to check from the beginning of the checkarr
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
				scanf(" %s",&u8arr_O_play);
				if(*u8arr_O_play>='1'&&*u8arr_O_play<='9'){break;}
				else{}
			}
		}
		printNewXO(u8arr_x_play,u8arr_O_play);/*print new game after x&o players play*/
		u8_CheckWinStatus=CheckTheWinner(u8_NumOfGameTurns);/*check if any of them won*/
			/*if yes stop the game*/
			if(u8_CheckWinStatus==1)
			{
				break;
			}
			/*if no continue*/
			else{
			
			}
	}
	if(gu8_flag==0)
	{
		printf("Player (x):");
		scanf(" %s",&u8arr_x_play);
		printNewXO(u8arr_x_play,u8arr_O_play);/*print new game after x&o players play*/
		u8_CheckWinStatus=CheckTheWinner(u8_NumOfGameTurns);/*check if any of them won*/
	}
	else{}
}

uint8_t printNewXO(uint8_t *u8arr_x_play,uint8_t *u8arr_O_play)
{
	uint8_t u8_Errorcheck=0;
	if((*u8arr_x_play==0) && (*u8arr_O_play==0))
	{
		u8_Errorcheck=1;
	}
	else
	{
		static uint8_t checkarrcounter=0;
	printf("-------------------------");
	printf("\n");
	for(gu8_i=0;gu8_i<3;gu8_i++)
	{
		for(gu8_j=0;gu8_j<3;gu8_j++)
		{
			if(gu8_arr[gu8_i][gu8_j]==*u8arr_x_play)
			{
				gu8_checkarr[checkarrcounter]=gu8_arr[gu8_i][gu8_j];
				gu8_arr[gu8_i][gu8_j]='X';
				printf("|   X   ");
				checkarrcounter++;
			}
			else if(gu8_arr[gu8_i][gu8_j]==*u8arr_O_play)
			{
				gu8_checkarr[checkarrcounter]=gu8_arr[gu8_i][gu8_j];
				gu8_arr[gu8_i][gu8_j]='O';
				printf("|   O   ");
				checkarrcounter++;
			}
			else
			{
				printf("|   %c   ",gu8_arr[gu8_i][gu8_j]);
			}
		}
		printf("|");
		printf("\n");
		printf("-------------------------");
		printf("\n");
	}
	}
	return u8_Errorcheck;
}

uint8_t CheckTheWinner(uint8_t u8_NumOfGameTurns)
{
	uint8_t u8_ErrorCheck=0;
	if((gu8_arr[0][0]==gu8_arr[0][1]) && (gu8_arr[0][0]==gu8_arr[0][2]))
	{
		if(gu8_arr[0][0]=='X')
		{
			printf("X player is winner.\n");
			u8_ErrorCheck=1;
			gu8_flag=1;
		}
		else if(gu8_arr[0][0]=='O')
		{
			printf("O player is winner.\n");
			u8_ErrorCheck=1;
			gu8_flag=1;
		}
	}
	else if((gu8_arr[0][0]==gu8_arr[1][0]) && (gu8_arr[0][0]==gu8_arr[2][0]))
	{
		if(gu8_arr[0][0]=='X')
		{
			printf("X player is winner.\n");
			u8_ErrorCheck=1;
			gu8_flag=1;
		}
		else if(gu8_arr[0][0]=='O')
		{
			printf("O player is winner.\n");
			u8_ErrorCheck=1;
			gu8_flag=1;
		}
	}
	else if((gu8_arr[0][1]==gu8_arr[1][1]) && (gu8_arr[0][1]==gu8_arr[2][1]))
	{
		if(gu8_arr[0][1]=='X')
		{
			printf("X player is winner.\n");
			u8_ErrorCheck=1;
			gu8_flag=1;
		}
		else if(gu8_arr[0][1]=='O')
		{
			printf("O player is winner.\n");
			u8_ErrorCheck=1;
			gu8_flag=1;
		}
	}
	else if((gu8_arr[0][2]==gu8_arr[1][2]) && (gu8_arr[0][2]==gu8_arr[2][2]))
	{
		if(gu8_arr[0][2]=='X')
		{
			printf("X player is winner.\n");
			u8_ErrorCheck=1;
			gu8_flag=1;
		}
		else if(gu8_arr[0][2]=='O')
		{
			printf("O player is winner.\n");
			u8_ErrorCheck=1;
			gu8_flag=1;
		}
	}
	else if((gu8_arr[1][0]==gu8_arr[1][1]) && (gu8_arr[1][0]==gu8_arr[1][2]))
	{
		if(gu8_arr[1][0]=='X')
		{
			printf("X player is winner.\n");
			u8_ErrorCheck=1;
			gu8_flag=1;
		}
		else if(gu8_arr[1][0]=='O')
		{
			printf("O player is winner.\n");
			u8_ErrorCheck=1;
			gu8_flag=1;
		}
	}
	else if((gu8_arr[2][0]==gu8_arr[2][1]) && (gu8_arr[2][0]==gu8_arr[2][2]))
	{
		if(gu8_arr[2][0]=='X')
		{
			printf("X player is winner.\n");
			u8_ErrorCheck=1;
			gu8_flag=1;
		}
		else if(gu8_arr[2][0]=='O')
		{
			printf("O player is winner.\n");
			u8_ErrorCheck=1;
			gu8_flag=1;
		}
	}
	else if((gu8_arr[0][0]==gu8_arr[1][1]) && (gu8_arr[0][0]==gu8_arr[2][2]))
	{
		if(gu8_arr[0][0]=='X')
		{
			printf("X player is winner.\n");
			u8_ErrorCheck=1;
			gu8_flag=1;
		}
		else if(gu8_arr[0][0]=='O')
		{
			printf("O player is winner.\n");
			u8_ErrorCheck=1;
			gu8_flag=1;
		}
	}
	else if((gu8_arr[0][2]==gu8_arr[1][1]) && (gu8_arr[0][2]==gu8_arr[2][0]))
	{
		if(gu8_arr[0][2]=='X')
		{
			printf("X player is winner.\n");
			u8_ErrorCheck=1;
			gu8_flag=1;
		}
		else if(gu8_arr[0][2]=='O')
		{
			printf("O player is winner.\n");
			u8_ErrorCheck=1;
			gu8_flag=1;
		}
	}
	else if(u8_NumOfGameTurns==4)
	{
		printf("Draw Game.");
		u8_ErrorCheck=1;
	}
	return u8_ErrorCheck;
}