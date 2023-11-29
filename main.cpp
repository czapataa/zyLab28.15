#include <iostream>
#include "PlaylistNode.h"

using namespace std;

void PrintMenu(string playlistTitle) {
   cout << playlistTitle << " PLAYLIST MENU" << endl;
   cout << "a - Add song" << endl;
   cout << "d - Remove song" << endl;
   cout << "c - Change position of song" << endl;
   cout << "s - Output songs by specific artist" << endl;
   cout << "t - Output total time of playlist (in seconds)" << endl;
   cout << "o - Output full playlist" << endl;
   cout << "q - Quit" << endl;
   cout << endl;
}

PlaylistNode* ExecuteMenu(char option, string playlistTitle, PlaylistNode* headNode) {
   /* Type your code here */
   
}

int main() {
   std::string playlistTitle;
   char option;
   PlaylistNode* headNode = nullptr;
   cout <<"Enter playlist's title:" << endl;
   cout << endl;
   getline(cin, playlistTitle);

   do{
      PrintMenu(playlistTitle);
      cout <<"Choose an option:" << endl;
      cin >> option;
      if(cin.peek() == '\n){
      cin.ignore();
      }
      headNode = ExecuteMenu(option,playlistTitle, headNode);
   } while(option != 'q');
   return 0;
}
