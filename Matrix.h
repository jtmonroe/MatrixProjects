#pragma once

#include<iostream> 
#include<string>

using std::to_string;

namespace MatMath{

template <class T> class Matrix
{
public:
	// Constructor + Destructor
	Matrix(int row, int col);
	Matrix(const Matrix<T>& M);
	~Matrix();

	// Get row/col numbers
	inline int getRown(){return this -> m_row;}	 
	inline int getColn(){return this -> m_col;}	

	// Getter and Setter functions for Rows, Cols, and Pos
	T* getCol(int coln) const;
	void setCol(T newcol[], int coln);

	T* getRow(int rown) const;
	void setRow(T newrow[], int rown);

	T getPos(int rown, int coln);
	void setPos(int rown, int coln, T val);


	// Operators
		// Scalar Mult
	Matrix<T> operator*(const T& c);

		// Matrix Mult and Addition
	Matrix<T> operator+(const Matrix<T>& M);
	Matrix<T> operator*(const Matrix<T>& M);
	bool operator==(const Matrix<T>& M);

		// Tensor Product
	Matrix<T> tensor(const Matrix<T>& M);

	// Row operations
	/*
	void Swaps(int i, int j); // Ri <-> Rj
	void Scale(int i, int c); // Ri = c*Ri
	void Inter(int i, int j, int c); // Ri = Ri + c*Rj
	*/

	Matrix<T> transpose();


	// Display Function
	void display();

private:
	int m_col;
	int m_row;
	T *m_data;
};

template <class T>
Matrix<T>::Matrix(int row,int col)
{
	m_row = row;
	m_col = col;

	m_data = new T[row*col];
}

template <class T>
Matrix<T>::Matrix(const Matrix<T>& M)
{
	m_row = M.m_row;
	m_col = M.m_col;
	m_data = M.m_data;
}

template <class T>
Matrix<T>::~Matrix()
{
	if ((m_row == 0) || (m_col == 0)) { delete m_data;}
	else { delete [] m_data; }
	m_data = NULL;	
}

template <class T>
T* Matrix<T>::getCol(int coln) const
{
	T *ret_col = new T[m_row];
	for (int i{ 0 }; i < m_row; i++) { ret_col[i] = m_data[i*m_col + coln]; }
	return ret_col;
}

template <class T>
void Matrix<T>::setCol(T newcol[], int coln)
{
	for (int i{ 0 }; i < m_row; i++) { m_data[i*m_col + coln] = newcol[i]; }
}

template <class T>
T * Matrix<T>::getRow(int rown) const
{
	T *ret_row = new T[m_col];
	for (int i{ 0 }; i < m_row; i++) { ret_row[i] = m_data[rown*m_col + i]; }
	return ret_row;
}

template <class T>
void Matrix<T>::setRow(T newrow[], int rown)
{
	for (int i{ 0 }; i < m_row; i++) { m_data[rown*m_col + i] = newrow[i]; }
}

template <class T>
T Matrix<T>::getPos(int rown, int coln)
{
	return m_data[rown*m_col + coln];
}

template <class T>
void Matrix<T>::setPos(int rown, int coln, T val)
{
	m_data[rown*m_col + coln] = val;
}

template <class T>
Matrix<T> Matrix<T>::operator*(const T& c)
{
	Matrix<T> result(m_row,m_col);
	for (unsigned int i{0}; i < m_row*m_col; i++) {result.m_data[i] = c*(this->m_data[i]);}
	return result;
}

template <class T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& M)
{
	if (m_col != M.m_col || m_row != M.m_row)
	{
		throw std::invalid_argument("Invalid size in second Matrix. Should be " + to_string(m_col) + "x" + to_string(m_row));
	}
	Matrix<T> result(m_row, m_col);
	for (unsigned int i{ 0 }; i < m_row*m_col; i++) { result.m_data[i] = m_data[i] + M.m_data[i]; }
	return result;
}

template <class T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& M)
{
	if (this->m_col != M.m_row)
	{
		throw std::invalid_argument("Invalid number of rows in second matrix. Should have " + to_string(m_col) + " rows.");
	}
	Matrix result(m_row, M.m_col);
	for (unsigned int i{0}; i < result.m_row; i++)
	{
		for (unsigned int j{0}; j < result.m_col; j++)
		{
			double curVal{0.0};
			for (unsigned int k{0}; k < m_col; k++)
			{
				result.m_data[i*result.m_col + j] += this->m_data[i*m_col + k]*M.m_data[k*M.m_col + j];
			}
		}
	}
	return result;
}

template <class T>
bool Matrix<T>::operator==(const Matrix<T>& M)
{
	if (m_row != M.m_row && m_col != M.m_col) return false;
	for(unsigned int i{0}; i < m_col*m_row; i++)
	{
		if (m_data[i] == M.m_data[i]) return false;
	}
	return true;
}

template <class T>
Matrix<T> Matrix<T>::tensor(const Matrix<T>& M)
{
	Matrix<T> result((m_row)*(M.m_row), (m_col)*(M.m_col));
	for (unsigned int i1{0}; i1 < m_row; i1++)
	{
		for (unsigned int j1{0}; j1 < m_col; j1++)
		{
			for (unsigned int i2{0}; i2 < M.m_row; i2++)
			{
				for (unsigned int j2{0}; j2 < M.m_col; j2++)
				{
					result.m_data[(i1*M.m_row + i2)*result.m_col + (j1*M.m_col + j2)] = this->m_data[i1*m_col + j1]*M.m_data[i2*M.m_col + j2];
				}
			}
		}
	}
	return result;
}

template <class T>
Matrix<T> Matrix<T>::transpose()
{
	Matrix<T> result(m_col, m_row);
	for (unsigned int i{0}; i < m_row; i++)
	{
		for (unsigned int j{0}; j < m_col; j++)
		{
			result.m_data[j*m_row + i] = m_data[i*m_col + j];
		}
	}
	return result;
}

template <class T>
void Matrix<T>::display()
{
	for (int i{ 0 }; i < m_row; i++) 
	{
		for (int j{ 0 }; j < m_col; j++) 
		{
			std::cout << to_string(m_data[i*m_col + j]) << ", ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}


template <class T>
Matrix<T> Identity(int n)
{
	Matrix<T> I(n,n);
	T o = 1;
	for (unsigned int i{0}; i < n; i++)
	{
		T ei[n];
		ei[i] = ei[i] + o;
		I.setCol(ei,i);
	}
	return I;
}

}