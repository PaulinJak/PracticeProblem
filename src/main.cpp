#include <iostream>
#include <fstream>
#include <iterator>
#include "matrix.hpp"
#include <vector>
using namespace std;


void readInstance(const char* nom_fichier,int& n, int& m, Matrix2D<int>& image ) {

  
  char char1;
   
	
	ifstream fichier(nom_fichier);
	if(fichier) {
		//pour n
		fichier >> n  >> m >> char1;
		cout <<"n="<< n <<", m=" << m <<"\n";
        
		 
		for(int i=0;i<n;i++) {

			for(int j=0;j<m;j++) {
				fichier >> char1;
				if(char1=='#') imag(i, j)=1;
				else image(i,j)=0;
				
			} 
			fichier >>char1; //lit "\n"
		}
	}
	else cout << "Fichier non trouvé!! \n";
}


class Case{

public:
  int i;
  int j;
}

  vector<Case> aPeindre(int const& n, int const& m, Matrix const& image){

    vector<Case> casesAPeindre();

	for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
			  if(image(i,j)==1){case new
			    casesAPeindre.insert(

  } 


int main(int argc, char* argv[])
{
   const char*  fileName;
  if(argc>1)//we passed the filename in arg
    fileName=argv[1];
  else fileName = "instances/logo.in";
  
  Matrix2D<int> image;
  int n=0,m=0;
  
  readInstance(fileName,n,m,image);
  
  
            return 0;
}
