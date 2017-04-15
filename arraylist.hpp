//Dennis Hahn CS1510 1B Homework #2

#include <iostream>
#include <string>
using namespace std; 

template <typename T>
void ArrayList<T>::insert(const T& x, int i)
{	
	if (m_max == 0)
	{
		m_data = new T[2];
		m_max = 2;
	}
	
	if (i >= 0 && i <= m_size)
	{
		if (m_size == m_max) 
		{
			T* tmp = new T[m_max * 2];
			m_max = m_max * 2;

			for (int k = 0; k < m_size; k++)
			{
				tmp[k] = m_data[k];
			}

			delete [] m_data;

			m_data = tmp;
		}

		for (int k = m_size; k > i; k--)
		{
			m_data[k] = m_data[k - 1];
		}

	

		m_data[i] = x;
		m_size++;
	}
	else
	{
		cout << "!-- ERROR : PANIC in ARRAYLIST!!.insert()  "; 
		cout << "(index out of bounds)" << endl;
	}
}

template <typename T>
void ArrayList<T>::insert_back(const T& x)
{
	insert(x, m_size);
}

template <typename T>
const T& ArrayList<T>::first() const 
{
	if (m_size > 0)
		return m_data[0];
	else if (m_size == 0)
	{
		cout << "!-- ERROR : PANIC in ARRAYLIST.first()!!  (List is empty)" << endl;
		return m_errobj;
	}

}

template <typename T>
void ArrayList<T>::remove(int i)  
{
	if (i >= 0 && i <= m_size)
	{
		if (m_size <= m_max/4)
		{
			T* tmp = new T[m_max / 2];
			m_max = m_max / 2;

			for (int k = 0; k < m_size; k++)
			{
				tmp[k] = m_data[k];
			}

			delete [] m_data;

			m_data = tmp;
		}
	
	
		for (int k = i; k < m_size - 1; k++)
		{
			m_data[k] = m_data[k + 1];
		}

		m_size--;
	}
	else
	{
	cout << "!-- ERROR : PANIC in ARRAYLIST!!.remove()  (index out of bounds)";
	cout << endl;
	}

}

template <typename T>
int ArrayList<T>::size() const
{
	return m_size;
}

template <typename T>
ArrayList<T>::~ArrayList()
{
	delete [] m_data;
}

template <typename T>
T& ArrayList<T>::operator[](int i)
{
	if (i >= 0 && i <= m_size)
		return m_data[i];
	else 
	{
		cout << "!-- ERROR : PANIC in ARRAYLIST!!.[]  (index out of bounds)";
		cout << endl;
		return m_errobj;
	}

}

template <typename T>
const T& ArrayList<T>::operator[](int i) const
{
	if (i >= 0 && i <= m_size)
		return m_data[i];
	else 
	{
		cout << "!-- ERROR : PANIC in ARRAYLIST!!.[]  (index out of bounds)";
		cout << endl;
		return m_errobj;
	}
}

template <typename T>
void ArrayList<T>::clear()
{
	m_size = 0;
	m_max = 0;
	delete [] m_data;
	m_data = NULL;
}



template <typename T>
void ArrayList<T>::swap(int i, int k)
{
	if (i >= 0 && k >= 0 && i <= m_size && k <= m_size)
	{
		T tmp = m_data[i];
		m_data[i] = m_data[k];
		m_data[k] = tmp;
	}
	else
	{
		cout << "!-- ERROR : PANIC in ARRAYLIST!!.swap()  (index out of bounds)";
		cout << endl;		
	}
}

template <typename T>
void ArrayList<T>::purge()  
{
	int check;
	
	for (int k = 0; k < m_size; k++)
	{
		check = k;
		for (int j = 0; j < m_size; j++)
		{
			if (m_data[check] == m_data[j] && check != j)
				remove(j);
		}
		
	}

}

template <typename T>
int ArrayList<T>::find(const T& x)
{
	bool found = false;
	int k = 0;
	while (k < m_size && found == false)
	{
		if (m_data[k] == x)
			found = true;
		else
			k++;
	}

	if (found == true)
		return k;
	else
		return -1;
}





template <typename T>
ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T>& rhs)
{
	if (this != &rhs) 
    {
		m_size = rhs.m_size;
		m_max = rhs.m_max;
		delete [] m_data; 
		m_data = new T[rhs.m_size];
		
		for (int k = 0; k < m_size; k++)
		{	
			m_data[k] = rhs.m_data[k];
		}
           
    }
        
  return *this;
}

template <typename T>
 ArrayList<T>::ArrayList(const ArrayList<T>& cpy)
 {
	 m_size = cpy.m_size;
	 m_max = cpy.m_max;
	 m_data = new T[cpy.m_size];

	 for (int k = 0; k < m_size; k++)
	{	
		m_data[k] = cpy.m_data[k];
	}

	 *this = cpy;
 }

 template <typename T>
 void ArrayList<T>::append(const ArrayList<T>& alist)
 { 
	 for (int k = 0; k < alist.m_size; k++)
	 {
		(*this).insert_back(alist.m_data[k]);
	 }
 }
