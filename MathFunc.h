namespace MathFunc{

    template <class T>
    T abs(T n){
        if (n < 0){return -n;}
        return n;
    }

    int gcd(int n, int k)
    {
        if (k < 0) {k = -k;}
        if (n < 0) {n = -n;}
        if (k > n)
        {
            int temp = k;
            k = n;
            n = temp;
        }
        if (k == 0){ return n; }
        return gcd(k, n - k);
    }

    int lcm(int n, int k)
    {
        return abs(n*k)/gcd(n,k);
    }
}