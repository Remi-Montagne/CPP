#include <iostream>
#include <string>
#include <vector>

#include "mot_mystere_functions.h"

using namespace std;

int main() {
	
	cout << endl << "-----------------------------------------------------------\nBienvenue dans le jeu du mot Mystere !" << endl;
	
	bool play = true;
	
	//gets the dictionnary of possible words in a vector
	vector<string> dico;
	getDico(dico, "dico.txt");
	
	//the actual game
	while(play) {
	
	string word = chooseWord(dico);
	
	string shuffled = shuffleWord(word);
	
	guessWord(word, shuffled);
	
	play = oneMore();
	}
	
	cout << endl << "Au revoir. Reviens bientôt !\n-----------------------------------------------------------" << endl << endl;
	
	return 0;
}