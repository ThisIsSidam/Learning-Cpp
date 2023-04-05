// --------------------------------------
// Author- Anshu Kumar Singh a.k.a. Sidam
// Purpose- Notes of Learning C++
// Date - 21/03/2023
//
// Problem14B Of Learning C++
// After Day47
// Name - Song Playlist
// --------------------------------------

/*
We have to make a program that first shows us the list of songs in the playlist and show the 
current playing song. After that gives us option to play the first song, or the next song,
or the previous song, or even add or delete a song from the playlist. And also to list all
the songs in the playlist. Simple. We have to do all that with doubly-linked lists, nothing
else.
*/

#include <iostream>
#include <string>
#include <list>
#include <iomanip>
#include "Song.h"

void print_playlist (std::list<Song> &, std::list<Song>::iterator &);
void print_menu ();
void playing_song (std::list<Song>::iterator &);
void add_song (std::list<Song> &, std::list<Song>::iterator &);
void remove_song (std::list<Song> &);

int main() {

    std::list<Song> playlist {
        {"Alone", "Alan Walker", 4},
        {"Bones", "Imagine Dragons", 4}
    };

    auto current_song = playlist.begin();

    print_playlist(playlist, current_song);

    int choice;
    do {
        print_menu();
        std::cin >> choice;

        switch (choice) {

            case 1 : 
            {
                print_playlist(playlist, current_song);
                break;
            }

            case 2 :
            {
                current_song = playlist.begin();
                playing_song(current_song);
                break;
            }

            case 3 :
            {   
                if ( current_song != --playlist.end() )
                {
                    playing_song(++current_song);
                    break;
                }
                else 
                {
                    current_song = playlist.begin();
                    playing_song(current_song);
                    break;
                }
            }

            case 4 :
            {
                if ( current_song != playlist.begin() )
                {
                    playing_song(--current_song);
                    break;
                } 
                else 
                {
                    current_song = --playlist.end();
                    playing_song(current_song);
                    break;
                }
            }

            case 5 :
            {
                add_song(playlist, current_song);
                break;
            }

            case 6 :
            {
                remove_song(playlist);
                break;
            }

            case 0 :
            {
                std::cout << "Goodbye!\n";
                break;
            }

            default : 
            {
                std::cout << "You've entered an illegal value!\n";
            }

        }
    } while (choice != 0);

    return 0;
}

void print_playlist (std::list<Song> &list, std::list<Song>::iterator &cs) {
    auto it = list.begin();
    while ( it != list.end() ) 
    {
        std::cout << *it;
        it++;
    }

    std::cout << "Current Song: \n";
    std::cout << *cs;
}

void print_menu () {
    std::cout << "\n1. List The Playlist Songs"
              << "\n2. Play First Song"
              << "\n3. Play Next Song"
              << "\n4. Play Previous Song"
              << "\n5. Add a Song in the Playlist" 
              << "\n6. Remove a Song from the Playlist"
              << "\n0. Quit\n"
              << "Enter Your Choice: ";
}

void playing_song (std::list<Song>::iterator &cs) {
    std::cout << "Playing Song: \n";
    std::cout << *cs;
}

void add_song (std::list<Song> &list, std::list<Song>::iterator &cs) {
    std::string name, creator;
    int rating;

    std::cout << "Enter the name of the song: ";
    std::cin.ignore();
    std::getline(std::cin, name);
    std::cout << "Enter the name of the creator of the song: ";
    std::getline(std::cin, creator);
    std::cout << "How would you like to rate this song from 1 to 5: ";

    std::cin >> rating;
    while ( (rating > 5) | (rating < 0) )
    {   
        if ( rating > 5 )
        {
            std::cout << "Rating can't be greater than 5!\n"; 
        }
        else if ( rating < 0 )
        {
            std::cout << "Rating can't be less then 0!\n";
        }
        std::cout << "Enter again: ";
        std::cin >> rating;
    }

    list.emplace(cs, name, creator, rating);
    std::cout << name << " has been added to the playlist!\n";
}

void remove_song (std::list<Song> &list) {
    std::string name;
    std::cout << "Enter the name of the song you want to delete: ";
    std::cin.ignore();
    std::getline(std::cin, name);

    auto it = list.begin();
    while (it != list.end()) 
    {
        if ( name == it->get_name() ) 
        {
            list.erase(it);
            std::cout << name << " has been removed from the playlist!\n";
            return;
        }

        it++;
    }

    std::cout << name << " was not found in the playlist!\n";
}