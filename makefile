CXX = g++
LFLAGS = -static
SRCS = TicTacToe.cpp functions\team_pick.cpp functions\player_game_logic.cpp functions\place_chooser.cpp functions\show_table.cpp functions\computer_ai.cpp functions\app.cpp functions\pseudo_rng.cpp
OUTPUTNAMEWindows = TicTacToe.exe
OUTPUTNAMELinux = TicaTacToe.o
#This will compile all files 
all_windows:
	$(CXX) -o $(OUTPUTNAMEWindows) $(SRCS) $(LFLAGS)

all_linux:
	$(CXX) -o $(OUTPUTNAMELinux) $(SRCS) $(LFLAGS)

#This will delete exectuable files in current directory (which is compiled TicTacToe.exe).
clean_executable_windows:
	del $(OUTPUTNAMEWindows)

clean_executable_linux:
	rm -rf $(OUTPUTNAMELinux)