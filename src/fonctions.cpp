//
//  fonctions.cpp
//
//
//  Created by Maud Doumergue on 10/02/2016.
//
//

#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include "matrix.hpp"
#include "objects.hpp"
using namespace std;



// LES LIGNES
void f_lignes(int n, int m, Matrix2D<int>& image, Matrix2D<int>& lignes, Matrix2D<int>& lignes_score){
    for (int i = 0; i<n; i++) {
        int j = 0;
        while (j<m) {
            int cpt = 0;
            while (((cpt+j)<m)&&(image(i,j+cpt)==1)) {
                cpt++;
            }
            lignes(i,j) = cpt;
            lignes_score(i,j) = cpt;
            j += cpt+1;
        }
    }
}


void f_lignes_point(int n, int m, int i0, int j0, Matrix2D<int>& image, Matrix2D<int>& lignes, Matrix2D<int>& lignes_score){
    
    if((j0 != 0)&&(image(i0,j0-1)>0)){ // on n'est pas au debut d une ligne a colorier
        lignes_score(i0,j0) = 0;
    }
    else{
        int cpt = 0;
        int cpt_2 = 0;
        while (((cpt+j0)<m)&&(image(i0,j0+cpt)>0)) {
            cpt++;
            if(image(i0,j0+cpt)>1){
                cpt_2++;
            }
        }
        lignes_score(i0,j0) = cpt-cpt_2;
    }
}


// LES COLONNES


void f_colonnes(int n, int m, Matrix2D<int>& image, Matrix2D<int>& colonnes, Matrix2D<int>& colonnes_score){
    for (int j = 0; j<m; j++) {
        int i = 0;
        while (i<n) {
            int cpt = 0;
            while (((cpt+i)<n)&&(image(i+cpt,j)==1)) {
                cpt++;
            }
            colonnes(i,j) = cpt;
            colonnes_score(i,j) = cpt;
            i += cpt+1;
        }
    }
}


void f_colonnes_point(int n, int m, int i0, int j0, Matrix2D<int>& image, Matrix2D<int>& colonnes, Matrix2D<int>& colonnes_score){
    
    if((i0 != 0)&&(image(i0-1,j0)>0)){ // on n'est pas au debut d une colonne a colorier
        colonnes_score(i0,j0) = 0;
    }
    else{
        int cpt = 0;
        int cpt_2 = 0;
        while (((cpt+i0)<n)&&(image(i0+cpt,j0)>0)) {
            cpt++;
            if(image(i0+cpt,j0)>1){
                cpt_2++;
            }
        }
        colonnes_score(i0,j0) = cpt-cpt_2;
    }
}


//
Case choix_next_move(int n,int m, Matrix2D<int>& image, Matrix2D<int>& colonnes, Matrix2D<int>& colonnes_score, Matrix2D<int>& lignes, Matrix2D<int>& lignes_score, Matrix2D<int>& carre, Matrix2D<int>& carre_score, vector<Case>& casesAPeindre){

    int score, type, taille, i0=0, j0=0;
    type = -1;
    score = 0;
    taille = 0;
    i0 = 0;
    j0 = 0;
    
    for( vector<Case>::iterator it=casesAPeindre.begin() ; it < casesAPeindre.end(); it++) {
        //cout << it->i <<" " << it->j << endl;
        //cout << score << endl;
        //cout << carre_score(it->i, it->j) << endl;
        
        
        if(carre_score(it->i, it->j)> score){
            score = carre_score(it->i, it->j);
            type = 0;
            taille = carre(it->i, it->j);
            i0=it->i;
            j0 = it->j;
        }
        if(lignes_score(it->i, it->j)>score){
            score = lignes_score(it->i, it->j);
            type = 1;
            taille = lignes(it->i, it->j);
            i0=it->i;
            j0 = it->j;
        }
        if(colonnes_score(it->i, it->j)>score){
            score = colonnes_score(it->i, it->j);
            type = 2;
            taille = colonnes(it->i, it->j);
            i0=it->i;
            j0 = it->j;
        }
    }
    
//    cout << i0 << " " << j0 << endl;
//    cout << type << " " << taille << " " << score << endl;
    
    switch (type) {
        case 0:
            cout << "PAINT_SQUARE "<< i0 <<" " << j0 <<" " << taille << endl;
            
            for (int l= i0-taille ; l <= i0+taille; l++) {
                for (int c= j0-taille ; c <= j0+taille; c++) {
                    image(l,c)=2;

                }
            }
            
            break;
            
        case 1:
            cout << "PAINT_LINE "<< i0 <<" " << j0 << " " << i0 <<" " << j0 + taille - 1 << endl;
            
            for (int c= j0 ; c <= j0+(taille-1); c++) {
                image(i0,c)=2;
                
            }
            
            break;
            
        case 2:
            cout << "PAINT_LINE "<< i0 <<" " << j0 << " " << i0  + taille - 1 <<" " << j0 << endl;
            
            for (int l= i0 ; l <= i0+(taille-1); l++) {
                image(l,j0)=2;
            }
            break;
            
        default:
            // cout << " PROBLEME" << endl;
            // Ou fin
            break;
    }
    
    return Case(i0, j0);
}





