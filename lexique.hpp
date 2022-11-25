#ifndef LEXIQUE_HPP
#define LEXIQUE_HPP

#include <string.h>
#include <fstream>
#include "utilitaire.hpp"

class lexique
{
private:
    string nom;
    map<string, int> lex;

public:
    /*Constructeurs*/
    lexique();
    lexique(string nom);

    /*getters*/
    string get_nom() const {return nom;}
    map<string, int> get_lex() const {return lex;}

    /*Methodes*/
    void addWords(const string word);
    void incrOccurence(const string word);
    int findWord(const string word);
    void fileToWord(const string &PATH);
    void afficherLexique();
    void saveLexique();
    void eraseWord(const string word);
    void testWord(const string word);
    void numberWord();
};



#endif //LEXIQUE_HPP