// problem 1) 1352. Product of the Last K Numbers
class ProductOfNumbers {
public:
    vector<int> v;
    int pre;
    ProductOfNumbers() {
        pre=1;
    }
    void add(int num) {
        if(num==0){
            v.clear();
            pre=1;
        }else{
            pre*=num;
            v.push_back(pre);
        }   
    }
    
    int getProduct(int k) {
        int vsz=v.size();
        if(k>vsz){
            return 0;
        }else{
            if(k==vsz){
                return v[vsz-1];
            }else{
                return v[vsz-1]/v[vsz-k-1];
            }
        }
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */