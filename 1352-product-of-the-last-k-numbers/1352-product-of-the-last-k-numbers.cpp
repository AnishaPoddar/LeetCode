class ProductOfNumbers {
public:
    vector<int> pre_product={1};
    ProductOfNumbers() { 
    }
    
    void add(int num) {
        if(num==0)
        {
            pre_product={1};
        }
        else
        {
            pre_product.push_back(pre_product.back()*num);
        }
    }
    int getProduct(int k) {
        int n=pre_product.size();
        if(k>=n)
        {
            return 0;
        }
        return pre_product.back() / pre_product[n - 1 - k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */