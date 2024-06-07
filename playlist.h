#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>

using namespace std;

class Song
{
public:
    string title;
    string artist;
    Song *next;
    Song *prev;
    Song(string title, string artist)
    {
        this->title = title;
        this->artist = artist;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class Playlist
{
public:
    Song *head;
    Song *tail;
    Playlist()
    {
        this->head = nullptr;
        this->tail = nullptr;
    }
    void addSong(string title, string artist)
    {
        Song *newSong = new Song(title, artist);
        if (head == nullptr)
        {
            head = newSong;
            tail = newSong;
        }
        else
        {
            tail->next = newSong;
            newSong->prev = tail;
            tail = newSong;
        }
    }
    void removeSong(string title)
    {
        Song *current = head;
        while (current != nullptr)
        {
            if (current->title == title)
            {
                if (current == head)
                {
                    head = current->next;
                    head->prev = nullptr;
                }
                else if (current == tail)
                {
                    tail = current->prev;
                    tail->next = nullptr;
                }
                else
                {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                }
                delete current;
                return;
            }
            current = current->next;
        }
    }
    void moveSong(string title, int position)
    {
        Song *current = head;
        Song *songToMove = nullptr;
        while (current != nullptr)
        {
            if (current->title == title)
            {
                songToMove = current;
                break;
            }
            current = current->next;
        }
        if (songToMove == nullptr)
        {
            return;
        }
        if (songToMove == head)
        {
            head = head->next;
            head->prev = nullptr;
        }
        else if (songToMove == tail)
        {
            tail = tail->prev;
            tail->next = nullptr;
        }
        else
        {
            songToMove->prev->next = songToMove->next;
            songToMove->next->prev = songToMove->prev;
        }
        current = head;
        for (int i = 0; i < position; i++)
        {
            if (current == nullptr)
            {
                break;
            }
            current = current->next;
        }
        if (current == nullptr)
        {
            tail->next = songToMove;
            songToMove->prev = tail;
            tail = songToMove;
            tail->next = nullptr;
        }
        else if (current == head)
        {
            songToMove->next = head;
            head->prev = songToMove;
            head = songToMove;
            head->prev = nullptr;
        }
        else
        {
            songToMove->next = current;
            songToMove->prev = current->prev;
            current->prev->next = songToMove;
            current->prev = songToMove;
        }
    }

    Song *getSong(string title)
    {
        Song *current = head;
        while (current != nullptr)
        {
            if (current->title == title)
            {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }
    string getArtist(string title)
    {
        Song *current = head;
        while (current != nullptr)
        {
            if (current->title == title)
            {
                return current->artist;
            }
            current = current->next;
        }
        return "";
    }
    string getTitle(string artist)
    {
        Song *current = head;
        while (current != nullptr)
        {
            if (current->artist == artist)
            {
                return current->title;
            }
            current = current->next;
        }
        return "";
    }
    void displayPlaylist()
    {
        Song *current = head;
        while (current != nullptr)
        {
            cout << current->title << " by " << current->artist << endl;
            current = current->next;
        }
    }
    void shufflePlaylist()
    {
        vector<Song *> songs;
        Song *current = head;
        while (current != nullptr)
        {
            songs.push_back(current);
            current = current->next;
        }
        shuffle(songs.begin(), songs.end(), default_random_engine(time(0)));
        head = songs[0];
        head->prev = nullptr;
        current = head;
        for (int i = 1; i < songs.size(); i++)
        {
            current->next = songs[i];
            songs[i]->prev = current;
            current = current->next;
        }
        tail = current;
        tail->next = nullptr;
    }
    void sortPlaylist()
    {
        vector<Song *> songs;
        Song *current = head;
        while (current != nullptr)
        {
            songs.push_back(current);
            current = current->next;
        }
        sort(songs.begin(), songs.end(), [](Song *a, Song *b)
             { return a->title < b->title; });
        head = songs[0];
        head->prev = nullptr;
        current = head;
        for (int i = 1; i < songs.size(); i++)
        {
            current->next = songs[i];
            songs[i]->prev = current;
            current = current->next;
        }
        tail = current;
        tail->next = nullptr;
    }
    void reversePlaylist()
    {
        Song *current = head;
        while (current != nullptr)
        {
            swap(current->next, current->prev);
            current = current->prev;
        }
        swap(head, tail);
    }
    void clearPlaylist()
    {
        Song *current = head;
        while (current != nullptr)
        {
            Song *temp = current->next;
            delete current;
            current = temp;
        }
        head = nullptr;
        tail = nullptr;
    }
};
