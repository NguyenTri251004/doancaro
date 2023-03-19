#include"Function_C.h" //hàm cơ bản của c++ trong đây
#include"view.h"
#include"control.h"

void main() {
    
    FullScreen();
    setColor(1);
    FixConsoleWindow();
    DrawBoard();
     do {
        int daux = 0, dau0 = 0, dem = 0, dem1 = 0, luotchoi = 0, luuct = 0, xoald = 0;
        Xoacontro xoacontro{}, xoacontro1{};
        Contro contro, contro1;
        XO A;
        khoitao(contro, contro1);
        do {
            if (xoald != 0) Xoacursor(xoacontro, xoacontro1, daux, dau0); xoald = 1;
            hienthi(contro, contro1, daux, dau0, xoacontro, xoacontro1, A);
            dieukhien(contro, contro1, xoacontro, xoacontro1, daux, dau0, A, dem, dem1, luotchoi, luuct);
            Luotchoi(luotchoi, A);
        } while (1);
        bool validEnter = true;

    }while(1);
    GotoXY(0, 0);
    _getch();
}
   

