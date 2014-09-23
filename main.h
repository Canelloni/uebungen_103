/*
 * main.h
 *
 *  Created on: 23.09.2014
 *      Author: chris
 */

#ifndef MAIN_H_
#define MAIN_H_
#include <iostream>
#include <limits>
#include <signal.h>
#include <unistd.h>
#include <cstdlib>

using namespace std;

class Funkt
{
public:
	void results(int hu, int ka) {
		cout << "\n\nEs hat " << hu <<" Huehner und " << ka << " Kanienchen auf der Farm!!!" << endl;

	}

	void clear_screen()
	{
#ifdef WINDOWS
		std::system("cls");
#else
		// Assume POSIX
		std::system ("clear");
#endif
	}
	/*	void hold_screen()
	{
#ifdef WINDOWS
		fflush(stdin);
		getchar();
#else
		cout<<"\n\nPress any Key...\n";
		cin.clear();
		cin.ignore();
		cin.get();
#endif
	}*/

	void one(){
		char rep;
		int start;
		int stop;
		int step;
		float Fa;
		do{
			start=0;
			stop=0;
			step=0;
			Fa=0;

			clear_screen();
			cout<<"###########################\n"
					"# Uebungen v1.2\t by Chris #\n###########################\n";
			cout<<"\nTemp Calc\n----------\n";
			cout<<"\nBei wieviel Celsius wollen wir starten?:\t";
			while(!(cin >> start)){
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Nur reale Zahlen eingeben. Neuer Versuch:\t";
			}
			cout<<"Bis?:\t";
			while(!(cin >> stop)){
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Nur reale Zahlen eingeben. Neuer Versuch:\t";
			}
			cout<<"Schritte?:\t";
			while(!(cin >> step)){
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Nur reale Zahlen eingeben. Neuer Versuch:\t";
			}


			cout<<"\n\nTemperaturumrechnung\n--------------------------\n"
					"Fahrenheit\tCelsius\n-------------------------\n";

			while(start<=stop){

				Fa=start*1.8+32;
				cout<<Fa<<"\t\t"<<start<<endl;
				start=start+step;

			}
			cout << "\nWillst du nochhmals? (j/n)\t";
			cin >> rep;
		}while(rep=='j' || rep =='J');
		//Fa=Ce*(9/5)+32;

		//clear_screen();

	}
	void two(){
		char rep;
		int sek;
		do{
			clear_screen();
			sek=0;
			cout<<"###########################\n"
					"# Uebungen v1.2\t by Chris #\n###########################\n";
			cout<<"\nCountdown\n-----------\n";
			cout<<"\nGib die Anzahl Sekunden ein:\t";
			while(!(cin >> sek)){
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Nur reale Zahlen eingeben. Neuer Versuch:\t";
			}
			for(int x=sek; x >= 0; x--){


				if (x==0){
					cout<<x<<"\a(Beep)"<<endl;
					cout<<flush;
					//alarm(3);
				}
				else{
					cout<<x<<endl;
					cout<<flush;
					sleep(1);
				}
				//clear_screen();
			}
			cout << "\nWillst du nochhmals? (j/n)\t";
			cin >> rep;
		}while(rep=='j' || rep=='J');

	}
	void thre(){
		//variables
		int eing_tiere;
		int eing_beine;
		int huhner;
		int kanien;
		int anz_beine;
		char rep;
		do {
			clear_screen();
			eing_tiere=0;
			eing_beine=0;
			huhner=0;
			kanien=0;
			anz_beine=0;
			try {
				do {
					cout<<"###########################\n"
							"# Uebungen v1.2\t by Chris #\n###########################\n";
					cout<<"\nFarm\n-------\n";
					cout << "\nAnzahl Tiere eingeben:\t";
					//cin >> eing_tiere;
					while(!(cin >> eing_tiere)){
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "Nur reale Zahlen eingeben. Neuer Versuch:\t";
					}
				}while(eing_tiere<0);
				do {
					cout << "Anzahl Beine eingeben:\t";
					//cin >> eing_beine;
					//wir erlauben nur int als eingabe
					while(!(cin >> eing_beine)){
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "Nur reale Zahlen eingeben. Neuer Versuch:\t";
					}
				}while((eing_beine % 2) ||
						(eing_beine < (2 * eing_tiere)) ||
						(eing_beine > (4 * eing_tiere)));

			}
			catch (int e){
				cout << "int exception: " << e << endl;
			}
			catch (char e){
				cout << "char exception: " << e << endl;
			}
			catch (...) {
				cout << "default exception ";
			}

			huhner = eing_tiere;

			while(anz_beine < eing_beine) {
				huhner--;
				kanien++;
				anz_beine = (2 * huhner) + (4 * kanien);
			}

			results(huhner, kanien);
			cout << "\nWillst du nochhmals? (j/n)\t";
			cin >> rep;
			cout<<endl;
			huhner=0;
			kanien=0;



		}while((rep=='j') || (rep=='J'));
		//cout << "\nGoodbye";
		//clear_screen();
		//getchar();
	}


};

class Choice
{
public:
	Funkt funk;
	void choice(int c){

		funk.clear_screen();


		switch(c){

		case 1:

			funk.one();
			break;

		case 2:
			funk.two();
			break;

		case 3:
			funk.thre();
			break;

		default:
			cout<<"default\n";
			break;

		}

		fflush(stdin);
		//funk.hold_screen();
		funk.clear_screen();

	}
};



#endif /* MAIN_H_ */
