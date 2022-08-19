#include<iostream>
#include<unistd.h>
#include"ui.h"
#include"frame.h"


int main(){

/*   frame test code.
*/  
    
    int i;
	UI ui;
	Chess chess;
	
	ui.showBegin();
l1:
	ui.showMenu_1();
	int o = ui.inputOption(2);
	if(o==1) {
	   i = ui.logIn();
	   if(i==0) goto l1;
	   else if(i==2){
	       std::cout<<"link error!\n";
	       return 0;
	   }
	 }
	else if(o==2) {
	   i = ui.signUp();
	   if(i==0) goto l1;
	   else if(i==2){
	       std::cout<<"link error!\n";
	       return 0;
	   }
	}
	
	
	ui.showMenu_2();
	
/* ******* tset code *************
	system("clear");
	chess.showTab();
	while(chess.state()){
	
	if(!chess.play(ui.inputSite(),ui.inputClass())) continue;
	system("clear");
	chess.showTab();
	chess.showState();
    }
	UI ui;
	ui.showBegin();
	system("pause");
  **********************************
*/

	return 0;
	
}
