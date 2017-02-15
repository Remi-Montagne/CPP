#include <iostream>
#include "mot_mystere_functions.h"
using namespace std;
/*
 * mot_mystere : game where the player must guess a word whose letters are shuffled
 */

main() {
	
	bool again(true); //indicates if the player wants to play one more game
	vector<string> dico;
	string const myFile = "dico.txt";
	
	getDico(dico, myFile);
	
	while(again) {
		string word = getWord(dico); //gets the word
		
		string newWord = mix(word); //shuffles the letters
		
		guess(word, newWord); //asks the player to guess the word
		
		again=playAgain(); ////asks the player if he wants to play one more game
		
	}
	
	return 0;
	
}