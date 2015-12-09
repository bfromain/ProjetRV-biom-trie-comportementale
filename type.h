#include <vector>
#include <algorithm>

using namespace std;

// Nombre de fois ou l'on doit écrire notre mot
#define N 5

// vecteur de temps
class word {

private :
    vector<char> lettres;
    vector<clock_t> temps;


public :
    void setLettre (char c){lettres.push_back(c);}
    void setTemps (clock_t t){temps.push_back(t);}
    void setSpecificTemps (clock_t t, int position){temps[position] = t;}
    char getLettre (int i){return lettres[i];}
    clock_t getTemps (int i){return temps[i];}
    int getSizeTemps () {return temps.size();}
    int getSizeLettres () {return lettres.size();}
    void reset () {temps.clear();lettres.clear();}
    void supr() {temps.pop_back(); lettres.pop_back();}
};

class password
{
    private :
    vector<char> lettres;
    int nbrLettres;

    public :

    void setLettre (char c){lettres.push_back(c);}
    void setNbrLettres(int i){nbrLettres = i;}
    int getNbrLettres (){return nbrLettres;}
    char getLettre (int i){return lettres[i];}

};

// Liste de vecteur dans lequel sera stocké les temps des multiples écrit du mot
typedef word m_words [N];

