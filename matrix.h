#pragma once
#include <iostream>
#include <cstring>
#include <limits>
#include "exception.h"

template <typename T>
class Matrix
{
    public:
       ~Matrix()
        {
        clear_memory();
        };

        Matrix(const size_t rows, const size_t cols)
                : m_rows(rows),
                  m_cols(cols)
        {
            get_memory(m_rows, m_cols);
            set_value(0);
        }

        Matrix(const T number, const size_t rows, const size_t cols)
            : m_rows(rows),
              m_cols(cols)
        {
            get_memory(m_rows, m_cols);
            set_value(number);
        }

        Matrix(const T *numeric_2D_array, const size_t rows, const size_t cols)
            : m_rows(rows),
              m_cols(cols)
        {
            get_memory(m_rows,m_cols);
            for (unsigned int i = 0; i < m_rows; i++)
            {
                for (unsigned int j = 0; j < m_cols; j++)
                {
                    m_matrix[i][j] = *(numeric_2D_array + i * m_cols + j);
                }
            }
        };

        Matrix(const char *math_string, const size_t rows, const size_t cols)
            : m_rows(rows),
              m_cols(cols)
        {
            char math_string_copy[std::strlen(math_string)];
            T matrix_temp[m_rows * m_cols];

            strcpy(math_string_copy, math_string);
            char *tokens = std::strtok(math_string_copy," [],;");

            bool flag_no_letter {true};
            unsigned int iter {0};
            while (tokens != nullptr && flag_no_letter)
            {
                for (unsigned int i = 0; i < std::strlen(tokens); i++)
                {
                    if (!std::isdigit(tokens[i]) && tokens[i] != '.' )
                    {
                        flag_no_letter = false;
                    }
                }
                if (flag_no_letter)
                {
                    if (sizeof(T) > sizeof(int))
                    {
                        matrix_temp[iter] = std::stod(tokens);
                    } else {
                        matrix_temp[iter] = std::stoi(tokens);
                    }
                    iter++;
                }
                tokens = std::strtok(nullptr," [],;");
            }

            if (flag_no_letter)
            {
                get_memory(m_rows, m_cols);
                for (unsigned int i = 0; i < m_rows; i++)
                {
                    for (unsigned int j = 0; j < m_cols; j++)
                    {
                        m_matrix[i][j] = matrix_temp[i * m_rows+j];
                    }
                }
            } else
            {
                m_cols = 0;
                m_rows = 0;
            }
        };

        Matrix(const Matrix& lhs_matrix)
        {
            if (this != &lhs_matrix) {
                if (m_matrix != nullptr)
                {
                    clear_memory();
                }
                m_rows = lhs_matrix.m_rows;
                m_cols = lhs_matrix.m_cols;
                get_memory(m_rows, m_cols);
                for (unsigned int i = 0; i < m_rows; i++) {
                    for (unsigned int j = 0; j < m_cols; j++) {
                        m_matrix[i][j] = lhs_matrix.m_matrix[i][j];
                    }
                }
            }
        }

        Matrix(Matrix&& rhs_matrix)
        {
            if (this != &rhs_matrix)
            {
                m_matrix = std::move(rhs_matrix.m_matrix);
                rhs_matrix.m_matrix = nullptr;
                rhs_matrix.m_cols = 0;
                rhs_matrix.m_rows = 0;
            }
        }

        Matrix& operator=(const Matrix& lhs_matrix)
        {
            if (this != &lhs_matrix)
            {
                if (m_matrix != nullptr)
                {
                    clear_memory();
                }
                m_rows = lhs_matrix.m_rows;
                m_cols = lhs_matrix.m_cols;
                get_memory(m_rows, m_cols);
                for (unsigned int i = 0; i < m_rows; i++)
                {
                    for (unsigned int j = 0; j < m_cols; j++)
                    {
                        m_matrix[i][j] = lhs_matrix.m_matrix[i][j];
                    }
                }
            }
            return *this;
        };

        Matrix& operator=(Matrix&& rhs_matrix)
        {
            if (this != &rhs_matrix)
            {
                m_matrix = std::move(rhs_matrix.m_matrix);
                rhs_matrix.m_matrix = nullptr;
                rhs_matrix.m_cols = 0;
                rhs_matrix.m_rows = 0;
            }
            return *this;
        };

        Matrix& operator+=(const T value)
        {
            if ((value > 0) && (get_max_element() > std::numeric_limits<T>::max() - value))
            {
               std::cout << "Additional overflow" << std::endl;
               return *this;
            }

            if ((value < 0) && (get_max_element() < std::numeric_limits<T>::min() - value))
            {
                std::cout << "Additional overflow" << std::endl;
                return *this;
            }

            for (unsigned int i = 0; i < m_rows; i++)
            {
                for (unsigned int j = 0; j < m_cols; j++)
                {
                   m_matrix[i][j] = m_matrix[i][j] + value;
                }
            }
            return *this;
        }

        Matrix& operator-=(const T value)
        {
            if ((value > 0) && (get_max_element() < std::numeric_limits<T>::min() + value))
            {
               std::cout << "Subtraction overflow" << std::endl;
               return *this;
            }

            if ((value < 0) && (get_max_element() > std::numeric_limits<T>::max() + value))
            {
                std::cout << "Subtraction overflow" << std::endl;
                return *this;
            }

            for (unsigned int i = 0; i < m_rows; i++)
            {
                for (unsigned int j = 0; j < m_cols; j++)
                {
                   m_matrix[i][j] = m_matrix[i][j] - value;
                }
            }
            return *this;
        }

        Matrix& operator*=(const T value)
        {
            for (unsigned int i = 0; i < m_rows; i++)
            {
                for (unsigned int j = 0; j < m_cols; j++)
                {
                   m_matrix[i][j] = m_matrix[i][j] * value;
                }
            }
            return *this;
        }

        Matrix& operator/=(const T value )
        {
            if (value)
            {
                for (unsigned int i = 0; i < m_rows; i++)
                {
                    for (unsigned int j = 0; j < m_cols; j++)
                    {
                       m_matrix[i][j] = m_matrix[i][j] / value;
                    }
                }
            } else
            {
                std::cout << "Division by zero" << std::endl;
            }
            return *this;
        }

        Matrix& operator+=(const Matrix& matrix)
        {
            if (m_rows == matrix.m_rows && m_cols == matrix.m_cols)
            {
                for (unsigned int i = 0; i < m_rows; i++)
                {
                    for (unsigned int j = 0; j < m_cols; j++)
                    {
                        if ((matrix.m_matrix[i][j] > 0) && (get_max_element() > std::numeric_limits<T>::max() - matrix.m_matrix[i][j]))
                        {
                           std::cout << "Additional overflow" << std::endl;
                           return *this = Matrix();
                        }

                        if ((matrix.m_matrix[i][j] < 0) && (this->get_max_element() < std::numeric_limits<T>::min() - matrix.m_matrix[i][j]))
                        {
                            std::cout << "Additional overflow" << std::endl;
                            return *this = Matrix();
                        }
                        m_matrix[i][j] = m_matrix[i][j] + matrix.m_matrix[i][j];
                    }
                }
            } else
            {
                std::cout << "Additioin is not posible" << std::endl;
            }
            return *this;
        }

        Matrix& operator-=(const Matrix& matrix)
        {
            if (m_rows == matrix.m_rows && m_cols == matrix.m_cols)
            {
                for (unsigned int i = 0; i < m_rows; i++)
                {
                    for (unsigned int j = 0; j < m_cols; j++)
                    {
                        if ((matrix.m_matrix[i][j] > 0) && (m_matrix[i][j] < std::numeric_limits<T>::min() + matrix.m_matrix[i][j]))
                        {
                           std::cout << "Subtraction overflow" << std::endl;
                           return *this = Matrix();
                        }

                        if ((matrix.m_matrix[i][j] < 0) && (m_matrix[i][j] > std::numeric_limits<T>::max() + matrix.m_matrix[i][j]))
                        {
                            std::cout << "Subtraction overflow" << std::endl;
                            return *this = Matrix();
                        }
                        m_matrix[i][j] = m_matrix[i][j] - matrix.m_matrix[i][j];
                    }
                }
            } else
            {
                std::cout << "Subtraction is not posible" << std::endl;
            }
            return *this;
        }

        Matrix& operator*=(const Matrix& matrix)
        {
            try
            {
                if(m_cols == matrix.m_rows)
                {
                    Matrix temp_matrix(m_rows,matrix.m_cols);
                    T temp_element;
                    for (unsigned int i = 0; i < m_rows; i++)
                    {
                        for (unsigned int j = 0; j < matrix.m_cols; j++)
                        {
                            temp_element = 0;
                            for (unsigned int k = 0; k < m_cols; k++)
                            {
                                temp_element += m_matrix[i][k] * matrix.m_matrix[k][j];
                            }
                            temp_matrix.m_matrix[i][j] = temp_element;
                        }
                    }
                    *this = temp_matrix;
                } else {
                    throw Exception_Matrix_Multiple(m_rows, m_cols, matrix.m_rows, matrix.m_cols);
                    std::cout << "Multiplication error" << std::endl;
                }
                return *this;
            }
            catch(Exception_Matrix_Multiple exception)
            {
                exception.what();
                return *this;
            }
        }

        Matrix& operator/=(const Matrix& matrix)
        {
            *this *= matrix.get_inverse_matrix();
            return *this;
        }

        friend Matrix operator+(Matrix matrix_A,
                                const T value)
        {
            return matrix_A += value;
        }

        friend Matrix operator-(Matrix matrix_A,
                                const T value)
        {
            return matrix_A -= value;
        }

        friend Matrix operator*(Matrix matrix_A,
                                const T value)
        {
            return matrix_A *= value;
        }

        friend Matrix operator/(Matrix matrix_A,
                                const T value)
        {
            try {
                if(value)
                {
                  matrix_A /= value;
                  return  matrix_A;
                }
                else
                {
                  throw Exception_Division_By_Zero();
                }
            }
            catch (Exception_Division_By_Zero &exception)
            {
                exception.what();
                exit(1);
                return matrix_A;
            }
        }

        friend Matrix operator+(Matrix matrix_A,
                                const char* string)
        {
            if (sizeof(T) > sizeof(int)) {
                return matrix_A += std::stod(string);
            } else {
                return matrix_A += std::stoi(string);
            }
        }

        friend Matrix operator-(Matrix matrix_A,
                                const char* string)
        {
            if (sizeof(T) > sizeof(int)) {
                return matrix_A -= std::stod(string);
            } else {
                return matrix_A -= std::stoi(string);
            }
        }

        friend Matrix operator*(Matrix matrix_A,
                                const char* string)
        {
            if (sizeof(T) > sizeof(int))
            {
                return matrix_A *= std::stod(string);
            } else {
                return matrix_A *= std::stoi(string);
            }
        }

        friend Matrix operator/(Matrix matrix_A,
                                const char* string)
        {
            if (sizeof(T) > sizeof(int))
            {
                return matrix_A /= std::stod(string);
            } else {
                return matrix_A /= std::stoi(string);
            }
        }

        friend Matrix operator+(Matrix matrix_A,
                                const Matrix& matrix_B)
        {
            return matrix_A += matrix_B;
        }

        friend Matrix operator-(Matrix matrix_A,
                                const Matrix& matrix_B)
        {
            return matrix_A -= matrix_B;
        }

        friend Matrix operator*(Matrix matrix_A,
                                const Matrix& matrix_B)
        {
            return matrix_A *= matrix_B;
        };

        friend Matrix operator/(Matrix matrix_A,
                                const Matrix& matrix_B)
        {
            return matrix_A /= matrix_B;
        }

        bool operator>(const Matrix& matrix)
        {
            return get_sum_of_elements() > matrix.get_sum_of_elements();
        }

        bool operator>=(const Matrix& matrix)
        {
            return get_sum_of_elements() >= matrix.get_sum_of_elements();
        }

        bool operator<(const Matrix& matrix)
        {
            return get_sum_of_elements() < matrix.get_sum_of_elements();
        }

        bool operator<=(const Matrix& matrix)
        {
            return get_sum_of_elements() <= matrix.get_sum_of_elements();
        }

        bool operator==(const Matrix& matrix)
        {
            return get_sum_of_elements() == matrix.get_sum_of_elements();
        }

        bool operator!=(const Matrix& matrix)
        {
            return get_sum_of_elements() != matrix.get_sum_of_elements();
        }

        bool operator>(const T value)
        {
            return get_sum_of_elements() > value;
        }

        bool operator>=(const T value)
        {
            return get_sum_of_elements() >= value;
        }

        bool operator<(const T value)
        {
            return get_sum_of_elements() < value;
        }

        bool operator<=(const T value)
        {
            return get_sum_of_elements() <= value;
        }

        bool operator==(const T value)
        {
            return get_sum_of_elements() == value;
        }

        bool operator!=(const T value)
        {
            return get_sum_of_elements() != value;
        }

        double get_determinant () const
        {
            try
            {
                if (m_cols == m_rows)
                {
                    Matrix temp_matrix(*this);
                    double temp_row[m_cols];
                    double determinant {1};
                    double max_element_of_col;
                    unsigned int max_element_of_col_index;

                    for (unsigned int i = 0; i < m_cols; i++)
                    {
                        if (temp_matrix.m_matrix[i][i]==0)
                        {
                            return 0;
                        }
                        max_element_of_col = temp_matrix.m_matrix[i][i];
                        max_element_of_col_index = i;

                        for (unsigned int j = 0; j < m_rows; j++)
                        {
                            if (temp_matrix.m_matrix[j][i] > max_element_of_col)
                            {
                                max_element_of_col = temp_matrix.m_matrix[j][i];
                                max_element_of_col_index = j;
                            }
                        }
                        if (i != max_element_of_col_index)
                        {
                            determinant *= -1;
                            for (unsigned int j = 0; j < m_cols; j++)
                            {
                                temp_row[j] = temp_matrix.m_matrix[max_element_of_col_index][j];
                                temp_matrix.m_matrix[max_element_of_col_index][j] = temp_matrix.m_matrix[i][j];
                                temp_matrix.m_matrix[i][j] = temp_row[j];
                            }
                        }
                        for (unsigned int j = i + 1; j < m_rows; j++)
                        {
                            if (temp_matrix.m_matrix[j][i] != 0)
                            {
                                double multiplier = 1/temp_matrix.m_matrix[i][i] * temp_matrix.m_matrix[j][i];
                                for (unsigned int k = 0; k < m_cols; k++)
                                {
                                     temp_matrix.m_matrix[j][k] -= temp_matrix.m_matrix[i][k]*multiplier;
                                }
                             }
                         }
                         determinant *= temp_matrix.m_matrix[i][i];
                    }
                    return determinant;
                } else
                {
                    throw Exception_Matrix_non_square(m_rows, m_cols);
                }
            }
            catch(Exception_Matrix_non_square exception)
            {
                exception.what();
            }
        }

        Matrix get_tranposed_matrix() const
        {
            Matrix transposed_matrix (m_cols, m_rows);
            for (unsigned int i = 0; i < m_cols; i++)
            {
                for (unsigned int j = 0; j < m_rows; j++)
                {
                    transposed_matrix.set_element(i,j,m_matrix[j][i]);
                }
            }
            return transposed_matrix;
        }

        Matrix get_inverse_matrix() const
        {
            try
            {
                if (m_cols == m_rows)
                {
                    Matrix inverse_matrix(m_rows, m_cols);
                    for (unsigned int i = 0; i < m_cols; i++)
                    {
                        inverse_matrix.m_matrix[i][i] = 1;
                    }
                    Matrix temp_matrix(*this);
                    double temp_element;
                    for (unsigned int i = 0; i < m_cols; i++)
                    {
                        if (temp_matrix.m_matrix[i][i] != 1)
                        {
                            temp_element = temp_matrix.m_matrix[i][i];
                            for (unsigned int j = 0; j < m_cols; j++)
                            {
                                temp_matrix.m_matrix[i][j] /= temp_element;
                                inverse_matrix.m_matrix[i][j] /= temp_element;
                            }
                        }
                        for (unsigned int j = i + 1; j < m_rows; j++)
                        {
                            if (temp_matrix.m_matrix[j][i])
                            {
                                temp_element = -temp_matrix.m_matrix[j][i];
                                for (unsigned int k = 0; k < m_cols; k++)
                                {
                                     temp_matrix.m_matrix[j][k] += temp_matrix.m_matrix[i][k]*temp_element;
                                     inverse_matrix.m_matrix[j][k] += inverse_matrix.m_matrix[i][k]*temp_element;
                                }
                             }
                        }
                        for (int j = i - 1; j >= 0; j--)
                        {
                            if (temp_matrix.m_matrix[j][i])
                            {
                                temp_element = -temp_matrix.m_matrix[j][i];
                                for (unsigned int k = 0; k < m_cols; k++)
                                {
                                     temp_matrix.m_matrix[j][k] += temp_matrix.m_matrix[i][k]*temp_element;
                                     inverse_matrix.m_matrix[j][k] += inverse_matrix.m_matrix[i][k]*temp_element;
                                }
                            }
                        }
                    }
                    return inverse_matrix;
                } else
                {
                    throw Exception_Matrix_non_square(m_rows, m_cols);
                }
            }
            catch (Exception_Matrix_non_square exception)
            {
                exception.what();
            }

        }

        void print_in_string() const
        {
            if (m_matrix != nullptr)
            {
                std::cout << "\n[ ";
                for (unsigned int i = 0; i < m_rows; i++)
                {
                    for (unsigned int j = 0; j < m_cols; j++)
                    {
                        std::cout << m_matrix[i][j] << ", ";
                    }
                    std::cout <<"; ";
                }
                std::cout << " ]\n" << std::endl;
            } else {
                std::cout << "Matrix doesn't exist" << std::endl;;
            }
        };

    private:
        size_t m_rows{0};
        size_t m_cols{0};

        T **m_matrix = nullptr;
        void set_value(const T value)
        {
            for (unsigned int i = 0; i < m_rows; i++)
            {
                for (unsigned int j = 0; j < m_cols; j++)
                {
                    m_matrix[i][j] = value;
                }
            }
        };

        void get_memory(size_t rows, size_t cols)
        {
            if (m_matrix == nullptr)
            {
                try {
                    if(m_matrix = new T *[rows])
                    {
                        for (unsigned int i = 0; i < rows; i++)
                        {
                            m_matrix[i] = new T [cols]{0};
                        }
                    }
                    else
                    {
                        Exception_Memory error_memory;
                        throw error_memory;
                    }
                } catch (Exception_Memory exception)
                {
                    exception.what();
                }
            }
        };
        void clear_memory()
        {
            m_cols = 0;
            m_rows = 0;
            if (m_matrix != nullptr)
            {
                for (unsigned int i = 0; i < m_rows; i++)
                {
                    delete[] m_matrix[i];
                }
                delete[] m_matrix;
                m_matrix = nullptr;
            }
        };

        T get_sum_of_elements() const
        {
            T sum {0};
            for (unsigned int i = 0; i < m_rows; i++)
            {
                for (unsigned int j = 0; j < m_cols; j++)
                {
                   sum += m_matrix[i][j];
                }
            }
            return sum;
        };

        T get_max_element() const
        {
            T max_elemet {0};
            for (unsigned int i = 0; i < m_rows; i++)
            {
                for (unsigned int j = 0; j < m_cols; j++)
                {
                   if (m_matrix[i][j] > max_elemet)
                   {
                       max_elemet = m_matrix[i][j];
                   }
                }
            }
            return max_elemet;
        }
};
