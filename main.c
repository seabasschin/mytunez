#include "tunes.h"


void main(){
  printf("\n\n\n\n\nwelcome to mytunez, by sebastian dittgen\n\n");
  
  song_node * A = (song_node *) malloc(sizeof(song_node));
  A = NULL;

  printf("ting insert (using print_list after each insert):\n\n");
  A = insert_order(A, "sponge", "sponge getting squeezed");
  print_list(A);
  A = insert_order(A, "spongebob", "campfire song");
  print_list(A);
  A = insert_order(A, "spongebob", "FUN");
  print_list(A);
  A = insert_order(A, "spoon", "cling clang");
  print_list(A);

  printf("\n\nfind song: cling clang\n\n");
  song_node * test = find_song(A, "cling clang");
  printf("%s - %s\n",test->artist, test->name);

  printf("\n\nfind artist: spongebob\n\n");
  song_node * t2 = find_artist(A, "spongebob");
  printf("%s - %s\n\n",t2->artist, t2->name);

  printf("\n\nremove song function:\n\n");
  print_list(A);
  printf("removing 'sponge getting squeezed'\n");
  A = remove_song(A, "sponge getting squeezed");
  print_list(A);
  printf("removing 'cling clang'\n");
  A = remove_song(A, "cling clang");
  print_list(A);

  printf("\n\nadding another song:\n\n");
  A = insert_order(A, "windows xp", "start up sound");
  print_list(A);

  printf("finding random song:\n\n");
  song_node * t3 = find_random(A);
  printf("%s - %s\n\n",t3->artist, t3->name);


  printf("\n\nlet the nodes free!:\n\n");
  A = free_nodes(A);
  print_list(A);

  printf("\n\n---moving on to the lib part---\n\n\n");

  srand(time(NULL));

  printf("gotta make a table\n");
  song_node *table[26];
  table[0] = insert(table[0], "a", "a");
  table[1] = insert(table[0], "b", "b");
  table[2] = insert(table[0], "c", "c");
  table[3] = insert(table[0], "d", "d");
  table[4] = insert(table[0], "e", "e");
  table[5] = insert(table[0], "f", "f");
  table[6] = insert(table[0], "g", "g");
  table[7] = insert(table[0], "h", "h");
  table[8] = insert(table[0], "i", "i");
  table[9] = insert(table[0], "j", "j");
  table[10] = insert(table[0], "k", "k");
  table[11] = insert(table[0], "l", "l");
  table[12] = insert(table[0], "m", "m");
  table[13] = insert(table[0], "n", "n");
  table[14] = insert(table[0], "o", "o");
  table[15] = insert(table[0], "p", "p");
  table[16] = insert(table[0], "q", "q");
  table[17] = insert(table[0], "r", "r");
  table[18] = insert(table[0], "s", "s");
  table[19] = insert(table[0], "t", "t");
  table[20] = insert(table[0], "u", "u");
  table[21] = insert(table[0], "v", "v");
  table[22] = insert(table[0], "w", "w");
  table[23] = insert(table[0], "x", "x");
  table[24] = insert(table[0], "y", "y");
  table[25] = insert(table[0], "z", "z");
  printf("\n...done...\n\n...and add some tunez: \n\n");
 
  printf("adding songs using add song function\n\n");
  add_song(table, "windows xp", "startup sound");
  add_song(table, "windows xp", "pop-up window");
  add_song(table, "dolphin", "assortment of sounds");
  add_song(table, "yeezy", "pt 3");
  add_song(table, "bag of chips", "getting stepped on");
  add_song(table, "macbook", "opening sound");
  printf("print using print library\n");
  print_library(table);
  
  printf("\n\ndelete song ('bag of chips - getting stepped on'):\n");
  delete_song(table, "getting stepped on");
  print_library(table);

  printf("\nif you try to delete a song that doesn't exist, mytunez doesn't crash!\n");
  printf("deleting nonexistant song: 'windows7 noises'\n\n");
  delete_song(table, "windows7 noises");
  print_library(table);

  printf("\nsearching for songs (searching for 'pop-up window')\n\n");
  song_node * s = search_song(table,"pop-up window");
  printf("%s - %s\n\n",s->artist, s->name);

  printf("\n\nsearching for an artists (searching for windows xp):\n\n");
  song_node * a = search_artist(table,"windows xp");
  printf("%s - %s\n\n",a->artist, a->name);

  printf("\n\nprinting out all 'w' songs:\n\n");
  print_song(table,"w");

  printf("\n\nadding more windows xp songs:\n\n");
  add_song(table, "windows xp", "crashing");
  add_song(table, "windows xp", "logging in");
  printf("print artist: windows xp\n\n");
  print_artist(table,"windows xp");

  printf("\n\nplaylist time!: \n\n");
  shuffle(table, 4);

  printf("\n\nalas, its time to let our library go. let it be free!\n\n");
  free_library(table);
  printf("hehehe its gone:\n\n");
  print_library(table);
  printf("^yup it's free!\n\nthat brings us to the end of the tour, hope you enjoyed mytunez!\n\n\n\n");
     
     

}