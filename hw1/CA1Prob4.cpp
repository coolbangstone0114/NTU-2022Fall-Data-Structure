/**
 * The class of flower that takes three member variables" name, petal, and price"
 *
 * @author 趙新元 CHAO,SIN-YUAN
 * @ID B10505057
 * @Department Engineering Science and Ocean Engineering
 * @Affiliation National Taiwan University
 */
#include <iostream>
class flower
{
private:
    std::string name;
    int petal;
    double price;

public:
    // Constructor, used to initialize the three variables "name", "petal", and "price".
    flower(std::string n, int pt, double pe)
    {
        setName(n);
        setPetal(pt);
        setPrice(pe);
    }
    // Set the name of the flower.
    void setName(std::string n)
    {
        name = n;
    }
    // Set the petal number of the flower.
    void setPetal(int pl)
    {
        if (pl > 0)
        {
            petal = pl;
        }
    }
    // Set the price of the flower.
    void setPrice(double pe)
    {
        if (pe >= 0)
        {
            price = pe;
        }
    }
    // Return the name of the flower.
    std::string getName()
    {
        return name;
    }
    // Return the petal number of the flowe r.
    int getPetal()
    {
        return petal;
    }
    // Return the price of the flower.
    double getPrice()
    {
        return price;
    }
};
/*
int main(void)
{
    std::string name,a;
    int petal,b;
    double price,c;
    std::cin >> name >> petal >> price;
    flower flower1(name, petal, price);
    a = flower1.getName();
    b = flower1.getPetal();
    c = flower1.getPrice();
    std::cout<<"name of flower: "<<a<<"\n";
    std::cout<<"number of petals: "<<b<<"\n";
    std::cout<<"Price of the flower: "<<c<<"\n";
}
//NoddingTrillium 3 75.0
*/