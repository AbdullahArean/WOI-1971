#ifndef SOUND_H
#define SOUND_H
 
//Preprocessor
#include "constants.h"
 
//Initializing
Mix_Music *bMusic2 = NULL, *bMusic3 = NULL;
Mix_Chunk *click = NULL, *bullet = NULL, *plane = NULL, *victory = NULL, *levelup = NULL, *death = NULL;
 
//Loading the musics
Mix_Music *bMusic1 = Mix_LoadMUS("assets/firstpage.mp3");

/*
bMusic2 = Mix_LoadMUS(“Please enter the path of an mp3”);
bMusic3 = Mix_LoadMUS(“Please enter the path of an mp3”);
//Loading the sound effects
bullet = Mix_LoadWAV(“Please enter the path of a wav or mp3”);
plane = Mix_LoadWAV(“Please enter the path of a wav or mp3”);
victory = Mix_LoadWAV(“Please enter the path of a wav or mp3”);
levelup = Mix_LoadWAV(“Please enter the path of a wav or mp3”);
death = Mix_LoadWAV(“Please enter the path of a wav or mp3”);
*/
 
//Freeing memory
void close()
{
   //Free the sound effects
   Mix_FreeChunk(bullet);
   Mix_FreeChunk(plane);
   Mix_FreeChunk(victory);
   Mix_FreeChunk(levelup);
   Mix_FreeChunk(death);
 
   //Setting the Chunks to NULL
   bullet = NULL;
   plane = NULL;
   victory = NULL;
   levelup = NULL;
   death = NULL;
 
   //Free the music
   Mix_FreeMusic(bMusic1);
   Mix_FreeMusic(bMusic2);
   Mix_FreeMusic(bMusic3);
 
   //Setting the Musics to NULL
   bMusic1 = NULL;
   bMusic2 = NULL;
   bMusic3 = NULL;
 
   //Quit SDL subsystems
   Mix_Quit();
   IMG_Quit();
   SDL_Quit();
}
 
#endif
