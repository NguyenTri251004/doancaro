struct Toado {
    int x, y;
};
struct Contro {
    Toado td;
};
struct Xoacontro {
    Toado td;
};
struct XO {
    Toado vtx[300], vto[300];
    int nx = 0, no = 0;
};
void TextColor(int x);
void khoitao(Contro& contro, Contro& contro1);
void hienthi(Contro contro, Contro contro1, int daux, int dau0, Xoacontro xoacontro, Xoacontro xoacontro1, XO A);
void Xoacursor(Xoacontro xoacontro, Xoacontro xoacontro1, int daux, int dau0);
void dieukhien(Contro& contro, Contro& contro1, Xoacontro& xoacontro, Xoacontro& xoacontro1, int& daux, int& dau0, XO& A, int& dem, int& dem1, int& luotchoi, int& luuct);
void Luotchoi(int luotchoi, XO A);

