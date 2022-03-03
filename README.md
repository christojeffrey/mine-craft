# tubes1-oop-tall-corn
repo buat tubes 1 oop

### dibuat oleh
- orang 123
- monyet 456

### link2 penting
[link pembagian kelompok](https://docs.google.com/spreadsheets/d/1e1iqv_0m8Hj05l9DQ6fYImuSGiHzUDW6z2K2LTNpIT8/edit#gid=2043760804)\
[link qna](https://docs.google.com/spreadsheets/d/1eId5WybvuhNl329oPe944U_iuOeaiQk7HQaVEPOSjeE/edit#gid=1410919163)\
[link spec](https://docs.google.com/document/d/1SeMA2ugBRTX8CC2HvdrkLcuhqRSLJ81m/edit)\
[link pedoman](https://docs.google.com/document/d/18TpVkY1RWG8EwFirT7qwFMvAEDTKdFdY/edit)\
[link laporan](https://docs.google.com/document/d/1G4pTkZyIyddl5NclLTXnlm7Fbg3ARk-4/edit)\
[link asistensi 1](https://docs.google.com/document/d/1NVLBiEOAP0xUehO1MuTZedD7Jtrwp341/edit)
--- 
# readme dari template

## What's Inside
This template consists of:
- config folder containing all the config files (items and recipes)
- tests folder containing two sample test files (input and answer)
- main.cpp containing the sample main code
- check.cpp containing the code for checking
- makefile for compiling and testing

## Running the Makefile
Make sure you are using Linux with C++17. WSL also works if you are using Windows.
```
sudo apt-get install make g++
make all
```
Using the sample main file, it should return that 1 out of 2 tests passed.

## Adding More Tests
You can add more tests by adding more files to the tests folder. Tests consists of two files, input with "in" extension and answer with "ans" extension. Each test should have exactly one EXPORT command which exports the current inventory into an "out" file in the tests folder. Please refer to the sample tests. Checking will be done by comparing the answer file and the output file.

As the test is done by comparing the output files, you can freely use standard output in your program.

Automated testing will not work if you are using GUI (obviously).