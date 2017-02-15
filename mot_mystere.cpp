#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>
 using namespace std;
/*
 * mot_mystere : game where the player must guess a word whose letters are shuffled
 */
 
string getWord() {
	
	string ligne; //Une variable pour stocker les lignes lues
	int lines(0);
	int choice;
	
	
	//step 1 : count the number of lines
	ifstream f("dico.txt");  //Ouverture d'un fichier en lecture
	
	if(!f) {
		cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;		
	}
	
	else {
		while(getline(f, ligne)){
			
			lines ++;
			
		}
		
		cout << endl << lines << " mots" << endl ;
		
	}
	
	//step 2 : choose the mystery word
	srand(time(0));
	choice = rand() % (lines+1);
	cout << endl << "choix : numero " << choice << endl ;
	
	f.close();
	
	ifstream f2("dico.txt");  //Ouverture d'un fichier en lecture
	string ligne2;
	
	if(!f2) {
		cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
	}
	
	else {	
		while(choice !=0){
			getline(f2, ligne2);
			choice--;
		}
	}
	
	cout << endl << "choix : mot " << ligne2 << endl ;
	
	return ligne2;
}

string mix(string word) {
	
	int i;
	string newWord; //new shuffled word
	int wordSize(word.size()); //size of the word
	
	srand(time(0));
	
	while(wordSize != 0) {
		//as long as there are still letters in the word
		
		i = rand() % wordSize; //randomly choose a number
		
		newWord.push_back(word[i]); //add the corresponding letter to the new shuffled word
		word.erase(i, 1); //take the letter from the original word
		wordSize = word.size(); //updates the variable so that we know when there is no letter left
	}
	
	return newWord;
	
}

void guess(string word, string newWord) {
	/**
	 * \brief prints the shuffled word and asks the user to find the original word
	 * \param word  the original word
	 * \param newWord the shuffled word
	 */
	
	string trial("");
	int nbtrials(5);
	
	while(trial != word && nbtrials != 0){
		//while the user hasn't found the good word and that nbtrials > 0, prints the shuffled word and asks the user their answer
		cout << "De quel mot les lettres ont-elles été mélangées ( " << nbtrials << " essai(s) ) ? " << newWord << endl;
		
		cin >> trial;
		cin.ignore();
		
		if(trial == word) {
			
			cout << "--------------------------------" << endl
			     << "Félicitations, vous avez gagné !" << endl;
			
		}
		
		else if(trial == "cheater") {
			//a cheatcode ;) !
			cout << "~~~ " << word << " ~~~" << endl << endl;
			
		}
		
		else{
			nbtrials --;
			
			
		}
		
		
	}
	
	if(nbtrials == 0) {
		//if nbtrials = 0, prints this message efore then end of the function, hence of the game
		cout << "--------------------------------" << endl
		     << "Perdu pour cette fois " << endl;
		
	}
	
}

bool playAgain() {
	/**
	 * \brief asks the player if he wants to play one more game
	 * \return nboolean (true for a new game, false to stop)
	 */
	string answer;
	
	while(answer != "o" && answer != "n") {
		cout << "Voulez-vous rejouer ? [o/n] ";
		cin >> answer;
	}
	
	if(answer == "o") {
		cout << endl;
		return true;
		
	}
	
	cout << "Fin du jeu. Revenez Bientôt !" << endl << endl;
	return false;
}

main() {
	
	bool again(true); //indicates if the player wants to play one more game
	
	while(again) {
		string word = getWord(); //gets the word
	
		string newWord = mix(word); //shuffles the letters
	
		guess(word, newWord); //asks the player to guess the word
		
		again=playAgain(); ////asks the player if he wants to play one more game
	
	}
	
	return 0;
	
}