#include<iostream>
#include<list>
#include<string>
#include<iomanip>
#include<limits>

typedef enum _flagSong
{
    NONE,
    FIRST_SONG,
    NEXT_SONG,
    PREVIOUS_SONG,
    ADD_PLAY,
    LIST
}FlagSong;
FlagSong flag_song = NONE;

class Song
{
private:
    friend std::ostream &operator<<(std::ostream &os ,const Song &s);
    std::string name;
    std::string artist;
    int rating;

public:
    Song() = default;
    Song(std::string n, std::string ar, int r)
        : name{n}, artist{ar}, rating{r} {}
    bool operator==(const Song &rhs) const{
        return (this->name == rhs.name);
    }
    bool operator<(const Song &rhs) const{
        return (this->rating < rhs.rating);
    }
    std::string get_name() const {
        return name;
    }
    std::string get_artist() const {
        return artist;
    }
    int get_rating() const {
        return rating;
    }
};

std::ostream &operator<<(std::ostream &os ,const Song &s)
{
    os << std::setw(20) << std::left << s.name
       << std::setw(30) << std::left << s.artist
       << std::setw(2) << std::left << s.rating;
    return os;
}

void display_menu()
{
    std::cout << "\nF - Play First Song" << std::endl;
    std::cout << "N - Play Next Song" << std::endl;
    std::cout << "P - Play Previous Song" << std::endl;
    std::cout << "A - Add and play a new song at curent location" << std::endl;
    std::cout << "E - Erase and play song at next location" << std::endl;
    std::cout << "L - List the current playlist" << std::endl;
    std::cout << "===========================================" << std::endl;
    std::cout << "Enter a selection (Q to quit): ";
}

void play_current_song(const Song &song)
{
    std::cout << "Current Song:" << std::endl;
    std::cout << song;

}

void display_playlist(const std::list<Song> &playL, const Song &cur_song)
{
    for(const auto &p: playL)
        std::cout << p << std::endl;
    
    play_current_song(cur_song);
}

int main()
{
    std::string song_name;    
    std::string artist_name;
    int rating{};

    std::list<Song> playlist{
        {"God's Plan",  "Drake",    5},
        {"Never Be The Same",   "Camila Cabello",   5},
        {"Pray For Me",     "The Weekend and K.Lamar",  4},
        {"The Middle",      "Zedd, Maren Morris & Grey", 5},
        {"Wait",        "Maroone 5",    4},
        {"Whatever It Takes",   "Imagine Dragons",  3}
    };

    std::list<Song>::iterator current_song = playlist.begin();

    display_playlist(playlist, *current_song);
    display_menu();
    
    char c{};
    std::cin >> c;
    
    while(c != 'Q'){
        switch (c)
        {
        case 'F': case 'f':
            current_song = playlist.begin();
            play_current_song(*current_song);
            break;
        case 'N': case 'n':
            ++current_song;
            if(current_song == playlist.end())
                current_song = playlist.begin();
            play_current_song(*current_song);
            break;
        case 'P': case 'p': 
            if(current_song == playlist.begin())
                current_song = --(playlist.end());
            else
                --current_song;
            play_current_song(*current_song);
            break;
        case 'A': case 'a': 
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Enter song name: ";
            std::getline(std::cin, song_name);
            std::cout << "\nEnter artist name: ";
            std::getline(std::cin, artist_name);            
            std::cout << "Enter rating: ";
            std::cin >>rating;
            playlist.emplace(current_song, Song(song_name, artist_name, rating));
            play_current_song(*(--current_song));
            break;
        case 'E': case 'e':
            std::cout << "Erasing current song from list." << std::endl;
            current_song = playlist.erase(current_song);
            break;
        case 'L': case 'l': 
            display_playlist(playlist, *current_song);
            break;
        
        default:
            std::cout << "Entered wrong command. Please try again." << std::endl;
            break;
        }
        
        display_menu();
        std::cin >> c;
    }
    return 0;
}









