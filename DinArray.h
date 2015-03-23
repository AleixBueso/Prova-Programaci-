#include <iostream>
#include <assert.h>

class DinArray
{
private:
	int* data;
	unsigned int memo_size;
	unsigned int item_num;

public:
	DinArray(){ memo_size = 0; item_num = 0; data = NULL; }
	DinArray(int capacity){ memo_size = capacity; item_num = 0; data = NULL; }
	~DinArray(){ delete[] data; }
	void operator[](unsigned int index)
	{
		assert(index < item_num);
		return data[index];
	}
	void PushBack(const int element)
	{
		if (item_num >= memo_size)
		{
			Alloc(memo_size + 16);
		}
		data[item_num++] = element;
	}
	bool Pop(int value)
	{
		if (item_num > 0)
		{
			value = data[--item_num];
			return true;
		}
		return false;
	}
	void Clear(){ item_num = 0; }
	bool Insert(const int element, unsigned int position)
	{
		if (position > item_num)
			return false;
		if (position==item_num)
		{
			PushBack(element);
			return true;
		}
		if (item_num + 1 > memo_size)
			Alloc(memo_size + 16);
		for (unsigned int i = item_num; i > position; --i)
		{
			data[i] = data[i - 1];
		}
		data[position] = element;
		++item_num;
		return true;
	}
	int* At(unsigned int index)
	{
		int* result = NULL;
		if (index < item_num)
			return result = &data[index];
		return result;

	}
	const int* At(unsigned int index) const
	{
		int* result = NULL;
		if (index < item_num)
			return result = &data[index];
		return result;
	}
	unsigned int GetCapacity() const
	{
		return memo_size;
	}
	unsigned int Count() const
	{
		return item_num;
	}
private:
	void Alloc(unsigned int memo)
	{
		int* tmp = data;
		memo_size = memo;
		data = new int[memo_size];
		
		if (item_num > memo_size)
			item_num = memo_size;
		if (tmp != NULL)
		{
			for (unsigned int i = 0; i < item_num; i++)
				data[i] = tmp[i];
			delete[] tmp;
		}
	}
};