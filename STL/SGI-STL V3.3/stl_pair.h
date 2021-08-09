/*
 * pair实现
 * make_pair() 创建pair对象
 * 运算符重载都是外联函数 == != < <= > >=
 */

#ifndef __SGI_STL_INTERNAL_PAIR_H
#define __SGI_STL_INTERNAL_PAIR_H

__STL_BEGIN_NAMESPACE

//模板结构体
//定义pair结构体类型为T1 T2
template <class _T1, class _T2>
struct pair {
  //类型改名 typedef
  typedef _T1 first_type;
  typedef _T2 second_type;

  _T1 first;  //第一个元素
  _T2 second;//第二个元素
  //构造函数
  pair() : first(_T1()), second(_T2()) {}
  //构造函数
  pair(const _T1& __a, const _T2& __b) : first(__a), second(__b) {}

#ifdef __STL_MEMBER_TEMPLATES
  //拷贝构造函数
  template <class _U1, class _U2>
  pair(const pair<_U1, _U2>& __p) : first(__p.first), second(__p.second) {}
#endif
};

//外部内联函数 运算符重载
//==运算符
template <class _T1, class _T2>
inline bool operator==(const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y)
{
    //比较first和second
  return __x.first == __y.first && __x.second == __y.second; 
}

//<运算符 const 函数里面不能修改__x的值
template <class _T1, class _T2>
inline bool operator<(const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y)
{ 
  return __x.first < __y.first || 
         (!(__y.first < __x.first) && __x.second < __y.second); 
}

#ifdef __STL_FUNCTION_TMPL_PARTIAL_ORDER

//!=运算符
template <class _T1, class _T2>
inline bool operator!=(const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y) {
  return !(__x == __y);
}

//>
template <class _T1, class _T2>
inline bool operator>(const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y) {
  return __y < __x;
}

//<=
template <class _T1, class _T2>
inline bool operator<=(const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y) {
  return !(__y < __x);
}

//>=
template <class _T1, class _T2>
inline bool operator>=(const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y) {
  return !(__x < __y);
}

#endif /* __STL_FUNCTION_TMPL_PARTIAL_ORDER */

//make_pair函数和make_shard函数很像 传入参数返回对象
template <class _T1, class _T2>
inline pair<_T1, _T2> make_pair(const _T1& __x, const _T2& __y)
{
  return pair<_T1, _T2>(__x, __y);
}

__STL_END_NAMESPACE

#endif /* __SGI_STL_INTERNAL_PAIR_H */

// Local Variables:
// mode:C++
// End:
