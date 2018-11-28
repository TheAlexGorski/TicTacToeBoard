/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

/* EXAMPLE TEST FORMAT
TEST(TicTacToeBoardTest, unitTestName)
{
	ASSERT_TRUE(true);
}
*/
TEST(TicTacToeBoardTest, firstTurn)
{
	TicTacToeBoard test = TicTacToeBoard();
	ASSERT_TRUE(test.toggleTurn() == O);
}

TEST(TicTacToeBoardTest, secondTurn)
{
	TicTacToeBoard test = TicTacToeBoard();
	test.toggleTurn();
	ASSERT_TRUE(test.toggleTurn() == X);
}

TEST(TicTacToeBoardTest, firstPlace)
{
	TicTacToeBoard test = TicTacToeBoard();
	ASSERT_EQ(test.placePiece(0, 0), X);
}

TEST(TicTacToeBoardTest, getEmpty)
{
	TicTacToeBoard test = TicTacToeBoard();
	ASSERT_EQ(test.getPiece(0, 0), Blank);
}

TEST(TicTacToeBoardTest, invalidRow)
{
	TicTacToeBoard test = TicTacToeBoard();
	ASSERT_TRUE(test.placePiece(3, 0) == Invalid);
}

TEST(TicTacToeBoardTest, invalidCol)
{
	TicTacToeBoard test = TicTacToeBoard();
	ASSERT_TRUE(test.placePiece(2, 3) == Invalid);
}