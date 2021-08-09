/*
 * 都是内联比较函数
 */
#ifndef __SGI_STL_INTERNAL_RELOPS
#define __SGI_STL_INTERNAL_RELOPS

__STL_BEGIN_RELOPS_NAMESPACE

template <class _Tp>
inline bool operator!=(const _Tp& __x, const _Tp& __y) {
  return !(__x == __y);
}

template <class _Tp>
inline bool operator>(const _Tp& __x, const _Tp& __y) {
  return __y < __x;
}

template <class _Tp>
inline bool operator<=(const _Tp& __x, const _Tp& __y) {
  return !(__y < __x);
}

template <class _Tp>
inline bool operator>=(const _Tp& __x, const _Tp& __y) {
  return !(__x < __y);
}

__STL_END_RELOPS_NAMESPACE

#endif /* __SGI_STL_INTERNAL_RELOPS */