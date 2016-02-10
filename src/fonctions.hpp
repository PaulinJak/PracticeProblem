//
//  fonctions.hpp
//  
//
//  Created by Maud Doumergue on 10/02/2016.
//
//

#ifndef fonctions_hpp
#define fonctions_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include "matrix.hpp"
#include "objects.hpp"
using namespace std;

void f_lignes(int n, int m, Matrix2D<int>& image, Matrix2D<int>& lignes, Matrix2D<int>& lignes_score);

void f_lignes_point(int n, int m, int i0, int j0, Matrix2D<int>& image, Matrix2D<int>& lignes, Matrix2D<int>& lignes_score);
    
    
void f_colonnes(int n, int m, Matrix2D<int>& image, Matrix2D<int>& colonnes, Matrix2D<int>& colonnes_score);
    
void f_colonnes_point(int n, int m, int i0, int j0, Matrix2D<int>& image, Matrix2D<int>& colonnes, Matrix2D<int>& colonnes_score);
    

void choix_next_move(int n,int m, Matrix2D<int>& image, Matrix2D<int>& colonnes, Matrix2D<int>& colonnes_score, Matrix2D<int>& lignes, Matrix2D<int>& lignes_score, Matrix2D<int>& carre, Matrix2D<int>& carre_score, vector<Case> casesAPeindre);


#endif /* fonctions_hpp */
