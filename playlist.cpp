#include "playlist.h"

int main()
{
    Playlist playlist;
    playlist.addSong("Tiny Dancer", "Elton John");
    playlist.addSong("Johnny B. Goode", "Chuck Berry");
    playlist.addSong("Imagine", "John Lennon");
    playlist.addSong("Purple Rain", "Prince and the Revolution");
    playlist.addSong("Smells Like Teen Spirit", "Nirvana");
    playlist.displayPlaylist();
    cout << endl;
    playlist.shufflePlaylist();
    playlist.displayPlaylist();
    cout << endl;
    playlist.sortPlaylist();
    playlist.displayPlaylist();
    cout << endl;
    playlist.reversePlaylist();
    playlist.displayPlaylist();
    cout << endl;
    playlist.removeSong("Johnny B. Goode");
    playlist.displayPlaylist();
    cout << endl;
    playlist.clearPlaylist();
    playlist.displayPlaylist();
    return 0;
}
