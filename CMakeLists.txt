cmake_minimum_required(VERSION 3.15)
project(filghtSimolator)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -pthread)

add_executable(filghtSimolator main.cpp openDataServerCommand.cpp openDataServerCommand.h Data.cpp Data.h Command.h ex1.cpp ex1.h Lexer.cpp Lexer.h
        parserClass.cpp parserClass.h DefineVarCommand.cpp DefineVarCommand.h whileLoopCommand.cpp whileLoopCommand.h printCommand.cpp printCommand.h
        ifCommand.cpp ifCommand.h mapsSingeltonClass.h ConnectControlClientCommand.cpp ConnectControlClientCommand.h sleepCommand.cpp sleepCommand.h)