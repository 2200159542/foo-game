#include"manage.h"
#include<thread>
#include<unistd.h>
#include<iostream>
#include<cstring>

Manage::Manage():server(PORT),pipe(PORT+1),count(0){

	server.Bind();
	server.Listen();
	pipe.Bind();
	pipe.Listen();
	memset(this->up,-1,sizeof(UP)*MAXSIGNUP);
}


static int check(char* s,Manage* thi){
	//用户名存在
	for(int i=0;i<thi->count;i++) if(!strncmp(thi->up[i].user,s,10)) return i+1;

	//用户名不存在
	return 0;
}

static int checkp(int i,char* s,Manage* thi){
	if(!strncmp(thi->up[i].passwd,s,10)) return 1;
	return 0;
}

static int login(int i,Manage* thi,int& ss){

	int s=-1;

	if(!thi->server.Receive(i)){std::cout<<"receive error!\n";return 0;}
l1:
	if(!strncmp((const char*)thi->server.player[i].getbuf(),"user",4)){
		if(!thi->server.Send("OK",i)) {std::cout<<"send error!";return 0;}
		
		memset(thi->server.player[i].getbuf(),0,PLAYBUFSIZE);
		
		if(!thi->server.Receive(i)){std::cout<<"receive error!\n";return 0;}
				/*   process user  */
				s=check(thi->server.player[i].getbuf(),thi);
				if(!s){
					if(!thi->server.Send("NO",i)) {std::cout<<"send error!";return 0;}
					if(!thi->server.Receive(i)){std::cout<<"receive error!\n";return 0;}
					if(!strncmp((const char*)thi->server.player[i].getbuf(),"return",6)) return 2;
					else goto l1;
				}
				
				if(thi->up[s-1].s==1){
					if(!thi->server.Send("EXIST",i)) {std::cout<<"send error!";return 0;}
					if(!thi->server.Receive(i)){std::cout<<"receive error!\n";return 0;}
					if(!strncmp((const char*)thi->server.player[i].getbuf(),"return",6)) return 2;
					else goto l1;
				
				}
				
		if(!thi->server.Send("OK",i)) {std::cout<<"send error!";return 0;}
	}
					
	if(!thi->server.Receive(i)){std::cout<<"receive error!\n";return 0;}
l2:
	if(!strncmp((const char*)thi->server.player[i].getbuf(),"passwd",6)){
		if(!thi->server.Send("OK",i)) {std::cout<<"send error!";return 0;}
		
		memset(thi->server.player[i].getbuf(),0,PLAYBUFSIZE);
		
		if(!thi->server.Receive(i)){std::cout<<"receive error!\n";return 0;}
				
					/*   process passwd   */
					if(!checkp(s-1,thi->server.player[i].getbuf(),thi)){
					if(!thi->server.Send("NO",i)) {std::cout<<"send error!";return 0;}
					if(!thi->server.Receive(i)){std::cout<<"receive error!\n";return 0;}
					if(!strncmp((const char*)thi->server.player[i].getbuf(),"return",6)) return 2;
					else goto l2;
					}
					
					thi->up[s-1].s=1;
					ss=s-1;
					
		if(!thi->server.Send("OK",i)) {std::cout<<"send error!";return 0;}
		return 1;
	}
	return 0;
	
}

static int signup(int i,Manage* thi,int& ss){
	
	char user[10];

	if(!thi->server.Receive(i)){std::cout<<"receive error!\n";return 0;}
l1:
	if(!strncmp((const char*)thi->server.player[i].getbuf(),"user",4)){
		if(!thi->server.Send("OK",i)) {std::cout<<"send error!";return 0;}
		
		memset(thi->server.player[i].getbuf(),0,PLAYBUFSIZE);
		
		if(!thi->server.Receive(i)){std::cout<<"receive error!\n";return 0;}
		
				/*   process user  */
				strncpy(user,thi->server.player[i].getbuf(),10);
				if(check(user,thi)){
					if(!thi->server.Send("NO",i)) {std::cout<<"send error!";return 0;}
					if(!thi->server.Receive(i)){std::cout<<"receive error!\n";return 0;}
					if(!strncmp((const char*)thi->server.player[i].getbuf(),"return",6)) return 2;
					else goto l1;
				}
		if(!thi->server.Send("OK",i)) {std::cout<<"send error!";return 0;}
	}
				
	if(!thi->server.Receive(i)){std::cout<<"receive error!\n";return 0;}
	if(!strncmp((const char*)thi->server.player[i].getbuf(),"passwd",4)){
		if(!thi->server.Send("OK",i)) {std::cout<<"send error!";return 0;}
		
		memset(thi->server.player[i].getbuf(),0,PLAYBUFSIZE);
		
		if(!thi->server.Receive(i)){std::cout<<"receive error!\n";return 0;}
					/*   process passwd   */
					strncpy(thi->up[thi->count].passwd,thi->server.player[i].getbuf(),10);
					strncpy(thi->up[thi->count].user,user,10);
					thi->up[thi->count].s=1;
					ss=thi->count;
					thi->count++;
					
		if(!thi->server.Send("OK",i)) {std::cout<<"send error!";return 0;}
		return 1;
	}
	return 2;
	
}

static int process1(int i,Manage* thi,int& ss){
	
	while(1){
		if(!thi->server.Receive(i)){std::cout<<"receive error!\n";return 0;}
		
		if(!thi->server.player[i].getmsize()) return 0;
	
		if(!strncmp((const char*)thi->server.player[i].getbuf(),"login",4)){
			if(!thi->server.Send("OK",i)) {std::cout<<"send error!";return 0;}
			int s = login(i,thi,ss);
			if(s==1) return 1;
			else if(s==2) continue;
			else return 0;
		}
		
		if(!strncmp((const char*)thi->server.player[i].getbuf(),"signup",4)){
			if(!thi->server.Send("OK",i)) {std::cout<<"send error!";return 0;}
			int s = signup(i,thi,ss);
			if(s==2) continue;
			else if(s==1) return 1;
			else return 0;
		}
	}
}

static void print(int n,int j,Manage* thi){

	
	char f4[2]={0,0};
	f4[0] = (char)thi->count;
	if(!thi->server.Receive(n)) std::cout<<"receive error!\n";
	if(!strncmp((const char*)thi->server.player[n].getbuf(),"count",5))
		if(!thi->server.Send((const char*)f4,n)) std::cout<<"send error!";
	
	for(int i=0;i<f4[0];i++){
		
		if(!thi->server.Receive(n)) std::cout<<"receive error!\n";
		if(!strncmp((const char*)thi->server.player[n].getbuf(),"data",4));
		
		int s0 = thi->up[i].s;
		
		if(s0==-1){
			char f1[MAXNAME+2]="1";
			thi->server.Send((const char*)f1,n);
		}else if(s0==0){
			if(i!=j){
				char f2[MAXNAME+4]="2";
				strncat(f2,thi->up[i].user,MAXNAME);
				thi->server.Send((const char*)f2,n);
			}else {
				char f2[MAXNAME+4]="2$ ";
				strncat(f2,thi->up[i].user,MAXNAME);
				thi->server.Send((const char*)f2,n);
			}
		}else if(s0==1){
			if(i!=j){
				char f3[MAXNAME+4]="3";
				strncat(f3,thi->up[i].user,MAXNAME);
				thi->server.Send((const char*)f3,n);
			}else {
				char f3[MAXNAME+4]="3$ ";
				strncat(f3,thi->up[i].user,MAXNAME);
				thi->server.Send((const char*)f3,n);
			}		
		}else if(s0==2){
			if(i!=j){
				char f4[MAXNAME+4]="4";
				strncat(f4,thi->up[i].user,MAXNAME);
				thi->server.Send((const char*)f4,n);
			}else {
				char f4[MAXNAME+4]="4$ ";
				strncat(f4,thi->up[i].user,MAXNAME);
				thi->server.Send((const char*)f4,n);
			}		
		}

	}
}

static int Game(int i,int j,Manage* thi){
	
	char s[2]={0,0};
	while(1){
		thi->pipe.Receive(j);
		if(thi->pipe.player[j].getmsize()==0) return 0;
//		std::cout<<"一号已下棋\n";
		if(!strncmp((const char*)thi->pipe.player[j].getbuf(),"over",4)) return 1;
		s[0]=thi->pipe.player[j].getbuf()[0];
		thi->server.Send((const char*)s,i);
//		std::cout<<"已发送！！\n";
		thi->server.Receive(i);
		if(thi->server.player[i].getmsize()==0) return 0;
		if(!strncmp((const char*)thi->server.player[i].getbuf(),"over",4))return 1;
//		std::cout<<"二号已下棋\n";
		s[0]=thi->server.player[i].getbuf()[0];
		thi->pipe.Send((const char*)s,j);
	}
}


static int process2(int i,int s0,Manage* thi){

l2:
	while(1){
		if(!thi->server.Receive(i)) std::cout<<"receive error!\n";
		
		if(!thi->server.player[i].getmsize()) return 0;
		
		if(!strncmp((const char*)thi->server.player[i].getbuf(),"puser",5)){
			if(!thi->server.Send("OK",i)) std::cout<<"send error!";
		
			print(i,s0,thi);
			continue;
			
		}else if(!strncmp((const char*)thi->server.player[i].getbuf(),"game",4)){
			if(!thi->server.Send("OK",i)) std::cout<<"send error!";
			
		l1:
			if(!thi->server.Receive(i)) std::cout<<"receive error!\n";
			if(!thi->server.player[i].getmsize()) return 0;
			if(!strncmp((const char*)thi->server.player[i].getbuf(),"return",6)){
//				thi->up[s0].s = 1;
				continue;
			}
			
			char n = thi->server.player[i].getbuf()[0];
			n-=1;
		
			if(n==(char)s0)	{thi->server.Send("YOU",i);
//				thi->up[s0].s = 1;
				goto l1;
			}
			if(thi->up[n].s!=1) {thi->server.Send("NO",i);goto l1;}
			
			thi->server.Send("OK",i);
			thi->server.Receive(i);
			
			thi->up[s0].s = 2;
			thi->up[n].pip = s0;
			
			while(1){
				sleep(1);
				if(thi->up[n].pip > 0) continue;
				else if(thi->up[n].pip==-2/*同意邀请*/){
					thi->server.Send("agree",i);
					thi->up[n].s = 2;
					Game(i,thi->up[n].i,thi);
					thi->pipe.Close(thi->up[n].i);
					thi->up[s0].s = 1;
					thi->up[n].s = 1;
					thi->up[n].pip = -1;
					goto l2;
				}
				else if(thi->up[n].pip==-3/*不同意邀请*/){
					thi->server.Send("disagree",i);
					thi->up[s0].s = 1;
//					thi->pipe.Close(thi->up[n].i);
					thi->up[n].pip = -1;
					goto l2;
				}
			}
		
		}
	}
}

static void Pipe(int i,int s,Manage* thi){

l1:
	thi->pipe.Accept(i);
	
	if(!thi->pipe.Receive(i)) std::cout<<"receive error!\n";
	if(!strncmp((const char*)thi->pipe.player[i].getbuf(),"link",4))
		if(!thi->pipe.Send("OK",i)) std::cout<<"send error!";
	
	while(1){
		sleep(1);
		int j = thi->up[s].pip;
		if(j < 0||j==s) continue;
		
		thi->pipe.Send((const char*)thi->up[j].user,i);
		if(!thi->pipe.Receive(i)) std::cout<<"receive error!\n";
		if(thi->pipe.player[i].getmsize()==0) {thi->up[s].pip = -3;return;}
		
		if(!strncmp((const char*)thi->pipe.player[i].getbuf(),"agree",5)){
			thi->up[s].pip = -2;
//			thi->pipe.Close(i);
			goto l1;
		}
		else {
			thi->up[s].pip = -3;
			thi->pipe.Close(i);
			goto l1;
		}
		
	}
	

}

static void process(int i,Manage* thi){
	if(!thi->server.Receive(i)) std::cout<<"receive error!\n";
	if(!strncmp((const char*)thi->server.player[i].getbuf(),"link",4))
		if(!thi->server.Send("OK",i)) std::cout<<"send error!";
		
	int s=-1;
	
	if(process1(i,thi,s)&&thi->up[s].s==1&&thi->up[s].i==-1){
	
		thi->up[s].i=i;
		
		std::thread(Pipe,i,s,thi).detach();
		
		process2(i,s,thi);
		
	}
//	print(thi);
	
	thi->server.Close(i);
	thi->pipe.Close(i);
	thi->server.player[i].setfd(-1);
	if(thi->up[s].s==1) thi->up[s].s=0;
	thi->up[s].i=-1;
}


int Manage::start(){

	Manage* p = this;
	
	for(int i=0,j=0;j<3;i++){
	
		if(i==MAXREQUEST+1) {i=0;j++;}
		if(this->server.player[i].getfd()!=-1) continue;
		
		this->server.Accept(i);
		
		std::thread(process,i,p).detach();
	}

	return 0;
}

