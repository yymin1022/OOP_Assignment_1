CC = g++
CXXFLAGS = -Wall -O2
OBJ = main.o

main.o: main.cpp File.h ManageData.h Student.h VerifyData.h
	$(CC) $(CXXFLAGS) -c main.cpp

StudentManage: $(OBJ)
	$(CC) $(CXXFLAGS) $(OBJ) -o StudentManage

.PHONY: clean
clean:
	rm -f $(OBJ) StudentManage
