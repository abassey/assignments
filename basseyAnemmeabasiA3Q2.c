/* Anemmeabasi Bassey, 1032523
abassey@uoguelph.ca
Question 2 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_TWEET_LENGTH 60

int isValidTweet(char tweet[]);
int isTweetAReply(char tweet[]);
void shorterTweet(char tweet1[], char tweet2[], char tweet3[]);
int numTweetsRequired(char tweet[]);

//working
//checks to make sure the string is not empty
int isValidTweet(char tweet[]){
  int validAns = 1;
  if(tweet[0] == '\0'){
    validAns = 0;
  }
  return validAns;
}
//working
//checks that the first char is an @, false if not
int isTweetAReply(char tweet[]){
  int replyAns = 0;
  if(tweet[0] == '@'){
    replyAns = 1;
  }
  return replyAns;
}
//working
//tweet3 = result. compares the length of tweet1 and tweet2
void shorterTweet(char tweet1[], char tweet2[], char tweet3[]){
  int tweetLengthDiff = 0;
  tweetLengthDiff = strlen(tweet1) - strlen(tweet2);
 if (tweetLengthDiff < 0){
   strcpy(tweet3, "Tweet 1");
 } else if (tweetLengthDiff > 0){
   strcpy(tweet3, "Tweet 2");
 } else {
   strcpy(tweet3, "Same length");
 }
}
//working
//for every 59 chars, +1 num of tweets to be made
int numTweetsRequired(char tweet[]){
  int tweetNumCnt = 0;
  for (int i = 0; i < strlen(tweet); ++i){
    if(i == (MAX_TWEET_LENGTH - 1) || i % (MAX_TWEET_LENGTH - 1) == 0 ){
      ++tweetNumCnt;
    }
  }
  return tweetNumCnt;
}
