// Copyright (C) 2017 Ange Abou - Polytech'Nice
//
// Ce programme est un logiciel libre; Il peut être redistribué et/ou
// modifié sous les termes de la "GNU General Public License" (Licence
// Générale Publique GNU) comme publiés par la Free Software Foundation;
// soit la version 2, soit (au choix) toute version ultérieure.
//
// Ce programme a une vocation éducative, et est distribué sans aucune
// garantie de fonctionnement; sans la garantie implicite de pouvoir 
// le commercialiser ou même de répondre à un besoin particulier.
// Se référer à la "GNU General Public License" pour plus de détails.
//
// Date de création: Mai 2017

#include "SlideShow.hpp"
#include <iostream>
// Pour générer des valeurs entières aléatoires uniformément réparties
#include <random>

using namespace std;


#define CHECK_IF_INITIALISED() \
    if (!_isInitialised) { \
        cerr << "Attention: appeler d'abord init sur objet SlideShow." << endl;\
        return 0;\
    }

/* */
SlideShow::SlideShow(const char* iFilePath) 
    : _filepath(iFilePath)
    , _filestream(iFilePath)
    , _nbFilelines(0) 
    , _isInitialised(false) {
    
}

/* */
SlideShow::SlideShow(const std::string iFilePath) 
    : SlideShow(iFilePath.c_str()) {
    // Ce constructeur avec paramètre 'const string' réutilise le constructeur
    // précédent avec paramètre 'const char*'
}
 
/* */
bool SlideShow::init() {
    
    ifstream _filestream(_filepath, ifstream::in);
    if (_filestream.good()) {
        this->_nbFilelines = 0;
        string ligne;
        while(getline(_filestream, ligne)){
            this->_nbFilelines++;
        }
        
        this->_isInitialised=true;
    } else {
        
        cerr << "Erreur: impossible d'ouvrir le fichier." << endl;
        this->_isInitialised=false;
        return false;
    }
    
    return true;
}

const std::uint64_t SlideShow::getNumberOfSlides() {
    CHECK_IF_INITIALISED();
    
    return _nbFilelines;
}

/*
 http://fr.cppreference.com/w/cpp/numeric/random/uniform_int_distribution
 Pour produire des valeurs entières aléatoires uniformément réparties
 */
const std::uint64_t SlideShow::getRandomNumber() {
    CHECK_IF_INITIALISED();
    
    static random_device rd;
    static mt19937 gen(rd()); // générateur
    static uniform_int_distribution<> dis(1, this->_nbFilelines);
    /*
    * TODO: Expliquez dans les commentaires 
    * 
    * - Pourquoi on utilise le mot clé 'static' ici ? (Contrairement au code en ligne)
    *   Pour que la variable n'existe qu'en un seul exemplaire.
    * - Modifiez le code pour choisir les nombres aléatoires jusqu'au nombre de slides
    */
    
    return dis(gen);
}

const std::uint8_t SlideShow::displayRandomSlide(std::ostream* out) {
    std::uint8_t rc = 0; // code de retour si OK
    if (!_isInitialised) {
        cerr << "Attention: appeler d'abord init sur objet SlideShow." << endl;
        rc = 1; // code d'erreur si non initialisé
    }
    else{
        uint64_t random = getRandomNumber();
        string slide;
        this->_filestream.seekg(0,ios::beg);        // Replace le curseur au début du fichier

        for(uint64_t i = 0 ; i < random; i++) {
            getline(this->_filestream, slide);
        }
        *out<<slide<<endl;
        rc = 0;
    }
    
    /*
    * TODO: complétez le code ...
    * 
    * Le but est d'afficher sur la sortie standard, de façon aléatoire,
    * le contenu d'une ligne du fichier
    * correspondant au nombre aléatoire obtenu
    */
    *out << endl;
    
    return rc;
}
