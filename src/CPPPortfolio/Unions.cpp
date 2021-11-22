#include <iostream>


/* Unions with floats */
struct Vector2F
{
	float x, y;

};

struct Vector4F
{
	union
	{
		struct
		{
			float x, y, z, w; 
		};
		struct
		{
			Vector2F a, b;
		};
	};

	// To get a vector 2 out of this vector

	// Kinda okay way, creates a whole new copy of data though
	/*Vector2 GetA()
	{
		return Vector2(x, y);
	}*/
	
};

struct Vector6F
{
	union
	{
		struct
		{
			float x, y, z, w, v, t;
		};
		struct
		{
			Vector2F a, b, c; 
		};
	};
};


/* Unions with doubles */
struct Vector2D
{
	double x, y;
};


struct Vector4D
{
	union
	{
		struct
		{
			double x, y, z, w;
		};
		struct
		{
			Vector2D a, b;
		};
	};
};

struct Vector6D
{
	union
	{
		struct
		{
			double x, y, z, w, v, t;
		};
		struct
		{
			Vector2D a, b, c;
		};
	};
};




void PrintVector2(const Vector2F& vector)
{
	std::cout << vector.x << ", " << vector.y << std::endl;
}
void PrintVector2(const Vector2D& vector)
{
	std::cout << vector.x << ", " << vector.y << std::endl;
}


void RunUnionsFile()
{
	std::cout << "Vector4 example" << std::endl;
	Vector4F vector4 = { 1.0f, 2.0f, 3.0f, 4.0f }; 
	PrintVector2(vector4.a); 
	PrintVector2(vector4.b); 
	vector4.z = 200.0f; 
	std::cout << "----------------------------\n";  
	PrintVector2(vector4.a); 
	PrintVector2(vector4.b); 
	 

	std::cout << "Vector6 example" << std::endl;
	Vector6F vector6 = { 1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f }; 
	PrintVector2(vector6.a);
	PrintVector2(vector6.b);
	PrintVector2(vector6.c);


	std::cout << "\nVector4D example" << std::endl;
	Vector4D vector4D = { 1.0f, 2.0f, 3.0f, 4.0f };
	PrintVector2(vector4D.a);
	PrintVector2(vector4D.b);
	vector4.z = 200.0f;
	std::cout << "----------------------------\n";
	PrintVector2(vector4D.a);
	PrintVector2(vector4D.b);


	std::cout << "Vector6D example" << std::endl;
	Vector6D vector6D = { 1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f };
	PrintVector2(vector6D.a);
	PrintVector2(vector6D.b);
	PrintVector2(vector6D.c);
}
