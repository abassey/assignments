/*
Name: Anemmeabasi Bassey, 1032523
Email: abassey@uoguelph.ca
Course: CIS*2500
bow.c file
*/

#include "bow.h"

struct bag_struct *new_bag()
{
  struct bag_struct *bagTemp;
  bagTemp = malloc(sizeof(struct bag_struct));
  bagTemp->bag = NULL;
  bagTemp->bag_size = 0;
  bagTemp->total_words = 0;
  return bagTemp;
}

int bagsearch( struct bag_struct *bow, char *word )
{

  /*int i, j,mid;
  char *temp;*/
  struct bag_struct *bowSearch;
  bowSearch = new_bag();
  bowSearch->bag = realloc(bowSearch->bag, (sizeof(struct word_count_struct) * (bow->bag_size)));
  memcpy(bowSearch->bag, bow->bag, sizeof(struct word_count_struct)*(bow->bag_size));
  bowSearch->bag_size = bow->bag_size;
  bowSearch->total_words = bow->total_words;


  /* this is the loop to sort the ba, but the bag was not being copied over properly

  for(i = 1; i < bowSearch->bag_size; ++i){
    for(j = 0; j < bowSearch->bag_size - i; ++j){
      if(bowSearch->bag[j].word > bowSearch->bag[i].word){
        temp = bowSearch->bag[j].word;
        bowSearch->bag[j].word = bowSearch->bag[i].word;
        bowSearch->bag[i].word = temp;
      }
    }
  }


  mid = bowSearch->bag_size / 2;
  */

  free(bowSearch);

  return 0;
}

char *get_word( char **string_ptr )
{
  char *word;
  int i = 0;
  word = malloc(919);

    while((is_letter(**string_ptr) == 0) && **string_ptr != '\0')
    {
      *string_ptr += sizeof(char);
    }

    while(is_letter(**string_ptr) == 1)
    {
      word[i] = **string_ptr; /*copies the current char being pointed to into word array*/
      word[i] = tolower(word[i]);
      *string_ptr += sizeof(char);
      i++;
    }

    word[i] = '\0'; /*assigns the null character to the end of word*/

    /*printf("\"%s\"\n", *string_ptr);
    *string_ptr += strlen(*string_ptr);

    Debugging tests to see what is being pointed to by string_ptr*/

    if(**string_ptr == '\0'){
      free(word);
      return NULL;
    }

    word = realloc(word, strlen(word) + 1);
  return word;
}

int is_letter(char character)
{/*checks A - Z and a - z */
  if((character >= 65 && character <= 90) || (character >= 97 && character <= 122)){
    return 1;
  } else {
    return 0;
  }
}

struct word_count_struct *new_word_count( char *word )
{
  struct word_count_struct *tempVar;
  tempVar = malloc(sizeof(struct word_count_struct));
  tempVar->word = word;
  tempVar->count = 1;
  return tempVar;
}


void print_word_count(struct word_count_struct *word)
{
  if(word != NULL){
    printf("%s: %d\n", word->word, word->count);
  }
}

void add_word( struct bag_struct *bow, char *word )
{
  int i = 0;
  int pos;
  struct word_count_struct *addWordVar;
  addWordVar = new_word_count(word); /*makes it point to a new word_count structure for the provided word*/
  bow->bag_size++;
  bow->bag = realloc(bow->bag, (sizeof(struct word_count_struct)* (bow->bag_size)));
  pos = bagsearch(bow, word);
    if (i >= pos){
      memcpy((bow->bag) + 1, (bow->bag) + pos, sizeof(struct word_count_struct) * (bow->bag_size - pos - 1));
    }
  memcpy((bow->bag) + pos, addWordVar, sizeof(struct word_count_struct));
  bow->total_words++;
  free(addWordVar);

}

void print_bag(struct bag_struct *current_bag)
{
  int i;

  for(i = 0; i < current_bag->bag_size; ++i)
  {
      printf("%d ", i);
      /*print_word_count(current_bag->bag[i]);*/
      printf("%s: %d\n", current_bag->bag[i].word, current_bag->bag[i].count);
  }
  printf("Total words: %d\n", current_bag->total_words);
}

void free_bag(struct bag_struct *current_bag)
{
  int i;

  for(i = 0; i < current_bag->bag_size; ++i){
    free(current_bag->bag[i].word);
  }
}

void add_text( struct bag_struct *bow, char *line )
{


}

void read_sms_data( struct bag_struct *bow, char *label )
{


}

void differences( struct bag_struct *ham, struct bag_struct *spam )
{


}
