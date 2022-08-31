#include<iostream>
#include<time.h>
#include<conio.h>

using namespace std;

int main()
{
	srand((unsigned int)time(NULL));

	int numArray[25] = {};
	for (int i = 0; i < 24; i++) {
		numArray[i] = i + 1;
	}
	numArray[24] = INT_MAX;

	int starIndex = 24;

	int idx1, idx2, temp;

	for (int i = 0; i < 100; i++) {
		idx1 = rand() % 24;
		idx2 = rand() % 24;
		temp = numArray[idx1];
		numArray[idx1] = numArray[idx2];
		numArray[idx2] = temp;
	}

	while (true) {
		system("cls");

		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (numArray[i * 5 + j] == INT_MAX) {
					cout << "*\t";
				}
				else {
					cout << numArray[i * 5 + j] << "\t";
				}
			}
			cout << "\n";
		}


		bool bWin = true;

		for (int i = 0; i < 24; i++) {
			if (numArray[i] != i + 1) {
				bWin = false;
				break;
			}
		}

		if (bWin == true) {
			cout << "congratulations!!" << "\n";
			break;
		}


		cout << "W : Up  S : Down  A : Left  D : Right  Q : Exit";
		char cInput = _getch();

		if (cInput == 'q' || cInput == 'Q') {
			break;
		}

		switch (cInput)
		{
		case 'w':
		case 'W':
			if (starIndex > 4) {
				numArray[starIndex] = numArray[starIndex - 5];
				numArray[starIndex - 5] = INT_MAX;
				starIndex -= 5;
			}
			break;
		case 's':
		case 'S':
			if (starIndex < 20) {
				numArray[starIndex] = numArray[starIndex + 5];
				numArray[starIndex + 5] = INT_MAX;
				starIndex += 5;
			}
			break;
		case 'a':
		case 'A':
			if (starIndex % 5 != 0) {
				numArray[starIndex] = numArray[starIndex - 1];
				numArray[starIndex - 1] = INT_MAX;
				starIndex--;
			}
			break;
		case 'd':
		case 'D':
			if (starIndex % 5 != 4) {
				numArray[starIndex] = numArray[starIndex + 1];
				numArray[starIndex + 1] = INT_MAX;
				starIndex++;
			}
			break;
		default:
			break;
		}
	}

	cout << "\nGame End" << "\n";

	return 0;
}