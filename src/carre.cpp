#include "matrix.hpp"

void fcarre(const Matrix2D<int> &image, Matrix2D<int> &carre, Matrix2D<int> &carre_score,const int i, const int j ){
    if (image(i, j) == 0){
        carre(i, j) = 0;
        carre_score(i, j) = 0;
        return;
    }

    int score=1;
    int valid_score = 1;
    bool go_on=true;
    int rayon=1;

    int left;
    int right;
    int up;
    int down;

    while (go_on){
        left  = j-rayon;
        right = j+rayon;
        up    = i-rayon;
        down  = i+rayon;
        if ((left<0)||(right>=image.width())||(up<0)||(down>=image.height())){
            go_on= false;
            break;
        }
        //en haut
        for(int k=left; k<=right; k++ ){
            switch (image(up,k)){
                case 0:
                    go_on=false;
                    break;
                case 1:
                    score++;
                    break;
                default:
                ;//ok but no score update
            }
        }
        if (!go_on) break;
        //a droite
        for(int k=up+1; k<=down-1; k++ ){
            switch (image(k,right)){
                case 0:
                    go_on=false;
                    break;
                case 1:
                    score++;
                    break;
                default:
                ;//ok but no score update
            }

        }
        if (!go_on) break;
        //en bas
        for(int k=left; k<=right; k++ ){
            switch (image(down,k)){
                case 0:
                    go_on=false;
                    break;
                case 1:
                    score++;
                    break;
                default:
                ;//ok but no score update
            }
        }
        if (!go_on) break;
        //a gauche
        for(int k=up+1; k<=down-1; k++ ){
            switch (image(k,left)){
                case 0:
                    go_on=false;
                    break;
                case 1:
                    score++;
                    break;
                default:
                ;//ok but no score update
            }
        }
        if (!go_on) break;
        valid_score = score;
        rayon++;
   }
   rayon--;
   carre_score(i,j) = valid_score;
   carre(i,j) = rayon;
}


