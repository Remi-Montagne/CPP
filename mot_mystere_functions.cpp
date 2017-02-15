#include "mot_mystere_functions.h"

using namespace std;

void getDico(vector<string>& dico, string inFile) {
	
	string word("");//Une variable pour stocker les mots lus
	ifstream f(inFile.c_str());  //Ouverture d'un fichier en lecture
	
	if(!f) {
		cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;		
	}
	
	else {
		while(f >> word){
			
			dico.push_back(word);
		}
	}
}

string getWord (vector<string>& dico) {
	//step 2 : choose the mystery word
	srand(time(0));
	
	string res("");
	
	int choice = rand() % (dico.size()+1);
	cout << endl << "choix : numero " << choice << endl ;
	
	res = dico[choice];
	cout << "mot choisi : " << res << endl;

	return res;
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