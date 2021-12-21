#include "Clases.h"
#include "gtest/gtest.h"

TEST(menuAdminUsuarios,Testsmenus){
    EXPECT_GT(menuAdmin1(),-1);
    EXPECT_LT(menuAdmin1(),4);    
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

TEST(menuAdminMaquinas,Testsmenus){
    EXPECT_GT(menuAdmin2(),3);
    EXPECT_LT(menuAdmin2(),7);    
}

TEST(menuUsuarios,Testsmenus){
    EXPECT_GT(menuUsuario(),6);
    EXPECT_LT(menuUsuario(),9);
}

TEST(creaReserva,TestReserva){
	Reservas res;
	EXPECT_EQ(true,res.creaReserva("manolo"));
}