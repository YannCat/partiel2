// Copyright (C) 2017 Ange Abou - Polytech'Nice
//
// Ce programme est un logiciel libre; Il peut �tre redistribu� et/ou
// modifi� sous les termes de la "GNU General Public License" (Licence
// G�n�rale Publique GNU) comme publi�s par la Free Software Foundation;
// soit la version 2, soit (au choix) toute version ult�rieure.
//
// Ce programme a une vocation �ducative, et est distribu� sans aucune
// garantie de fonctionnement; sans la garantie implicite de pouvoir 
// le commercialiser ou m�me de r�pondre � un besoin particulier.
// Se r�f�rer � la "GNU General Public License" pour plus de d�tails.
//
// Date de cr�ation: Mai 2017
//
// Notes: 
//
// Point d'entr�e de slide-show

#include "SlideShow.hpp"
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
    /*
    * TODO: Compl�tez le code ici ...
    *
    * Le but est de :
    * - tenir compte du fichier pass� en argument de l'ex�cutable
    * - utiliser un objet SlideShow pour afficher al�atoirement sur la sortie standard,
    *   un nom de fichier (image) contenu dans le fichier pass� en argument
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
