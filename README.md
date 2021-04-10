# randomizeSpotifyPlaylist

The random function in spotify has a tendency to always play the same songs, even in playlists with titles >1000.

In this is a work-around the user has to copy the content of playlist, to randomize it and to create a new playlist.

Usage

- go to your spotify playlist within the spotify desktop app
- select and copy all tracks, `CTRL+A` followed by `CTRL+C` on windows
- paste it into a textfile `playlist.txt`
- run `main.exe` or `main.out`
- open the result file `playlist_randomized.txt` and copy the content, again `CTRL+A` followed by `CTRL+C` on windows
- create a new playlist in the spotify desktop app
- paste the tracks, `CTRL+V` on windows
- enjoy a randomize playlist

Usage with dedicated file names

```bash
./main.out inputfilename outputfilename
```

Windows version compiled with mingw32

```bash
x86_64-w64-mingw32-g++ -static -o main.exe spotify.cc
```
