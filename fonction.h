#include <vector>
#include <ctime>
#include "type.h"


/* fonction qui permet de taper une lettre et de lancer un chrono qui s'arretera
lorsqu'une autre lettre sera entr�e */
word WordType(int nbrLettres);

/* Fonction pour �crire les diff�rent temps entre les lettres d'un mot */
void ReadData (word c);

/* fonction pour initialiser le nom�bre de lettre du mot que l'on va taper */
password initialisation ();

/* Cr�e un mot dont les diff�rents temps sont la moyenne de ceux rentr�s pr�c�demment */
word  moyenne (m_words tableau, word w);

/* calcul la m�diane */
word median (m_words tableau);

/* check si on a rentr� le bon mot de passe */
bool verification (password p, word w);

bool test(clock_t tolerance, word w, word m);


