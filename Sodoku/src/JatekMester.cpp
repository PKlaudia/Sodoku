#include "JatekMester.hpp"
#include "graphics.hpp"
#include "Widget.hpp"
#include "time.h"
#include "SodokuBox.hpp"
#include "iostream"
#include <vector>

using namespace std;
JatekMester::JatekMester(std::vector<std::vector<SodokuBox*>> &b)

{
boxes = b;
numbers={
                {3,6,8, 4,2,5,  1,9,7},
                {5,9,1, 3,8,7,  6,4,2},
                {2,4,7, 1,6,9,  3,5,8},

                {7,1,3, 6,5,4,  8,2,9},
                {9,2,5, 8,3,1,  7,6,4},
                {6,8,4, 9,7,2,  5,1,3},

                {4,5,2, 7,1,3,  9,8,6},
                {8,7,9, 5,4,6,  2,3,1},
                {1,3,6, 2,9,8,  4,7,5}}
        ;

    //ctor
}

JatekMester::~JatekMester()
{
    //dtor
}

void JatekMester::check()
{
    int r_start;
    int r_end;
    int c_start;
    int c_end;

    int mistakes =0;
for(int i=0;i<9;i++){
    for(int j=0; j<9; j++){
mistakes =0;
    which_box(r_end,c_end,r_start,c_start,i,j);
            for(int k=0;k<9; k++){//oszlopban
                if(k!=i){
                if(boxes[k][j]->getInNumber() != 0 && boxes[k][j]->getInNumber() == boxes[i][j]->getInNumber()){

                 boxes[i][j]->setMistake(true);

                 boxes[i][j]->setRGB(255,0,0);
                 mistakes++;
                }
                if(boxes[i][j]->getInNumber()==0){
                    boxes[i][j]->setMistake(false);
                    boxes[i][j]->setRGB(255,255,255);
                }
                }
            }
            for(int k=0; k<9; k++){//sor
                if(k!=j){
                  if(boxes[i][k]->getInNumber() != 0 && boxes[i][k]->getInNumber() == boxes[i][j]->getInNumber()){

                 boxes[i][j]->setMistake(true);

                 boxes[i][j]->setRGB(255,0,0);
                 mistakes++;
                }
                if(boxes[i][j]->getInNumber()==0){
                    boxes[i][j]->setMistake(false);
                    boxes[i][j]->setRGB(255,255,255);
                }

                }
            }
            for(int k=r_start; k<r_end;k++){
                for(int h=c_start; h<c_end; h++){
                        if(k!=i || j!=h){

                    if(boxes[k][h]->getInNumber() !=0 &&boxes[k][h]->getInNumber() == boxes[i][j]->getInNumber()){

                 boxes[i][j]->setMistake(true);

                 boxes[i][j]->setRGB(255,0,0);
                 mistakes++;

                        }
                        }
                }
            }


if(mistakes==0){
    boxes[i][j]->setRGB(255,255,255);
}
}



}
}


void JatekMester::generateSodoku(){
/*shuffle numbers*/
srand(time(NULL));
int n = rand()%8 +1 ;
int n2 = rand()%8 +1 ;

while (n==n2){
 n = rand()%8+1;
}

for(int i=0; i<9;i++){
        for(int j=0; j<9; j++){


                 if(numbers[i][j] == n){
                     boxes[i][j]->setProperties(n2,0,n2);

                 }else if(numbers[i][j] == n2){
                       boxes[i][j]->setProperties(n,0,n);
                 }else{
                     boxes[i][j]->setProperties(numbers[i][j],0,numbers[i][j]);
                 }

        }

}
bool solvable;


int h_box = 0;


while(h_box<38){

int col_rand = rand()%9;
int row_rand = rand()%9;
if(!boxes[row_rand][col_rand]->getHide()){
boxes[row_rand][col_rand]->setHide(true);
//cout<< row_rand << "  "<<col_rand<<endl;
solvable = solve(row_rand,col_rand);
if(!solvable){

boxes[row_rand][col_rand]->setHide(false);
//cout << "unsolvable"<<endl;
}else{
h_box++;
boxes[row_rand][col_rand]->setHide(true);
//cout<<"solvable"<<endl;
}

}
}





}


bool JatekMester::solve(int r, int c){
    int row=r;
    int col=c;
    bool solved = false;



bool found;

for(int i=1;i<10;i++){
    found=false;
    for(int j=0; j<9; j++){
            if(!boxes[row][j]->getHide()){
                if(boxes[row][j]->getValue() == i){
                    found = true;
                  // std::cout<<i<<"  "<<"van"<<std::endl; //A keresett szam nem jo
                }

            }

    }
    if(!found){//hianyzo szam: i
            bool num_good= true;
           // std::cout<<"hianyzik "<<i<<std::endl;
            //sajat oszlop ellenorzes, ha van i akkor nem jo (FALSE)
            for(int j=0; j<9; j++){
                if(!boxes[j][col]->getHide()){
                    if(boxes[j][col]->getValue() == i){
                        num_good =false;
                  //    std::cout << i <<" van az oszlopban " << j<<std::endl;
                    }
                }
            }
            if(num_good){
                //std::cout<< i <<" nincs az oszlopban"<<std::endl;
                           //ha a többi oszlopban van -- ha van i True
                int counter =0;
                 for(int j=0; j<9;j++){
                    for(int k=0; k<9; k++){
                        if(!boxes[j][k]->getHide()){
                            if(boxes[j][k]->getValue() == i){

                         //           cout<< i << "van a sorban "<<j<<endl;
                       counter++;
                    }
                }

                    }

                 }
                if(counter == 8){//vált
                    solved = true;
                   //      cout << "megoldas "<< i << endl;
                    return true;
                }else{
                //sorokban
                counter =0;
                  for(int j=0; j<9;j++){
                    for(int k=0; k<9; k++){
                        if(!boxes[k][j]->getHide()){
                            if(boxes[k][j]->getValue() == i){
                       //             cout<< i << "van az oszlopban "<<j<<endl;
                       counter++;
                    }
                }
                    }
                  }
                if(counter == 8){//valt
                    solved = true;
                  //  cout << "megoldas "<< i << endl;
                    return true;
                }else{
                //tömbök szerint
                int r_start =0;
                int r_end =0;
                int c_start =0;
                int c_end =0;
                    which_box(r_end,c_end, r_start,c_start,row,col);

                //leellenőrzi hogy a saját tömbjében van e
  for(int k=r_start; k<r_end; k++ ){
    for(int j=c_start; j<c_end; j++){
              if(!boxes[k][j]->getHide()){
                    if(boxes[k][j]->getValue() == i){
                 //      cout<< i << "van a tombben "<<endl;
                       num_good = false;
                    }
                }

    }
  }

  if(num_good){

           int rejtett_m_szam=0;
            int kieso_szam=0;

              for(int k=r_start; k<r_end; k++ ){

    for(int j=c_start; j<c_end; j++){
             bool kiesett= false;

              if(boxes[k][j]->getHide()){//rejtett
                    if(k!=r){//nem egyenlo onmagaval
                            rejtett_m_szam++;
                            for(int h=0;h<9;h++){//sorban
                                if(boxes[k][h]->getValue()==i && !boxes[k][h]->getHide()){
                                  kieso_szam++;
                                  kiesett=true;
                                }

                            }
                            if(kiesett){
                                for(int h=0; h<9;h++){
                                if(boxes[h][j]->getValue()==i && !boxes[h][j]->getHide()){
                                  kieso_szam++;
                                  kiesett=true;
                                }
                                }
                            }
                        }
                }

    }
  }
   if(kieso_szam == rejtett_m_szam){
     //   cout<< "megoldas "<< i <<endl;
    return true;
   }else{

   return false;
   }
  }
}


}



    }





    }}
return false;
}

void JatekMester::help(){
bool b;
bool ok=false;
while(!ok){
int col_rand = rand()%9;
int row_rand = rand()%9;
if(boxes[row_rand][col_rand]->getHide()){
  boxes[row_rand][col_rand]->setHide(false);
    ok=true;
}
}

}

void JatekMester::solveit(){
for(int i=0; i<9;i++){
    for(int j=0; j<9; j++){

            boxes[i][j]->setHide(false);

            }

}

}

void JatekMester::which_box(int &r_end, int &c_end, int &r_start, int &c_start, int r, int c){
 if( r < 3 && c< 3){//1.tömb
                        r_start =0;
                        r_end =3;
                        c_start =0;
                        c_end =3;
                        //cout << "1. tomb" <<endl;
                    }else if(r<3 &&c>2 && c<6){//2.tömb
                          r_start =0;
                          r_end =3;
                            c_start =3;
                            c_end =6;
                        //cout << "2. tomb" <<endl;
                    }else if(r<3&& c>5 && c<9){//3.tömb
                          r_start =0;
                r_end =3;
                c_start =6;
                c_end =9;

                    }else if(r>2 &&r<6 && c<3){//4tömb
                          r_start =3;
                r_end =6;
                c_start =0;
                c_end =3;
               // cout << "1. tomb" <<endl;
                    }else if(r>2 &&r<6 && c<6 && c>2){//5
                          r_start =3;
                r_end =6;
                c_start =3;
                c_end =6;
                //cout << "1. tomb" <<endl;
                    }else if(r>2 &&r<6 && c>5 && c<9){//6
                          r_start =3;
                r_end =6;
                c_start =6;
                c_end =9;
               // cout << "1. tomb" <<endl;
                    }else if(r>5 && r<9 && c<3 ){
                          r_start =6;
                r_end =9;
                c_start =0;
                c_end =3;
                //cout << "1. tomb" <<endl;
                    }else if(r>5 && r<9 &&c>2 && c<6){
                          r_start =6;
                r_end =9;
                c_start =3;
                c_end =6;
                //cout << "1. tomb" <<endl;
                    }else if(r>5 && r<9 &&c>5 && c<9){
                          r_start =6;
                r_end =9;
                c_start =6;
                c_end =9;

                    }

}



