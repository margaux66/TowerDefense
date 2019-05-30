#include "../include/checkMap.h"

using namespace std;

checkMap::checkMap(){

};
checkMap::~checkMap(){

};

int checkMap::checkItd (){
	ifstream itd;
	itd.open(this->getPath()); 
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
			//else{
			//	cout<< "OKKKK \n";
			//}

			getline(itd, ligne);
			//cout<< ligne<< "\n";
			if(ligne.compare("#premiere ligne de commentaire") != 0){
			 	cout <<"Le fichier n'est pas une carte valide.\n";
			 	itd.close();
			 	return 0;
			}
			//else{
			//	cout<< "OKKKK \n";
			//}

			//getline(itd, ligne);

			string word;
			itd>>word;
			//cout<<word<<"\n";
			if(word.compare("carte") == 0){
			 	string fichierPPM;
				itd>> fichierPPM;
				//cout<< fichierPPM <<"\n";
				this->setImage(fichierPPM);
			}
			else {
			 	cout<< "Pb avec la ligne carte\n";
			 	itd.close();
			  	return 0;
			}

			itd>>word;
			vector<int> chemin;
			if(word.compare("chemin") == 0){
				//int r, v ,b;
				itd>> r;
				itd>> g;
				itd>> b;
				//chemin[0]=r;
				//chemin[1]=g;
				//chemin[2]=b;
				chemin.push_back(r);
				chemin.push_back(g);
				chemin.push_back(b);
				this->setChemin(chemin);
			}
			else {
			 	cout<< "Pb avec le chemin\n";
			 	itd.close();
			  	return 0;
			}


			itd>>word;
			vector<int> construct;
			if(word.compare("construct") == 0){
				//int r, v ,b;
				itd>> r;
				itd>> g;
				itd>> b;
				construct.push_back(r);
				construct.push_back(g);
				construct.push_back(b);
				this->setConstruct(construct);
			}
			else {
			 	cout<< "Pb avec le construct\n";
			 	itd.close();
			  	return 0;
			}

			itd>>word;
			vector<int> in;
			if(word.compare("in") == 0){
				//int r, v ,b;
				itd>> r;
				itd>> g;
				itd>> b;
				in.push_back(r);
				in.push_back(g);
				in.push_back(b);
				this->setIn(in);
			}
			else {
			 	cout<< "Pb avec le in\n";
			 	itd.close();
			  	return 0;
			}

			itd>>word;
			vector<int> out;
			if(word.compare("out") == 0){
				//outt r, v ,b;
				itd>> r;
				itd>> g;
				itd>> b;
				out.push_back(r);
				out.push_back(g);
				out.push_back(b);
				this->setOut(out);
			}
			else {
			 	cout<< "Pb avec le out\n";
			 	itd.close();
			  	return 0;
			}

			itd>>word;
			vector<int> nodeColor;
			if(word.compare("noeud") == 0){
				//outt r, v ,b;
				itd>> r;
				itd>> g;
				itd>> b;
				nodeColor.push_back(r);
				nodeColor.push_back(g);
				nodeColor.push_back(b);
				this->setNodeColor(nodeColor);
			}
			else {
			 	cout<< "Pb avec le out\n";
			 	itd.close();
			  	return 0;
			}


			itd>>nb_node;
			//cout << nb_node<< "\n";
			itd.seekg(1, itd.cur);
			this->setNbNode(nb_node);

			vector<vector<int>> nodes;
			while(getline(itd, ligne)){
				vector<int> node;
				int composante;
				istringstream row(ligne);
				while(row>>composante){
					node.push_back(composante);
				}
				nodes.push_back(node);
				count = count+1;
			}
			if ((count) != nb_node){
				cout<< "Pb avec les noeuds\n";
			 	itd.close();
			  	return 0;
			}
			cout.flush();
			this->setNode(nodes);			

			itd.close();

			cout << "Fichier .itd valide ! \n";
	 	}

	 else{
	 	cout << "Erreur à l'ouverture du fichier! \n";
	 	return 0;
	 }
	 return 1;
}

int checkMap::checkedMap(){
	//int nb_node = map.getNbNode();
	if(this->checkItd()==1){
		this->loadPPM();
		vector<int> pixels = this->getData();
		//cout << pixels[(3*22+3*170)+1] << "\n";
		cout << this->getPixel(pixels,10,20,2) << "\n";
		vector<vector<int>>nodes = this->getNode();
		for(int i =0; i<nodes.size();i++){
			switch(nodes[i][1]){
				case 1:
					if(this->getPixel(pixels,nodes[i][2],nodes[i][3],1)==this->getIn()[0]){
						cout << "ok "<< i<<" \n";
					}
					if(this->getPixel(pixels,nodes[i][2],nodes[i][3],2)==this->getIn()[1]){
						cout << "ok 2 "<< i<<" \n";
					}
					if(this->getPixel(pixels,nodes[i][2],nodes[i][3],3)==this->getIn()[2]){
						cout << "ok 3 "<< i<<" \n";
					}
					//else{
					//	cout << "gros soucy \n";
					//}
					cout << getPixel(pixels,nodes[i][2],nodes[i][3],0);
				case 2:
					if(this->getPixel(pixels,nodes[i][2],nodes[i][3],1)==this->getOut()[0]){
						cout << "ok "<< i<<" \n";
					}
					if(this->getPixel(pixels,nodes[i][2],nodes[i][3],2)==this->getOut()[1]){
						cout << "ok 2 "<< i<<" \n";
					}
					if(this->getPixel(pixels,nodes[i][2],nodes[i][3],3)==this->getOut()[2]){
						cout << "ok 3 "<< i<<" \n";
					}
			}
		}
		//cout << "\n" << nodes[0][0];
	}	


	return 0;
}

int checkMap::loadPPM(){
	ifstream ppm;
	ppm.open(this->getImage());
	string element;
	ppm >> element;
	if(element.compare("P3")!=0){
		cout << "Problème avec le format PPM " << element << " au lieu de P3 \n";
		return 0;
	}
	for(int i = 0; i<3; i++){
		ppm >> element;
	}
	vector<int> pixels;
	int composante;
	while(ppm >> composante){
		pixels.push_back(composante);
	}
	this->setData(pixels);
	return 0;
}

int checkMap::getPixel(vector<int> pixels, int x, int y, int composante){
	return pixels[(3*x+3*y)+composante];
}

void bresenham_x_y(int start_x, int start_y, int end_x, int end_y,
									 void (*visitor)(int, int, int, void**), int argc, void** argv)
{
	int dx = abs(end_x - start_x);
	int dy = abs(end_y - start_y);

	int inc_ex=dy*2, inc_ey=-dx*2;
	int e=-dx;
	int inc_y = end_y > start_y ? 1 : -1;
	int inc_x = end_x > start_x ? 1 : -1;
	int x=start_x, y=start_y;
	if (inc_x>0)
	{
		while (x<end_x)
		{
			(*visitor)(x, y, argc, argv);
			++x;
			e+=inc_ex;
			if (e>0)
			{
				y+=inc_y;
				e+=inc_ey;
			}
		}
	}
	else
	{
		while (x>end_x)
		{
			(*visitor)(x, y, argc, argv);
			--x;
			e+=inc_ex;
			if (e>0)
			{
				y+=inc_y;
				e+=inc_ey;
			}
		}
	}
	(*visitor)(x, y, argc, argv);
}

void bresenham_y_x(int start_x, int start_y, int end_x, int end_y,
									 void (*visitor)(int, int, int, void**), int argc, void** argv)
{
	int dx = abs(end_x - start_x);
	int dy = abs(end_y - start_y);

	int inc_ex=-dy*2, inc_ey=dx*2;
	int e=-dy;
	int inc_y = end_y > start_y ? 1 : -1;
	int inc_x = end_x > start_x ? 1 : -1;
	int x=start_x, y=start_y;
	if (inc_y>0)
	{
		while (y<end_y)
		{
			(*visitor)(x, y, argc, argv);
			++y;
			e+=inc_ey;
			if (e>0)
			{
				x+=inc_x;
				e+=inc_ex;
			}
		}
	}
	else
	{
		while (y>end_y)
		{
			(*visitor)(x, y, argc, argv);
			--y;
			e+=inc_ey;
			if (e>0)
			{
				x+=inc_x;
				e+=inc_ex;
			}
		}
	}
	(*visitor)(x, y, argc, argv);
}
