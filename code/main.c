#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

int mainPart();

int enterNews()
{
	FILE *fptr;
	fptr = fopen("newsDatabase.txt", "a");
	
	char userName[100];
	char news[100];
	char source[100];
	char dta[200];
	
	system("cls");
	
	printf("\t\t\t _____________________________________________________________________\n");
	printf("\t\t\t|---------------------------- Add News -------------------------------|\n");
	printf("\t\t\t|_____________________________________________________________________|\n");
	
	printf("\n\t\t\tEnter the News: ");
	fflush(stdin);
	scanf("%[^\n]s", news);
	
	printf("\n\n\t\t\tEnter the Source: ");
	fflush(stdin);
	
	scanf("%[^\n]s", source);
	
	strcat(news,",");
	strcpy(dta, news);
	
	strcat(dta,source);
	printf("%s",dta);
	
	fprintf(fptr, "%s, %s", news, source);
	fclose(fptr);
	
	mainPart();
}

int checknews(){
	
	char userName[100];
	char news[100];
	char source[100];
	int flag=0;
	
	FILE *fptr;
	fptr = fopen("newsDatabase.txt", "r");
	
	char dbnews[100], dbsource[100];
	
	system("cls");
	
	printf("\t\t\t _____________________________________________________________________\n");
	printf("\t\t\t|--------------------------- Check News ------------------------------|\n");
	printf("\t\t\t|_____________________________________________________________________|\n");
	printf("\n\t\t\t Enter The News You Want To Check: ");
	fflush(stdin);
	scanf("%[^\n]s", &news);
	
	char line[100];
	while (fgets(line, sizeof(line), fptr)) {
            char *token = strtok(line, ",");

            if (strcmp(token, news) == 0) {
                flag = 1;

                token = strtok(NULL, ",");

                printf("\n\t\t\tThe news is correct, the Source is %s\n", token);
            }
        }

        if (flag == 0) {
            printf("\n\t\t\tNews entered is fake\n\t\t\t");
        }
        
        
	
	system("pause");
	mainPart(userName);
}

int mainPart(){
	
	int option;
	char name[100];
	//strcpy(name, userName); 
	system("cls");
	//printf("Hello");
	//printf("[ You Are Logedin as %s ]" ,name);
	
	printf("\t\t\t _____________________________________________________________________\n");
	printf("\t\t\t|-------------------------Welcome To Gullible-------------------------|\n");
	printf("\t\t\t|_____________________________________________________________________|\n");
	printf("\t\t\t|                                Index                                |\n");	
	printf("\t\t\t|     [1]. Check News                                                 |\n");
	printf("\t\t\t|     [2]. Add New                                                    |\n");
	printf("\t\t\t|     [3]. Have Suggestions ?!                                        |\n");
	printf("\t\t\t|     [4]. Go to Home                                                 |\n");
	printf("\t\t\t|     [5]. Exit                                                       |\n");
	printf("\t\t\t|_____________________________________________________________________|\n\n");
	printf("\t\t\t                     [Please Select Your Option]                      \n");
	
	scanf("\t\t\t                                    %d",&option);
	system("pause");
	
	if(option==1)
	{
		checknews();
	}
	
	if(option==2){
		enterNews();
	}
	
	if(option==3){
		feedback();
	}
	
	if(option==4){
		main();
	}
	
	if(option==5){
		
	}
	
}

int login(){
	
	FILE *fptr;
	
	fptr = fopen("userData.txt","r");
	
	int count =0;
	char userId[20], pwd[20];
	
	//char adm = "a";
   	//char vol = "v";
    //char gue = "g";
	
	char dbLoginID[100];
   	char dbPassword[100];
    char dbuserType[100];
		
	system("cls");
	printf("\t\t\t _____________________________________________________________________\n");
	printf("\t\t\t|--------------------------- Login Form ------------------------------|\n");
	printf("\t\t\t|_____________________________________________________________________|\n\n");
	
	printf("\t\t\t Enter Your User Id: ");
	scanf("%s",&userId);
	
	printf("\n\t\t\t Enter Your Password: ");
	fflush(stdin);
	scanf("%s",&pwd);
	
	if(strcmp(userId,"Admin")==0 && strcmp(userId,"Admin")==0){
		system("pause");
		//admin();
	}
	
	else{
		
	char line[100];
  	while (fgets(line, 100, fptr) != NULL) 
	  {
       	
    	sscanf(line, "%s %s %s", dbLoginID, dbPassword, dbuserType);

    
    	if (strcmp(userId, dbLoginID) == 0 && strcmp(pwd, dbPassword) == 0) {
			//printf("Login successful\n");
			/*if(strcmp(adm, dbuserType))
			{
				admin();	
			}*/
			count = count + 1;
			
			    		
			}
			
    	}
    	
    	if (count==1)
    	{
    		printf("\n\t\t\t|------------------- You Have Login Succesfuly ---------------------|\n");
			printf("\t\t\t|_____________________________________________________________________|\n");
			//printf("\n\t\t\t                    [Press any Key to Continue]");
      		
      		//printf("\t\t\t");
			//system("pause");
			fclose(fptr);
			printf("\n\t\t\t ");
			system("pause");
        	mainPart();
		}
    	
    	else
    	{	
    		printf("\n\n\t\t\t______________________________________________________________________");
    		printf("\n\n\t\t\t Incorrect userId or Password\n\n\t\t\t Please Try Again\n\n\t\t\t ");
    		system("pause");
    		login();
		}
  	
	  }
	
}

int regis(){
	
	FILE *fptr;
	
	char userId[20], pwd[20], userType[5];
	int opt;
	
	fptr = fopen("userData.txt","a");
	
	system("cls");
	printf("\t\t\t _____________________________________________________________________\n");
	printf("\t\t\t|--------------------- Registeration Form ----------------------------|\n");
	printf("\t\t\t|_____________________________________________________________________|\n\n");
	
	printf("\t\t\t Enter Your User Id: ");
	scanf("%s",&userId);
	
	printf("\n\t\t\t Enter Your Password: ");
	fflush(stdin);
	scanf("%s",&pwd);
	
	printf("\n\t\t\t State the Type of User: ");
	printf("\n\t\t\t                         [v]-> Volunteer");
	printf("\n\t\t\t                         [g]-> Guest\n\t\t\t");
	
	fflush(stdin);
	scanf("%s",&userType);
	
	fflush(stdin);
	fprintf(fptr, "%s %s %s\n",userId, &pwd, &userType);
	fclose(fptr);
	
	printf("\n\t\t\t|----------------- You Have Registered Succesfuly --------------------|\n");
	printf("\t\t\t|_____________________________________________________________________|");
	
	printf("\n\t\t\t                         <-[1]. Home\n ");
	printf("\t\t\t                         <-[2]. Login\n ");
	scanf("%d",&opt);
	if(opt==1)
	{
		main();
	}
	
	else if(opt==2)
	{
		login();
	}
	
	else
	{
		printf("\nInvalid Input");
	}

}

int relog(){
	
	int opt;
	
	system("cls");
	printf("\t\t\t _____________________________________________________________________\n");
	printf("\t\t\t|----------------- Please Login/Register to continue------------------|\n");
	printf("\t\t\t|_____________________________________________________________________|\n");
	printf("\t\t\t _____________________________________________________________________ \n");
	printf("\t\t\t|                        [1].  Login                                  |\n");	
	printf("\t\t\t|                        [2].  Register                               |\n");	
	printf("\t\t\t|_____________________________________________________________________|\n\n");
	printf("\t\t\t                     [Please Select Your Option]                      \n");
	
	scanf("%d",&opt);
	if(opt==1)
	{
		login();
	}

	
	else if(opt==2);
	{
		regis();
	}
	
}

/*int index(int opt)
{
	if(opt==1)
	{
		main();
	}
	
} */

int feedback(){
	
	int opt;
	char fb[100], username[100];
	FILE *fptr;
	fptr = fopen("feedback.txt","a");
	
	system("cls");
	
	if (fptr == NULL){
		printf("Error[001]: Required File ['feedback.txt'] Missing !");
	}
	
	else{
		printf("\t\t\t _____________________________________________________________________ \n");
		printf("\t\t\t|                      [1].  Feedback Form                            |\n");	
		printf("\t\t\t|_____________________________________________________________________|\n\n");
		printf("\t\t\t                    [ Enter Your Feedback Here ]\n");
		printf("\t\t\t_____________________________________________________________________\n\n");
		
		printf("Please Enter Your Username: ");
		fflush(stdin);
		scanf("%[^\n]s",username);
		fflush(stdin);
		printf("\nPlease Enter Your Feedback Here: ");
	    scanf("%[^\n]s", fb);
	    fprintf(fptr, "%s, %s \n", username, &fb);
	    
	    printf("\n\t\t\t---------------[ Thanks For Your Valuable Feedback ]-------------------\n");
	    printf("\t\t\t                         <-[1]. Home\n ");
		
		scanf("%d",&opt);
	    
		opt==1 ? main():printf("\n Invalid Input");	    
			
	    fclose(fptr);
		
		}
}


int info(){
	int opt;
	
	system("cls");
	printf("\t\t\t _____________________________________________________________________\n");
	printf("\t\t\t|-------------------------------About Us------------------------------|\n");
	printf("\t\t\t|_____________________________________________________________________|\n");
	printf("\t\t\t|                     [1].  What Is Gullible                          |\n");	
	printf("\t\t\t|_____________________________________________________________________|\n");
	printf("\t\t\t|      Is Gullible is an extension that is made for people who        |\n");
	printf("\t\t\t|      are continuously using social media as their No.1 source       |\n");
	printf("\t\t\t|      of latest news. Gullible help these people differntiate        |\n");
	printf("\t\t\t|      between REAL NEWS and FAKE NEWS, by providing accurate         |\n");
	printf("\t\t\t|      data with actual sources beside the posts.                     |\n");
	printf("\t\t\t|_____________________________________________________________________|\n");
	printf("\t\t\t ++-----------------------------------------------------------------++\n");	
	printf("\t\t\t _____________________________________________________________________\n");
	printf("\t\t\t|                       [3].  About Me                                |\n");	
	printf("\t\t\t|_____________________________________________________________________|\n");
	printf("\t\t\t|      Hi! I am Anorak the developer of Gullibe                       |\n");
	printf("\t\t\t|      Currently I am studying Btech in CS                            |\n");
	printf("\t\t\t|_____________________________________________________________________|\n");
	printf("\t\t\t ++-----------------------------------------------------------------++\n\n");
	printf("\t\t\t                         <-[1]. Home\n ");
	printf("\t\t\t                [2]. Wanna Leave Some Feedback\n ");
	scanf("%d",&opt);
	
	if(opt==1)
	{
		main();
	}
	
	else if(opt==2)
	{
		feedback();
	}
	
	else {
		printf("Invalid Input");
	}
}

int buy(){
	system("cls");
	printf("\n\t\t\t|_________________________________________________|\n");
	printf("\t\t\t|      To Puchase Gullibe Please visit            |\n");
	printf("\t\t\t|                gullible.hopto.org               |\n");
	printf("\t\t\t|_________________________________________________|\n");
}

int main(){
	
	int opt;
	
	system("cls");
	printf("\t\t\t _____________________________________________________________________\n");
	printf("\t\t\t|-------------------------Welcome To Gullible-------------------------|\n");
	printf("\t\t\t|_____________________________________________________________________|\n");
	printf("\t\t\t|                                Index                                |\n");	
	printf("\t\t\t|     [1]. What Is Gullible                                           |\n");
	printf("\t\t\t|     [2]. Login                                                      |\n");
	printf("\t\t\t|     [3]. Buy Gullible                                               |\n");
	printf("\t\t\t|     [4]. Have Suggestions ?!                                        |\n");
	printf("\t\t\t|     [5]. Exit                                                       |\n");
	printf("\t\t\t|_____________________________________________________________________|\n\n");
	printf("\t\t\t                     [Please Select Your Option]                      \n");
	
	scanf("%d",&opt);
	
	if(opt==1)
	{
		info();
	}
	
	else if(opt==2)
	{
		relog();
	}
	
	else if(opt==3){
		buy();
	}
		
	else if(opt==4)
	{
		feedback();
	}
	
	return 0;
}
