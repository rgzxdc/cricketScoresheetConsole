#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<string.h>
#include<time.h>

COORD coord = {0,0};
void gotoxy (int x, int y){
    coord.X = x; coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int currentInnings;
void ppt();
void view();
void date();
void menu();
void inputGameDetails();
void inputPlayer();
void match();


struct gameDetails {
    char competitionName[50];
    char venue[50];
    char matchBetween[20];
    char versus[20];
    char tossWonBy[20];
    char electedTo[15];
    char date[15];
} gameDetails;

struct matchDetails {
    int innings;
    int totalRuns;
    float overPlayed;
    float runRate;
} inningsA, inningsB;

struct batsMan {
    char name[30];
    int runs;
    int balls;
    char status[10];
    int fours;
    int sixes;
} batsManTeamA[11], batsManTeamB[11];

struct bowler {
    char name[30];
    float overs;
    int runs;
    int wicket;
    int maiden;
    float Economy;
    int extra;
} bowlerTeamA[8], bowlerTeamB[8];
    
    
    
int main() {
    
    menu();
    return 0;
}


void inputGameDetails() {
    ppt();
    gotoxy(16,0);
    gets(gameDetails.competitionName);
    gotoxy(47,0);
    gets(gameDetails.venue);
    gotoxy(16,2);
    gets(gameDetails.matchBetween);
    gotoxy(47,2);
    gets(gameDetails.versus);
    gotoxy(16,4);
    gets(gameDetails.tossWonBy);
    gotoxy(47,4);
    gets(gameDetails.electedTo);
    int n;
    gotoxy(16,6);
    scanf("%d", &n);
    if(n == 1) {
        inningsA.innings = 1;
        currentInnings = 1;
    }
    else {
        currentInnings = 2;
        inningsB.innings = 2;
    }
    fflush(stdin);
    gotoxy(47,6);
    gets(gameDetails.date);
    
    inputPlayer();
    return;
}

void menu() {
    system("cls");
    int n;
    printf("\n\n\t\t\t\t\tMENU:\n");
    printf("\n\n\n\t\t\t\t1.New scoresheet:\n");
    printf("\t\t\t\t2.View scoresheet:\n");
    printf("\t\t\t\t3.Exit:\n\t\t");
    printf("\n\t\t\tYour Choise: ");
    scanf("%d", &n);
    fflush(stdin);
    switch(n) {
        case 1: inputGameDetails(); 
                gotoxy(90,6);
                printf("Game Details Saved");
                gotoxy(90,7);
                printf("Press Anything to go Menu");
                getch(); menu(); break;
                
        case 2: view();
                gotoxy(90, 10);
                printf("Press anything to menu");
                getch(); menu(); break;
        case 3: exit(0); break;
        default: menu();
    }
}

void inputPlayer() {
    if(currentInnings == 1) {
        
        for(int i=0; i<11; i++){
            gotoxy(13,9+(i+1));
            gets(batsManTeamA[i].name);
            gotoxy(39,9+(i+1));
            scanf("%d",&batsManTeamA[i].runs);
            gotoxy(53,9+(i+1));
            scanf("%d",&batsManTeamA[i].balls);
            gotoxy(65,9+(i+1));
            scanf("%d",&batsManTeamA[i].fours);
            gotoxy(75,9+(i+1));
            scanf("%d",&batsManTeamA[i].sixes);
            fflush(stdin);
        }
        match();
        
        for(int i=0; i<8; i++){
            gotoxy(11,25+(i+1));
            gets(bowlerTeamB[i].name);
            gotoxy(37,25+(i+1));
            scanf("%f",&bowlerTeamB[i].overs);
            gotoxy(46,25+(i+1));
            scanf("%d",&bowlerTeamB[i].maiden);
            gotoxy(52,25+(i+1));
            scanf("%d",&bowlerTeamB[i].runs);
            gotoxy(58,25+(i+1));
            scanf("%d",&bowlerTeamB[i].wicket);
            gotoxy(68,25+(i+1));
            scanf("%d",&bowlerTeamB[i].extra);
            gotoxy(75,25+(i+1));
            scanf("%f",&bowlerTeamB[i].Economy);
            fflush(stdin);
        }

        gotoxy(90,6);
        printf("Press c to continue innigs 2");
        if(getch() == 'c' || getch() == 'C') {
            currentInnings = 2;
            inputPlayer();
        }
    }
    
    else {
        
        for(int i=0; i<11; i++){
            gotoxy(13,9+(i+1));
            gets(batsManTeamB[i].name);
            gotoxy(39,9+(i+1));
            scanf("%d",&batsManTeamB[i].runs);
            gotoxy(53,9+(i+1));
            scanf("%d",&batsManTeamB[i].balls);
            gotoxy(65,9+(i+1));
            scanf("%d",&batsManTeamB[i].fours);
            gotoxy(75,9+(i+1));
            scanf("%d",&batsManTeamB[i].sixes);
            fflush(stdin);
        }
        
        match();
        
        for(int i=0; i<8; i++){
            gotoxy(11,25+(i+1));
            gets(bowlerTeamA[i].name);
            gotoxy(37,25+(i+1));
            scanf("%f",&bowlerTeamA[i].overs);
            gotoxy(46,25+(i+1));
            scanf("%d",&bowlerTeamA[i].maiden);
            gotoxy(52,25+(i+1));
            scanf("%d",&bowlerTeamA[i].runs);
            gotoxy(58,25+(i+1));
            scanf("%d",&bowlerTeamA[i].wicket);
            gotoxy(68,25+(i+1));
            scanf("%d",&bowlerTeamA[i].extra);
            gotoxy(75,25+(i+1));
            scanf("%f",&bowlerTeamA[i].Economy);
            fflush(stdin);
        }
    }
    return;
}

void match() {
    int a = 0;
    for(int i = 0; i<12; i++) {
        a = a + batsManTeamA[i].runs;
    }
    inningsA.totalRuns = a;
    a = 0;
    for(int i = 0; i<11; i++) {
        a = a + batsManTeamB[i].runs;
    }
    inningsB.totalRuns = a;
    a = 0;
    for(int i = 0; i<8; i++) {
        a = a + bowlerTeamA[i].overs;
    }
    inningsA.overPlayed = a;
    a = 0;
    for(int i = 0; i<8; i++) {
        a = a + bowlerTeamA[i].overs;
    }
    inningsB.overPlayed = a;
    a = 0;
    inningsA.runRate = (inningsA.totalRuns/inningsA.overPlayed);
    inningsB.runRate = (inningsB.totalRuns/inningsB.overPlayed);
}

void ppt() {
    
    system("cls");
    
    //game_details
    gotoxy(0,0);
    printf("Competition:");
    gotoxy(35,0);
    printf("Venue:");
    gotoxy(0,2);
    printf("Match Between:");
    gotoxy(35,2);
    printf("Versus:");
    gotoxy(0,4);
    printf("Toss won by:");
    gotoxy(35,4);
    printf("Elected to:");
    gotoxy(0,6);
    printf("Inning of:");
    gotoxy(35,6);
    printf("Date:");
 
    //Batting
    gotoxy(0,8);
    printf("%c",179);
    gotoxy(8,8);
    printf("Batsmanname");
    gotoxy(0,10);
    for(int i=0; i<11; i++)
    printf("%cBatsman %d:\n",179,i+1);
    gotoxy(39,8);
    printf("Runs");
    gotoxy(53,8);
    printf("Balls");
    gotoxy(65,8);
    printf("4s");
    gotoxy(75,8);
    printf("6s");
    
    //matchDetails
    gotoxy(25,22);
    printf("Total Runs: ");
    gotoxy(45,22);
    printf("Over: ");
    gotoxy(60,22);
    printf("Run Rate: ");
    
    //Bowling
    gotoxy(5,24);
    printf("Bowlers");
    gotoxy(37,24);
    printf("Over");
    gotoxy(44,24);
    printf("Maiden");
    gotoxy(52,24);
    printf("Run");
    gotoxy(58,24);
    printf("Wicket");
    gotoxy(68,24);
    printf("Extra");
    gotoxy(75,24);
    printf("Econ");
    gotoxy(0,26);
    for(int i=0; i<8; i++)
    printf("%cBowler %d:\n",179,i+1);
    
    //Table
    gotoxy(0,3);
    for(int i=0; i<79; i++)
        printf("%c",205);
    gotoxy(0,1);
    for(int i=0; i<79; i++)
        printf("%c",205);
    gotoxy(0,5);
    for(int i=0; i<79; i++)
        printf("%c",205);
    gotoxy(35,0);
    for (int i=0; i<33; i++)
    {
    gotoxy(34,i);
        printf("%c",182);
    }
    gotoxy(0,7);
    for(int i=0; i<79; i++)
        printf("%c",205);
    gotoxy(0,21);
    for(int i=0; i<79; i++)
        printf("%c",205);
    gotoxy(0,9);
    for(int i=0; i<79; i++)
        printf("%c",205);
    gotoxy(0,23);
    for (int i=0; i<79; i++)
        printf("%c",205);
    gotoxy(0,25);
    for (int i=0; i<79; i++)
        printf("%c",205);
    gotoxy(0,34);
    for (int i=0; i<79; i++)
        printf("%c",205);
    gotoxy(61,10);
    for(int i=0; i<11; i++)
    {
        printf("%c",179);
        gotoxy(61,10+(i+1));
    }
    gotoxy(71,10);
    for(int i=0; i<11; i++)
    {
        printf("%c",179);
        gotoxy(71,10+(i+1));
    }
    gotoxy(49,10);
    for(int i=0; i<11; i++)
    {
        printf("%c",179);
        gotoxy(49,10+(i+1));
    }
    gotoxy(0,40);
    for(int i=0;i<79;i++)
    {
        printf("%c",205);
    }
}

void view() {
    ppt();
    gotoxy(88, 6);
    printf("Result of Innins: ");
    gotoxy(105,6);
    int a;
    scanf("%d",&a);
    if(a==1)
        currentInnings = 1;
    else if(a==2)
        currentInnings = 2;
                
    gotoxy(16,0);
    printf("%s",gameDetails.competitionName);
    gotoxy(47,0);
    printf("%s",gameDetails.venue);
    gotoxy(16,2);
    printf("%s",gameDetails.matchBetween);
    gotoxy(47,2);
    printf("%s",gameDetails.versus);
    gotoxy(16,4);
    printf("%s",gameDetails.tossWonBy);
    gotoxy(47,4);
    printf("%s",gameDetails.electedTo);
    gotoxy(47,6);
    printf("%s",gameDetails.date);
    
    if(currentInnings == 1) {
        
        gotoxy(16,6);
        printf("1st");
        for(int i=0; i<11; i++){
            gotoxy(13,9+(i+1));
            printf("%s",batsManTeamA[i].name);
            gotoxy(39,9+(i+1));
            printf("%d",batsManTeamA[i].runs);
            gotoxy(53,9+(i+1));
            printf("%d",batsManTeamA[i].balls);
            gotoxy(65,9+(i+1));
            printf("%d",batsManTeamA[i].fours);
            gotoxy(75,9+(i+1));
            printf("%d",batsManTeamA[i].sixes);
        }
        
        for(int i=0; i<8; i++){
            gotoxy(11,25+(i+1));
            printf("%s",bowlerTeamB[i].name);
            gotoxy(37,25+(i+1));
            printf("%0.0f",bowlerTeamB[i].overs);
            gotoxy(44,25+(i+1));
            printf("%d",bowlerTeamB[i].maiden);
            gotoxy(52,25+(i+1));
            printf("%d",bowlerTeamB[i].runs);
            gotoxy(58,25+(i+1));
            printf("%d",bowlerTeamB[i].wicket);
            gotoxy(68,25+(i+1));
            printf("%d",bowlerTeamB[i].extra);
            gotoxy(75,25+(i+1));
            printf("%0.1f",bowlerTeamB[i].Economy);
        }
        
    gotoxy(36,22);
    printf("%d",inningsA.totalRuns);
    gotoxy(50,22);
    printf("%.0f",inningsA.overPlayed);
    gotoxy(70,22);
    printf("%.01f",inningsA.runRate);

    }
    
    else {
        
        gotoxy(16,6);
        printf("2nd");
        
        for(int i=0; i<11; i++){
            gotoxy(13,9+(i+1));
            printf("%s",batsManTeamB[i].name);
            gotoxy(39,9+(i+1));
            printf("%d",batsManTeamB[i].runs);
            gotoxy(53,9+(i+1));
            printf("%d",batsManTeamB[i].balls);
            gotoxy(65,9+(i+1));
            printf("%d",batsManTeamB[i].fours);
            gotoxy(75,9+(i+1));
            printf("%d",batsManTeamB[i].sixes);
        }
        
        for(int i=0; i<8; i++){
            gotoxy(11,25+(i+1));
            printf("%s",bowlerTeamA[i].name);
            gotoxy(37,25+(i+1));
            printf("%0.0f",bowlerTeamA[i].overs);
            gotoxy(44,25+(i+1));
            printf("%d",bowlerTeamA[i].maiden);
            gotoxy(52,25+(i+1));
            printf("%d",bowlerTeamA[i].runs);
            gotoxy(58,25+(i+1));
            printf("%d",bowlerTeamA[i].wicket);
            gotoxy(68,25+(i+1));
            printf("%d",bowlerTeamA[i].extra);
            gotoxy(75,25+(i+1));
            printf("%0.1f",bowlerTeamA[i].Economy);
        }
        
    gotoxy(36,22);
    printf("%d",inningsB.totalRuns);
    gotoxy(50,22);
    printf("%.0f",inningsB.overPlayed);
    gotoxy(70,22);
    printf("%.01f",inningsB.runRate);

    
    }
    
}