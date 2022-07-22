#include<string>
#include<iostream>

class Ansi {
  public:
    std::string reset(){
        return "\u001b[0m";
    };
};

class Ansi16 : public Ansi {
  public:
    std::string foreground(const int color){
        return (
           "\u001b[3"+
           std::to_string(color)+
           "m"
        );
    };
    std::string background(const int color){
        return (
           "\u001b[3"+
           std::to_string(color)+
           "m"
        );
    };
    std::string text(const int color, std::string text_in, const int back_color){
        return (
            this->foreground(color)+
            this->background(color)+
            text_in+
            this->reset()
        );
    };
    void test(){
        std::string out = "\n";
        for(int i = 0 ; 8 > i ; i++)
            out += this->text(i,std::to_string(i),0);
        out += "\n";
        for(int i = 0 ; 8 > i ; i++)
            out += this->text(0," ",i);
        out += "\n";
        std::cout << out << std::endl;

    }
};

class Ansi255 : public Ansi {
  public:
    std::string foreground(const int color){
        return (
           "\u001b[38;5;"+
           std::to_string(color)+
           "m"
        );
    };
    std::string background(const int color){
        return (
           "\u001b[48"+
           std::to_string(color)+
           "m"
        );
    };
    std::string text(const int color, std::string text, const int back_color){
        return (
            this->foreground(color)+
            this->background(color)+
            text+
            this->reset()
        );
    };
    void test(){
        std::string out = "\n";
        int a = 0;
        for(int i = 0 ; 16 > i ; i++)
            out += this->text(i,"0",0);
        out += "\n";
        for(int i = 16 ; 232 > i ; i++){
            out += this->text(i,"0",0);
            if(a == 35){
                out += "\n";
                a = 0;
            }else 
                a++;
        }
        out += "\n";
        for(int i = 232 ; 256 > i ; i++)
            out += this->text(i,"0",0);
        out += "\n";
        for(int i = 0 ; 16 > i ; i++)
            out += this->text(0,"0",i);
        out += "\n";
        for(int i = 16 ; 232 > i ; i++){
            out += this->text(0,"0",i);
            if(a == 35){
                out += "\n";
                a = 0;
            }else 
                a++;
        }
        out += "\n";
        for(int i = 232 ; 256 > i ; i++)
            out += this->text(0,"0",i);
        std::cout << out << std::endl;

    };
};

class Ansi24Bit : public Ansi {
  public:
    std::string foreground(
        const int red,
        const int green,
        const int blue
    ){
        return (
            "\u001b[38;2;"+
            std::to_string(red)+
            ";"+
            std::to_string(green)+
            ";"+
            std::to_string(blue)+
            "m"
        );
    };
    std::string background(
        const int red,
        const int green,
        const int blue
    ){
        return (
            "\u001b[48;2;"+
            std::to_string(red)+
            ";"+
            std::to_string(green)+
            ";"+
            std::to_string(blue)+
           "m"
        );
    };
    std::string text(
        const int red, 
        const int green, 
        const int blue, 
        std::string text,
        const int back_red,
        const int back_green,
        const int back_blue
    ){
        return (
            this->foreground(red,green,blue)+
            this->background(back_red,back_green,back_blue)+
            text+
            this->reset()
        );
    };
    void test(){
        std::string out = "\n";
        for(int i = 0 ; 256 > i ; i++)
            out += this->text(i,0,0,"0",0,0,0);
        out += "\n";
        for(int i = 0 ; 256 > i ; i++)
            out += this->text(0,i,0,"0",0,0,0);
        out += "\n";
        for(int i = 0 ; 256 > i ; i++)
            out += this->text(0,0,i,"0",0,0,0);
        out += "\n";
        for(int i = 0 ; 256 > i ; i++)
            out += this->text(i,i,i,"0",0,0,0);
        out += "\n";
        for(int i = 0 ; 256 > i ; i ++)
            out += this->text(0,0,0," ",i,0,0);
        out += "\n";
        for(int i = 0 ; 256 > i ; i ++)
            out += this->text(0,0,0," ",0,i,0);
        out += "\n";
        for(int i = 0 ; 256 > i ; i ++)
            out += this->text(0,0,0," ",0,0,i);
        out += "\n";
        for(int i = 0 ; 256 > i ; i++)
            out += this->text(0,0,0," ",i,i,i);
        out += "\n";
        std::cout << out << std::endl;

    };
};

int main(int argc, char *argv[]){
    Ansi16 *ansi16 = new Ansi16();
    Ansi255 *ansi255 = new Ansi255();
    Ansi24Bit *ansi24bit = new Ansi24Bit();
    ansi16->test();
    ansi255->test();
    ansi24bit->test();
};
