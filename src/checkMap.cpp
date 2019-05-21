#include "../include/checkMap.h"

int checkItd (checkMap ckeckMap){
	ifstream itd;
	itd.open(checkMap.path); 
	string img;
	int r, g, b;
	int nb_node;
	int count = 0;

	 	if(itd.is_open()){
			string ligne;		
			getline(itd,ligne);

			if(ligne.compare("@ITD 1") != 0){
				cout <<"Le fichier  n'est pas une carte valide.\n";
				itd.close();
				return 0;
			}
			else{
				cout<< "OKKKK \n";
			}

			getline(itd, ligne);
			cout<< ligne<< "\n";
			if(ligne.compare("#premiere ligne de commentaire") != 0){
			 	cout <<"Le fichier n'est pas une carte valide.\n";
			 	itd.close();
			 	return 0;
			}
			else{
				cout<< "OKKKK \n";
			}

			//getline(itd, ligne);

			string word;
			itd>>word;
			cout<<word<<"\n";
			if(word.compare("carte") == 0){
			 	string fichierPPM;
				itd>> fichierPPM;
				cout<< fichierPPM <<"\n";
				ckeckMap.setImage(fichierPPM);
			}
			else {
			 	cout<< "Pb avec la ligne carte\n";
			 	itd.close();
			  	return 0;
			}

			itd>>word;
			array<int,3> chemin{r,g,b};
			if(word.compare("chemin") == 0){
				//int r, v ,b;
				itd>> r;
				itd>> g;
				itd>> b;
				chemin[0]=r;
				chemin[1]=g;
				chemin[2]=b;
				ckeckMap.setChemin(chemin);
			}
			else {
			 	cout<< "Pb avec le chemin\n";
			 	itd.close();
			  	return 0;
			}


			itd>>word;
			array<int,3> construct{r,g,b};
			if(word.compare("construct") == 0){
				//int r, v ,b;
				itd>> r;
				itd>> g;
				itd>> b;
				construct[0]=r;
				construct[1]=g;
				construct[2]=b;
				ckeckMap.setConstruct(construct);
			}
			else {
			 	cout<< "Pb avec le construct\n";
			 	itd.close();
			  	return 0;
			}

			itd>>word;
			array<int,3> in{r,g,b};
			if(word.compare("in") == 0){
				//int r, v ,b;
				itd>> r;
				itd>> g;
				itd>> b;
				in[0]=r;
				in[1]=g;
				in[2]=b;
				ckeckMap.setIn(in);
			}
			else {
			 	cout<< "Pb avec le in\n";
			 	itd.close();
			  	return 0;
			}

			itd>>word;
			array<int,3> out{r,g,b};
			if(word.compare("out") == 0){
				//outt r, v ,b;
				itd>> r;
				itd>> g;
				itd>> b;
				out[0]=r;
				out[1]=g;
				out[2]=b;
				ckeckMap.setOut(out);
			}
			else {
			 	cout<< "Pb avec le out\n";
			 	itd.close();
			  	return 0;
			}

			itd>>nb_node;
			cout << nb_node<< "\n";
			checkMap.setNbNode(nb_node);
			array<string,10> node;
			while(getline(itd, ligne)){
				node[count]=ligne;
				cout <<node[count]<<"\n";
				count = count+1;
			}
			if ((count-1) != nb_node){
				cout<< "Pb avec les noeuds\n";
			 	itd.close();
			  	return 0;
			}
						

			itd.close();
	 	}

	 else{
	 	cout << "Erreur à l'ouverture du fichier!";
	 	return 0;
	 }
	 return 1;
}

int checkMap(checkMap checkMap){
	int nb_node = checkMap.getNbNode();
	int i,j,c;
	for(i=0 ; i< 200 ; i++){
		for(j=0; j< 200; j++){
			for (c=0; c<3; c++){


			}
		}
	}
}

