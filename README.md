 # Andrew Krikorian
#
# Project 4: The 'Make' utility
#
## Read a makefile, tokenize its contents (targets, dependents, command 
## and other necessary characters), parse through these tokens and create a search 
## tree, parse through the search tree to create a dependency graph and use this graph 
## to compare timstamps and dependents to 'make' the file.
# 
# To use the program:
## Must first make the program using the 'make' command to generate an executable. After
## doing so, you type './project4.x (MAKEFILE NAME)' into the command line and it should 
## act as the 'make' utility. 
#
# Compare results:
## You can compare results for the 'make' utility and this program by touching a few files
## then making the project with 'make'. Then touch the same files and use our command/program
## and compare outputs.
