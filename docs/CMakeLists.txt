cmake_minimum_required(VERSION 3.16)
project(docs)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(docs
        CLI.cpp
        CLI.h
        collection.cpp
        collection.h
        controller.cpp
        controller.h
        dna_sequence.cpp
        dna_sequence.h
        DNAMetadata.cpp
        DNAMetadata.h
        Dup.cpp
        Dup.h
        IAppend.cpp
        IAppend.h
        IDelete.cpp
        IDelete.h
        IExecute.cpp
        IExecute.h
        IGet.cpp
        IGet.h
        IUpdate.cpp
        IUpdate.h
        IUpdateStatus.cpp
        IUpdateStatus.h
        Load.cpp
        Load.h
        main.cpp
        MapCommand.cpp
        MapCommand.h
        New.cpp
        New.h
        Pair.cpp
        Pair.h
        Save.cpp
        Save.h
        Slice.cpp
        Slice.h)
