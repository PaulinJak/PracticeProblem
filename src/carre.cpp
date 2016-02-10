#include "matrix.hpp"

void fcarre(const Matrix2D<int> &image, Matrix2D<int> &carre, Matrix2D<int> &carre_score,const int i, const int j ){
    if (image(i, j) == 0){
        carre(i, j) = 0;
        carre_score(i, j) = 0;
        return;
    }
    int score=0;
    int valid_score = 0;
    bool go_on=true;
    int rayon=1;
    while (go_on){

        for(int k=i-rayon, k<i+rayon, k++ ){
           
        }
        for(int k=i-rayon, k<i+rayon, k++ ){
            
        }
        for(int k=i-rayon, k<i+rayon, k++ ){
            
        }
        for(int k=i-rayon, k<i+rayon, k++ ){
            
        }

    }
}


