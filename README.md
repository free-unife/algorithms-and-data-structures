# algorithms-and-data-structures
C functions related to "Algoritmi e strutture dati" 
course in UNIFE (University of Ferrara), year 2014-2015.

##What this repository is about

This repository is a collection of C functions you can freely use.

What you need is a compilant C compiler and preferibily `bash` to run the 
compile script like this:
```
$ cd src/<directory> &&./compile.sh
```
An executable file called `<directory>.o` will be created in the 
`src/<directory>` directory.

Fell free to contribute to this repository.

##Covered arguments

- Lists
  - List as ADT (Abstract Data Types - functional programming).
  - List Implementation of ADT and related operations.
- Stacks
  - Lists' ADT and implementations to create new operations.

##Function file structure

```
  License notice
  

  Include header(s)

  Brief description of what the (*) function does.

  I: Input[s]
  P: Propriety[es] of input P
  O: Output[s]
  C: Consequence[s]

  Function prototype
    
  Function code
```

(*) Each file can contain more than one function.

##License

Every file in this repository is covered by the WTFPL. We decided not to use 
the GPL because all these are implemetations of well known algorithms, 
so the copyleft clause and others clauses are not necessary here.
