#include "fonction2.h"
#include "fonction.h"
#include <conio.h>
#include<iostream>


int main()
{
word w, m, a;
password p;
m_words tableau;
bool verif;
bool cbon = true;
clock_t tolerance = 50;

// On enregistre le mot de passe choisi par l'utilisateur
p=initialisation();

for(int i=0 ; i<N ; i++)
{
    w=WordType(p.getNbrLettres());
    verif = verification(p,w);
    while (verif != true)
    {
       cout << "Mot de passe incorrect" << endl << endl;
       w=WordType(p.getNbrLettres());
       verif = verification(p,w);
    }
    tableau[i] = w;
    cout << " ==> Ok" << endl;
}
m=median(tableau);

while (1){
cout << endl << "maintenant le test " << endl ;
a=WordType(p.getNbrLettres());
cbon = test(tolerance,a,m);
while (cbon!=true)
{
    cout << endl << "c est pas bon " << endl;
    a=WordType(p.getNbrLettres());
    cbon = test(tolerance,a,m);

}

std::cout << "bienvenue " << std::endl;

}
}
