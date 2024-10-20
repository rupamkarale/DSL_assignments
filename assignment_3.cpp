#include <iostream>
using namespace std;

class Track {
public:
    string title;
    Track* nextTrack;

    Track() {
        title = "";
        nextTrack = NULL;
    }

    Track(string newTitle) {
        title = newTitle;
        nextTrack = NULL;
    }
};

class MusicPlaylist {
public:
    Track* headTrack; // Removed default initialization

    MusicPlaylist() { // Constructor to initialize headTrack
        headTrack = NULL;
    }

    void addTrackAtBeginning(string newTitle);
    void addTrackAtEnd(string newTitle);
    void insertTrackAtPosition(string newTitle, int position);
    void removeTrackFromBeginning();
    void removeTrackFromEnd();
    void removeTrackAtPosition(int position);
    void displayPlaylist();
};

void MusicPlaylist::addTrackAtBeginning(string newTitle) {
    Track* newTrack = new Track(newTitle);
    if (headTrack == NULL) {
        cout << "Playlist is empty" << endl;
        headTrack = newTrack;
        return;
    }
    newTrack->nextTrack = headTrack;
    headTrack = newTrack;
}

void MusicPlaylist::addTrackAtEnd(string newTitle) {
    Track* newTrack = new Track(newTitle);
    if (headTrack == NULL) {
        headTrack = newTrack;
        return;
    }
    Track* temp = headTrack;
    while (temp->nextTrack != NULL) {
        temp = temp->nextTrack;
    }
    temp->nextTrack = newTrack;
}

void MusicPlaylist::insertTrackAtPosition(string newTitle, int position) {
    int pos = 0;
    Track* newTrack = new Track(newTitle);
    if (position == 0) {
        addTrackAtBeginning(newTitle);
        return;
    }
    Track* temp = headTrack;
    while ((pos + 1) != position && temp != NULL) {
        temp = temp->nextTrack;
        pos++;
    }
    if (temp == NULL) {
        cout << "Position out of bounds" << endl;
        return;
    }
    newTrack->nextTrack = temp->nextTrack;
    temp->nextTrack = newTrack;
}

void MusicPlaylist::removeTrackFromBeginning() {
    if (headTrack == NULL) {
        cout << "Playlist is already empty" << endl;
        return;
    }
    Track* temp = headTrack;
    headTrack = temp->nextTrack;
    delete temp; // Use delete instead of free
}

void MusicPlaylist::removeTrackFromEnd() {
    if (headTrack == NULL) {
        cout << "Playlist is already empty" << endl;
        return;
    }
    if (headTrack->nextTrack == NULL) {
        delete headTrack;
        headTrack = NULL;
        return;
    }
    Track* secondLast = headTrack;
    while (secondLast->nextTrack->nextTrack != NULL) {
        secondLast = secondLast->nextTrack;
    }
    Track* temp = secondLast->nextTrack;
    secondLast->nextTrack = NULL;
    delete temp; // Use delete instead of free
}

void MusicPlaylist::removeTrackAtPosition(int position) {
    if (position == 0) {
        removeTrackFromBeginning();
        return;
    }
    int pos = 0;
    Track* currentTrack = headTrack;
    while (currentTrack != NULL && (pos + 1) != position) {
        currentTrack = currentTrack->nextTrack;
        pos++;
    }
    if (currentTrack == NULL || currentTrack->nextTrack == NULL) {
        cout << "Position out of bounds" << endl;
        return;
    }
    Track* temp = currentTrack->nextTrack;
    currentTrack->nextTrack = currentTrack->nextTrack->nextTrack;
    delete temp; // Use delete instead of free
}

void MusicPlaylist::displayPlaylist() {
    Track* temp = headTrack;
    while (temp != NULL) {
        cout << temp->title << " --> ";
        temp = temp->nextTrack;
    }
    cout << "NULL" << endl;
}

int main() {
    MusicPlaylist myPlaylist;
    myPlaylist.addTrackAtBeginning("Shallow");
    myPlaylist.addTrackAtBeginning("Despacito");
    myPlaylist.addTrackAtEnd("Believer");
    myPlaylist.addTrackAtEnd("Lose Yourself");
    myPlaylist.insertTrackAtPosition("Perfect", 2);
    myPlaylist.removeTrackFromBeginning();
    myPlaylist.removeTrackFromEnd();
    myPlaylist.removeTrackAtPosition(1);
    
    cout << "Current Playlist:" << endl;
    myPlaylist.displayPlaylist();
    cout << endl;
    return 0;
}