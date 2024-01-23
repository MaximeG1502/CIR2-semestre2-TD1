//============================================================================
// Name : generationMots.cpp
// Author : SaPlanque
//============================================================================c
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

void Suivant(string &motCourant, vector<char> &lettresTriees);
void Generateur(string &premierMot, vector<char> &lettresTriees);

int main() {
 
    vector<char> lettresDuMotAlgo { 'A', 'L', 'G', 'O', 'R', 'I', 'T', 'H', 'M', 'E' };

    cout << endl << "lettresDuMotAlgo avant Sort : ";

    for (auto element : lettresDuMotAlgo)   cout << " " << element;

    sort(lettresDuMotAlgo.begin(), lettresDuMotAlgo.end());

    cout << endl << "lettresDuMotAlgo après Sort : ";

    for (auto element : lettresDuMotAlgo) cout << " " << element;

    string premierMot(lettresDuMotAlgo.size(), *lettresDuMotAlgo.begin());

    cout << endl << "Premier mot : " << premierMot;

    Generateur(premierMot, lettresDuMotAlgo);

    cout << endl << "main() parcouru." << premierMot;

    return 0;
}


void Suivant(string &motCourant, vector<char> &lettresTriees) {
    /*
    * last char'
    */
    int derniereLettre = lettresTriees.size() - 1;
    int i = derniereLettre;
    /* Les derniers seront les premiers... */
    while (motCourant[i] == lettresTriees[derniereLettre]) {
    motCourant[i--] = lettresTriees[0];
    }
    auto itLettreSuivante = std::find(lettresTriees.begin(),lettresTriees.end(), motCourant[i]);
    /* Il existe forcément (pas de test) */
    motCourant[i] = *(++itLettreSuivante);
}

void Generateur(string &premierMot, vector<char> &lettresTriees) {
    int verifierNombreMots = 1;
    string motCourant(premierMot);
    string dernierMot(lettresTriees.size(), *(--lettresTriees.end()));
    cout << endl << "\t> " << motCourant << " <";
    while (motCourant.compare(dernierMot)) {
        Suivant(motCourant, lettresTriees);
        verifierNombreMots++;
        cout << endl << "\t> " << motCourant << " <";   
    }

    if ( verifierNombreMots == pow(lettresTriees.size(), lettresTriees.size()))
    {
        cout<<" Generation de "<<verifierNombreMots<<" mots comme attendu. " <<
        endl;
    }
    else
    {
        cout<<" Generation de " <<verifierNombreMots <<" alors que " 
            << pow(lettresTriees.size(), lettresTriees.size()) << " étaient attendus." << endl;
    }
}   
