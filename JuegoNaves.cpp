#include <stdio.h>
#include <conio.h>
#include <cstdlib>
#include <windows.h>
#include <list>
using namespace std;
#define arr 72
#define aba 80
#define izq 75
#define der 77

void gotoxy(int x,int y){
    HANDLE hCon;
    hCon=GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X=x;
    dwPos.Y=y;
    SetConsoleCursorPosition(hCon,dwPos);
}
void OcultarCursor(){
    HANDLE hCon;
    hCon=GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO cci;
    cci.dwSize=50;
    cci.bVisible=false;
    SetConsoleCursorInfo(hCon,&cci);
}
void PUNTAJE(int p, int ar[],int _arrsize){
    int aux[_arrsize];
    int i,b,c;
    for(i=0; i<_arrsize; i++){
        aux[i]=ar[i];
    }

for (i=0; i<5; i++){
  if(ar[i]<p){ int b=i;
    for(c=i+1; c<5; c++){

         ar[c]=aux[b];
                b++;
                    }
         ar[i]=p;
         break;
                }

}
}

void LIMPIAR_PANT(){
  gotoxy(32,16); printf("                             ");
    gotoxy(32,17); printf("                           " );
    gotoxy(32,18); printf("                              ");
    gotoxy(32,19); printf("                               ");
    gotoxy(32,20); printf("                                        ");
     gotoxy(32,21); printf("                                          ");
        gotoxy(32,22); printf("                                          ");
    gotoxy(20,24);printf("                                                        ");
}
class NAVE{
 int x,y;
 int coraz, vida;
 public:
    NAVE(int _x, int _y, int _c, int _v):x(_x),y(_y),coraz(_c),vida(_v){}
    int X(){return x;}
    int Y(){return y;}
    int C(){return coraz;}
    int V(){return vida;}
    void CREAR();
    void BORRAR();
    void MOVER();
    void VIDA(){vida++;}
    void pintar_corazones();
    void MORIR ();
    void cor(){coraz--;}
    void Scor(){coraz++;}
};

void NAVE::CREAR(){
 gotoxy (x,y); printf  ("  %c",30);
 gotoxy (x,y+1); printf(" %c%c%c",40,207,41);
 gotoxy (x,y+2); printf("%c%c %c%c",30,190,190,30);
}
void NAVE::BORRAR(){
 gotoxy (x,y); printf  ("      ");
 gotoxy (x,y+1); printf("      ");
 gotoxy (x,y+2); printf("      ");
}
void NAVE::MOVER(){
 if(kbhit()){
        char tecla=getch();
        BORRAR();
        if(tecla==der && x+6<77) x++;
        if(tecla==izq && x>3)x--;
        if(tecla==arr && y>4)y--;
        if(tecla==aba && y+3<33)y++;
        CREAR();
            }
}
void NAVE::MORIR(){
    if(coraz==0){
       BORRAR();
        gotoxy (x,y);   printf  (" ** ");
        gotoxy (x,y+1); printf  ("****");
        gotoxy (x,y+2); printf  (" ** ");
        Sleep (200);
        BORRAR();
        gotoxy (x,y);   printf  ("* ** *");
        gotoxy (x,y+1); printf  (" **** ");
        gotoxy (x,y+2); printf  ("* ** *");
        Sleep(200);
        BORRAR();
        CREAR();
        vida--;
        coraz=3;
        pintar_corazones();

    }
}
void NAVE::pintar_corazones(){
    gotoxy (50,2); printf  ("Vidas");
    gotoxy (55,2); printf ("%d",vida);
    gotoxy (64,2); printf  ("Salud");
    gotoxy (70,2); printf  ("   ");
    for(int i=0; i< coraz; i++){
        gotoxy(70+i,2); printf("%c",3);
                           }
}

void limites(){
    for (int i=2; i<78; i++){
        gotoxy(i,3); printf ("%c", 205);
        gotoxy(i,33); printf ("%c", 205);
    }
    for (int i=4; i<33; i++){
        gotoxy(2,i); printf ("%c", 186);
        gotoxy(77,i); printf ("%c", 186);
    }
    gotoxy(2,3); printf ("%c",201 );
    gotoxy(2,33); printf ("%c",200);
    gotoxy(77,3); printf ("%c",187);
    gotoxy(77,33); printf ("%c",188);
}
class AST{
    int x,y;
public:
    AST(int _x, int _y):x(_x),y(_y){}
    int X(){return x;}
    int Y(){return y;}
    void CREAR_AST();
    void MOVER_AST();
    void CHOQUE(class NAVE &N);
};

void AST::MOVER_AST(){

     gotoxy(x,y); printf (" ");
     y++;
     if(y>32){
        x=rand()%71+4;
        y=4;
     }

    CREAR_AST();
}
void AST::CREAR_AST(){
     gotoxy(x,y); printf ("%c", 184);
}

void AST::CHOQUE(class NAVE &N){
if(x>=N.X() && x<N.X()+5 && y>=N.Y() && y<N.Y()+2){
    N.cor();
    N.BORRAR();
    N.CREAR();
    N.pintar_corazones();
    x=rand()%71+4;
        y=4;}
}
class CORAZON{
    int x,y;
public:
    CORAZON(int _x, int _y):x(_x),y(_y){}
    int X(){return x;}
    int Y(){return y;}
    void CREAR_COR();
    void IMPRIMIR_COR();
    void BORRAR();
    void CHOQUE(class NAVE &N);

};
void CORAZON::BORRAR(){
 gotoxy(x,y);printf(" ");
}

void CORAZON::CREAR_COR(){
    if(5==rand()%300){
        IMPRIMIR_COR();
    }

}
void CORAZON::IMPRIMIR_COR(){
    BORRAR();
     x=rand()%71+4;
     y=rand()%22+7;
     gotoxy(x,y); printf ("%c", 3);

}

void CORAZON::CHOQUE(class NAVE &N){
if(x>=N.X() && x<N.X()+6 && y>=N.Y() && y<N.Y()+3){
    N.Scor();
    N.BORRAR();
    N.CREAR();
    if (N.C()>3){
        N.cor();
        N.cor();
        N.cor();
        N.VIDA();
    }
    N.pintar_corazones();
    x=rand()%71+4;
        y=4;}
}

class BALA{
    int x,y;
public:
    BALA(int _x, int _y):x(_x),y(_y){}
    int X(){return x;}
    int Y(){return y;}
  void MOVER();
  bool fuera();
};
 void BALA::MOVER(){
 gotoxy(x,y); printf (" ");
    y--;
 gotoxy(x,y); printf("*");
}
bool BALA::fuera(){
    if(y==4) return true;
    else return false;
}

int main (){
int puntos,h,op,i,control,a, score[5]={0,0,0,0,0};
     bool gameover=false;
     FILE *archivo;
    limites();
    OcultarCursor();




do{ puntos-=puntos;
    gotoxy(10,2);printf("                  ");
    NAVE N(34,30,3,3);
    N.CREAR();
    N.pintar_corazones();
        CORAZON C1(rand()%74+4,rand()%32+4);
    list<BALA*> B;
    list<BALA*>::iterator it;
    list<AST*> A;
    list<AST*>::iterator itA;
    for(int i=0; i<6; i++){
          A.push_back(new AST(rand()%74+3,rand()%7+4));
    }
while(gameover==false){


        if(GetAsyncKeyState(0X20))

        B.push_back(new BALA(N.X()+2,N.Y()-1));

    for(it=B.begin(); it!=B.end();){
            (*it)->MOVER();
            if((*it)->fuera()){
                gotoxy((*it)->X(),(*it)->Y()); printf (" ");
                delete (*it);
                    it=B.erase(it);
            }
            else it++;
                }
         for(itA=A.begin(); itA!=A.end(); itA++){

                (*itA)->MOVER_AST();
                (*itA)->CHOQUE(N);
            }

 for(itA=A.begin(); itA!=A.end(); itA++){
             for(it=B.begin(); it!=B.end(); it++){
                if( (*itA)->X()==(*it)->X() && ( (*itA)->Y()+1 ==(*it)->Y() || (*itA)->Y()==(*it)->Y()) )
                    {
                    gotoxy((*it)->X(),(*it)->Y()); printf (" ");
                    delete (*it);
                    it=B.erase(it);

                    A.push_back(new AST (rand()%74+3,4));
                     gotoxy((*itA)->X(),(*itA)->Y()); printf (" ");
                    delete (*itA);
                    itA=A.erase(itA);
                    puntos+=50;
                    }

    }
}

    for(itA=A.begin(); itA!=A.end(); itA++){
        if((*itA)->X()==C1.X() && (*itA)->Y()==C1.Y()){
                C1.IMPRIMIR_COR();

                                                    }
                                            }
            for(it=B.begin(); it!=B.end(); it++){
             if((*it)->X()==C1.X() && (*it)->Y()==C1.Y()){
                C1.IMPRIMIR_COR();
             }
            }

        C1.CREAR_COR();C1.CHOQUE(N);
        gotoxy(10,2);printf("PUNTOS %d",puntos);


        N.MORIR();
        N.MOVER();
        Sleep(30);
        if(N.V()==0) gameover=true;
}
         archivo=fopen("SCORE.txt","rb");
         fread(&score,sizeof(score),100,archivo);
            PUNTAJE(puntos,score,5);

            fwrite(&score,sizeof(score),100,archivo);
            fclose(archivo);
        N.BORRAR();
        C1.BORRAR();
        for(it=B.begin(); it!=B.end();){
                gotoxy((*it)->X(),(*it)->Y()); printf (" ");
                delete (*it);
                    it=B.erase(it);

                    }
        for(itA=A.begin(); itA!=A.end();){
                gotoxy((*itA)->X(),(*itA)->Y()); printf (" ");
                delete (*itA);
                    itA=A.erase(itA);
            }


    gotoxy(32,16); printf("GAME OVER");
    gotoxy(32,17); printf("TU PUNTUACI%cN %d" ,224,puntos);
    gotoxy(32,18); printf("PRESIONE");
    gotoxy(32,19); printf("1-VOLVER A INTENTAR");
    gotoxy(32,20); printf("2-VER M%cXIMOS PUNTAJES",181);
     gotoxy(32,21); printf("3-SALIR",181);
    for (a=0;a<1;){
    if(kbhit()){
        char op=getch();
    switch (op){
        case '1':control=1;a++;
        gameover=false;
        LIMPIAR_PANT();
        break;
        case '3': control=0;a++;
        break;
        case '2':LIMPIAR_PANT();
                  h=0;i=0;
                    gotoxy(34,16);printf("M%cXIMOS PUNTAJES:",181);
                    for (i=0; i<5; i++){
                        gotoxy(34,17+i);printf("%d- %d",i+1,score[i]);
                        gotoxy(32,22);printf("PRESIONE <ESPACIO> PARA VOLVER");
                                }
                while(h==0){
                    if(kbhit()){
                    char tecla=getch();
                    if(tecla==0X20)h++;
                    }
                }
                LIMPIAR_PANT();
        gotoxy(32,16); printf("GAME OVER");
        gotoxy(32,17); printf("TU PUNTUACI%cN %d" ,224,puntos);
        gotoxy(32,18); printf("PRESIONE");
        gotoxy(32,19); printf("1-VOLVER A INTENTAR");
        gotoxy(32,20); printf("2-VER M%cXIMOS PUNTAJES",181);
        gotoxy(32,21); printf("3-SALIR",181); control=1;
     break;
        default: gotoxy(20,24);printf("                                                         ");
        Sleep(300);
         a=0;     gotoxy(20,24);printf("LA OPCI%cN QUE INTRODUJO NO ES V%cLIDA, VUELVA A INTENTAR",224,181);

    }
                }
                }
} while(control==1);

return 0;
}
