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

PlaylistNode* ExecuteMenu(char option, std::string playlistTitle, PlaylistNode* headNode) {
   std::string id, songName, artistName;
   int songLength;
   int currentPos, newPos, listlength = 0;
   swtich (option) {
      case 'a':{
         cout << "ADD SONG" << endl;
         cout << "Enter song's unique ID:" << endl;
         getline(cin, id);
         cout << "Enter song's name:" << endl;
         getline(cin, soneName);
         cout << "Enter artist's name:" << endl;
         getline(cin, artistName);
         cout << "Enter song's length (in seconds):" << endl;
         cin >> songLength;
         cout << endl;
         if(cin.peek() == '\n'){
            cin.ignore();
         }
         PlatlistNode* newNode = new PlaylistNode(id, songName, artistName, songLength);
         if(headNode == nullptr) {
            headNode = newNode;
         }else {
            PlaylistNode* currentNode = headNode;
            while(currentNode->GetNext() != nullptr) {
               currentNode = currentNode->GetNext();
            }
            currentNode->SetNext(newNode);
         }
         break;
      }
      case 'd':{
         cout << "REMOVE SONG" << endl;
         cout 
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
