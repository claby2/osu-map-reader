## osu! Map Reader
Read and visualize [.osu file format](https://osu.ppy.sh/help/wiki/osu!_File_Formats/Osu_(file_format)) which contains information about an osu! beatmap. It ignores 'sliders' and treats them as a standard 'hit circle' located at the start of the 'slider'.

## Dependencies
```
SDL2
```

## Build and Run
1. Add .osu file to directory
2. Edit `fileLocation` in `source.cpp` with .osu file location
3. Compile and run:
```
$ g++ source.cpp -w -lSDL2main -lSDL2 -o source
$ ./source
```
