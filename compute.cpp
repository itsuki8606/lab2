#include<math.h>
#include"compute.h"
using namespace std;
Elo::Elo(){
	
}
void Elo::setK(int K)
{
	this->K=K;
}
void Elo::setRA(int RA)
{
	this->RA=RA;
}
void Elo::setRB(int RB)
{
	this->RB=RB;
}
void Elo::compute(int now,float* score)
{
	float A,B,EA,EB;
	A=(float)(RB-RA)/400;
	B=(float)(RA-RB)/400;
	EA=(float)(1/(1+pow(10,A)));
	EB=(float)(1/(1+pow(10,B)));
	RA=(int)(RA+K*(score[now]-EA)+0.5);
	RB=(int)(RB+K*(1-score[now]-EB)+0.5);
}
int Elo::getK()
{
	return K;
}
int Elo::getRA()
{
	return RA;
}
int Elo::getRB()
{
	return RB;
}

