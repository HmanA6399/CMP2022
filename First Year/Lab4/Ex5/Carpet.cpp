#include "pch.h"
#include <iostream>
#include "Carpet.h"
using namespace std;

bool Response(int, Carpet*&);

int main()
{
	Carpet* *Products;
	int size; cin >> size;
	Products = new Carpet*[size]; //Array of pointer-to-classes 

	printf("\nWelcome to your e-Market!\n");
	
	bool again = false; int choice;
	for (int i = 0; i < size; ++i) {
		printf("Carpet %d:-\n", i + 1);
		Response(0, Products[i]); //Instantiation
		Products[i]->printInfo();
		cout << Products[i]->getArea() << endl;
		do {
			printf("How can I help you ?\n");
			printf("1- Get Area\t2- Get Price\t3-Mark as sold\n");
			printf("Please choose one of the those >>> ");
			cin >> choice;
			if (!Response(choice, Products[i])) continue; //re-request if the user entered wrong entry
			printf("Any more help ? any key for yes, 0 for no >> ");
			cin >> again;
			printf("\n");
		} while (again);
	}
	
	printf("Sold Carpets:\n");
	for (int i = 0; i < size; ++i) {
		if (!(Products[i]->getInStock())) Products[i]->printInfo();
	}

	return 0;
}

Carpet::Carpet(float w, float l, float p, float sales_pctg, bool in_stck) : width(w), length(l)
{
	this->setPrice(p); 
	this->setSalesPctg(sales_pctg);
	this->setInStock(in_stck);
}

Carpet::Carpet()
{
}

void Carpet::setPrice(float p)
{
	this->price = (p >= 0) ? p : this->price;
}

void Carpet::setSalesPctg(float pctg)
{
	if (pctg >= 0 && pctg <= 100)
		this->salesPercentage = pctg;
}

void Carpet::setInStock(bool t)
{
	this->inStock = t;
}

float Carpet::getWidth() 
{
	return this->width;
}

float Carpet::getLength()
{
	return this->length;
}

float Carpet::getPrice()
{
	return this->price;
}

float Carpet::getSalesPctg()
{
	return this->salesPercentage;
}

bool Carpet::getInStock()
{
	return this->inStock;
}

float Carpet::getArea()
{
	return this->getLength() * this->getWidth();
}

float Carpet::priceAfterSale()
{
	return ((this->getPrice()-this->getSalesPctg())/100) * this->getPrice();
}

Carpet Carpet::compareCarpet(Carpet C) 
{
	if (C.getArea() > this->getArea()) return C;
	else return *this;
}

void Carpet::printInfo()
{
	printf("\nOne of our products\n");
	printf("Width = %0.2f, Length = %0.2f\n", this->getWidth(), this->getLength());
	printf("Only \$%0.2f\n", this->getPrice());
	printf("Discount %0.2f\%\n", this->getSalesPctg());
	printf("The product is %s\n", this->getInStock() ? "Available" : "Sold");
}
Carpet::~Carpet() {}

bool Response(int req, Carpet*& prod) {
	switch (req) {
	case 0: //defining and instantiating values for an object
		float w, l, pr, pctg;
		printf("Please Enter Width: ");
		cin >> w;
		printf("\nPlease Enter Length: ");
		cin >> l;
		printf("\nPlease Enter Price: ");
		cin >> pr;
		printf("\nPlease Enter Sales Percentage: ");
		cin >> pctg;
		prod = new Carpet(w, l, pr, pctg, true);
		break;
	case 1: //getting area
		printf("Area = %0.2f\n", prod->getArea());
		break;
	case 2: //getting price
		printf("Price after Sale = %0.2f\n", prod->priceAfterSale());
		break;
	case 3: //Marking product as sold
		if (prod->getInStock() == false) printf("Product already sold");
		else prod->setInStock(false);
		break;
	default: printf("Please enter valid value");
		return false;
		break;
	}
	return true;
}