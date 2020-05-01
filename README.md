## osu! Map Reader
Read and visualize [.osu file format](https://osu.ppy.sh/help/wiki/osu!_File_Formats/Osu_(file_format)) which contains information about an osu! beatmap.

## Dependencies
```
SDL2
SDL2_image
SDL2_ttf
```

## Build and Run
1. Add .osu file to directory
2. Edit `fileLocation` in `source.cpp` with .osu file location
3. Compile and run:
```
$ g++ source.cpp -w -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -o source
$ ./source
```