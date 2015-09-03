#ifndef UTILSTRUCTURES_H
#define UTILSTRUCTURES_H

// Structure to hold up to three dimensions
struct Dimensions{
	public:
		Dimensions();
		Dimensions(int i);
		Dimensions(int i, int j);
		Dimensions(int i, int j, int k);
		Dimensions(const Dimensions &source);
		~Dimensions();

		Dimensions& operator= (const Dimensions &source);

		static const int NO_DIM = -1;

		int x, y, z;
};

#endif
