#include "matriz.h"

matriz::matriz()
{
    private:
        Mnode* head;
    public:
        Matrix() {
            Mnode* temp = new Mnode(0);
            head = temp;
        }
        Mnode* getHead(){
            return this->head;
        }
        void add(int R, int G, int B, int x, int y) {
            //HEADERS OR AXES
            X(x);
            Y(y);
            //NODE INSERTION
            Mnode* current = new Mnode(R, G, B, x, y);
            addX(current, x, y);
            addY(current, x, y);
        }

        std::string DecimalToHexadecimal(int dec) {
            if (dec < 1) return "00";
            int hex = dec;
            std::string hexStr = "";

            while (dec > 0){
                hex = dec % 16;
                if (hex < 10){
                    hexStr = hexStr.insert(0, string(1, (hex + 48)));
                }else{
                    hexStr = hexStr.insert(0, string(1, (hex + 55)));
                }
                dec /= 16;
            }

            return hexStr;
        }

        std::string RGBtoHEXA(int R, int G, int B) {
            std::string rs = DecimalToHexadecimal(R);
            std::string gs = DecimalToHexadecimal(G);
            std::string bs = DecimalToHexadecimal(B);
            return "#" + rs + gs + bs;
        }

        std::string getCSS(int width){
            std::string code = "";
            Mnode* tx = NULL;
            try {tx = head->right;}catch (const std::exception&) {tx = NULL;}
            Mnode* ty = NULL;
            int row = 0;
            while (tx != NULL) {
                if (tx->down != NULL) {
                    ty = tx->down;
                    row = ty->getX();
                    while (ty != NULL) {
                        code = code +"\n /*("+std::to_string(ty->getX())+","+std::to_string(ty->getY())+")  ->  "+std::to_string(ty->getY()+((row-1)*width))+"  Row:"+std::to_string(row)+"  Width:"+std::to_string(width)+"*/ \n";
                        code = code + "\n.pixel:nth-child(" + std::to_string(ty->getY()+((row-1)*width))+"){ background:"+ RGBtoHEXA(ty->getR(), ty->getG(), ty->getB()) + "; } \n";
                        ty = ty->down;
                    }
                }
                tx = tx->right;
            }
            return code;
        }


        std::string XlinealGraph(){

            std::string code = "rankdir = LR; graph [nodesep=\"0.8\", ranksep=\"0.6\"]; \n";
            Mnode* tx = NULL;
            try {tx = head->right;}catch (const std::exception&) {tx = NULL;}
            Mnode* ty = NULL;
            while (tx != NULL) {
                if (tx->down != NULL) {
                    ty = tx->down;
                    while (ty != NULL) {
                        stringstream sx; sx << ty->getX();
                        string rx; sx >> rx;
                        stringstream sg; sg << (ty->getX()+1);
                        string rg; sg >> rg;
                        stringstream sy; sy << ty->getY();
                        string ry; sy >> ry;
                        if(ty->getR() < 50 && ty->getG() < 50 && ty->getB() < 50){
                            code = code + "S" + rx +"_"+ ry + "[ label = \"(" + rx +" , "+ ry + ")\" shape = \"square\" fontcolor = \"white\" style = \"filled\" fillcolor =\""+ RGBtoHEXA(ty->getR(), ty->getG(), ty->getB())+"\" ]; \n";
                        }else{
                            code = code + "S" + rx +"_"+ ry + "[ label = \"(" + rx +" , "+ ry + ")\" shape = \"square\" style = \"filled\" fillcolor =\""+ RGBtoHEXA(ty->getR(), ty->getG(), ty->getB())+"\" ]; \n";
                        }
                        ty = ty->down;
                    }
                }
                tx = tx->right;
            }

            try {tx = head->right;}catch (const std::exception&) {tx = NULL;}
            ty = NULL;
            while (tx != NULL) {
                if (tx->down != NULL) {
                    ty = tx->down;
                    stringstream sv; sv << tx->getV();
                    string rv; sv >> rv;
                    while (ty != NULL) {
                        stringstream sx; sx << ty->getX();
                        string rx; sx >> rx;
                        stringstream sy; sy << ty->getY();
                        string ry; sy >> ry;
                        if(ty->down != NULL){
                            code = code + "S" + rx +"_"+ ry + " -> ";
                        }else{
                            code = code + "S" + rx +"_"+ ry;
                        }
                        ty = ty->down;
                    }
                }
                if(tx->right != NULL){
                    code = code + " -> ";
                }else{
                    //NADA
                }
                tx = tx->right;
            }
            return code;
        }

        std::string YlinealGraph(){

            std::string code = "rankdir = LR; graph [nodesep=\"0.8\", ranksep=\"0.6\"]; \n";
            Mnode* tx = NULL;
            try {tx = head->right;}catch (const std::exception&) {tx = NULL;}
            Mnode* ty = NULL;
            while (tx != NULL) {
                if (tx->down != NULL) {
                    ty = tx->down;
                    while (ty != NULL) {
                        stringstream sx; sx << ty->getX();
                        string rx; sx >> rx;
                        stringstream sg; sg << (ty->getX()+1);
                        string rg; sg >> rg;
                        stringstream sy; sy << ty->getY();
                        string ry; sy >> ry;
                        if(ty->getR() < 50 && ty->getG() < 50 && ty->getB() < 50){
                            code = code + "S" + rx +"_"+ ry + "[ label = \"(" + rx +" , "+ ry + ")\" shape = \"square\" fontcolor = \"white\" style = \"filled\" fillcolor =\""+ RGBtoHEXA(ty->getR(), ty->getG(), ty->getB())+"\" ]; \n";
                        }else{
                            code = code + "S" + rx +"_"+ ry + "[ label = \"(" + rx +" , "+ ry + ")\" shape = \"square\" style = \"filled\" fillcolor =\""+ RGBtoHEXA(ty->getR(), ty->getG(), ty->getB())+"\" ]; \n";
                        }
                        ty = ty->down;
                    }
                }
                tx = tx->right;
            }

            ty = NULL;
            try { ty = head->down; }
            catch (const std::exception&) { ty = NULL; }
            tx = NULL;
            while (ty != NULL) {
                if (ty->right != NULL) {
                    tx = ty->right;
                    stringstream sv; sv << ty->getV();
                    string rv; sv >> rv;
                    while (tx != NULL) {
                        stringstream sx; sx << tx->getX();
                        string rx; sx >> rx;
                        stringstream sy; sy << tx->getY();
                        string ry; sy >> ry;
                        if(tx->right != NULL){
                            code = code + "S" + rx +"_"+ ry + " -> ";
                        }else{
                            code = code + "S" + rx +"_"+ ry;
                        }
                        tx = tx->right;
                    }
                }
                if(ty->down != NULL){
                    code = code + " -> ";
                }else{
                    //NADA
                }
                ty = ty->down;
            }

            return code;
        }

        void PrintX() {
            Mnode* tx = NULL;
            //Por si se chinga a la verga XD
            try {tx = head->right;}catch (const std::exception&) {tx = NULL;}
            Mnode* ty = NULL;
            while (tx != NULL) {
                if (tx->down != NULL) {
                    ty = tx->down;
                    cout << "\n";
                    //Por si se chinga a la verga XD
                    try { cout << ty->getX();cout << +" :\t"; }
                    catch (const std::exception&) {}
                    while (ty != NULL) {
                        cout << ty->getR();
                        cout << ",";
                        cout << ty->getG();
                        cout << ",";
                        cout << ty->getB();
                        cout << ",  ";
                        ty = ty->down;
                    }
                }
                tx = tx->right;
            }
        }

        void PrintY() {
            Mnode* ty = NULL;
            //Por si se chinga a la verga XD
            try { ty = head->down; }
            catch (const std::exception&) { ty = NULL; }
            Mnode* tx = NULL;
            while (ty != NULL) {
                if (ty->right != NULL) {
                    tx = ty->right;
                    cout << "\n";
                    //Por si se chinga a la verga XD
                    try { cout << tx->getY(); cout << +" :\t"; }catch (const std::exception&) {}
                    while (tx != NULL) {
                        cout << tx->getR();
                        cout << ",";
                        cout << tx->getG();
                        cout << ",";
                        cout << tx->getB();
                        cout << ",  ";
                        tx = tx->right;
                    }
                }
                ty = ty->down;
            }

        }


        std::string headers = "";
        std::string nodes = "";
        std::string MatrixGraph() {
            headers = ""; nodes = "";
            headers = "graph [nodesep=\"0.8\", ranksep=\"0.6\"]; \n";
            headers = headers + "M0[ label = \"Inicio\" width = 1.5 shape = \"square\" style = \"filled\" fillcolor =\"slateblue\" group = 1]; \n";
            HeadersGraph();
            NodesGraph();
            std::string join = headers + nodes;
            return join;
        }

    private:
        void X(int x) {
            Mnode * current = new Mnode(x);
            if (head->right == NULL) {
                head->right = current;
                current->left = head;
            }else {
                Mnode * temp = head;
                //Sorted insertion while value < x-position
                while (temp->right != NULL && temp->right->getV() < x) {
                    temp = temp->right;
                }
                //At the end
                if (temp->right == NULL) {
                    temp->right = current;
                    current->left = temp;
                }else if(temp->right != NULL && temp->right->getV() != x) {
                //Between nodes
                    Mnode* r = temp->right;
                    temp->right = current;
                    current->left = temp;
                    current->right = r;
                    r->left = current;
                }
            }
        }
        void Y(int y) {
            Mnode * current = new Mnode(y);
            if (head->down == NULL) {
                head->down = current;
                current->up = head;
            }
            else {
                Mnode * temp = head;
                //Sorted insertion while value < y-position
                while (temp->down != NULL && temp->down->getV() < y) {
                    temp = temp->down;
                }
                //At the end
                if (temp->down == NULL) {
                    temp->down = current;
                    current->up = temp;
                }else if (temp->down != NULL && temp->down->getV() != y) {
                    //Between nodes
                    Mnode* r = temp->down;
                    temp->down = current;
                    current->up = temp;
                    current->down = r;
                    r->up = current;
                }
            }
        }
        void addX(Mnode *n, int x, int y) {
            Mnode* temp = head;
            while (temp->getV() != x) {
                temp = temp->right;
            }
            if (temp->down == NULL) {
                temp->down = n;
                n->up = temp;
            }else {
                //Sorted insertion while value < y-position
                while (temp->down != NULL && temp->down->getY() < y) {
                    temp = temp->down;
                }
                //At the end
                if (temp->down == NULL) {
                    temp->down = n;
                    n->up = temp;
                }else if (temp->down != NULL && temp->down->getY() != y) {
                    //Between nodes
                    Mnode* r = temp->down;
                    temp->down = n;
                    n->up = temp;
                    n->down = r;
                    r->up = n;
                }
            }

        }
        void addY(Mnode* n, int x, int y) {
            Mnode* temp = head;
            while (temp->getV() != y) {
                temp = temp->down;
            }
            if (temp->right == NULL) {
                temp->right = n;
                n->up = temp;
            }
            else {
                //Sorted insertion while value < y-position
                while (temp->right != NULL && temp->right->getX() < x) {
                    temp = temp->right;
                }
                //At the end
                if (temp->right == NULL) {
                    temp->right = n;
                    n->up = temp;
                }
                else if (temp->right != NULL && temp->right->getX() != x) {
                    //Between nodes
                    Mnode* r = temp->right;
                    temp->right = n;
                    n->left = temp;
                    n->right = r;
                    r->left = n;
                }
            }
        }

        void NodesGraph(){
            //NODES DECLARATION
            Mnode* tx = NULL;
            try {tx = head->right;}catch (const std::exception&) {tx = NULL;}
            Mnode* ty = NULL;
            while (tx != NULL) {
                if (tx->down != NULL) {
                    ty = tx->down;
                    while (ty != NULL) {
                        nodes = nodes + "S" + std::to_string(ty->getX()) +"_"+ std::to_string(ty->getY()) + "[ label = \"" + std::to_string(ty->getR()) +", " + std::to_string(ty->getG()) +", " + std::to_string(ty->getB()) +"\" width = 1.5 shape = \"square\" style = \"filled\" fillcolor =\"slategray1\" group = " + std::to_string((ty->getX()+1)) +" ]; \n";
                        nodes = nodes + "{rank = same; Y" + std::to_string(ty->getY()) + "; S"+ std::to_string(ty->getX()) +"_"+ std::to_string(ty->getY()) +"; } \n";
                        ty = ty->down;
                    }
                }
                tx = tx->right;
            }

            //NODES X CONECTIONS
            try {tx = head->right;}catch (const std::exception&) {tx = NULL;}
            ty = NULL;
            while (tx != NULL) {
                if (tx->down != NULL) {
                    ty = tx->down;
                    stringstream sv; sv << tx->getV();
                    string rv; sv >> rv;
                    nodes = nodes + "X" + rv +" -> ";
                    while (ty != NULL) {
                        stringstream sx; sx << ty->getX();
                        string rx; sx >> rx;
                        stringstream sy; sy << ty->getY();
                        string ry; sy >> ry;
                        if(ty->down != NULL){
                            nodes = nodes + "S" + rx +"_"+ ry + " -> ";
                        }else{
                            nodes = nodes + "S" + rx +"_"+ ry +" [dir = \"both\"]; \n";
                        }
                        ty = ty->down;
                    }
                }
                tx = tx->right;
            }

            //NODES Y CONECTIONS
            ty = NULL;
            try { ty = head->down; }
            catch (const std::exception&) { ty = NULL; }
            tx = NULL;
            while (ty != NULL) {
                if (ty->right != NULL) {
                    tx = ty->right;
                    stringstream sv; sv << ty->getV();
                    string rv; sv >> rv;
                    nodes = nodes + "Y" + rv +" -> ";
                    while (tx != NULL) {
                        stringstream sx; sx << tx->getX();
                        string rx; sx >> rx;
                        stringstream sy; sy << tx->getY();
                        string ry; sy >> ry;
                        if(tx->right != NULL){
                            nodes = nodes + "S" + rx +"_"+ ry + " -> ";
                        }else{
                            nodes = nodes + "S" + rx +"_"+ ry +"  [dir = \"both\"]; \n";
                        }
                        tx = tx->right;
                    }
                }
                ty = ty->down;
            }

        }

        void HeadersGraph(){
            Mnode* tv = NULL;
            //NODES
            try { tv = head->down; }catch (const std::exception&) { tv = NULL; }
            while (tv != NULL) {
                stringstream s; s << tv->getV();
                string r; s >> r;
                headers = headers + "Y" + r + "[ label = \"Y( " + r + " )\" width = 1.5 shape = \"square\" style = \"filled\" fillcolor =\"skyblue3\" group = 1 ]; \n";
                tv = tv->down;
            }
            try {tv = head->right;}catch (const std::exception&) { tv = NULL;}
            while (tv != NULL) {
                stringstream s; s << tv->getV();
                string r; s >> r;
                stringstream sg; sg << (tv->getV()+1);
                string rg; sg >> rg;
                headers = headers + "X" + r + "[ label = \"X( " + r +" )\" width = 1.5 shape = \"square\" style = \"filled\" fillcolor =\"skyblue3\" group = "+ rg +" ]; \n";
                tv = tv->right;
            }
            //CONECTIONS Y
            try { tv = head->down; }catch (const std::exception&) { tv = NULL; }
            Mnode* tv2;
            headers = headers + "M0 ->";
            while (tv != NULL) {
                stringstream s; s << tv->getV();
                string r; s >> r;
                if(tv->down != NULL){
                    headers = headers + "Y" + r + " -> ";
                }else{
                    headers = headers + "Y" + r + "[dir = \"both\"]; \n";
                    tv2 = tv;
                }
                tv = tv->down;
            }
            //CONECTIONS X
            try { tv = head->right; }catch (const std::exception&) { tv = NULL; }
            headers = headers + "M0 ->";
            std::string rank;
            rank = "{rank = same; M0; ";
            while (tv != NULL) {
                stringstream s; s << tv->getV();
                string r; s >> r;
                if(tv->right != NULL){
                    headers = headers + "X" + r + " -> ";
                }else{
                    headers = headers + "X" + r + "[dir = \"both\"]; \n";
                    tv2 = tv;
                }
                rank = rank + "X" + r + ";";
                tv = tv->right;
            }
            rank = rank +" }";
            headers = headers + rank + "\n";
            rank = "";
        }
}
