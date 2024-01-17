#include <vector>
#include <iostream>

void monotomie_croissante_max(std::vector<int> &nums)
{

    size_t n = nums.size();

    if (n == 0)
    {
        return;
    }

    size_t max_len = 1, len = 1, max_start = 0, start = 0;

    for (size_t i = 1; i < n; i++)
    {
        if (nums[i] > nums[i - 1])
        {
            ++len;
        }
        else
        {
            if (len > max_len)
            {
                max_len = len;
                max_start = start;
            }
            len = 1;
            start = i;
        }
    }
    if (len > max_len)
    {
        max_len = len;
        max_start = start;
    }

    std::cout << "L'indice de depart est: " << max_start << std::endl;
    std::cout << "La longueur est: " << max_len << std::endl;
}


int main() {

    std::vector<int> T = {1, 2, 3, 2, 3, 4, 5, 1, 2};
    monotomie_croissante_max(T);
    
    return 0;
}