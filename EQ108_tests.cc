#include "Clases.h"
#include "gtest/gtest.h"

TEST(menuAdmin1,Testsmenus){

    EXPECT_GT(menuAdmin1(),-1);
    EXPECT_GT(menuAdmin2(),-1);
    EXPECT_GT(menuUsuario(),-1);

    EXPECT_LT(menuAdmin1(),9);
    EXPECT_LT(menuAdmin2(),9);
    EXPECT_LT(menuUsuario(),9);
}