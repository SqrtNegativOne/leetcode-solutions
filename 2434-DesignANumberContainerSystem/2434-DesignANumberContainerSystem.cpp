// Last updated: 07/08/2025, 12:49:56
class NumberContainers {

    std::unordered_map <
        int, 
        std::priority_queue<int, std::vector<int>, std::greater<int>>
    > number_indexes;
    std::unordered_map<int, int> index_number;

public:
    NumberContainers() {}

    void change(const int& index, const int& number) {

        if (index_number.contains(index)) {
            // If old number has that index as its least, remove the last element.
            const int old_number = index_number[index];
            const int smallest_index_for_old_number = number_indexes[old_number].top();
            if (smallest_index_for_old_number == index)
                number_indexes[old_number].pop();

        }
        index_number[index] = number;

        number_indexes[number].push(index);
    }

    int find(const int& number) {
        if (!number_indexes.contains(number))
            return -1;
        
    
        while (!number_indexes[number].empty() and index_number[number_indexes[number].top()] != number) {
            number_indexes[number].pop();
        }

        if (number_indexes[number].empty())
            return -1;
        
        return number_indexes[number].top();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */