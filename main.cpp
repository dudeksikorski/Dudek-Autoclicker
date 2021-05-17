#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <cstdio>
#include <cstdlib>
using namespace std;

int przycisk = 1;
int zsleep = 100;

void menu()
{   
	system("cls");
	system("color 04");
	cout << "=============================" << endl;
	cout << "SLEEP = " << zsleep << endl;
	cout << "=============================" << endl;
	cout << "WLACZ LEWY <BICIE> : Z"  << endl;
	cout << "WYLACZ PRAWY <STAWIANIE> : C" << endl;
	cout << "WYLACZ KLIKANIE: X" << endl;
	cout << "WSTRZYMAJ NA 2s: 1" << endl;
	cout << "EXIT: 2" << endl;
	cout << "=============================" << endl;
}


void clicker()
{
	bool click = false; //nie klika

	while (true)
	{
		if (GetAsyncKeyState('Z')) //jezeli x to zaczyna
		{
			click = true;
			przycisk = 1;

		}
		else if (GetAsyncKeyState('C')) //jezeli x to zaczyna
		{
			click = true;
			przycisk = 2;
		}
		else if (GetAsyncKeyState('X')) //jezeli c to konczy
		{
			click = false;
		}
		else if (GetAsyncKeyState('1')) //jezeli W to wsztrzymujemy klikanie na chwile
		{
			Sleep(2000);
		}
		else if (GetAsyncKeyState('2')) //jezeli E to wychodzimy z programu (wyjscie awaryjne)
		{
			exit(0);
		}


		if (click == true && przycisk == 1) 
		{
			mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
			Sleep(18);
			mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
			Sleep(zsleep); //dostosowywanie szybkosi
		}
		else if (click == true && przycisk == 2)
		{
			mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0);
			Sleep(18);
			mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
			Sleep(zsleep); //dostosowywanie szybkosi
		}
	}
}

int main()
{
	system("color 02");
	cout << "=============================" << endl;
	cout << "NAJLEPSZY CONFIG = 15ms" << endl;
	cout << "=============================" << endl;
	cout << endl;
	cout << "Sleep w ms: ";
	

	cin >> zsleep;

	cout << endl;
	cout << endl;

	//cout << "podaj button (1 prawy 2 lewy): ";

	//cin >> przycisk;





	menu();
	clicker();



	return 0;
}