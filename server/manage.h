#include"server.h"

#define PORT 12345 
#define MAXSIGNUP 10
#define MAXNAME 10

typedef struct{
	char pip;
	int i;
	int s;		/*s=0--->离线	s=1--->在线      s=2--->游戏中      s=-1--->未注册*/
	char user[MAXNAME];
	char passwd[MAXNAME];
}UP;

class Manage{

	
public:
	Server server;
	Server pipe;
	UP up[MAXSIGNUP];
	int count;
	
	
	Manage();
	int start();
//	void process(int i,Manage* thi);


};
