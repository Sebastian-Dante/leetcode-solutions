class ProductOfNumbers {
private:
    std::vector<int> prefixProducts; // Stores prefix profuct values
public:
    ProductOfNumbers() {
        // Initialize with 1 to handle edge cases in multiplication
        prefixProducts.push_back(1);
    }
    
    void add(int num) {
        if (num == 0) {
            // Reset prefix product when zero is encountered
            prefixProducts.clear();
            prefixProducts.push_back(1); // Reset prefix product
        } else {
            // Compute new prefix profuct and append it
            prefixProducts.push_back(prefixProducts.back() * num);
        }
    }
    
    int getProduct(int k) {
        int size = prefixProducts.size();
        if (k >= size) {
            // If k is greater than or equal to the available size, a zero was encountered
            return 0;
        }
        // Compute profuct using prefix division
        return prefixProducts.back() / prefixProducts[size - k - 1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */