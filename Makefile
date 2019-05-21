CC     = gcc
CFLAGS = -Wall -O2 -Wno-unused-result -g
LIB    = -lm
OBJ    = building.o image.o game.o monster.o subsystems.o tower.o #map.o
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

image.o : src/image.cpp include/image.h
	@echo "compile image"
	$(CC) $(CFLAGS) -c $<  
	@echo "done..."

# main.o : include/main.c include/image.h include/game.h include/map.h include/monster.h include/subsystems.h include/tower.h
# 	@echo "compile main"
# 	$(CC) $(CFLAGS) -c $<  
# 	@echo "done..."

game.o : src/game.cpp include/game.h
	@echo "compile game"
	$(CC) $(CFLAGS) -c $<  
	@echo "done..."

# map.o : src/map.cpp include/map.h
# 	@echo "compile map"
# 	$(CC) $(CFLAGS) -c $<  
# 	@echo "done..."

monster.o : src/monster.cpp include/monster.h
	@echo "compile monster"
	$(CC) $(CFLAGS) -c $<  
	@echo "done..."

subsystems.o : src/subsystems.cpp include/subsystems.h
	@echo "compile subsystems"
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
