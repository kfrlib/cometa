#include <cometa.hpp>
#include <cstdint>

using namespace cometa;

struct struct1
{
};
struct struct2
{
    constexpr operator int() const { return 0; }
};

enum enum1
{
};
enum class enumclass1
{
};

void func1() {}
void func1(int) {}
void func1(bool, float) {}

CMT_FN(func1)

struct struct3
{
    int array[4];
};

void func(const struct3& s3)
{
    constexpr size_t size = CMT_ARRAYSIZE(s3.array);
    static_assert(size == 4, "");
}

int& ref_fn(int& x) { return x; }

int main(int, char**)
{
    static_assert(is_poweroftwo(1), "");
    static_assert(is_poweroftwo(2), "");
    static_assert(!is_poweroftwo(3), "");
    static_assert(is_poweroftwo(4), "");

    static_assert(gcd(6, 10) == 2, "");
    static_assert(lcm(6, 10) == 30, "");

    static_assert(next_poweroftwo(0) == 0, "");
    static_assert(next_poweroftwo(1) == 1, "");
    static_assert(next_poweroftwo(2) == 2, "");
    static_assert(next_poweroftwo(3) == 4, "");

    static_assert(prev_poweroftwo(0) == 0, "");
    static_assert(prev_poweroftwo(1) == 1, "");
    static_assert(prev_poweroftwo(2) == 2, "");
    static_assert(prev_poweroftwo(3) == 2, "");

    static_assert(ilog2(0) == 0, "");
    static_assert(ilog2(1) == 0, "");
    static_assert(ilog2(2) == 1, "");
    static_assert(ilog2(3) == 1, "");
    static_assert(ilog2(4) == 2, "");

    static_assert(is_number<float>::value, "");
    static_assert(is_number<double>::value, "");
    static_assert(is_number<char>::value, "");
    static_assert(is_number<unsigned long long>::value, "");
    static_assert(is_number<wchar_t>::value, "");
    static_assert(is_number<char16_t>::value, "");
    static_assert(is_number<char32_t>::value, "");
    static_assert(!is_number<bool>::value, "");
    static_assert(!is_number<enum1>::value, "");
    static_assert(!is_number<enumclass1>::value, "");

    static_assert(is_callable<fn_func1>::value, "");
    static_assert(is_callable<fn_func1, int>::value, "");
    static_assert(is_callable<fn_func1, bool, float>::value, "");
    static_assert(is_callable<fn_func1, enum1>::value, "");
    static_assert(is_callable<fn_func1, struct2>::value, "");
    static_assert(!is_callable<fn_func1, char, char, char>::value, "");
    static_assert(!is_callable<fn_func1, enumclass1>::value, "");
    static_assert(!is_callable<fn_func1, struct1>::value, "");

    static_assert(ctypeid<int>() == ctypeid<std::int32_t>(), "");
    static_assert(ctypeid<char>() == ctypeid<char>(), "");

    static_assert(details::strlen("hello") == 5, "");
    static_assert(make_cstring("abc") == make_cstring("abc"), "");
    static_assert(ctype_name<float>() == ctype_name<float>(), "");
    static_assert(ctype_name<float>() != ctype_name<double>(), "");

    {
        function<int&(int&)> fn = ref_fn;

        int x;
        int& y = ref_fn(x);
        int& z = fn(x);
        (void)y;
        (void)z;
        function<int&(int&)> empty_fn;
        int d;
        int& a = fn.call(d, x);
        (void)a;
    }

    return 0;
}
