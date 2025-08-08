#include <iostream>
#include <cassert>

class IntArray
{
private:
	int* m_data{ nullptr };
	int m_length{};

public:
	IntArray() = default;

	IntArray(int length)
		: m_length(length)
	{
		assert(m_length > 0);
		if (length > 0)
		{
			m_data = new int[static_cast<std::size_t>(length)];
			
		}
	}

	//constructor de copias de operador de asignacion
	IntArray(const IntArray& copy)
	{
		copy_deep(copy);
	}

	IntArray& operator=(const IntArray& right)
	{
		if (this == &right)
		{
			return *this; // self-assignment, do nothing
		}

		copy_deep(right);
		return *this;
	}

	~IntArray()
	{
		delete[] m_data;
	}

	int& operator[](int index)
	{
		return m_data[index];
	}

	void erase()
	{
		delete[] m_data;
		m_data = nullptr;
		m_length = 0;
	}

	void copy_deep(const IntArray& copy)
	{
		delete[] m_data; // Clean up existing data
		if (copy.m_data)
		{
			m_length = copy.m_length;
			m_data = new int[static_cast<std::size_t>(m_length)];
			for (std::size_t i{ 0 }; i < m_length; ++i)
			{
				m_data[i] = copy.m_data[i];
			}
		}
		else
		{
			m_data = nullptr;
			m_length = 0;
		}
	}

	int getLength() const
	{
		return m_length;
	}

};

int	main()
{
	IntArray arr{ 5 };

	IntArray arr1{ arr }; // copy constructor

	std::cout << "arr1 length: " << arr1.getLength() << '\n';

	arr1[0] = 10;
	std::cout << "arr[0]: " << arr[0] << '\n';
	std::cout << "arr1[0]: " << arr1[0] << '\n';

	return 0;
}