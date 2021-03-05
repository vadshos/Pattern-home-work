
#include "Sort_Vector.h"

std::vector<std::string> SortByABC::sort(std::vector<std::string> v)
{
    std::sort(v.begin(), v.end());
    return v;
}

std::vector<std::string> SortByLength::sort(std::vector<std::string> v)
{
    std::sort(v.begin(), v.end(), [](const std::string& first, const std::string& second) {
        if (first.length() != second.length()) {
            return first.length() > second.length();
        }
        else {
            first < second;
        }
        });
    return v;
}

Sort_Vector::Sort_Vector(ISort* Sort, const std::vector<std::string> v) : Sort(Sort)
{
set(v);
}

void Sort_Vector::sort()
{
    v = Sort->sort(v);
}

void Sort_Vector::print()
{
    for (auto& i : v)
    {
        std::cout << i << " ";
    }
}

const std::vector<std::string> Sort_Vector::get() const 
{
    return v;
}

void Sort_Vector::set(std::vector<std::string> v)
{
    this->v = v;
}
