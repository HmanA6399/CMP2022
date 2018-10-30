#pragma once
class Carpet
{
	float const width = 0.0;
	float const length = 0.0;
	float price = 0.0;
	float salesPercentage = 0;
	bool inStock = true;
public:
	Carpet(float w, float l, float p, float sales_pctg, bool in_stck);
	Carpet();
	void setPrice(float p);
	void setSalesPctg(float pctg);
	void setInStock(bool t);
	float getWidth();
	float getLength();
	float getPrice();
	float getSalesPctg();
	bool getInStock();
	float getArea();
	float priceAfterSale();
	Carpet compareCarpet(Carpet C);
	void printInfo();
	~Carpet();
};

