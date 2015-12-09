#include <iostream>
#include <conio.h>
#include <vector>
#include <ctime>
#include "type.h"


word WordType(int nbrLettres)
{
word w;
char o;
clock_t t;

    for (int i = 0;i<nbrLettres;i++)
    {
        // on rentre le charactere directemment dans la console, sans devoir appuyer sur entrée
            o = getch();
            if (o!='\b')
                {
                    if (i<nbrLettres-1)
                    {
                    // on lance le chrono
                        t = clock();
                    // on écrit le charactère à l'écran
                        putch(o);
                        w.setLettre(o);
                    // tant que l'on a pas d'appui sur une touche, boucle infini de rien
                        while (!kbhit()){}
                    // on récupère le temps
                        t = clock() - t;
                        w.setTemps(t);
                    }

                    else  //dernier caractère du mot
                    {
                        putch(o);
                        w.setLettre(o);


                    }
                }

            else
                {
                    std::cout << std::endl <<  std::endl <<"Entrez de nouveau le mot de passe :" << std::endl << std::endl;
                    w.reset();
                    // -1 et pas 0 je sais pas pourquoi mais sinon ça marche pas
                    i=-1;
                }
    }
                    // on attend que le mec appui sur entrée avnt de tout valider
                        o = getch();
                        while (o !='\r'){o=getch();}
                        std::cout << std::endl;

            return w;
}

password initialisation (){

int nbrlettre;
char lettre;
password p;

string phraseString ;
cout << "Rentrez la phrase que vous souhaitez faire verifier, puis appuyez sur entree." << endl << endl;
getline(cin, phraseString); // Permet de récupérer la phrase avec les espaces

// On récupère la longueur de la chaîne de caractères :
nbrlettre = phraseString.size();

for (int i=0;i<nbrlettre;i++)
{
lettre = phraseString[i];
//putch(lettre);
p.setLettre(lettre);
}
p.setNbrLettres(nbrlettre);

cout << endl << endl << "Mot valide" << endl << endl ;

return p;
}


void ReadData (word w)
{
    // affichage des différent temps entre les lettres
for (int i=0 ; i<w.getSizeTemps() ; i++)
    std::cout << "temps entre les lettres "<< w.getLettre(i) << " et " << w.getLettre(i+1) << ": " << w.getTemps(i) << std::endl ;

std::cout << std::endl;
}

word  moyenne (m_words tableau, word w)
{
    // on met des 0 partout au début
    word m;
    for (int k=0;k<w.getSizeTemps();k++)
    {
        m.setTemps(0);
    }

   // on rempli avec les valeurs des différents essais
for (int i=0;i<w.getSizeTemps();i++)
{
    for (int j=0;j<N;j++)
    {
        m.setSpecificTemps(m.getTemps(i)+tableau[j].getTemps(i), i);
    }
    // on fait la moyenne
    m.setSpecificTemps(m.getTemps(i)/N,i);
}

    return m;

}

word median (m_words tableau)
{
    word m;
    vector<clock_t> rangement;

// On met dans le mot median les mêmes lettres que dans le mot tapé
for (int k=0 ; k<tableau[0].getSizeLettres() ; k++)
    m.setLettre(tableau[0].getLettre(k));


    // stratégie moldave de tri
    for (int i=0;i<tableau[0].getSizeTemps();i++){
        for (int j=0;j<N;j++)
            {
                // on met toute les valeurs d'une lettre  dans un vecteur
                rangement.push_back(tableau[j].getTemps(i));
            }

    // on tri le dit vecteur
        sort (rangement.begin(), rangement.end());
    // on met dans notre mot le temps median de chaque lettre (N/2 ça marche même si N impaire
        m.setTemps(rangement[N/2]);
    // on clear le vecteur de rangement sinon ça empile plein de valeurs
        rangement.clear();

}

return m;

}

bool verification (password p, word w)
{
    bool verif = true;

    // Si tous les caractères sont identiques c'est bon
    for (int i=0 ; i<p.getNbrLettres() ; i++)
    {
        if (p.getLettre(i) == w.getLettre(i) && verif == true)
            verif = true;
        else
            verif = false;

    }
    return verif;

}

bool test(clock_t tolerance, word w, word m)
{
    bool cbon = true;
    bool mdp = true;
    int compteur = 0;
    for (int i=0 ; i<w.getSizeTemps() ; i++)
    {
        // Si on est dans la tolérance  et que c'est la bonne lettre c'est bon
        if (m.getTemps(i)-tolerance < w.getTemps(i) && m.getTemps(i)+tolerance > w.getTemps(i)  )
            // on met un compteur car l'erreur est humaine
              compteur+=1;
    }

// check si c'est le bon mot de passe
for (int i=0 ; i<=w.getSizeTemps() ; i++){
        if (w.getLettre(i) == m.getLettre(i)&& mdp == true)
            mdp = true;
        else
            mdp = false;
}

// Si c'est le bon on affiche le taux de réussite
if (mdp == true){
    if (compteur > 8*w.getSizeTemps()/10)
        cbon = true;
    else
        cbon = false;

        std::cout << std::endl << "reussite = " << compteur << "/" << w.getSizeTemps() << std::endl;
        std::cout << "reussite = " << compteur*100/w.getSizeTemps() << "%" << std::endl;
        }
    else
    {
        cbon = false;
    }

return cbon;

}


