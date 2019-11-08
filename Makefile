# Makefile
# Specify what I need in the end. One single executable
divisonExecutable : main.o div.o
# Read this as divisionExecutable depends on main.o div.o
# But how is it produced??? Hmm...using the below statement
    g++ main.o div.o -o divisonExecutable 
# starts with tab, I repeat tab
#-----------------------------------------------------------------
# But main.o is not there? So specify how it is produced.
main.o : main.cpp div.h
    g++ -c main.cpp
# Same for test.o
test.o : test.cpp test.h
    g++ -c test.cpp
