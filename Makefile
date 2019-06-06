CC     = g++
CFLAGS = -Wall -O2 -Wno-unused-result -g
LIB    = -lm -lGL -lSDL -lGLU -lSDL_image 
OBJ    = building.o monster.o main.o tower.o checkMap.o wave.o timer.o utils.o map.o 
RM     = rm -f
BIN    = bin/towerdefense
DIRNAME = $(shell basename $$PWD)
BACKUP  = $(shell date +`basename $$PWD`-%m.%d.%H.%M.zip)
STDNAME = $(DIRNAME).zip

all : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $(BIN)
	@echo "--------------------------------------------------------------"
	@echo "            to execute type: $(BIN) &"
	@echo "--------------------------------------------------------------"

building.o : src/building.cpp include/building.h
	@echo "compile building"
	$(CC) $(CFLAGS) -c $<  
	@echo "done..."

main.o : src/main.cpp include/map.h include/monster.h include/timer.h include/tower.h include/wave.h include/utils.h include/checkMap.h include/building.h include/map.h
	@echo "compile main"
	$(CC) $(CFLAGS) -c $<  
	@echo "done..."

# game.o : src/game.cpp include/game.h
# 	@echo "compile game"
# 	$(CC) $(CFLAGS) -c $<  
# 	@echo "done..."

timer.o : src/timer.cpp include/timer.h
	@echo "compile timer"
	$(CC) $(CFLAGS) -c $<
	@echo "done..."

utils.o : src/utils.cpp include/utils.h
	@echo "compile utils"
	$(CC) $(CFLAGS) -c $<
	@echo "done..."

checkMap.o : src/checkMap.cpp include/checkMap.h
	@echo "compile checkMap"
	$(CC) $(CFLAGS) -c $<
	@echo "done..."

wave.o : src/wave.cpp include/wave.h
	@echo "compile wave"
	$(CC) $(CFLAGS) -c $<
	@echo "done..."

map.o : src/map.cpp include/map.h
	@echo "compile map"	
	$(CC) $(CFLAGS) -c $<  
	@echo "done..."

monster.o : src/monster.cpp include/monster.h
	@echo "compile monster"
	$(CC) $(CFLAGS) -c $<  
	@echo "done..."

tower.o : src/tower.cpp include/tower.h
	@echo "compile tower"
	$(CC) $(CFLAGS) -c $<  
	@echo "done..."


clean :	
	@echo "**************************"
	@echo "CLEAN"
	@echo "**************************"
	$(RM) *~ $(OBJ) $(BIN)    

bigclean :
	@echo "**************************"
	@echo "BIG CLEAN"
	@echo "**************************"
	find . -name '*~' -exec rm -fv {} \;
	$(RM) *~ $(OBJ) $(BIN)

zip : clean 
	@echo "**************************"
	@echo "ZIP"
	@echo "**************************"
	cd .. && zip -r $(BACKUP) $(DIRNAME)
