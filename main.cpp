/*
 * main.cpp
 *
 *  Created on: 23.09.2014
 *      Author: chris
 */

#include <iostream>
#include <stdio.h>
#include <string>
#include "main.h"

using namespace std;

int main(){

	Choice choice1;
	Funkt funk1;

	int choi;
	char rep;

	do {
		string menu = "###########################\n"
				"# Uebungen v1.2\t by Chris #\n###########################\n"
				"\nHauptmenu\n----------\n\n"
				"1\t Celsius/Fahrenheit Calculator\n"
				"2\t Countdown\n"
				"3\t Farm\n"
				"\ngo to:\t";
		funk1.clear_screen();
		cout<<menu;
		while(!(cin >> choi)){
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Nur reale Zahlen eingeben. Neuer Versuch:\t";
		}



		choice1.choice(choi);
		cout<<"###########################\n"
				"# Uebungen v1.2\t by Chris #\n###########################\n";
		cout<<"\nZurueck zum Hauptmenu? (j/n):\t";

		cin>>rep;

	}while((rep=='j') || (rep=='J'));
	funk1.clear_screen();
	cout<<"Googbye\n";
	fflush(stdin);
	getchar();
	return 0;

}
