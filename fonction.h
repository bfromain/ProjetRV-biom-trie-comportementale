#include <vector>
#include <ctime>
#include "type.h"


/* fonction qui permet de taper une lettre et de lancer un chrono qui s'arretera
lorsqu'une autre lettre sera entrée */
word WordType(int nbrLettres);

/* Fonction pour écrire les différent temps entre les lettres d'un mot */
void ReadData (word c);

/* fonction pour initialiser le nomùbre de lettre du mot que l'on va taper */
password initialisation ();

/* Crée un mot dont les différents temps sont la moyenne de ceux rentrés précédemment */
word  moyenne (m_words tableau, word w);

/* calcul la médiane */
word median (m_words tableau);

/* check si on a rentré le bon mot de passe */
bool verification (password p, word w);

bool test(clock_t tolerance, word w, word m);


