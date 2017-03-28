#include<iostream>
#include<math.h>
#include<stdio.h>
using namespace std;
int K,RA,RB,n=0;
float EA,EB;
int compute(int f,float* score)
{
	float A,B;
	A=(float)(RB-RA)/400;
	B=(float)(RA-RB)/400;
	EA=(float)(1/(1+pow(10,A)));
	EB=(float)(1/(1+pow(10,B)));
	RA=(int)(RA+K*(score[f]-EA)+0.5);
	RB=(int)(RB+K*(1-score[f]-EB)+0.5);
}
int main()
{
	int f,filelength;
	FILE *fp1=NULL;
	fp1=fopen("file.in","r");
	fseek(fp1,0,SEEK_END);
	filelength=ftell(fp1);
	rewind(fp1);
	char temp[filelength];
	for(f=0;f<filelength;f++)
	{
		fscanf(fp1,"%c",&temp[f]);
		if(temp[f]=='\n')
		{
			n++;
		}
	}
	n--;	
	fclose(fp1);
	fp1=fopen("file.in","r");
	fscanf(fp1,"%d %d %d",&K,&RA,&RB);
	float score[n];
	for(f=0;f<n;f++)
	{
		fscanf(fp1,"%f",&score[f]);
	}	
	FILE *fp2=NULL; 
	fp2=fopen("file.out","w");
	fprintf(fp2,"%d %d\n",RA,RB);
	for(f=0;f<n;f++)
	{
		compute(f,score);
		fprintf(fp2,"%d %d\n",RA,RB);
	}
	fclose(fp1);
	fclose(fp2);
	return 0;
} 
