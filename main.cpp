#include <iostream>
#include "PlaylistNode.h"

using namespace std;

void PrintMenu(const string playlistTitle) {
   /* Type your code here */
   
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
