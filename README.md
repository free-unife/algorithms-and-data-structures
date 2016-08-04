# algorithms-and-data-structures
C and Python exercises related to "Algoritmi e strutture dati" 
course in UNIFE (University of Ferrara), years 2014-2016.

##What this repository is about

This repository is a collection of C and Python exercises you can freely use.

Fell free to contribute to this repository and enjoy :) .

##Repository cloning
Since [libncc](https://github.com/free-unife/libncc) is used as a [git submoudle](https://git-scm.com/book/en/v2/Git-Tools-Submodules) for some 
exercises, the following command will clone everything needed:
```
$ git clone --recursive https://github.com/free-unife/algorithms-and-data-structures
```

##Programming languages
###C
####Makefile
Traditional `Makefile`s are available for some exercises. A list of the 
possible targets is given in a `README.md` file.

####Script
What you need is a compilant ANSI C99 compiler and `bash` to run 
the compile script like this:
```
$ cd src/<directory> && ./build.sh
```
An executable file called `<directory>.o` will be created in the 
`src/<directory>` directory.

If you have the program `indent` installed in your system, the 
files called by every `build.sh` will automatically be indented (and changed) 
with the options specified by the `indentOptions` variable in 
`src/mainBuild.sh`. Common programming mistakes and code errors are checked by 
the program `splint`. To use `indent` and `splint` you must add `-i` option 
after issuing `build.sh`, like this:
```
$ ./build.sh -i
```
Some exercises need `gnuplot` to be installed, otherwise no output is shown.
Specifically the build files behave similarly to `build.sh` 
and they are called `buildAndPlot.sh`.

####Dependencies
```
gnuplot
splint
indent
bash
```

###Python
To execute python programs simply install `python3` then run:
```
python <programName>
```

####Dependencies
```
matplotlib
```

##Covered arguments
Run: `$ tree -d src/` 

##License
Every file in this repository is covered by the WTFPL. We decided not to use 
the GPL because all these are implemetations of well known algorithms, 
so the copyleft clause and others clauses are not necessary here.
