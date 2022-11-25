#include "lexique.hpp"

lexique::lexique(){
    this->nom = "Lexique";
}

lexique::lexique(string nom){
    this->nom = nom;
}

int lexique::findWord(const string word){
    auto item = this->lex.find(word);
    if(item != lex.end()){
        return 1;
    }
    else return 0;
}

void lexique::eraseWord(const string word){
    auto item = this->lex.find(word);
    if(item != lex.end()){
        lex.erase(item);
    }
}

void lexique::testWord(const string word){
    auto item = this->lex.find(word);
    if(item != lex.end()){
        cout << "The word ";
        cout << item->first << " ";
        cout << "is present ";
        cout << item-> second << " ";
        cout << "in " << this->nom << endl;
    }
    else{
        cout << "The word ";
        cout << word;
        cout << "isn't present in " << this->nom << endl;
    }
}

void lexique::numberWord(){
    map<string, int>::iterator it;
    int number = 0;
    for (it = this->lex.begin (); it != this->lex.end(); it++)
    {
        number++;
    }
    cout << "Number of word in lexique : " << number << endl;
}

void lexique::addWords(const string word){
    this->lex.insert(pair<string, int>(word, 1));
}

void lexique::incrOccurence(const string word){
    this->lex[word] += 1;
}

void lexique::afficherLexique(){
    map<string, int>::iterator it;
    for (it = this->lex.begin (); it != this->lex.end(); it++)
    {
        cout << it->first << " ";
        cout << it-> second << '\n';
    }
    cout << "\n";
}

void lexique::saveLexique(){
    map<string, int>::iterator it;
    ofstream file(this->nom.c_str());
    if(!file){
        cout << "ERREUR: Impossible d'ouvrir le fichier!" << endl;
    }
    else{
        for (it = this->lex.begin (); it != this->lex.end(); it++)
        {
            file << it->first << " ";
            file << it-> second << '\n';
        }
    }
}

void lexique::fileToWord(const string &PATH){
    string content;
    string word;
    char* string;
    char* pch;

    readFileIntoString(PATH, content);
    toLower(content);
    
    string = new char[content.length()+1];
    strcpy(string, content.c_str());

    pch = strtok(string, " ,.-\":/@!?#&“”()‘_\n*’$'");
    while (pch != NULL)
    {
        word = pch;
        remove_punctuation(word);
        if(this->findWord(word) == 0){
            this->addWords(word);
        }
        else{
            this->incrOccurence(word);
        }
        pch = strtok (NULL, " ,.-\":/@!?#&“”()‘_\n*’$'");
    }

    this->saveLexique();

    delete[] string;
}