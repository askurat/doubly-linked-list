#include "playlist.h"
#include <gtest/gtest.h>

TEST(Song, Constructor)
{
    Song s1("Hello", "Adele");
    EXPECT_EQ("Hello", s1.title);
    EXPECT_EQ("Adele", s1.artist);
}

TEST(Playlist, Constructor)
{
    Playlist p1;
    EXPECT_EQ(nullptr, p1.head);
    EXPECT_EQ(nullptr, p1.tail);
}

TEST(Playlist, AddSong)
{
    Playlist p1;
    p1.addSong("Hello", "Adele");
    p1.addSong("Shape of You", "Ed Sheeran");
    p1.addSong("Roar", "Katy Perry");
    EXPECT_EQ("Hello", p1.head->title);
    EXPECT_EQ("Adele", p1.head->artist);
    EXPECT_EQ("Roar", p1.tail->title);
    EXPECT_EQ("Katy Perry", p1.tail->artist);
}

TEST(Playlist, GetSong)
{
    Playlist p1;
    p1.addSong("Hello", "Adele");
    p1.addSong("Shape of You", "Ed Sheeran");
    p1.addSong("Roar", "Katy Perry");
    Song *s1 = p1.getSong("Hello");
    Song *s2 = p1.getSong("Shape of You");
    Song *s3 = p1.getSong("Roar");
    EXPECT_EQ("Hello", s1->title);
    EXPECT_EQ("Adele", s1->artist);
    EXPECT_EQ("Shape of You", s2->title);
    EXPECT_EQ("Ed Sheeran", s2->artist);
    EXPECT_EQ("Roar", s3->title);
    EXPECT_EQ("Katy Perry", s3->artist);
}

TEST(Playlist, MoveSong)
{
    Playlist p1;
    p1.addSong("Hello", "Adele");
    p1.addSong("Shape of You", "Ed Sheeran");
    p1.addSong("Roar", "Katy Perry");
    p1.moveSong("Shape of You", 1);
    EXPECT_EQ("Hello", p1.head->title);
    EXPECT_EQ("Adele", p1.head->artist);
    EXPECT_EQ("Shape of You", p1.head->next->title);
    EXPECT_EQ("Ed Sheeran", p1.head->next->artist);
    EXPECT_EQ("Roar", p1.tail->title);
    EXPECT_EQ("Katy Perry", p1.tail->artist);
}

TEST(Playlist, RemoveSong)
{
    Playlist p1;
    p1.addSong("Hello", "Adele");
    p1.addSong("Shape of You", "Ed Sheeran");
    p1.addSong("Roar", "Katy Perry");
    p1.removeSong("Hello");
    EXPECT_EQ("Shape of You", p1.head->title);
    EXPECT_EQ("Ed Sheeran", p1.head->artist);
    EXPECT_EQ("Roar", p1.tail->title);
    EXPECT_EQ("Katy Perry", p1.tail->artist);
}

TEST(Playlist, ClearPlaylist)
{
    Playlist p1;
    p1.addSong("Hello", "Adele");
    p1.addSong("Shape of You", "Ed Sheeran");
    p1.addSong("Roar", "Katy Perry");
    p1.clearPlaylist();
    EXPECT_EQ(nullptr, p1.head);
    EXPECT_EQ(nullptr, p1.tail);
}

TEST(Playlist, ReversePlaylist)
{
    Playlist p1;
    p1.addSong("Hello", "Adele");
    p1.addSong("Shape of You", "Ed Sheeran");
    p1.addSong("Roar", "Katy Perry");
    p1.reversePlaylist();
    EXPECT_EQ("Roar", p1.head->title);
    EXPECT_EQ("Katy Perry", p1.head->artist);
    EXPECT_EQ("Shape of You", p1.head->next->title);
    EXPECT_EQ("Ed Sheeran", p1.head->next->artist);
    EXPECT_EQ("Hello", p1.tail->title);
    EXPECT_EQ("Adele", p1.tail->artist);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
