#include <iostream>

using namespace std;
class GeoShop{
    protected:
    float d1;
    float d2;
    public:
        GeoShop(){
            d1 =0;
            d2=0;
        }
        GeoShop(float d1 ,float d2){
            this ->d1 = d1;
            this ->d2 = d2;
        }

        GeoShop(float d1 ){
            this->d1 = d2 =d1;
        }
        void setD1(float d1){
            this->d1=d1;
        }
        void setD2(float d2){
            this->d2=d2;
        }
        float getD1(){
        return d1;
        }
        float getD2(){
        return d2;
        }
        virtual float calArea()=0;
        virtual ~GeoShop() {}
};
class Circle :private GeoShop{
    protected:
        float radius;
    public:
        Circle():GeoShop(){
            radius=0;
        }
        Circle(float raduis):GeoShop(raduis){
            this ->radius=raduis;
        }
        void setRedius(float radius){
            this->radius = d1=d2= radius;
        }
        float getRedius(){
            return d1;
        }
        float calArea(){
            return 22.0/7 * d1*d2;
        }
};
class Rectangle :public GeoShop{
    public:
        Rectangle():GeoShop(){}
        Rectangle(float x):GeoShop(x){}
        Rectangle(float x ,float y):GeoShop(x,y){
        }
        float calArea(){
            return d1 * d2;
        }
};
class Square :private Rectangle{
    public:
        Square():Rectangle(){
        }
        Square(float side):Rectangle(side,side){}
        void setSide(float side){
            d1 = d2 =side;
        }
        float getSide(){
            return d1;
        }
        float calArea(){
            return d1*d2;
        }
};
class Triangle :public GeoShop{
    public:
        Triangle():GeoShop(){}
        Triangle(float base ,float height):GeoShop(base,height){}
        float calArea(){
            return 0.5 * d1 * d2;
        }
};

void print(){
    cout<<"-------------------------------"<<endl;
}
int main()
{
    Circle c(5);
    cout << "Circle radius: " << c.getRedius() << endl;
    cout << "Circle area: " << c.calArea() << endl;
    print();

    Rectangle r(4, 5);
    cout << "Rectangle area: " << r.calArea() << endl;
    print();

    Square s(4);
    cout << "Square side: " << s.getSide() << endl;
    cout << "Square area: " << s.calArea() << endl;
    print();
    
    Triangle t(3, 6);
    cout << "Triangle area: " << t.calArea() << endl;

    return 0;
}
