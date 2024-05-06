
namespace lasd
{
	template <typename Data>
	inline Vector<Data>::Vector(const unsigned long n)
	{
		elements = new Data[n]{};
		size = n;
	}

	template <typename Data>
	Vector<Data>::Vector(const TraversableContainer<Data> &con) : Vector(con.Size())
	{
		unsigned long index = 0;
		con.Traverse(
			[this, &index](const Data &data)
			{
				elements[index] = data;
				index++;
			});
	}

	template <typename Data>
	Vector<Data>::Vector(MappableContainer<Data> &&con) : Vector(con.Size())
	{
		unsigned long index = 0;
		con.Map(
			[this, &index](Data &data)
			{
				elements[index] = std::move(data);
				index++;
			});
	}

	template <typename Data>
	Vector<Data>::Vector(const Vector<Data> &vec)
	{
		elements = new Data[vec.size];
		std::copy(vec.elements, vec.elements + vec.size, elements);
		size = vec.size;
	}

	template <typename Data>
	Vector<Data>::Vector(Vector<Data> &&vec) noexcept
	{
		std::swap(size, vec.size);
		std::swap(elements, vec.elements);
	}

	template <typename Data>
	Vector<Data>::~Vector()
	{
		delete[] elements;
	}

	template <typename Data>
	Vector<Data> &Vector<Data>::operator=(const Vector<Data> &vec)
	{
		Vector<Data> *tmpvec = new Vector<Data>(vec);
		std::swap(*tmpvec, *this);
		delete tmpvec;
		return *this;
	}

	template <typename Data>
	Vector<Data> &lasd::Vector<Data>::operator=(Vector<Data> &&vec) noexcept
	{
		std::swap(elements, vec.elements);
		std::swap(size, vec.size);
		return *this;
	}

	template <typename Data>
	bool Vector<Data>::operator==(const Vector<Data> &vec) const noexcept
	{
		if (size == vec.size)
		{
			for (unsigned int index = 0; index < size; index++)
			{
				if (elements[index] != vec.elements[index])
				{
					return false;
				}
			}
			return true;
		}
		else
		{
			return false;
		}
	}

	template <typename Data>
	inline bool Vector<Data>::operator!=(const Vector<Data> &vec) const noexcept
	{
		return !(*this == vec);
	}

	template <typename Data>
	void Vector<Data>::Clear() noexcept
	{
		delete[] elements;
		elements = nullptr;
		size = 0;
	}

	template <typename Data>
	void lasd::Vector<Data>::Resize(const unsigned long newsize) noexcept
	{
		if (newsize == 0)
		{
			Clear();
		}
		else if (size != newsize)
		{
			unsigned long limit;
			limit = (size < newsize) ? size : newsize;

			Data *TmpElements = new Data[newsize]{};

			for (unsigned long index = 0; index < limit; index++)
			{
				std::swap(elements[index], TmpElements[index]);
			}

			std::swap(elements, TmpElements);
			size = newsize;
			delete[] TmpElements;
		}
	}

	template <typename Data>
	const Data &lasd::Vector<Data>::operator[](const unsigned long index) const
	{
		if (index < size)
		{
			return elements[index];
		}
		else
		{
			throw std::out_of_range("Position inaccessible: " + std::to_string(index) + " in a vector of " + std::to_string(size));
		}
	}

	template <typename Data>
	Data &Vector<Data>::operator[](const unsigned long index)
	{
		if (index < size)
		{
			return elements[index];
		}
		else
		{
			throw std::out_of_range("Position inaccessible: " + std::to_string(index) + " in a vector of " + std::to_string(size));
		}
	}

	template <typename Data>
	const Data &Vector<Data>::Front() const
	{
		if (size != 0)
		{
			return elements[0];
		}
		else
		{
			throw std::length_error("Front position inaccessible: vector is empty");
		}
	}

	template <typename Data>
	Data &Vector<Data>::Front()
	{
		if (size != 0)
		{
			return elements[0];
		}
		else
		{
			throw std::length_error("Front position inaccessible: vector is empty");
		}
	}

	template <typename Data>
	const Data &Vector<Data>::Back() const
	{
		if (size != 0)
		{
			return elements[size - 1];
		}
		else
		{
			throw std::length_error("Back position inaccessible: vector is empty");
		}
	}

	template <typename Data>
	Data &Vector<Data>::Back()
	{
		if (size != 0)
		{
			return elements[size - 1];
		}
		else
		{
			throw std::length_error("Back position inaccessible: vector is empty");
		}
	}

	template <typename Data>
	inline SortableVector<Data>::SortableVector(const unsigned long n)
	{
		std::cout << "SortableVec Constructor Long" << std::endl;
		elements = new Data[n]{};
		size = n;
	}

	template <typename Data>
	SortableVector<Data>::SortableVector(const TraversableContainer<Data> &con) : SortableVector(con.Size())
	{
		unsigned long index = 0;
		con.Traverse(
			[this, &index](const Data &data)
			{
				elements[index] = data;
				index++;
			});
	}

	template <typename Data>
	SortableVector<Data>::SortableVector(MappableContainer<Data> &&con) : SortableVector(con.Size())
	{
		unsigned long index = 0;
		con.Map(
			[this, &index](Data &data)
			{
				elements[index] = std::move(data);
				index++;
			});
	}

	template <typename Data>
	SortableVector<Data>::SortableVector(const SortableVector<Data> &vec)
	{
		size = vec.size;
		elements = new Data[vec.size];
		std::copy(vec.elements, vec.elements + vec.size, elements);
	}

	template <typename Data>
	SortableVector<Data>::SortableVector(SortableVector<Data> &&vec) noexcept
	{
		std::swap(size, vec.size);
		std::swap(elements, vec.elements);
	}

	template <typename Data>
	SortableVector<Data> &SortableVector<Data>::operator=(const SortableVector<Data> &vec)
	{
		Vector<Data>::operator=(vec);
		return *this;
	}

	template <typename Data>
	SortableVector<Data> &SortableVector<Data>::operator=(SortableVector<Data> &&vec) noexcept
	{
		Vector<Data>::operator=(std::move(vec));
		return *this;
	}
}