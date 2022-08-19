

extern const char table[23][33];


extern const char piece1[5][7];

extern const char piece2[5][7];

extern const char block[5][7];

#define SIGN(x1,y1) x=x1*10+2+x1,y=y1*7+1+y1;  


class Chess{

private:
	char tab[23][33];
	char exist[9];
	int isWin();
	int check(int, int);
public:
	Chess();
	~Chess();
	
	int play(int, int);
	void showTab();
	void showState(int);
	int state();
};

