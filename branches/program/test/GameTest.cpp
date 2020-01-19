//
// Created by Przemek on 19.01.2020.
//

#include <boost/test/unit_test.hpp>
#include <memory>
#include "Field.h"
#include "Board.h"
#include "Player/AI.h"
#include "Player/Human.h"
#include "Game.h"
#include "boost/date_time/local_time/local_time.hpp"
#include "boost/date_time/posix_time/posix_time.hpp"
#ifdef linux
#include <unistd.h>
#elif _WIN32
#include <windows.h>
#endif
const int sleepMs = 1000;

BOOST_AUTO_TEST_SUITE(GameTestSuite)

    BOOST_AUTO_TEST_CASE(GameTest1) {
      Game game(false, true, false);
      BOOST_CHECK(dynamic_cast<AI*>(game.get_black_player().get()));
      BOOST_CHECK(dynamic_cast<Human*>(game.get_white_player().get()));
#ifdef linux
        usleep(sleepMs * 1000);
#elif _WIN32
        Sleep(sleepMs);
#endif
      BOOST_CHECK(game.time_passed() > boost::posix_time::duration_from_string("00:00:00"));
      BOOST_CHECK(game.get_white_player()->get_pieces() ==  game.get_black_player()->get_enemy_pieces());
      BOOST_CHECK(game.get_black_player()->get_pieces() == game.get_white_player()->get_enemy_pieces());
      game.save_game();
      Game game2 (false, false, true);  // when loading is_ai parameter doesn't matter
      BOOST_CHECK(game.time_passed().seconds() - game2.time_passed().seconds() <= 1);
      BOOST_CHECK(dynamic_cast<AI*>(game2.get_black_player().get()));
      BOOST_CHECK(dynamic_cast<Human*>(game2.get_white_player().get()));
      BOOST_CHECK(game2.get_white_player()->get_pieces() ==  game2.get_black_player()->get_enemy_pieces());
      BOOST_CHECK(game2.get_black_player()->get_pieces() == game2.get_white_player()->get_enemy_pieces());

    }




BOOST_AUTO_TEST_SUITE_END()