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
//
// Notes: 
//
// Point d'entrée de slide-show

#include "SlideShow.hpp"
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
    /*
    * TODO: Complétez le code ici ...
    *
    * Le but est de :
    * - tenir compte du fichier passé en argument de l'exécutable
    * - utiliser un objet SlideShow pour afficher aléatoirement sur la sortie standard,
    *   un nom de fichier (image) contenu dans le fichier passé en argument
    */

    if(argc >= 1){
		if(argv[1] != (char*)""){
			string chemin = (string)argv[1];
			SlideShow lemien(chemin.c_str());
			lemien.init();
			while(1){
				lemien.displayRandomSlide(&cout);
				chrono::system_clock::time_point timePoint = chrono::system_clock::now() + std::chrono::seconds(2);	// https://thispointer.com/how-to-put-a-thread-to-sleep-in-c11-sleep_for-sleep_until/
				this_thread::sleep_until(timePoint);
			}
		}
	}
    
    return 0;
}
