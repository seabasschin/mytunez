#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct song_node{ 
  char name[256];
  char artist[256];
  struct song_node *next;
} song_node;

//insert song in front
song_node * insert_front(song_node * list, char * a, char * s){
  song_node * newNode = (song_node *) malloc(sizeof(song_node));
  strcpy(newNode->name, s);
  strcpy(newNode->artist, a);
  newNode->next = list;
  return newNode;
}

//insert song in alphabetical order
song_node * insert_order(song_node * list, char * a, char * s){
  song_node * retNode = list;
  song_node * prevNode;
  if(list == NULL || strcmp(list->artist, a) > 0){return insert_front(list,a,s);}
  while(list != NULL && strcmp(list->artist, a) < 0 ){
    prevNode = list;
    list = list->next;
  }
  if( list != NULL && strcmp(list->artist, a) == 0){
    while(list != NULL && strcmp(list->name, s) < 0 ){
      prevNode = list;
      list = list->next;
    }
  }
  song_node * newNode = (song_node *) malloc(sizeof(song_node));
  strcpy(newNode->name, s);
  strcpy(newNode->artist, a);
  newNode->next = list;
  prevNode->next = newNode;
  
  return retNode;
  
}

//print list of songs
void print_list(song_node * list){
  if(list == NULL){
    printf("nothin' here :(");
  }
  while(list != NULL){
    printf("%s - %s\n",list->artist, list->name);
    list = (list->next);
  }
  printf("\n");
  return;
}

song_node * find_song(song_node *  list, char * s){
  while(list != NULL && strcmp(list->name, s) != 0 ){
      list = list->next;
    }
  return list;
}

song_node * find_artist(song_node * list, char * a){
  while(list != NULL && strcmp(list->artist, a) < 0 ){
    list = list->next;
  }
  return list;
}
  
song_node * find_random(song_node *list){
  song_node * top = list;
  srand(time(NULL));
  int counter = (rand() % 100);
  while (counter > 0){
    if(list == NULL){
      list = top;
    }
    list = list->next;
    counter --;
  }
  if(list == NULL){
    return top;
  }
  return list;
}

song_node * remove_song(song_node * list, char * s ){
  song_node * retNode = list;
  song_node * prevNode = NULL;
  while(list != NULL && strcmp(list->name, s) != 0 ){
    prevNode = list;
    list = list->next;
  }
  if(list == NULL){
    return retNode;
  }
  if(prevNode == NULL){
    retNode = list->next;
    free(list);
  }
  else{
    prevNode->next = list->next;
    free(list);
  }
  return retNode;
}

 song_node * free_nodes(song_node * list){
  while(list != NULL){
    song_node * temp = list->next;
    free(list);
    list = temp;
  }
  return NULL;
}