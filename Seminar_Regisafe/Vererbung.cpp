#include <iostream>

// Java // C#
//interface IShape
//{
//    public virtual void paint();
//};

// C++ interface  // poor man's C++ interface
class IShape
{
public:
    virtual void paint() = 0;  // abstract
};

// THIS IS SHITTY / DON'T DO THAT
// void IShape::paint() {}

// Shape ist abtrakt:
// Shape ist eine unvollständige Klasse,
// stellt aber grundlegende Realisierungen für alle abgel. Klassen bereit !!!
class Shape : public IShape
{
public:
    //virtual void paint()
    //{
    //    std::cout << "paint of Shape" << std::endl;
    //}

protected:
    // Entwurfsentscheidung: don't override me !!!
    void clearBackground()
    {
        std::cout << "clearBackground" << std::endl;
    }
};

class Rectangle : public Shape  // ist-ein Beziegung  // is-a 
{
public:
    void paint() override
    {
        clearBackground();
        //Shape::paint();
        std::cout << "paint of Rectangle" << std::endl;
    }
};

class BlackAndWhiteRectangle : public Shape  // ist-ein Beziegung  // is-a 
{
public:
    void paint() override
    {
        clearBackground();
        //Shape::paint();
        std::cout << "paint of BlackAndWhiteRectangle" << std::endl;
    }
};

void testVererbungZWEI()
{
    // Shape s;  // Shape is abstract

    Rectangle rect1;
    Rectangle rect2;
    BlackAndWhiteRectangle bwrect1;
    BlackAndWhiteRectangle bwrect2;

    IShape* shapes[] = { &rect1, &bwrect1, &rect2, &bwrect2 };

    // obj.size(); Es existiert hier genau EINE Methode

    // for_each // range based loop
    for (IShape* sp : shapes) 
    {
        sp->paint();  // ist NICHT erkennbar, WELCHE Methode aufgerufen wird 
                      // es wird genau die Methode aufgerufen des Objekts, das vorliegt
                      // Polymorphismus
    }

    // NICHT !!!!!!!!!!!!!!!!!!!!!
    //for (Shape* sp : shapes)
    //{
    //    if (sp.isTypeOf() == Rectangle) {
    //        sp->paintVonRectangle();
    //    }
    //    else if (sp.isTypeOf() == BlackAndWhiteRectangle) {
    //        sp->paintVonBlackAndWhiteRectangle();
    //    }
    //}


}

void testVererbung()
{
    Rectangle rect;
    Shape& shape = rect;
    shape.paint();
}