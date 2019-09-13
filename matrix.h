#pragma once
#include <map>


template<typename T, int def>
class Matrix {
public:
    Matrix() : column(*this), row(*this) {};

    Matrix(const Matrix &other) : Matrix() {
        data = other.data;
    }

    Matrix(const Matrix &&other) noexcept : Matrix() {
        data = move(other.data);
    }

    Matrix &operator=(const Matrix &other) {
        if (this != &other) {
            this->data = other.data;
        }
        return *this;
    }

    Matrix &operator=(Matrix &&other) noexcept {
        if (this != &other) {
            this->data = move(other.data);
        }
        return *this;
    }

    ~Matrix() = default;

    auto &operator[](const int rowNum) {
        index.first = rowNum;
        return this->row;
    }

    const std::size_t size() const {
        return data.size();
    }

    auto begin() {
        return std::begin(data);
    }

    auto end() {
        return std::end(data);
    }


private:

    struct MatrixRow {
        Matrix<T, def> &matrix;

        MatrixRow(Matrix<T, def> &matrix) :
                matrix(matrix) {};

        auto operator[](const int columNum) {
            matrix.index.second = columNum;
            return matrix.column;
        }
    };

    struct MatrixColumn {
        Matrix<T, def> &matrix;

        MatrixColumn(Matrix<T, def> &matrix) :
                matrix(matrix) {};

        auto &operator=(const T &other) {
            if (other == def)
                matrix.data.erase(matrix.index);
            else
                matrix.data[matrix.index] = other;
            return *this;
        }

        operator T() {
            const auto it = matrix.data.find(matrix.index);
            return it == matrix.data.end() ? def : it->second;
        }
    };

    std::pair<int, int> index;
    std::map<std::pair<int, int>, T> data;
    MatrixColumn column;
    MatrixRow row;
};
