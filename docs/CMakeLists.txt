cmake_minimum_required(VERSION 3.16)
project(docs)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(docs
        cli.cpp
        cli.h
        collection.h
        controller.h
        dna_sequence.cpp
        dna_sequence.h
        executeHandler.h
        IexecuteHandler.h
        Load.h
        mapCommand.h
        DNAMetadata.cpp DNAMetadata.h collection.cpp Load.cpp main.cpp IAppend.cpp IAppend.h IUpdate.cpp IUpdate.h IDelete.cpp IDelete.h controller.cpp executeHandler.cpp IexecuteHandler.cpp mapCommand.cpp)
