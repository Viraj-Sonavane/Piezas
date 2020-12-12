/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"
 
class PiezasTest : public ::testing::Test
{
	protected:
		PiezasTest(){} //constructor runs before each test
		virtual ~PiezasTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(PiezasTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

TEST(PiezasTest, Invalid_Entry)
{
	Piezas A;
	Piece val1 = A.dropPiece(10);
	ASSERT_EQ(val1, Invalid);
}

TEST(PiezasTest, Return_Invalid)
{
	Piezas A;
	Piece val1 = A.dropPiece(7);
	ASSERT_EQ(val1, Invalid);
}

TEST(PiezasTest, Out_of_Bound)
{
	Piezas A;
	Piece val1 = A.pieceAt(6,6,);
	ASSERT_EQ(val1, Invalid);
}

TEST(PiezasTest, Inserting_O)
{
	Piezas A;
	A.dropPiece(0);
	Piece val1 = A.dropPiece(0);
	ASSERT_EQ(val1, O);
}

TEST(PiezasTest, Inserting_X)
{
	Piezas A;
	A.dropPiece(0);
	Piece val1 = A.dropPiece(0);
	ASSERT_EQ(val1, X);
}

TEST(PiezasTest, Blank_Board)
{
	Piezas A;
	ASSERT_TRUE(Blank == A.reset());
}

TEST(PiezasTest, Unfinished_game)
{
	Piezas A;
	ASSERT_TRUE(Invalid == A.reset());
}

