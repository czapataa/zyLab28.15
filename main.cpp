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
   switch (option) {
      case 'a':{
         cout << "ADD SONG" << endl;
         cout << "Enter song's unique ID:" << endl;
         getline(cin, id);
         cout << "Enter song's name:" << endl;
         getline(cin, songName);
         cout << "Enter artist's name:" << endl;
         getline(cin, artistName);
         cout << "Enter song's length (in seconds):" << endl;
         cin >> songLength;
         cout << endl;
         if(cin.peek() == '\n'){
            cin.ignore();
         }
         PlaylistNode* newNode = new PlaylistNode(id, songName, artistName, songLength);
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
         cout << "Enter song's unique ID:" << endl;
         getline(cin, id);

         PlaylistNode* currenetNode = headNode;
         PlaylistNode* prevNode = nullptr;

         while(currentNode != nullptr && currentNode->GetID() != id)
         {
            prevNode = currentNode;
            currentNode = currentNode->GetNext();
         }
         if(currentNode == nullptr){
            cout << "Song with ID " << id << " not found." << endl;
         }
            else{
               if(prevNode == nullptr){
                  headNode = currentNode->GetNext();
               }
               else{
                  prevNode->SetNext(currentNode->GetNext());
               }

               cout << "\"" << currentNode->GetSongName() << "\" removed." << endl;
               cout << endl;
               delete currentNode;
            }
               break;   
      }
      case 'c':{
         cout << "CHANGE POSITION OF SONG" << endl;
         cout << "Enter song's current position:" << endl;
         cin >> currentPos;
         cout << "Enter new position for song:" << endl;
         cin >> newPos;
         PlaylistNode* currentNode = headNode;
         while(currentNode != nullptr) {
            listLength++;
            currentNode = currentNode->GetNext();
         }
         if(newPos < 1){
            newPos = 1;
         } else if (newPos > listLength) {
            newPos = listLength;
         }
         PlaylistNode* prevNode = nullptr;
         currentNode = headNode;
         for(int i = 1; currentNode != nullptr && i < currentPos; ++i) {
            prevNode = currentNode;
            currentNode = currentNode->GetNext();
         }
         if(currentNode == nullptr) {
            cout << "Invalid current position." << endl;
            break;
         }
         if(prevNode == nullptr) {
            headNode = currentNode->GetNext();
         } else {
            prevNode->SetNext(currentNode->GetNext());
         }
         PlaylistNode* newNode = currentNode;
         currentNode = headNode;
         prevNode = nullptr;
         for(int i = 1; currentNode != nullptr && i < newPos; ++i) {
            prevNode = currentNode;
            currentNode = currentNode->GetNext();
         }
         if(prevNoe == nullptr) {
            newNode->SetNext(headNode);
         }else {
            newNode->SetNext(currentNode);
            prevNode->SetNext(newNode);
         }
         cout << "\" << newNode->GetSongName() << "\" moved to position " << newPos << endl;
         cout << endl;
         break;
      }
      case 's':{
         cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
         cout << "Enter artist's name:" << endl;
         geline(cin, artistName);
         cout << endl;
         int position = 1;
         PlaylistNode* currentNode = headNode;

         while(currentNode != nullptr){
            if(currentNode->GetArtistName() == artistName){
               cout << position << "." << endl;
               currentNode->PrintPlaylistNode();
               cout << endl;
            }
            cuurentNode = currentNode->GetNext();
            position++;
         }
         break;     
      }
      case 't':{
         int totalTime = 0;
         PlaylistNode* currentNode = headNode;

         while (currentNode != nullptr) {
            totalTime += currentNode->GetSongLength();
            currentNode = currentNode->GetNext();
         }
         cout << "OUTPUT TOTAL TIMEOF PLAYLIST (IN SECONDS)" << endl;
         cout << "Total time: " << totalTime << " seconds" << endl;
         cout << endl;
         break;
      }
      case 'o':{
         cout << playlistTitle << " - OUTPUT FULL PLAYLIST" << endl;
         if(headNode == nullptr){
            cout << "Playlist is empty";
            cout << endl;
         }
         else{
            int songNumber = 1;
            PlaylistNode* currentNode = headNode;
            while(currentNode != nullptr){
               cout << songNumber << "." << endl;
               cuurentNode-> PrintPlayListNode();
               cout << endl;
               currentNode = currentNode->GetNext();
               songNumber++;
            }
         }
         break;
      }
      case 'q':{
         break;
         default;
         cout << "Invalid option. Please try again." << endl;
      }
      return headNode;
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
