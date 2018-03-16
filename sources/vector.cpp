#include <algorithm>
#include <cassert>

#include "vector.hpp"

vector_t::vector_t()
{
    elements_ = nullptr;
    size_ = 0;
    capacity_ = 0;
}

vector_t::vector_t(vector_t const &other)
{
    size_ = other.size_;
    capacity_ = other.capacity_;
    elements_ = new int[capacity_];
    for (unsigned int i = 0; i < size_; ++i)
    {
        elements_[i] = other.elements_[i];
    }
}

vector_t &vector_t::operator=(vector_t const &other)
{
    if (this != &other)
    {
        delete[] elements_;

        size_ = other.size_;
        capacity_ = other.capacity_;
        elements_ = new int[capacity_];
        for (unsigned int i = 0; i < size; ++i)
        {
            elements_[i] = other.elements_[i];
        }
    }
    return *this;
}

bool vector_t::operator==(vector_t const &other) const
{
    bool equal = true;
    if (size_ == other.size_ && capacity_ == other.capacity_)
    {
        for (unsigned int i = 0; i < size_; ++i)
        {
            if (elements_[i] != other.elements_[i])
            {
                equal = false;
                break;
            }
        }
    }
    else
    {
        equal = false;
    }
    return equal;
}

vector_t::~vector_t()
{
    delete[] elements_;
}

std::size_t vector_t::size() const
{
    return size_;
}

std::size_t vector_t::capacity() const
{
    return capacity_;
}

void vector_t::push_back(int value)
{

    if (elements_ == nullptr)
    {
        ++capacity_;
        elements_ = new int[capacity_];
    }
    else if (size_ == capacity_)
    {
        int *buff = new int[capacity_ * 2];
        for (unsigned int i = 0; i < size_; ++i)
        {
            buff[i] = elements_[i];
        }
        delete[] elements_;
        elements_ = buff;
    }
    elements_[size_] = value;
    ++size_;
}

void vector_t::pop_back()
{
    assert(size_ != 0);
    --size_;
    if (size_ * 4 == capacity_)
    {
        int *buff = new int[capacity_ / 2];
        for (unsigned int i = 0; i < size_; ++i)
        {
            buff[i] = elements_[i];
        }
        delete[] elements_;
        capacity_ = capacity_ / 2;
        elements_ = buff;
    }
}

int &vector_t::operator[](std::size_t index)
{
    return elements_[index];
}

int vector_t::operator[](std::size_t index) const
{
    return elements_[index];
}

bool operator!=(vector_t const &lhs, vector_t const &rhs)
{

    return !(lhs == rhs);
}
