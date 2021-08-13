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


FILE *fp;
int currentInnings = 1;
char filename[50];
char extension[] = ".txt";
char directory[60] = "File//";

void printGameDetails();
void printCurrentInnings();
int checkIfFileExists(const char *filename);
void checkFileWrite();
void checkFileRead();
void fileNameMaker();
void fileWrite();
void fileRead();
void ppt();
void view();
void date();
void menu();
void inputGameDetails();
void inputPlayer();
void match();
void printMatchResult();

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
    system("cls");
    gotoxy(50,10);
    printf("You are at Main Function");
    getch();
    return 0;
}

void menu() {
    system("cls");
    int n;
    printf("\n\n\t\t\t\tCricket Score Sheet\n");
    printf("\n\n\n\t\t\t\t1.New scoresheet:\n");
    printf("\t\t\t\t2.View scoresheet:\n");
    printf("\t\t\t\t3.Exit:\n\t\t");
    printf("\n\t\t\tEnter your choice: \033[0;m ");
    scanf("%d", &n);
    fflush(stdin);
    switch(n) {
        case 1: inputGameDetails(); 
                gotoxy(90,6);
                printf("Press Y to Save ");
                getch();
                checkFileWrite();
                gotoxy(90,12);
                printf("Game DATA Saved");
                gotoxy(90,13);
                printf("Press Any Key To Main Menu");                
                getch(); menu(); break;
                
        case 2: 
                checkFileRead();
                break;

        case 3: exit(0); break;
        default:
                gotoxy(36,10);
                printf("Invalid Choice!~ Please try again.");
                menu();
                break;
    }
    
    return;
}

void inputGameDetails() {
    ppt();
    printCurrentInnings();
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
    fflush(stdin);
    gotoxy(47,6);
    gets(gameDetails.date);
    inputPlayer();
    return;
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
            
            printMatchResult();
        }

        gotoxy(90,6);
        printf("Press c to Continue Innigs 2 ");
        if(getch() == 'c' || getch() == 'C') {
            currentInnings = 2;
            system("cls");
            ppt();
            printGameDetails();
            printCurrentInnings();
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
            
            printMatchResult();
        }
    }
    currentInnings = 1;
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
    inningsB.overPlayed = a;
    
    a = 0;
    for(int i = 0; i<8; i++) {
        a = a + bowlerTeamB[i].overs;
    }
    inningsA.overPlayed = a;
    
    a = 0;
    inningsA.runRate = (inningsA.totalRuns/inningsA.overPlayed);
    inningsB.runRate = (inningsB.totalRuns/inningsB.overPlayed);
}

void fileNameMaker() {   
    strcat(filename,extension);
    strcat(directory,filename);
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
    system("cls");
    ppt();
                    
    printGameDetails();
    printCurrentInnings();
    
    if(currentInnings == 1) {
        
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
        
    printMatchResult();

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
        
        printMatchResult();
    
    }
    
    
    gotoxy(90, 10);
                printf("Press n to view Next Innings or AnyKey to Menu");
                if(getch() == 'n') {
                    currentInnings = 2;
                    view();
                }
                currentInnings = 1;
                menu();
}

void printCurrentInnings() {
    gotoxy(16,6);
    if(currentInnings == 1) {
        inningsA.innings = 1;
        printf("1st");
    }
    else {
        printf("2st");
        inningsB.innings = 2;
    }
}

void fileWrite() {

    fp = fopen(directory,"a+");
    
    rewind(fp);
    fwrite(&gameDetails,sizeof(gameDetails),1,fp);
    
    
    fseek(fp,0,SEEK_END);
    fwrite(&inningsA,sizeof(inningsA),1,fp);
    
    fseek(fp,0,SEEK_END);
    for(int i=0; i<11; i++)
        fwrite(&batsManTeamA[i],sizeof(batsManTeamA[0]),1,fp);
    
    fseek(fp,0,SEEK_END);
    for(int i=0; i<8; i++)
        fwrite(&bowlerTeamB[i],sizeof(bowlerTeamB[0]),1,fp);

    
    fseek(fp,0,SEEK_END);
    fwrite(&inningsB,sizeof(inningsB),1,fp);

    fseek(fp,0,SEEK_END);
    for(int i=0; i<11; i++)
        fwrite(&batsManTeamB[i],sizeof(batsManTeamB[0]),1,fp);

    fseek(fp,0,SEEK_END);
    for(int i=0; i<8; i++)
        fwrite(&bowlerTeamA[i],sizeof(bowlerTeamA[0]),1,fp);
    fclose(fp);
    
    return;
}
void fileRead() {
    
    fp = fopen(directory,"r");
    strcpy(directory,"File//");
    
    rewind(fp);
    fread(&gameDetails,sizeof(gameDetails),1,fp);
    
    fread(&inningsA,sizeof(inningsA),1,fp);
    
    for(int i=0; i<11; i++)
        fread(&batsManTeamA[i],sizeof(batsManTeamA[0]),1,fp);
    
    for(int i=0; i<8; i++)
        fread(&bowlerTeamB[i],sizeof(bowlerTeamB[0]),1,fp);


    fread(&inningsB,sizeof(inningsB),1,fp);

    for(int i=0; i<11; i++)
        fread(&batsManTeamB[i],sizeof(batsManTeamB[0]),1,fp);

    for(int i=0; i<8; i++)
        fread(&bowlerTeamA[i],sizeof(bowlerTeamA[0]),1,fp);
    fclose(fp);
    return;
}

void printGameDetails() {
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
}
void printMatchResult() {
    
    match();
    if(currentInnings==1) {
        gotoxy(36,22);
        printf("%d",inningsA.totalRuns);
        gotoxy(50,22);
        printf("%.0f",inningsA.overPlayed);
        gotoxy(70,22);
        printf("%.01f",inningsA.runRate);
    }
    else {
        gotoxy(36,22);
        printf("%d",inningsB.totalRuns);
        gotoxy(50,22);
        printf("%.0f",inningsB.overPlayed);
        gotoxy(70,22);
        printf("%.01f",inningsB.runRate);
    }

}

void checkFileRead() {
    system("cls");
    
    gotoxy(45,4);
    printf("Cricket Scoresheet");
    
    gotoxy(34,7);
    printf("Enter the filename You Want to Open: ");
    gotoxy(72,7);
    scanf("%s",filename);
    fileNameMaker();
    
    if(checkIfFileExists(directory)) {
        
        gotoxy(34,9);
        printf("File Found");
        gotoxy(34,10);
        Sleep(1000);
        printf("Please Wait");
        Sleep(1000);
        printf(".");
        Sleep(1000);
        printf(".");
        Sleep(1000);
        printf(".");
        fileRead();
        view();
    }
    else {
        gotoxy(34,9);
        printf("File does not Exists, Check filename Agian");
        gotoxy(34,11);
        printf("Press m to Menu Or ENTER to Check Again");
        if(getch() == 'm') 
            menu();
        checkFileRead();
    }
    
    return;
    
}
void checkFileWrite() {
    
    gotoxy(90,7);
    printf("Enter the filename: ");
    gotoxy(110,7);
    scanf("%s",filename);
    fileNameMaker();
    
    if(checkIfFileExists(directory)) {
        gotoxy(90,8);
        printf("File Already Exits.");
        gotoxy(90,10);
        printf("Press ENTER to Try Different filename");
        gotoxy(90,11);
        printf("Or Press c to Cancel Save ");
        if(getch() == 'c') 
            menu();
        checkFileWrite();
    }
    
    else {
    fileWrite();
        return;
    }
    
}

int checkIfFileExists(const char * filename) {
    FILE *file;
    if (file = fopen(filename, "r"))
    {
        fclose(file);
        return 1;
    }
    
    return 0;
}