/*
 * rechner.cpp
 *
 *  Created on: 26.07.2012
 *      Author: KickDown
 */

#include <iostream>
using namespace std;


int addi(int x, int y) {
	return (x+y);
}

int subt(int x, int y) {
	return (x-y);
}

int multi(int x, int y) {
	return (x*y);
}

int divid(int x, int y) {
	cout << "Das Ergebnis ist gerundet!" << endl;
	return (x/y);
}

//Funktion zum checken der Eingabe
int eingabeCheck(string frage, int min, int max) {
	int eingabe;
	while((cout << frage) && (!(cin >> eingabe) || eingabe>max || eingabe<min)) {
		cout << "Die Eingabe kann nicht verarbeitet werden!" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	return eingabe;
}

//Funktion zum Ã¼berpÃ¼fen ob 0 oder 1 eingegeben wurde
int nulleinsCheck(string frage) {
	int eingabe;
	cout << endl;
	while((cout << frage) && (!(cin >> eingabe) || (eingabe!=0 && eingabe!=1))) {
		cout << "Die Eingabe kann nicht verarbeitet werden!" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	return eingabe;
}

//Hauptfunktion
int main() {
	int c=1;
	while(c==1) {

		//BegrÃ¼ssung
		cout << "Rechner v1.0" << endl;
		cout << "************" << endl << endl;

		//Funktionsauswahl
		cout << "Was wills Du tun?" << endl;
		cout <<"1. Addieren (Plus)" << endl;
		cout <<"2. Subtrahieren (Minus)" << endl;
		cout <<"3. Multiplizieren (Mal)" << endl;
		cout <<"4. Dividieren (Teilen)" << endl;

		//Eingabe prÃ¼fen
		int f;
		f = eingabeCheck("Ich wÃ¤hle Nr.: ",1,4);

		//Zahlen aufnehmen und prÃ¼fen
		int a, b;
		a = eingabeCheck("Erste Zahl: ", -2147483647, 2147483647);
		b = eingabeCheck("Zweite Zahl: ", -2147483647, 2147483647);

		//AusfÃ¼hren
		int r=0;
		if(f==1) {
			r = addi(a,b);
		}
		if(f==2) {
			r = subt(a,b);
		}
		if(f==3) {
			r = multi(a,b);
		}
		if(f==4) {
			r = divid(a,b);
		}

		//Ergebnis anzeigen
		cout << "Das Ergebnis lautet: " << r << endl;

		//Abfrage noch einmal
		c = nulleinsCheck("Noch eine Berechnung? (1=Ja, 0=Nein)");
		cout << endl << endl;
	}

	return 0;

}
