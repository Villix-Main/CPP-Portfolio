#include <iostream>



template <typename T>
class NumCollection
{
private:
	uint32_t m_Size;
	T* m_Data;

public:
	NumCollection() = default;
	NumCollection(const T* nums, uint32_t size) 
	{
		printf("Created the number collection\n"); 

		m_Size = size;
		m_Data = new T[m_Size];
		memmove(m_Data, nums, size * sizeof(T)); 
	}

	NumCollection(const NumCollection& other)
	{
		printf("Copied\n");
		m_Size = other.m_Size;
		m_Data = new T[m_Size];
		memmove(m_Data, other.m_Data, m_Size * sizeof(T));
	}

	NumCollection(NumCollection&& other) noexcept
	{
		printf("Moved!\n");
		m_Size = other.m_Size;
		m_Data = other.m_Data;

		other.m_Size = 0;
		other.m_Data = nullptr;
	}

	NumCollection& operator=(NumCollection&& other) noexcept
	{
		printf("Moved!\n");

		if (this == &other)
		{
			printf("Could not do shit!\n");
			return *this;
		}

		delete[] m_Data;

		m_Size = other.m_Size;
		m_Data = other.m_Data;

		other.m_Size = 0;
		other.m_Data = nullptr;
	}

	void PrintAll()
	{
		for (size_t i=0; i < m_Size; i++)
		{
			std::cout << "Item " << i << ": " << *(m_Data + i) << std::endl;
		}
	}

	~NumCollection()
	{
		printf("Destroyed!\n");
		delete m_Data;
	}

};

class SchoolModel
{
private:
	NumCollection<int> m_RoomNumbers;

public:
	SchoolModel(NumCollection<int>&& roomNumbers) 
		: m_RoomNumbers(std::move(roomNumbers))
	{
		printf("Created");
	}
};


void PrintNameLen(const std::string& name)
{
	std::cout << "[lvalue]: " << name.length() << std::endl; 
}


void PrintNameLem(std::string&& name)
{
	name = "Josh";
	std::cout << "[rvalue]: " << name.length() << std::endl; 
}

void SetVal(int& val)
{
	val = 50;
}



void RunMoveSemanticsFile()
{
	std::string name = "Dominic";
	std::string address = "some address";
	
	PrintNameLen(name);
	PrintNameLen("Dominic"); 

	SchoolModel model(NumCollection<int>(new int[] {3, 3, 3}, 3));

	NumCollection<int> collection(new int[] {3, 21, 2}, 3);
	NumCollection<int> movItem(std::move(collection)); 

	movItem = std::move(movItem);
	//movItem = NumCollection(new int[] {12, 34, 15, 53}, 4);


	//NumCollection<int> data(new int[] {1, 2, 3, 4, 5, 6}, 6);
	//NumCollection<int> moveData;
	//
	//std::cout << "Original data collection\n";
	//data.PrintAll();

	//moveData = std::move(data);

	//std::cout << "Original data collection\n";
	//data.PrintAll(); // Won't print anything because all it's contents have been moved
	//std::cout << "Moved data\n";
	//moveData.PrintAll();
	
}



