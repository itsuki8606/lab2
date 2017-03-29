#include<iostream>
#include<math.h>
#include<stdio.h>
#include"compute.h"
using namespace std;
int main()
{
	Elo elo;
	int f,n,now,filelength;
	int K,RA,RB;
	float* score;
	FILE *fp1=NULL;
	fp1=fopen("file.in","r");
	fseek(fp1,0,SEEK_END);
	filelength=ftell(fp1);
	rewind(fp1);
	char temp[filelength];
	n=0;
	for(f=0;f<filelength;f++)
	{
		fscanf(fp1,"%c",&temp[f]);
		if(temp[f]=='\n')
		{
			n++;
		}
	}
	fclose(fp1);
	fp1=fopen("file.in","r");
	fscanf(fp1,"%d %d %d",&K,&RA,&RB);
	for(f=0;f<n;f++)
	{
		fscanf(fp1,"%f",&score[f]);
	}
	FILE *fp2=NULL;
	fp2=fopen("file.out","w");
	fprintf(fp2,"%d %d\n",RA,RB);
	for(now=0;now<n;now++)
	{
		elo.compute(now,score);
		fprintf(fp2,"%d %d\n",elo.getRA(),elo.getRB());
	}
	fclose(fp1);
	fclose(fp2);
	return 0;
}


