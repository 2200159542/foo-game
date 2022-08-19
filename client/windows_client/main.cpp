#include<iostream>
#include<unistd.h>
#include"ui.h"
#include"frame.h"

int main(){

	UI ui;
	Chess chess;
	ui.showBegin();

l1:
	ui.showMenu_1();
	int o = ui.inputOption(2);
	if(o==1) {if(!ui.logIn()) goto l1;}
	else if(o==2) {if(!ui.signUp()) goto l1;}
	
	ui.showMenu_2();

	system("pause");
	return 0;
	
}
