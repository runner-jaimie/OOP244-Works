
template <typename T>  // T present anytype
bool validate(const T& min, const T *myarr, int size, bool check[])
{ //*myarr == myarr[]
    bool ok = true;
    for (int i = 0; i < size; i++)
    {
      if (myarr[i] <= min)  // 여기서 operator overload 가 사용된다. myarr[i] <=  min
      {
          ok = false;
          check[i] = false;
      }
      else {
          check[i] = true;
      }
    }
    return ok;
}
