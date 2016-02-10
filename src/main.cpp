#include <iostream>
#include <fstream>
#include <iterator>
#include "matrix.hpp"
#include <vector>
#include "objects.hpp"
using namespace std;


void readInstance(const char* nom_fichier,int& n, int& m, Matrix2D<int>& image ) {

  
  char char1;
   
	
	ifstream fichier(nom_fichier);
	if(fichier) {
		//pour n
		fichier >> n  >> m >> char1;
		cout <<"n="<< n <<", m=" << m <<"\n";
		
		image=Matrix2D<int>(n,m);
		
		for(int i=0;i<n;i++) {

			for(int j=0;j<m;j++) {
				fichier >> char1;
				if(char1=='#') image(i, j)=1;
				else image(i,j)=0;
				
			} 
			fichier >>char1; //lit "\n"
		}
	}
	else cout << "Fichier non trouvé!! \n";
}




vector<Case> aPeindre(int const& n, int const& m, Matrix2D<int> const& image, vector<Case>& casesAPeindre){


	for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
			  if(image(i,j)==1){Case CaseAPeindre(i,j);
			                    casesAPeindre.push_back(CaseAPeindre);
			  }
			}
	}
	return casesAPeindre;

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
  
  vector<Case> casesAPeindre;
  aPeindre(n,m,image,casesAPeindre);

  vector<Case>::iterator iter;

  iter = casesAPeindre.begin();

  for(vector<Case>::iterator iter=casesAPeindre.begin(); iter != casesAPeindre.end();++iter){
    (*iter).print();} 

	
            return 0;
}
