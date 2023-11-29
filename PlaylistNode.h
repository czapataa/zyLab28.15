#ifndef PLAYLISTNODE_H
#define PLAYLISTNODE_H

#include <string>

class PlaylistNode{
private:
  std::string uniqueID;
  std::string songName;
  std::string artistName;
  int songLength;
  PlaylistNode* nextNodePtr;

public:
  PlaylistNode();
  PlaylistNode(std::string id, std::string songName, std::string artistName, int songLength);

  std::string GetID() const;
  std::string GetSongName() const;
  std::steing GetArtistName() const;
  int GetSongLength() const;
  PlaylistNode* GetNext() const;

  void InsertAfter(PlaylistNode* nodePtr);
  void SetNext(PlaylistNode* nodePtr);
  void PrintPlaylistNode() const;
};

#endif
