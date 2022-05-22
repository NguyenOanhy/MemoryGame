#include <SDL.h>
#include <SDL_image.h>
#include <stdlib.h>
#include <map>
#include <time.h>
#include <iostream>
using namespace std;
int main(int argc, char* argv[])
{
    SDL_Event event ;
    int x , y ;
    int picPairs = 0 , win_game = 0;
    int numberClicks = 0;


    int a[4][4] ;
    /*int r;
    map<int, bool> vis;
    srand((int)time(0));
    for (int i = 0; i<4; i++)
        for (int j = 0; j<4; j++)
        {
            do{
                r = 1 + rand() % (16);
            }while(vis.find(r) != vis.end());
            vis[r] = true;
            a[i][j] = r %8;
        }
    */
    a[0][0] = 1;a[0][1] = 2;a[0][2] = 6;a[0][3] = 8;
    a[1][0] = 4;a[1][1] = 3;a[1][2] = 7;a[1][3] = 5;
    a[2][0] = 1;a[2][1] = 5;a[2][2] = 8;a[2][3] = 4;
    a[3][0] = 6;a[3][1] = 2;a[3][2] = 3;a[3][3] = 7;
    int b1,b2,b3,b4;

    SDL_Init (SDL_INIT_VIDEO) ;
    bool quit= false ;
    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGTH = 600;

    int size = SCREEN_WIDTH/8;
    int dis = SCREEN_HEIGTH/15;

    SDL_Window * windows = SDL_CreateWindow("Memory Game" , 0 , 0 , SCREEN_WIDTH  , SCREEN_HEIGTH , 0) ;
    SDL_Renderer * renderer = SDL_CreateRenderer(windows , -1 , 0) ;
    SDL_Surface * pic[16] = {IMG_Load ("image/0.jpg"),IMG_Load ("image/1.jpg") , IMG_Load ("image/2.jpg"), IMG_Load ("image/3.jpg"), IMG_Load ("image/4.jpg"), IMG_Load ("image/5.jpg"), IMG_Load ("image/6.jpg"), IMG_Load ("image/7.jpg"), IMG_Load ("image/8.jpg"), IMG_Load ("image/9.png"), IMG_Load ("image/10.png"), IMG_Load ("image/11.png"), IMG_Load ("image/12.png"), IMG_Load ("image/13.png"), IMG_Load ("image/14.png"), IMG_Load ("image/15.png")} ;

    //Start game
    for (int i = 10; i<= 14; i++) {
        SDL_Rect i_picaa = {0 , 0 , 800 , 600} ;
        SDL_Texture * pic_saa = SDL_CreateTextureFromSurface (renderer , pic[i]) ;
        SDL_RenderCopy(renderer , pic_saa , NULL , &i_picaa) ;
        SDL_RenderPresent (renderer) ;
     SDL_Delay(750);
    }

//Display picture
    for (int i=0; i<4; i++)
    for (int j=0; j<4; j++){
        SDL_Rect i_pica = {i*(dis+size) , j*(dis+size) , size , size} ;
        SDL_Texture * pic_sa = SDL_CreateTextureFromSurface (renderer , pic[a[i][j]]) ;
        SDL_RenderCopy(renderer , pic_sa , NULL , &i_pica) ;
    }

    SDL_RenderPresent (renderer) ;
    SDL_Delay(3500);
//Hide picture
    for (int i=0; i<4; i++)
    for (int j=0; j<4; j++){
    SDL_Rect i_pic = {i*(dis+size) , j*(dis+size) , size , size}  ;
    SDL_Texture * pic_s = SDL_CreateTextureFromSurface (renderer , pic[0]) ;
    SDL_RenderCopy(renderer , pic_s , NULL , &i_pic) ;
    }
//Show quit button
    SDL_Rect quitButton = {(dis+size)*4 , (dis+size)*3 , 2*size , 2*size} ;
    SDL_Texture * quitButton_ = SDL_CreateTextureFromSurface (renderer , pic[15]) ;
    SDL_RenderCopy(renderer , quitButton_ , NULL , &quitButton) ;

//Game loop
    while (!quit)
    {
        Uint8 SDL_GetMouseState(int *x, int *y);
        while(SDL_PollEvent( &event ) != 0)
        {
            if( event.type == SDL_QUIT )
                quit=true ;
            if (event.type == SDL_MOUSEBUTTONDOWN&& win_game == 0){
                    for (int i=0; i<4; i++)
                    for (int j=0; j<4; j++){
                        if (x > i*(size+dis) && x < (i*(size+dis)+size)  && y > j*(size+dis) && y < (j*(size+dis)+size)){
                            if (event.type == SDL_MOUSEBUTTONDOWN && numberClicks <= 2){
                                SDL_Rect i_pic = {i*(size+dis) , j*(size+dis) , size , size} ;
                                SDL_Texture * pic_s = SDL_CreateTextureFromSurface (renderer , pic[a[i][j]]) ;
                                SDL_RenderCopy(renderer , pic_s , NULL , &i_pic) ;
                                numberClicks++;
                                if (numberClicks== 1){b1 = i ; b2 = j;}
                                if (numberClicks == 2){b3 = i; b4 = j;}
                                }
                            }
                        //if player presses quit button
                        if (x > 4*(size+dis) && x < 4*(size+dis)+2*size && y > 3*(size+dis) && y < 3*(size+dis)+2*size){
                            if (event.type == SDL_MOUSEBUTTONDOWN && numberClicks <= 2){return 0 ;}
                        }
                    }
            }
        //if player presses quit button
        if (x > 4*(size+dis) && x < 4*(size+dis)+2*size && y > 3*(size+dis) && y < 3*(size+dis)+2*size){
                if (event.type == SDL_MOUSEBUTTONDOWN && numberClicks <= 2){return 0 ;}
            }
        }
        numberClicks%=3;
        SDL_GetGlobalMouseState(&x,&y);
        if (numberClicks==2){
            //If the pictures are not the same then flip them over
            if (a[b1][b2]!=a[b3][b4]){
                SDL_RenderPresent (renderer) ;
                SDL_Delay(750);
                SDL_Rect i_pic21 = {b1*(size+dis) , b2*(size+dis) , size , size} ;
                SDL_Texture * pic_s21 = SDL_CreateTextureFromSurface (renderer , pic[0]) ;
                SDL_RenderCopy(renderer , pic_s21 , NULL , &i_pic21) ;
                SDL_Rect i_pic20 = {b3*(size+dis) , b4*(size+dis) , size , size} ;
                SDL_Texture * pic_s20 = SDL_CreateTextureFromSurface (renderer , pic[0]) ;
                SDL_RenderCopy(renderer , pic_s20 , NULL , &i_pic20) ;
                numberClicks = 0 ;
                }
            else{
                //If the pictures are the same, make them disappear
                SDL_RenderPresent (renderer) ;
                SDL_Delay(750);
                SDL_Rect i_pic21 = {b1*(size+dis) , b2*(size+dis) , size , size} ;
                SDL_Texture * pic_s21 = SDL_CreateTextureFromSurface (renderer , pic[14]) ;
                SDL_RenderCopy(renderer , pic_s21 , NULL , &i_pic21) ;
                SDL_Rect i_pic20 = {b3*(size+dis) , b4*(size+dis) , size , size} ;
                SDL_Texture * pic_s20 = SDL_CreateTextureFromSurface (renderer , pic[14]) ;
                SDL_RenderCopy(renderer , pic_s20 , NULL , &i_pic20) ;
                picPairs++;
            }

        }
        //if the player chooses exactly 8 pairs of pictures
        if(picPairs == 8){
            SDL_Rect win = {0 , 0, SCREEN_WIDTH, SCREEN_HEIGTH} ;
            SDL_Texture * win_= SDL_CreateTextureFromSurface (renderer , pic[9]) ;
            SDL_RenderCopy(renderer , win_ , NULL , &win) ;
            win_game = 1;
        }
        numberClicks%=3;
        if (numberClicks == 2){numberClicks=0;}
        SDL_RenderPresent (renderer) ;
        SDL_Delay (20) ;
    }
    for (int j=0 ; j <=10 ; j++)
        SDL_FreeSurface(pic[j]);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(windows);
    SDL_Quit();
    return 0;
}

