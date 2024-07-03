#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<unistd.h>
#include <time.h>

int letters();
void lettercount();
void wordcount();
int words();
void reading_scoreboard();

int main()
{
	int choice, choice2, i;
	for(i=1; i>0; i++)
	{
		printf("1- START GAME\n2- SCORE BOARD\n3- HOW TO PLAY\n4- ABOUT US\nPress 0 to exit");
		printf("\nEnter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 0:
				exit(0);
				break;
			case 1:
				printf("1- Letters Per Minute\n2- Words Per Minute\nEnter your choice: ");
				scanf("%d",&choice2);
				
				switch(choice2){
					case 1://Letters per minute
						lettercount();
						printf("\n1-Continue\n2-Exit\nEnter your choice: ");
						scanf("%d",&choice);
						if(choice==1)
						{
							system("cls");
							continue;
						}
						else
						break;
					case 2://Words per minute
						wordcount();
						printf("\n1-Continue\n2-Exit\nEnter your choice: ");
						scanf("%d",&choice);
						if(choice==1)
						{
							system("cls");
							continue;
						}
						else
						break;
					default:
						printf("\nInvalid choice!!\n");
						printf("\n\n1-Go back to menu\n2-Exit\nEnter your choice: ");
						scanf("%d",&choice);
						if(choice==1)
						{
							system("cls");
							continue;
						}
						else
						break;
				}
				
				break;
			case 2:
				system("cls");
				reading_scoreboard();  //function to show the scoreboard
				printf("\n\n1-Go back to menu\n2-Exit\nEnter your choice: ");
				scanf("%d",&choice);
				if(choice==1)
				{
					system("cls");
					continue;
				}
				else
				break;
			case 3:
				system("cls");
				printf("LEVEL 1:\n\nRandom words will display on\nyour screen for 1 minute and\nyou will have to type\nas many of them as possible.");
				printf("\n1-Continue\n2-Exit\nEnter your choice: ");
				scanf("%d",&choice);
				if(choice==1)
				{
					system("cls");
					continue;
				}
				else
				break;
			case 4:
				printf("We are aspiring CS students,\nenabling people to get better at typing.\n1.22K-4678 Huzkail Waseem\n2.22K-0500 Anas Saleem");
				printf("\n1-Continue\n2-Exit\nEnter your choice: ");
				scanf("%d",&choice);
				if(choice==1)
				{
					system("cls");
					continue;
				}
				else
				break;
			default:
				system("cls");
				printf("Please enter a valid choice.\n");
				sleep(2);
				system("cls");
				continue;		
		}
		break;
	}
}

 //function to start game of letters per minute
 int letters(){
	system("cls");
	char e,word[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
	int upper=0,lower=51,x,start,end,words=0;
	time_t now=time(NULL);
	start=now;
	end=now+5;
	printf("\t----------ENTER THE FOLLOWING CHARCTERS----------\n");
	while(start<end){
		start=time(NULL);
		x=rand()%(upper-lower+1)+upper;
		printf("\r\t\t\t\t%c",word[x]);
		e=getch();
		if(e==word[x]){
			words++;
		}
	}
	return words;
}

void lettercount(){			//function to display letter results
	int lpm=letters();
	int choice;
	FILE *ptr;
	system("cls");
	
	if(lpm>=0&&lpm<=15)
	{
		printf("You are a turtle.\nYou can type %d letters per minute.\n",lpm);
	
		ptr=fopen("scoreboard.txt","a");
		fprintf(ptr," %d",lpm);
		fclose(ptr);
	}
	else if(lpm>=16&&lpm<=30)
	{
		printf("Your typing speed is below average.\nYou can type %d letters per minute.\n",lpm);
		ptr=fopen("scoreboard.txt","a");
		fprintf(ptr," %d",lpm);
		fclose(ptr);
	}
	else if(lpm>=31&&lpm<=60)
	{
		printf("Your typing speed is average.\nYou can type %d letters per minute.\n",lpm);
		ptr=fopen("scoreboard.txt","a");
		fprintf(ptr," %d",lpm);
		fclose(ptr);
	}
	else if(lpm>=61&&lpm<=90)
	{
		printf("Your typing speed is above average.\nYou can type %d letters per minute.\n",lpm);
		ptr=fopen("scoreboard.txt","a");
		fprintf(ptr," %d",lpm);
		fclose(ptr);
	}
	else if(lpm>=91&&lpm<=119)
	{
		printf("Your typing speed is fast.\nYou can type %d letters per minute.\n",lpm);
		ptr=fopen("scoreboard.txt","a");
		fprintf(ptr," %d",lpm);
		fclose(ptr);
	}
	else
	{
		printf("Your typing speed is extraordinarily fast.\nYou can type %d letters per minute.\n",lpm);
		ptr=fopen("scoreboard.txt","a");
		fprintf(ptr," %d",lpm);
		fclose(ptr);
	}
}


int words(){ 				//function to start game of words per minute
    system("cls");
    char e[42][20], CommonWords[42][20] = {
        "defense", "employee", "financial", "ability", "back", "blue", "center",
        "commercial", "debate", "capital", "decision", "current", "easy", "family",
        "forward", "health", "hope", "involve", "little", "moment", "newspaper",
        "organization", "practice", "purpose", "rest", "serious", "space", "take",
        "thousand", "voice", "whatever", "yourself", "weight", "treatment", "themselves",
        "stock", "according", "analysis", "become", "blood", "campaign"
    };
    int upper=41, lower=0, x, words=0;
    int start, end;
    time_t now = time(NULL);
    start = now;
    end =now+5;
    printf("\t----------ENTER THE FOLLOWING WORDS----------\n");
    while(start < end){
        start = time(NULL);
        x=rand()%(lower-upper+1)+lower;
        printf("\r\t\t\t\t%s\n", CommonWords[x]); // print the word
        scanf("%s", e[x]); // read the input
        if(strcmp(e[x], CommonWords[x]) == 0){ // compare strings
            words++;
        }
    }
    return words;
}


void wordcount(){		//function to display word results
	int wpm=words();
	int choice;
	FILE *ptr;
	system("cls");
	
	if(wpm>=0&&wpm<=15)
	{
		printf("You are a turtle.\nYou can type %d letters per minute.\n",wpm);
	
		ptr=fopen("scoreboard.txt","a");
		fprintf(ptr," %d",wpm);
		fclose(ptr);
	}
	else if(wpm>=16&&wpm<=30)
	{
		printf("Your typing speed is below average.\nYou can type %d letters per minute.\n",wpm);
		ptr=fopen("scoreboard.txt","a");
		fprintf(ptr," %d",wpm);
		fclose(ptr);
	}
	else if(wpm>=31&&wpm<=60)
	{
		printf("Your typing speed is average.\nYou can type %d letters per minute.\n",wpm);
		ptr=fopen("scoreboard.txt","a");
		fprintf(ptr," %d",wpm);
		fclose(ptr);
	}
	else if(wpm>=61&&wpm<=90)
	{
		printf("Your typing speed is above average.\nYou can type %d letters per minute.\n",wpm);
		ptr=fopen("scoreboard.txt","a");
		fprintf(ptr," %d",wpm);
		fclose(ptr);
	}
	else if(wpm>=91&&wpm<=119)
	{
		printf("Your typing speed is fast.\nYou can type %d letters per minute.\n",wpm);
		ptr=fopen("scoreboard.txt","a");
		fprintf(ptr," %d",wpm);
		fclose(ptr);
	}
	else
	{
		printf("Your typing speed is extraordinarily fast.\nYou can type %d letters per minute.\n",wpm);
		ptr=fopen("scoreboard.txt","a");
		fprintf(ptr," %d",wpm);
		fclose(ptr);
	}
	
}

 //function to read the scoreboard
 void reading_scoreboard(){
 	FILE *fptr;
 	fptr=fopen("scoreboard.txt","r");
 	int board,i=1;
 	
 	if (fptr==NULL){
 		printf("\nYou have not played any game.\nPlay atleast one game to generate scoreboard.");
	 }
	else{
		printf("\n\t\t\tHERE IS THE SCOREBOARD\n");
 		while(fscanf(fptr,"%d",&board)==1){
 			printf("\n\t\t\tNumber %d user's score is %d",i,board);
 			i++;
		}
	fclose(fptr);
  	}
 }
