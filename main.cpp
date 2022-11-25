#include "lexique.hpp"

int main(int argc, char *argv[]){
    if(argc == 0){
        cout << "We need arguments : " << endl;
        cout << "Obligatory : " << endl;
        cout << "   - name of file to read for lexique : ex notreDameDeParis_A.txt" << endl;
        cout << "Optional : " << endl;
        cout << "   - test occurence for word : -o <word>" << endl;
        cout << "   - remove word from lexique : -d <word>" << endl;
        cout << "   - print number of word : -n" << endl;
    }
    else{
        if(argv[1][0] == '.'){
            cout << "Remove the ./ before the name of file" << endl;
            return 0;
        }
        string path = argv[1];
        cout << path << endl;
        string name_lexique = "Lexique_";
        name_lexique += path;
        lexique lexique_file(name_lexique);

        lexique_file.fileToWord(path);

        if(argc >= 2){
            if(strcmp(argv[2], "-o") == 0){
                if(argc >= 3){
                    string word = argv[3];
                    lexique_file.testWord(word);
                }
            }
            else if(strcmp(argv[2], "-d") == 0){
                if(argc >= 3){
                    string word = argv[3];
                    lexique_file.eraseWord(word);
                }
            }
            else if(strcmp(argv[2], "-n") == 0){
                lexique_file.numberWord();
            }
        }

        lexique_file.saveLexique();
    }

    return 0;
}