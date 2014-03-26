#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>

int score=0;
int length=3;

int flevel()
{
	int sublevel=5,sub_score=0;;
	char arr[20]={'a','s','d','f','j','k','l',';','A','S','D','F','J','K','L','G','H','\0'};
    char tmp[10];
	char tmp2[10];clock_t start=clock();
	while(sublevel--)
	{
		int j=0;
		for(int i=0;i<length;i++)
		{
		    tmp[i]=arr[rand()%17];
		    tmp[++j]=' ';
		}
		tmp[j]=NULL;
		puts("");
		printf("\t%s\n\t",tmp);
		scanf("%s",tmp2);
		if(strcmp(tmp2,tmp)==0){
			sub_score++;score++;}
		else
			puts("Wrong Answer!");
	}
	length++;
	printf("Score: %d",sub_score);
	printf("\nTime = %.2f secondes\n", (double)(clock()-start)/CLOCKS_PER_SEC);
return 0;
}
int writefile(char name[],double &a)
{
	FILE *fp;
		fp=fopen("Result.txt","a+");
		fputs("============================",fp);fflush(fp);
		fprintf(fp,"\nName: %s",name);
		fprintf(fp,"\nTotal Score: %d",score);
		fprintf(fp,"\nTotal time = %.2f secondes\n", a);
		fputs("============================",fp);
		fclose(fp);
		return 0;
}
int main()
{
    puts("==========================");
    puts(" Beginner's Typing Test 1 ");
    puts("==========================");
    puts("LEVELS 5 : SCORE (5*5)=25");
	puts("==========================");
    int cases;
    printf("How Many Examinee(s)?: ");
    scanf("%d",&cases);
    while(cases--)
    {
		char name[10];score=0;length=3;
		puts("");puts("");
		puts("===============================");
		printf("Enter Your Name: ");
		scanf("%s",name);
		puts("===============================");
		printf("\nGet Ready %s !!!\n",name);
		system("pause");
        int level=5,levelcase=1;
		clock_t start=clock();
        while(levelcase<=level)
        {
            printf("\n\tLEVEL: %d\n",levelcase++);
			puts("============================");
            flevel();
        }
		puts("");puts("");
		puts("============================");
		printf("Total Score: %d\n",score);
		double a=(double)(clock()-start)/CLOCKS_PER_SEC;
		printf("\nTotal time = %.2f secondes\n", a);
		puts("============================\n\n");
        writefile(name,a);system("pause");
    }
	system("pause"); return 0;
}
