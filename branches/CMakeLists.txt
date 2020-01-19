cmake_minimum_required(VERSION 3.4)

project(pobi_proj_szachy)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_C_FLAGS_DEBUG "-g3 -gdwarf-4")
set(CMAKE_CXX_FLAGS_DEBUG "-g3 -gdwarf-4")

find_package (Boost 1.60.0 COMPONENTS "unit_test_framework" REQUIRED)

set(SOURCE_FILES
        program/src/Field.cpp program/headers/Field.h program/headers/Position.h program/src/Position.cpp program/src/Board.cpp program/headers/Board.h program/src/Pieces/Piece.cpp program/headers/Pieces/Piece.h program/src/Pieces/Pawn.cpp program/headers/Pieces/Pawn.h program/src/Pieces/Queen.cpp program/headers/Pieces/Queen.h program/src/Pieces/Rook.cpp program/headers/Pieces/Rook.h program/src/Pieces/Knight.cpp program/headers/Pieces/Knight.h program/src/Pieces/Bishop.cpp program/headers/Pieces/Bishop.h program/src/Pieces/King.cpp program/headers/Pieces/King.h program/src/Game.cpp program/headers/Game.h program/src/Player/Player.cpp program/headers/Player/Player.h program/src/Player/Move.cpp program/headers/Player/Move.h program/src/Player/Previous_Move.cpp program/headers/Player/Previous_Move.h program/src/Player/Human.cpp program/headers/Player/Human.h program/src/Player/AI.cpp program/headers/Player/AI.h)

add_library(library ${SOURCE_FILES})

target_include_directories(library PUBLIC include)


set(SOURCE_TEST_FILES
        program/test/master.cpp
        program/test/FieldTest.cpp program/test/BoardTest.cpp program/test/PiecesTest.cpp program/test/PlayerTest.cpp program/test/GameTest.cpp program/test/MoveTest.cpp)


add_executable (TestChess
        ${SOURCE_TEST_FILES}
        #${SOURCE_FILES}
        )

add_executable(pobi_proj_szachy 
		# ${SOURCE_FILES}
        program/src/main.cpp)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/program/headers
        ${Boost_INCLUDE_DIRS}
)


target_link_libraries (TestChess
		library
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
        )
IF(WIN32)
    target_link_libraries (TestChess
            -lbcrypt
            )
ENDIF(WIN32)

target_link_libraries (pobi_proj_szachy
		library
        )
IF(WIN32)
    target_link_libraries (pobi_proj_szachy
            -lbcrypt
            )
ENDIF(WIN32)

enable_testing()

add_test(TestSzachy1 ChessTest
        --report_level=detailed
        --log_level=all
        --color_output=yes
        )

set(CMAKE_CXX_FLAGS "-Wall -Wpedantic -Wextra -werror")
set(CMAKE_CXX_FLAGS "-DBOOST_SYSTEM_NO_DEPRECATED")
add_definitions(-DBOOST_ERROR_CODE_HEADER_ONLY)