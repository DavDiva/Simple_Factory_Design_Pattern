#include <iostream>
#include<string>
using namespace std;

//Simple Factory Design Pattern

class Pizza//The product class that has useful methods that can be overridden in the derived classes(like an interface but with opportunity to create an instance of this class)
{public:
    /*Pizza()
    {
        cout << "Pizza const called" << endl; //There are constructors in the programm that can be uncommented to track calling of the constructors
    }*/
    virtual void prepare()
    {
        cout << "any Pizza is being prepared" << endl;
    }
    virtual void bake()
    {
        cout << "any Pizza is being baked" << endl;
    }
    virtual void cut()
    {
        cout << "any Pizza is being cut" << endl;
    }
    virtual void box()
    {
        cout << "any Pizza is being put into the box" << endl;
    }
};

class CheesePizza: public Pizza//Should override all the methods of Pizza class
{
public:
    /*CheesePizza()
    {
        cout << "Chesse Pizza const called" << endl;
    }*/
    void prepare()override
    {
        cout << "chesse Pizza is being prepared" << endl;
    }
    void bake()override
    {
        cout << "chesse Pizza is being baked" << endl;
    }
    void cut()override
    {
        cout << "chesse Pizza is being cut" << endl;
    }
    void box()override
    {
         cout << "chesse Pizza is being put into the box" << endl;
    }

};

class VeggiPizza : public Pizza//Should override all the methods of Pizza class
{
public:
   /* VeggiPizza()
    {
        cout << "Veggi Pizza const called" << endl;
    }*/
    void prepare()override
    {
        cout << "veggi Pizza is being prepared" << endl;
    }
    void bake()override
    {
        cout << "veggi  Pizza is being baked" << endl;
    }
    void cut()override
    {
        cout << "veggi  Pizza is being cut" << endl;
    }
    void box()override
    {
        cout << "veggi Pizza is being put into the box" << endl;
    }

};

class SalamiPizza : public Pizza//Should override all the methods of Pizza class
{
public:
    /*SalamiPizza()
    {
        cout << "Salami Pizza const called" << endl;
    }*/
    void prepare()override
    {
        cout << "salami Pizza is being prepared" << endl;
    }
    void bake()override
    {
        cout << "salami   Pizza is being baked" << endl;
    }
    void cut()override
    {
        cout << "salami   Pizza is being cut" << endl;
    }
    void box()override
    {
        cout << "salami  Pizza is being put into the box" << endl;
    }

};

class SimplePizzaFactory//Has method createPizza() that creates an instance of a derived from Pizza classes depending on the given arguments
                        //SimplePizzaFactory should be the only class that works with derived from Pizza classes
{public:
    /*SimplePizzaFactory()
    {
        cout << "SimplePizzaFactory const called" << endl;
    }*/
    Pizza *createPizza(string type)
    {
        Pizza* pizza = nullptr;

        if (type == "cheese")
        {
           pizza = new CheesePizza();
        }
        else if (type == "veggi")
        {
            pizza = new VeggiPizza();
        }
        else if (type == "salami")
        {
            pizza = new SalamiPizza();
        }
        return pizza;
    }


};

class PizzaStore//The client of the Factory, ask SimplePizzaFactory to get instances of the needed class, doesn`t know details of their implementation
{
private:
    SimplePizzaFactory factory;
    Pizza* pizza;
public:
    PizzaStore(SimplePizzaFactory factory)
    {
        /*cout << "PizzaStore const called" << endl;*/
        this->factory = factory;
    }

    Pizza * orderPizza(string type)
    {
       
        pizza = factory.createPizza(type);
        pizza->prepare();
        pizza->bake();
        pizza->cut();
        pizza->box();
        return pizza;
    }

    ~PizzaStore()
    {
        /*cout << "Destructor called" << endl;*/
        delete pizza;
    }
};





int main()
{
    SimplePizzaFactory factory;
    PizzaStore order1(factory);
    order1.orderPizza("veggi");


    return 0;
}


