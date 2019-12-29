cmake_minimum_required(VERSION 3.15)
project(pobi_proj_szachy)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_C_FLAGS_DEBUG "-g3 -gdwarf-4")
set(CMAKE_CXX_FLAGS_DEBUG "-g3 -gdwarf-4")

find_package (Boost 1.60.0 COMPONENTS "unit_test_framework" REQUIRED)

set(SOURCE_FILES
        program/src/Field.cpp program/headers/Field.h program/headers/Position.h program/src/Position.cpp program/src/Board.cpp program/headers/Board.h program/src/Pieces/Piece.cpp program/headers/Pieces/Piece.h program/src/Pieces/Pawn.cpp program/headers/Pieces/Pawn.h)

set(SOURCE_TEST_FILES
        program/test/master.cpp
        program/test/FieldTest.cpp program/test/BoardTest.cpp )


add_executable (TestChess
        ${SOURCE_TEST_FILES}
        ${SOURCE_FILES}
        )

add_executable(pobi_proj_szachy ${SOURCE_FILES}
        program/src/main.cpp)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/program/headers
        ${Boost_INCLUDE_DIRS}
)


target_link_libraries (TestChess
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
        )
IF(WIN32)
    target_link_libraries (TestChess
            -lbcrypt
            )
ENDIF(WIN32)

target_link_libraries (pobi_proj_szachy
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