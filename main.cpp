#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <string>
#include <iostream>
#include "SDL_Manager.h"
#include <stdlib.h>
#include <map>
#include <time.h>
using namespace std;

    const int SCREEN_WIDTH = 600;
    const int SCREEN_HEIGHT = 700;
    const int CARD_SIZE = 130;
    const int dis = 20;
    int picPairs = 0 , win_game = 0, numberClicks = 0, playMenu = 0;
    //Mouse coordinates
    int x, y;
    int a[4][4];
    int b1,b2,b3,b4;

void LoadCard(SDL_Renderer *renderer, int &i, int &j, SDL_Surface* CARD_){
    SDL_Rect card = {i*(dis+CARD_SIZE) , j*(dis+CARD_SIZE) , CARD_SIZE , CARD_SIZE} ;
    SDL_Texture * card_ = SDL_CreateTextureFromSurface (renderer , CARD_) ;
    SDL_RenderCopy(renderer , card_ , NULL , &card) ;

 }

void displayMenu(SDL_Renderer *renderer, SDL_Surface* CARD[]){
    SDL_Rect bg = {0 , 0, SCREEN_WIDTH, SCREEN_HEIGHT} ;
    SDL_Texture * bg_= SDL_CreateTextureFromSurface (renderer , CARD[14]) ;
    SDL_RenderCopy(renderer , bg_ , NULL , &bg) ;

    SDL_Rect title = {0 , 0 , SCREEN_WIDTH , SCREEN_HEIGHT / 3} ;
    SDL_Texture * title_ = SDL_CreateTextureFromSurface (renderer , CARD[16]) ;
    SDL_RenderCopy(renderer , title_ , NULL , &title) ;

    SDL_Rect play = {SCREEN_WIDTH/4, SCREEN_HEIGHT / 3, SCREEN_WIDTH/2, SCREEN_HEIGHT / 3} ;
    SDL_Texture * play_ = SDL_CreateTextureFromSurface (renderer , CARD[17]) ;
    SDL_RenderCopy(renderer , play_ , NULL , &play) ;

    SDL_Rect exit = {SCREEN_WIDTH/4 ,SCREEN_HEIGHT *2 / 3  ,SCREEN_WIDTH / 2, SCREEN_HEIGHT / 3} ;
    SDL_Texture * exit_ = SDL_CreateTextureFromSurface (renderer , CARD[18]) ;
    SDL_RenderCopy(renderer , exit_ , NULL , &exit) ;

    SDL_RenderPresent(renderer);
}

void displayGame(SDL_Renderer *renderer, SDL_Surface*CARD[], Mix_Music* Intro){

    //Random card
     srand((int)time(0));
     int r;
     map<int, bool> vis;
    for(int i = 0; i < 4; i++)
    for(int j = 0; j < 4; j++){
        do{
            r = 1 + rand() % 16;
        }while(vis.find(r) != vis.end());
        vis[r] = true;
        a[i][j] = 1+ r % 8;
    }
     for (int i = 10; i <= 13; i++) {
        Mix_PlayMusic(Intro, 1);
        SDL_Rect card = {0 , 0 , SCREEN_WIDTH , SCREEN_HEIGHT} ;
        SDL_Texture * card_ = SDL_CreateTextureFromSurface (renderer , CARD[i]) ;
        SDL_RenderCopy(renderer , card_ , NULL , &card) ;
        SDL_RenderPresent (renderer) ;
        SDL_Delay(600);

    }

    SDL_Rect bg = {0 , 0, SCREEN_WIDTH, SCREEN_HEIGHT} ;
    SDL_Texture * bg_= SDL_CreateTextureFromSurface (renderer , CARD[14]) ;
    SDL_RenderCopy(renderer , bg_ , NULL , &bg) ;

   SDL_Rect menu = {SCREEN_WIDTH/4 ,SCREEN_WIDTH ,SCREEN_WIDTH / 2, SCREEN_HEIGHT - SCREEN_WIDTH} ;
   SDL_Texture * menu_ = SDL_CreateTextureFromSurface (renderer , CARD[15]) ;
   SDL_RenderCopy(renderer , menu_ , NULL , &menu) ;

 //Display picture
    for (int i=0; i<4; i++)
    for (int j=0; j<4; j++){
        LoadCard(renderer, i, j, CARD[a[i][j]]);
    }
    SDL_RenderPresent(renderer);
    SDL_Delay(3500);

//Hide picture
    for (int i=0; i<4; i++)
    for (int j=0; j<4; j++){
        LoadCard(renderer, i, j, CARD[0]);
    }

}

int main(int argc, char* argv[])
{
    bool quit = false ;

    SDL_Manager manager = SDL_Manager (SCREEN_WIDTH, SCREEN_HEIGHT);
    manager.init();
    SDL_Event event;
    SDL_Renderer* renderer = manager.getRenderer();
    SDL_Surface * CARD[19] = {IMG_Load ("image/0.jpg"),IMG_Load ("image/1.jpg") , IMG_Load ("image/2.jpg"), IMG_Load ("image/3.jpg"), IMG_Load ("image/4.jpg"), IMG_Load ("image/5.jpg"), IMG_Load ("image/6.jpg"), IMG_Load ("image/7.jpg"), IMG_Load ("image/8.jpg"), IMG_Load ("image/9.png"), IMG_Load ("image/10.png"), IMG_Load ("image/11.png"), IMG_Load ("image/12.png"), IMG_Load ("image/13.png"), IMG_Load ("image/14.png"), IMG_Load ("image/15.png"), IMG_Load ("image/16.png"), IMG_Load ("image/17.png"), IMG_Load ("image/18.png")} ;
    Mix_Music* Intro = Mix_LoadMUS("music/Intro.mp3");
    displayMenu(renderer,CARD);

//Game loop
    while (!quit){
        Uint8 SDL_GetMouseState(int *x, int *y);
        while (SDL_PollEvent( &event ) != 0){
            if( event.type == SDL_QUIT ) quit=true ;
            if (event.type == SDL_MOUSEBUTTONDOWN && playMenu == 0) {
                 if ((x > SCREEN_WIDTH/4 && x < SCREEN_WIDTH*3/4) && (y > SCREEN_HEIGHT / 3 && y < SCREEN_HEIGHT* 2 / 3)){
                        displayGame(renderer,CARD,Intro);
                 }
                 else if ((x > SCREEN_WIDTH/4 && x < SCREEN_WIDTH*3/4) && (y > SCREEN_HEIGHT *2/ 3 && y < SCREEN_HEIGHT)){
                    return 0 ;
                 }
                playMenu = 1;
            }

           if (event.type == SDL_MOUSEBUTTONDOWN&& win_game == 0){
                for (int i = 0; i < 4; i++)
                for (int j = 0; j < 4; j++){
                    if (x > i*(CARD_SIZE+dis) && x < (i*(CARD_SIZE+dis)+CARD_SIZE)  && y > j*(CARD_SIZE+dis) && y < (j*(CARD_SIZE+dis)+ CARD_SIZE) && numberClicks<=2){
                            LoadCard(renderer, i, j, CARD[a[i][j]]);
                            numberClicks++;
                            if (numberClicks== 1){b1 = i ; b2 = j;}
                            if (numberClicks == 2){b3 = i; b4 = j;}
                    }
                    //if player presses menu button
                    if ((x > SCREEN_WIDTH/4 && x < SCREEN_WIDTH*3/4) && (y > SCREEN_WIDTH && y < SCREEN_HEIGHT)){
                        playMenu = 0 ; displayMenu(renderer, CARD); numberClicks = 0; picPairs = 0; win_game = 0; break;
                    }
                }
            }
        }

        numberClicks %= 3;
        SDL_GetGlobalMouseState(&x,&y);
        if (numberClicks==2){
            //If the pictures are not the same then flip them over
            if (a[b1][b2]!=a[b3][b4] || (b1 == b3)){
                SDL_RenderPresent (renderer) ;
                SDL_Delay(600);
                LoadCard(renderer, b1, b2, CARD[0]);
                LoadCard(renderer, b3, b4, CARD[0]);
                numberClicks = 0 ;
            }
            else{
                //If the pictures are the same, make them disappear
                SDL_RenderPresent (renderer) ;
                SDL_Delay(600);
                LoadCard(renderer, b1, b2, CARD[14]);
                LoadCard(renderer, b3, b4, CARD[14]);
                picPairs++;
            }
        }
        //if the player chooses exactly 8 pairs of card
        if(picPairs == 8){
            SDL_Rect win = {0 , 0, SCREEN_WIDTH, SCREEN_WIDTH} ;
            SDL_Texture * win_= SDL_CreateTextureFromSurface (renderer , CARD[9]) ;
            SDL_RenderCopy(renderer , win_ , NULL , &win);
            win_game = 1;
        }

        numberClicks %= 3;
        if (numberClicks == 2){numberClicks=0;}
        SDL_RenderPresent (renderer) ;

        //if player presses menu button
        while (SDL_PollEvent( &event ) != 0){
            if ((event.type == SDL_MOUSEBUTTONDOWN)&& (x > SCREEN_WIDTH/4 && x < SCREEN_WIDTH*3/4) && (y > SCREEN_WIDTH && y < SCREEN_HEIGHT)) {
                displayMenu(renderer, CARD); playMenu=0; numberClicks = 0; picPairs = 0; win_game = 0; break;
            }
        }
        SDL_Delay (10) ;

     }

    for (int j=0 ; j <=10 ; j++)
        SDL_FreeSurface(CARD[j]);

    return 0;
}





