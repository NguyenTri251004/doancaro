#include"control.h"
#include "view.h"
#include "Function_C.h"
void TextColor(int x)
{
    HANDLE mau = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(mau, x);
}
void khoitao(Contro& contro, Contro& contro1)
{
    contro.td.x = 32; contro.td.y = 21;
    contro1.td.x = 40; contro1.td.y = 21;
}
void hienthi(Contro contro, Contro contro1, int daux, int dau0, Xoacontro xoacontro, Xoacontro xoacontro1, XO A)
{
    //Contro 1----------------------------------------------------------------------------------------------
    if (daux == 1)
    {
        TextColor(14); GotoXY(xoacontro.td.x, xoacontro.td.y); printf(" X ");
        GotoXY(contro.td.x, contro.td.y); TextColor(224); printf("   ");
    }
    else if (daux == 2)
    {
        TextColor(235); GotoXY(contro.td.x, contro.td.y); printf(" X ");
    }
    else if (daux == 0)
    {
        GotoXY(contro.td.x, contro.td.y); TextColor(224); printf("   ");
    }
    //Con tro 2----------------------------------------------------------------------------------------------------
    if (dau0 == 1)
    {
        TextColor(12); GotoXY(xoacontro1.td.x, xoacontro1.td.y); printf(" O ");
        GotoXY(contro1.td.x, contro1.td.y); TextColor(207);  printf("   ");
    }
    else if (dau0 == 2)
    {
        TextColor(207); GotoXY(contro1.td.x, contro1.td.y); printf(" O ");
    }
    else if (dau0 == 0)
    {
        GotoXY(contro1.td.x, contro1.td.y); TextColor(207);  printf("   ");
    }
    //Khoi phuc cac quan co------------------------------------------------
    for (int i = 0; i < A.nx; i++)
    {
        GotoXY(A.vtx[i].x, A.vtx[i].y); TextColor(14);  printf(" X ");
    }
    for (int i = 0; i < A.no; i++)
    {
        GotoXY(A.vto[i].x, A.vto[i].y); TextColor(12); printf(" O ");
    }

    for (int i = 0; i < A.nx; i++)
    {
        if (contro.td.x == A.vtx[i].x && contro.td.y == A.vtx[i].y)
        {
            GotoXY(contro.td.x, contro.td.y); TextColor(233); printf(" X ");
        }
        if (contro1.td.x == A.vtx[i].x && contro1.td.y == A.vtx[i].y)
        {
            GotoXY(contro1.td.x, contro1.td.y); TextColor(193);  printf(" X ");
        }
    }
    for (int i = 0; i < A.no; i++)
    {
        if (contro.td.x == A.vto[i].x && contro.td.y == A.vto[i].y)
        {
            GotoXY(contro.td.x, contro.td.y); TextColor(233);  printf(" O ");
        }
        if (contro1.td.x == A.vto[i].x && contro1.td.y == A.vto[i].y)
        {
            GotoXY(contro1.td.x, contro1.td.y); TextColor(193); printf(" O ");
        }
    }
}
void Xoacursor(Xoacontro xoacontro, Xoacontro xoacontro1, int daux, int dau0)
{
    GotoXY(xoacontro.td.x, xoacontro.td.y);
    if (daux == 0) printf("   ");
    GotoXY(xoacontro1.td.x, xoacontro1.td.y);
    if (dau0 == 0) printf("   ");
}
void dieukhien(Contro& contro, Contro& contro1, Xoacontro& xoacontro, Xoacontro& xoacontro1, int& daux, int& dau0, XO& A, int& dem, int& dem1, int& luotchoi, int& luuct)
{
    int ct = 5;
    //  if(kbhit())
    {
        int a = _getch();
        if (a == 'a' || a == 'A') ct = 0;
        else if (a == 'd' || a == 'D') ct = 1;
        else if (a == 's' || a == 'S') ct = 2;
        else if (a == 'w' || a == 'W') ct = 3;
        else if (a == 'e' || a == 'E') ct = 4;
        else if (a == 75) ct = 10;
        else if (a == 77) ct = 11;
        else if (a == 80) ct = 12;
        else if (a == 72) ct = 13;
        else if (a == 13) ct = 14;
    }
    xoacontro.td = contro.td;
    xoacontro1.td = contro1.td;
    if (ct == 0 && contro.td.x > 5) contro.td.x = contro.td.x - 4;       // nhan phim a
    else if (ct == 1 && contro.td.x < 71) contro.td.x = contro.td.x + 4;  //Nhan phim d
    else if (ct == 2 && contro.td.y < 41) contro.td.y = contro.td.y + 2;   //Nhan phim S
    else if (ct == 3 && contro.td.y > 4) contro.td.y = contro.td.y - 2;   //Nhan phim W
    else if (ct == 4)
    {
        int n = 0;
        if (luotchoi == 0 || luotchoi % 2 == 1)
        {
            for (int i = 0; i < A.nx; i++) if (contro.td.x == A.vtx[i].x && contro.td.y == A.vtx[i].y) n++;
            for (int i = 0; i < A.no; i++) if (contro.td.x == A.vto[i].x && contro.td.y == A.vto[i].y) n++;
            if (luotchoi == 0) luotchoi = 1;
            if (n == 0)
            {
                if (luuct == ct) luotchoi++;
                daux = 2;
                A.vtx[dem] = contro.td;
                dem++;
                A.nx++;
            }
            else if (n >= 1 && luuct != ct) luotchoi--;
        }
    }  //Nhan phim E
    else if (ct == 10 && contro1.td.x > 5) contro1.td.x = contro1.td.x - 4;    // mui ten de di chuyen
    else if (ct == 11 && contro1.td.x < 71) contro1.td.x = contro1.td.x + 4;  
    else if (ct == 12 && contro1.td.y < 41) contro1.td.y = contro1.td.y + 2;   
    else if (ct == 13 && contro1.td.y > 4) contro1.td.y = contro1.td.y - 2;  
    else if (ct == 14)
    {
        int n = 0;
        if (luotchoi == 0 || luotchoi % 2 == 0)
        {
            for (int i = 0; i < A.no; i++) if (contro1.td.x == A.vto[i].x && contro1.td.y == A.vto[i].y) n++;
            for (int i = 0; i < A.nx; i++) if (contro1.td.x == A.vtx[i].x && contro1.td.y == A.vtx[i].y) n++;
            if (n == 0)
            {
                if (ct == luuct) luotchoi++;
                dau0 = 2;
                A.vto[dem1] = contro1.td;
                dem1++;
                A.no++;
            }
            else if (n >= 1 && luuct != ct) luotchoi--;
        }
    } //Nhan phim enter
    if ((ct == 10 || ct == 11 || ct == 12 || ct == 13) && dau0 >= 1) dau0--;
    if ((ct == 0 || ct == 1 || ct == 2 || ct == 3) && daux >= 1) daux--;
    if (ct == 4 || ct == 14)
    {
        if (ct != luuct) luotchoi++;
        luuct = ct;
    }
}
void Luotchoi(int luotchoi, XO A)
{
    GotoXY(150, 3);
    TextColor(14);
    if ((luotchoi > 0 && luotchoi % 2 == 1)||luotchoi==0) printf("X");
    else if (luotchoi % 2 == 0)
    {
        TextColor(12);
        printf("O");
    }
    GotoXY(100, 3);   TextColor(14); printf("%d", A.nx);
    GotoXY(115, 3); TextColor(14); printf("%d", A.no);
}
