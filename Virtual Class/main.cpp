class onlineshooping
{
public:
    int price;
    onlineshooping() // constructor
    {
        price = 10;
    }
    void show()
    {
        cout<<"\nWelcome to ONLINE SHOOPING";
    }
};

class firstcry : public virtual onlineshooping
{
    /*all public member of class onlineshooping will be accessible here*/
};

class hopscotch : public virtual onlineshooping
{
    /*all public member of class onlineshooping will be accessible here*/
};

class customer : public firstcry, public hopscotch
{
    /*here if NOT used virtual class there would aries a ambiguity to which data/function member would be called? One inherited through B or the other inherited through C. This confuses compiler and it displays error.*/


};

class A {
public:
    int a;
    A() // constructor
    {
        a = 10;
    }
};

class B : public virtual A {
};

class C : public virtual A {
};

class D : public B, public C {
};

int main()
{
    customer amogh;
    amogh.show(); /*due to usage of virtual class there will not be any ambiguity from customer class*/
    cout << "Price = " << amogh.price << endl;
    D object; // object creation of class d
    cout << "a = " << object.a << endl;
    return 0;
}

