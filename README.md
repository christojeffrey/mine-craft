# tubes1-oop-tall-corn
###### Kelompok 6 tall corn
CLI-based program that implements Minecraft-like crafting system using Object-oriented paradigm in c++.

## Author
NIM | NAMA
--- | ---
13520043 | Muhammad Risqi Firdaus
13520049 | Aditya Prawira Nugroho
13520055 | Christopher Jeffrey
13520058 | Kristo Abdi Wiguna
13520151 | Rizky Ramadhana

## What's Inside
This template consists of:
- config folder containing all the config files (items and recipes)
- tests folder containing two sample test files (input and answer)
- main.cpp containing the sample main code
- test.cpp containing the testing per unit code
- check.cpp containing the code for checking
- makefile for compiling and testing

## System Requirements
- UNIX based system or WSL if you're using windows
- C++ 17
- g++

## Running the Makefile
Make sure you are using Linux with C++17. WSL also works if you are using Windows.
If you are running for the first time, then
```
git clone https://github.com/christojeffrey/tubes1-oop-tall-corn
cd tubes1-oop-tall-corn
```

```
sudo apt-get install make g++
make compile
```
Using the sample main file, it should return that 1 out of 2 tests passed.

## Tests
Make sure you are using Linux with C++17. WSL also works if you are using Windows.
```
sudo apt-get install make g++
make compiletest
```

You can add more tests by adding more files to the tests folder. Tests consists of two files, input with "in" extension and answer with "ans" extension. Each test should have exactly one EXPORT command which exports the current inventory into an "out" file in the tests folder. Please refer to the sample tests. Checking will be done by comparing the answer file and the output file.

As the test is done by comparing the output files, you can freely use standard output in your program.
