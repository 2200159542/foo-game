#include<iostream>
#include<cstring>
#include<unistd.h>
#include<thread>
#include<mutex>
#include"frame.h"
#include"ui.h"



static char Drew[24][65]={
{42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42},
{42,32,32,32,32,42,42,42,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,42},
{42,32,32,42,42,42,42,42,42,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,42,42,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,'h','a','p','p','y',32,32,32,32,42},
{42,32,42,42,42,42,42,42,42,42,32,32,32,32,32,32,32,32,32,32,42,42,42,32,32,32,32,32,32,32,32,32,32,32,32,32,42,42,42,42,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,'t','i','m','e','!',32,32,32,32,42},
{42,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,42,42,42,42,42,42,42,32,32,32,32,32,32,32,32,32,32,32,32,42,42,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,42},
{42,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,42,42,42,42,42,42,42,42,42,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,42},
{42,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,42},
{42,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,42},
{42,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,42},
{42,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,42},
{42,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,42},
{42,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,42},
{42,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,42},
{42,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,42},
{42,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,42,42,42,42,42,32,32,32,32,42},
{42,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,42,42,42,42,42,42,42,32,32,32,42},
{42,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,42,42,42,42,42,32,32,32,32,42},
{42,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,42,42,42,32,32,32,32,32,42},
{42,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,42,42,42,42,42,42,42,42,32,32,42},
{42,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,42,42,32,42,42,42,32,42,42,32,32,42},
{42,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,42,32,32,42,32,42,32,32,32,32,32,42},
{42,32,32,32,32,42,42,42,42,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,42,42,32,42,42,32,32,32,32,42},
{42,42,42,42,42,42,42,42,42,42,42,42,42,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,42,42,32,42,42,32,32,32,32,42},
{42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42},
};


static const char H[6][7]={
{42,42,32,32,32,42,42},
{42,42,32,32,32,42,42},
{42,42,42,42,42,42,42},
{42,42,32,32,32,42,42},
{42,42,32,32,32,42,42},
{42,42,32,32,32,42,42},
};

static const char E[6][7]={
{42,42,42,42,42,42,42},
{42,42,32,32,32,32,32},
{42,42,42,42,42,42,42},
{42,42,32,32,32,42,42},
{42,42,32,32,32,32,32},
{42,42,42,42,42,42,42},
};

static const char L[6][7]={
{42,42,32,32,32,32,32},
{42,42,32,32,32,32,32},
{42,42,32,32,32,32,32},
{42,42,32,32,32,32,32},
{42,42,42,42,42,42,42},
{42,42,42,42,42,42,42},
};

static const char O[6][7]={
{32,32,42,42,42,32,32},
{32,42,32,32,32,42,32},
{42,42,32,32,32,42,42},
{42,42,32,32,32,42,42},
{32,42,32,32,32,42,32},
{32,32,42,42,42,32,32},
};

UI::UI():client(IPADDR,PORT){
	if(this->client.link()) 
		if(this->client.Send("link"))
			if(this->client.Receive()&&strncmp("OK",(const char*)this->client.getbuf(),2)) 
				std::cout<<"???????????????\n";
}

static int Game(int i,int j,Client& jp);

int y0(int i) {return (3-i)*(1-i)+8;}

int x0(int i) {return 3+(i-1)*7+(i-1)*2;}

void pen(int ch){
	
	for(int i=0,y=y0(ch);i<6;i++,y++)
		for(int j=0,x=x0(ch);j<7;j++,x++)
			if(ch==1)
				Drew[y][x]=H[i][j];
			else if(ch==2)
				Drew[y][x]=E[i][j];
			else if(ch==3||ch==4)
				Drew[y][x]=L[i][j];
			else if(ch==5)
				Drew[y][x]=O[i][j];	
}


void UI::showBegin(){
	
	char* p;
	
	for(int n=1;n<6;n++){
		system("cls");
		pen(n);
		p = (char*) Drew;
		for(int i=0;i<24;i++,p+=65){
			write(1,p,65);
			write(1,"\n",1);
		}
		sleep(1);
	}
	
	write(1,"Loading",7);
	sleep(1);
	write(1," .",2);
	sleep(1);
	write(1," .",2);
	sleep(1);
	write(1," .",2);
	sleep(1);

}


static int inputSite(){

	int i;
	std::cin>>i;
	if(i>9||i<1) return 0;
	
	return i;

}

int UI::inputClass(){

	int i;
	std::cin>>i;
	if(i>3||i<1) return 0;

	return i;
}

int UI::inputOption(int n){
	
	char i;
	std::cout<<"????????????";
l1:
	std::cin>>i;
	if(i=='q'||i=='Q') return 400;
	if(i>64&&i<n+65) return i-64;
	else if(i>96&&i<n+97) return i-96;
	else {
		std::cout<<"????????????????????????:";
		goto l1;
	}
}


void UI::showMenu_1(){
	
	system("cls");
	std::cout<<"*************************************************************\n";
	std::cout<<"*                                                           *\n";
	std::cout<<"*                                                           *\n";
	std::cout<<"*                                                           *\n";
	std::cout<<"*                                                           *\n";
	std::cout<<"??                   A ---- ??????                             ??\n";
	std::cout<<"*                                                           *\n";
	std::cout<<"*                                                           *\n";
	std::cout<<"??                   B ---- ??????                             ??\n";
	std::cout<<"*                                                           *\n";
	std::cout<<"*                                                           *\n";
	std::cout<<"*                                                           *\n";
	std::cout<<"*                                                           *\n";
	std::cout<<"*                                                           *\n";
	std::cout<<"*                                                           *\n";
	std::cout<<"*************************************************************\n";

}

int UI::pUser(){
	char count;
	if(this->client.Send("puser"))
		if(this->client.Receive()&&!strncmp("OK",(const char*)this->client.getbuf(),2)){}
		
	if(this->client.Send("count"))
		if(this->client.Receive())
			count=this->client.getbuf()[0];
	
	
	std::cout<<"\n****************************************\n";
	std::cout<<"*??????		?????????		   ??????*\n";
	
	for(char i=0;i<count;i++){
		
		memset(this->client.getbuf(),0,BUFSIZE);
		
		if(this->client.Send("data"))
			if(this->client.Receive()){
				if(!strncmp("2",(const char*)this->client.getbuf(),1)){
					std::cout<<"*"<<(int)i<<"		";
					std::cout<<(this->client.getbuf()+1)<<"		   "<<"??????*\n";
				}else if(!strncmp("3",(const char*)this->client.getbuf(),1)){
					std::cout<<"*"<<(int)i<<"		";
					std::cout<<(this->client.getbuf()+1)<<"		  "<<"&??????*\n";
				}else if(!strncmp("4",(const char*)this->client.getbuf(),1)){
					std::cout<<"*"<<(int)i<<"		";
					std::cout<<(this->client.getbuf()+1)<<"		"<<"&?????????*\n";
				}
				else continue;
		
			}
	}

	std::cout<<"****************************************\n";
		
		return count;
}

//static Client pipe(IPADDR,PORT+1);
static int state=1;
static int state0=1;
//static int state1=1;

static void Pipe(){
	Client pipe(IPADDR,PORT+1);
//	std::mutex mtx;
	
	if(pipe.link()) 
		if(pipe.Send("link"))
			if(pipe.Receive()&&strncmp("OK",(const char*)pipe.getbuf(),2)) 
				std::cout<<"pipe ???????????????\n";
				
	while(1){
		
		memset(pipe.getbuf(),0,BUFSIZE);
		pipe.Receive();
//		if(state1==2) return;
		if(pipe.getmsize()==0) continue;
		
		std::cout<<"\n****************************************\n";
		std::cout<<"*?????? `"<<pipe.getbuf()<<" `?????????????????????\n";
		std::cout<<"*?????? C ??????.....\n";
		std::cout<<"****************************************\n";

		state0=2;
		while(state==1){
//			if(state1==2) return;
			sleep(2);
		}
		
		system("cls");
		
//		mtx.lock();
		
		std::cout<<"\n***********************************\n";
		std::cout<<"*?????????????????? `"<<pipe.getbuf()<<" `??????????????????\n\n";
		std::cout<<"* A --- ???	B --- ???\n";
		std::cout<<"***********************************\n";
		
		
		
		char i;
		std::cout<<"????????????";
	l1:
		std::cin>>i;
		
		if(i=='B'||i=='b') pipe.Send("disagree");
		
		else if(i=='a'||i=='A'){
		
			pipe.Send("agree");
			Game(2,1,pipe);
			
		}else {
			std::cout<<"????????????????????????:";
			goto l1;
		}
		
//		mtx.unlock();
		
		return;
	}
	
}

static int Game(int i,int j,Client& jp){
	std::cout<<"???????????????????????????\n??????????????????\n";
	sleep(2);
	Chess chess;
	if(i==1){
		chess.showTab();
		int who = j;
		while(chess.state()){
		
			if(who==j){
				std::cout<<"\n???????????????......\n";
				jp.Receive();
				int s=(int)jp.getbuf()[0];
				chess.play(s,j);
				who=i;
				if(!chess.state()) {jp.Send("over");goto l2;}
			}
		
			else{	
				std::cout<<"????????????";
		 l1:
		 		int s = inputSite();	
				if(!chess.play(s,i)){std::cout<<"??????????????????\n????????????";goto l1;}
				char ss[2]={0,0};
				ss[0] = (char)s;
				jp.Send((const char*)ss);
				who=j;
			}
		
		
	l2:
		system("cls");
		chess.showTab();
		}
		chess.showState(i);
	
	}
	else{
		chess.showTab();
		
		int who = i;
		while(chess.state()){
		
		
		
			if(who==i){	
				std::cout<<"????????????";
				
		 l3:
		 		int s = inputSite();	
				if(!chess.play(s,i)){std::cout<<"??????????????????\n????????????";goto l3;}
				
				char ss[2]={0,0};
				ss[0] = (char)s;
				jp.Send((const char*)ss);
				who=j;
				if(!chess.state()) {jp.Send("over");goto l4;}
			}else{
				std::cout<<"\n???????????????......\n";
				jp.Receive();
				int s=(int)jp.getbuf()[0];
				chess.play(s,j);
				who=i;
				
			}
		
		
	l4:
		system("cls");
		chess.showTab();
		}
		chess.showState(i);
	}
	
	return 1;
}

void UI::showMenu_2(){
	
	std::cout<<"??????????????????.....\n";
	system("cls");
	
l3:
	std::thread th_d(Pipe);
	
l1:
	pUser();
	
	std::cout<<"A --- ????????????\nB --- ??????????????????\nQ --- ??????\n";
	
	int k=this->inputOption(3);
	
	if(k==1){
		
		system("cls");
		std::cout<<"\n???????????????.....\n";
		goto l1;
		
	}else if(k==2){
		
		system("cls");
		int i=(char)pUser();
		char j=0;
	
		if(this->client.Send("game"))
			if(this->client.Receive()&&!strncmp("OK",(const char*)this->client.getbuf(),2)){
				std::cout<<"\n?????????????????????????????????(0~"<<i-1<<")?????? q ????????????";
			}
	
	l2:
		std::cin>>j;
		
		
		if(j=='q'||j=='Q') {this->client.Send("return");system("cls");goto l1;};
		if((j=='C'||j=='c')&&state0==2) {this->client.Send("return");goto l4;}
		
		j-=48;
		if(j<0||j>=i){std::cout<<"\nerror!!!???????????????????????? q ????????????";goto l2;}
		
		
		{		/*		?????????????????????????????????		*/
		
			char n[2]={0,0};
			n[0]=(char)(j+1);
			
			if(this->client.Send((const char*)n)){
				if(this->client.Receive()){
					if(!strncmp("NO",(const char*)this->client.getbuf(),2)){
						std::cout<<"\n????????????......\n????????????????????? q ????????????";
						goto l2;
					}
				
					else if(!strncmp("YOU",(const char*)this->client.getbuf(),3)){
						std::cout<<"\n????????????????????????????????? q ????????????";
						goto l2;
					}
				}
			}
			this->client.Send("OK");
			
			if(this->client.Receive())
				if(!strncmp("disagree",(const char*)this->client.getbuf(),8)){
					std::cout<<"\n??????????????????????????????\n";
					goto l1;
				}
			
			std::cout<<"????????????????????????\n";
			
			Game(1,2,this->client);
			goto l1;
		}
		
	
	}else if(k==3){
	
l4:
		if(state0==1) goto l1;
		state=2;
		th_d.join();
		state=1;
		state0=1;
		goto l3;
	}else if(k==400) {
		
		th_d.detach();
		return;
	}
}

int UI::process(const char* s){
	
	system("cls");
	std::cout<<"                 "<<s;
	std::cout<<"*************************************************************\n";
	std::cout<<"*                                                           *\n";
	std::cout<<"*                   A ---- ????????????                          *\n";
	std::cout<<"*                                                           *\n";
	std::cout<<"*                                                           *\n";
	std::cout<<"*                   B ---- ??????                             *\n";
	std::cout<<"*                                                           *\n";
	std::cout<<"*                                                           *\n";
	std::cout<<"*************************************************************\n";

	return this->inputOption(2);

}


int UI::logIn(){
	char s[10];
	
	system("cls");
	std::cout<<"?????????????????????......\n\n";
	if(this->client.Send("login")){
		if(this->client.Receive()&&!strncmp("OK",(const char*)this->client.getbuf(),2)) std::cout<<"???????????????\n";
		else return 2;
	}

	while(1){
		std::cout<<"?????????????????????";
		std::cin>>s;
		if(this->client.Send("user")&&this->client.Receive()&&!strncmp("OK",(const char*)this->client.getbuf(),2))
			if(this->client.Send((const char*)s)&&this->client.Receive())
				if(strncmp("OK",(const char*)this->client.getbuf(),2)){
					const char* ss;
					if(!strncmp("EXIST",(const char*)this->client.getbuf(),5))
						ss="?????????????????????????????????\n";
					ss="?????????????????????\n";
					if(process(ss)==1) continue;
					else this->client.Send("return");
					return 0;
				}
l1:
		std::cout<<"??????????????????";
		std::cin>>s;
		if(this->client.Send("passwd")&&this->client.Receive()&&!strncmp("OK",(const char*)this->client.getbuf(),2))
			if(this->client.Send((const char*)s)&&this->client.Receive())
				if(strncmp("OK",(const char*)this->client.getbuf(),2)){
					const char* ss="???????????????\n";
					if(process(ss)==1) goto l1;
					else this->client.Send("return");
					return 0;
				}
		
		break;
	}
	std::cout<<"???????????????\n";
	sleep(1);
	return 1;
}

int UI::signUp(){
	char s[10];
	
	system("cls");
	std::cout<<"?????????????????????......\n\n";
	if(this->client.Send("signup")){
		if(this->client.Receive()&&!strncmp("OK",(const char*)this->client.getbuf(),2)) std::cout<<"???????????????\n";
		else return 2;
	}
	
	
	while(1){
		std::cout<<"?????????????????????";
		std::cin>>s;
		
		if(this->client.Send("user")&&this->client.Receive()&&!strncmp("OK",(const char*)this->client.getbuf(),2))
			if(this->client.Send((const char*)s)&&this->client.Receive())
				if(strncmp("OK",(const char*)this->client.getbuf(),2)){
					const char* ss="?????????????????????\n";
					if(process(ss)==1) continue;
					else this->client.Send("return");
					return 0;
				}
		break;
	}

	while(1){
		char s0[20];
		memset(s0,0,20);
		memset(s,0,20);
		std::cout<<"??????????????????";
		std::cin>>s;
		std::cout<<"????????????????????????";
		std::cin>>s0;
		if(strncmp(s,s0,20)){
			const char* ss="?????????????????????????????????\n";
			if(process(ss)==1) continue;
			else this->client.Send("return");
			return 0;
		}
		
		break;
	}
	
	if(this->client.Send("passwd")&&this->client.Receive()&&!strncmp("OK",(const char*)this->client.getbuf(),2))
		if(this->client.Send((const char*)s)&&this->client.Receive()){
			if(!strncmp("OK",(const char*)this->client.getbuf(),2)) std::cout<<"???????????????\n";
			else {std::cout<<"???????????????\n";return 2;}
		}
	sleep(1);
	return 1;
	
}


