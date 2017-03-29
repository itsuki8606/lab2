using namespace std;
class Elo {
public:
	Elo();
	int n,now;
	float* score;
	void setK(int K);
	void setRA(int RA);
	void setRB(int RB);
	int getK();
	int getRA();
	int getRB();
	void compute(int now,float* score);
private:
	int K,RA,RB;
};

