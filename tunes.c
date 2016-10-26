#include "llist.h"
#ifndef MY_TUNES

#define MY_TUNES


song_node * insert(song_node * list, char * a, char * s){
  song_node * newNode = (song_node *) malloc(sizeof(song_node));
  strcpy(newNode->name, s);
  strcpy(newNode->artist, a);
  newNode->next = NULL;
  return newNode;
}

void add_song(song_node * d[26], char * a, char * s){
  int i = 0;
  while(strcmp(d[i]->artist, a) < 0){
    i = i + 1;
  }
  d[i-1] = insert_order(d[i-1], a, s);;
}
    
void delete_song(song_node * d[26], char * s){
  int i = 0;
  while(i < 26){
    d[i] = remove_song(d[i],s);
    i = i + 1;
  }  
}


song_node * search_song(song_node * d[26], char * s){
  song_node * retNode = NULL;
  int i = 0;
  while(retNode == NULL && i < 26){
    retNode = find_song(d[i],s);
    i = i + 1;
  }
  if(retNode == NULL){
    printf("make sure you typed the song correctly\n");
    return d[0];
  }
  else{
    return retNode;
  }
}

song_node * search_artist(song_node * d[26], char * a){
  song_node * retNode = NULL;
  int i = 0;
  while(strcmp(d[i]->artist, a) < 0){
    i = i + 1;
  }
  retNode = find_artist(d[i-1],a);
  if(retNode == NULL){
    printf("make sure you typed the artist correctly\n");
    return d[0];
  }
  else{
    return retNode;
  }
}

void print_song(song_node * d[26], char * l){
  int i = 0;
  while(i < 26 && strcmp(d[i]->artist, l) != 0){
    i++;
  }
  print_list(d[i]->next);
}

void print_artist(song_node * d[26], char * a){
  int i = 0;
  while(i < 26 && strcmp(d[i]->artist, a) < 0){
    i++;
  }
  song_node * x = d[i-1];
  while(x != NULL){
    if(strcmp(x->artist,a) == 0){
      printf("%s - %s\n",x->artist, x->name);
    }
    x = x->next;
  }
}

void shuffle(song_node * d[26], int len){
  while(len > 0){
    int x = (rand() % 26);
    while(d[x] -> next == NULL){
      x = (rand() % 26);
    }
    song_node * j = find_random(d[x]->next);
    printf("%s - %s  ",j->artist, j->name);
    len--;
    srand(time(NULL) * len);
  }
  printf("\n");
}


void print_library(song_node * d[26]){
  int i = 0;
  while(i < 26){
    if(d[i] != NULL){
      if((d[i]->next) != NULL){
	printf("----+ %s +----\n", d[i]->artist);
	print_list(d[i]->next);
	
      }
    }
     i++;
  }
}

void free_library(song_node * d[26]){
  int i = 0;
  while(i < 26){
    d[i] = free_nodes(d[i]);
    i++;
  }
}
#endif