CXX = g++
LFLAGS = -static
SRCS = TicTacToe.cpp functions\team_pick.cpp functions\player_game_logic.cpp functions\place_chooser.cpp functions\show_table.cpp functions\computer_ai.cpp functions\app.cpp functions\pseudo_rng.cpp
OUTPUTNAME = TicTacToe.exe

all:
	$(CXX) $(CFLAGS) -o $(OUTPUTNAME) $(SRCS) $(LFLAGS)
