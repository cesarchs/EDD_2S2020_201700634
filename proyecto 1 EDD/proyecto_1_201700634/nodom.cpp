#include "nodom.h"

nodoM::nodoM()
{
    private:
        int R, G, B;
        int x, y;
        int v;
    public:
        nodoM* right;
        nodoM* down;
        nodoM* left;
        nodoM* up;
        nodoM(int R, int G, int B, int x, int y) {
            this->R = R;
            this->B = B;
            this->G = G;
            this->x = x;
            this->y = y;
            right = NULL;
            left = NULL;
            down = NULL;
            up = NULL;
        }

       nodoM(int v) {
            this->v = v;
            right = NULL;
            left = NULL;
            down = NULL;
            up = NULL;
        }
        //GETTERS
        int getR() { return this->R; } int getG() { return this->G; } int getB() { return this->B; }
        int getV() { return this->v; } int getX() { return this->x; } int getY() { return this->y; }
        //SETTERS
        void setR(int R) { this->R = R; } void setG(int G) { this->G = G; } void setB(int B) { this->B = B; }
        void setV(int V) { this->v = V; } void setX(int X) { this->x = X; } void setY(int Y) { this->y = Y; }
}
