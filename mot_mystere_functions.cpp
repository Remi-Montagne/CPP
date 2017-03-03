#include "mot_mystere_functions.h"

using namespace std;

void getDico(vector<string>& dico, string const& inFile) {
	
	string word; //gets the word of the dictionnary file
	ifstream f(inFile.c_str()); // tries to open a flux
	
	if(!f){ //if it doesn't work
		cout << "ERREUR: Impossible d'ouvrir le fichier dictionnaire en lecture." << endl;
	}
	
	else { //if it works
		while(f >> word) {
			dico.push_back(word); //ads each word in the dico
		}
		f.ignore();
	}
}

string chooseWord(vector<string> const& dico) {
	
	srand(time(0));;
	
	return dico[rand() % dico.size()];
}

string shuffleWord(string word) {
	
	int i, letter;
	int const sizeMax = word.size();
	string shuffled = "";
	
	srand(time(0));
	
	for(i = 0; i < sizeMax; i++) {
		
		letter = rand() % word.size(); //choose a number between 0 and the size of the remaining letters in the original word
		shuffled = shuffled + word[letter]; //ads the letter at this position to the shuffled word
		word.erase(letter, 1); //erase the letter at this positionn from the original word
		
	}
	
	return shuffled;
}

void guessWord(string original, string shuffled) {
	
	bool again = true; //to get out of the while when the word is found
	int trials = 5; //number of trials left
	string guess; //takes the word entered by the user
	
	while(again && trials > 0 ) {
		
		cout << endl << "De quel mot les lettres ont-elles été mélangées (" << trials << " essais) ? " << shuffled << endl;
		cin >> guess ;
		cin.ignore();
		
		if(guess == "cheater") {
			//a code for the cheaters : displays the answer
			cout << original << endl;
		}
		
		else if(guess != original) {
			// else, if the proposed word is not the original, takes 1 trial and goes back to the beginning of the while
			cout << "Ce n'est pas le bon mot." << endl ;
			trials -= 1;
		}
		
		else {
			// else (word guessed) the player wins and leaves the while
			cout << "Bravo, tu as trouve le mot mystere !" << endl;
			again = false;
		}
	}
	
	if(trials == 0 && guess != original)
	{
		cout << "Le bon mot était " << original << " !" << endl;
	}
}

bool oneMore() {
	
	string answer; //takes the answer of the user
	
	//display the question
	cout << endl << "Veux-tu rejouer ? [o/n] ";
	cin >> answer;
	cin.ignore();
	
	if(answer == "o") {
		return true;
	}
	
	else if(answer == "n") {
		return false;
	}
	
	else {
		cout << "Tape \"o\" pour oui et \"n\" pour non" << endl;
		return oneMore();
	}
}