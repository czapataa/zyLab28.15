#include <iostream>
#include "PlaylistNode.h"

using namespace std;

void PrintMenu(string playlistTitle) {
   cout << playlistTitle << " PLAYLIST MENU" << endl;
   cout << "a - Add song" << endl;
   cout << "b - Remove song" << endl;
   cout << "c - Change position of song" << endl;
   cout << "s - Output songs by specific artist" << endl;
   cout << "t - Output total time of playlist (in seconds)" << endl;
   cout << "o - Output full playlist" << endl;
   cout << "q - Quit" << endl;
   cout << endl;
}

PlaylistNode* ExecuteMenu(char option, std::string playlistTitle, PlaylistNode* headNode) {
   std::string id, songName, artistName;
   int songLength;
   int currentPos, newPos, listlength = 0;
   swtich (option) {
      case 'a':{
      }
      case 'd':{
      }
      case 'c':{
      }
      case 's':{
      }
      case 't':{
      }
      case 'o':{
      }
      case 'q':{
      }
}

int main() {
   /* Type your code here */
   
   return 0;
}
