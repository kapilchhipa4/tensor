
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/tensor.hpp>
#include <boost/numeric/ublas/vector.hpp>
#include <complex>

template <class T>
constexpr std::string_view type_name() {
  using namespace std;
#ifdef __clang__
  string_view p = __PRETTY_FUNCTION__;
  return string_view(p.data() + 34, p.size() - 34 - 1);
#elif defined(__GNUC__)
  string_view p = __PRETTY_FUNCTION__;
#if __cplusplus < 201402
  return string_view(p.data() + 36, p.size() - 36 - 1);
#else
  return string_view(p.data() + 49, p.find(';', 49) - 49);
#endif
#elif defined(_MSC_VER)
  string_view p = __FUNCSIG__;
  return string_view(p.data() + 84, p.size() - 84 - 7);
#endif
}

int main() {
  using namespace boost::numeric::ublas;
  tensor<int> t1{shape{4, 4}, 4};
  tensor<float> t2{shape{4, 4}, 4.2};

  auto expr = (t1 + t1) / 2;

  tensor<std::complex<float>> c_t{{5, 5}};
  auto expr2 = c_t / 5.0f;
  boost::yap::print(std::cout, expr2);
  auto ig = expr2(0);
}
