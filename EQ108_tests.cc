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

TEST(AdministradorUser, CrearUsuario){
	AdministradorUsu adminus;
	EXPECT_EQ(true, adminus.creaUsuario());
	
}

TEST(AdministradorUser, ModificarUser){
	AdministradorUsu adminus;
	std::cout<<"---------------------------------"<<endl<<"PRUEBE A ACTAULIZAR i02essej"<<endl<<"---------------------------------"<<endl;
	EXPECT_EQ(true,adminus.actualizaUsuario());
	
	std::cout<<"---------------------------------"<<endl<<"PRUEBE A ELIMINAR i02essej"<<endl<<"---------------------------------"<<endl;
	EXPECT_EQ(true,adminus.actualizaUsuario());
	
}
